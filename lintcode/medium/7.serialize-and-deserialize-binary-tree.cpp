/*
 * 7.serialize-and-deserialize-binary-tree.cpp
 *
 *  Created on: Jun 16, 2019
 *      Author: jerron
 *      https://www.lintcode.com/problem/serialize-and-deserialize-binary-tree/description
 *      Design an algorithm and write code to serialize and deserialize a binary tree. Writing the tree to a file is called 'serialization' and reading back from the file to reconstruct the exact same binary tree is 'deserialization'.
 */
#include "../utils/utils.h"

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        string result;
        function<string&(TreeNode*)>sl=[&sl,&result](TreeNode*root)->string&{
            if(root){
                result+=","+to_string(root->val);
                sl(root->left);
                sl(root->right);
            }
            else
                result+=",#";
            return result;
        };
        return sl(root);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in
     * "serialize" method.
     */
    TreeNode * deserialize(string data) {
        // write your code here
        TreeNode* root;
        istringstream is(data);
        function<TreeNode*(TreeNode**)> ds=[&ds,&is](TreeNode** node){
            char comma;
            int val;
            is>>comma;
            if(is.peek()=='#'){
                *node=nullptr;
                is>>comma;
            }
            else{
    		    is>>val;
                *node=new TreeNode(val);
                ds(&((*node)->left));
                ds(&((*node)->right));
            };
            return *node;
        };
        return ds(&root);
    }
};


//*
#pragma GCC diagnostic ignored "-Wunused-function"
static//*/
int test(){ // @suppress("Unused static function")
	Solution s;
	TreeNode tree[5];
	tree[0].val=3;tree[0].left=&tree[1];tree[0].right=&tree[2];
	tree[1].val=9;
	tree[2].val=20;tree[2].left=&tree[3];tree[2].right=&tree[4];
	tree[3].val=15;
	tree[4].val=7;
	auto ntree=s.deserialize(s.serialize(tree));
	assert(ntree->val==tree->val);
	assert(ntree->left->val==tree->left->val);
	assert(ntree->right->val==tree->right->val);
	assert(ntree->left->left==tree->left->left);
	assert(ntree->left->right==tree->left->right);
	assert(ntree->right->left->val==tree->right->left->val);
	assert(ntree->right->right->val==tree->right->right->val);
	cout<<"serialize-and-deserialize-binary-tree passed.\n";
	return 0;
}
