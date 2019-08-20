#ifndef __BREADTHFIRSTSEARCH_H_
#define __BREADTHFIRSTSEARCH_H_
#include <list>
#include <map>
#include <stack>
#include <string>

namespace algorithm {
namespace BreadthFirstSearch {
using Childs = std::list<std::string>;
using Graph = std::map<std::string, Childs>;
using ParentMap = std::map<std::string /*node*/, std::string /*parent*/>;
struct Pair {
  std::string Name;
  std::string Parent;
};

inline void appendList(std::list<Pair> &list, const std::string &parent,
                       const std::list<std::string> &subList) {
  for (auto &e : subList) {
    Pair pair;
    pair.Name = e;
    pair.Parent = parent;
    list.push_back(pair);
  }
}

inline std::list<std::string> search(Graph &graph, const std::string &start,
                                     const std::string &end) {
  Childs childs = graph[start];
  std::list<Pair> childPairs;
  ParentMap parent;

  appendList(childPairs, start, graph[start]);

  while (!childPairs.empty()) {
    auto child = childPairs.front();
    childPairs.pop_front();
    parent[child.Name] = child.Parent;
    if (child.Name == end) {
      break;
    }
    appendList(childPairs, child.Name, graph[child.Name]);
  }
  std::list<std::string> pathList;
  std::string endNode = end;
  pathList.push_back(endNode);
  while (parent.find(endNode) != parent.end()) {
    pathList.push_back(parent[endNode]);
    endNode = parent[endNode];
  }
  pathList.reverse();
  return pathList;
}
} // namespace BreadthFirstSearch
} // namespace algorithm

#endif // __BREADTHFIRSTSEARCH_H_
