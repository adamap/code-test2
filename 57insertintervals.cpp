//
//Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
//You may assume that the intervals were initially sorted according to their start times.
//
//Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9]. 
//
// Example 2:
//  Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16]. 
//
//  This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10]. 

vector<Interval> insert1(vector<Interval>& intervals, Interval newInterval)
{
    int start = newInterval.start;
    int end = newInterval.end;
    int insert = 1;
    int j;
    for (j = 0; j < intervals.size(); j++)
    {
       if (intervals[j].start <= start && intervals[j].end >= end)
       {
         insert = 0;
         break;
       }
       else if (intervals[j].start > end)
       {
         break;
       }
       else if (intervals[j].end < start )
      {
        continue;
      }
      else if (intervals[j].start <= end && intervals[j].end >= start)
      {
        start = min(start, intervals[j].start);
        end = max(end, intervals[j].end);
        intervals.erase(intervals.begin() + j);
        j--;
      }
   }

  if (insert == 1)
  {
    newInterval.start = start;
    newInterval.end = end;
    intervals.insert(intervals.begin() + j, newInterval);
  }
  return intervals;
}

vector<Interval> insert2(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> ret;
    int start = newInterval.start;
    int end = newInterval.end;
    int i;
    for (i = 0; i < intervals.size(); )
    {
      if ( intervals[i].end < start)
      {
        i++;
        continue;
      }
      if ( intervals[i].start > end)
      {
        break;
      }
      start = min(start, intervals[i].start);
      end = max(end, intervals[i].end);
      intervals.erase(intervals.begin() + i);
    }

   newInterval.start = start;
   newInterval.end = end;
   intervals.insert(intervals.begin() + i, newInterval);

   return intervals;
}

vector<Interval> insert3(vector<Interval>& intervals, Interval newInterval)
{
    vector<Interval> ret;
    ret.push_back(newInterval);
    
    for ( int  i = 0; i < intervals.size(); i++)
    {
        Interval neww = ret.back();
        ret.pop_back();
        Interval curr = intervals[i];
        
        if ( curr.end < neww.start)
        {
            ret.push_back(curr);
            ret.push_back(neww);
        }
        else if ( curr.start > neww.end)
        {
            ret.push_back(neww);
            ret.push_back(curr);
        }
        else
        {
        neww.start = min(neww.start, curr.start);
    neww.end = max(neww.end, curr.end);
            ret.push_back(neww);    
        }
    }
    
    return ret;
  
}
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    return insert3(intervals, newInterval);
}
};



