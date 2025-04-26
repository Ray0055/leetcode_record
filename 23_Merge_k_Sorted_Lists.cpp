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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // check if the lists is empty
        if (lists.size() == 0){
            return nullptr;

        }
        ListNode dummy(-1), *p = &dummy;

        // pop the null pointers like [[], [1,2,3], [4,5,6]]
        for (auto i = 0; i < lists.size(); i++){
            if (lists[i] == nullptr){
                lists.erase(lists.begin() + i);
                i--;
            }
        }

        while (lists[0] != nullptr && lists.size() > 0){
            int min_val = 100000;
            int min_index = 0;
            // find min ListNode
            for (auto i = 0; i < lists.size(); i++){
                if (lists[i]->val < min_val){
                    min_val = lists[i]->val;
                    min_index = i;
                }
            }           
            p->next = lists[min_index];
            p = p->next;
            
            // remove the min ListNode from the list
            // check if the min ListNode is null
            if (lists[min_index] != nullptr){
            lists[min_index] = lists[min_index]->next;}

            //remoev the null ListNode
            for (auto i = 0; i < lists.size(); i++){
                if (lists[i] == nullptr){
                    lists.erase(lists.begin() + i);
                    i--;
                }
            }
        }
        return dummy.next;
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
    ListNode node3 = ListNode(5);
    ListNode node4 = ListNode(1);
    ListNode node5 = ListNode(3);
    ListNode node6 = ListNode(4);
    ListNode node7 = ListNode(2);
    ListNode node8 = ListNode(6);

    node1.next = &node2;
    node2.next = &node3;
    node3.next = nullptr;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = nullptr;

    node7.next = &node8;
    node8.next = nullptr;

    std::vector<ListNode*> lists = vector<ListNode*>();
    lists.push_back(&node1);
    lists.push_back(&node4);
    lists.push_back(&node7);

    // ListNode node1 = ListNode(1);
    // ListNode node2 = ListNode(0);
    // node1.next = nullptr;
    // node2.next = nullptr;


    // std::vector<ListNode*> lists = vector<ListNode*>();
    // lists.push_back(&node1);
    // lists.push_back(&node2);
    ListNode* resList = solution.mergeKLists(lists);
    auto res = solution.getValVector(resList);
    for (auto i : res){
        cout << i << " ";
    }
    return 0;
}