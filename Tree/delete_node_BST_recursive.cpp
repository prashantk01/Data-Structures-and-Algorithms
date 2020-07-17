// leetcode problem : Delete Node in a BST
/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7
    
 */
 
 
 // THIS IS RECURSIVE APPROACH
 
 
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root){
            if (root->val == key){
                if(root->left==NULL && root->right==NULL){
                    root=NULL; 
                }
                else if(root->left==NULL){
                    TreeNode* temp=root;
                    root=root->right;
                    delete(temp);
                }
                else if(root->right==NULL){
                    TreeNode* temp=root;
                    root=root->left;
                    delete(temp);
                }
                else{
                    TreeNode *temp=findmax(root->left);    // you can go for min in right subtree
                    root->val=temp->val;
                    root->left=deleteNode(root->left,temp->val);
                }
            }
            else if(root->val >key)
                root->left=deleteNode(root->left,key);
            else
                root->right=deleteNode(root->right,key);
        }
        return root;          
    }
     TreeNode* findmax(TreeNode* root){
         while(root->right)
             root=root->right;
         return root;
     }
};
