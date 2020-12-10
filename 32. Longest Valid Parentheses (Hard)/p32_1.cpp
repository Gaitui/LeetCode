class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> k;
        int ans=0;
        k.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='\(')
            {
                k.push(i);
            }
            else
            {
                k.pop();
                if(k.empty())
                {
                    k.push(i);
                }
                else
                {
                    ans=max(ans,i-k.top());
                }
            }
        }
        return ans;
    }
};
