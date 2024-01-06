#include<bits/stdc++.h>
#include<random>
using namespace std;

class Solution {
public:
  set<pair<int,int>>st;
    int m,n;
    Solution(int m, int n) {
        this->m=m;
        this->n=n;
    }
    
    vector<int> flip() {
        int x=random()%m;
        int y=random()%n;

        if(st.find({x,y})!=st.end())
            return flip();
        
       st.insert({x,y});
        return {x,y};
    }
    
    void reset() {
        st.clear();
    }
};