/*Given an input string (STR), print all possible permutations of the input string.
Note:

The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Input Format:

The only input line contains a string (STR) of alphabets in lower case

Output Format:

Print each permutations in a new line

Note:

You do not need to print anything, it has already been taken care of. Just implement the function.  

Constraint:

1<=length of STR<=8
Time Limit: 1sec

Sample Input 1:

cba

Sample Output 1:

abc
acb
bac
bca
cab
cba
*/

#include <iostream>
#include <string>
using namespace std;
void help(string input,int start,int end);
void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    help(input,0,input.length()-1);
}
void help(string input,int start,int end)
{
    if(start==end)
    {
        cout<<input<<endl;
        return;
    }
    for(int i=start;i<=end;i++)
    {
        int temp1=input[start];
        input[start]=input[i];
        input[i]=temp1;
        help(input,start+1,end);
        int temp2=input[start];
        input[start]=input[i];
        input[i]=temp2;
    }
}

