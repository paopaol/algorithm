#ifndef __DIJKSTRA_H_
#define __DIJKSTRA_H_

#include <assert.h>
#include <map>
#include <string>
#include <vector>

namespace algorithm {
using TimeSecond = unsigned long long;
const TimeSecond maxTimeSecond = 0xffffffff;
using NodeName = std::string;

class Node;
using Neighbors = std::map<NodeName, Node>;

class Node {
public:
  Node() {}
  Node(const NodeName name, TimeSecond overhead)
      : name_(name), overhead_(overhead) {}
  ~Node() {}
  Node &addNeighbor(const NodeName &name, TimeSecond overhead) {
    Node node(name, overhead);

    neighbors_[name] = node;
    return neighbors_[name];
  }

  Neighbors &neighbors() { return neighbors_; }
  NodeName name() const { return name_; }
  TimeSecond overhead() const { return overhead_; }

  Node &getNodeByName(const NodeName &name) {
    return findNodeByName(*this, name);
  }

private:
  Node &findNodeByName(Node &node, const NodeName &name) {
    if (node.name() == name) {
      return node;
    }
    for (auto &neighbor : node.neighbors()) {
      if (neighbor.second.name() == name) {
        return neighbor.second;
      }
    }
    for (auto &neighbor : node.neighbors()) {
      return findNodeByName(neighbor.second, name);
    }
  }

  NodeName name_;
  Neighbors neighbors_;
  TimeSecond overhead_{maxTimeSecond};
};

class Graph : public Node {
public:
  Graph(const NodeName &rootName) : Node(rootName, maxTimeSecond) {}
  virtual ~Graph(){};
};

class GraphPath {
public:
  GraphPath(Graph &graph) { buildCosts(graph, graph.name()); }
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
  void buildCosts(Node &node, const NodeName &rootName) {
    auto &neighbors = node.neighbors();
    if (neighbors.empty()) {
      return;
    }
    for (auto neighbor : neighbors) {
      NodeOverhead overhead;
      overhead.parent = node.name();
      if (overhead.parent == rootName) {
        overhead.overhead = neighbor.second.overhead();
      } else {
        overhead.overhead = maxTimeSecond;
      }
      if (costs_.find(neighbor.second.name()) == costs_.end()) {
        costs_[neighbor.second.name()] = overhead;
      }
      buildCosts(neighbor.second, rootName);
    }
  }

  bool getLowestNodeName(NodeName &lowestNodename) {
    TimeSecond lowestOverhead = maxTimeSecond;
    lowestNodename.clear();

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

  friend GraphPath findShortestGraphPath(Graph &graph, const NodeName &end);
  std::map<std::string, NodeOverhead> costs_;
};

inline GraphPath findShortestGraphPath(Graph &graph, const NodeName &end) {
  GraphPath p(graph);

  NodeName name;
  while (p.getLowestNodeName(name)) {
    TimeSecond overhead = p.costs_[name].overhead;
    auto node = graph.getNodeByName(name);
    for (auto neighbor : node.neighbors()) {
      NodeName neighborName = neighbor.second.name();
      TimeSecond newOverhead = overhead + neighbor.second.overhead();
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
