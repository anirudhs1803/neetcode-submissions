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
    ListNode* mergeTwoLists(ListNode* node1, ListNode* node2){
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(node1!= nullptr && node2!=nullptr){
            if(node1->val <=node2->val){
                tail->next = node1;
                tail = tail->next;
                node1 = node1->next;
            }
            else{
                tail->next = node2;
                tail = tail->next;
                node2 = node2->next;
            }
        }

        if(node1!= nullptr){
            tail->next = node1;
        }
        if(node2!= nullptr){
            tail->next = node2;
        }

        return dummy.next;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        
        while (lists.size() > 1) {
            vector<ListNode*> merged;
            
            for (int i = 0; i < lists.size(); i += 2) {
                if (i + 1 < lists.size()) {
                    merged.push_back(mergeTwoLists(lists[i], lists[i+1]));
                } else {
                    merged.push_back(lists[i]);   // odd one out, no pair this round
                }
            }
            
            lists = merged;
        }
        
        return lists[0];
    }
};
