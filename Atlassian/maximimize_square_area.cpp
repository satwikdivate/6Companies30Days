  #include<bits/stdc++.h>
using namespace std;
 int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
    sort(hBars.begin(),hBars.end());
    sort(vBars.begin(),vBars.end());

    int maxHbar=1;
    int currHbar=1;
    for(int i=0;i<hBars.size()-1;i++){

        if(hBars[i]+1 ==hBars[i+1])
            currHbar++;
        else
            currHbar=1;

        maxHbar=max(currHbar,maxHbar);
    }


    int maxVbar=1;
    int currVbar=1;
    for(int i=0;i<vBars.size()-1;i++){

        if(vBars[i]+1 ==vBars[i+1])
            currVbar++;
        else
            currVbar=1;

        maxVbar=max(currVbar,maxVbar);
    }
   int mini=min(maxVbar,maxHbar)+1;
   return mini*mini;
    }