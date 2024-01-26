  #include<bits/stdc++.h>
using namespace std;
 bool asteroidsDestroyed(int m, vector<int>& arr) {
        
        long long mass=m;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){

            if(mass<arr[i])
                return false;
            mass+=arr[i];
        }
        return true;
    }