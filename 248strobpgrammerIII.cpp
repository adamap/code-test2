//
//
//A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
//Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
//
//For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers. 
//
// Note:
//  Because the range might be a large number, the low and high numbers are represented as string. 
//

void strobogrammaticInRange_helper(string low, string high, string set, int len, int &result)
{
    if ( set.length() >= len)
    {
        if( set.length() > len || len != 1 && set[0] == '0')
        {
            return;
        }
        
        if (( len == low.length() && set.compare(low) < 0 ) || ( len == high.length() && set.compare(high) > 0 ))
        {
            return;
        }
        result++;
    }
    
    strobogrammaticInRange_helper(low, high, "0"+set+"0", len, result);
    strobogrammaticInRange_helper(low, high, "1"+set+"1", len, result);
    strobogrammaticInRange_helper(low, high, "8"+set+"8", len, result);
    strobogrammaticInRange_helper(low, high, "6"+set+"9", len, result);
    strobogrammaticInRange_helper(low, high, "9"+set+"6", len, result);
    
}



class Solution {
public:
    int strobogrammaticInRange(string low, string high) 
    {
        int result = 0;
        
        for ( int len = low.length(); len <= high.length(); len++)
        {
            strobogrammaticInRange_helper(low, high, "",len, result);
            strobogrammaticInRange_helper(low, high, "0",len, result);
            strobogrammaticInRange_helper(low, high, "1",len, result);
            strobogrammaticInRange_helper(low, high, "8",len, result);
        }
        
        return result;
    }
};
