// Problem Link : https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1

 
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
         int mod= (int)1e9+7;
        int dp[n+1][sum+1];
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j <= sum; j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= sum; j++){
                if( arr[i-1] <= j){
                    dp[i][j] = (dp[i-1][j] + dp[i-1][j- arr[i-1]])%mod;
                }
                else
                    dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n][sum];
	}

