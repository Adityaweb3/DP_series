// You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from
// a path starting from any cell in the first row to any cell  in the last row.
// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or 
// right. So from a particular cell (row, col), we can move in three directions

#include <bits/stdc++.h> 

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size() ; 
    int m= matrix[0].size() ; 
    vector<vector<int>>dp(n , vector<int>(m,0)) ;

    for(int j = 0 ; j<m ; j++){
        dp[0][j]=matrix[0][j] ; 
    }

    for(int i =1 ; i<n ; i++){
        for(int j = 0 ; j<m ; j++){
            int u = matrix[i][j]+dp[i-1][j] ; 
            int ld = matrix[i][j] ; 

            if(j-1>=0){
                ld+=dp[i-1][j-1];
            }

            else {
                ld+=-1e8 ;
            }

            int rd = matrix[i][j] ; 
            if(j+1<m){
                rd+=dp[i-1][j+1] ;
            }

            else {
                rd+=-1e8 ; 
            }

            dp[i][j]= max(u , max(ld , rd));
        }
    }
    

    int maxi = dp[n-1][0] ; 

    for(int i = 1 ; i<m ; i++){
        maxi = max(maxi , dp[n-1][i]) ;
    }

    return maxi ; 
}