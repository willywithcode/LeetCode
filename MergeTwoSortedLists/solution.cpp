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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* sortedList = new ListNode();
        ListNode* head = sortedList;
        if (!list1 && !list2)
            return nullptr;
        while (list1 || list2) {
            if (!list1) {
                head->val = list2->val;
                list2 = list2->next;
            } else if (!list2) {
                head->val = list1->val;
                list1 = list1->next;
            } else {
                if (list1->val < list2->val) {
                    head->val = list1->val;
                    list1 = list1->next;
                } else {
                    head->val = list2->val;
                    list2 = list2->next;
                }
            }
            if (list1 || list2) {
                head->next = new ListNode();
                head = head->next;
            }
        }
        return sortedList;
    }
};