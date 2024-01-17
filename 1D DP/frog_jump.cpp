// There is a frog on the '1st' step of an 'N' stairs long staircase. 
// The frog wants to reach the 'Nth' stair. 'HEIGHT[i]' is the height of the '(i+1)th' stair.
// If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute value of ( HEIGHT[i-1] - HEIGHT[j-1] ). 
// If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
// Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

#include <bits/stdc++.h> 


int frogJump(int n, vector<int> &heights)
{
vector<int>dp(n, 0) ; 
dp[0]= 0; 

for(int i = 1 ; i<n ; i++){
    int fs = dp[i-1] + abs(heights[i]-heights[i-1]) ; 

    int ss = INT_MAX ; 

    if(i>1){
        ss = dp[i-2]+ abs(heights[i]-heights[i-2]) ; 
    }

    dp[i]= min(fs , ss) ; 
}

return dp[n-1] ; 
    
}