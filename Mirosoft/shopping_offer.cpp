 #include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<string,int>mp;
    int solve(int spi, vector<int>& price, vector<vector<int>>& special,vector<int> needs) {
        if(spi == special.size()){
            int res = 0;
            for (int k = 0; k < needs.size(); k++) {
                if (needs[k] != 0)    res += needs[k] * price[k];
            }
            return res;
        }
        string ok = "";
        ok+=to_string(spi);
        ok+="@";

        
        int ans = 0;
        bool flag = true;
        for (int i = 0; i < special[spi].size() - 1; i++) {
            if (special[spi][i] > needs[i]) {
                flag = false;
            }
            ok+=to_string(needs[i]);
            ok+="@";
        }
        if(mp.count(ok))    return mp[ok];
        if (flag) {
            ans = solve(spi + 1, price, special, needs);
            for (int i = 0; i < special[spi].size() - 1; i++) {
                needs[i] -= special[spi][i];
            }
            ans = min(ans, solve(spi, price, special, needs) + special[spi].back());
        } else {
            ans = solve(spi + 1, price, special, needs);
        }
        return mp[ok] = ans;
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special,vector<int>& needs) {
        
        return solve(0, price, special, needs);
    }
};