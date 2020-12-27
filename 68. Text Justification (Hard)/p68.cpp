class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int num=words[0].size();
        vector<string> ans;
        int b=0;
        int e=1;
        int space=0;
        while(e<=words.size())
        {
            if(e==words.size())
            {
                string tmp;
                int blank = maxWidth-num;
                for(int i=b;i<e-1;i++)
                {
                    tmp+=words[i];
                    tmp+=" ";
                    blank--;   
                }
                tmp+=words[e-1];
                for(;blank>0;)
                {
                    tmp+=" ";
                    blank--;
                }
                ans.push_back(tmp);
                return ans;
            }
            if(num+space+1+words[e].size()>maxWidth)
            {
                string tmp;
                int blank = maxWidth-num;
                if(e-b-1>0)
                {
                    //cout<<blank<<" "<<space<<endl;
                    blank-=space;
                    int bnum=blank/(e-b-1);
                    int blos=blank%(e-b-1);
                    for(int i=b;i<e-1;i++)
                    {
                        tmp+=words[i];
                        tmp+=" ";
                        int k=bnum;
                        while(k--)
                        {
                            tmp+=" ";
                            blank--;
                        }
                        if(blos>0)
                        {
                            tmp+=" ";
                            blank--;
                            blos--;
                        }
                    }
                    tmp+=words[e-1];
                }
                else
                {
                    tmp+=words[b];
                    for(;blank>0;)
                    {
                        tmp+=" ";
                        blank--;
                    }
                }
                ans.push_back(tmp);
                num=words[e].size();
                b=e;
                e++;
                space=0;
            }
            else
            {
                num+=words[e].size();
                e++;
                space++;
            }
        }
        return ans;
    }
};
