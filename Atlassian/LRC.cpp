 #include<bits/stdc++.h>
using namespace std;
class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;

    }
    
    void makemostrecentl(int key){
 //  remove the entry
            dll.erase(mp[key].first);
        // add at front to make it fresh
            dll.push_front(key);
            
    // update addess
            mp[key].first=dll.begin();
    }

    int get(int key) {
        if(mp.find(key)!=mp.end()){
            
             makemostrecentl(key);
        
        // return the elemenet
            return mp[key].second;
        }

        return -1;
    }
    
    void put(int key, int value) {
       
       if(mp.find(key)!=mp.end()){
           mp[key].second=value;
             makemostrecentl(key);
       }else {
           dll.push_front(key);
           mp[key]={dll.begin(),value};
           n--;
       }

    //    if(more than n elements)
    if(n<0){
        n++;
        int key=dll.back();
        // delete from map
        mp.erase(key);
        // delete from the queue
        dll.pop_back();
    }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */