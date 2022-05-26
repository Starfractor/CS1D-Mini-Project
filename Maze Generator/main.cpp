#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> generateMazeDFS(int n);

int main()
{
    //Input
    cout << "ENTER SIZE OF MAZE (N x N) between 10-50" << endl;
    int n;
    cin >> n;

    vector<vector<int>> maze = generateMazeDFS(n);

    //Get start point
    int x = rand() % (n + 1);
    int y = rand() % (n + 1);

    while(maze[y][x] != 0) {
        x = rand() % (n + 1);
        y = rand() % (n + 1);
    }

    cout << endl;

    cout << "{";
    for (int i = 0; i < n - 1; ++i) {
	    cout << "{";
        for(int j = 0; j < n - 1; ++j){
            cout <<  maze[i][j] << ",";
        }
        cout << maze[i][n - 1] << "}," << endl;
    }
    cout << "{";
    for(int i = 0; i < n - 1; ++i)
        cout << maze[n - 1][i] << ",";
    cout << maze[n - 1][n - 1] << "}}" << endl << endl;

    cout << "Start at (" << x << ", " << y << ")" << endl;
             
    return 0;
}


