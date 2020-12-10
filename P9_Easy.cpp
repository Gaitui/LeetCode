class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0))
            return false;
        long long k=x,w=0;
        while(k>0)
        {
            w=w*10+k%10;
            k/=10;
        }
        if(w!=x)
            return false;
        return true;
    }
};
