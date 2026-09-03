class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        return ranges::min(nums1)&1 || ranges::all_of(nums1, [](int x){ return (x&1)==0;});
    }
};