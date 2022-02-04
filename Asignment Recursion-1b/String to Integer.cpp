/*Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :

Numeric string S (string, Eg. "1234")

Output format :

Corresponding integer N (int, Eg. 1234)

Constraints :

0 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :

00001231

Sample Output 1 :

1231

Sample Input 2 :

12567

Sample Output 2 :

12567
*/

#include<string.h>
#include<math.h>
int help(char input[],int x);
int stringToNumber(char input[]) 
{
    // Write your code here
    return help(input,strlen(input)-1);
}
int help(char input[],int x)
{
    if(x==0)
        return input[x]-'0';
	return help(input,x-1)*10+input[x]-'0';
}
