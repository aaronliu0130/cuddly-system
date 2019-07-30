/*
 * 85.insert-node-in-a-binary-search-tree.cpp
 *      Author: jerron
 *      https://www.lintcode.com/problem/insert-node-in-a-binary-search-tree/description
 *      Given a binary search tree and a new tree node, insert the node into the tree. You should keep the tree still be a valid binary search tree.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        // write your code here
        auto p=&root;
        while(*p)
            p=(*p)->val>node->val?&(*p)->left:&(*p)->right;
        *p=node;
        return root;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode *nodes[]{new TreeNode{1},new TreeNode{6}},*tests[]{nullptr,new TreeNode{2,1,4,INT_MIN,INT_MIN,3}};
	for(auto i=0u;i<countof(nodes);++i){
		auto node=nodes[i]->val;
		auto r=s.insertNode(tests[i],nodes[i]);
		assert(r->find(node)->val==node);
		assert(r->isBST());
		r->del();
		delete r;
	}
	cout<<"insert-node-in-a-binary-search-tree passed.\n";
	return 0;
}
