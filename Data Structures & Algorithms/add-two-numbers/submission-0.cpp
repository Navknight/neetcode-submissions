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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode();
        ListNode* ans = dummy;
        while (l1 && l2) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            dummy->next = new ListNode(sum);
            l1 = l1->next;
            l2 = l2->next;
            dummy = dummy->next;
        }

        if (l2) l1 = l2;
        while (carry && l1) {
            int sum = l1->val + carry;
            carry = sum / 10;
            sum = sum % 10;
            dummy->next = new ListNode(sum);
            l1 = l1->next;
            dummy = dummy->next;
        }

        if (carry) {
            dummy->next = new ListNode(carry);
        } else if (l1) {
            dummy->next = l1;
        }

        return ans->next;
    }
};
