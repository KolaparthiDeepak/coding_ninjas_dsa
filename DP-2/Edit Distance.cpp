/*
Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
Edit Distance

Edit Distance of two strings is minimum number of operations required to make one string equal to other. In order to do so you can perform any of the following three operations only :
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note

Strings don't contain spaces

Input Format :

The first line of input contains a string, that denotes the value of s. The following line contains a string, that denotes the value of t.

Output Format :

The first and only line of output contains the edit distance value between the given strings.

Constraints :

1<= m,n <= 10
Time Limit: 1 second

Sample Input 1 :

abc
dc

Sample Output 1 :

2
*/

/*************Brute Force***********/
int editDistance(string s1, string s2) {
	// Write your code here
    if(s1.size()==0 || s2.size()==0)
        return max(s1.size(),s2.size());
    if(s1[0]==s2[0])
        return editDistance(s1.substr(1),s2.substr(1));
    //insert operation
    int i=editDistance(s1.substr(1),s2);
    //delete operation
    int d=editDistance(s1,s2.substr(1));
    //replace operation
    int r=editDistance(s1.substr(1),s2.substr(1));
    return 1+min(i,min(d,r));
}

/********Memoization**********/
int editDistance(string s1, string s2, int **mem)
{
    if(s1.size()==0 || s2.size()==0)
        return max(s1.size(),s2.size());
    if(mem[s1.size()][s2.size()]!=-1)
        return mem[s1.size()][s2.size()];
    if(s1[0]==s2[0])
        return editDistance(s1.substr(1),s2.substr(1),mem);
    //insert operation
    int i=editDistance(s1.substr(1),s2,mem);
    //delete operation
    int d=editDistance(s1,s2.substr(1),mem);
    //replace operation
    int r=editDistance(s1.substr(1),s2.substr(1),mem);
    mem[s1.size()][s2.size()]=1+min(i,min(d,r));
    return mem[s1.size()][s2.size()];
}
int editDistance(string s1, string s2)
{
	//Write your code here
    int **mem=new int* [s1.size()+1];
    for(int i=0;i<=s1.size();i++)
    {
        mem[i]=new int[s2.size()+1];
        for(int j=0;j<=s2.size();j++){
            mem[i][j]=-1;
        }
    }
    return editDistance(s1,s2,mem);
}

/**************DP****************/
int editDistance(string s1, string s2) {
	int m=s1.size();
	int n=s2.size();
	int **dp=new int*[m+1];
	for(int i=0;i<=m;i++) 
  {
		dp[i]=new int[n+1];
	}
	// Fill 1st row
	for(int j=0;j<=n;j++) 
  {
		dp[0][j]=j;
	}
	// Fill 1st col
	for(int i=1;i<=m;i++) 
  {
		dp[i][0] = i;
	}
	for(int i=1;i<=m;i++) 
  {
		for(int j=1;j<=n;j++) 
    {
			if(s1[m-i]==s2[n-j]) 
      {
				 dp[i][j]=[i-1][j-1];
			}
			else 
      {
				int in=dp[i-1][j];
				int del=dp[i][j-1];
				int rep=dp[i-1][j-1];
				dp[i][j]=min(in,min(del,rep))+1;
			}
		}
	}
	return dp[m][n];
}
