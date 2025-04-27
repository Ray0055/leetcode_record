#include <string>
#include <iostream>
#include <vector>
//  Definition for singly-linked list.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode dummy1 = ListNode(-1);
        ListNode dummy2 = ListNode(-1);

        ListNode *p_less = &dummy1;
        ListNode *p_larger = &dummy2;

        while(head!=nullptr){
            if (head->val < x){
                p_less->next = head;
                p_less = p_less->next;

                head = head->next;
            }else{
                p_larger->next = head;
                p_larger = p_larger->next;
                
                head = head->next;
                p_larger->next = nullptr; 
                // This is important, otherwise the last node of larger list will point to one node of smaller list
            }
        }
        
        p_less->next = dummy2.next;
        return dummy1.next;
    }
        vector<int> getValVector(ListNode* list){
            vector<int> res = vector<int>();
            for (auto ptr=list; ptr != nullptr;){
                res.push_back(ptr->val);
                ptr = ptr->next;
            }
            return res;
        }
    
    };

int main(){
    Solution solution = Solution();
    ListNode node1 = ListNode(1);
    ListNode node2 = ListNode(4);
    ListNode node3 = ListNode(3);
    ListNode node4 = ListNode(2);
    ListNode node5 = ListNode(5);
    ListNode node6 = ListNode(2);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    // 1 -> 4 -> 3 -> 2 -> 5 -> 2

    ListNode* resList = solution.partition(&node1, 3);
    auto res = solution.getValVector(resList);
    for (auto i : res){
        cout << i << " ";
    }
    return 0;
}