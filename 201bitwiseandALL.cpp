//
//
//Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//For example, given the range [5, 7], you should return 4. 
//
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) 
    {
        int mask = INT_MAX;
        while ((m&mask) != (n&mask))
        {
            mask = mask<<1;
        }
        
        return mask&n;
    }
};
