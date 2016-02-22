//Given a list of non negative integers, arrange them such that they form the largest number.
//
//For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//
struct comparator
{
  bool operator()(string a, string b)
  {
      return ((a+b).compare(b+a) > 0);
  }
    
};


class Solution {
public:
    string largestNumber(vector<int>& nums) 
    {
        vector<string>strset;
        
        for ( int i = 0; i < nums.size(); i++)
        {
            ostringstream is;
            is << nums[i];
            strset.push_back(is.str());
        }
        
        sort(strset.begin(), strset.end(), comparator());
        
        string ret;
        
        for ( int i = 0; i < strset.size(); i++)
        {
            ret += strset[i];
        }
        
        int index = 0;
        while ( index < ret.size() && ret[index] == '0')
        {
            index++;
        }
        if ( index == ret.size())
        {
            return "0";
        }
        return ret;
    }
};
