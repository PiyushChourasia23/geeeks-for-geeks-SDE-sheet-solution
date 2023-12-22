                                 // In simple way c language
#include<stdio.h>
void sum(int x[],int n,int s)
{
	int left=0;
	int right=0;
	int sum=x[0];
	for(int i=0;i<n;i++)
	{
		if(sum==s)
		{
		printf("%d ",left+1);	
		printf("%d",right+1);	
		return;
		}
		if(sum<s)
		{
			right++;
			sum=sum+x[right];
		}
		if(sum>s)
		{
			sum=sum-x[left];
			left++;
		}
	}
	printf("-1");
}
void main()
{
	int n=10;
	int s=15;
	int x[]={1,2,3,4,5,6,7,8,9,10};
	sum(x,n,s);
}
                             // In java Acc. t0 geeks for geeks
import java.util.*;
import java.lang.*;
import java.io.*;
class Main{
	static BufferedReader br;
    static PrintWriter ot;
    public static void main(String[] args) throws IOException
	{
        
        br = new BufferedReader(new InputStreamReader(System.in));
        ot = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine());
        while(t-->0){
            
            String s[] = br.readLine().trim().split(" ");
            
            int n = Integer.parseInt(s[0]);
            int k = Integer.parseInt(s[1]);
            int a[] = new int[n];
            s = br.readLine().trim().split(" ");
            for(int i = 0; i < n; i++)
                a[i] = Integer.parseInt(s[i]);
            Solution obj = new Solution();
            ArrayList<Integer> res = obj.subarraySum(a, n, k);
            for(int ii = 0;ii<res.size();ii++)
                ot.print(res.get(ii) + " ");
            ot.println();
        }
        ot.close();
    }

}
// } Driver Code Ends


class Solution
{
    //Function to find a continuous sub-array which adds up to a given number.
    static ArrayList<Integer> subarraySum(int[] arr, int n, int s) 
    {
    ArrayList<Integer> list = new ArrayList<>();
        
        int i = 0, j = 0, sum = 0;
    
        while(i < n)
        {
            sum = sum + arr[i];
            
            while(sum > s && j < i)                                                    // but s or target is  0.
            {
                sum = sum - arr[j];
                j++;
            }
            
            if(sum == s)
            {
                list.add(j+1);
                list.add(i+1);
                return list;
            }
            
            i++;
        }
        
        
        list.add(-1);
        return list;
    
     
    }
}
