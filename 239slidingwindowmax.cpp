//Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
//
//For example,
// Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
//      Therefore, return the max sliding window as [3,3,5,5,6,7].
//
ass Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
    
        deque<int>dque;
        vector<int>result;
        if ( nums.size() == 0 || k == 0)
        {
            return result;
        }
        
        for ( int i = 0; i < k; i++)
        {
            while( !dque.empty() && nums[dque.back()] < nums[i])
            {
                dque.pop_back();    
            }
            dque.push_back(i);
        }
        
        result.push_back(nums[dque.front()]);
        
        for ( int i = k; i < nums.size(); i++)
        {
            while (!dque.empty() && i - dque.front() >= k)
            {
                dque.pop_front();
            }
            
            while( !dque.empty() && nums[dque.back()] < nums[i])
            {
                dque.pop_back();    
            }
            dque.push_back(i);
            result.push_back(nums[dque.front()]);
        }
        
        return result;        
        
    }
    
};     
