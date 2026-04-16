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
    bool helper(TreeNode* root, int sum,int targetSum){
        if(!root) return 0;
        sum+= root->val;

        if(!root->left && !root->right ) return sum == targetSum;

        bool left = helper(root->left,sum,targetSum);
        bool right = helper(root->right, sum,targetSum);

        return left || right;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, sum,targetSum);
    }
};