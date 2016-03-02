//
//
//
//
//Given a non-negative number represented as an array of digits, plus one to the number.
//
//The digits are stored such that the most significant digit is at the head of the list.

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        reverse(digits.begin(), digits.end());
        
        int temp = 0, carry = 1;
        
        for (int i = 0; i < digits.size(); i++)
        {
            temp = digits[i]+carry;
            digits[i] = temp%10;
            carry = temp/10;
        }
        if ( carry == 1)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
