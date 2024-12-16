#include "utils.h"

using namespace std;

tuple<map<int, vector<int>>, vector<vector<int>>> getRules(string f)
{
    ifstream file(f);
    string line;

    vector<string> rules, input;
    while (getline(file, line))
    {
        if (line.empty())
        {
            break;
        }
        rules.push_back(line);
    }
    while (file >> line)
    {
        input.push_back(line);
    }

    map<int, vector<int>> rulemap;
    for (auto r : rules)
    {
        vector<string> ints = split(r, "|");
        rulemap[stoi(ints[0])].push_back(stoi(ints[1]));
    }
    vector<vector<int>> pages;
    {
        for (auto i : input)
        {
            vector<int> temp;
            for (auto val : split(i, ","))
            {
                temp.push_back(stoi(val));
            }
            pages.push_back(temp);
        }
    }
    return {rulemap, pages};
}

void printRulemap(map<int, vector<int>> rulemap)
{
    for (auto r : rulemap)
    {
        cout << r.first << ':';
        for (auto rs : r.second)
        {
            cout << rs << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    // Read the data split into rules (map) and pages (vec<ints>)
    // Rule map is indexed by left side of | in rules section
    // iterate through elements and check if latter numbers are in the rule map
    // if all rules are satisfied, add middle number to sum

    string filename = "5inp.txt";
    map<int, vector<int>> rulemap;
    vector<vector<int>> pages;

    tie(rulemap, pages) = getRules(filename);

    // printRulemap(rulemap);
    // printVec2int(pages);
    vector<vector<int>> inOrder, outOfOrder, sortedOrder;

    for (auto p : pages)
    {
        int flag = 1;
        for (int i = 0; i < p.size() - 1; i++)
        {
            int lhs = p[i];
            for (int j = i + 1; j < p.size(); j++)
            {
                int rhs = p[j];
                vector<int> ss = rulemap[rhs];
                if (find(ss.begin(), ss.end(), lhs) != ss.end())
                {
                    // lhs is contained in rhs
                    // not in order
                    flag = 0;
                }
            }
        }

        if (flag)
        {
            // cout << "\nIn order ";
            // printVec1int(p);
            inOrder.push_back(p);
        }
        else
        {
            outOfOrder.push_back(p);
        }
    }

    for (auto o : outOfOrder)
    {
        for (int i = 0; i < o.size() - 1; i++   )
        {
            for (int j = i + 1; j < o.size(); j++)
            {
                int lhs = o[i];
                int rhs = o[j];

                // Compare o[i], o[j]: swap if rulemap[j] contains i
                vector<int> ss = rulemap[rhs];
                if (find(ss.begin(), ss.end(), lhs) != ss.end())
                {
                    int tmp = lhs;
                    o[i] = rhs;
                    o[j] = tmp;
                }
            }
        }
        sortedOrder.push_back(o);
    }

    int rs1 = 0, rs2 = 0;
    for (auto o : inOrder)
    {
        rs1 += o[o.size() / 2];
    }
    cout << "Part 1: " << rs1 << endl;

    for (auto o : sortedOrder)
    {
        rs2 += o[o.size() / 2];
    }
    cout << "Part 2: " << rs2 << endl;

    return 0;
}