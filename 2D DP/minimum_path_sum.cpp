// Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. 
// Each point in the grid has some cost associated with it.
// Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) 
// which minimizes the sum of the cost of all the numbers along the path. 
// You need to tell the minimum sum of that path.

#include <bits/stdc++.h> 
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size() ;
    int m = grid[0].size() ;
    int dp[n][m] ; 

    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            if(i==0 && j==0){
                dp[i][j]=grid[0][0]  ; 
            }

            else {
            int up = grid[i][j]  ; 
            int left = grid[i][j] ; 

            if(i>0){
                up +=dp[i-1][j] ; 
            }
            else {
                up +=1e9 ; 

            }

            if(j>0){
                left +=dp[i][j-1] ; 
            }

            else {
                left+=1e9 ; 
            }

            dp[i][j] =min(up , left) ; 

            }

            
        }
    }

    return dp[n-1][m-1] ; 
}