/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so, return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :

The first and only line of input contains an integer, that denotes the value of h. Here, h is the height of the tree.

Output Format :

The first and only line of output contains the count of balanced binary trees modulus 10^9 + 7.

Constraints :

1 <= h <= 24
Time Limit: 1 sec

Sample Input 1:

3

Sample Output 1:

15

Sample Input 2:

4

Sample Output 2:

315
*/

#include <bits/stdc++.h>
using namespace std;
int mod=1e9+7;
//tabulate method(dp)
int balancedBTsDP(int n){
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++){
         dp[i]=((int)(((long)(dp[i-1])*dp[i-1])%mod)+(int)((2*(long)(dp[i-1])*dp[i-2])%mod))%mod);
    }
    return dp[n];
}
//memorisation 
int balancedBTsMem(int n,int *dp){
    if(n<=1) return 1;
    if(dp[n]!=-1) return dp[n];
    int x=balancedBTsMem(n-1,dp);
    int y=balancedBTsMem(n-2,dp);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans=(temp1+temp2)%mod;
    dp[n]=ans;
    return ans;
}
int balancedBTsMem(int n){
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    return balancedBTsMem(n,dp);
}
//recursion
int balancedBTs(int n) {
    if(n<=1) return 1;
    int x=balancedBTs(n-1);
    int y=balancedBTs(n-2);
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)((2*(long)(x)*y)%mod);
    int ans=(temp1+temp2)%mod;
    return ans;
}
