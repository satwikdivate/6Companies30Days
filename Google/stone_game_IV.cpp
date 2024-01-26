 #include<bits/stdc++.h>
using namespace std;
static bool cmp(int a,int b){
    return a>b;
}

    int stoneGameVI(vector<int>& a, vector<int>& b) {
    vector<vector<int>>v;

    for(int i=0;i<a.size();i++){
        v.push_back({a[i]+b[i],a[i],b[i]});
    }

    sort(v.begin(),v.end(),greater<vector<int>>());
    int acount=0,bcount=0;

    for(int i=0;i<v.size();i++){

        if(i%2==0)
            acount+=v[i][1];
        else
            bcount+=v[i][2];
    }

    if(acount==bcount)
        return 0;
    
    if(acount<bcount)
        return -1;
    else
        return 1;
    }