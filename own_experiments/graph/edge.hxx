#ifndef OWN_EXPERIMENTS_GRAPH_EDGE_HXX_
#define OWN_EXPERIMENTS_GRAPH_EDGE_HXX_

#include <vector>
using std::vector;

class Graph;

class Edge {
  friend class Graph;
  friend bool operator==(const Edge&, const Edge&);

 public:
  Edge(int parent, int child, double weigth = 1.0)
      : parent_(parent), child_(child), weigth_(weigth) {}
  int GetParent() const { return parent_; }
  int GetChild() const { return child_; }
  double GetWeigth() const { return weigth_; }

 private:
  int parent_;
  int child_;
  double weigth_;
};

inline bool operator==(const Edge& lhs, const Edge& rhs) {
  return lhs.parent_ == rhs.parent_ && lhs.child_ == rhs.child_;
}

#endif  // OWN_EXPERIMENTS_GRAPH_EDGE_HXX_
