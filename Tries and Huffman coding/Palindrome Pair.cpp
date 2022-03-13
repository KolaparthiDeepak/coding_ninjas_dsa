/*
Given 'n' number of words, you need to find if there exist any two words which can be joined to make a palindrome or any word, which itself is a palindrome.
The function should return either true or false. You don't have to print anything.
Input Format :

The first line of the test case contains an integer value denoting 'n'.

The following contains 'n' number of words each separated by a single space.

Output Format :

The first and only line of output contains true if the conditions described in the task are met and false otherwise.

Constraints:

0 <= n <= 10^5
Time Limit: 1 sec

Sample Input 1 :

4
abc def ghi cba

Sample Output 1 :

true

Explanation of Sample Input 1:

"abc" and "cba" forms a palindrome

Sample Input 2 :

2
abc def

Sample Output 2 :

false

Explanation of Sample Input 2:

Neither their exists a pair which forms a palindrome, nor any of the words is a palindrome in itself. Hence, the output is 'false.'
*/

#include<vector>
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool add(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
            this->count++;
        }
    }

    /*..................... Palindrome Pair................... */
    
    string reverse(string word)
    {
        string rev="";
        while(word.length()!=0)
        {
            rev=word[0]+rev;
            word=word.substr(1);
        }
        return rev;
    }
    
    bool search(TrieNode *root,string word)
    {
        if(word.size()==0 )
            return true;
        int index=word[0]-'a';
        TrieNode *child=root->children[index];
        if(child!=NULL)
            return search(child,word.substr(1));
        return false;
    }
    
    bool search(string word) {
        // Write your code here
        return search(root,word);
    }

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        vector<string> revwords;
         for(int i=0;i<words.size();i++)
         {
             string s=words[i];
             add(words[i]);
             string rev=reverse(s);
             revwords.push_back(rev);
         }
         for(int i=0;i<revwords.size();i++)
         {
             if(search(revwords[i]))
               return true;
         }
         return false;
    }
    
};


/*    OR


    //..................... Palindrome Pair................... //
    
   
    bool isPalindrome(string& s) {   
          int l=0, r=s.size()-1;
          while(l<r){if(s[l++]!=s[r--]) return false;}
          return true; 
    }


     vector<vector<int>> isPalindromePairhelp(vector<string>& words) {
        vector<vector<int>> ans;
        int n = words.size();
        if(n<2) return ans;
        unordered_map<string, int> m;
        for(int i=0;i<n;++i){
            
            auto s= words[i];
            reverse(s.begin(),s.end());
            m[s]=i;
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<=words[i].size(); ++j){
                string st1 = words[i].substr(0,j); // prefix
                string st2 = words[i].substr(j);    //sufix           
                 
                 if(m.count(st1) && isPalindrome(st2) && m[st1] != i) {
                     ans.push_back({i, m[st1]});    
                 }

                 if(!st1.empty() && m.count(st2) && isPalindrome(st1) && m[st2] != i) {
                     ans.push_back({m[st2], i});
                 }
            }            
        }
        return ans;
    }

    bool isPalindromePair(vector<string>& words){
        vector<vector<int>> ans=isPalindromePairhelp(words);
        if(ans.size()!=0)
            return true;
        if(words.size()==1&&isPalindrome(words[0])==true)
            return true;
        return false;
    }
    
    
};
*/
