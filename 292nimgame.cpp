//
//You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones. 
//
//Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap. 
//
//For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend. 
//
//


bool canWinNim_direct(int n) 
{
    return (n%4);
}

// use dp to simulate how players play this game
// tle, not sure how to optimize
bool canWinNim_dp(int n) 
{
    vector<char>dp(n+1, 0);
    
    if ( n== 1)
    {
        dp[1] = 1;        
    }
    else if ( n == 2)
    {
        dp[1] = dp[2] = 1;
    }
    else if (n == 3)
    {
        dp[1] = dp[2] = dp[3] = 1;
    }
    else if ( n == 4)
    {
        dp[1] = dp[2] = dp[3] = 1;
        dp[4] = 0;
    }
    else if ( n == 5)
    {
        dp[1] = dp[2] = dp[3] = dp[5] = 1;
        dp[4] = 0;
    }
    else if ( n == 6)
    {
        dp[1] = dp[2] = dp[3] = dp[5] = dp[6] = 1;
        dp[4] = 0;
    }
    
    if ( n > 6)
    {
        dp[1] = dp[2] = dp[3] = dp[5] = dp[6] = 1;
dp[4] = 0;
        for ( int i = 7; i <= n; i++)
        {
            dp[i] = ((dp[i - 2]&&dp[i - 3]&&dp[i - 4]) || (dp[i - 3]&&dp[i - 4]&&dp[i - 5]) || (dp[i - 4]&&dp[i - 5]&&dp[i - 6]));
        }
    }
    
    return dp[n];
}

class Solution {
public:
    bool canWinNim(int n) 
    {
       
        return canWinNim_direct(n);
        //return canWinNim_dp(n);
    }
};
