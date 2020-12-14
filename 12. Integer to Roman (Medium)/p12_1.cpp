class Solution {
public:
    string intToRoman(int n) {
        string ans;
        map<int,string,greater<int>> r;
        r[1000]="M";
        r[900]="CM";
        r[500]="D";
        r[400]="CD";
        r[100]="C";
        r[90]="XC";
        r[50]="L";
        r[40]="XL";
        r[10]="X";
        r[9]="IX";
        r[5]="V";
        r[4]="IV";
        r[1]="I";
        map<int,string>::iterator iter;
        for(iter=r.begin();iter!=r.end();)
        {
            if(n>=iter->first)
            {
                n-=iter->first;
                ans+=iter->second;
            }
            else
            {
                iter++;
            }
        }
        return ans;
    }
};
