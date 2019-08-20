#include <algorithm/BreadthFirstSearch.h>
#include <gtest/gtest.h>
#include <string>

TEST(BreadthFirstSearchTest, searchShortestPath) {
  algorithm::BreadthFirstSearch::Graph graph;
  std::list<std::string> actualPath = {"A", "B", "C", "D"};
  graph["A"] = std::list<std::string>({"B", "E"});
  graph["B"] = std::list<std::string>({"C"});
  graph["E"] = std::list<std::string>({"F", "G"});
  graph["F"] = std::list<std::string>({"C"});
  graph["G"] = std::list<std::string>({"G"});
  graph["C"] = std::list<std::string>({"D"});

  auto shortestPath = algorithm::BreadthFirstSearch::search(graph, "A", "D");
  EXPECT_EQ(std::equal(shortestPath.begin(), shortestPath.end(),
                       actualPath.begin(), actualPath.end()),
            true);
}
