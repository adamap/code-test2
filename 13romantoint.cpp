//
//Given a roman numeral, convert it to an integer.
//
//Input is guaranteed to be within the range from 1 to 3999.
//



//I:1, V:5, X:10, L:50, C:100, D:500, M:1000
int ctoi(char c)
{
    switch(c)
    {
        case 'I':
        return 1;

        case 'V':
        return 5;

        case 'X':
        return 10;

        case 'L':
        return 50;

        case 'C':
        return 100;

        case 'D':
        return 500;

        case 'M':
        return 1000;
        
        default:
        return 0;
    }
}

class Solution {
public:
    int romanToInt(string s) 
    {
        if (0 == s.size())
        {
            return 0;
        }
        int ret = 0;
        for ( int i = 0; i < s.size(); i++)
        {
            if (i>0 && ctoi(s[i]) > ctoi(s[i-1]))
            {
                ret += ctoi(s[i])-2*ctoi(s[i-1]);
            }
            else
            {
                ret += ctoi(s[i]);
            }
        }
        return ret;
    }
};





