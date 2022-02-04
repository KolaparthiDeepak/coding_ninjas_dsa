/*Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :

Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15
Sample Input:

3
15 20 12

Sample Output:

[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 
*/

void help(int input[],int startindex,int size,int output[],int currsubsetsize);
void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[100000];
    help(input,0,size,output,0);
}
void help(int input[],int startindex,int size,int output[],int currsubsetsize)
{
    if(startindex==size)
    {
        for(int k=0;k<currsubsetsize;k++)
        {
            cout<<output[k]<<" ";
        }
        cout<<endl;
        return;
    }
    help(input,startindex+1,size,output,currsubsetsize);//startindex not included
    output[currsubsetsize]=input[startindex];
    help(input,startindex+1,size,output,currsubsetsize+1);//startindex also included
}

