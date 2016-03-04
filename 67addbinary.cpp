//
//
//Given two binary strings, return their sum (also a binary string). 
//
//For example,
//  a = "11"
//  b = "1"
//  Return "100". 
//
//


class Solution {
public:
    string addBinary(string a, string b) 
    {
        int n = a.size(), m = b.size();
        
        int i = 0, j = 0;
        
        int carry = 0;
        int temp = 0;
        string ret;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        while(i < n && j < m)
        {
            temp = a[i]-'0' + b[j]-'0' + carry;
            carry = temp/2;
            temp = temp%2;
            ret.push_back(temp+'0');
            i++;
            j++;
        }

        while(i < n)
        {
            temp = a[i]-'0' + carry;
            carry = temp/2;
            temp = temp%2;
            ret.push_back(temp+'0');
            i++;
        }
        while(j < m)
        {
            temp = b[j]-'0' + carry;
            carry = temp/2;
            temp = temp%2;
            ret.push_back(temp+'0');
            j++;
        }
        if ( carry)
        {
            ret.push_back(carry+'0');
        }
        reverse(ret.begin(), ret.end());
        return ret;

    }
};
