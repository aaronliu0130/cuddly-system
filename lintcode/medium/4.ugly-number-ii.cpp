/*
 * 4.ugly-number-ii.cpp
 *
 *  Created on: Jun 7, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/ugly-number-ii/description
 *      Ugly number is a number that only have prime factors 2, 3 and 5.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
    int nthUglyNumber(int n) {
        // write your code here
        int f[3]={2,3,5},p[3]{-1,-1,-1},u[3]{1,1,1},r[n],j;
        for(int i=0;i<n;++i){
            for(r[i]=INT_MAX,j=0;j<3;++j)
        		r[i]=min(r[i],u[j]);
        	for(j=0;j<3;++j)
        		if(u[j]==r[i])
        			u[j]=r[++p[j]]*f[j];
        }
        auto re=r[n-1];
        return re;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert (s.nthUglyNumber(100)==1536);
	cout<<"ugly-number-ii passed.\n";
	return 0;
}


