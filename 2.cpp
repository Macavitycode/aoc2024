#include "utils.h"

using namespace std;

int safeCheck1(vector<int> li)
{
    bool inc = (li[0] - li[1] > 0) ? true : false;
    int flag = 1;

    for (int j = 0; j < li.size() - 1; j++)
    {
        int cur = li[j];
        int nex = li[j + 1];

        bool ci = (cur - nex > 0) ? true : false;

        if (ci != inc || cur == nex || abs(cur - nex) > 3)
        {
            flag = 0;
        }
    }

    return flag;
}

int safeCheck2(vector<int> li)
{
    vector<int> res;

    for (int i = 0; i < li.size(); i++)
    {
        vector<int> tmp = li;
        tmp.erase(tmp.begin() + i);
        res.push_back(safeCheck1(tmp));
    }

    int h = 0;
    for (int i = 0; i < res.size(); i++)
    {
        h |= res[i];
    }
    return h;
}

int main(int argc, char *argv[])
{
    using namespace std;
    string inp = "2inp.txt";

    vector<vector<int>> lines = fileToVec2int(inp);

    int safe1 = 0;
    int safe2 = 0;

    for (int i = 0; i < lines.size(); i++)
    {
        safe1 += safeCheck1(lines[i]);
        safe2 += safeCheck2(lines[i]);
    }

    cout << "1st: " << safe1 << endl
         << "2nd: " << safe2 << endl;
    return 0;
}