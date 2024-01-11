 #include<bits/stdc++.h>
using namespace std;
int equalSubstring(string s, string t, int maxCost) {
       
        int i=0,j=0;
        int count=0;
        int tempans=0;
        int ans=0;
        while(j<s.size()){
            int first=s[j]-'a';
            int second=t[j]-'a';
              
            count=count+abs(first-second);
            if(count<=maxCost){
 ans=max(ans,j-i+1);
               j++;
            }
            else{
                int first=s[i]-'a';
                int second=t[i]-'a';
                int temp=abs(first-second);
                count-=temp;
               
                i++;
                j++;
                tempans=0;
            }
        // j++;
        }
    return ans;
    }