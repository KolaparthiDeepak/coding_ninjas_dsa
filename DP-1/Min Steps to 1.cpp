/*
Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:

1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  

Write brute-force recursive solution for this.
Input format :

The first and the only line of input contains an integer value, 'n'.

Output format :

Print the minimum number of steps.

Constraints :

1 <= n <= 200

Time Limit: 1 sec

Sample Input 1 :

4

Sample Output 1 :

2 

Explanation of Sample Output 1 :

For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1 

Sample Input 2 :

7

Sample Output 2 :

3

Explanation of Sample Output 2 :

For n = 7
Step 1 :  n = 7 - 1 = 6
Step 2 : n = 6  / 3 = 2 
Step 3 : n = 2 / 2 = 1  
*/

#include<climits>
int countMinStepsToOne(int n)          //brute force
{
	//Write your code here
    if(n==1)
        return 0;
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    a=countMinStepsToOne(n-1);
    if(n%2==0)
        b=countMinStepsToOne(n/2);
    if(n%3==0)
        c=countMinStepsToOne(n/3);
    return min(a,min(b,c))+1;
}

int countMinStepsToOneHelp(int n,int *ans)              // Memoization approach
{
    if(n==1)
    {
        ans[n]=0;
        return ans[n];
    }
    if(ans[n]!=-1)
        return 1+ans[n];
    int a=INT_MAX,b=INT_MAX,c=INT_MAX;
    a=countMinStepsToOneHelp(n-1,ans);
    if(n%2==0)
        b=countMinStepsToOneHelp(n/2,ans);
    if(n%3==0)
        c=countMinStepsToOneHelp(n/3,ans);
    ans[n]=min(a,min(b,c));
    return 1+ans[n];
}
int countMinStepsToOne(int n)
{
	//Write your code here
    if(n==1)
        return 0;
    int *ans=new int[n+1];
    for(int i=0;i<n+1;i++)
    {
        ans[i]-=1;
    }
    return countMinStepsToOneHelp(n,ans);
}

int countStepsToOne(int n)          //Dynamic Programming approach
{
	//Write your code here
    int *a=new int[n+1];
    a[1]=0;
    a[2]=1;
    a[3]=1;
    int b,c;
    for(int i=4;i<n+1;i++)
    {
        b=n;
        c=n;
        if(i%2==0) 
            b=a[i/2];
        if(i%3==0) 
            c=a[i/3];
        a[i]=1+min(a[i-1],min(b,c));
    }
    return a[n];
}

