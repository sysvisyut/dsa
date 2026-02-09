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
    void inOrder(TreeNode* root,vector<TreeNode*>& nodes){
        if(!root) return;

        inOrder(root->left,nodes);
        nodes.push_back(root);
        inOrder(root->right,nodes);
    }

    TreeNode* build(int l,int r, vector<TreeNode*>& nodes){
        if(l>r) return nullptr;
        int mid = l+(r-l)/2;
        TreeNode* root = nodes[mid];

        root->left = build(l,mid-1,nodes);
        root->right = build(mid+1,r,nodes);

        return root;

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inOrder(root, nodes);
        return build(0,nodes.size()-1,nodes);
    }
};