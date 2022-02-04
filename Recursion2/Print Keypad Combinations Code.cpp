/*Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :

Integer n

Output Format :

All possible strings in different lines

Constraints :
1 <= n <= 10^6
Sample Input:

23

Sample Output:

ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include <iostream>
#include <string>
using namespace std;
string alpha(int num);
void help(int num,string output);
void printKeypad(int num){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
    */
    string output="";
    help(num,output);
}
string alpha(int num) //for convet numbet to string
{
    string input="";
    switch(num)
    {
        case 2: input = "abc";
            break;
        case 3: input = "def";
            break;
        case 4: input = "ghi";
            break;
        case 5: input = "jkl";
            break;
        case 6: input = "mno";
            break;
        case 7: input = "pqrs";
            break;
        case 8: input = "tuv";
            break;
        case 9: input = "wxyz";
            break;
    }
    return input;
}
void help(int num,string output)
{
    if(num==0)
    {
        cout<<output<<endl;
        return;
    }
    string input=alpha(num%10);
    for(int i=0;i<input.size();i++)
    {
        help(num/10,input[i]+output);
    }
    
}

