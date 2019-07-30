/*
 * 16.permutations-ii.cpp
 *
 *  Created on: Jul 1, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/permutations-ii/description
 *      Given a linked list, remove the nth node from the end of list and return its head.
 */

#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param :  A list of integers
     * @return: A list of unique permutations
     */
    vector<vector<int>> permuteUnique(vector<int> nums) {
        // write your code here
        int s=nums.size();
        if(s<1)
            return {{}};
        vector<int> states(s,0);
		vector<bool> used(s+1,false);
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        nums.insert(nums.begin(),INT_MIN);
        for(int i=0;i>=0;){
        	auto prev=states[i];
        	auto ok=false;
        	for(used[prev]=false;!ok&&++states[i]<=s;
        	    ok=!used[states[i]]&&nums[states[i]]!=nums[prev]);
        	if(ok){
        		used[states[i]]=true;
        		++i;
            	if(i>=s){
            		vector<int> res(s);
            		for(int j=0;j<s;++j)
            			res[j]=nums[states[j]];
            		result.push_back(res);
            		--i;
            	}
            	else
            		states[i]=0;
        	}
        	else
        		--i;
        }
        return result;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assertv(s.permuteUnique({1,2,2,3,3}),{{1,2,2,3,3},{1,2,3,2,3},{1,2,3,3,2},{1,3,2,2,3},{1,3,2,3,2},{1,3,3,2,2},{2,1,2,3,3},{2,1,3,2,3},{2,1,3,3,2},{2,2,1,3,3},{2,2,3,1,3},{2,2,3,3,1},{2,3,1,2,3},{2,3,1,3,2},{2,3,2,1,3},{2,3,2,3,1},{2,3,3,1,2},{2,3,3,2,1},{3,1,2,2,3},{3,1,2,3,2},{3,1,3,2,2},{3,2,1,2,3},{3,2,1,3,2},{3,2,2,1,3},{3,2,2,3,1},{3,2,3,1,2},{3,2,3,2,1},{3,3,1,2,2},{3,3,2,1,2},{3,3,2,2,1}});
	cout<<"permutations-ii passed.\n";
	return 0;
}
