#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> findPathDFS(vector<vector<int>>& maze, int x, int y);

int main()
{
std::vector<std::vector<int>> maze = 
{{1,0,0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,1,0,0,1,1},
{0,0,1,1,1,1,1,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,0,1,0,0,1,0,0,0},
{0,1,1,1,0,0,0,1,1,1,1,1,0,0,1,0,0,0,1,1,0,0,0,1,1,0,1,1,1,0},
{0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,1,0,0,0,1,1,1,1,0,0,1,0,0,0},
{0,1,0,1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,1,0,1,0,0,1,0,0,1,0},
{0,0,1,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,0,1,1,0},
{1,0,1,0,1,0,0,1,0,0,1,0,0,0,1,0,1,1,1,1,0,0,1,0,0,1,0,1,0,0},
{1,0,0,0,1,0,1,1,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,1,0,1,0,0,1,1},
{0,1,0,1,0,0,1,1,0,1,0,0,0,0,1,0,0,1,1,1,1,1,0,0,0,1,1,0,0,0},
{0,0,0,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1,0,0,0,1,1,1,0,0,0,1,1,0},
{1,0,1,0,0,1,0,0,0,1,0,0,1,0,0,1,0,1,0,1,0,0,2,1,1,1,0,0,0,0},
{1,0,1,0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,0,0,1,1,1,1,0},
{1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,0,1,1,1,0,0,0,0,0,1,0,0,0,1,0},
{0,0,1,0,1,0,1,0,1,0,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,1,0,1,0},
{0,1,1,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,1,0,0,1,0,1,0,1,0,1,0},
{0,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,1,0,0,0,1,0,0,1,1,0,1,0,0,0},
{0,1,0,0,1,1,0,0,0,1,1,0,1,0,1,1,0,0,1,0,1,1,0,1,0,0,1,1,1,1},
{0,1,0,1,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,0,1,0,0,1,0,1,1,0,0,1},
{0,1,0,1,0,1,1,0,1,0,1,1,0,0,0,1,0,1,1,0,0,0,1,1,0,0,0,1,0,0},
{1,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,0,1,0,1,1,0,1,1,0},
{0,0,0,1,1,1,0,1,0,1,0,0,1,0,0,1,1,1,0,1,0,0,0,0,1,1,0,1,0,0},
{0,1,1,1,0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,1,1,1,1,0,0,1,0,1},
{0,1,0,0,0,1,1,0,0,0,1,1,0,0,1,1,0,0,1,0,0,1,1,0,0,0,1,1,0,1},
{0,1,0,1,1,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,1,1,0,0,0},
{0,0,0,1,1,0,0,1,0,1,1,0,0,1,1,0,0,1,1,1,1,0,1,1,0,0,1,0,1,0},
{0,1,1,0,0,0,1,0,0,1,0,1,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,1,0},
{0,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,1,1,0,0,1,0,0,1,1,1,1,0,0},
{1,0,1,0,1,1,1,0,1,0,1,1,1,0,0,1,1,1,0,1,0,0,1,0,0,1,1,0,0,0},
{0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0},
{0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,0}};
int startX = 3, startY = 25;

vector<vector<int>> path = findPathDFS(maze, startX, startY);  // TODO GET PATH HERE (i.e. path = dfs(maze, startY, startX);)

std::cout << "{";
if(!path.empty()) {
    for (int i = 0; i < path.size(); ++i) {
	std::cout << "{" <<  path[i][0] << "," << path[i][1] << "}" << (i == path.size() - 1 ? "" : ",");
    }
} 

std::cout << "}\n"; 

    return 0;
}

