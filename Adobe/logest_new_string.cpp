#include<bits/stdc++.h>
using namespace std;
int longestString(int x, int y, int z) {
        int ans=0;

        if(x==y){
            ans+=(x*4);
            ans+=(z*2);
            return ans;
        }

        int mn=min(x,y);
        ans+=(mn*2);
        ans+=((mn+1)*2);
        ans+=(z*2);
        return ans;
    } 
 
 int longestString(int x, int y, int z) {
        
        deque<int>ans;
        // 1 for x
        // 2 for y
        // 3 for z
        
        while(x>0 && y>0){
            ans.push_back(1);
            x--;
            ans.push_back(2);
            y--;
        }
        while(z>0){
            ans.push_front(3);
            z--;
        }

        if((ans[0]==3 || ans[0]==1) && y>0){
            ans.push_front(2);
            y--;
        }
        
        if(ans[ans.size()-1]==1 && y>0){
            ans.push_back(2);
            y--;
        }
        
        if((ans[ans.size()-1]==3 || ans[ans.size()-1]==2) && x>0){
            ans.push_back(1);
            x--;
        }

            return ans.size()*2;

    }