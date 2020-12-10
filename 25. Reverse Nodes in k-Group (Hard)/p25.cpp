class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> x;
        ListNode* ans=new ListNode;
        ListNode* tmp=head;
        ListNode* now=ans;
        bool first=true;
        while(tmp!=NULL)
        {
            x.push_back(tmp->val);
            tmp=tmp->next;
        }
        for(int i=0;i<x.size();)
        {
            if(i+k-1<x.size())
            {
                for(int j=i+k-1;j>=i;j--)
                {
                    if(first)
                    {
                        now->val=x[j];
                        first=false;
                    }
                    else
                    {
                        ListNode* t=new ListNode;
                        t->val=x[j];
                        now->next=t;
                        now=now->next;
                    }
                }
                i+=k;
            }
            else
            {
                if(first)
                {
                    now->val=x[i];
                    first=false;
                }
                else
                {
                    ListNode* t=new ListNode;
                    t->val=x[i];
                    now->next=t;
                    now=now->next;
                }
                i++;
            }
        }
        return ans;
