/*Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :

A numeric string

Constraints :
1 <= Length of String S <= 10
Sample Input:

1123

Sample Output:

aabc
kbc
alc
aaw
kw
*/

#include <string.h>
using namespace std;
int atoi(char a);
char itoa(int i);
int getCodes(string input, string output[10000]) { /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }
    if(input.size()==1)
    {
        output[0]=itoa(atoi(input[0]));
        return 1;
    }
    string res1[10000],res2[10000];
    int size1=getCodes(input.substr(1),res1);
    int size2=0;
    if(input.size()>1)
    {
        if(atoi(input[0])*10+atoi(input[1])>=10&&atoi(input[0])*10+atoi(input[1])<27)
        {
            size2=getCodes(input.substr(2),res2);
        }
    }
    int k=0;
    for(int i=0;i<size1;i++)
    {
        output[k]=itoa(atoi(input[0]))+res1[i];
        k++;
    }
    for(int i=0;i<size2;i++)
    {
        output[k]=itoa(atoi(input[0])*10+atoi(input[1]))+res2[i];
        k++;
    }
    return k;
}
int atoi(char a)
{
    int i=a-'0';
    return i;
}
char itoa(int i)
{
    char c='a'+i-1;
    return c;
}
