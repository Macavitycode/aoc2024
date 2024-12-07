#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <sstream>

using namespace std;

void printVec1int(vector<int> v)
{
    /*Func to print 1d vec */
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

void printVec2int(vector<vector<int>> v)
{
    /*Func to print 2d vec */
    for (int i = 0; i < v.size(); i++)
    {
        printVec1int(v[i]);
    }
}

void printVecString(vector<string> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}

vector<vector<int>> fileToVec2int(string inp, bool toPrint = false)
{
    /*Func to split file to vector of vectors of int*/

    using namespace std;
    ifstream file(inp);
    string l;

    vector<vector<int>> lines;

    while (getline(file, l))
    {
        vector<int> ll;
        string linestring;
        stringstream ss(l);
        while (getline(ss, linestring, ' '))
        {
            ll.push_back(stoi(linestring));
        }
        lines.push_back(ll);
    }

    if (toPrint)
    {
        printVec2int(lines);
    }
    return lines;
}

vector<string> fileToVecString(string inp, bool toPrint = false)
{
    /*Func to split file to vector of vectors of int*/

    using namespace std;
    ifstream file(inp);
    string l;
    vector<string> vs;
    while (getline(file, l))
    {
        vs.push_back(l);
    }
    if (toPrint)
    {
        printVecString(vs);
    }
    return vs;
}