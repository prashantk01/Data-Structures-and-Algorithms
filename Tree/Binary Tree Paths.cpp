//leetcode problem: -  Binary Tree Paths
/*Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    vector<string> list;
    string s="->";
public:
    vector<string> binaryTreePaths(TreeNode* root) {
         traversal(root,"");
        return list;
    }
    
    void traversal(TreeNode* root,string st){
        if(root){
            if (root->left==NULL && root->right==NULL){
                st+=to_string(root->val);
                list.push_back(st);
            }
            traversal(root->left,st+to_string(root->val)+s);
            traversal(root->right,st+to_string(root->val)+s);
            }
        return;
    }      
};
