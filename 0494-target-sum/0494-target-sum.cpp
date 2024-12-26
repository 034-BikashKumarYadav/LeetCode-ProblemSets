class Solution {
     private:
    //int dp[501][2501];
    int mod=1e9+7;
    int solve(int ind,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(ind==0)
        {
            if(sum==0 && arr[0]==0)
              return 2;
             
             if(sum==0 || arr[0]==sum)
               return 1;
            
            return 0;
        }
        
        if(dp[ind][sum]!=-1)
         return dp[ind][sum];
        
        int np=solve(ind-1,sum,arr,dp);
        int p=0;
        
        if(sum>=arr[ind])
            p=solve(ind-1,sum-arr[ind],arr,dp);
            
        return dp[ind][sum]=(p+np)%mod;
    }

  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
      //  memset(dp,-1,sizeof(dp));
        int tSum=0;
        for(int i=0;i<arr.size();i++)
        {
               tSum+=arr[i]%mod;
        }
        
      int   s2=(tSum-d);
        
        if(s2<0 || s2%2==1)
          return 0;
          
    vector<vector<int>>dp(n,vector<int>(s2/2+1,-1));
        
         
        return solve(n-1,s2/2,arr,dp);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
         return countPartitions(n,target,nums);
    }
};