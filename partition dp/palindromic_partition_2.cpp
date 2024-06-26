// Problem Link : https://leetcode.com/problems/palindrome-partitioning-ii/description/

bool isPalindrome(string &s , int start , int end){
        int low = start ;
        int high = end ; 

        while(low<high){
            if(s[low]!=s[high]){
                return false ; 
            }
            low++ ; 
            high-- ; 
        }

        return true ; 
    }

    int mcm(string &s , int i , int j , vector<vector<int>>&dp){
        if(i>=j){
            return 0 ; 
        }


        if(isPalindrome(s , i , j)){
            dp[i][j]=0 ;
            return dp[i][j] ; 
        }

        if(dp[i][j]!=-1){
            return 0 ; 
        }

       dp[i][j]=INT_MAX ; 
        for(int k = i ; k<=j-1 ; k++){
            int left = 0 ; 
            int right =0 ; 

            if(dp[i][k]!=-1){
                left = dp[i][k] ; 
            }
            else {
                if(isPalindrome(s , i , k)){
                    left=0 ; 
                }
                else {
                    left = mcm(s , i , k ,dp) ;
                } 
            }

            if(dp[k+1][j]!=-1){
                right = dp[k+1][j] ; 
            }
            else {
                if(isPalindrome(s , k+1 , j)){
                    right=0;
                }
                else {
                    right = mcm(s, k+1 , j , dp) ; 
                }
            }

            dp[i][j] = min(dp[i][j] , 1+left+right) ; 
        }
        return dp[i][j] ; 
    }
    int minCut(string s) {
        int n = s.size() ;
        int i = 0 ; 
        int j= s.size()-1 ; 
        vector<vector<int>>dp(n , vector<int>(n , -1)) ; 
        return mcm(s,i , j , dp) ; 
    }