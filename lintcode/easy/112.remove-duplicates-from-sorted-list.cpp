/*
 * 112.remove-duplicates-from-sorted-list.cpp
 *
 *  Created on: Jul 2, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/remove-duplicates-from-sorted-list/description
 *      Given a sorted linked list, delete all duplicates such that each element appear only once.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: head is the head of the linked list
     * @return: head of linked list
     */
    ListNode * deleteDuplicates(ListNode * head) {
        // write your code here
        for(auto cur=head;cur&&cur->next;)
            if(cur->next->val==cur->val){
                auto next=cur->next->next;
                delete cur->next;
                cur->next=next;
            }
            else
                cur=cur->next;
        return head;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assertl(s.deleteDuplicates(nullptr),nullptr);
	ListNode test{1,1,2},expected{1,2};
	assertl(s.deleteDuplicates(&test),&expected);
	ListNode test2{1,1,2,3,3},expected2{1,2,3};
	assertl(s.deleteDuplicates(&test2),&expected2);
	del(vector<ListNode*>{&test,&test2,&expected,&expected2});
	cout<<"remove-duplicates-from-sorted-list passed.\n";
	return 0;
}




