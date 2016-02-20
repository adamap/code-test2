//
//Write a program to find the n-th ugly number. 
//
//Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers. 
//
//Note that 1 is typically treated as an ugly number. 
//

long long maxdivide2(long long i)
{
    while(i%2== 0)
    {
        i = i/2;
    }
    return i;
}

long long maxdivide3(long long i)
{
    while(i%3== 0)
    {
        i = i/3;
    }
    return i;
}

long long maxdivide5(long long i)
{
    while(i%5== 0)
    {
        i = i/5;
    }
    return i;
}

long long isuglynumber(long long i)
{
    i = maxdivide2(i);
    i = maxdivide3(i);
    i = maxdivide5(i);
    
    if ( i == 1)
    {
        return 1;
    }
    return 0;
}
// method1: exceed time limit
int nthUglyNumber1(int n)
{
    long long num = 0;
    int count = 0;
    while(count < n)
    {
        num++;
        if (1 == isuglynumber(num))
        {
            count++;
        }
    }
    return num;
}


// method2: priority queue + hash set, easy to understand
int nthUglyNumber2(int n)
{
    priority_queue<long long, vector<long long>,  greater<long long>>heap;
    unordered_set<long long>hash_set;
    int primes[3];
    primes[0] = 2;
    primes[1] = 3;
    primes[2] = 5;
    
    for ( int i = 0; i <= 2; i++)
    {
        heap.push(primes[i]);
        hash_set.insert(primes[i]);
    }
    
    long long min_element = 1;
    for (int i = 0; i < n-1; i++)
    {
        min_element = heap.top();
        heap.pop();
        
        for ( int j = 0; j <= 2; j++)
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

// same idea as method 2, use array and multiple indexs
int nthUglyNumber3(int n)
{
    if(n <= 0)  return 0;  
    int* nums = new int[n + 1]; nums[0] = 0; nums[1] = 1;  

    int pos2, pos3, pos5; pos2 = pos3 = pos5 = 1;  
    for(int i = 2; i <= n; i++) 
    {  
        if(nums[pos2]*2 <= nums[pos3]*3 && nums[pos2]*2 <= nums[pos5]*5) 
        {  
            nums[i] = nums[pos2]*2;  
            pos2 ++;  
            if(nums[i] % 3 == 0) pos3 ++;  
            if(nums[i] % 5 == 0) pos5 ++;  
        }  
        else if(nums[pos3]*3 <= nums[pos2]*2 && nums[pos3]*3 <= nums[pos5]*5) 
        {  
            nums[i] = nums[pos3]*3;  
            pos3 ++;  
            if(nums[i] % 2 == 0) pos2 ++;  
            if(nums[i] % 5 == 0) pos5 ++;  
        }  
        else 
        {  
            nums[i] = nums[pos5]*5;  
            pos5 ++;  
            if(nums[i] % 2 == 0) pos2 ++;  
            if(nums[i] % 3 == 0) pos3 ++;  
        }  
    }  
    return nums[n];  
}

class Solution {
public:
    int nthUglyNumber(int n) 
    {
        //int ret = nthUglyNumber1(n);
        //int ret = nthUglyNumber2(n);
        int ret = nthUglyNumber3(n);
        return ret;
    }
};
