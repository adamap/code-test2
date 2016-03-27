//Given two arrays of length m and n with digits 0-9 representing two numbers. Create the maximum number of length k <= m + n from digits of the two. The relative order of the digits from the same array must be preserved. Return an array of the k digits. You should try to optimize your time and space complexity. 
//
//Example 1:
//
//
//nums1 = [3, 4, 6, 5]
// nums2 = [9, 1, 2, 5, 8, 3]
//  k = 5
//   return [9, 8, 6, 5, 3] 
//
//   Example 2:
//
//
//   nums1 = [6, 7]
//    nums2 = [6, 0, 4]
//     k = 5
//      return [6, 7, 6, 0, 4] 
//
//      Example 3:
//
//
//      nums1 = [3, 9]
//       nums2 = [8, 9]
//        k = 3
//         return [9, 8, 9] 
//    
//
vector<int> maxNumber_arr(vector<int>nums, int len)
{
  vector<int>result;

  if (len == 0)
  {
    return result;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    int remain = nums.size() - i;
    while (result.size() > 0 && result.size() + remain > len && nums[i] > result[result.size() - 1])
    {
      result.pop_back();
    }

    if (result.size() < len)
    {
      result.push_back(nums[i]);
    }
  }

  return result;
}

int merge_cal(vector<int>r1, vector<int>r2, vector<int>&result_arr)
{
  int i = 0, j = 0;

  int result = 0;
  while (i < r1.size() && j < r2.size())
  {
    if (r1[i] > r2[j])
    {
      result_arr.push_back(r1[i]);
      result = result * 10 + r1[i];
      i++;
    }
    else if (r1[i] < r2[j])
    {
      result_arr.push_back(r2[j]);
      result = result * 10 + r2[j];
      j++;
    }
    else
    {
      int i_temp = i + 1, j_temp = j + 1;
      while (i_temp < r1.size() && j_temp < r2.size() && r1[i_temp] == r2[j_temp])
      {
        i_temp++;
        j_temp++;
      }
      if (i_temp == r1.size())
      {
        result_arr.push_back(r2[j]);
        result = result * 10 + r2[j];
        j++;
      }
      else if (j_temp == r2.size())
      {
        result_arr.push_back(r1[i]);
        result = result * 10 + r1[i];
        i++;
      }
      else
      {
        if (r1[i_temp] > r2[j_temp])
        {
          result_arr.push_back(r1[i]);
          result = result * 10 + r1[i];
          i++;
       }
       else
       {
         result_arr.push_back(r2[j]);
         result = result * 10 + r2[j];
         j++;
      }
     }
    }
  }
  while (i < r1.size())
  {
    result_arr.push_back(r1[i]);
    result = result * 10 + r1[i];
    i++;
  }
  while (j < r2.size())
  {
    result_arr.push_back(r2[j]);
    result = result * 10 + r2[j];
    j++;
  }
  return result;
}


bool greater_check(const vector<int> & a, int start1, const vector<int> &b, int start2) 
{
  for (; start1 < a.size() && start2 < b.size(); start1++, start2++) 
  {
    if (a[start1] > b[start2]) 
    {
      return true;
   } 
   if (a[start1] < b[start2]) 
   {
     return false;
   }
  }
  return start1 != a.size();
}


 vector<int> merge_cal1(vector<int>res1, vector<int>res2, int k, int &ret)
 {

  vector<int> res(k, 0);
  int pos1 = 0, pos2 = 0, tpos = 0;

  while (pos1 < res1.size() || pos2 < res2.size()) 
  {
    res[tpos] = greater_check(res1, pos1, res2, pos2) ? res1[pos1++] : res2[pos2++];
    ret = ret*10+res[tpos];
    tpos++;
  }

  return res;
}


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        int n1 = nums1.size(), n2 = nums2.size();
        
        vector<int> result_arr(k, 0); int max_ret = INT_MIN;
        for ( int i = 0; i <= k; i++)
        {
            if ( i > n1 || k-i > n2)
            {
                continue;
            }
            
            vector<int>r1 = maxNumber_arr(nums1, i);
            vector<int>r2 = maxNumber_arr(nums2, k-i);
            
            vector<int>temp;
            int result = 0;
            temp = merge_cal1(r1, r2, k, result);
            //if ( result > max_ret)
            //{
            //    result_arr = temp;
            //   max_ret = result;
            //}
            
            if (!greater_check(result_arr, 0, temp, 0))
            {
                result_arr = temp;
            }
        }
        
        return result_arr;
    }
};
