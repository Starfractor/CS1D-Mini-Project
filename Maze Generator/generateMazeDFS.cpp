#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMazeDFS(int n) 
{
  
  int startY = rand() % (n + 1);
  int startX = rand() % (n + 1);
  int y = startY;
  int x = startX;
  vector<vector<int>> maze(n, vector<int>(n, 1));
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  stack<pair<int, int>> stk;
  stk.push(make_pair(y, x));
  visited[y][x] = true;


  while (!stk.empty())
  {
        //Get head of stack
        pair<int, int> cell = stk.top();
        stk.pop();
        y = cell.first;
        x = cell.second;

        //Get neighbors
        vector<pair<int, int>> neighbors;
        if(x + 1 < n && !visited[y][x + 1]) neighbors.push_back(make_pair(y, x + 1));
        if(y + 1 < n && !visited[y + 1][x]) neighbors.push_back(make_pair(y + 1, x));
        if(x - 1 >= 0 && !visited[y][x - 1]) neighbors.push_back(make_pair(y, x - 1));
        if(y - 1 >= 0 && !visited[y - 1][x]) neighbors.push_back(make_pair(y - 1, x));

        if (!neighbors.empty())
        {
            //Select random neighbor
            int randIdx = rand() % neighbors.size();

            //Visit all neighbors
            for (int i = 0; i < neighbors.size(); ++i)
            {
                int yCell = neighbors[i].first;
                int xCell = neighbors[i].second;
                
                visited[yCell][xCell] = true;

                
                //Add all except for picked node
                if (i != randIdx) stk.push(neighbors[i]);
            }

            //Add picked node
            stk.push(neighbors[randIdx]);
            maze[neighbors[randIdx].first][neighbors[randIdx].second] = 0;

            //Connect rooms
            if(visited[y][x] && maze[y][x] == 1) maze[y][x] = 0;
        }
  }

  //Get Goal
  maze[startY][startX] = 2;

  return maze;
}
