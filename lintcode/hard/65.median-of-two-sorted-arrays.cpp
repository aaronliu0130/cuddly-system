/*
 * 65.median-of-two-sorted-arrays.cpp
 *
 *  Created on: Jul 1, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/median-of-two-sorted-arrays/description
 *      There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
 */

#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param A: An integer array
     * @param B: An integer array
     * @return: a double whose format is *.5 or *.0
     */
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int m=A.size(),n=B.size(),k=(m+n)/2,i=0,j=0,m1,m2;
        while (k>1) {
            int s=k/2,ia=i+s-1,ib=j+s-1;
            ia=ia>=m?INT_MAX:A[ia];
            ib=ib>=n?INT_MAX:B[ib];
            if (ia<ib)
                i=i+s;
            else
                j=j+s;
            k=k-s;
        }
        if (i>=m){
        	m1=B[j];m2=j+1==n?m1:B[j+1];
        }
        else if (j>=n){
        	m1=A[i];m2=i+1==m?m1:A[i+1];
        }
        else if(A[i]<B[j]){
        	m1=A[i];m2=i+1==m?B[j]:min(A[i+1],B[j]);
        }
        else{
        	m1=B[j];m2=j+1==n?A[i]:min(A[i],B[j+1]);
        }
        if ((m+n)%2==0) {
            return (m1+m2)/2.0;
        }else
        	return m2;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert(s.findMedianSortedArrays({1,2,3,4,5,6},{2,3,4,5})==3.5);
	assert(s.findMedianSortedArrays({1,2,3},{4,5})==3);
	cout<<"median-of-two-sorted-arrays passed.\n";
	return 0;
}
