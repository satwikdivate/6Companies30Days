#define pb push_back
 #include<bits/stdc++.h>
using namespace std;
 vector<int> LPS(string &txt,int n){
            
            int i=1;
            // length of previous ogest prfix and suffix
            int length=0;
            vector<int>p(txt.size(),0);
         
            while(i<n){
                
                if(txt[i]==txt[length]){
                    length++;
                    p[i]=length;
                    // incrment i
                    i++;
                }else{
                    // not match chhos just back lps value
                    if(length!=0)
                        length=p[length-1];
                    else{
                        // not found then inito with 0
                        p[i]=0;
                        i++;
                    }
                        
                }
            }
            return p;
        }
        
        
    vector<int> beautifulIndices(string s, string a, string b, int k) {
       int n=s.length();
            int m=a.length();
            
            vector<int>result;
            
             vector<int>lps=LPS(a,m);
            int i=0,j=0;
            
            while(i<n){
                
                if(s[i]==a[j] ){
                    i++;
                    j++;
                }
                if(j==m){
                    result.push_back(i-m);
                    j=lps[j-1];
                    
                }else if(s[i]!=a[j]){
                    
                    if(j!=0)
                        j=lps[j-1];
                    else
                        i++;
                }
            }

            vector<int>result1;
            m=b.length();
            vector<int>lps1=LPS(b,m);
            i=0,j=0;
            while(i<n){
                
                if(s[i]==b[j] ){
                    i++;
                    j++;
                }
                if(j==m){
                    result1.push_back(i-m);
                    j=lps1[j-1];
                    
                }else if(s[i]!=b[j]){
                    
                    if(j!=0)
                        j=lps1[j-1];
                    else
                        i++;
                }
            }

            vector<int>ans;

            for(int i=0;i<result.size();i++){

                for(int j=0;j<result1.size();j++){

                    if(abs(result[i]-result1[j])<=k){
                        ans.push_back(result[i]);
                         break;
                    }
                }
            }

            return ans;
    }