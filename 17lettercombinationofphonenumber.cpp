//Given a digit string, return all possible letter combinations that the number could represent. 

//A mapping of digit to letters (just like on the telephone buttons) is given below.
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].


void letterCombinations_helper(string digits, string keypad[], int index, string set, vector<string> &result)
{
    if ( index == digits.size())
    {
        if (set.size() == digits.size()&&set.size() > 0)
        {
            result.push_back(set);
        }
        return;
    }
    
    for ( int i = index; i < digits.size(); i++)
    {
        for ( int j = 0; j < keypad[digits[i]-'0'-2].size();j++)
        {
            set.push_back(keypad[digits[i]-'0'-2][j]);
            letterCombinations_helper(digits, keypad, i+1, set, result);
            set.pop_back();
        }
    }
    
}

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        
        string keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        vector<string>result;
        
        string set;
        
        letterCombinations_helper(digits, keypad, 0, set, result);
        
        return result;
        
    }
};
