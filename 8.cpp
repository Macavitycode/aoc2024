#include "utils.h"

void printThisMap(map<char, vector<pair<int, int>>> m) {
  for (auto a : m) {
    cout << a.first << " : ";
    for (auto b : a.second) {
      cout << "{" << b.first << "," << b.second << "} ";
    }
    cout << endl;
  }
}

int main() {
  string filename = "8inp.txt";
  grid theBigG(filename);

  auto uni = theBigG.findAllUnique({'.'});

  map<char, vector<pair<int, int>>> antennaPoses;

  for (auto a : uni) {
    vector<pair<int, int>> loc = theBigG.findAllChars(a);
    antennaPoses[a] = loc;
  }
  //   printThisMap(antennaPoses);

  set<pair<int, int>> antiNodeSet;
  for (auto antenna : antennaPoses) {
    auto sec = antenna.second;
    for (int i = 0; i < sec.size() - 1; i++) {
      for (int j = i + 1; j < sec.size(); j++) {
        auto diff = sec[j] - sec[i];
        auto diffM = diff;
        antiNodeSet.insert(sec[i]);
        antiNodeSet.insert(sec[j]);
        while (theBigG.value(sec[i] - diffM) != ' ') {
          antiNodeSet.insert(sec[i] - diffM);
          diffM = diffM + diff;
        }
        diffM = diff;
        while (theBigG.value(sec[j] + diffM) != ' ') {
          antiNodeSet.insert(sec[j] + diffM);
          diffM = diffM + diff;
        }
      }
    }
  }

cout << "Part 2: " << antiNodeSet.size();
}