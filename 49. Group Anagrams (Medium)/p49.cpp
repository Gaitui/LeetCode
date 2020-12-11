class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        bool *u=new bool[strs.size()];
        vector<string> tmp;
        for(int i=0;i<strs.size();i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            tmp.push_back(str);
            u[i]=true;
        }
        vector<vector<string>> ans;
        for(int i=0;i<strs.size();i++)
        {
            if(u[i])
            {
                vector<string> as;
                as.push_back(strs[i]);
                u[i]=false;
                for(int j=i+1;j<strs.size();j++)
                {
                    if(u[j] && tmp[i]==tmp[j])
                    {
                        as.push_back(strs[j]);
                        u[j]=false;
                    }
                
                }
                ans.push_back(as);
            }
        }
        return ans;
    }
};
