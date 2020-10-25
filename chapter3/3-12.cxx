#include <string>
#include <vector>

using std::string;
using std::vector;

int main() {
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused"
  vector<vector<int>> ivec;
  // vector<string> svec = ivec;  // No conversion available
  vector<string> svec(10, "null");
#pragma clang diagnostic pop
  return 0;
}
