/*logic: 

findHeight: if the node is pointing to null return height as 0,
 else call the the function for left child and right child if left or right
doesnt exist it will return 0, find the max of left and right +1 to include the curr node
 
is balanced: if rootis null return true, find the height of left and right subtrees, 
if their abs difference is greater than 1 return false,
else call the function to check for all the substrees of left and right and
return what the function returns */
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>

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
    int findHeight(TreeNode* node){
        if(!node) return 0;


        return 1+max(findHeight(node->left),findHeight(node->right));
    }
    bool isBalanced(TreeNode* root) {
        if(!root){
            return true;
        }
        int left = findHeight(root->left);
        int right = findHeight(root->right);

        if(abs(right-left) >1) return false;

        return isBalanced(root->left)&& isBalanced(root->right);
    }
};