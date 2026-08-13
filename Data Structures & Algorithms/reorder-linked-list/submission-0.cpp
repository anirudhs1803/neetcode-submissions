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
    void reorderList(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        

        ListNode* middle = slow;

        ListNode* newhead = middle->next;
        ListNode* prev = nullptr;
        slow->next = nullptr;

        while(newhead!=nullptr){
            ListNode* next = newhead->next;
            newhead->next = prev;
            prev = newhead;
            newhead = next;
        }
        ListNode* p1 = head;
        ListNode* p2 = prev;   // head of reversed second half

        while (p2 != nullptr) {
            ListNode* p1next = p1->next;
            ListNode* p2next = p2->next;
            
            p1->next = p2;
            p2->next = p1next;
            
            p1 = p1next;
            p2 = p2next;
        }



    }
};
