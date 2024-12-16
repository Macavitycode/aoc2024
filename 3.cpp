#include "utils.h"

long long parseValid(string fs)
{
    string m = "mul\\(\\d{1,3},\\d{1,3}\\)";
    vector<string> vecstr = regexExtract(fs, m);

    string tmp;
    long long out = 0, a, b;

    for (int i = 0; i < vecstr.size(); i++)
    {
        tmp = vecstr[i].substr(4, vecstr[i].length() - 5);
        a = stoll(tmp.substr(0, tmp.find(',')));
        b = stoll(tmp.substr(tmp.find(',') + 1));
        out += a * b;
    }
    return out;
}

int main(int argc, char *argv[])
{
    string inp = "3inp.txt";
    vector<string> vs = fileToVecString(inp);

    int matches = 0;
    string fs;
    for (int i = 0; i < vs.size(); i++)
    {
        fs.append(vs[i]);
    }

    long long out = parseValid(fs);

    cout << "Part 1: " << out << endl;

    string tmp = fs, stmp;
    int i = 0;
    out = 0;
    while (true)
    {
        i = tmp.find("don't()");
        if (i != string::npos)
        {
            stmp = tmp.substr(0, i);
            tmp = tmp.substr(i + 7);
            out += parseValid(stmp);

            if (tmp.find("do()") != string::npos)
            {
                tmp = tmp.substr(tmp.find("do()") + 4);
            }
            else
            {
                break;
            }
        }
        else
        {
            out += parseValid(tmp);
            break;
        }
    }
    cout << "Part 2: " << out;

    return 0;
}