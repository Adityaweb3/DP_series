string slv(int m,int n,string& s1,string& s2)
    {   
        string dp[m+1][n+1];
        for(int i=0;i<m+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                if(i==0||j==0) dp[i][j]="";
                else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1] + s1[i-1];
                else
                    dp[i][j]=(dp[i-1][j].size()>=dp[i][j-1].size())?dp[i-1][j]:dp[i][j-1];
            }
        }
        return dp[m][n];
    }