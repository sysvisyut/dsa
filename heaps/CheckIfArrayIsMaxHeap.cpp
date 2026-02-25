/*maxheap: when all the elements are represented as tree the parent should
be greater than the left and the right child

LOGIC: for an element left child is at index 2i and right child is at index
2i+1 so check for that condition for all elements*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=0;i<n;i++){
            int leftChild = 2*i+1;
            int rightChild = 2*i+2;
            
            if(leftChild < n && arr[i] < arr[leftChild]) return false;
            
            if(rightChild < n && arr[i] < arr[rightChild]) return false;
        }
        
        return true;
    }
};