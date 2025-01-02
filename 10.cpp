// Read map grid <int>
// find 0's make them a base with 0 trails <pair <paint <int int>, int>>
// recursive search on each 0 to find consecutive numbers
// base case 0 (not 9) if number is 9 return 1
// check coord make it unique for every 9 set<coord>
// if find 9, retrun 0's valid base number ++

#include "utils.h"
#include <vector>

vector<pair<int, int>> findNextTrail(pair<int, int> pos, int num,
                                     grid theBigG) {
  if (num == 9) {
    return {pos};
  }
  vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  vector<pair<int, int>> coord;
  vector<pair<int, int>> tmp;
  for (auto d : dirs) {
    if (theBigG.value(pos + d) == to_string(num + 1)[0]) {
      tmp = findNextTrail(pos + d, num + 1, theBigG);
      coord.insert(coord.end(), tmp.begin(), tmp.end());
    }
  }
  return coord;
}

int main() {
  string filename = "10inp.txt";
  grid theBigG(filename);

  vector<pair<int, int>> zerosBase = theBigG.findAllChars('0');

  LL rs2 = 0;
  vector<pair<set<pair<int, int>>, int>> trailHeads;
  for (auto z : zerosBase) {
    vector<pair<int, int>> tmp;
    set<pair<int, int>> res;
    tmp = findNextTrail(z, 0, theBigG);
    for (auto a : tmp) {
      res.insert(a);
    }
    rs2 += tmp.size();
    trailHeads.push_back({res, res.size()});
  }

  LL rs = 0;
  for (auto a : trailHeads) {
    rs += a.second;
    // cout << a << endl;
  }
  cout << "Part 1: " << rs << endl;
  cout << "Part 2: " << rs2 << endl;

  return 0;
}