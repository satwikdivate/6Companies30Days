#include<bits/stdc++.h>
using namespace std;
 bool match(const string& s, const string & b) {
        int i = 0;
        for (const auto ch : s) {
            if (b[i] == ch) {
                i++;
            }
        }
        return i == b.size();
    }
class Solution {
public:
   
    

    string findLongestWord(string s, vector<string>& dictionary) {
        sort(dictionary.begin(), dictionary.end());
        string result;
        for (const auto & word : dictionary) {
            if (match(s, word)) {
                if (result.size() < word.size()) {
                    result = word;
                }
            }
        }
        return result;
    }
 
};