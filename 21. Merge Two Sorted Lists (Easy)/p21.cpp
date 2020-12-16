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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans;
        ListNode* now;
        ListNode* l1now;
        ListNode* l2now;
        if(l1==NULL)
        {
            return l2;
        }
        else if(l2==NULL)
        {
            return l1;
        }
        else
        {
            if(l1->val<l2->val)
            {
                ans=l1;
                now=l1;
                l1now=l1->next;
                l2now=l2;
            }
            else
            {
                ans=l2;
                now=l2;
                l2now=l2->next;
                l1now=l1;
            }
        }
        while(1)
        {
            if(l1now==NULL)
            {
                now->next=l2now;
                break;
            }
            else if(l2now==NULL)
            {
                now->next=l1now;
                break;
            }
            if(l1now->val<l2now->val)
            {
                now->next=l1now;
                l1now=l1now->next;
                now=now->next;
            }
            else
            {
                now->next=l2now;
                l2now=l2now->next;
                now=now->next;
            }
        }
        return ans;
    }
};
