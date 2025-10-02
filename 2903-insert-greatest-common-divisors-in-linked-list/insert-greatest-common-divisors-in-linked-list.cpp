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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* currnode=head;
        ListNode* nextnode=head->next;
        while(currnode && nextnode){
            int g=std::gcd(currnode->val, nextnode->val);
            ListNode* gcd=new ListNode(g);
            currnode->next=gcd;
            gcd->next=nextnode;
            currnode=nextnode;
            nextnode=nextnode->next;
        }
        return head;
    }
};