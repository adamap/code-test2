//
//
//Given an integer n, return the number of trailing zeroes in n!.
//
//Note: Your solution should be in logarithmic time complexity.
//

class Solution {
public:
    int trailingZeroes(int n) 
    {
        long sum = 0;
        
        while( n!= 0)
        {
            sum += n/5;
            n=n/5;
        }
        
        return sum;
    }
};
