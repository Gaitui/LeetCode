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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
        {
            return head;
        }
        ListNode* tmp=head;
        int num=1;
        while(tmp->next!=NULL)
        {
            tmp=tmp->next;
            num++;
        }
        tmp->next=head;
        tmp=head;
        for(int i=1;i<num-(k%num);i++)
        {
            tmp=tmp->next;
        }
        ListNode* ans=tmp->next;
        tmp->next=NULL;
        return ans;
    }
};
