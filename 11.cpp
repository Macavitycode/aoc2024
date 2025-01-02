// Read inp vector<string>
// Rules in a if else ladder
// iters loop
// tmp
// loop over all stones
// - if stone == 0 -> 1 in tmp
// - if len[stone] %2 == 0 -> string split based on length add to tmp
// - else to_string(stoll (stone) * 2024 )in tmp

#include "utils.h"
#include <map>
#include <string>
#include <vector>

vector<LL> proc(LL a) {
  vector<LL> tmp;

  if (a == 0) {
    tmp.push_back(1);
  } else if (to_string(a).size() % 2 == 0) {
    string aa = to_string(a);
    int s = aa.size() / 2;

    tmp.push_back(stoll(aa.substr(0, s)));
    tmp.push_back(stoll(aa.substr(s)));
  } else {
    tmp.push_back(a * 2024);
  }
  return tmp;
}

vector<LL> ruledStones(vector<LL> inp) {
  vector<LL> tmp;
  for (auto a : inp) {
    vector<LL> tmp2 = proc(a);
    tmp.insert(tmp.end(), tmp2.begin(), tmp2.end());
  }
  return tmp;
}

map<pair<LL, int>, LL> cache;

LL part2(LL inp, int depth) {
  if (depth >= 75) {
    return 1;
  }
  if (cache.contains({inp, depth})) {
    return cache[{inp, depth}];
  }
  if (inp == 0) {
    LL ans = part2(1, depth + 1);
    cache[{inp, depth}] = ans;
    return ans;
  } else if (to_string(inp).length() % 2 == 0) {
    string aa = to_string(inp);
    LL ans = part2(stoll(aa.substr(0, aa.length() / 2)), depth + 1) +
             part2(stoll(aa.substr(aa.length() / 2)), depth + 1);
    cache[{inp, depth}] = ans;
    return ans;
  } else {
    LL ans = part2(inp * 2024, depth + 1);
    cache[{inp, depth}] = ans;
    return ans;
  }
}

int main() {
  string filename = "11inp.txt";
  vector<int> inp = fileToVec2int(filename)[0];
  vector<LL> stones;
  stones.insert(stones.end(), inp.begin(), inp.end());
  auto tmp = stones, tmp2 = stones;

  for (int i = 0; i < 25; i++) {
    tmp = ruledStones(tmp);
  }

  int depth = 0;
  LL nSizes = 0;

  for (int i = 0; i < tmp2.size(); i++) {
    nSizes += part2(tmp2[i], depth);
  }

  cout << "Part 1: " << tmp.size() << endl;
  cout << "Part 2: " << nSizes << endl;
  return 0;
}