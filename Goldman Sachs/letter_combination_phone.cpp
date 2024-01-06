 #include<bits/stdc++.h>
using namespace std;
 void solve(int index,string dight,vector<string> &mapping,string &ds,vector<string>&ans){
        
        if(index>=dight.size()){
            // we reach to end state so add the ans
            ans.push_back(ds);
            return;
        }

        int no=dight[index]-'0';
        string res=mapping[no];

        for(int i=0;i<res.size();i++){
            // add the element
            ds.push_back(res[i]);
            solve(index+1,dight,mapping,ds,ans);
            // backtract and remove the element
            ds.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return {};
   string ds;
    vector<string>mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>ans;

    solve(0,digits,mapping,ds,ans);

    return ans;

    }