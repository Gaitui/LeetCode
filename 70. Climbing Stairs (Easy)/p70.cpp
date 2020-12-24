class Solution {
public:
    int climbStairs(int n) {
        int pre=1;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            pre+=ans;
            swap(pre,ans);
        }
        return ans;
    }
};
