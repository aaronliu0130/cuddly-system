/*
 * 165.merge-two-sorted-lists.cpp
 *
 *  Created on: Jul 2, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/merge-two-sorted-lists/description
 *      Merge two sorted (ascending) linked lists and return it as a new sorted list
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param l1: ListNode l1 is the head of the linked list
     * @param l2: ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
        // write your code here
        ListNode* head=nullptr,**cur=&head;
        while(l1&&l2){
            auto next=l1->val>l2->val?&l2:&l1;
            *cur=*next;
            cur=&(*cur)->next;
            *next=*cur;
        }
        *cur=l1?l1:l2;
        return head;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test1{1,2,3,4,5},test2{0,3,3},expected{0,1,2,3,3,3,4,5};
	assertl(s.mergeTwoLists(&test1,&test2),&expected);
	ListNode test22{0,3,3},expected2{0,3,3};
	assertl(s.mergeTwoLists(nullptr,&test22),&expected2);
	del(vector<ListNode*>{&test1,&test2,&expected,&test22,&expected2});
	cout<<"merge-two-sorted-lists passed.\n";
	return 0;
}
