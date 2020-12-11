class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> sstr;
        if(strs.size()==0)
            return ans;
        for(int i=0;i<strs.size();i++)
        {
            bool f=true;
            string s=strs[i];
            sort(s.begin(),s.end());
            for(int j=0;j<sstr.size();j++)
            {
                if(s==sstr[j])
                {
                    f=false;
                    ans[j].push_back(strs[i]);
                    break;
                }
            }
            if(f)
            {
                vector<string> tmp;
                tmp.push_back(strs[i]);
                ans.push_back(tmp);
                sstr.push_back(s);
            }
        }
        return ans;
    }
};
