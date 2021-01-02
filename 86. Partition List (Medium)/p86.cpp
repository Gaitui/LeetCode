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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tmp = head;
        ListNode* ntmp;
        ListNode* small;
        if(tmp==NULL)
            return head;
        if(tmp->val>=x)
        {
            while(1)
            {
                ntmp=tmp->next;
                if(ntmp==NULL)
                {
                    return head;
                }
                if(ntmp->val<x)
                {
                    tmp->next=ntmp->next;
                    ntmp->next=head;
                    head = ntmp;
                    break;
                }
                tmp=ntmp;
            }
            small=head;
            while(1)
            {
                ntmp=tmp->next;
                if(ntmp==NULL)
                {
                    return head;
                }
                if(ntmp->val<x)
                {
                    tmp->next=ntmp->next;
                    ntmp->next=small->next;
                    small->next = ntmp;
                    small=small->next;
                }
                else
                {
                    tmp=ntmp;
                }
            }
        }
        else
        {
            while(1)
            {
                ntmp=tmp->next;
                if(ntmp==NULL)
                {
                    return head;
                }
                if(ntmp->val>=x)
                {
                    small=tmp;
                    tmp=ntmp;
                    break;
                }
                else
                {
                    tmp=ntmp;
                }
            }
            while(1)
            {
                ntmp=tmp->next;
                if(ntmp==NULL)
                {
                    return head;
                }
                if(ntmp->val<x)
                {
                    tmp->next=ntmp->next;
                    ntmp->next=small->next;
                    small->next = ntmp;
                    small=small->next;
                }
                else
                {
                    tmp=ntmp;
                }
            }
        }
        
    }
};
