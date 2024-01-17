// You are given an array/list of ‘N’ integers. 
// You are supposed to return the maximum sum of the subsequence 
// with the constraint that no two elements are adjacent in the given array/list.

#include <bits/stdc++.h> 
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size() ; 
    vector<int>dp(n , 0) ; 
    dp[0]= nums[0];

    for(int i =1 ; i<n ;i++){
        int take = nums[i] ; 
        if(i>1) {
            take+=dp[i-2] ; 
        }

        int notake = 0 + dp[i-1];

        dp[i] = max(take , notake) ; 

    }

    return dp[n-1] ; 
}