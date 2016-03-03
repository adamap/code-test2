//
//
//
//
//Determine whether an integer is a palindrome. Do this without extra space.
//
//
class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long i = 10; 
        
        long long temp = x;
        if ( temp < 0)
        {
            return 0;
        }
        
        while( i < temp)
        {
            i = i*10;
        }
        
        i= i/10;
        
        while( temp > 0)
        {
            int a = temp/i;
            int b = temp%10;
            if ( a != b)
            {
                return 0;
            }
            temp = temp%i;
            temp = temp/10;
            i = i/100;
        }
        
        return 1;
        
    }
};
