/*
 * 43.maximum-subarray-iii.cpp
 *
 *  Created on: Jun 17, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/maximum-subarray-iii/description
 *      Given an array of integers and a number k, find k non-overlapping subarrays which have the largest sum.
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        // write your code here
        int s = nums.size();
        vector<vector<int>> sum(k+1, vector<int>(s+1, 0));
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= s; j++)
                sum[i][j] = max(sum[i][j-1], sum[i-1][j-1]) + nums[j-1];

            for(int j = i+1; j <= s; j++)
                sum[i][j] = max(sum[i][j-1], sum[i][j]);
        }
        return sum[k][s];
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert (s.maxSubArray({-1,4,-2,3,-2,3},2)==8);
	assert (s.maxSubArray({5,-3,4,-2,4},3)==13);
	assert (s.maxSubArray({-68,64,-44,16,-85,6,-58,84,-5,72,-16,100,-88,14,-36,73,-96,42,-72,93,-15,53,-18,67,-71,25,-51,26,-37,16,-33,32,-11,89,},3)==525);

	cout<<"maximum-subarray-iii passed.\n";
	return 0;
}



