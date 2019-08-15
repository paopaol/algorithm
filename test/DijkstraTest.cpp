#include <algorithm/Dijkstra.h>
#include <gtest/gtest.h>

TEST(DijkstraTest, findShortestGraphPath) {
  algorithm::Graph graph("Start");
  graph.addNeighbor("A", 6).addNeighbor("End", 1);
  auto &b = graph.addNeighbor("B", 2);
  b.addNeighbor("A", 3);
  b.addNeighbor("End", 5);

  std::vector<algorithm::NodeName> expectPath = {"Start", "B", "A", "End"};

  auto path = algorithm::findShortestGraphPath(graph, "End");
  auto actualPath = path.path("End");
  EXPECT_EQ(std::equal(expectPath.begin(), expectPath.end(), actualPath.begin(),
                       actualPath.end()),
            true);
}
