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
        ListNode *lr=new ListNode();
        ListNode *lrn=lr;
        int carry=0;
        int k,w,p;
        while(1)
        {
            k=0,w=0;
            if(l1!=NULL)
            {
                k=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                w=l2->val;
                l2=l2->next;
            }
            p=k+w+carry;
            carry=0;
            if(p>9)
            {
                p-=10;
                carry++;
            }
            lrn->val=p;
            if(l1!=NULL || l2!=NULL)
            {
                lrn->next=new ListNode();
                lrn=lrn->next;   
            }
            else
            {
                if(carry!=0)
                {
                    lrn->next=new ListNode();
                    lrn=lrn->next; 
                    lrn->val=carry;
                }
                break;
            }
        }
        return lr;
    }
};
