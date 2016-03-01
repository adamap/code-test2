



//
//
//
//Majority Element II
// My Submissions 
// Question 
//
// Total Accepted: 23290 Total Submissions: 92335 Difficulty: Medium 
//
//
//
//
//
// Given an integer array of size n, find all elements that appear more than ? n/3 ? times. The algorithm should run in linear time and in O(1) space.
//
//

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
      vector<int>result;
      if (nums.size() < 1)
      {
         return result;
      } 
      int number1 = 0, number2 = 0, count1 = 0, count2 = 0;

      for (int i = 0; i < nums.size(); i++)
      {
        // following orders are important
        if (nums[i] == number1)
        {
          count1++;
        }    
        else if (nums[i] == number2)
        { 
          count2++;
        }
        else if (count1 == 0)
        {
          number1 = nums[i];
          count1 = 1;
        }
        else if (count2 == 0)
        {
          number2 = nums[i];
          count2 = 1;
        }
        else if (nums[i] != number2 && nums[i] != number1)
        {
          count1--;
          count2--;
        }
     }
 
     count1 = count2 = 0;

     for (int i = 0; i < nums.size(); i++)
     {
       if (nums[i] == number1)
       {
         count1++;
       }
       else if (nums[i] == number2)
       {
         count2++;
       }
     }
     if (count1 > nums.size() / 3)
     { 
        result.push_back(number1);
     }
     if (count2 > nums.size() / 3)
     {
        result.push_back(number2);
     }
      return result;
    }
};
