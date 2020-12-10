class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> x;
        ListNode* tmp=head;
        while(tmp!=NULL)
        {
            x.push_back(tmp->val);
            tmp=tmp->next;
        }
        tmp=head;
        for(int i=0;i<x.size();)
        {
            if(i+k-1<x.size())
            {
                for(int j=i+k-1;j>=i;j--)
                {
                    tmp->val=x[j];
                    tmp=tmp->next;
                }
                i+=k;
            }
            else
            {
                break;
            }
        }
        return head;
    }
};
