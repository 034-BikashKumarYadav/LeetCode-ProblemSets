class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& vect) {
        vector<int>arr=vect;
        sort(arr.begin(),arr.end());
        unordered_map<int,int>mp;
        int n=arr.size(), rank=1;
        int i=0;
        while(i<n)
        {
            if(i==0)
            {}
            else if(arr[i]==arr[i-1])
            {}
           else rank++;
            mp[arr[i]]=rank;
           
            i++;
        }

        for(auto &i:vect)
        {
               i=mp[i];
        }

        return vect;
    }
};