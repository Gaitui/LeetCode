class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
                return 0;
        if(haystack.size()==0 || haystack.size()<needle.size())
        {
                return -1;
        }
        int find=-1;
        for(int i=0;i<haystack.size()-needle.size()+1;i++)
        {
            if(haystack[i]==needle[0])
            {
                find=true;
                for(int j=0;j<needle.size();j++)
                {
                    find=i;
                    if(haystack[i+j]!=needle[j])
                    {
                        find=-1;
                        break;
                    }
                }
                if(find!=-1)
                    return find;
            }
        }
        return find;
    }
};
