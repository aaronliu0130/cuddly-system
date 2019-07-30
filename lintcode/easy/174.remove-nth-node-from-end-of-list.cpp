/*
 * 174.remove-nth-node-from-end-of-list.cpp
 *
 *  Created on: Jun 30, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/remove-nth-node-from-end-of-list/description
 *      Given a linked list, remove the nth node from the end of list and return its head.
 */

#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: The head of linked list.
     */
    ListNode * removeNthFromEnd(ListNode * head, int n) {
        // write your code here
        ListNode** l1=&head,*l2=head;
        int i=0;
        for(;i<n&&l2;++i)
            l2=l2->next;
        if(i>=n){
        for(;l2;l1=&((*l1)->next),l2=l2->next);
        if((l2=*l1)){
            *l1=l2->next;
            delete l2;
        }}
        return head;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test{1,2,3,4,5},expected{1,2,4,5};
	assertl(s.removeNthFromEnd(&test,3),&expected);
	test.del();
	expected.del();
	cout<<"remove-nth-node-from-end-of-list passed.\n";
	return 0;
}





