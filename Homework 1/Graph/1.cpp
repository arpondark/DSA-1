/*
!!leet code 463. Island Perimeter
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int island = 0;
        int neibor = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j]) {
                    island++;
                    if (i - 1 >= 0 && grid[i - 1][j]) {
                        neibor++;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1]) {
                        neibor++;
                    }
                }
            }
        }
        return island * 4 - neibor * 2;
    }
};
*/
/*
!!using dfs to find the perimeter of an island in a grid
class Solution {
public:

    int counter = 0;
     
     void dfs(int i,int j,vector<vector<int>>& grid)
     {
        int l = grid.size();
        int m = grid[0].size();

        
        if(i>=l || j >= m)
        {
            counter++;
            return;
        }
        if(i<0 || j < 0)
        {
            counter++;
            return;
        }
        if(grid[i][j] == 0)
        {
            counter++;
            return;
        }

        if(grid[i][j] == -1)
            return;

        
        grid[i][j] = -1;
        


        dfs(i-1,j,grid);
        dfs(i+1,j,grid);
        dfs(i,j-1,grid);
        dfs(i,j+1,grid);
     }
 
    int islandPerimeter(vector<vector<int>>& grid) {

        int r =0;
        int c = 0;
        
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j =0; j < grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(i,j,grid);
                    return counter;
                }
                
            }
        }
         return counter;
        
    }
};
*/



#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void dfs(int i, int j, vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    
    // If out of bounds or water, increment perimeter counter
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) {
        counter++;
        return;
    }
    
    // If already visited (marked as -1), return
    if (grid[i][j] == -1) {
        return;
    }
    
    // Mark current cell as visited
    grid[i][j] = -1;
    
    // Explore all 4 directions: up, down, left, right
    dfs(i - 1, j, grid);
    dfs(i + 1, j, grid);
    dfs(i, j - 1, grid);
    dfs(i, j + 1, grid);
}

int islandPerimeter(vector<vector<int>>& grid) {
    counter = 0; // Reset counter for each call
    
    // Find the first land cell and start DFS
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                dfs(i, j, grid);
                return counter;
            }
        }
    }
    
    return counter;
}

int main() {
    int rows, cols;
    cin >> rows >> cols;
    
    vector<vector<int>> grid(rows, vector<int>(cols));
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }
    
    int result = islandPerimeter(grid);
    cout << result << endl;
    
    return 0;
}
