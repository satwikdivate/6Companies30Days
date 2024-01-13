 #include<bits/stdc++.h>
using namespace std;
 int maxRotateFunction(vector<int>& arr) {
        
        // int  ans=0;
        
        // for(int i=0;i<arr.size();i++){
        //     int temp=0;
        //     for(int j=0;j<arr.size();j++){
        //         cout<<arr[j]<<"  ";
        //         temp+=(arr[j]*j);
        //     }
        //     cout<<endl;
        //     ans=max(ans,temp);
        //     arr.push_back(arr[0]);
        // arr.erase(arr.begin()+0);
        // }

        // return ans;

        // Optimized approach
        int fo=0;
        // calculate the sum
        int sum = accumulate(arr.begin(), arr.end(), 0);


        // calaculate first sum i* arr[i]
        for(int i=0;i<arr.size();i++){
            fo+=arr[i]*i;
        }

        int fk=fo;
        int ans=fo;
        int n=arr.size();
        for(int i=1;i<arr.size();i++){
            fk=fk - (n)* arr[n-i] +sum;
            ans=max(ans,fk);
        }
        return ans;
    }