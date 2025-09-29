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
    int length_LL(ListNode* head){
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        int len=length_LL(head);
        int k1=k;
        ListNode* first_node=head;
        while(k1>1){
            first_node=first_node->next;
            k1--;
        }
        int k2=len-k+1;
        ListNode* second_node=head;
        while(k2>1){
            second_node=second_node->next;
            k2--;
        }
        swap(first_node->val,second_node->val);
        return head;
    }
};