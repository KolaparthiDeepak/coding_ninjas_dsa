/*
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Since the answer can be pretty large print the answer % mod(10^9 +7)
Input Format:

First line will contain T (number of test case).
Each test case is consists of a single line containing an integer N.

Output Format:

For each test case print the answer in new line

Constraints :

1 <= T < = 10
1 <= N <= 10^5

Sample input 1

2
2
3

Sample output 1

2
4

Explanation of sample input 1:

Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)

Sample input 2:

2
5
10

Sample output 2:

13
274
*/

#include <bits/stdc++.h>
using namespace std;
//tabulation method
long staircaseDP(long n){
    long dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

//memorisation method
long staircaseMem(long n,long *dp){
    if(n<=1) return 1;
    else if(n==2) return 2;
    if(dp[n]!=-1) return dp[n]; //if small ans already exist
    long ans1=staircaseMem(n-1,dp);
    long ans2=staircaseMem(n-2,dp);
    long ans3=staircaseMem(n-3,dp);
    dp[n]=ans1+ans2+ans3;  //save the small ans
    return dp[n];  //return small ans
}
long staircaseMem(long n){
    long dp[n+1];
    memset(dp,-1,sizeof(dp));
    return staircaseMem(n,dp);
}

//recursion method
long staircaseRec(long n){
    if(n<=1) return 1;
    else if(n==2) return 2;
    long ans1=staircaseRec(n-1);
    long ans2=staircaseRec(n-2);
    long ans3=staircaseRec(n-3);
    return ans1+ans2+ans3;
}

int main(){
    long n;
    cin>>n;
    cout<<staircaseRec(n)<<"\n";
    cout<<staircaseMem(n)<<"\n";
    cout<<staircaseDP(n);
}
