class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> num;
        string ans;
        int s=1;
        int x=n-1;
        for(int i=2;i<n;i++)
            s*=i;
        for(int i=1;i<=n;i++)
        {
            if(s>=k)
            {
                ans+=(i+'0');
                if(x==0)
                    return ans;
                s/=x;
                x--;
            }
            else
            {
                num.push_back(i+'0');
            }
        }
        while(1)
        {
            if(k%s==0)
            {
                ans+=num[(k/s)-1];
                num.erase(num.begin()+(k/s)-1);
                k=s;
            }
            else
            {
                ans+=num[k/s];
                num.erase(num.begin()+(k/s));
                k=k%s;
            }
            if(x==0)
                return ans;
            s/=x;
            x--; 
        }
    }
};
