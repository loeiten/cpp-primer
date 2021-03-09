#include <iostream>

#include "graph.hxx"
using std::cout;
using std::endl;

int main() {
  Graph g;

  // Add graphs
  g.AddNode(5);
  g.AddNode(77);
  g.AddNode(1);

  // Add edges
  g.AddEdge(77, 1);
  g.AddEdge(77, 5, 7.3);

  // Print
  g.Print();
  auto res = g.IsCyclic() ? "" : "not ";
  cout << "g is " << res << "cyclic" << endl;

  // Make cyclic
  cout << "\nMaking g cyclic" << endl;
  g.AddEdge(1, 77);

  // Print
  g.Print();
  res = g.IsCyclic() ? "" : "not ";
  cout << "g is " << res << "cyclic" << endl;
  return 0;
}
