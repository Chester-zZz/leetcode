/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
 *
 * https://leetcode.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (35.33%)
 * Total Accepted:    209.8K
 * Total Submissions: 593.7K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example:
 *
 *
 * Input:  1->2->6->3->4->5->6, val = 6
 * Output: 1->2->3->4->5
 *
 *
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };
class Solution {
   public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }
        ListNode* ptr = head;
        while (ptr->next) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            } else {
                ptr = ptr->next;
            }
        }
        if (head->val == val) {
            head = head->next;
        }
        return head;
    }
};
