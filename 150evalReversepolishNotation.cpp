//
//
//
//
//
//
//Evaluate the value of an arithmetic expression in Reverse Polish Notation. 
//
//Valid operators are +, -, *, /. Each operand may be an integer or another expression. 
//
//Some examples:
//
//  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//
//
//

int isoperator(string str)
{
    if ( str == "+" || str == "-" || str == "*" || str == "/")
    {
        return 1;
    }
    return 0;
}

int calcproc(int s1, int s2, string oper)
{
    int temp;
    
    if ( oper == "+")
    {
        temp = s1+s2;
    }
    if ( oper == "-")
    {
        temp = s1-s2;
    }
    if ( oper == "*")
    {
        temp = s1*s2;
    }
    if ( oper == "/")
    {
        temp = s1/s2;
    }
    return temp;
}

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>stk;
        
        for ( int i = 0; i < tokens.size(); i++)
        {
            if (1 == isoperator(tokens[i]))
            {
                int s2 = stk.top();
                stk.pop();
                int s1 = stk.top();
                stk.pop();
                int result = calcproc(s1, s2, tokens[i]);
                stk.push(result);
            }
            else
            {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();        
    }
};
