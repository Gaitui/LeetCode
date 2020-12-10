class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str;
        if(strs.size()==0)
            return str;
        for(int i=0;i<strs[0].size();i++)
        {
            for(int j=1;j<strs.size();j++)
            {
                if(strs[j].size()==i || strs[j][i]!=strs[0][i])
                {
                    return str;
                }
            }
            str+=strs[0][i];
        }
        return str;
    }
};
