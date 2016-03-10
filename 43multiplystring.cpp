//
//
//
//Given two numbers represented as strings, return multiplication of the numbers as a string.
//
//Note: The numbers can be arbitrarily large and are non-negative.
//

class Solution {
public:
    string multiply(string num1, string num2) 
    {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        vector<int>result(num1.size()+num2.size(), 0);
        
        
        for ( int i = 0; i < num1.size(); i++)
        {
            int j; int carry = 0; 
            for (j  = 0; j < num2.size(); j++)
            {
                int temp = (num1[i]-'0')*(num2[j]-'0')+carry+ result[i + j];
                result[i+j] = temp%10;
                carry = temp/10;
            }
            result[i+j] = carry;
        }
        
        reverse(result.begin(), result.end());
        
        string ret;
        int i = 0;
        
        while(i < result.size()-1 && result[i] == 0)
        {
            i++;
        }
        
        for ( ; i < result.size(); i++)
        {
            ret.push_back(result[i]+'0');
        }
        return ret;
    }
};
