class Solution {
public:

long long nC2(int n) {
    if (n < 2) return 0; 
    return (1LL * n * (n - 1)) / 2;
}
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(1e4, 0);
        map<int, int> mp;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                int p = nums[i] * nums[j];
                mp[p]++;
            }
        }
        int ans=0;
        for (auto it : mp) {
           
            if(it.second>=2){
                 cout<<it.first<<" "<<it.second<<endl;
               ans+=8*(nC2(it.second));
            }
        }
        return ans;
    }
};