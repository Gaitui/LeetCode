class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        pair<int,int> tmp;
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
            if(st.empty() || heights[i]>st.top().first)
            {
                tmp.first=heights[i];
                tmp.second=i;
                st.push(tmp);
            }
            else if(heights[i]<st.top().first)
            {
                while(!st.empty() && st.top().first>=heights[i])
                {
                    tmp.second=st.top().second;
                    ans=max(ans,st.top().first*(i-st.top().second));
                    st.pop();
                }
                tmp.first=heights[i];
                st.push(tmp);
            }
        }
        while(!st.empty())
        {
            if(st.top().first*(heights.size()-st.top().second)>ans)
                ans=st.top().first*(heights.size()-st.top().second);
            st.pop();
        }
        return ans;
    }
};
