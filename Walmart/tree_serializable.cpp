 #include<bits/stdc++.h>
using namespace std;
bool isValidSerialization(string preorder) {
        
      istringstream iss(preorder);
      string node;
      int availableslot=1;

      while(getline(iss,node,',')){
          availableslot--;

          if(availableslot<0)
            return false;
        
        if(node!="#")
            availableslot+=2;
      }
      return availableslot==0;
    }