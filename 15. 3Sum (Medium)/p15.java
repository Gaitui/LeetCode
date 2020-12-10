class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans=new ArrayList<List<Integer>>();
		int minus=-1;
		int zero=-1;
		int plus=-1;
		Arrays.sort(nums);
		/*for(int i=0;i<nums.length;i++)
		{
			System.out.print(nums[i]+' ');
		}
		System.out.println();*/
		for(int i=0;i<nums.length;i++)
		{
			if(nums[i]==0 && zero==-1)
			{
				zero=i;
				minus=i-1;
			}
			else if(nums[i]>0)
			{
				plus=i;
				if(zero==-1)
				{
					minus=i-1;
				}
				break;
			}
		}
        if(zero!=-1 && nums.length>2)
        {
            if(zero+2<nums.length && nums[zero+2]==0)
            {
                List<Integer> temp=new ArrayList();
                temp.add(0);
                temp.add(0);
                temp.add(0);
                ans.add(temp);   
            }
        }
		if(minus==-1 || plus==-1)
		{
			
            //System.out.println("[]");
			//return;
			return ans;
		}
		for(int i=plus;i<nums.length;i++)
		{
			if(nums[i]==nums[i-1])
			{
				continue;
			}
			for(int j=minus;j>=0;j--)
			{
				if(nums[j]==nums[j+1])
				{
					continue;
				}
				int k=nums[i]+nums[j];
				if(k==0 && zero!=-1)
				{
					List<Integer> temp=new ArrayList();
					temp.add(nums[j]);
					temp.add(0);
					temp.add(nums[i]);
					ans.add(temp);
				}
				else if(k+nums[j]>=0)
				{
					for(int z=j-1;z>=0;z--)
					{
						if(k+nums[z]==0)
						{
							List<Integer> temp=new ArrayList();
							temp.add(nums[z]);
							temp.add(nums[j]);
							temp.add(nums[i]);
							ans.add(temp);
							break;
						}
						else if(k+nums[z]<0)
						{
							break;
						}
					}
				}
			}
		}
		for(int j=minus;j>=0;j--)
		{
			if(nums[j]==nums[j+1])
			{
				continue;
			}
			for(int i=plus;i<nums.length;i++)
			{
				if(nums[i]==nums[i-1])
				{
					continue;
				}
				int k=nums[i]+nums[j];
				if(k+nums[i]<=0)
				{
					for(int x=i+1;x<nums.length;x++)
					{
						if(k+nums[x]==0)
						{
							List<Integer> temp=new ArrayList();
							temp.add(nums[j]);
							temp.add(nums[i]);
							temp.add(nums[x]);
							ans.add(temp);
                            				break;
						}
						else if(k+nums[x]>0)
						{
							break;
						}
					}
				}
			}
		}
		/*for(int i=0;i<ans.size();i++)
		{
			for(int j=0;j<ans.get(i).size();j++)
			{
				System.out.print(ans.get(i).get(j)+' ');
			}
			System.out.println();
		}*/
        return ans;
    }
}
