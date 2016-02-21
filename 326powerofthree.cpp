//Given an integer, write a function to determine if it is a power of three. 


class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        if ( n == 0)
        {
            return 0;
        }
        int i = n;
        while (n%3 == 0)
        {
            n = n/3;
            i = n;
        }
        
        if ( i == 1)
        {
            return 1;
        }
        return 0;
        
    }
};
