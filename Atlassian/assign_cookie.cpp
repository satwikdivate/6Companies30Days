 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i=0,j=0;
        int count=0;
        while(i<s.size() && j<g.size()){

            if(s[i]>=g[j]){
                j++;
                count++;
            }
            i++;
        }

        return count;
    }
};