//Implement strStr(). 
//
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack. 
//
//

class Solution {
public:
    int strStr(string haystack, string needle) 
    {
  
        for ( int i = 0; i <= (int)(haystack.size()-needle.size()); i++)
        {
            int i_index = i, j_index= 0;
            
            while( j_index < needle.size() && (haystack[i_index] == needle[j_index] ))
            {
                j_index++;
                i_index++;
            }
            
            if ( j_index == needle.size())
            {
                return i;
            }
        }
        
        return -1;
    }
};
