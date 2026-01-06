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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        int curLvl =1;
        int bestLvl =1;
        while(!q.empty()){
            int size = q.size();
            int sum=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                sum += node->val;
                q.pop();

                if(node->left != NULL){
                    q.push(node->left);
                }
                if(node->right != NULL){
                    q.push(node->right);
                }
            }
            if(sum > maxi){
                maxi= sum;
                bestLvl = curLvl;
            }
            curLvl++;
            
        }

        return bestLvl;
    }
};