/*
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
Input Format :

The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
Each of the following N lines contain M characters. Please note that characters are not space separated.

Output Format :

Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.

Constraints :

1 <= N <= 1000
1 <= M <= 1000
Time Limit: 1 second

Sample Input 1:

2 11
CXDXNXNXNXA
XOXIXGXIXJX

Sample Output 1:

1
*/

#include<vector>
#include<string>
bool hasPath(vector<vector<char>> &board, int n, int m, vector<vector<bool>> &visited, string s, int i, int j)
{
     if(board[i][j]!=s[0]) 
        return false;
    // If Last letter of string is found then we return
    if(s.length()==1)
        return true;
    visited[i][j]=true;
    //a[i][j] is current cell check 8 directions of it
    bool dir1=false,dir2=false,dir3=false,dir4=false,dir5=false,dir6=false,dir7=false,dir8=false;
    // a[i-1][j-1]
    if(i-1>=0 && j-1>=0) 
        if(!visited[i-1][j-1])
            dir1=hasPath(board,n,m,visited,s.substr(1),i-1,j-1);
    // a[i-1][j]
    if(i-1>=0) 
        if(!visited[i-1][j])
            dir2=hasPath(board,n,m,visited,s.substr(1),i-1,j);
    // a[i-1][j+1]
    if(i-1>=0 && j+1<m) 
        if(!visited[i-1][j+1])
            dir3=hasPath(board,n,m,visited,s.substr(1),i-1,j+1);
    // a[i][j+1]
    if(j+1<m)
        if(!visited[i][j+1])
            dir4=hasPath(board,n,m,visited,s.substr(1),i,j+1);
    // a[i+1][j+1]
    if(i+1<n && j+1<m)
        if(!visited[i+1][j+1])
            dir5=hasPath(board,n,m,visited,s.substr(1),i+1,j+1);
    // a[i+1][j]
    if(i+1<n) 
        if(!visited[i+1][j])
            dir6=hasPath(board,n,m,visited,s.substr(1),i+1,j);
    // a[i+1][j-1]
    if(i+1<n && j-1>0) 
        if(!visited[i+1][j-1])
            dir7=hasPath(board,n,m,visited,s.substr(1),i+1,j-1);
    // a[i][j-1]
    if(j-1>=0) 
        if(!visited[i][j-1])
            dir8=hasPath(board,n,m,visited,s.substr(1),i,j-1);
    
    if(dir1 || dir2 || dir3 || dir4 || dir5 || dir6 || dir7 || dir8)
        return true;
    else 
    {
        visited[i][j]=false;
        return false;
    }
}
    
bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    string s="CODINGNINJA";
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++) 
        {
            if(board[i][j]=='C')
            {
                bool path=hasPath(board,n,m,visited,s,i,j);
                if(path) 
                {
                    return true;
                }
            }
        }
    }
    return false;
}
