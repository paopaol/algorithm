#ifndef __DIJKSTRA_H_
#define __DIJKSTRA_H_

#include <assert.h>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace algorithm {
using TimeSecond = unsigned long long;
using NodeName = std::string;

const TimeSecond maxTimeSecond = 0xffffffff;

class Node;
using NodePtr = std::shared_ptr<Node>;
using Neighbors = std::map<NodeName, NodePtr>;
using NodeToNodeTimeSecondMap = std::map<NodeName, TimeSecond>;

class Node : public std::enable_shared_from_this<Node> {
public:
  Node() {}
  Node(const NodeName &name) : name_(name) {}
  ~Node() {}
  void connect(const NodePtr &toNode, TimeSecond overhead) {
    // toNode is child node of this
    neighbors_[toNode->name()] = toNode;
    // from `this` goto `toNode`, will take `overhead` seconds
    toNode->overhead_[name()] = overhead;
  }

  Neighbors &neighbors() { return neighbors_; }
  NodeName name() const { return name_; }
  TimeSecond overhead(const NodeName &name) { return overhead_[name]; }

  NodePtr getNodeByName(const NodeName &name) {
    return findNodeByName(shared_from_this(), name);
  }

private:
  NodePtr findNodeByName(const NodePtr &node, const NodeName &name) {
    if (node->name() == name) {
      return node;
    }
    for (auto &neighbor : node->neighbors()) {
      if (neighbor.second->name() == name) {
        return neighbor.second;
      }
    }
    for (auto &neighbor : node->neighbors()) {
      return findNodeByName(neighbor.second, name);
    }
    return nullptr;
  }

  NodeName name_;
  Neighbors neighbors_;
  //`parent node` go to `this`, will table `overhead_[parent]` seconds
  NodeToNodeTimeSecondMap overhead_;
};

class Graph {
public:
  Graph(const NodeName &rootName)
      : rootNode_(std::make_shared<Node>(rootName)) {}
  void gotoNode(const NodeName &fromName, const NodeName &toName,
                TimeSecond overhead) {
    auto fromNode = getNodeByName(fromName);
    auto toNode = getNodeByName(toName);
    if (!toNode) {
      toNode = std::make_shared<Node>(toName);
    }
    fromNode->connect(toNode, overhead);
  }

  NodePtr getNodeByName(const NodeName &name) {
    return rootNode_->getNodeByName(name);
  }

  virtual ~Graph(){};

private:
  friend class GraphPath;
  NodePtr rootNode_;
};
using GraphPtr = std::shared_ptr<Graph>;

class GraphPath {
public:
  GraphPath(const GraphPtr &graph) {
    buildCosts(graph->rootNode_, graph->rootNode_->name());
  }
  virtual ~GraphPath() {}
  TimeSecond overhead(const NodeName &name) { return costs_[name].overhead; }
  std::vector<NodeName> path(const NodeName &name) {
    std::vector<NodeName> pathList;
    pathList.push_back(name);
    NodeName parentName = costs_[name].parent;
    while (!parentName.empty()) {
      pathList.push_back(parentName);
      parentName = costs_[parentName].parent;
    }
    std::reverse(pathList.begin(), pathList.end());
    return pathList;
  }

private:
  struct NodeOverhead {
    TimeSecond overhead;
    NodeName parent;
    bool handled{false};
  };
  void buildCosts(const NodePtr &node, const NodeName &rootName) {
    auto &neighbors = node->neighbors();
    if (neighbors.empty()) {
      return;
    }
    for (auto neighbor : neighbors) {
      NodeOverhead overhead;
      overhead.parent = node->name();
      if (overhead.parent == rootName) {
        overhead.overhead = neighbor.second->overhead(rootName);
      } else {
        overhead.overhead = maxTimeSecond;
      }
      if (costs_.find(neighbor.second->name()) == costs_.end()) {
        costs_[neighbor.second->name()] = overhead;
      }
      buildCosts(neighbor.second, rootName);
    }
  }

  bool getLowestNodeName(NodeName &lowestNodename) {
    TimeSecond lowestOverhead = maxTimeSecond;
    lowestNodename.clear();

    // find lowest from costs_ table, if has handled, skip it
    for (auto it : costs_) {
      NodeName name = it.first;
      NodeOverhead nodeOverhead = it.second;
      if (nodeOverhead.overhead < lowestOverhead && !nodeOverhead.handled) {
        lowestOverhead = nodeOverhead.overhead;
        lowestNodename = name;
      }
    }
    return !lowestNodename.empty();
  }

  friend GraphPath findShortestGraphPath(const GraphPtr &graph,
                                         const NodeName &end);
  std::map<std::string, NodeOverhead> costs_;
};

inline GraphPath findShortestGraphPath(const GraphPtr &graph,
                                       const NodeName &end) {
  GraphPath p(graph);

  NodeName name;
  while (p.getLowestNodeName(name)) {
    TimeSecond overhead = p.costs_[name].overhead;
    auto node = graph->getNodeByName(name);
    for (auto neighbor : node->neighbors()) {
      NodeName neighborName = neighbor.second->name();
      TimeSecond newOverhead =
          overhead + neighbor.second->overhead(node->name());
      if (p.costs_[neighborName].overhead > newOverhead) {
        p.costs_[neighborName].overhead = newOverhead;
        p.costs_[neighborName].parent = name;
      }
    }
    p.costs_[name].handled = true;
  }

  return p;
}

} // namespace algorithm

#endif // __DIJKSTRA_H_
