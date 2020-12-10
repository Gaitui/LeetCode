class Solution {
public:
    string multiply(string num1, string num2) {
        if((num1.size()==1 && num1[0]=='0') || (num2.size()==1 && num2[0]=='0') )
        {
            return "0";
        }
        string ans;
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        for(int i=0;i<num1.size();i++)
        {
            int e=0;
            int c=0;
            for(int j=0;j<num2.size();j++)
            {
                e=(num1[i]-'0')*(num2[j]-'0')+c;
                //cout<<e<<" ";
                if(i+j<ans.size())
                {
                    e+=(ans[i+j]-'0');
                    c=e/10;
                    e=e%10;
                    ans[i+j]=e+'0';
                }
                else
                {
                    c=e/10;
                    e=e%10;
                    ans+=(e+'0');
                }
            }
            while(c>0)
            {
                ans+=(c%10+'0');
                c/=10;
            }
            //cout<<endl;
            //cout<<"ansnow = "<<ans<<endl;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
