/*
An island is a small piece of land surrounded by water . A group of islands is said to be connected if we can reach from any given island to any other island in the same group . Given V islands (numbered from 1 to V) and E connections or edges between islands. Can you count the number of connected groups of islands.
Input Format :

The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b. 

Output Format :

Print the count the number of connected groups of islands

Constraints :

0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second

Sample Input 1:

5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3

Sample Output 1:

1 
*/

#include <iostream>
#include <bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;
vector<int> BFS(int **edges,int n,int sv,bool *visited)
{
    queue<int> pendingVertices;
    pendingVertices.push(sv);
    visited[sv]=true;
    vector<int> ans;
    while(!pendingVertices.empty()) 
    {   
        int currentVertex=pendingVertices.front();
        pendingVertices.pop();
        ans.push_back(currentVertex);
        for (int i=0;i<n;i++) 
        {
            if(i==currentVertex)
                continue;
            if (edges[currentVertex][i]==1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }
    return ans;
}
void BFS(int **edges,int n)
{
    bool* visited = new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            vector<int> ans=BFS(edges,n,i,visited);
            count=count+1;
         }
    }
    cout<<count<<endl;
    delete [] visited;
}
int main() {
    // Write your code here
    int n;
    int e;
    cin >> n >> e;
    int** edges = new int*[n];
    for(int i=0;i<n;i++)
    {
        edges[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            edges[i][j]=0;
        }
    }
    for(int i=0;i<e;i++)
    {
        int f,s;
        cin >> f >> s;
        edges[f][s]=1;
        edges[s][f]=1;
    }
    BFS(edges,n);
}

