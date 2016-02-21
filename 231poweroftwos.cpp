//Given an integer, write a function to determine if it is a power of two.
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
        if ( n == 0)
        {
            return 0;
        }
        int i = n;
        while (n%2 == 0)
        {
            n = n/2;
            i = n;
        }
        
        if ( i == 1)
        {
            return 1;
        }
        return 0;
    }
}; 
