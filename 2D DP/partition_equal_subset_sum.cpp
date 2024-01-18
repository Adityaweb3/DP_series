// You are given an array 'ARR' of 'N' positive integers. 
// Your task is to find if we can partition the given array into two subsets such that the sum of elements in 
// both subsets is equal.

bool SumK(vector<int>&arr , int k){
  int n = arr.size() ; 

  vector<vector<bool>>dp(n , vector<bool>(k+1,0)) ; 

  for(int i = 0 ; i<n ;i++){
	  dp[i][0]=true ;
  }

  dp[0][arr[0]]=true ; 

  for(int i = 1 ; i<n ; i++){
	  for(int j =1 ; j<=k ;j++){
		  bool notake = dp[i-1][j] ; 
		  bool take = false ; 

		  if(arr[i]<=j){
			  take = dp[i-1][j-arr[i]] ; 
		  }
		  dp[i][j]= take |notake ; 
	  }
  }


  return dp[n-1][k] ; 
}

bool canPartition(vector<int> &arr, int n)
{
	// Write your code here.
	int sum = 0 ;

	for(int i = 0 ; i<n ; i++){
		sum+=arr[i] ; 
	}

	if(sum%2!=0){
		return false ; 
	}

	int target = sum/2 ; 

	return SumK(arr , target) ; 
}
