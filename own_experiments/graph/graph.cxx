#include "graph.hxx"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "edge.hxx"
#include "node.hxx"

using std::cout;
using std::endl;
using std::find;
using std::find_if;
using std::invalid_argument;
using std::make_shared;
using std::range_error;
using std::shared_ptr;
using std::stringstream;
using std::vector;

void Graph::AddNode(int name) {
  Node new_node(name);

  for (const auto &node : nodes_) {
    if (new_node == *node) {
      stringstream ss("Node \"");
      ss << name << "\" already exists in graph";
      throw invalid_argument(ss.str());
    }
  }

  nodes_.push_back(make_shared<Node>(new_node));
}

void Graph::AddEdge(int from, int to, double weigth) {
  Edge new_edge(from, to, weigth);

  for (const auto &edge : edges_) {
    if (new_edge == *edge) {
      stringstream ss("Edge between \"");
      ss << from << "\" and \"" << to << "\" already exists in graph";
      throw invalid_argument(ss.str());
    }
  }

  // Add relationship between nodes
  auto node = GetNode(from);
  node->children_.push_back(to);
  node = GetNode(to);
  node->parents_.push_back(from);

  // Add edges to the vector
  edges_.push_back(make_shared<Edge>(new_edge));
}

shared_ptr<Node> Graph::GetNode(int name) {
  // https://stackoverflow.com/a/14253405/2786884
  Node new_node(name);
  auto it = find_if(nodes_.cbegin(), nodes_.cend(),
                    [&](shared_ptr<Node> const &p) { return *p == new_node; });

  if (it == nodes_.cend()) {
    stringstream ss("Node \"");
    ss << name << "\" not found in graph";
    throw range_error(ss.str());
  }

  return *it;
}

shared_ptr<Edge> Graph::GetEdge(int from, int to) {
  // https://stackoverflow.com/a/14253405/2786884
  Edge new_edge(from, to);
  auto it = find_if(edges_.cbegin(), edges_.cend(),
                    [&](shared_ptr<Edge> const &p) { return *p == new_edge; });

  if (it == edges_.cend()) {
    stringstream ss("Edge not found for node \"");
    ss << from << "\"";
    throw range_error(ss.str());
  }

  return *it;
}

vector<shared_ptr<Node>> Graph::GetRoots(int node_name) {
  // Empty root if cyclic or empty nodes_
  vector<shared_ptr<Node>> roots;
  if (nodes_.empty()) {
    return roots;
  }

  // Get root of current node
  vector<int> traversed;
  vector<int> skipped_parents;

  int parent_node;

  shared_ptr<Node> cur_node = GetNode(node_name);
  while (!cur_node->IsRoot()) {
    // Check not traversed
    auto it = find(traversed.cbegin(), traversed.cend(), cur_node->name_);
    if (it == traversed.cend()) {
      // The node has not been traversed
      traversed.push_back(cur_node->name_);
      // We know that there is a parent (due to IsRoot being false)
      parent_node = cur_node->parents_[0];
      if (cur_node->parents_.size() > 1) {
        // Add the other parents
        skipped_parents.insert(skipped_parents.end(),
                               cur_node->parents_.begin() + 1,
                               cur_node->parents_.end());
      }
      // Proceed to next node
      cur_node = GetNode(parent_node);
    } else {
      // Current node is cyclic, continue to skipped nodes
      break;
    }
  }

  // While loop has terminated, we can be at a root, or something cyclic
  if (cur_node->IsRoot()) {
    roots.push_back(cur_node);
  }

  // Now we need to add roots from the skipped_parents
  // We can do this with a recursive call
  for (const auto &parent : skipped_parents) {
    auto new_roots = GetRoots(parent);
    roots.insert(roots.end(), new_roots.begin(), new_roots.end());
  }
  return roots;
}

bool Graph::IsCyclic() {
  // FIXME: Fails if there is a cyclic graph which is not connected to nodes_[0]
  if (nodes_.empty()) {
    return false;
  }

  // Find all roots
  auto roots = GetRoots(nodes_[0]->name_);
  // If there are no roots, we can be sure that that the graph is cyclic as we
  // checked that nodes_ was not empty
  if (roots.empty()) {
    return true;
  }
  return false;
}

void Graph::Print() {
  // NOTE: We could have sorted at insert as explained here:
  //       http://www.cplusplus.com/forum/beginner/156680/#msg804736

  // NOTE: The elements of nodes_ are shared pointesr
  sort(nodes_.begin(), nodes_.end(),
       [](const shared_ptr<Node> n1, const shared_ptr<Node> n2) -> bool {
         return n1->name_ < n2->name_;
       });

  // Loose nodes
  for (const auto &node : nodes_) {
    if (node->children_.empty()) {
      cout << node->name_ << endl;
      continue;
    }

    // Connected nodes
    sort(node->children_.begin(), node->children_.end());
    for (const auto &child : node->children_) {
      // Find the matching edge to get the weigth
      auto edge = GetEdge(node->name_, child);
      cout << node->name_ << "  --(" << edge->weigth_ << ")-->  " << child
           << endl;
    }
  }
}
