/*
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.

Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :

The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.

Output Format :

Print true if there is a cycle in the board, else print false.

Constraints :

2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second

Sample Input 1:

3 4
AAAA
ABCA
AAAA

Sample Output 1:

true
*/

const pair<int,int> dir[4] = {{0,-1},{1,0},{0,1},{-1,0}};
bool validMove(int x,int y,int n,int m){return x>=0 && y>=0 && x<n && y<m;}
bool cycle = 0;
void dfs(vector<vector<char>> &board,vector<vector<bool>> &vis ,int n, int m,int x,int y,char needColor,int fromX = -1,int fromY=-1){
    if(board[x][y]!=needColor) return;
    if(!validMove(x,y,n,m)) return;
    if(vis[x][y]){
        cycle = 1;
        return;
    }
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        int newX = x+dir[i].first;
        int newY = y+dir[i].second;
        if(newX == fromX && newY == fromY) continue;
        if(validMove(newX,newY,n,m)) dfs(board,vis,n,m,newX,newY,needColor,x,y);
    }
}
bool hasCycle(vector<vector<char>> &board, int n, int m) {
	vector<vector<bool>> vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(!vis[i][j]) dfs(board,vis,n,m,i,j,board[i][j]);
    return cycle;
}

