
  #include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node *last;
    node(int data){
        this->data=data;
        // next=
    }

};

void add(node *&top,node *&last,int data){
    node *temp=new node(data);
    temp->next=NULL;

    if(top==NULL){
        top=temp;
        temp->next=temp;
        last=temp;
        return ;
    }

    last->next=temp;
    last=temp;

    temp->next=top;

}

node * deleteNode(node *top,int k){

  
        
    if(top==top->next)
        return top;
    int count=1;
    node *res=NULL;
    while(count<=k-1){
        res=top;
        top=top->next;
        count++;
    }
    node  *ans=top->next;
    res->next=top->next;
    return ans;
    

}

void display(node *top){
    node *temp=top;
    do{
        cout<<temp->data<<"  ";
        temp=temp->next;
    }while(temp!=top);
    cout<<endl;
}
class Solution {

public:
    int findTheWinner(int n, int k) {

        // gives TLE  
        // if(k==1)
        //     return n;

        // node *top=NULL,*last=NULL;
        // for(int i=1;i<=n;i++){
        //     add(top,last,i);
        // }

        // // display(top->next->next);
        // int count=n;
        // while(n!=0){
        //     top=deleteNode(top,k);
        //     display(top);
        //     n--;
        // }
        // return top->data;

        // simple solution
        int winner=0;
        for(int i=2;i<=n;i++){

            winner=(winner+k)%i;
        }
        return winner+1;
    }
};