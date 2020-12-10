class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n,o;
        int i,j;
        double ans;
        n=nums1.size()+nums2.size();
        if(n%2==0)
        {
            o=0;
        }
        else
        {
            o=1;
        }
        i=0;
        j=0;
        ans=0.0;
        while(1)
        {
            if(i<nums1.size() && j<nums2.size())
            {
                if((i+j)==(n/2))
                {
                    if(o)
                    {
                        if(nums1[i]>nums2[j])
                        {
                            ans=nums2[j];
                        }
                        else
                        {
                            ans=nums1[i];
                        }
                        return ans;
                    }
                    else
                    {
                        if(nums1[i]>nums2[j])
                        {
                            ans+=nums2[j];
                        }
                        else
                        {
                            ans+=nums1[i];
                        }
                        return ans/2;
                    }

                }
                if(nums1[i]>nums2[j])
                {
                    ans=nums2[j];
                    j++;
                }
                else
                {
                    ans=nums1[i];
                    i++;
                }   
            }
            else if(i==nums1.size())
            {
                if((i+j)==(n/2))
                {
                    if(o)
                    {
                        return (double)nums2[j];
                    }
                    else
                    {
                        return (ans+nums2[j])/2;
                    }
                }
                ans=nums2[j];
                j++;
            }
            else
            {
                if((i+j)==(n/2))
                {
                    if(o)
                    {
                        return (double)nums1[i];
                    }
                    else
                    {
                        return (ans+nums1[i])/2;
                    }

                } 
                ans=nums1[i];
                i++;
            }
        }
    }
};
