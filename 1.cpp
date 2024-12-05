#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

int main(){
    using namespace std;
    ifstream file("1inp.txt");
    int str;
    
    vector<int> v1, v2;
    int flag = 0;

    while(true) {
        if(file >> str) {
            if(flag) {
                v2.push_back(str);
            }
            else {
                v1.push_back(str);
            }
            flag ^= true;
        }
        else{
            break;
        }
    }

    // TODO: IMPORTANT
    // for(int i=0; i<v1.size(); i++) {
    //     cout << v1[i] << " " << v2[i] << "\n";
    // }

    // cout << "\n\nTHIS WORKS\n\n";
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    long long rs;
    for(int i=0; i<v1.size(); i++){
        rs += abs(v1[i] - v2[i]);
    }
    cout << "\n\n" << rs << "\n\n";

    long long ss = 0, oc, n;
    for(int i=0; i<v1.size(); i++){
        n = v1[i];
        oc = 0;
        for(int j=0; j<v2.size(); j++){
            if(n==v2[j]){
                oc += 1;
            }
        }
        ss += n*oc;
    }
    
    cout << "\n\n" << ss << "\n\n";

    return 0;
}