   #include<bits/stdc++.h>
using namespace std;
 
 vector<string> findHighAccessEmployees(vector<vector<string>>& acc) {
        
        unordered_map<string,vector<int>>temp;
        vector<string>ans;
        for(int i=0;i<acc.size();i++){
            temp[acc[i][0]].push_back(stoi(acc[i][1]));
        }

        for(const auto &it:temp) {

            auto time=it.second;

            if(time.size()<3)
                continue;
            
            int count=1;
            vector<int>res=time;
            sort(res.begin(),res.end());
            for(int i=0;i<res.size()-2;i++){

                if(res[i+2]-res[i]<100){
                    ans.push_back(it.first);
                    break;
                }
                    
            }
        }
        
        // for(int i=0;i<ans.size();i++)
        //     cout<<ans[i]<<endl;
        return ans;
    }