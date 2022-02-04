/*Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :

String S

Output Format :

All permutations (in different lines)

Sample Input :

abc

Sample Output :

abc
acb
bac
bca
cab
cba
*/

#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    if(input.length()==0)
    {
        output[0]="";
        return 1;
    }
    string smallout[10000];
    int k=0;
    int smallsize=returnPermutations(input.substr(1),smallout);
    for(int i=0;i<smallsize;i++)
    {
        for(int j=0;j<=smallout[i].length();j++)
        {
            output[k]=smallout[i].substr(0,j)+input[0]+smallout[i].substr(j); 
            k++;
        }
    }
    return k;
}
