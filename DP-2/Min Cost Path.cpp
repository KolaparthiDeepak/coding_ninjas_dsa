/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i, j), you can move in three directions:

1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.
 Input format :

The first line of the test case contains two integer values, 'M' and 'N', separated by a single space. They represent the 'rows' and 'columns' respectively, for the two-dimensional array/list.

The second line onwards, the next 'M' lines or rows represent the ith row values.

Each of the ith row constitutes 'N' column values separated by a single space.

Output format :

Print the minimum cost to reach the destination.

Constraints :

1 <= M <= 10 ^ 2
1 <= N <=  10 ^ 2

Time Limit: 1 sec

Sample Input 1 :

3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :

13

Sample Input 2 :

3 4
10 6 9 0
-23 8 9 90
-200 0 89 200

Sample Output 2 :

76

Sample Input 3 :

5 6
9 6 0 12 90 1
2 7 8 5 78 6
1 6 0 5 10 -4 
9 6 2 -10 7 4
10 -2 0 5 5 7

Sample Output 3 :

18
*/

/****************Brute Force*************/
int minCostPath(int **a, int i, int j, int m, int n)
{
    if(i==m-1 && j==n-1) 
        return a[i][j];
    if(i>=m || j>=n) 
        return INT_MAX;
    int x=minCostPath(a,i+1,j,m,n);
    int y=minCostPath(a,i,j+1,m,n);
    int z=minCostPath(a,i+1,j+1,m,n);
    return a[i][j]+min(x,min(y,z));
}
int minCostPath(int **a, int m, int n)
{
	//Write your code here
    return minCostPath(a,0,0,m,n);
}

/***************Memoization***************/
int minCostPath_Mem(int **input, int m, int n, int i, int j, int **output) {
    if(i == m- 1 && j == n- 1) {
        return input[i][j];
    }
    
    if(i >= m || j >= n) {
        return INT_MAX;
    }
    
    // Check if ans already exists
    if(output[i][j] != -1) {
        return output[i][j];
    }
    
    // Recursive calls
    int x = minCostPath_Mem(input, m, n, i, j+1, output);
    int y = minCostPath_Mem(input, m, n, i+1, j+1, output);
    int z = minCostPath_Mem(input, m, n, i+1, j, output);
    
    // Small Calculation
    int a = min(x, min(y, z)) + input[i][j];
    
    // Save the answer for future use
    output[i][j] = a;
    
    return a;
}

int minCostPath(int **input, int m, int n, int i, int j) {
    int **output = new int*[m];
    for(int i = 0; i < m; i++) {
        output[i] = new int[n];
        for(int j = 0; j < n; j++) {
            output[i][j] = -1;
        }
    }
    
    return minCostPath_Mem(input, m, n, i, j, output);
}

int minCostPath(int **input, int m, int n) {
    return minCostPath(input, m, n, 0, 0);
}

/*************DP**************/
int minCostPath_DP(int **input, int m, int n) {
	int **ans = new int*[m];
	for(int i = 0; i < m; i++) {
		ans[i] = new int[n];
	}

	ans[m-1][n-1] = input[m-1][n-1];

	// Last row
	for(int j = n - 2; j >= 0; j--) {
		ans[m-1][j] = input[m-1][j] + ans[m-1][j+1];
	}

	// Last col
	for(int i = m-2; i >= 0; i--) {
		ans[i][n-1] = input[i][n-1] + ans[i+1][n-1];
	}

	for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			ans[i][j] = input[i][j] + min(ans[i][j+1], min(ans[i+1][j+1], ans[i+1][j]));
		}
	}
	return ans[0][0];
}

int minCostPath(int **input, int m, int n) {
	return minCostPath_DP(input, m, n);
}
