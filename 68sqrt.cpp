

//
//
//
//Implement int sqrt(int x).
//
//Compute and return the square root of x.

class Solution {
public:
    int mySqrt(int x) 
    {
        long long i = 1, j = x;
        
        while ( i+1 < j)
        {
            long long mid = i +(j-i)/2;
            
            if (mid*mid == x)
            {
                return mid;
            }
            else if ( mid*mid > x)
            {
                j = mid;
            }
            else
            {
                i= mid;
            }
        }
    
        if(j*j <= x)
        {
            return j;
        }
        return i;
    }
};
