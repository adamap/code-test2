//Write a program to check whether a given number is an ugly number. 
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7. 
//
//Note that 1 is typically treated as an ugly number. 
//
//Credits:
//

class Solution {
public:
    bool isUgly(int num) 
    {
        if ( num == 1)
        {
            return 1;
        }
        if ( num == 0)
        {
            return 0;
        }
        
        while ( num != 2 && num != 3 && num != 5)
        {
            if (num%2 != 0 && num%3 != 0 && num%5 != 0)
            {
                return 0;
            }
            if(num%2 == 0)
            {
                num = num/2;
            }
            else if (num%3 == 0)
            {
                num = num/3;
            }
            else
            {
                num = num/5;
            }
        }
        
        return 1;
    }
};


