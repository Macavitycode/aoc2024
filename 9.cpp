#include "utils.h"
#include <vector>
#define LL long long

LL part1(vector<int> f) {

  LL endLoc = f.size() - 1;
  int flag = 0;

  for (int i = 0; i < f.size(); i++) {
    if (f[i] == -1) {
      while (f[endLoc] == -1) {
        if (endLoc > i) {
          endLoc -= 1;
        } else {
          flag = 1;
          break;
        }
      }
      if (flag) {
        break;
      }
      int tmp = f[i];
      f[i] = f[endLoc];
      f[endLoc] = -1;
    }
    if (i > endLoc) {
      break;
    }
  }

  LL rs = 0;
  for (int i = 0; i < f.size(); i++) {
    if (f[i] == -1) {
      break;
    }
    rs += i * f[i];
  }
  return rs;
}

LL part2(vector<pair<int, int>> &nf) {
  for (int i = nf.size() - 1; i >= 0; i--) {
    if (nf[i].first != -1) {
      for (int j = 0; j < i; j++) {
        if (nf[j].first == -1 and nf[j].second >= nf[i].second) {
          nf[j].second -= nf[i].second;
          nf.insert(nf.begin() + j, nf[i]);
          nf[++i].first = -1;
          break;
        }
      }
    }
  }
  vector<int> f;
  for (auto a : nf) {
    for (int i = 0; i < a.second; i++) {
      f.push_back(a.first);
    }
  }

  LL rs = 0;
  for (int i = 0; i < f.size(); i++) {
    if (f[i] == -1) {
      continue;
    }
    rs += i * f[i];
  }
  return rs;
}

int main() {
  string filename = "9inp.txt";
  vector<string> vecStrInp = fileToVecString(filename);
  string diskMap = mergeVecString(vecStrInp);
  vector<int> f;
  vector<pair<int, int>> nf;
  bool flop = 1;
  int ID = 0;
  for (char ch : diskMap) {
    int nChars = stoi(string{ch});
    int tID = -1;
    for (int i = 0; i < nChars; i++) {
      if (flop) {
        tID = ID;
      }
      f.push_back(tID);
    }
    nf.push_back({tID, nChars});
    if (flop) {
      ID++;
    }
    flop ^= true;
  }

  LL rs1 = part1(f);
  LL rs2 = part2(nf);
  cout << "part 1: " << rs1 << endl;
  cout << "part 2: " << rs2 << endl;
}