class Solution {
public:
    string countAndSay(int n) {
        string a;
        a+='1';
        string b;
        while(--n)
        {
            string b;
            char c='1';
            char k=a[0];
            for(int i=1;i<a.size();i++)
            {
                if(a[i]==k)
                {
                    c++;
                }
                else
                {
                    b+=c;
                    b+=k;
                    c='1';
                    k=a[i];
                }
            }
            b+=c;
            b+=k;
            a=b;
        }
        return a;
    }
};
