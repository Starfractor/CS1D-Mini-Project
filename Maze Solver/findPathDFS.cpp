#include <bits/stdc++.h>

using namespace std;

void searchPath(vector<vector<int>>& maze, vector<vector<int>>& path, int x, int y, int n);

vector<vector<int>> sol;

vector<vector<int>> findPathDFS(vector<vector<int>>& maze , int x, int y)
{
    int n = maze.size();
    vector<vector<int>> path;
    searchPath(maze, path, x, y, n);
    return sol;
}

void searchPath(vector<vector<int>>& maze, vector<vector<int>>& path, int x, int y, int n)
{
    //Invalid move
    if(x < 0 || y < 0 || y >= n || x >= n || maze[y][x] == 1) {
        return;
    }

    //Reached destination
    if(maze[y][x] == 2)  {
        path.push_back({y, x});
        if(sol.empty() || path.size() < sol.size()) sol = path;
        path.pop_back();
        return;
    }

    //Add to path
    maze[y][x] = 1;
    path.push_back({y, x});
    
    //Make moves
    searchPath(maze, path, x + 1, y, n);
    searchPath(maze, path, x - 1, y, n);
    searchPath(maze, path, x, y + 1, n);
    searchPath(maze, path, x, y - 1, n);

    //Undo path
    maze[y][x] = 0;
    path.pop_back();
   

}
