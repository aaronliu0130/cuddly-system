/*
 * 106.convert-sorted-list-to-binary-search-tree.cpp
 *
 *  Created on: Jul 3, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/convert-sorted-list-to-binary-search-tree/description
 *      Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @return: a tree node
     */
    TreeNode * sortedListToBST(ListNode * head) {
        // write your code here
        function<TreeNode*(ListNode*,ListNode*)> ltt=
        		[&ltt](ListNode* head,ListNode* tail)->TreeNode*{
            if(head==tail)
                return nullptr;
            auto l1=head,l2=l1;
            for(;l2!=tail&&l2->next!=tail;l1=l1->next,l2=l2->next->next);
            auto tree=new TreeNode(l1->val);
            tree->left=ltt(head,l1);
            tree->right=ltt(l1->next,tail);
            return tree;
        };
        return ltt(head,nullptr);
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	ListNode test[]{{1,2,3},{2,3,6,7}};
	TreeNode expected[]{{2,1,3},{6,3,7,2,INT_MIN,INT_MIN}},*result[countof(test)];
	assertt(s.sortedListToBST(nullptr),nullptr);
	for(auto i=0u;i<countof(test);++i){
		result[i]=s.sortedListToBST(&test[i]);
		assertt(result[i],&expected[i]);
		test[i].del();
		result[i]->del();
		delete result[i];
		expected[i].del();
	}
	cout<<"convert-sorted-list-to-binary-search-tree passed.\n";
	return 0;
}









