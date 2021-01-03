class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if(n==0)
            return ans;
        int tmp=0;
        run(ans,n-1,tmp,1);
        return ans;
    }
    void run(vector<int> &ans,int n,int &tmp,int p)
    {
        if(n>0)
        {
            run(ans,n-1,tmp,1);
            if(p==1)
            {
                tmp+=pow(2,n);
            }
            else
            {
                tmp-=pow(2,n);
            }
            ans.push_back(tmp);
            run(ans,n-1,tmp,0);
        }
        else
        {
            if(p==1)
            {
                tmp++;
            }
            else
            {
                tmp--;
            }
            ans.push_back(tmp);
        }
        return;
    }
};
