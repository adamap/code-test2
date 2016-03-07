//
//
//
//Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value. 
//
//Examples: 
//
//"123", 6 -> ["1+2+3", "1*2*3"] 
//"232", 8 -> ["2*3+2", "2+3*2"]
//"105", 5 -> ["1*0+5","10-5"]
//"00", 0 -> ["0+0", "0-0", "0*0"]
//"3456237490", 9191 -> []
//
//

void addOperators_helper(string num, int target, long curresult, long prevnum, string set, vector<string> &result) 
{
    if ( curresult == target && num.size() == 0)
    {
        result.push_back(set);
        return;
    }
    
    // pay attention to start/end position with respect to string length
    for ( int i = 1; i <= num.size(); i++)
    {
        string curstr = num.substr(0, i);
        if ( curstr.size() > 1 && curstr[0] == '0')
        {
            continue;
        }
        
        long long curnum = atol(curstr.c_str());
        
        string nextstr = num.substr(i);
        if (set.size() > 0)
        {
            addOperators_helper(nextstr, target, ((curresult-prevnum)+prevnum*curnum), prevnum*curnum, set+"*"+curstr, result);
            addOperators_helper(nextstr, target, (curresult+curnum), curnum, set+"+"+curstr, result);
            addOperators_helper(nextstr, target, (curresult-curnum), -curnum, set+"-"+curstr, result);
        }
        else
        {
            addOperators_helper(nextstr, target, curnum, curnum, curstr, result);
        }
    }
    
}

class Solution {
public:
    vector<string> addOperators(string num, int target) 
    {
        vector<string> result;
        if ( num.size() == 0)
        {
            return result;
        }
        string set;
        addOperators_helper(num, target, 0, 0, set, result);
        return result;
        
    }
};
