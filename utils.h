#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ostream>
#include <regex>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <typeinfo>
#include <vector>

using LL = long long;

using namespace std;

template <class T> void printVec1T(vector<T> v);
template <class T> void printVec2T(vector<vector<T>> v);

void printVecString(vector<string> v);

vector<vector<int>> fileToVec2int(string inp, bool toPrint = false);

vector<string> fileToVecString(string inp, bool toPrint = false);

vector<string> regexExtract(string inp, string reg);

vector<string> split(const string s, const string delimiter);

void printMap(map<int, string> m);

class grid {
private:
  vector<string> data;
  int width, height;

public:
  grid(string inp, bool toPrint = false) {
    data = fileToVecString(inp, toPrint);
    width = data[0].size();
    height = data.size();
  }
  grid(vector<string> temp) {
    data = temp;
    width = data[0].length();
    height = data.size();
  }
  char value(int i, int j) {
    if (i < 0 || j < 0 || i >= height || j >= width) {
      return ' ';
    }
    return data[i][j];
  }
  char value(pair<int, int> head) { return value(head.first, head.second); }
  int get_width() { return width; }
  int get_height() { return height; }

  void print() { printVecString(data); }

  int replaceAt(pair<int, int> tmp, char ch) {
    /* Replaces char at given pos*/
    return replaceAt(tmp.first, tmp.second, ch);
  }

  int replaceAt(int x, int y, char ch) {
    /* Replaces char at given pos*/
    if (value(x, y) != '1' && ch != '1') {
      data[x][y] = ch;
      return 0;
    }
    return -1;
  }

  vector<pair<int, int>> findAllChars(char ch) {
    /* Returns all locations of given char in grid*/
    vector<pair<int, int>> LocList;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        if (value(i, j) == ch) {
          LocList.push_back({i, j});
        }
      }
    }
    return LocList;
  }

  set<char> findAllUnique(set<char> ignore = {}, bool toPrint = false) {
    /* Returns a set of all unique chars in data*/
    set<char> v;
    for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
        char val = value(i, j);
        if (not ignore.contains(val)) {
          v.insert(val);
        }
      }
    }
    if (toPrint) {
      for (auto a : v) {
        cout << a << ' ';
      }
      cout << endl;
    }
    return v;
  }
};

pair<int, int> operator+(pair<int, int> a, pair<int, int> b);

pair<int, int> operator-(pair<int, int> a, pair<int, int> b);

pair<int, int> operator-(pair<int, int> a);

string mergeVecString(vector<string> stringInp);

template <class T, class S>
ostream &operator<<(ostream &os, const pair<T, S> &p);

template <class T> ostream &operator<<(ostream &os, const set<T> &p);

template <class T> ostream &operator<<(ostream &os, const vector<T> &p);

template <class T, class S> ostream &operator<<(ostream &os, const map<T, S> &p);

template <class T> void printVec1T(vector<T> v) {
  /*Func to prT 1d vec */
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

template <class T> void printVec2T(vector<vector<T>> v) {
  /*Func to print 2d vec */
  for (int i = 0; i < v.size(); i++) {
    printVec1T(v[i]);
  }
}

void printVecString(vector<string> v) {
  cout << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}

vector<vector<int>> fileToVec2int(string inp, bool toPrint) {
  /*Func to split file to vector of vectors of int*/

  using namespace std;
  ifstream file(inp);
  string l;

  vector<vector<int>> lines;

  while (getline(file, l)) {
    vector<int> ll;
    string linestring;
    stringstream ss(l);
    while (getline(ss, linestring, ' ')) {
      ll.push_back(stoi(linestring));
    }
    lines.push_back(ll);
  }

  if (toPrint) {
    printVec2T(lines);
  }
  return lines;
}

vector<string> fileToVecString(string inp, bool toPrint) {
  /*Func to split file to vector of vectors of int*/
  using namespace std;
  ifstream file(inp);
  string l;
  vector<string> vs;
  while (getline(file, l)) {
    vs.push_back(l);
  }
  if (toPrint) {
    printVecString(vs);
  }
  return vs;
}

vector<string> regexExtract(string inp, string reg) {
  /* Func to return regex matched vec of strings*/
  regex r(reg);
  smatch m;
  vector<string> out;
  string tmp = inp;
  while (regex_search(tmp, m, r)) {
    out.push_back(m.str());
    tmp = m.suffix().str();
  }
  return out;
}

vector<string> split(const string s, const string delimiter) {
  vector<string> tokens;
  size_t last = 0;
  size_t next = 0;
  while ((next = s.find(delimiter, last)) != string::npos) {
    tokens.push_back(s.substr(last, next - last));
    last = next + delimiter.length();
  }
  tokens.push_back(s.substr(last));
  return tokens;
}

void printMap(map<int, string> m) {
  for (int i = 0; i < m.size(); i++) {
    cout << i << ": " << m[i] << endl;
  }
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return {a.first - b.first, a.second - b.second};
}

pair<int, int> operator-(pair<int, int> a) { return {-a.first, -a.second}; }

string mergeVecString(vector<string> stringInp) {
  string s;
  for (auto a : stringInp) {
    s += a;
  }
  return s;
}

template <class T, class S>
ostream &operator<<(ostream &os, const pair<T, S> &p) {
  return os << "{" << p.first << ", " << p.second << "}";
}

template <class T> ostream &operator<<(ostream &os, const set<T> &p) {
  for (auto i : p) {
    os << i << " ";
  }
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &p) {
  for (auto i : p) {
    os << i << " ";
  }
  return os;
}

template <class T, class S> ostream &operator<<(ostream &os, const map<T, S> &p) {
  for (auto i : p) {
    os << i.first << " : " << i.second << endl;
  }
  return os;
}