  #include<bits/stdc++.h>
using namespace std;
  vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string>mp;
        if(s.size()==10)
            return {};
        string str;
        int i=0;
        char ch=s[0];
        int count=0;
        for(i=0;i<10;i++){
            if(ch!=s[i])
                count++;
            str.push_back(s[i]);
        }
        vector<string>ans;
        mp.insert(str);
        if(count==0){
            ans.push_back(str);
            return ans;
        }
        int j=10;
        for(;j<s.size();j++){
            str.push_back(s[j]);
            str.erase(str.begin()+0);
            i++;

            if(mp.find(str)!=mp.end()){
                ans.push_back(str);
            }else
                mp.insert(str);
        }
        return ans;
    }