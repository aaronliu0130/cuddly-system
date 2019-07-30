/*
 * 96.partition-list.cpp
 *
 *  Created on: Jul 2, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/partition-list/description
 *      Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list
     * @param x: An integer
     * @return: A ListNode
     */
    ListNode * partition(ListNode * head, int x) {
        // write your code here
        ListNode**l1=&head,*second=nullptr,**l2=&second,*cur=head;
        for(;cur;cur=cur->next){
            auto p=cur->val>=x?&l2:&l1;
            **p=cur;
            *p=&cur->next;
        }
        *l1=second;
        *l2=nullptr;
        return head;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assertl(s.partition(nullptr,0),nullptr);
	ListNode test{1,4,3,2,5,2},expected{1,2,2,4,3,5};
	assertl(s.partition(&test,3),&expected);
	del(vector<ListNode*>{&test,&expected});
	cout<<"partition-list passed.\n";
	return 0;
}
