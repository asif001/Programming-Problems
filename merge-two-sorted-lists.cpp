// Problem: https://leetcode.com/problems/merge-two-sorted-lists/

// First solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr){
            return nullptr;
        }
        
        ListNode* mergedList = new ListNode();
        ListNode* headOfMergedList = nullptr;
        
        while(list1 != nullptr && list2 != nullptr){
            if(headOfMergedList != nullptr){
                mergedList->next = new ListNode();
                mergedList = mergedList->next;
            }else{
                headOfMergedList = mergedList;
            }
            
            if(list1->val < list2->val){
                mergedList->val = list1->val;
                list1 = list1->next;
            }else if(list1->val > list2->val){
                mergedList->val = list2->val;
                list2 = list2->next;
            }else{
                mergedList->val = list1->val;
                list1 = list1->next;
            }
        }
        
        while(list1 != nullptr){
            if(headOfMergedList != nullptr){
                mergedList->next = new ListNode();
                mergedList = mergedList->next;
            }else{
                headOfMergedList = mergedList;
            }
            
            mergedList->val = list1->val;
            list1 = list1->next;
        }
        
        while(list2 != nullptr){
            if(headOfMergedList != nullptr){
                mergedList->next = new ListNode();
                mergedList = mergedList->next;
            }else{
                headOfMergedList = mergedList;
            }
            
            mergedList->val = list2->val;
            list2 = list2->next;
        }
        
        return headOfMergedList;
    }
};

// Improved first solution removing unnecessary code

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {       
        ListNode* headOfMergedList = new ListNode(INT_MAX);
        ListNode* mergedList = headOfMergedList;
        
        while(list1 && list2){          
            if(list1->val < list2->val){
                mergedList->next = new ListNode(list1->val);
                list1 = list1->next;
            }else{
                mergedList->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            
            mergedList = mergedList->next;
        }
        
        mergedList->next = list1 ? list1 : list2;
        
        return headOfMergedList->next;
    }
};

// Recursive solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return list1;
        }
        
        if(!list1){
            return list2;
        }
        
        if(!list2){
            return list1;
        }
        
        ListNode* head = new ListNode();
        
        if(list1->val < list2->val){
            head->val = list1->val;
            head->next = mergeTwoLists(list1->next, list2);
        }else{
            head->val = list2->val;
            head->next = mergeTwoLists(list1, list2->next);
        }
        
        return head;
    }
};

// Recursive solution by removing unnecessary intialization

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2){
            return list1;
        }
        
        if(!list1){
            return list2;
        }
        
        if(!list2){
            return list1;
        }
                
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
