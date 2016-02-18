

//Divide two integers without using multiplication, division and mod operator. 
//
//If it is overflow, return MAX_INT. 
//
//
class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        int neg = 0;
        long long dividend_num = dividend, divisor_num = divisor;
        if ( dividend_num < 0 && divisor_num < 0)
        {
            dividend_num = -dividend_num;
            divisor_num = -divisor_num;
        }
        else if (dividend_num < 0)
        {
            dividend_num = -dividend_num;
            neg = 1;
        }
        else if (divisor_num < 0)
        {
            divisor_num = -divisor_num;
            neg = 1;
        }
        
        if ( divisor_num == 0)
        {
            return INT_MAX;
        }
        
        if (divisor_num == 1)
    {
    if (dividend_num >= INT_MAX)
    {
    return (neg == 1) ? INT_MIN : INT_MAX;
    }
    else
    {
    return (neg == 1) ? -dividend_num : dividend_num;
    }
    }
        
        if (dividend_num < divisor_num)
        {
            return 0;
        }
        else if (dividend_num == divisor_num)
        {
            return (neg == 1)?-1:1;
        }
        
        int result = 0;
        while(dividend_num >= divisor_num)
        {
            long long temp = 1;
            long long temp_divisor = divisor_num;
            while (dividend_num >= temp_divisor)
            {
                temp_divisor = temp_divisor*2;
                temp = temp*2;
            }
            result += temp/2;
            dividend_num -= temp_divisor/2; 
        }
        
        return (neg == 1)?(-result):result;
        
    }
};
