/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.

Note : Order of vertices in output doesn't matter.
Constraints :

2 <= V, E <= 10^5
Time Limit: 1 sec

Sample Input 1 :

4 4
0 1 3
0 3 5
1 2 1
2 3 8

Sample Output 1 :

0 0
1 3
2 4
3 5
*/

#include <iostream>
#include<climits>
#include<algorithm>
using namespace std;
int findMinVertex(int *distances,bool *visited,int n)
{
    int mindistancevertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!visited[i] && (mindistancevertex==-1 || distances[i]<distances[mindistancevertex]))
            mindistancevertex=i;
    }
    return mindistancevertex;
}
void DijkstrasAlgorithm(int **edges,int n)
{
    bool *visited=new bool[n];
    int *distances=new int[n];
    for(int i=0;i<n;i++){
        visited[i]=0;
        distances[i]=INT_MAX;
    }
    distances[0]=0;
    for(int i=0;i<n-1;i++)
    {
        int mindistancevertex=findMinVertex(distances,visited,n);
        visited[mindistancevertex]=true;
        for(int j=0;j<n;j++)
        {
            if(edges[mindistancevertex][j]!=0 && !visited[j])
            {
                int dist=distances[mindistancevertex]+edges[mindistancevertex][j];
                if(dist<distances[j])
                    distances[j]=dist;
            }
        }
    }  
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distances[i]<<endl;
    }
    delete [] visited;
    delete [] distances;
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    int **edges=new int*[n];
    for(int i=0;i<n;i++){
        edges[i]=new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }
    for(int i=0;i<n;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    DijkstrasAlgorithm(edges,n);
    for(int i=0;i<n;i++)
    {
        delete [] edges[i];
    }
    delete [] edges;
}

