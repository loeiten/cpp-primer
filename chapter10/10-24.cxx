#include <iostream>
using std::cout;
using std::endl;

#include <algorithm>
using std::find_if;

#include <functional>
using std::bind;
using namespace std::placeholders;  // NOLINT

#include <string>
using std::string;

#include <vector>
using std::vector;

bool check_size(const string& s, const string::size_type sz) {
  return s.size() < sz;
}

int main() {
  vector<int> vi;
  string s = "Forever young!";

  // Populate the vector with even values
  for (int i = 0; i < 20; i += 2) {
    vi.push_back(i);
  }

  cout << "The string reads\n\"" << s << "\",\nand has size=" << s.size()
       << endl;
  cout << "\nElements of vector" << endl;
  for (const auto& el : vi) {
    cout << el << endl;
  }

  auto it = find_if(vi.begin(), vi.end(), bind(check_size, s, _1));

  cout << "The first match in our vector which a value greater than the string "
          "size is "
       << *it << endl;

  return 0;
}
