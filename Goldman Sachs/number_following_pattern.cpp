#include<bits/stdc++.h>
using namespace std;

string printMinNumberForPattern(string s){
        // code here 
        
       stack<int>st;
       string ans;
       for(int i=0;i<=s.size();i++){
           
           st.push(i+1);
           
           if(s[i]=='I'){
               
               while(!st.empty()){
                   ans+=to_string(st.top());
                   st.pop();
               }
               
           }
       }
       
       while(!st.empty()){
           ans+=to_string(st.top());
           st.pop();
       }
       
       return ans;
    }