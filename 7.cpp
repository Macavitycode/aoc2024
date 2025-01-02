#include "utils.h"
#include <string>
#define LL long long

using namespace std;

void printProc(pair<LL, vector<LL>> a) {
  cout << a.first << ": ";
  printVec1T(a.second);
}

vector<pair<LL, vector<LL>>> getRules(string f) {
  ifstream file(f);
  string line;
  vector<pair<LL, vector<LL>>> op;
  while (getline(file, line)) {
    vector<string> sl = split(line, ": ");
    LL v1 = stoll(sl[0]);
    vector<LL> v2;
    for (auto a : split(sl[1], " ")) {
      v2.push_back(stoll(a));
    }
    // printProc({v1, v2});
    op.push_back({v1, v2});
  }
  return op;
}

int main(int argc, char **argv) {
  string filename = "7inp.txt";
  vector<pair<LL, vector<LL>>> toProc = getRules(filename);

  // Read the file
  // Solve the problem
  // ???
  // profit

  LL validSum1 = 0;
  LL validSum2 = 0;

  for (auto a : toProc) {
    const int s = a.second.size();
    int n = pow(2, (s - 1)) - 1;

    while (n >= 0) {
      int tmp = n;
      LL LHS = a.second[0];
      for (int i = 1; i < s; i++) {
        if (tmp % 2) {
          LHS += a.second[i];
        } else {
          LHS *= a.second[i];
        }
        tmp = tmp / 2;
      }
      if (LHS == a.first) {
        validSum1 += LHS;
        // cout << "Found valid sum " << LHS << endl;
        break;
      }
      n--;
    }
  }

  for (auto a : toProc) {
    const int s = a.second.size();
    int n = pow(3, (s - 1)) - 1;

    while (n >= 0) {
      int tmp = n;
      LL LHS = a.second[0];
      for (int i = 1; i < s; i++) {
        switch (tmp % 3) {
        case 0: {
          LHS += a.second[i];
          break;
        }
        case 1: {
          LHS *= a.second[i];
          break;
        }
        case 2: {
          // concat here
          LHS = stoll(to_string(LHS) + to_string(a.second[i]));
          break;
        }
        default: {
          break;
        }
        }
        tmp = tmp / 3;
      }
      if (LHS == a.first) {
        validSum2 += LHS;
        // cout << "Found valid sum " << LHS << endl;
        break;
      }
      n--;
    }
  }

  cout << "Part 1: " << validSum1 << endl;
  cout << "Part 2: " << validSum2 << endl;
}