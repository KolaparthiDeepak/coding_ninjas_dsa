/*
Given a chain of matrices A1, A2, A3,.....An, you have to figure out the most efficient way to multiply these matrices. In other words, determine where to place parentheses to minimize the number of multiplications.
You will be given an array p[] of size n + 1. Dimension of matrix Ai is p[i - 1]*p[i]. You need to find minimum number of multiplications needed to multiply the chain.
Input Format:

The first line of input contains an integer, that denotes the value of n. The following line contains n+1 integers, that denote the value of elements of array p[].

Output Format:

The first and only line of output prints the minimum number of multiplication needed.

Constraints :

1 <= n <= 100
Time limit: 1 second

Sample Input 1:

3
10 15 20 25

Sample Output 1:

8000

Sample Output Explanation:

There are two ways to multiply the chain - A1*(A2*A3) or (A1*A2)*A3.
If we multiply in order- A1*(A2*A3), then number of multiplications required are 11250.
If we multiply in order- (A1*A2)*A3, then number of multiplications required are 8000.
Thus minimum number of multiplications required are 8000. 
*/

#include<vector>
#include<climits>
int f(int* arr, int start, int end, vector<vector<int>> &dp)
{
    if(end-start==1)
        return 0;
    if(dp[start][end]!=-1)
        return dp[start][end];
    int ans=INT_MAX;
    for(int i=start+1;i<end;i++)
    {
        int temp=f(arr,start,i,dp)+f(arr,i,end,dp)+arr[start]*arr[i]*arr[end];
        ans=min(ans,temp);
    }
    dp[start][end]=ans;
    return ans;
}
int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
     vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
     return f(arr,0,n,dp);
}
