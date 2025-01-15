#include <immintrin.h>

class Solution {
public:
    static int minimizeXor(unsigned num1, unsigned num2) __attribute__(( __target__("bmi2"))) {
            const int A=popcount(num1)-popcount(num2);
                    return (A>0)?_pdep_u32(UINT_MAX<<A, num1):num1+_pdep_u32((1<<-A)-1, ~num1);
                        }
                        };