/*Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :

String S

Output format :

Modified string

Constraints :

0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :

hello

Sample Output 1:

hel*lo

Sample Input 2 :

aaaa

Sample Output 2 :

a*a*a*a
*/

// Change in the given string itself. So no need to return or print the changed string.
#include<string.h>
void help(char input[],int i);
void pairStar(char input[]) {
    // Write your code here
    help(input,0);
}
void help(char input[],int i)
{
    if(input[i]=='\0'||input[i+1]=='\0')
        return;
    help(input,i+1);
    if(input[i]==input[i+1])
    {
        for(int j=strlen(input);j>=i;j--) 
        {
            input[j+1]=input[j];
        }
        input[i+1]='*';
    }
}

