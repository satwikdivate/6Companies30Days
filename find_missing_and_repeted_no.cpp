#include<bits/stdc++.h>
using namespace std;
vector<int> findTwoElement(vector<int> arr, int n) {
        // code here
        vector<int>ans;
        int duplicate=-1,missing=-1;
        vector<int>res(n+1,0);;
        
        for(int i=0;i<n;i++)
            res[arr[i]]++;
        
        for(int i=0;i<=n;i++){
            // misiing
            if(res[i]==0){
                missing=i;
            }else if(res[i]==2){
                duplicate=i;
            }
        }
        
        ans.push_back(duplicate);
        ans.push_back(missing);
        return ans;
    }