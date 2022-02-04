/*Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
Do this recursively.
Input Format :

Line 1 : Input String S
Line 2 : Character c1 and c2 (separated by space)

Output Format :

Updated string

Constraints :
1 <= Length of String S <= 10^6
Sample Input :

abacd
a x

Sample Output :

xbxcd
*/

#include<string.h>
void replaceCharacter(char input[], char c1, char c2) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * No need to print or return the output. 
     * Change in the given input string itself.
     * Taking input and printing output is handled automatically.
     */
    if(strlen(input)==0)
        return;
    if(input[0]==c1)
        input[0]=c2;
    replaceCharacter(input+1,c1,c2);
}
