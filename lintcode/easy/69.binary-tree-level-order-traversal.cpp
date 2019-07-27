/*
 * 69.binary-tree-level-order-traversal.cpp
 *
 *  Created on: Jul 13, 2019
 *      Author: Aaron
 */

#include "../../lintcode/utils/utils.h"
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> result;
        if(root){
            TreeNode* Q[21];
            int f(0),b(-1);
            Q[++b]=root;
            while(f<=b){
                result.push_back(vector<int>());
                for(int i=b-f;i>0;i--){
                    auto n=Q[f++];
                    result.back().push_back(n->val);
                    if(n->left)Q[++b]=n->left;
                    if(n->right)Q[++b]=n->right;
                }
            }
        }
        return result;
    }
};
class SolutionOLD {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */

    vector<vector<int>> levelOrder(TreeNode * root) {
        vector<vector<int>> result;
        if(root){
            vector<TreeNode*> Q;
            Q.push_back(root);
            while(!Q.empty()){
                result.push_back(vector<int>());
                for(int i=Q.size();i>0;i--){
                    auto n=Q.front();
                    result.back().push_back(n->val);
                    if(n->left)Q.push_back(n->left);
                    if(n->right)Q.push_back(n->right);
                }
            }
        }
        return result;
    }
};
/*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode test{1,2,3};
	vector<vector<int>>result=s.levelOrder(&test);
	assertv(s.levelOrder(&test),{{1},{2,3}});
	cout<<"binary-tree-level-order-traversal passed.\n";
	test.del();
	return 0;
}
