class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long temp=x;
        long long rev=0;
        while(temp!=0)
        {
             int mod=temp%10;
             rev=rev*10+mod;
             temp/=10;
        }

        return rev==x;
    }
};