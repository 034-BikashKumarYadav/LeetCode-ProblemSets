class Solution {
public:
    int findMinDifference(vector<string>& timePoints) 
    {
        vector<int> num(timePoints.size());
        for(int i = 0; i < timePoints.size(); i++)
        {
            num[i] = stoi(timePoints[i].substr(0, 2)) * 60 + stoi(timePoints[i].substr(3, 2)); 
        }
        sort(num.begin(),num.end());

        int min_dif = 1439;
        for(int i = 0; i < num.size()-1; i++)
        {
            if((num[i+1]-num[i]) < min_dif) min_dif = num[i+1]-num[i]; 
        }

        if (num[0] + 1440 - num[num.size()-1] < min_dif) 
            min_dif = num[0] + 1440 - num[num.size()-1]; 
        
        return min_dif;
    }
};