/*
 * 170.rotate-list.cpp
 *
 *  Created on: Jul 1, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/rotate-list/description
 *      Given a list, rotate the list to the right by k places, where k is non-negative.
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: the List
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode * rotateRight(ListNode * head, int k) {
        // write your code here
        if(head){
        auto l1=head,l2=l1;
        for(auto i=0;i<k;++i,l2=l2->next)
            if(!l2)
                l2=head;
        for(;l2&&l2->next;l1=l1->next,l2=l2->next);
        if(l2){l2->next=head;
        head=l1->next;
        l1->next=nullptr;
        }}return head;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test{1,2,3,4,5},expected{4,5,1,2,3};
	assertl(s.rotateRight(&test,2),&expected);
	test.del();
	expected.del();
	cout<<"rotate-list passed.\n";
	return 0;
}
