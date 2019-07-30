/*
 * 99.reorder-list.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/reorder-list/description
 *      Given a singly linked list L: L0 ¡ú L1 ¡ú ¡­ ¡ú Ln-1 ¡ú Ln reorder it to: L0 ¡ú Ln ¡ú L1 ¡ú Ln-1 ¡ú L2 ¡ú Ln-2 ¡ú ¡­
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: nothing
     */
    void reorderList(ListNode * head) {
        // write your code here
        if(!head)
            return ;
        auto l1=head,l2=head->next;
        for(;l2&&(l2=l2->next);l1=l1->next,l2=l2->next);
        ListNode* l3=l1->next,*bl=l1->next=nullptr;
        while(l3){
            l2=l3->next;
            l3->next=bl;
            bl=l3;
            l3=l2;
        }
        for(l2=head;bl;){
            l3=bl->next;
            bl->next=l2->next;
            l2->next=bl;
            l2=bl->next;
            bl=l3;
        }
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test[]{{1,2,3,4},{1,2,3,4,5}},
			expected[]{{1,4,2,3},{1,5,2,4,3}};
	for(auto i=0u;i<countof(test);++i){
		s.reorderList(&test[i]);
		assertl(&test[i],&expected[i]);

		test[i].del();
		expected[i].del();
	}

	cout<<"reorder-list passed.\n";
	return 0;
}




