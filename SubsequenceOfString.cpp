#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

//subsequence based problems
vector<string> sbsq(string s){
    if(s.empty()) return { "" };
    vector<string> smallString = sbsq(s.substr(1));
    //for abc 
    // smallString = {"","c","b","bc"}
    vector<string> ans = smallString;
    for(auto &u: smallString){
        u = s[0]+u;
        ans.push_back(u);
    }
    // ans = {"","c","b","bc","a","ac","ab","abc"}

    return ans;
}


int main (){
    string str ;
    cin >> str;
    vector<string> v = sbsq(str);
    cout << v.size() << endl;
    for(auto u: v) cout << u << endl;

   	return 0;
}
