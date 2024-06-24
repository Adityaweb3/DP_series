// Problem Link : https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

 int count (vector<int>&arr , int k , int n){
       vector<vector<int>>dp(n+1 , vector<int>(k+1 , 0)) ; 
       
       dp[0][0]=1 ; 
       
       for(int i =1 ; i<=n ; i++){
           for(int j =0 ; j<=k ; j++){
               int notake = dp[i-1][j] ; 
               
               int take = 0 ; 
               
               if(arr[i-1]<=j){
                   take = dp[i-1][j-arr[i-1]] ; 
               }
               
               dp[i][j] = (take+notake)%1000000007 ; 
           }
       }
       
       return dp[n][k] ; 
   }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0 ; 
        for(auto i : arr){
            sum+=i ; 
        }
        
        if((sum+d)%2!=0){
            return 0 ; 
        }
        
        int k = (sum+d)/2 ; 
        
        return count(arr , k , n) ; 
    }