class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int> range;
        range.push_back(intervals[0][0]);
        range.push_back(intervals[0][1]);
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=range[range.size()-2])
            {
                range.push_back(intervals[i][0]);
                range.push_back(intervals[i][1]);
            }
            else
            {
                for(int j=0;j<range.size();j+=2)
                {
                    if(range[j]>=intervals[i][0])
                    {
                        range.insert(range.begin()+j,intervals[i][1]);
                        range.insert(range.begin()+j,intervals[i][0]);
                        break;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        tmp.push_back(range[0]);
        tmp.push_back(range[0]);
        int Max=range[1];
        for(int i=3;i<range.size();i+=2)
        {
            if(range[i-1]>Max)
            {
                tmp[1]=Max;
                ans.push_back(tmp);
                tmp[0]=range[i-1];
            }
            Max=max(Max,range[i]);
        }
        tmp[1]=Max;
        ans.push_back(tmp);
        return ans;
    }
};
