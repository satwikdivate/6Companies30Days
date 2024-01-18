// class Solution {
// public:
//     int getLastMoment(int n, vector<int>& left, vector<int>& right) {
//      int result=0;

//      for(int i=0;i<left.size();i++)   
//         result=max(left[i],result);
    
//     for(int i=0;i<right.size();i++)
//         result=max(n-right[i],result);

//     return result;
//     }
// };