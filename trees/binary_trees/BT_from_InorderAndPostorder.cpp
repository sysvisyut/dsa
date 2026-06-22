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
    TreeNode* helper(vector<int>& inorder,int inSt,int inEnd, vector<int>& postorder, int postSt, int postEnd, unordered_map<int,int>& mp){

        if(inSt > inEnd || postSt > postEnd) return NULL;


        TreeNode* root = new TreeNode(postorder[postEnd]);
        int postRoot = postorder[postEnd];
        int inRoot = mp[postRoot];
        int numsLeft = inRoot-inSt;



        root->left = helper(inorder,inSt,inRoot-1,postorder,postSt,postSt+inRoot-1-inSt,mp);

        root->right = helper(inorder,inRoot+1,inEnd,postorder,postSt+numsLeft,postEnd-1,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }

        return helper(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
    }
};