class Solution {
public:
    string minWindow(string s, string t) {
        vector<char> word;
        vector<int> wnum;
        vector<int> whic;
        vector<int> wher;
        for(int i=0;i<t.size();i++)
        {
            com(word,wnum,t[i]);
        }
        int count=0;
        int wbegin=0;
        int lend=findfirst(s,word,wnum,whic,wher);
        if(lend==-1)
        {
            return "";
        }
        int nl=wher[wher.size()-1]-wher[wbegin];
        int wb=wbegin;
        int we=wher.size()-1;
        while(1)
        {
            wbegin=findbegin(wnum,whic,wher,wbegin);
            if(nl>(wher[wher.size()-1]-wher[wbegin]))
            {
                we=wher.size()-1;
                wb=wbegin;
                nl = wher[wher.size()-1]-wher[wbegin];
            }
            lend=findend(s,word,wnum,whic,wher,lend,whic[wbegin]);
            if(lend==-1)
                break;
            wbegin++;
        }
        //cout<<"Begin: "<<wher[wb]<<" End: "<<wher[we]<<" NL = "<<nl<<endl;
        return s.substr(wher[wb], nl+1);
    }
    void com(vector<char>& word,vector<int>& wnum,char w)
    {
        for(int i=0;i<word.size();i++)
        {
            if(word[i]==w)
            {
                wnum[i]--;
                return;
            }
        }
        word.push_back(w);
        wnum.push_back(-1);
        return;
    }
    int findfirst(string &s,vector<char> &word,vector<int> &wnum,vector<int> &whic,vector<int> &wher)
    {
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            for(int j=0;j<word.size();j++)
            {
                if(s[i]==word[j])
                {
                    whic.push_back(j);
                    wher.push_back(i);
                    wnum[j]++;
                    if(wnum[j]==0)
                    {
                        c++;
                        if(c==word.size())
                            return i;
                    }
                }
            }
        }
        return -1;
    }
    int findbegin(vector<int> &wnum,vector<int> &whic,vector<int> &wher,int wbegin)
    {
        for(int i=wbegin;i<whic.size();i++)
        {
            wnum[whic[i]]--;
            if(wnum[whic[i]]<0)
            {
                return i;
            }
        }
        return wbegin;
    }
    int findend(string &s,vector<char> &word,vector<int> &wnum,vector<int> &whic,vector<int> &wher,int lend,int fword)
    {
        for(int i=lend+1;i<s.size();i++)
        {
            for(int j=0;j<word.size();j++)
            {
                if(s[i]==word[j])
                {
                    whic.push_back(j);
                    wher.push_back(i);
                    wnum[j]++;
                    if(j==fword)
                    {
                        return i;
                    }
                }
            }
        }
        return -1;
    }
};
