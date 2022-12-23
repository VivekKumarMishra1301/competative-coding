/*
    Note:
    To get all the test cases accepted, make recursive calls in following order: Top, Down, Left, Right.
    This means that if the current cell is (x, y), then order of calls should be: top cell (x-1, y),
    down cell (x+1, y), left cell (x, y-1) and right cell (x, y+1).
*/
#include <bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int>> &maze, vector<vector<int>> &smaze, int x, int y, int size)
{

    if (x < 0 || y < 0)
    {
        return false;
    }
    if (x >= size || y >= size)
    {
        return false;
    }

    // Both should be below because if x and y are wrong addresses and we try to access the wrong address it will give the runtime error

    if (maze[x][y] == 0)
    {
        return false;
    }
    if (smaze[x][y] == 1)
    {
        return false;
    }
    return true;
}

void printMaze(vector<vector<int>> &maze)
{
    for (int i = 0; i < maze.size(); i++)
    {
        for (int j = 0; j < maze[i].size(); j++)
        {
            cout << maze[i][j] << " ";
        }
    }
    cout << endl;
}

void rat(vector<vector<int>> &maze, vector<vector<int>> &smaze, int m, int n, int size)
{
    if (m == size - 1 && n == size - 1)
    {
        smaze[m][n] = 1;
        printMaze(smaze);
        return;
    }
    if (safe(maze, smaze, m, n, size))
    {
        smaze[m][n] = 1;
        rat(maze, smaze, m - 1, n, size);
        rat(maze, smaze, m + 1, n, size);
        rat(maze, smaze, m, n - 1, size);
        rat(maze, smaze, m, n + 1, size);
        smaze[m][n] = 0;
    }
}

int main()
{

    // Write your code here
    int n;
    cin >> n;
    vector<vector<int>> maze(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k;
            cin >> k;
            maze[i][j] = k;
        }
    }
    // printMaze(maze);
    vector<vector<int>> smaze(n, vector<int>(n, 0));
    rat(maze, smaze, 0, 0, n);
    return 0;
}

// void mazeHelp(int maze[][20], int n, int** solution, int x, int y){
// 	if(x == n-1 && y == n-1){
// 		solution[x][y] = 1;
// 		printSolution(solution, 1);
// 		solution[x][y] = 0;
// 		return;
// 	}

// 	if(x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || solution[x][y] == 1){
// 		return;
// 	}
// }

// void ratInAMaze(int maze[][20], int n){
// 	int **solution = new int*[n];

// 	for(int i = 0; i < n; i++){
// 		solution[i] = new int[n];
// 	}

// 	for(int i = 0; i < n; i++){
// 		memset(solution[i], 0, n*sizeof(int));
// 	}

// 	mazeHelp(maze, n, solution, 0, 0);
// }

// int main(){
// 	int n;
// 	cin >> n;
// 	int maze[20][20] = {0};

// 	for(int i = 0; i < n; i++){
// 		for(int j = 0; j < n; j++){
// 			cin >> maze[i][j];
// 		}
// 	}

// 	ratInAMaze(maze, n);
// 	return 0;
// }
