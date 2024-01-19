// You are given an array 'arr' containing 'n' non-negative integers.
// Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.


int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	
	int totalSum = 0 ; 
	for(int i = 0 ; i<n ; i++){
		totalSum+=arr[i] ;
	}
	int k = totalSum ;

	vector<vector<bool>>dp(n , vector<bool>(k+1 , 0)) ;

	for(int i = 0 ; i<n ; i++){
		dp[i][0]=true ; 
	}

	if(arr[0]<=k){
		dp[0][arr[0]] = true ;
	}

	for(int i = 1; i<n ; i++){
		for(int j =1 ; j<=k ;j++){
			bool notake = dp[i-1][j] ;

			bool take = false ; 
			if(arr[i]<=j){
				take = dp[i-1][j-arr[i]] ; 
			}

			dp[i][j] = take | notake ; 
		}
	}

	int mini = 1e9 ; 
	for(int s1 = 0 ; s1<=totalSum/2 ; s1++){
		if(dp[n-1][s1]==true){
			mini = min(mini , abs((totalSum-s1)-s1)) ;
		}

	}

	return mini ; 
}
