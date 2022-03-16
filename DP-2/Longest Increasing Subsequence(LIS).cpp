/*
Given an array with N elements, you need to find the length of the longest subsequence in the given array such that all elements of the subsequence are sorted in strictly increasing order.
Input Format

The first line of input contains an integer N. The following line contains N space separated integers, that denote the value of elements of array.

Output Format

The first and only line of output contains the length of longest subsequence.

Constraints

1 <= N <= 10^3
Time Limit: 1 second

Sample Input 1 :

6
5 4 11 1 16 8

Sample Output 1 :

3

Sample Output Explanation

Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2 :

3
1 2 2

Sample Output 2 :

2
*/

/*********Brute Force***********/
#include<climits>
int longestIncreasingSubsequence(int* arr,int n,int i,int prev)
{
	if (i==n)
		return 0;
	int exclude=longestIncreasingSubsequence(arr,n,i+1,prev);
	int include=0;
	if (arr[i]>prev)
		include=1+longestIncreasingSubsequence(arr,n,i+1,arr[i]);
	return max(include, exclude);
}
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    return longestIncreasingSubsequence(arr,n,0,INT_MIN);
}

/***************DP******************/
#include<climits>
int longestIncreasingSubsequence(int* arr, int n) {
	// Write your code here
    int *dp=new int[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
                if(dp[j]+1>dp[i])
                    dp[i]=dp[j]+1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(ans<dp[i]) 
            ans=dp[i];
    }
    return ans;
}
