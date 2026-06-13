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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }

        int width = 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root,0});

        while(!q.empty()){
            long long st = q.front().second;
            long long end = q.back().second;
            int s = q.size();

            width = max(width, (int)(end-st+1));

            for(int i=0;i<s;i++){
                pair<TreeNode*, int> temp = q.front();
                q.pop();

                if(temp.first->left){
                    q.push({temp.first->left, (long long)2*temp.second+1});
                }
                if(temp.first->right){
                    q.push({temp.first->right, (long long)2*temp.second+2});
                }
                
            }

        }
        return width;
    }
};