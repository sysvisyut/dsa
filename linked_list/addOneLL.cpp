#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
using namespace std;

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};


// logic: reverse the entire linked list, add one and then again reverse back;
class Solution {
  public:
    Node* rev(Node* head){
        Node* temp = head;
        Node* prev = NULL;
        
        while(temp){
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head = rev(head);
        
        Node* temp = head;
        int carry = 1;
        
        while(temp){
            int sum = temp->data+carry;
            temp->data = sum%10;
            carry = sum/10;
            
            if(carry == 0) break;
            if(temp->next == NULL && carry){
                temp->next = new Node(0);
            }
            temp = temp->next;
        }
        
        return rev(head);
        
        
        
        
        
    }
};