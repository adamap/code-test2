//
//
//You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner. 
//
//Write a function to determine if the starting player can guarantee a win. 
//
//For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+". 
//
//Follow up:
// Derive your algorithm's runtime complexity. 
//



int canWin_helper(string &s)
{
    for ( int i = 0; i < s.length()-1; i++)
    {
        if ( s[i] == '+' && s[i+1] == '+')
        {
            s[i]   = '-';
            s[i+1] = '-';
            int canp1win = !canWin_helper(s);
            s[i]   = '+';
            s[i+1] = '+';
            if (1 == canp1win)
            {
                return 1;
            }
        }
    }
    return 0;    
}

// use memorization to speed up
int canWin_helper_mem(string &s, unordered_map<string, int>&hash_map)
{
    
    for ( int i = 0; i < s.length()-1; i++)
    {
        if ( s[i] == '+' && s[i+1] == '+')
        {
            s[i]   = '-';
            s[i+1] = '-';
            
            if ( hash_map.find(s) == hash_map.end())
            {
                int canp1win = !canWin_helper_mem(s, hash_map);
                hash_map[s] = canp1win;
            }
           
            string temp = s;
            s[i]   = '+';
            s[i+1] = '+';
            
            if ( hash_map[temp] == 1)
            {
                return 1;
            }
        }
    }
    return 0;    
}

class Solution {
public:
    bool canWin(string s) 
    {
        if ( s.length() == 0)
        {
            return 0;
        }
        unordered_map<string, int>hash_map;
        //return canWin_helper(s);
        return canWin_helper_mem(s, hash_map);
    }
};
