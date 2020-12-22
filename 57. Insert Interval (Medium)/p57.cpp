class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size()==0 || intervals[intervals.size()-1][1]<newInterval[0])
        {
            intervals.push_back(newInterval);
            return intervals;
        }
        if(intervals[0][0]>newInterval[1])
        {
            intervals.insert(intervals.begin(),newInterval);
            return intervals;
        }
        if(intervals[0][0]>=newInterval[0] && intervals[intervals.size()-1][1]<=newInterval[1])
        {
            vector<vector<int>> ans;
            ans.push_back(newInterval);
            return ans;
        }
        int num;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][0]>newInterval[0])
            {
                intervals.insert(intervals.begin()+i,newInterval);
                num=i;
                break;
            }
            else if(intervals[i][1]>=newInterval[0])
            {
                if(intervals[i][1]>=newInterval[1])
                {
                    return intervals;
                }
                else
                {
                    intervals[i][1]=newInterval[1];
                    num=i;
                    break;
                }
            }
        }
        for(int i=num+1;i<intervals.size();)
        {
            if(intervals[i][0]>intervals[num][1])
            {
                return intervals;
            }
            else
            {
                if(intervals[i][1]>=intervals[num][1])
                {
                    intervals[num][1]=intervals[i][1];
                    intervals.erase(intervals.begin()+i);
                    return intervals;
                }
                else
                {
                    intervals.erase(intervals.begin()+i);
                }
            }
        }
        return intervals;
    }
};
