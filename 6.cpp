#include "utils.h"

using namespace std;

class state {
public:
  pair<int, int> coord;
  int dir;
  state(pair<int, int> c, int d) {
    coord = c;
    dir = d;
  }
};

bool operator<(const state LHS, const state RHS) {
  if (LHS.coord.first == RHS.coord.first &&
      LHS.coord.second == RHS.coord.second) {
    return LHS.dir < RHS.dir;
  } else if (LHS.coord.first == RHS.coord.first) {
    return LHS.coord.second < RHS.coord.second;
  } else {
    return LHS.coord.first < RHS.coord.first;
  }
}

int checker(grid theBigG, pair<int, int> tmp, pair<int, int> head, int dir) {
  // Checks if adding a # ends outside or on previous state
  set<state> stateSet;
  vector<pair<int, int>> diffs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  pair<int, int> barrier = tmp + diffs[dir];
  // pair<int, int> barrier = tmp;

  if (theBigG.value(barrier) == '#') {
    return 0;
  }
  theBigG.replaceAt(barrier, '#');

  tmp = head;
  dir = 0;

  while (theBigG.value(tmp) != ' ') {

    if (stateSet.contains({tmp, dir})) {
      return 1;
    }
    if (theBigG.value(tmp) == '#') {
      tmp = tmp - diffs[dir];
      dir = (dir + 1) % 4;
    } else {
      stateSet.insert(state(tmp, dir));
      tmp = tmp + diffs[dir];
    }
  }
  return 0;
}

int main(int argc, char *argv[]) {
  // Read inp
  // Make ruleset
  // iterate inp using ruleset over boundary
  // mark X's and count =>> profit

  string filename = "6inp.txt";
  grid theBigG(filename);

  // theBigG.print();

  pair<int, int> head;
  int i, j;

  for (i = 0; i < theBigG.get_height(); i++) {
    for (j = 0; j < theBigG.get_width(); j++) {
      if (theBigG.value(i, j) == '^') {
        head = {i, j};
      }
    }
  }

  set<pair<int, int>> visited;
  int dir = 0; // up right down left
  vector<pair<int, int>> diffs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  pair<int, int> tmp = head;
  int ghostBarriers = 0;
  set<pair<int, int>> setBarriers;

  while (theBigG.value(tmp) != ' ') {
    if (theBigG.value(tmp) == '#') {
      tmp = tmp - diffs[dir];
      dir = (dir + 1) % 4;
    } else {
      // TODO RUN CHECKER HERE
      if (checker(theBigG, tmp, head, dir)) {
        if (!setBarriers.contains(tmp + diffs[dir])) {
          setBarriers.insert(tmp + diffs[dir]);
          ghostBarriers += 1;
          // cout << "Here!: ";
          // printPair(tmp + diffs[dir]);
          // cout << endl;
        }
      }
      visited.insert(tmp);
      tmp = tmp + diffs[dir];
    }
  }

  cout << "Part 1: " << visited.size() << endl;
  cout << "Part 2: " << ghostBarriers;

  return 0;
}