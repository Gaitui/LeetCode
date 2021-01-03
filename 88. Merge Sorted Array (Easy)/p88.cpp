class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        for(int i=0;i<nums2.size();i++)
        {
            nums1.pop_back();
        }
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]>=nums2[j])
            {
                nums1.insert(nums1.begin()+i,nums2[j]);
                j++;
            }
            else
            {
                i++;
            }
        }
        for(;j<nums2.size();j++)
            nums1.push_back(nums2[j]);
        return;
    }
};
