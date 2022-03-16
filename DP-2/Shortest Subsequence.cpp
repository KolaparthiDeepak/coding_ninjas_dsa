/*
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :

The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.

Output Format :

Length of shortest subsequence in S such that it is not a subsequence in V

Constraints:

1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second

Sample Input 1:

babab
babba

Sample Output 1:

3

Explanation:

"aab" is the shortest subsequence which is present in S and absent in V.
*/

#include<string>
int solve(string s,string v,int m,int n,int** dp)
{
    if(m==0)
        return 1001;
    if(n<=0)
        return 1;
    if(dp[m][n]!=-1)
        return dp[m][n];
    int ans;
    //exclude first letter of s
    int choice1=solve(s.substr(1),v,m-1,n,dp);
	int i=0;
	for(;i<n;i++)
	{
		if(s[0]==v[i])
		{
			break;
		}
	}
	if(i==n)
	{
		return 1;
	}
    //include first letter of s
    int choice2=1+solve(s.substr(1),v.substr(i+1),m-1,n-i-1,dp);
    dp[m][n]=min(choice1,choice2);
    return dp[m][n];
}
int solve(string s, string v) {
    // Write your code here
    int m=s.length();
    int n=v.length();
	int **dp=new int*[m+1];
    for(int i=0;i<m+1;i++)
    {
        dp[i]=new int[n+1];
        for(int j=0;j<n+1;j++)
        {
            dp[i][j]=-1;
        }
    }
    return solve(s,v,m,n,dp);
}
