class Solution {
public:
    vector<string> ans;
    void running(string digits,string *word,string str,int k)
    {
        if(k==digits.size())
        {
            ans.push_back(str);
            return;
        }
        else
        {
            for(int i=0;i<word[digits[k]-'2'].size();i++)
            {
                running(digits,word,str+word[digits[k]-'2'][i],k+1);
            }
            return;
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0)
            return ans;
        string word[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        running(digits,word,"",0);
        return ans;
    }
};
