/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
Input format :

The first and the only line of input contains an integer value, 'N'.

 Output format :

Print the minimum count of numbers required.

Constraints :

0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :

12

Sample Output 1 :

3

Explanation of Sample Output 1 :

12 can be represented as : 
A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :

9

Sample Output 2 :

1
*/


#include <bits/stdc++.h>
using namespace std;
//tabulate method(DP)
int minCountDP(int n){
    int dp[n+1];
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=__INT_MAX__;
        for(int j=0;j*j<=i;j++){
            dp[i]=min(dp[i],dp[i-(j*j)]);
        }
        dp[i]++;
    }
    return dp[n];
}
//memorisation method
int minCount(int n,int *dp){  //helper function
    if(n<=1) return n;
    if(dp[n]!=-1) return dp[n];  //check if small ans id already calculated
    int ans=__INT_MAX__;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,minCount(n-(i*i),dp));
    }
    dp[n]=ans+1;  //saving the small ans
    return dp[n]; //return the ans
}
int minCountMem(int n){ 
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return minCount(n,dp);
}
//recursive Method
int minCountRec(int n){
    if(n<=1) return n;
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++){
        ans=min(ans,minCountRec(n-(i*i)));
    }
    return ans+1;
}
