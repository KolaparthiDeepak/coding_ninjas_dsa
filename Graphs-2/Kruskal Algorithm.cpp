/*
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.

Note : Order of different edges doesn't matter.
Input Format :

Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

Output Format :

Print the MST, as described in the task.

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

1 2 1
0 1 3
0 3 5
*/

#include <iostream>
#include<algorithm>
using namespace std;
class Edge{
  public:
    int source;
    int dest;
    int weight;
};
bool sortalgo(Edge x,Edge y)
{
	return x.weight<y.weight;
}
int find_parent(int v1,int *parent)
{
	int parentofv1=v1;
	while(parent[parentofv1]!=parentofv1)
    {
		parentofv1=parent[parentofv1];
	}
	return parentofv1;
}
int main() {
    // Write your code here
    int n,e;
    cin>>n>>e;
    Edge input[e];
    Edge output[n-1];
	for(int i=0;i<e;i++)
    {
		int source,dest,weight;
		cin>>source>>dest>>weight;
		input[i].source=source;
		input[i].dest=dest;
		input[i].weight=weight;
	}
    int parent[n];
	for(int i=0;i<n;i++)
    {
		parent[i]=i;
	}
    sort(input,input+e,sortalgo);
    int count=0,i=0,v1,v2;
	while(count<n-1)
    {
		v1=input[i].source;
		v2=input[i].dest;
		int parentofv1=find_parent(v1,parent);
		int parentofv2=find_parent(v2,parent);
		if(parentofv1!=parentofv2)
        {
			parent[parentofv2]=parentofv1;
			output[count].source=input[i].source;
			output[count].dest=input[i].dest;
			output[count].weight=input[i].weight;
			count++;
		}
		i++;
	}
    for(int i=0;i<n-1;i++)
    {
	    int minVertex=min(output[i].source,output[i].dest);
		  int maxVertex=max(output[i].source,output[i].dest);
		  cout<<minVertex<<" "<<maxVertex<<" "<<output[i].weight<<endl;
	}
	return 0;
}

