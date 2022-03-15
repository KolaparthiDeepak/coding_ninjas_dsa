/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?
Input Format :

The first line of the input contains an integer value N, which denotes the total number of items.

The second line of input contains the N number of weights separated by a single space.

The third line of input contains the N number of values separated by a single space.

The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.

Output Format :

Print the maximum value of V that the thief can steal.

Constraints :

1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec

Sample Input 1 :

4
1 2 4 5
5 4 8 6
5

Sample Output 1 :

13

Sample Input 2 :

5
12 7 11 8 9
24 13 23 15 16
26

Sample Output 2 :

51
*/

/*************Brute Force******/
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	//write your code here
     if (n==0 || maxWeight==0)
        return 0;
    if (weights[0]>maxWeight) 
        return knapsack(weights+1,values+1,n-1,maxWeight);
    int x=knapsack(weights+1,values+1,n-1,maxWeight);
    int y=knapsack(weights+1,values+1,n-1,maxWeight-weights[0])+values[0];
    return max(x,y);
}

/**********Memoization************/
int knapsack(int* weights, int* values, int n, int maxWeight, int **mem)
{
    if (n==0 || maxWeight==0)
        return 0;
    if(mem[n][maxWeight]!=-1)
        return mem[n][maxWeight];
    if (weights[0]>maxWeight) 
        mem[n][maxWeight]=knapsack(weights+1,values+1,n-1,maxWeight,mem);
    else
    {
        int x=knapsack(weights+1,values+1,n-1,maxWeight,mem);
        int y=knapsack(weights+1,values+1,n-1,maxWeight-weights[0],mem)+values[0];
        mem[n][maxWeight]=max(x,y);
    }
    return mem[n][maxWeight];
}
int knapsack(int* weights, int* values, int n, int maxWeight) {
	// Write your code here
    int **mem=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        mem[i]=new int[maxWeight+1];
        for(int j=0;j<=maxWeight;j++)
        {
            mem[i][j]=-1;
        }
    }
    return knapsack(weights,values,n,maxWeight,mem);
}

/***************DP************/
int knapsack(int* weights, int* values, int n, int maxWeight) {
	// Write your code here
    int **dp=new int*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new int[maxWeight+1];
    }
    //fill 1st col
    for(int i=0;i<=n;i++) 
        dp[i][0]=0;
    //fill 1st row
    for(int j=0;j<=maxWeight;j++) 
        dp[0][j]=0;  
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            if(weights[i-1]>j) 
                dp[i][j]=dp[i-1][j];
            else 
                dp[i][j]=max(values[i-1]+dp[i-1][j-weights[i-1]],dp[i-1][j]);
        }
    }
    return dp[n][maxWeight];
}
