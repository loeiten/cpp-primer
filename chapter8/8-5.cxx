#include <iostream>
using std::cerr;
using std::cout;
using std::endl;

#include <fstream>
using std::getline;
using std::ifstream;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main() {
  ifstream in;
  vector<string> lines;
  vector<string> words;
  string tmp;
  string filename = "data_8-5.txt";

  in.open(filename);
  if (in) {
    while (getline(in, tmp)) {
      lines.push_back(tmp);
    }
    in.close();
  } else {
    cerr << "Failed to open " << filename << endl;
  }

  cout << "\nPRINTING LINES\n\n" << string(80, '=') << '\n' << endl;
  for (const auto &line : lines) {
    cout << line << endl;
  }

  in.open(filename);
  if (in) {
    while (in >> tmp) {
      words.push_back(tmp);
    }
    in.close();
  } else {
    cerr << "Failed to open " << filename << endl;
  }

  cout << "\nPRINTING WORDS\n\n" << string(80, '=') << '\n' << endl;
  for (const auto &word : words) {
    cout << word << endl;
  }
  return 0;
}
