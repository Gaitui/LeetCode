class Solution {
public:
    vector<string> ans;
    void run(string str,int ln,int rn)
    {
        if(ln+rn==0)
        {
            ans.push_back(str);
        }
        else
        {
            if(rn>ln)
            {
                run(str+'\)',ln,rn-1);
            }
            if(ln>0)
            {
                run(str+'\(',ln-1,rn);
            }
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        string str;
        run(str,n,n);
        return ans;
    }
    
};
