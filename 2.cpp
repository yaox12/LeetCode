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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode(-1);
        ListNode* now = ans;
        int carry = 0;
        int cnt;
        while (l1 != NULL && l2 != NULL) {
            cnt = (l1->val + l2->val + carry) % 10;
            now->next = new ListNode(cnt);
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            now = now->next;
        }
        
        while (l1 != NULL) {
            cnt = (l1->val + carry) % 10;
            now->next = new ListNode(cnt);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
            now =  now->next;
        }
        
        while (l2 != NULL) {
            cnt = (l2->val + carry) % 10;
            now->next = new ListNode(cnt);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
            now =  now->next;
        }
        
        if (carry != 0)
            now->next = new ListNode(carry);
        
        return ans->next;
    }
};