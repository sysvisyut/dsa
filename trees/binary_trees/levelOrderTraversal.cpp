#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
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
    vector<vector<int>> levelOrderTraversal(TreeNode* root) {
        vector<vector<int>> lvlOrder;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            int size = q.size();
            vector<int> level;

            for(int i=0;i<size;i++){
                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
                level.push_back(node->val);

            }
            lvlOrder.push_back(level);
        }

        return lvlOrder;
    }
};