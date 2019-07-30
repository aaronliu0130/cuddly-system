/*
 * 98.sort-list.cpp
 *
 *  Created on: Jul 5, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/sort-list/description
 *      Sort a linked list in O(n log n) time using constant space complexity.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @return: You should return the head of the sorted linked list, using constant space complexity.
     */
    ListNode * sortList(ListNode * head) {
        // write your code here
        function<ListNode*(ListNode**,ListNode*)> sl=
        		[&sl](ListNode** begin,ListNode*end)->ListNode*{
            if(*begin==end)
                return *begin;
            ListNode *mid=*begin,**back=&mid->next,**front=begin;
            auto par=mid->val;
            for(auto cur=*back;cur!=end;cur=cur->next){
                auto update=cur->val>=par?&back:&front;
                **update=cur;
                *update=&cur->next;
            }
            *front=mid;
            *back=end;
            sl(begin,mid);
            for(;mid->next&&mid->val==mid->next->val;mid=mid->next);
            sl(&mid->next,end);
            return *begin;
        };
        return sl(&head,nullptr);
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test[]{{1,3,2},{1,7,2,6}},
			expected[]{{1,2,3},{1,2,6,7}};
	for(auto i=0u;i<countof(test);++i){
		s.sortList(&test[i]);
		assertl(&test[i],&expected[i]);

		test[i].del();
		expected[i].del();
	}

	cout<<"sort-list passed.\n";
	return 0;
}
