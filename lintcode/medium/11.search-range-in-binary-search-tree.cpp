/*
 * 11.search-range-in-binary-search-tree.cpp
 *
 *  Created on: Jul 28, 2019
 *      Author: Aaron
 */

#include "../../lintcode/utils/utils.h"
class Solution {
public:
    vector<int> searchRange(TreeNode * root, int k1, int k2) {
        vector<int> result;
        function<int(TreeNode*root)> dfs;
        dfs=[&dfs,&result,k1,k2](TreeNode*root){
            if(root){
                if(root->val<k1)return dfs(root->right);
                if(root->val>k2)return dfs(root->left);
                dfs(root->left);
                result.push_back(root->val);
                dfs(root->right);
            }
        };
        dfs(root);
        return result;
    }
};

//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode test={20,8,22,4,12};
	vector<int> expected={12,20,22};
	assertv(s.searchRange(&test,10,22),expected);
	cout<<"search-range-in-binary-search-tree passed.\n";
	return 0;
}
