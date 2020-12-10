class Solution {
public:
    int maxArea(vector<int>& height) {
        int Max=0;
        int i=0;
        int j=height.size()-1;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                Max=max(Max,(j-i)*height[i]);
                i++;
            }
            else
            {
                Max=max(Max,(j-i)*height[j]);
                j--;
            }
        }
        return Max;
    }
};
