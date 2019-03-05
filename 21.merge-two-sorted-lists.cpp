/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (45.84%)
 * Total Accepted:    513.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
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
class Solution {
   public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result;
        ListNode* other;
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        if (l1->val < l2->val) {
            result = l1;
            other = l2;
        } else {
            result = l2;
            other = l1;
        }
        ListNode* tmp_result = result;
        ListNode* tmp_node;
        while (tmp_result->next != nullptr) {
            if (other != nullptr) {
                if (tmp_result->next->val > other->val) {
                    tmp_node = tmp_result->next;
                    tmp_result->next = other;
                    other = other->next;
                    tmp_result->next->next = tmp_node;
                    tmp_result = tmp_result->next;
                } else if (tmp_result->next->val <= other->val) {
                    tmp_result = tmp_result->next;
                }
            } else {
                // 必须要循环完
                tmp_result = tmp_result->next;
            }
        }
        if (other) {
            tmp_result->next = other;
        }
        return result;
    }
};
