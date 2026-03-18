#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if(!head || left==right) return head;

        ListNode* dummy = new ListNode(0,head);

        
        ListNode* prevRef = dummy;
        ListNode* afterRef = head;
        

        for(int i=0;i<left-1;i++){
            prevRef = prevRef->next;
        }
        ListNode* pointNext = prevRef;
        
      
        ListNode* start= prevRef->next;
        ListNode* temp = start;
        ListNode* prev = NULL;

        for(int i=left;i<=right;i++){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        
        prevRef->next = prev;
        start->next = temp;


        return dummy->next;


    }
};