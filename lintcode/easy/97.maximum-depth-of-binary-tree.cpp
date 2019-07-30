/*
 * 97.maximum-depth-of-binary-tree.cpp
 *
 *  Created on: Jul 8, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/maximum-depth-of-binary-tree/description
 *      Given a binary tree, find its maximum depth.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        // write your code here
    	return root?max(maxDepth(root->left),maxDepth(root->right))+1:0;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	assert(s.maxDepth(nullptr)==0);
	TreeNode test{1,2,3,INT_MIN,INT_MIN,4,5};
	assert(s.maxDepth(&test)==3);
	test.del();
	cout<<"maximum-depth-of-binary-tree passed.\n";
	return 0;
}
