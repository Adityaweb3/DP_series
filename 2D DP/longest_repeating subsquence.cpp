// // Problem : https://www.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1

// lcs with i==j not allowed

 int lcs(string &s1 , string &s2 , int n){
	       vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0)) ; 
	       
	       for(int i =1 ; i<=n ; i++){
	           for(int j=1 ; j<=n ; j++){
	               if(s1[i-1]==s2[j-1] && i!=j){
	                   dp[i][j]= 1+dp[i-1][j-1] ; 
	               }
	               else {
	                   dp[i][j]= max(dp[i-1][j] , dp[i][j-1]) ; 
	               }
	           }
	       }
	       
	       return dp[n][n] ; 
	   }
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    int n = str.size() ; 
		    
		    return lcs( str , str , n) ; 
		}