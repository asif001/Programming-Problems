// Problem: https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHead = slow;
        ListNode* prev = nullptr;
        
        while(secondHead != nullptr){
            ListNode* next = secondHead->next;
            secondHead->next = prev;
            prev = secondHead;
            secondHead = next;
        }
        secondHead = prev;
        
        bool isPalindromeList = true;
        while(head != nullptr && secondHead != nullptr && isPalindromeList){
            isPalindromeList = isPalindromeList && (head->val == secondHead->val);
            head = head->next;
            secondHead = secondHead->next;
        }
        
        return isPalindromeList;
    }
};
