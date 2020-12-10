class Solution {
    public int romanToInt(String s) {
        Map roman = new HashMap();
		roman.put('I',1);
		roman.put('V',5);
		roman.put('X',10);
		roman.put('L',50);
		roman.put('C',100);
		roman.put('D',500);
		roman.put('M',1000);
		int tmp=0,sum=0,k;
		tmp=(int)roman.get(s.charAt(0));
		for(int i=1;i<s.length();i++)
		{
			if((int)roman.get(s.charAt(i-1)) == (int)roman.get(s.charAt(i)))
			{
				tmp+=(int)roman.get(s.charAt(i));
			}
			else if((int)roman.get(s.charAt(i-1)) < (int)roman.get(s.charAt(i)))
			{
				sum+=(int)roman.get(s.charAt(i));
				sum-=tmp;
				tmp=0;
			}
			else
			{
				sum+=tmp;
				tmp=(int)roman.get(s.charAt(i));
			}
        }
        sum+=tmp;
        return sum;
    }
}
