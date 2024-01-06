#include<bits/stdc++.h>
using namespace std;
int countDistinct(vector<int>& arr, int k, int p) {
        
        set<string>ans;
        for(int i=0;i<arr.size();i++){

            int count=0;
            string s;

            for(int j=i;j<arr.size();j++){

                if(arr[j]%p==0)
                    count++;
                
                if(count>k)
                    break;

                s.push_back(arr[j]);
                ans.insert(s);
            }
        }
    return ans.size();
    }