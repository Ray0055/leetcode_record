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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1), *p1 = &dummy;
        p1 = head;
        
        for (auto i=0;i<n;i++){
            p1 = p1->next;
        }
        if ( p1 == nullptr){ // p1 now is at the end of list
            return head->next;
        }
        ListNode* p2 = head;
        while (p1->next != nullptr){
            p1 = p1->next;
            p2 = p2->next;
        }

        auto removed_ptr = p2->next;
        p2->next = removed_ptr->next;
        return head;
    }
};