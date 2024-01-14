//   #include<bits/stdc++.h>
// using namespace std;

//  void treetograph(TreeNode *root,unordered_map<int,list<int>>&mp){
        
//         if(root==NULL)
//             return ;
        
//         mp[root->val];

//         if(root->left){
//             mp[root->val].push_back(root->left->val);
//             mp[root->left->val].push_back(root->val);
//             treetograph(root->left,mp);
//         }
//         if(root->right){
//             mp[root->val].push_back(root->right->val);
//             mp[root->right->val].push_back(root->val);
//             treetograph(root->right,mp);
//         }
//     }




//     int amountOfTime(TreeNode* root, int start) {
//         unordered_map<int,list<int>>mp;

//          treetograph(root,mp);

//         if(mp.size()==1)
//             return 0;
//          for(auto i:mp){

//              cout<<i.first<<"   ";
//              list<int>l=i.second;
//              for(auto i:l)
//                 cout<<i<<"  ";
//             cout<<endl;
//          }

//         // int bfs
//         queue<pair<int,int>>q;
//         unordered_set<int>visited;
//         q.push({start,0});
//         visited.insert(start);
//         int count=0;
//         int rescount=0;
//         while(!q.empty()){

//           auto  top=q.front();
//             q.pop();

//             int element=top.first;
            

          
//              for(auto i:mp[element]){

//                 if(!visited.count(i)){
//                     visited.insert(i);
//                     q.push(make_pair(i,top.second+1));
//                     count=max(count,top.second+1);
//                  }
//              }
            
//         }

//          return count;
     
//     }
//     // anothwer way
//      int maxDist = 0;
//     int amountOfTime(TreeNode* root, int start) {
//         dfs(root, start);
//         return maxDist;
//     }

//     int dfs(TreeNode* root, int start) {
//         if (!root) return 0;

//         int depth;
//         int leftDepth = dfs(root->left, start);
//         int rightDepth = dfs(root->right, start);

//         // Current node is the start
//         if (root->val == start) {
//             depth = -1;
//             maxDist = max(leftDepth, rightDepth);
//         // Current subtree does not contain start node
//         } else if (leftDepth >= 0 && rightDepth >= 0) {
//             depth = max(leftDepth, rightDepth) + 1;
//         // Current subtree contains start node
//         } else {
//             int dist = abs(leftDepth) + abs(rightDepth);
//             maxDist = max(dist, maxDist);
//             // Return the distance between the curr with the start
//             depth = min(leftDepth, rightDepth) - 1;
//         } 

//         return depth;
//     }