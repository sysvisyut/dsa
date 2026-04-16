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
  
    int minDepth(TreeNode* root) {
        if(!root) return 0;


        /* edge case: if there is no left or right child fn will have min(left,0) or min(0,right)
        but we need the explore the path ignoring the null value
        
        eg:
            1
           2 null
          3   null
           
        above the minDepth is 3
        */
        if(!root->left) return 1+minDepth(root->right);
        if(!root->right) return 1+minDepth(root->left);

        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};