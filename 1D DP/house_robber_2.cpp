// Mr. X is a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money hidden. All houses along this street are arranged in a circle.
//  That means the first house is the neighbor of the last one. Meanwhile, 
//  adjacent houses have a security system connected, and it will automatically contact the police if two adjacent 
//  houses were broken into on the same night.
// You are given an array/list of non-negative integers 'ARR' representing the amount of money of each house. 
// Your task is to return the maximum amount of money Mr. X can rob tonight without alerting the police.

class Solution {
public:
    int rob1(vector<int>&nums){
        int n = nums.size() ; 

        vector<int>dp(n,0) ; 
        dp[0] = nums[0] ; 

        for(int i =1 ; i<n ; i++){
            int take = nums[i] ; 
            if(i>1){
                take+=dp[i-2] ; 
            }
            int notake = dp[i-1] ; 


            dp[i]= max(take,notake) ;
        }

        return dp[n-1] ;
    }
    int rob(vector<int>& nums) {

        int n = nums.size() ; 
        if(n==1){
            return nums[0] ; 
        }

        vector<int>n1 ; 
        vector<int>n2 ; 

        for(int i = 0 ; i<n ; i++){
            if(i!=0){
                n1.push_back(nums[i]) ; 
            }

            if(i!=n-1){
                n2.push_back(nums[i]) ; 
            }

            
        }

        return max(rob1(n1) , rob1(n2)) ; 
        
    }
};