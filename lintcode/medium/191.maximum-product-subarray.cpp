/*
 * 191.maximum-product-subarray.cpp
 *
 *  Created on: Jul 11, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/maximum-product-subarray/description
 *      Find the contiguous subarray within an array (containing at least one number) which has the largest product.
 */
#define __DEBUG
#include "../utils/utils.h"

class Solution {
public:
    /*
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode * removeNode(TreeNode * root, int value) {
        // write your code here
        if(root){
            if(root->val==value){
                auto oldroot=root;
                if(root->left)
                    if(!root->left->right){
                        root->left->right=root->right;
                        root=root->left;
                    }
                    else if(root->right)
                        if(!root->right->left){
                            root->right->left=root->left;
                            root=root->right;
                        }
                        else{
                            root->left=removeNode(root->left,root->val=root->left->val);
                            return root;
                        }
                    else
                        root=root->left;
                else if(root->right)
                    root=root->right;
                else
                    root=nullptr;
                delete oldroot;
            }
            else if(root->val>value)
                root->left=removeNode(root->left,value);
            else
                root->right=removeNode(root->right,value);
        }
        return root;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode *tests[]{new TreeNode{5,3,6,2,4},new TreeNode{5,3,6,2,4}};
	int test2[]{3,6};
	for(auto i=0u;i<countof(tests);++i){
		auto r=s.removeNode(tests[i],test2[i]);
		assert(r->find(test2[i])==nullptr);
		assert(r->isBST());
		r->del();
		delete r;
	}
	cout<<"maximum-product-subarray passed.\n";
	return 0;
}





