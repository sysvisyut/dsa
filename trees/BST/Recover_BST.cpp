#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* prev = NULL;
    TreeNode* n1 = NULL;
    TreeNode* n2 = NULL;

    void helper(TreeNode* root){
        if(!root) return;

        helper(root->left);

        if(prev && prev->val > root->val){
            if(!n1){
                n1 = prev;
            }
            n2 = root;
        }
        prev = root;

        helper(root->right);
    }
    void recoverTree(TreeNode* root) {

        /*inorder traversal should give me sorted order, while processing the tree in inorder check for nodes mismatched*/

        helper(root);
        swap(n1->val, n2->val);

    }
};