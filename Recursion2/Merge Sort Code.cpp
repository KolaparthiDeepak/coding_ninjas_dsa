/*Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :

Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :

Array elements in increasing order (separated by space)

Constraints :

1 <= n <= 10^3

Sample Input 1 :

6 
2 6 8 5 4 3

Sample Output 1 :

2 3 4 5 6 8

Sample Input 2 :

5
2 1 5 2 3

Sample Output 2 :

1 2 2 3 5 
*/

void merge(int input[],int start,int mid,int end)
{
    int i,j,k,a[end-start+1];
    i=start;
    j=mid+1;
    k=0;
    while(i<=mid&&j<=end)
    {
        if(input[i]<input[j])
        {
            a[k]=input[i];
            i++;
            k++;
        }
        else
        {
            a[k]=input[j];
            j++;
            k++;
        }
    }
    while(i<=mid)
    {
        a[k]=input[i];
        i++;
        k++;
    }
    while(j<=end)
    {
        a[k]=input[j];
        j++;
        k++;
    }
    for(int x=start;x<=end;x++)
    {
        input[x]=a[x-start];
    }
}

void mergeSort(int input[],int start,int end)
{
    if(start>=end)
        return;
    int mid=(start+end)/2;
    mergeSort(input,start,mid);
    mergeSort(input,mid+1,end);
    merge(input,start,mid,end);
}

void mergeSort(int input[], int size){
	// Write your code here
    mergeSort(input,0,size-1);
}

