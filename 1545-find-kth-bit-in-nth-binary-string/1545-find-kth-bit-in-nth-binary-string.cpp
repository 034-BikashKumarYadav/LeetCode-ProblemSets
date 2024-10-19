class Solution {
public:
    char findKthBit(int n, int k) {
        if (n == 1) return '0'; // Base case
        int len = (1 << n) - 1; // Total length of Sn
        if (k == len / 2 + 1) return '1'; // Middle element is '1'
        if (k <= len / 2) return findKthBit(n - 1, k); // Before middle
        return findKthBit(n - 1, len - k + 1) == '0' ? '1' : '0'; // After middle and inverted
    }
};