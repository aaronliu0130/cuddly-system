/*
 * 93.balanced-binary-tree.cpp
 *
 *  Created on: Jul 8, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/maximum-depth-of-binary-tree/description
 *      Given a binary tree, determine if it is height-balanced.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode * root) {
        // write your code here
        function<int(TreeNode*)>dfs;
        dfs=[&dfs](TreeNode* root)->int{
            if(root){
                int depthl=dfs(root->left),depth2;
                if(depthl<0||(depth2=dfs(root->right))<0||
                    depth2>depthl+1||depthl>depth2+1)
                    return -1;
                return max(depthl,depth2)+1;
            }
            return 0;
        };
        return dfs(root)>=0;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode test[]{{1,2,3},{3,9,20,INT_MIN,INT_MIN,15,7},{1,INT_MIN,2,3,4}};
	bool expected[]{true,true,false};
	for(auto i=0u;i<countof(test);++i){
		assert(s.isBalanced(&test[i])==expected[i]);
		test[i].del();
	}
	cout<<"maximum-depth-of-binary-tree passed.\n";
	return 0;
}
