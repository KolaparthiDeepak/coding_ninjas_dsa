/*You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.
Note:
Given array/list can contain duplicate elements. 
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the first array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Third line contains an integer 'num'.
Output format :
For each test case, print the total number of pairs present in the array/list.

Output for every test case will be printed in a separate line.
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2


 Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/

void mergesort(int arr[],int start,int end);
void merge(int arr[],int start,int mid,int end);
int find(int arr[],int n,int x);
int pairSum(int *arr, int n, int num)
{
	//Write your code here
    mergesort(arr,0,n-1);
    int i=0;
    int j=n-1;
    int res=0;
    while(i<j)
    {
        if(arr[i]+arr[j]==num)
        {
            
            if(arr[i]==arr[j])
            {
                int count=j-i+1;
                i=j;
                res=res+(count*(count-1))/2;
            }
            else
            {
                int a1=find(arr,n,arr[i]);
                int a2=find(arr,n,arr[j]);
                i=i+a1;
                j=j-a2;
                res=res+(a1*a2);
            }
        }
        else if(arr[i]+arr[j]>num)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return res;
}
void mergesort(int arr[],int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int mid=(start+end)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
}
void merge(int arr[],int start,int mid,int end)
{
    int i,j,k,a[end-start+1];
    i=start;
    j=mid+1;
    k=0;
    while(i<=mid&&j<=end)
    {
        if(arr[i]<arr[j])
        {
            a[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            a[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k]=arr[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        a[k]=arr[j];
        j++;
        k++;
    }
    for(int x=start;x<=end;x++)
    {
        arr[x]=a[x-start];
    }
}
int find(int arr[],int n,int x)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            c++;
        }
    }
    return c;
}

