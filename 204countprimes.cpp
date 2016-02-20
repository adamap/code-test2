//
//Description:
//
//Count the number of prime numbers less than a non-negative number, n.


//sieve algorithm to find all primes < n
class Solution {
public:
    int countPrimes(int n) 
    {
        if ( n <= 1)
        {
            return 0;
        }
        
        vector<int>isprimes(n, 1);
        
        for ( int i = 2; i < n; i++)
        {
            if(isprimes[i] == 1)
            {    
                for ( int j = 2; i*j < n; j++)
                {
                    isprimes[i*j] = 0;
                }
            }
        }
        
        int numofprimes = 0;
        for ( int i = 2; i < n; i++)
        {
            if (isprimes[i] == 1)
            {
                numofprimes++;
            }
        }
        return numofprimes;
    }
};
