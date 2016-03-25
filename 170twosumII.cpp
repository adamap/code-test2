//
//
//
//Design and implement a TwoSum class. It should support the following operations: add and find.
//
//add - Add the number to an internal data structure.
//find - Find if there exists any pair of numbers which sum is equal to the value. 
//
//For example,
//
//add(1); add(3); add(5);
//find(4) -> true
//find(7) -> false
//
//
//

class TwoSum 
{
    unordered_map<int, int>hash_map;
public:

    // Add the number to an internal data structure.
void add(int number) 
{
    hash_map[number]++;
}

    // Find if there exists any pair of numbers which sum is equal to the value.
bool find(int value) 
{
    unordered_map<int, int>::iterator it;
    for (it = hash_map.begin(); it != hash_map.end(); it++)
    {
        int diff = value - it->first;
        
        if ( hash_map.find(diff) != hash_map.end())
        {
            if ( diff != it->first)
            {
                return 1;
            }
            else 
            {
                if ( it->second >= 2)
                {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);
