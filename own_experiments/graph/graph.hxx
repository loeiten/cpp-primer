#ifndef OWN_EXPERIMENTS_GRAPH_GRAPH_HXX_
#define OWN_EXPERIMENTS_GRAPH_GRAPH_HXX_

#include <memory>
#include <vector>

using std::shared_ptr;
using std::vector;

class Node;
class Edge;

class Graph {
 public:
  Graph() {}
  void AddNode(int);
  void AddEdge(int, int, double = 1.0);
  shared_ptr<Node> GetNode(int);
  shared_ptr<Edge> GetEdge(int, int);
  vector<shared_ptr<Node>> GetRoots(int);
  bool IsCyclic();
  void Print();

 private:
  vector<shared_ptr<Node>> nodes_;
  vector<shared_ptr<Edge>> edges_;
};

#endif  // OWN_EXPERIMENTS_GRAPH_GRAPH_HXX_
