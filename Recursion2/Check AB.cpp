/*Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:

a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
Input format :

String S

Output format :

'true' or 'false'

Constraints :

1 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :

abb

Sample Output 1 :

true

Sample Input 2 :

abababa

Sample Output 2 :

false
*/

#include<string.h>
bool checkAB(char input[]) {
	// Write your code here
    if(strlen(input)==0)
        return true;
    if(input[0]=='a')
    {
        if(strlen(input+1)>1&&input[1]=='b'&&input[2]=='b')
        {
              return checkAB(input+3);
        }
        else
        {
            return checkAB(input+1);
        }
    }
    return false;
}
