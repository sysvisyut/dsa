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
    TreeNode* helper(vector<int>& preorder, int preSt,int preEnd, vector<int>& inorder, int inSt, int inEnd,unordered_map<int,int>& mp){
        if(preSt > preEnd || inSt > inEnd){
            return NULL; //cant shrink the preorder or inorder anymore to build subtree
        }
        TreeNode* root = new TreeNode(preorder[preSt]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot-inSt; // total vals to the left of inRoot.

        root->left = helper(preorder,preSt+1,preSt+numsLeft,inorder,inSt, inRoot-1,mp);

        root->right = helper(preorder,preSt+numsLeft+1,preEnd,inorder,inRoot+1,inEnd,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return helper(preorder,0,preorder.size()-1, inorder,0,inorder.size()-1, mp);
    }
};