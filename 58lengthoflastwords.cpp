//
//
//
//Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non-space characters only.
//
//For example, 
// Given s = "Hello World",
//  return 5. 
//


class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int j = s.size()-1;
        
        int i = j; int found = 0;
        while ( j >= 0)
        {
            if(s[j] == ' ')
            {
                if (found == 0)
                {
                    j--;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(found == 0)
                {
                    i=j;
                    found = 1;
                }
                j--;
            }
        }
        if ( found == 1)
        {
            return i-j;
        }
        else
        {
            return 0;
        }
    }
};
