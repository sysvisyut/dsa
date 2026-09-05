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
    vector<int> inorder;

    void helper(TreeNode* root){
        if(root == NULL){
            return;
        }

        helper(root->left);
        inorder.push_back(root->val);
        helper(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        // inorder traversal will give us sorted array
        helper(root);

        int n = inorder.size();

        int l = 0;
        int r = n-1;

        while(l < r){
            int curr = inorder[l]+inorder[r];
            if(curr == k){
                return true;
            }
            else if(curr > k){
                r--;
            }
            else{
                l++;
            }
        }
        return false;
    }
};