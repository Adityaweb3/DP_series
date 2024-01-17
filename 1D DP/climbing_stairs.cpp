// You have been given a number of stairs. Initially, you are at the 0th stair, and you need to reach the Nth stair. 
// Each time you can either climb one step or two steps. 
// You are supposed to return the number of distinct ways in which you can climb from the 0th step to Nth step.

#include <bits/stdc++.h> 
int countDistinctWays(int nStairs) {
    //  Write your code here.
    const int mod = 1000000007;

    vector<int>dp(nStairs+1 , -1) ; 

    dp[0]=1 ; 
    dp[1]=1 ; 

    for(int i =2 ; i<=nStairs ; i++){
        dp[i]=(dp[i-1]+dp[i-2])%mod ; 

    }

    return dp[nStairs] ; 
}