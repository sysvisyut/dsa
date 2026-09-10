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
    int maxSum = 0;

    struct info{
        bool isBST;
        int mini;
        int maxi;
        int sum;
    };

    info helper(TreeNode* root){
        if(!root){ // empty tree is a BST itself
            return {true,INT_MAX,INT_MIN,0};
        }
        
        // do postoder traversal coz i need the left and right for processing the current node

        info left = helper(root->left);
        info right = helper(root->right);

        if(left.isBST && right.isBST && left.maxi < root->val &&
        right.mini > root->val){
            
            int currSum = root->val+left.sum+right.sum;

            maxSum = max(maxSum, currSum);


            // this subtree is a BST
            return {true,min(left.mini,root->val), max(right.maxi,root->val),currSum};
        }

        // subtree is not a BST
        return {false,INT_MIN, INT_MAX,0};


    }

    int maxSumBST(TreeNode* root) {
        
        /*
        each node should have isBST, maxVal, minVal, sum as information
        */

        helper(root);
        return maxSum;
        
    }
};