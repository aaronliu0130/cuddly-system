/*
 * 102.linked-list-cycle.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/linked-list-cycle/description
 *      Given a linked list, determine if it has a cycle in it.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: True if it has a cycle, or false
     */
    bool hasCycle(ListNode * head) {
        // write your code here
        for(auto l1=head,l2=l1;l2&&(l2=l2->next);l1=l1->next,l2=l2->next)
            if(l1==l2)
                return true;
        return false;
    }
};
//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test[]{{1,2,3,4,5},{2,3,6,7}};
	test[0].next->next->next->next->next=test[0].next;
	bool expected[]{true,false};
	for(auto i=0u;i<countof(test);++i){
		assert(s.hasCycle(&test[i])==expected[i]);
		//can't delete the link before we write extra code to break the cycle
		//test[i].del();
	}

	cout<<"linked-list-cycle passed.\n";
	return 0;
}
