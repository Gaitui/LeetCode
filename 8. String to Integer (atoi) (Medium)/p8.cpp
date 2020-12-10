class Solution {
public:
    int myAtoi(string str) {
        long long ans=0;
        stringstream ss;
        ss<<str;
        ss>>ans;
        if(ans>INT_MAX)
            return INT_MAX;
        else if(ans<INT_MIN)
            return INT_MIN;
        else
            return ans;
    }
};
