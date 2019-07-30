/*
 * 105.copy-list-with-random-pointer.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/copy-list-with-random-pointer/description
 *      A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        if(!head)
            return head;
        for(auto p=head;p;){
            auto n=new RandomListNode(p->label);
            n->next=p->next;
            p->next=n;
            p=n->next;
        }
        for(auto p=head;p;p=p->next->next)
            if(p->random)
                p->next->random=p->random->next;
        RandomListNode* nh=head->next,*tail=nh;
        while(tail){
            head=head->next=head->next->next;
            tail=tail->next=head?head->next:nullptr;
        }
        return nh;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	RandomListNode test({1,2,3,4,5,6,7},{3,2,2,INT_MIN,6,6,1}),*result=s.copyRandomList(&test);
	assertr(&test,result);
	test.del();
	result->del();
	delete result;
	cout<<"copy-list-with-random-pointer passed.\n";
	return 0;
}
