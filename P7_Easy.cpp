class Solution {
public:
    int reverse(int x) {
        long long y;
        long long z=0;
        bool m;
        if(x<0)
        {
            y=x;
            y*=(-1);
            m=true;
        }
        else
        {
            y=x;
            m=false;
        }
        while(y>0)
        {
            z=z*10+y%10;
            y/=10;
        }
        if(m)
            z*=(-1);
        if(z<INT_MIN || z>INT_MAX)
            return 0;
        return z;
    }
};
