//
//
//
//
//Given a sorted integer array without duplicates, return the summary of its ranges.
//
//For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].




class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
      int i = 0, j = 1;
      vector<string> result;
      if ( 0 == nums.size( ))
      {
         return result;
      }

      while (j < nums.size())
      {
        if (nums[j] == nums[i] + j - i)
        {
          j++;
        }
        else
        { 
          if (i == j - 1)
          {
            ostringstream is;
            is<<nums[i];
            result.push_back(is.str());
          }
          else
          {
            string set;
            ostringstream is1;
            is1<<nums[i];
            set.append(is1.str());
            set.append("->");
            ostringstream is2;
            is2<<nums[j-1];
            set.append(is2.str());
            result.push_back(set);
          }
          i = j;
        }
     }

     if (i == j - 1)
     {
       ostringstream is;
       is<<nums[i];
       result.push_back(is.str());
     }
     else
     {
       string set;
       ostringstream is1;
       is1<<nums[i];
       set.append(is1.str());
       set.append("->");
       ostringstream is2;
       is2<<nums[j-1];
       set.append(is2.str());
       result.push_back(set);
     } 

      return result;
    }
};
