// Problem Link : https://www.codingninjas.com/studio/problems/matrix-chain-multiplication_975344

#include <bits/stdc++.h> 

int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>>dp(N , vector<int>(N , 0)) ; 

    for(int i= N-1 ; i>=0 ; i--){
        for(int j = i+1 ; j<N ; j++){
            int steps = 0 ; 
            int mini= 1000000009;
            for(int k = i; k<=j-1 ;k++){
                int steps = (arr[i-1]*arr[k]*arr[j]) + dp[i][k]+dp[k+1][j] ; 
                mini = min(mini, steps) ; 
            }

            dp[i][j]= mini ; 
        }
    }

    return dp[1][N-1] ; 

    
}