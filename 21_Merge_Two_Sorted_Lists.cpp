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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            ListNode tmp = ListNode(-101);
            ListNode* ptr = &tmp;

            while(list1 != nullptr && list2 != nullptr){
                if (list1->val > list2->val){
                    ptr->next = list2;
                    list2 = list2->next;

                }else{
                    ptr->next = list1;
                    list1 = list1->next;
                }
                ptr = ptr->next;

            }

            if (list2 != nullptr){
                ptr->next = list2;
            }

            if (list1 != nullptr){
                ptr->next = list1;
            }
            return tmp.next;
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
    ListNode node2 = ListNode(2);
    ListNode node3 = ListNode(4);

    ListNode node4 = ListNode(2);
    ListNode node5 = ListNode(3);
    ListNode node6 = ListNode(4);
    // node1.next = &node2;
    // node2.next = &node3;
    // node3.next = nullptr;

    // node4.next = &node5;
    // node5.next = &node6;
    // node6.next = nullptr;

    // 1
    // 2
    ListNode* resList = solution.mergeTwoLists(&node1, &node4);
    // ListNode* resList = solution.mergeTwoLists(&node1, &node4);
    auto res = solution.getValVector(resList);
    for (auto i : res){
        cout << i << " ";
    }
    return 0;
}