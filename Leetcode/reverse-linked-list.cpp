//Problem: https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// Recursion

class Solution {
public:
    ListNode* reverseListRecursive(ListNode* prev, ListNode* curr){ 
        if(curr == nullptr){
            return prev;
        }
        
        ListNode* newHead = nullptr;
        
        if(curr != nullptr){
            newHead = reverseListRecursive(curr, curr->next);
        }
        
        if(curr != nullptr){
            curr->next = prev;
        }
        
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {        
        return reverseListRecursive(nullptr, head);
    }
};

// Iterative

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {        
        ListNode* prev = nullptr;;
        
        while(head){
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
};
