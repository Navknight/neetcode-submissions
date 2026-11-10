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
    ListNode* merge(ListNode* node1, ListNode* node2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        while(node1 && node2) {
            if(node1->val < node2->val) {
                temp->next = node1;
                node1 = node1->next;
            } else {
                temp->next = node2;
                node2 = node2->next;
            }
            temp = temp->next;
        }

        if(node1) temp->next = node1;
        else temp -> next = node2;

        return ans->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        int n = lists.size();
        if(n == 0) return nullptr;
        queue<ListNode*> q;
        for(auto& l: lists) q.push(l);

        while(q.size() > 1) {
            ListNode* l1 = q.front(); q.pop();
            ListNode* l2 = q.front(); q.pop();

            q.push(merge(l1, l2));
        }

        return q.front();
    }
};
