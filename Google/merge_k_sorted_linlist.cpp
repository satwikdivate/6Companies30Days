// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
//  #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:

// static void add(ListNode * &head,int data){

//     ListNode *temp=new ListNode(data);
//     head->next=temp;
//     head=head->next;
// }
//     ListNode* mergeKLists(vector<ListNode*>& list) {
//         vector<int>elements;

//         for(int i=0;i< list.size();i++){

//             ListNode *temp=list[i];
//             while(temp!=NULL){
//                 elements.push_back(temp->val);
//                 temp=temp->next;
//             }
//         }

//         sort(elements.begin(),elements.end());
//         ListNode * start=new ListNode(-1);
//         ListNode *end=start;

//         for(int i=0;i<elements.size();i++){
//             add(end,elements[i]);
//         }

//         return start->next;
//     }
// };