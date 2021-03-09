#ifndef OWN_EXPERIMENTS_GRAPH_NODE_HXX_
#define OWN_EXPERIMENTS_GRAPH_NODE_HXX_

#include <vector>
using std::vector;

class Graph;

class Node {
  friend class Graph;
  friend bool operator==(const Node&, const Node&);

 public:
  explicit Node(int name) : name_(name) {}
  bool IsRoot() { return children_.empty(); }
  bool IsLeaf() { return parents_.empty(); }

 private:
  const int name_;
  vector<int> parents_;
  vector<int> children_;
};

inline bool operator==(const Node& lhs, const Node& rhs) {
  return lhs.name_ == rhs.name_;
}

#endif  // OWN_EXPERIMENTS_GRAPH_NODE_HXX_
