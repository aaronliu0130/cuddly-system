/*
 * 3.digit_counts.cpp
 *
 *  Created on: Jun 7, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/digit-counts/description
 *      Count the number of k's between 0 and n. k can be 0 - 9.
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param k: An integer
     * @param n: An integer
     * @return: An integer denote the count of digit k in 1..n
     */
    int digitCounts(int k, int n) {
        // write your code here
        unordered_map<int,int>M;
        function<int(int,bool)>dc=[&dc,&M,&k](int n,bool o){
            int total;
            if(n<10)
                total=n>=k?1:0;
            else if(o&&M.count(n))
                total=M[n];
            else{
                int l=pow(10,(int)log10(n)),r=n%l,c=n/l;
                if(o||k>0){
                    total=c*dc(l-1,true)+dc(r,true);
                    if(c>=k)
                        total+=min(l,n-k*l+1);
                    M[n]=total;
                }
                else
                    total=(c-1)*dc(l-1,true)+dc(r,true)+dc(l-1,false);
            }
            return total;
        };
        return dc(n,false);
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert (s.digitCounts(0,1234)==344);
	cout<<"digit-counts passed.\n";
	return 0;
}
