#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <set>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

using namespace std;

void printVec1int(vector<int> v) {
  /*Func to print 1d vec */
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

void printVec2int(vector<vector<int>> v) {
  /*Func to print 2d vec */
  for (int i = 0; i < v.size(); i++) {
    printVec1int(v[i]);
  }
}

void printVecString(vector<string> v) {
  cout << endl;
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << endl;
}

vector<vector<int>> fileToVec2int(string inp, bool toPrint = false) {
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
    printVec2int(lines);
  }
  return lines;
}

vector<string> fileToVecString(string inp, bool toPrint = false) {
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
      return '1';
    }
    return data[i][j];
  }
  char value(pair<int, int> head) { return value(head.first, head.second); }
  int get_width() { return width; }
  int get_height() { return height; }

  void print() { printVecString(data); }

  int replaceAt(pair<int, int> tmp, char ch) {
    return replaceAt(tmp.first, tmp.second, ch);
  }

  int replaceAt(int x, int y, char ch) {
    if (value(x, y) != '1' && ch != '1') {
      data[x][y] = ch;
      return 0;
    }
    return -1;
  }
};

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
  return {a.first + b.first, a.second + b.second};
}

pair<int, int> operator-(pair<int, int> a, pair<int, int> b) {
  return {a.first - b.first, a.second - b.second};
}

void printPair(pair<int, int> a){
  cout << a.first << ' ' << a.second;
}