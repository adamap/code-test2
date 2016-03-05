//
//
//
//
//
//
//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses. 
//
//For example, given n = 3, a solution set is: 
//
//"((()))", "(()())", "(())()", "()(())", "()()()" 
//
//
//





void generateParenthesis_helper(int left, int right, vector<string>&result, string set)
{
    if ( left > right)
    {
        return;
    }
    
    if ( left == 0 && right == 0)
    {
        result.push_back(set);
        return;
    }
    
    if ( left == right)
    {
        generateParenthesis_helper(left-1, right, result, set+"(");
    }
    else 
    {
        if ( left >= 1)
        {
            generateParenthesis_helper(left-1, right, result, set+"(");
        }
        generateParenthesis_helper(left, right-1, result, set+")");
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        vector<string>result;
        
        string set;
        
        generateParenthesis_helper(n, n, result, set);
        
        return result;
    }
};
