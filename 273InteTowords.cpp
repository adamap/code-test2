//
//
//Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1. 
//
//For example,
//
//123 -> "One Hundred Twenty Three"
//12345 -> "Twelve Thousand Three Hundred Forty Five"
//1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
//

string digit[20] = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine",
             "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
string digit1[10] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string digit2[10] = { "", "Thousand", "Million", "Billion" };

string getWord(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    string result;
    int remain = num % 100;
    num = num / 100;
    if (num > 0)
    {
        result += digit[num] + " Hundred";
    }
    if (remain == 0)
    {
        return result;
    }
    if (num > 0)
    {
        result += " ";
    }
    if (remain >= 20)
    {
        int temp = remain / 10;
        remain = remain % 10;
        result += digit1[temp];
  
        if (remain > 0)
        {
            result += " " + digit[remain];
        }
    }
    else
    {
        result += digit[remain];
    }
    return result;
}

class Solution {
public:
    string numberToWords(int num) 
    {
        if (num == 0)
        {
            return "Zero";
        }
        vector<string>result;
        int count = 0;
        while (num > 0)
        {
            int temp = num % 1000;
            string str = getWord(temp);
            if (str != "Zero")
            {
                if (count > 0)
                {
                    str += " " + digit2[count];
                }
                result.push_back(str);
            }
 
            num = num / 1000;
            ++count;
        }
        string ret;
        for (int i = result.size() - 1; i >= 0; i--)
        {
            ret += result[i];
            ret.push_back(' ');
        }
        ret.pop_back();
        return ret;
        
    }
};
