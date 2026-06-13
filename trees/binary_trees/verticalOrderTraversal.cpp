#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <limits>
#include <numeric>
#include <iomanip>

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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;

        queue<pair<TreeNode*,pair<int,int>>> todo;

        todo.push({root,{0,0}});

        while(!todo.empty()){
            auto it = todo.front();
            todo.pop();
            TreeNode* node = it.first;
            int v = it.second.first;
            int lvl = it.second.second;

            nodes[v][lvl].insert(node->val);

            if(node->left){
                todo.push({node->left,{v-1, lvl+1}});
            }
            
            if(node->right){
                todo.push({node->right,{v+1, lvl+1}});
            }
        }

        vector<vector<int>> ans;

        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }

        return ans;

    }
};