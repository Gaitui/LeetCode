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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int nodenum=0;
        while(temp!=NULL)
        {
            nodenum++;
            temp=temp->next;
        }
        if(nodenum-n==0)
        {
            head=head->next;
        }
        else
        {
            temp=head;
            for(int i=1;i<nodenum-n;i++)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
        return head;
    }
};
