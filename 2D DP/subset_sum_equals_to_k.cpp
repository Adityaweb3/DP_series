// You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. 
// Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.
// Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>>dp(n ,vector<bool>(k+1 , 0)) ;
    for(int i = 0 ;i<n ; i++){
        dp[i][0]=true ;
    }

    dp[0][arr[0]] = true ; 

    for(int i = 1; i<n ; i++){
        for(int t =1 ; t<=k ;t++){
            bool notake = dp[i-1][t] ;

            bool take = false ; 

            if(arr[i]<=t ){
                take = dp[i-1][t-arr[i]] ;
            }

            dp[i][t] = take |notake ;

        }
    }

    return dp[n-1][k] ;
}