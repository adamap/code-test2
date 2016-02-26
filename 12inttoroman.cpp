//Given an integer, convert it to a roman numeral. 
//
//Input is guaranteed to be within the range from 1 to 3999.
//


class Solution {
public:
    string intToRoman(int num) 
    {
        string result;
        if (num == 0)
        {
            return result;
        }
        //I:1, V:5, X:10, L:50, C:100, D:500, M:1000
        char s[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        
        int scale = 1000;
        for ( int i = 0; i <7; i+=2)
        {
            int j = num/scale;
            
            if (j != 0)
            {
                if ( j <= 3)
                {
                    result.append(j, s[i]);
                }
                else if ( j == 4)
                {
                    result.append(1, s[i]);
                    result.append(1, s[i-1]);
                }
                else if ( j == 5)
                {
                    result.append(1, s[i-1]);
                }
                else if ( j <= 8)
                {
                    result.append(1, s[i-1]);
                    result.append(j-5, s[i]);
                }
                else if ( j == 9)
                {
                    result.append(1, s[i]);
                    result.append(1, s[i-2]);
                }
            }

            num = num%scale;
            scale = scale/10;
        }
        
        return result;
        
        
    }
};
