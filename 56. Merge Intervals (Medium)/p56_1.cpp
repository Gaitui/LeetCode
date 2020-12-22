class Solution {
public:
    bool static func(const vector<int>& a,const vector<int>& b)
    {
        return a[0]<b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end(),func);
        ans.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++)
        {
            if(ans[ans.size()-1][1]<intervals[i][0])
            {
                ans.push_back(intervals[i]);
            }
            ans[ans.size()-1][1]=max(ans[ans.size()-1][1],intervals[i][1]);
        }
        return ans;
    }
    
};
