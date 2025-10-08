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
    int pairSum(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        //slow pointer is the mid node
        ListNode* mid=slow;
        ListNode* prev=nullptr;
        ListNode* front=nullptr;
        while(mid){
            front=mid->next;
            mid->next=prev;
            prev=mid;
            mid=front;
        }
    int result=0;
    ListNode* temp=head;
    while(prev){
        result=max(result,prev->val+temp->val);
        temp=temp->next;
        prev=prev->next;
    }
        //reverse
    return result;
    }
};