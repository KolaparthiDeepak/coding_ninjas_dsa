/*
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?
 Input format :

The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.

Output format :

Prints the name of the winner, either 'Whis' or 'Beerus' (Without the quotes).

Constraints :

1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec

Sample Input 1 :

4 2 3

Sample Output 1 :

Whis

Sample Input 2 :

10 2 4

Sample Output 2 :

Beerus
*/

string findWinner(int n, int x, int y)
{
	// Write your code here
    bool *dp=new bool[n+1];
    dp[0]=false; 
    dp[1]=true;
    for (int i=2;i<=n;i++) 
    { 
        // If A losses any of i-1 or i-x or i-y game then he will definitely win game i 
        if(i-1>=0 && dp[i-1]==false) 
            dp[i]=true; 
        else if(i-x>=0 && dp[i-x]==false) 
            dp[i]=true; 
        else if(i- y>=0 && dp[i-y]==false) 
            dp[i]=true; 
        // Else A loses game. 
        else
            dp[i]=false; 
    } 
    // If dp[n] is true then A will 
    // game otherwise  he losses 
    if (dp[n]==true)
        return "Beerus";
    return "Whis";

}
