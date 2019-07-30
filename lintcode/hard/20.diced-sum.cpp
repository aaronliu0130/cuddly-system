/*
 * 20.Dices-Sum.cpp
 *
 *  Created on: Jun 7, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/dices-sum/description
 *      Throw n dices, the sum of the dices' faces is S. Given n, find the all possible value of S along with its probability.
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param n an integer
     * @return a list of pair<sum, probability>
     */
    vector<pair<int, double>> dicesSum(int n) {
        // Write your code here
        vector<double>result[2]{{1},{}};
        int prev=0,cur=1;
        for(auto i=0;i<n;++i,prev=cur,cur=1-prev){
                result[cur]=vector<double>(i*5+6,0);
            for(auto j=i;j<=i*6;++j){
                auto p=result[prev][j-i]/6;
                for(auto k=1;k<=6;++k)
                    result[cur][j+k-i-1]+=p;
            }
        }
        vector<pair<int,double>>re(n*5+1);
        for(auto i=n;i<=n*6;++i)
            re[i-n]={i,result[prev][i-n]};
        return re;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert (abs(s.dicesSum(1)[2].second-1/6.)<.000001);
	assert (abs(s.dicesSum(14)[30].second-0.046010619)<.0000001);
	cout<<"dices-sum passed.\n";
	return 0;
}


