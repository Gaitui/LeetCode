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
    ListNode* swapPairs(ListNode* head) {
        ListNode* now=head;
        ListNode* next;
        ListNode* last=NULL;
        while(now!=NULL)
        {
            if(now->next==NULL)
                break;
            next=now->next;
            if(last!=NULL)
            {
                last->next=next;
            }
            else
            {
                head=next;
            }
            now->next=next->next;
            next->next=now;
            last=now;
            now=last->next;
        }
        return head;
    }
};
