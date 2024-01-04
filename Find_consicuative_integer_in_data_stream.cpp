class DataStream {
public:
    


    int value,k;
    int count;
    DataStream(int value, int k) {
        this->value=value;
        this->k=k;
        count=0;
    }
    
    bool consec(int num) {
        if(num==value)
            count++;
        else
            count=0;
        
        if(count>=k)
            return true;
        else
            return false;



// another_approach
    // map<int,int>mp;
    // queue<int>q;
        // q.push(num);
        // mp[num]++;

        // if(q.size()>=k){

        //     if(q.size()>k){
        //         mp[q.front()]--;
        //         if(mp[q.front()]==0)
        //             mp.erase(q.front());
        //         // pop the element
        //         q.pop();
        //     }
        //      if(mp.size()==1 && mp[value]>0){
        //         return true;
        //     }else
        //         return false;
        // }else
        //     return false;
    }
};
