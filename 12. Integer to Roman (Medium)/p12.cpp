class Solution {
public:
    string intToRoman(int n) {
        string ans;
        while(n>0)
        {
            if(n>=1000)
            {
                ans+="M";
                n-=1000;
            }
            else if(n>=900)
            {
                n-=900;
                ans+="CM";
            }
            else if(n>=500)
            {
                n-=500;
                ans+="D";
            }
            else if(n>=400)
            {
                n-=400;
                ans+="CD";
            }
            else if(n>=100)
            {
                n-=100;
                ans+="C";
            }
            else if(n>=90)
            {
                n-=90;
                ans+="XC";
            }
            else if(n>=50)
            {
                n-=50;
                ans+="L";
            }
            else if(n>=40)
            {
                n-=40;
                ans+="XL";
            }
            else if(n>=10)
            {
                n-=10;
                ans+="X";
            }
            else if(n>=9)
            {
                n-=9;
                ans+="IX";
            }
            else if(n>=5)
            {
                n-=5;
                ans+="V";
            }
            else if(n>=4)
            {
                n-=4;
                ans+="IV";
            }
            else
            {
                n--;
                ans+="I";
            }
        }
        return ans;
    }
};
