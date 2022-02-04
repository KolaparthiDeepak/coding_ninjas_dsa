/*Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
Input format :

Line 1 : Size of input array
Line 2 : Array elements separated by space
Line 3 : K 

Sample Input:

9 
5 12 3 17 1 18 15 3 17 
6

Sample Output:

3 3
5 1
*/

void help(int input[],int start,int k,int output[]);
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int *output=new input[0];
    help(input,0,k,output);
}
void help(int input[],int start,int k,int output[])
{
    if(start==(sizeof(input)/sizeof(*input)))
    {
        if(k==0)
        {
            for(int i=0;i<(sizeof(output)/sizeof(*output));i++)
            {
                cout<<output[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else
            return;
    }
    help(input,start+1,k,output);
    int temp[(sizeof(output)/sizeof(*output))+1];
    int i=0;
    for(;i<sizeof(output)/sizeof(*output);i++)
    {
        temp[i]=output[i];
    }
    temp[i]=input[start];
    help(input,start+1,k-input[start],temp);
}
