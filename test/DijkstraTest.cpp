#include <algorithm/Dijkstra.h>
#include <gtest/gtest.h>

TEST(DijkstraTest, findShortestGraphPath) {
  algorithm::GraphPtr graph = std::make_shared<algorithm::Graph>("Start");
  graph->gotoNode("Start", "A", 6);
  graph->gotoNode("Start", "B", 2);
  graph->gotoNode("A", "End", 1);
  graph->gotoNode("B", "End", 5);
  graph->gotoNode("B", "A", 3);

  std::vector<algorithm::NodeName> expectPath = {"Start", "B", "A", "End"};

  auto path = algorithm::findShortestGraphPath(graph, "End");
  auto actualPath = path.path("End");
  EXPECT_EQ(std::equal(expectPath.begin(), expectPath.end(), actualPath.begin(),
                       actualPath.end()),
            true);
}

TEST(DijkstraTest, findShortestGraphPath2) {
  algorithm::GraphPtr graph = std::make_shared<algorithm::Graph>("Start");
  graph->gotoNode("Start", "A", 5);
  graph->gotoNode("Start", "B", 0);
  graph->gotoNode("A", "C", 15);
  graph->gotoNode("C", "End", 20);
  graph->gotoNode("A", "D", 20);
  graph->gotoNode("B", "D", 35);
  graph->gotoNode("B", "C", 30);
  graph->gotoNode("D", "End", 10);

  std::vector<algorithm::NodeName> expectPath = {"Start", "A", "D", "End"};

  auto path = algorithm::findShortestGraphPath(graph, "End");
  auto actualPath = path.path("End");
  EXPECT_EQ(std::equal(expectPath.begin(), expectPath.end(), actualPath.begin(),
                       actualPath.end()),
            true);
}


TEST(DijkstraTest, findShortestGraphPath3) {
  algorithm::GraphPtr graph = std::make_shared<algorithm::Graph>("Start");
  graph->gotoNode("Start", "A", 5);
  graph->gotoNode("Start", "B", 2);
  graph->gotoNode("A", "C", 4);
  graph->gotoNode("C", "End", 3);
  graph->gotoNode("A", "D", 2);
  graph->gotoNode("B", "D", 7);
  graph->gotoNode("C", "D", 6);
  graph->gotoNode("D", "End", 1);

  std::vector<algorithm::NodeName> expectPath = {"Start", "A", "D", "End"};

  auto path = algorithm::findShortestGraphPath(graph, "End");
  auto actualPath = path.path("End");
  EXPECT_EQ(std::equal(expectPath.begin(), expectPath.end(), actualPath.begin(),
                       actualPath.end()),
            true);
}
