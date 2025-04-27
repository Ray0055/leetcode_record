
#include <iostream>
#include "../common/ListNode.cpp"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
using namespace std;
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;

        if (fast == nullptr || fast->next == nullptr){
            return false;
        }

        while (fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){
                return true;
            }
        }
        return false;
    }
};


int main() {
    Solution solution;

    // your test code here
    ListNode *l1 = ListNode::createHead({1, 3, 5});

    bool result = Solution().hasCycle(l1);
    cout << "Has cycle: " << (result ? "true" : "false") << endl;
}