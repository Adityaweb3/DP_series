// Problem Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

int maxProfit(vector<int>& prices) {
       int n = prices.size() ; 
       int profit = 0 ; 
       for(int i =1 ; i<n ;i++){
           if(prices[i]>prices[i-1]){
               profit+=(prices[i]-prices[i-1]) ; 

           }
       }

       return profit ;
    }