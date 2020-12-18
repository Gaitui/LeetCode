class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)
        {
            return 0;
        }
        int left=0;
        int right=height.size()-1;
        int leftmax=height[0];
        int rightmax=height[height.size()-1];
        int ans=0;
        while(right>left)
        {
            if(leftmax<rightmax)
            {
                left++;
                if(height[left]>=leftmax)
                    leftmax=height[left];
                else
                    ans+=(leftmax-height[left]);
            }
            else
            {
                right--;
                if(height[right]>=rightmax)
                    rightmax=height[right];
                else
                    ans+=(rightmax-height[right]);
            }
        }
        return ans;
    }
};
