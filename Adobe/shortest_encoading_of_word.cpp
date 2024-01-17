 #include<bits/stdc++.h>
 using namespace std;
 int minimumLengthEncoding(vector<string>& words) {
        set<string>s1(words.begin(),words.end());
        set<string>s2(words.begin(),words.end());

        for(auto parts:words){
// start from 1 becasue if we start from 0 then entire string is deleted
            for(int i=1;i<parts.size();i++){

                // erase tfrom s2 if that substring is present 
                s2.erase(parts.substr(i));
            }
        }

        // count all then elemnt length and every lword length add 1 for #
        int count=0;
        for(auto i:s2){
            count+=i.size()+1;
        }

        return count;
    }