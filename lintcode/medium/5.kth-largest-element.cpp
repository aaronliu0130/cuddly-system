/*
 * 5.kth-largest-element.cpp
 *
 *  Created on: Jun 7, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/kth-largest-element/description
 *      Find K-th largest element in an array.
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int n, vector<int> nums) {
        // write your code here
    	--n;
        function<int(int,int)>par=[&par,n,&nums](int begin,int end)->int{
            if(end<n||end<=begin)
                return nums[n];
            for(auto b=begin,e=end,piv=nums[n];;){
                for(;e>=b&&nums[b]>piv;++b);
                for(;e>=b&&nums[e]<piv;--e);
                if(e<=b){
                	if(e<=n)
                		if (e==b&&e==n)
                			return nums[n];
                		else
                			return par(b,end);
                	else
                		return par(begin,e);
                }
                swap(nums[b++],nums[e--]); // @suppress("Invalid arguments")
            }
        };
        return par(0,nums.size()-1);
    }
};
//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert (s.kthLargestElement(10,{1,2,3,4,5,6,8,9,10,7})==1);
	assert (s.kthLargestElement(3,{9,3,2,4,8})==4);
	assert (s.kthLargestElement(1,{1,3,4,2})==4);
	cout<<"kth-largest-element passed.\n";
	return 0;
}


