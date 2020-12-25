class Solution {
public:
    int uniquePaths(int m, int n) {
        int k=m+n-2;
        int x=max(m-1,n-1);
        int y=min(m-1,n-1);
        int ans=1;
        for(int i=2;i<=y;)
        {
            if(ans%i==0)
            {
                ans/=i;
                i++;
            }
            else
            {
                ans*=k;
                k--;
            }
        }
        while(k>x)
        {
            ans*=k;
            k--;
        }
        return ans;
    }
};
