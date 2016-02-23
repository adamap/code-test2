//Given a collection of intervals, merge all overlapping intervals.
//
//For example,
// Given [1,3],[2,6],[8,10],[15,18],
//  return [1,6],[8,10],[15,18]. 


struct comparator
{
    bool operator()(Interval a, Interval b)
    {
        if ( a.start != b.start)
        {
            return (a.start < b.start);
        }
        else
        {
            return (a.end < b.end);
        }
    }
};

//in-place 
vector<Interval> merge1(vector<Interval>& intervals) 
{
    if (0 == intervals.size())
    {
        return intervals;
    }
    
    sort(intervals.begin(), intervals.end(), comparator());
        
    for ( int i = 0; i < intervals.size(); i++)
    {
        int start = intervals[i].start;
        int end = intervals[i].end;
            
        for ( int j = i+1; j < intervals.size(); j++)
        {
            if ( intervals[j].start <= end)
            {
                start = min(start, intervals[j].start);
                end = max(end, intervals[j].end);
                intervals.erase(intervals.begin() + j);
                j--;
            }
            else
            {
                break;
            }
        }
        intervals[i].start = start;
        intervals[i].end = end;
    }
        
    return intervals;
}

//extra vector
vector<Interval> merge2(vector<Interval>& intervals) 
{
    if (0 == intervals.size())
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end(), comparator());
    
    vector<Interval>ret;
          
    for ( int i = 0; i < intervals.size(); i++)
    {
        if ( ret.empty() || ret.back().end < intervals[i].start)
        {
            ret.push_back(intervals[i]);
        }
        else
        {
            ret.back().end = max(ret.back().end, intervals[i].end);
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
    vector<Interval> merge(vector<Interval>& intervals) 
    {
        vector<Interval> ret = merge1( intervals); 
        return ret;
    }
};
