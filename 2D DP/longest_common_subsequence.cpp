// Problem Link : https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879

int lcs(string s, string t)
{
	//Write your code here
    int n = s.size() ; 
	int m = t.size() ; 
	vector<vector<int>>dp(n+1  , vector<int>(m+1 , -1)) ;

    for(int j = 0 ; j<=m ;j++){
		dp[0][j]=0 ;
		
	}

	for(int i=0 ; i<=n ;i++){
		dp[i][0]=0 ;
	}

	for(int i =1 ; i<n+1 ; i++){
		for(int j =1 ;j<m+1 ; j++){
			if(s[i-1]==t[j-1]){
				dp[i][j]= 1+dp[i-1][j-1] ;	

			}
			else {
				dp[i][j]= max(dp[i-1][j] , dp[i][j-1]) ;
			}
		}
	}

	return dp[n][m] ;
}