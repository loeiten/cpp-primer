#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::getline;

#include <fstream>
using std::ifstream;

#include <sstream>
using std::istringstream;
using std::ostringstream;

#include <algorithm>
using std::find;

#include <map>
using std::map;

#include <string>
using std::string;

#include <exception>
using std::range_error;

map<string, string>* buildMap(ifstream* mapFilePtr,
                              map<string, string>* transformMapPtr) {
  string key;
  string value;

  while (*mapFilePtr >> key && getline(*mapFilePtr, value)) {
    if (value.size() > 1) {
      // .substr(1) skips the space
      (*transformMapPtr)[key] = value.substr(1);
    } else {
      throw range_error("No value found for \"" + key + "\"");
    }
  }

  return transformMapPtr;
}

string transform(ifstream* textFilePtr, map<string, string>* transformMapPtr) {
  string line;
  string word;
  ostringstream outStream;
  istringstream lineStream;
  auto end = transformMapPtr->cend();
  while (getline(*textFilePtr, line)) {
    lineStream = istringstream(line);
    while (lineStream >> word) {
      auto it = transformMapPtr->find(word);
      if (it != end) {
        outStream << (*transformMapPtr)[word];
      } else {
        outStream << word;
      }
      outStream << " ";
    }
    // https://stackoverflow.com/a/26492431/2786884
    outStream.seekp(-1, outStream.cur);
    outStream << "\n";
  }
  return outStream.str();
}

// NOTE: getline modifies the stream, so no const
string getTransformedText(ifstream* mapFilePtr, ifstream* textFilePtr) {
  map<string, string> transformMap;
  map<string, string>* transformMapPtr = &transformMap;

  transformMapPtr = buildMap(mapFilePtr, transformMapPtr);
  string transformedText = transform(textFilePtr, transformMapPtr);

  return transformedText;
}

int main() {
  ifstream mapFile("map.txt");
  ifstream textFile("text.txt");

  string transformedText = getTransformedText(&mapFile, &textFile);
  cout << "\nTransformed text:\n\"\n" << transformedText << "\"\n" << endl;

  return 0;
}
