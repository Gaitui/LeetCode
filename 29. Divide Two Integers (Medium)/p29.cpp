class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1)
        {
            return dividend;
        }
        else if(divisor==-1)
        {
            if(dividend<=(1<<31))
                return -((1<<31)+1);
            else
                return -(dividend);
        }
        else if(dividend==0)
            return 0;
        bool flag = false;
        if(dividend > 0)
        {
            dividend=-dividend;
            flag = !flag;
        }
        if(divisor > 0)
        {
            flag = !flag;
        }
        else
        {
            if(dividend-divisor>0)
                return 0;
            else if(dividend-divisor==0)
            {
                if(flag)
                {
                    return -1;
                }
                return 1;
            }
            divisor=-divisor;
        }
        int k=divisor;
        int i=0;
        while(1)
        {
            if(dividend+k>=-k)
            {
                if(dividend+k==-k)
                {
                    if(flag)
                        return -(1<<(i+1));
                    else
                        return 1<<(i+1);
                }
                break;
            }
            i++;
            k<<=1;
        }
        int ans=0;
        do
        {
            ans<<=1;
            if(dividend+k<=0)
            {
                ans++;
                dividend+=k;
            }
            k>>=1;
        }while(i--);
        if(flag)
        {
            ans=-ans;
        }
        return ans;
    }
};
