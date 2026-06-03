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

class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;

        trieNode(){
            left = NULL;
            right = NULL;
        }
    };

    trieNode* root;

    void insert(int num){
        trieNode* crawler = root;

        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(bit == 0){
                if(crawler->left == NULL){
                    crawler->left = new trieNode();
                }
                crawler = crawler->left;
            }
            else{
                if(crawler->right == NULL){
                    crawler->right = new trieNode();
                }
                crawler = crawler->right;
            }
        }
    }

    int findMax(int &num){
        int maxXor = 0;
        trieNode* crawler = root; 

        for(int i = 31; i>=0;i--){
            int bit = (num>>i)&1;

            if(bit == 1){
                if(crawler->left != NULL){
                    maxXor |= (1 << i);
                    crawler = crawler->left;
                }
                else{
                    crawler = crawler->right;
                }
            }
            else{
                if(crawler->right != NULL){
                    maxXor += pow(2,i);
                    crawler = crawler->right;
                }
                else{
                    crawler = crawler->left;
                }
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        
        root = new trieNode();

        for(int n: nums){
            insert(n);
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans = max(ans, findMax(nums[i]));
        }

        return ans;
    }
};