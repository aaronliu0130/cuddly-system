/*
 * 24.lfu-cache.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/lfu-cache/description
 *      For a cache with capacity k, if the cache is full and need to evict a key in it, the key with the lease frequently used will be kicked out.
 */
#include "../utils/utils.h"

class LFUCache {
public:
    /*
    * @param capacity: An integer
    */LFUCache(int capacity):capacity(capacity) {
        // do intialization if necessary
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        if(storage.count(key))
            update(key)=value;
        else{
        	#pragma GCC diagnostic ignored "-Wsign-compare"
            if(storage.size()>=capacity){
                auto freq=f2k.begin();
                while(!freq->second.size()) {
                    f2k.erase(freq);
                    freq=f2k.begin();
                };
                auto ite=freq->second.begin();
                storage.erase(*ite);
                freq->second.erase(ite);
            }
            f2k[1].push_back(key);
            storage[key]={value,1};
        }
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        // write your code here
        if(!storage.count(key))
            return -1;
        return update(key);
    }
private:
    map<int,vector<int>> f2k;
    unordered_map<int,pair<int,int>> storage;
    int capacity;
    int& update(int key){
        auto&f=storage[key];
        auto&k=f2k[f.second];
        k.erase(find(k.begin(),k.end(),key));
        f2k[++f.second].push_back(key);
        return f.first;
    }
};



//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	LFUCache lfu(3);
	lfu.set(2, 2);
	lfu.set(1, 1);
	assert(lfu.get(2)==2);
	assert(lfu.get(1)==1);
	assert(lfu.get(2)==2);
	lfu.set(3, 3);
	lfu.set(4, 4);
	assert(lfu.get(3)==-1);
	assert(lfu.get(2)==2);
	assert(lfu.get(1)==1);
	assert(lfu.get(4)==4);
	cout<<"lfu-cache passed.\n";
	return 0;
}
