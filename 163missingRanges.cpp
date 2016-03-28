//
//
//Given a sorted integer array where the range of elements are [lower, upper] inclusive, return its missing ranges.
//
//For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"]. 
//

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) 
    {
        vector<string> result;
        for (int i = 0; i < nums.size() && nums[i] <= upper; i++)
        {
            while (nums[i] == lower && i < nums.size())
            {
                i++;
                lower++;
            }
            if (i == nums.size())
            {
                break;
            }
            if (nums[i] == lower + 1)
            {
                result.push_back(to_string(lower));
            }
            else
            {
                result.push_back(to_string(lower) + "->"+to_string(min(upper, nums[i]-1)));
            }
            lower = nums[i] + 1;
        }
        if (lower == upper)
        {
            result.push_back(to_string(lower));
        }
        else if (lower < upper)
        {
            result.push_back(to_string(lower) + "->" + to_string(upper));
        }
        return result;
    }
};
