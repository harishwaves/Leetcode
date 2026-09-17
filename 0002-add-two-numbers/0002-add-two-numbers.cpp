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
        ListNode *temp1 = l1,*temp2 = l2;
        ListNode* ans = new ListNode(-1),*a = ans;

        int carry = 0;
        while(temp1 && temp2){
            int sum = temp1->val + temp2->val + carry;
            carry = 0;
            if(sum>=10){
                sum = sum%10;
                carry = 1;
            }
            ListNode *val = new ListNode(sum);
            a->next = val;
            a = a->next;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int sum = temp1->val + carry;
            carry = 0;
            if(sum>=10){
                sum = sum%10;
                carry = 1;
            }
            ListNode *val = new ListNode(sum);
            a->next = val;
            a = a->next;
            temp1 = temp1->next;
        }
        while(temp2){
            int sum = temp2->val + carry;
            carry = 0;
            if(sum>=10){
                sum = sum%10;
                carry = 1;
            }
            ListNode *val = new ListNode(sum);
            a->next = val;
            a = a->next;
            temp2 = temp2->next;
        }
        if(carry==1){
            ListNode* last = new ListNode(1);
            a->next = last;
        }
        return ans->next;
    }
};