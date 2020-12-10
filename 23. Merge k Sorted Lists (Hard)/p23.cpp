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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int nullnum=0;
        int Min=1e9,wMin=0;
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i]==NULL || lists[i]->val==1e9)
            {
                nullnum++;
            }
            else
            {
                if(lists[i]->val<Min)
                {
                    Min=lists[i]->val;
                    wMin=i;
                }
            }
        }
        if(nullnum<lists.size())
        {
            ListNode* ans=new ListNode;
            ListNode* now=ans;
            now->val=Min;
            while(1)
            {
                lists[wMin]->val=1e9;
                if(lists[wMin]->next!=NULL)
                {
                    lists[wMin]=lists[wMin]->next;   
                }
                nullnum=0;
                Min=1e9;
                wMin=0;
                for(int i=0;i<lists.size();i++)
                {
                    if(lists[i]==NULL || lists[i]->val==1e9)
                    {
                        nullnum++;
                    }
                    else
                    {
                        if(lists[i]->val<Min)
                        {
                            Min=lists[i]->val;
                            wMin=i;
                        }
                    }
                }
                if(nullnum==lists.size())
                {
                    break;
                }
                ListNode* temp=new ListNode;
                temp->val=Min;
                now->next=temp;
                now=now->next;
            }
            return ans;
        }
        else
        {
            return NULL;
        }
        
    }
};
