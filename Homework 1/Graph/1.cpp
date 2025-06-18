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



#include <bits/stdc++.h>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    int perimeter = 0;
    
    // Directions: up, down, left, right
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                // Check all 4 directions for this land cell
                for (int k = 0; k < 4; k++) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    
                    // If neighbor is out of bounds or water, add to perimeter
                    if (newX < 0 || newX >= rows || newY < 0 || newY >= cols || grid[newX][newY] == 0) {
                        perimeter++;
                    }
                }
            }
        }
    }
    
    return perimeter;
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
