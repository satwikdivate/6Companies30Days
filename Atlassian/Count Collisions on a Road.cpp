#include<bits/stdc++.h>
using namespace std;
int countCollisions(string directions) {
       int ans=0;
       int collision=0;
       int right=0,left=0,stationary=0;

       for(int i=0;i<directions.size();i++) {

            if(directions[i]=='R')
                right++;

            if(directions[i]=='S'){
              stationary=1;
                ans=ans+right;
                right=0;
            }

            if(directions[i]=='L'){

                if(right>0){
                    ans=ans+=right+1;
                    right=0;
                    collision=1;
                }else if(stationary==1){
                    ans++;
                    collision=1;
                }else if(collision==1)
                    ans++;
            }
       }
       return ans;
    }