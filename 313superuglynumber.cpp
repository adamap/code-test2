//Write a program to find the nth super ugly number. 
//
//Super ugly numbers are positive numbers whose all prime factors are in the given prime list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32]  is the sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4. 
//
//Note:
// (1) 1 is a super ugly number for any given primes.
// (2) The given numbers in primes are in ascending order.
// (3) 0 < k ¡ 100, 0 < n ¡ 106, 0 < primes[i] < 1000. 
//
//time limit exceed
int nthUglyNumber3(int n, vector<int>& primes)
{
    priority_queue<long long, vector<long long>,  greater<long long>>heap;
    unordered_set<long long>hash_set;

    for ( int i = 0; i < primes.size(); i++)
    {
        heap.push(primes[i]);
        hash_set.insert(primes[i]);
    }
    
    long long min_element = 1;
    for (int i = 0; i < n-1; i++)
    {
        min_element = heap.top();
        heap.pop();
        
        for ( int j = 0; j < primes.size(); j++)
        {
            if ( hash_set.find(primes[j]*min_element) == hash_set.end())
            {
                hash_set.insert(primes[j]*min_element);
                heap.push(primes[j]*min_element);
            }
            
        }
    }
    
    return min_element;
}

int nthUglyNumber5(int n, vector<int>& primes)
{
    int k = primes.size();  
    vector<int> pos(k, 0);  
    vector<int> ugly(n, INT_MAX);  
    ugly[0] = 1;  
          
    for(int i = 1; i< n; i++)  
    {  
        for(int j = 0; j < k; j++)  
        {
            ugly[i] = (ugly[i] < ugly[pos[j]] * primes[j]) ? ugly[i] : (ugly[pos[j]] * primes[j]);  
        }
        
        for(int j = 0; j < k; j++)  
            if(ugly[i] == ugly[pos[j]] * primes[j]) pos[j]++;  
    }  
    return ugly[n - 1];  
}

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) 
    {
        //return nthUglyNumber3(n, primes);
        return nthUglyNumber5( n,  primes);
    }
};
