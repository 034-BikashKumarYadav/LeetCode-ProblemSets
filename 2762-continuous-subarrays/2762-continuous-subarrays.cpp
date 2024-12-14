class Solution {
public:
    //Optimal Sliding Window + Multiset problem
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count = 0;

        //To get the largest and smallest in a subarray, we use multiset
        multiset<int> st;

        //initialise two pointers
        //Here i is the front and j is the rear pointer
        int i = 0;
        int j = 0;

        //we will check til rear < n i.e j < n
        while(j<n){

            //insert the element at rear
            st.insert(nums[j]);

            //When the condition fails, we can just remove the element at front pointer and increase the front pointer
            while(!st.empty() && (*st.rbegin() - *st.begin()) > 2){
                //Here as there are dublicates in the multisetm if we use st.erase(nums[i]), it will remove all the same numbers, we just find one and delete it.
                st.erase(st.find(nums[i]));
                i++;
            }

            //Most confusing part =>
            //count is increased by j - i + 1 as -
            //Lets take a subarray -> [5,6].
            //Here there are two subarray that satisfies the condion first are [5,6] and [6] itself. so i.e i=0,j=1 so count += 1-0+1 => count += 2.
            //lets take another subarray -> [3,4,5,6]
            //Here also we have j-i+1 = 4 subarrays that satisfies the condition -> [3,4,5,6] , [4] , [5] , [6].****Bold****
            count =  count + j-i +1;

            //Increment the rear pointer
            j++;
        }
        return count;
    }
};