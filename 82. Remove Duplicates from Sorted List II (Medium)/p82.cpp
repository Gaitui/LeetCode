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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        bool f;
        while(1)
        {
            f=false;
            while(head != NULL && head->next!=NULL)
            {
                if(head->val == head->next->val)
                {
                    head=head->next;
                    f=true;
                }
                else
                {
                    break;
                }
            }
            if(f)
            {
                head=head->next;
            }
            else
            {
                break;
            }
        }
        ListNode* last=head;
        ListNode* now;
        while(last!=NULL && last->next!=NULL)
        {
            f=false;
            now = last->next;
            while(now->next!=NULL)
            {
                if(now->val == now->next->val)
                {
                    now=now->next;
                    f=true;
                }
                else
                {
                    break;
                }
            }
            if(f)
            {
                last->next=now->next;
            }
            else
            {
                last=last->next;
            }
        }
        return head;
    }
};
