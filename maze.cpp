#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <conio.h>
#include <queue>
using namespace std;
int score=1000;
char a='w';
char inp;
int steps=0;
int dist=0;
/*bool isSafe(vector<vector<int>> &mat, vector<vector<bool>> &visited, int x, int y){
    return (x >= 0 && x < mat.size() && y >= 0 && y < mat[0].size()) &&
            mat[x][y] == 1 && !visited[x][y];
}
void findShortestPath(vector<vector<int>> &mat, vector<vector<bool>> &visited,
    int i, int j, int x, int y, int &min_dist, int dist){
    if (i == x && j == y){
        min_dist = min(dist, min_dist);
        return;
    }
    visited[i][j] = true;
    if (isSafe(mat, visited, i + 1, j)) {
        findShortestPath(mat, visited, i + 1, j, x, y, min_dist, dist + 1);
    }
    if (isSafe(mat, visited, i, j + 1)) {
        findShortestPath(mat, visited, i, j + 1, x, y, min_dist, dist + 1);
    }
    if (isSafe(mat, visited, i - 1, j)) {
        findShortestPath(mat, visited, i - 1, j, x, y, min_dist, dist + 1);
    }
    if (isSafe(mat, visited, i, j - 1)) {
        findShortestPath(mat, visited, i, j - 1, x, y, min_dist, dist + 1);
    }
    visited[i][j] = false;
}
  
// Wrapper over findShortestPath() function
int findShortestPathLength(vector<vector<int>> &mat, pair<int, int> &src,
                    pair<int, int> &dest){
    if (mat.size() == 0 || mat[src.first][src.second] == 0 ||
            mat[dest.first][dest.second] == 0)
        return -1;
    int row = mat.size();
    int col = mat[0].size();
    vector<vector<bool>> visited;
    visited.resize(row, vector<bool>(col));
    int dist = INT_MAX;
    findShortestPath(mat, visited, src.first, src.second, dest.first, dest.second,
            dist, 0);
    if (dist != INT_MAX)
        return dist;
    return -1;
}*/
int ROW;
int COL;

class Point
{
    public:
    int x;
    int y;
    Point(){
        int x=0;
        int y=0;
    }
    Point(int a,int b){
        x=a;
        y=b;
    }
};
 
// A Data Structure for queue used in BFS
struct queueNode
{
    Point pt;  // The coordinates of a cell
    int dist;  // cell's distance of from the source
};
 
// check whether given cell (row, col) is a valid
// cell or not.
bool isValid(int row, int col)
{
    // return true if row number and column number
    // is in range
    return (row >= 0) && (row < ROW) &&
           (col >= 0) && (col < COL);
}
Point dest;
// These arrays are used to get row and column
// numbers of 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};
 
// function to find the shortest path between
// a given source cell to a destination cell.
int BFS(vector<vector<int>> mat, Point src, Point dest)
{
    // check source and destination cell
    // of the matrix have value 1
    if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
        return -1;
 
    bool visited[ROW][COL];
    memset(visited, false, sizeof visited);
     
    // Mark the source cell as visited
    visited[src.x][src.y] = true;
 
    // Create a queue for BFS
    queue<queueNode> q;
     
    // Distance of source cell is 0
    queueNode s = {src, 0};
    q.push(s);  // Enqueue source cell
 
    // Do a BFS starting from source cell
    while (!q.empty())
    {
        queueNode curr = q.front();
        Point pt = curr.pt;
 
        // If we have reached the destination cell,
        // we are done
        if (pt.x == dest.x && pt.y == dest.y)
            return curr.dist;
 
        // Otherwise dequeue the front
        // cell in the queue
        // and enqueue its adjacent cells
        q.pop();
 
        for (int i = 0; i < 4; i++)
        {
            int row = pt.x + rowNum[i];
            int col = pt.y + colNum[i];
             
            // if adjacent cell is valid, has path and
            // not visited yet, enqueue it.
            if (isValid(row, col) && mat[row][col] &&
               !visited[row][col])
            {
                // mark cell as visited and enqueue it
                visited[row][col] = true;
                queueNode Adjcell = { {row, col},
                                      curr.dist + 1 };
                q.push(Adjcell);
            }
        }
    }
 
    // Return -1 if destination cannot be reached
    return -1;
}
void printer(vector<vector<int>> max,int x,int y){
    system("CLS");
    cout<<"\nSteps taken: "<<steps<<"  "<<dist<<"\n";
    int s1=max.size();
    int s2=max[0].size();
    cout<<"\t\tScore: "<<score<<"\n";
    for(int i=0;i<s1;i++){
        for(int j=0;j<s2;j++){
            if(i==8&&j==9)
                a='1';
            if(i==x&&j==y){
                cout<<(char)(219)<<" ";
                continue;
            }
            if(i==dest.x&&j==dest.y){
                a='1';
                cout<<'X'<<" ";
            }
            else
            cout<<max[i][j]<<" ";
        }
        cout<<"\n";
    }
}
void failed(){
    cout<<"---------------Game Over-----------------\n";
    cout<<"Enter 1 to try again and 2 to exit\n";
    inp=getch();
}
void successfull(){
    system("CLS");
    cout<<"You have reched the desitnation in "<<steps<<" Steps \n";
    cout<<"Minimum Steps required: "<<dist<<"\n";
    cout<<"Final score: "<<score<<"\n";
    if(score==1000){
        cout<<"Congratulation you have achieved the perfect score \n";
    }
    else{
        cout<<"Score breakdown 1000"<<(dist-steps)<<"*10="<<score<<"\n";
    }
    cout<<"______Thanks for playing_____\n";
    cout<<"Enter any key to exit\n";
    char ch=getch();
}
void strt_screen(){
    cout<<"_______________This is The Maze _________________\n";
    cout<<"Enter 1 to play the easy mode\n";
    cout<<"Enter 2 to play the hard mode\n";
    inp=getch();
}
void play(vector<vector<int>> mat){
    int i=0,j=0,modifier=-10;
    cout<<"Enter w a s d to move \n";
    printer(mat,i,j);
    steps=0;
    while(a=getch()){
        system("CLS");
        switch(a){
            case 'w':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                    cout<<"hello\n";
                }
                if(mat[i-1][j]==0||i-1<0){
                    failed();
                    return;
                }
                if(i-1==dest.x&&j==dest.x){
                    successfull();
                    return;
                }
                printer(mat,--i,j);
            break;
            case 'a':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i][j-1]==0||j-1<0){
                    failed();
                    return;
                }
                if(i==dest.x&&j-1==dest.y){
                    successfull();
                    return;
                }
                printer(mat,i,--j);
            break;
            case 's':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i+1][j]==0||i+1>ROW){
                    failed();
                    return;
                }
                if(i+1==dest.x&&j==dest.y){
                    successfull();
                    return;
                }
                printer(mat,++i,j);
            break;
            case 'd':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i][j+1]==0||j+1>COL){
                    failed();
                    return;
                }
                if(i==dest.x&&j+1==dest.y){
                    successfull();
                    return;
                }
                printer(mat,i,++j);
            break;
            default:
            printer(mat,i,j);
                a=getch();
        }
    }
}
int mainm()
{
    strt_screen();
    vector<vector<int>> mat= 
                { {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                  {1, 0, 1, 0, 1, 1, 1, 0, 1, 1 },
                  {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                  {0, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                  {1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
                  {1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
                  {1, 0, 1, 0, 0, 0, 0, 0, 0, 1 },
                  {1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                  {1, 1, 0, 0, 0, 0, 1, 0, 0, 1 }};
    vector<vector<int>> mat2=
   {{1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,1,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,1,0,1,0,1,0,1,0,0,0,1,0,0,0,1,0,0,0,1},
    {1,1,1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0},
    {1,0,1,0,1,1,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1,1,1},
    {1,0,1,0,1,1,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1,0,1},
    {1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,1,0,1,1,1,0,1,0,0,0,0,0,0,0,1,0,1,0,0,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,1,1},
    {1,0,1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1},
    {1,0,1,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,0,1},
    {1,0,1,0,0,0,1,0,1,1,1,0,1,0,1,0,0,0,1,0,1,0,1},
    {1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,0,0,1,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1}};
    if(inp=='1'){
        ROW=9;
        COL=10;
        Point src(0,0);
        dest.x=8;dest.y=9;
        /*pair<int, int> src = make_pair(0, 0);
        pair<int, int> dest = make_pair(8, 9);*/
        dist = BFS(mat, src, dest);
        play(mat);
    }
    else {
        ROW=23;
        COL=23;
        Point src(0,0);
        dest.x=10;dest.y=10;
        //pair<int, int> src = make_pair(0, 0);
        //pair<int, int> dest = make_pair(10, 10);
        dist = BFS(mat2, src, dest);
        play(mat2); 
    }
    int i=0,j=0;
    score=1000;
    int modifier=-10;
    /*i=0,j=0,score=1000;
    cout<<"Enter w a s d to move \n";
    printer(mat,i,j);
    steps=0;
    while(a=getch()){
        system("CLS");
        switch(a){
            case 'w':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i-1][j]==0||i-1<0){
                    failed();
                    goto en;
                }
                if(i-1==8&&j==9){
                    successfull();
                    goto en;
                }
                printer(mat,--i,j);
            break;
            case 'a':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i][j-1]==0||j-1<0){
                    failed();
                    goto en;
                }
                if(i==8&&j-1==9){
                    successfull();
                    goto en;
                }
                printer(mat,i,--j);
            break;
            case 's':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i+1][j]==0||i+1<0){
                    failed();
                    goto en;
                }
                if(i+1==8&&j==9){
                    successfull();
                    goto en;
                }
                printer(mat,++i,j);
            break;
            case 'd':
                system("CLS");
                steps++;
                if(steps>dist){
                    score=score+modifier;
                }
                if(mat[i][j+1]==0||j+1<0){
                    failed();
                    goto en;
                }
                if(i==8&&j+1==9){
                    successfull();
                    goto en;
                }
                printer(mat,i,++j);
            break;
            default:
            printer(mat,i,j);
                a=getch();
        }
    }
    en:*/
    if(inp!='2'){
        cout<<"Enter 1 to play again: \n";
        inp=getch();
    }
    if(inp=='1')
        play(mat);
    cout<<"\n";
    return 0;
}
/*
   {{1,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
    {1,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,1,1},
    {1,0,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

    
    
    
    
    }

*/