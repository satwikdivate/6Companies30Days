#include<bits/stdc++.h>
using namespace std;

string encode(string s)
{     
  //Your code here 
    int i=0;
    string ans;
    
    while(i<s.size()){
        
        int j=i+1;
        int count=1;
        
        while(j<s.size() && s[i]==s[j]){
            j++;
            count++;
        }
        
        ans.push_back(s[i]);
        ans.push_back(count+'0');
        i=j;
    }
    return ans;
}     