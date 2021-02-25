#include <iostream>
using std::endl;
using std::ostream;

#include "queryResult_12-27.hxx"

ostream& print(ostream& os, QueryResult qr) {
  os << qr.query << " occurs " << qr.lines->size()
     << (qr.lines->size() == 1 ? " time" : " times") << endl;
  // NOTE: lines is a smartpointer which needs to be dereferenced
  //        lines is a member of qr, and qr called by value
  for (auto lineIndex : *(qr.lines)) {
    // NOTE: line number = lineIndex +1
    os << "\t(line " << lineIndex + 1 << ") " << (*(qr.file))[lineIndex]
       << endl;
  }

  return os;
}
