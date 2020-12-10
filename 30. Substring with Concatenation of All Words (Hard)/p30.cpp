class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int ws=words.size();
        int ss=words[0].size();
        bool *flag=new bool[ws];
        bool find;
        int refind;
        vector<int> order;
        vector<int> ans;
        string sub;
        //cout<<ws<<" "<<ss<<endl;
        for(int f=0;f<ws;f++)
        {
            flag[f]=true;
        }
        for(int x=0;x<s.size()-ss*ws+1;x++)
        {
            for(int i=x;i<s.size()-ss+1;i+=ss)
            {
                find=false;
                sub=s.substr(i,ss);
                for(int f=0;f<ws;f++)
                {
                    if(flag[f])
                    {
                        if(words[f].compare(sub)==0)
                        {
                            flag[f]=false;
                            order.push_back(f);
                            find=true;
                            break;
                        }
                    }
                }
                if(find)
                {
                    //cout<<"find"<<endl;
                    if(order.size()==ws)
                    {
                        //cout<<i<<endl;
                        ans.push_back(i-(ws-1)*ss);
                        for(int j=0;j<order.size();j++)
                        {
                            flag[order[j]]=true;
                        }
                        order.clear();
                        break;
                    }
                }
                else
                {
                    for(int j=0;j<order.size();j++)
                    {
                        flag[order[j]]=true;
                    }
                    order.clear();
                    break;
                }
            }
        }
        return ans;
    }
};
