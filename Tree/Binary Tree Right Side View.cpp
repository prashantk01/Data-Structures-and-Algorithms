
/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
public:
    int level=-1;
    vector<int> v;
    vector<int> rightSideView(TreeNode* root){
        findrightmost(root,0);
        return v;
    }
    void findrightmost(TreeNode* root, int current_level){
        if(root){
            if(level < current_level){  // checking if current level is greater so we can push right most element of every particular level
                level=current_level;
                v.push_back(root->val);
            }
        findrightmost(root->right,current_level+1);
        findrightmost(root->left,current_level+1);
        }
       
        return;
    }
};
