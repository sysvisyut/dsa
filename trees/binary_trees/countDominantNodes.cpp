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
    int ans = 0;
    int helper(TreeNode* root){
        if(!root){
            return INT_MIN;
        }

        int leftMax = helper(root->left);
        int rightMax = helper(root->right);

        int maxi = max(leftMax,rightMax);

        if(root->val >= maxi){
            maxi = root->val;
            ans++;
        }

        return maxi;
        
    }
    int countDominantNodes(TreeNode* root) {
        
        helper(root);

        return ans;
        
    }
};