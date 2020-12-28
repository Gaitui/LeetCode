class Solution {
public:
    string simplifyPath(string path) {
        vector<string> str;
        string tmp;
        for(int i=0;i<path.size();i++)
        {
            if(path[i]=='/' || i==path.size()-1)
            {
                if(path[i]!='/')
                    tmp+=path[i];
                if(tmp.size()==2 && (tmp[0]=='.' && tmp[1]=='.'))
                {
                       if(str.size()!=0)
                       {
                           str.pop_back();
                       }
                }
                else if((tmp.size()==1 && tmp[0]!='.') || tmp.size()>1)
                {
                    str.push_back(tmp);
                }
                tmp.clear();
            }
            else
            {
                tmp+=path[i];          
            }
        }
        string ans;
        if(str.size()==0)
        {
            ans+='//';
            return ans;
        }
        for(int i=0;i<str.size();i++)
        {
            ans+='//';
            ans+=str[i];
        }
        return ans;
    }
};
