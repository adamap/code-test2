//
//
//
//Implement atoi to convert a string to an integer.
//
class Solution {
public:
    int myAtoi(string str) 
    {
        int i = 0;
        while ( i < str.size() && str[i] == ' ')
        {
            i++;
        }
        if ( i == str.size())
        {
            return 0;
        }
        int neg = 0;
        if ( str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '-')
            {
               neg = 1;
            }
            i++;
        }
        
        if (i == str.size() || (str[i] > '9' || str[i] <'0'))
        {
            return 0;
        }
        
        long long result = 0;
        
        while( i < str.size() && (str[i] <= '9' && str[i] >='0'))
        {
            result = result*10+str[i]-'0';
            if ( result >= INT_MAX)
            {
                break;
            }
            i++;
        }
        
        if ( neg == 1)
        {
            if ( result > INT_MAX)
            {
                return INT_MIN;
            }
            else
            {
                return -result;
            }
        }
        else 
        {
            if (result >= INT_MAX )
            {
                return INT_MAX;
            }
            else
            {
                return result;
            }
        }
    }
};

