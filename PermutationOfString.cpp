#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

// Permutation of a string
vector<string> permute(string s){
    if(s.size() == 1) return { s };

    vector<string> smallPermute = permute(s.substr(1));
    // for abc
    // smallPermute = {bc,cb};

    vector<string> ans;
    for(auto str: smallPermute){
        int smsz = str.size();

        for(int i = 0; i <= smsz; i++){
            string temp = str;
            string szero = s.substr(0,1);
            temp.insert(i,(szero));
            ans.push_back(temp);

        }
    }
    // ans = {abc,bac,bca, -> inserting a at every pos of bc
    // 		  acb,cab,cba  -> inserting a at every pos of cb
	//		 };

    // removing duplicates from ans
    set<string> st;
    for(auto u: ans){
        st.insert(u); 
    } 
    ans.clear(); 
    for(auto u: st){
        ans.push_back(u);
    }
    
    return ans;
}

int main(){
    string str;
    cin >> str;
    std::vector<string> ans = permute(str);

    for(auto s: ans) cout << s << endl;

    return 0;
}