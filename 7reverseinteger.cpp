//
//
//
//
//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321 

class Solution {
public:
    int reverse(int x) 
    {
        int sign = (x<0)?-1:1;
        long long temp = (long long)x;
        temp = (temp>0)?temp:(-temp);
        
        long long result = 0;
        
        while(temp > 0 )
        {
            long long mod = temp%10;
            result = result*10+mod;
            temp = temp/10;
        }
        
        result = result*sign;
        
        if ( result < INT_MIN || result > INT_MAX)
        {
            return 0;
        }
        
        return (int)result;
    }
};
