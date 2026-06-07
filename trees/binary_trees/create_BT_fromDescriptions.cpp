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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> childSet;

        for(auto it: descriptions){
            int p = it[0];
            int c = it[1];
            int left = it[2];

            if(!mp.count(p)){
                mp[p] = new TreeNode(p); //if the parent node is not created yet, create and store the respective pointer in map
            }
            if(!mp.count(c)){
                mp[c] = new TreeNode(c); //same for child
            }

            if(left == 1){ // if left child point the parent node->left to child 
                mp[p]->left = mp[c];
            }else{
                mp[p]->right = mp[c];
            }

            childSet.insert(c);
        }

        for(auto it: descriptions){ //iterate through all the parents and root is the one that is not found in the childset
            int p= it[0];

            if(!childSet.count(p)){
                return mp[p];
            }
             
        }

        return NULL;

    }
};