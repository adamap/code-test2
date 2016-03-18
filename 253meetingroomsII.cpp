//
//
//Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
//For example,
// Given [[0, 30],[5, 10],[15, 20]],
//  return 2. 
//
//

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct comparator
{
    bool operator()(Interval a, Interval b)
    {
        return (a.start <= b.start);          
    }
};

int minMeetingRooms_pq(vector<Interval>& intervals)
{
    if ( intervals.size() == 0)
    {
        return 0;
    }
        
    sort(intervals.begin(), intervals.end(), comparator());
        
    // min head
    priority_queue<int, vector<int>, greater<int> >q;
    q.push(intervals[0].end);
     
    for (int i = 1; i < intervals.size(); i++)
    {
        if ( intervals[i].start < q.top())
        {
            q.push(intervals[i].end);
        }
        else
        {
            q.pop();
            q.push(intervals[i].end);
        }
    }
        
    return q.size();
}

struct point
{
    int time;
    int start;
    
    point(int s, int i):time(s),start(i)
    {
        
    }
};

struct comparatorp
{
    bool operator()(point *a, point *b)
    {
        if (a->time != b->time)
        {
            return (a->time < b->time);
        }
        else
        {
            // if endtime == starttime
            // put end first so we dont overcount
            return (a->start < b->start);
        }
    }
};

int minMeetingRooms_scan(vector<Interval>& intervals)
{
    if ( intervals.size() == 0)
    {
        return 0;
    }    
    
    vector<point *>p;

    for (int i = 0; i < intervals.size(); i++)
    {
        p.push_back(new point(intervals[i].start, 1));
        p.push_back(new point(intervals[i].end, 0));
    }
    
    sort(p.begin(), p.end(), comparatorp());
    
    int count  = 0;
    int max = INT_MIN;
    for ( int i = 0; i < p.size(); i++)
    {
        if (p[i]->start == 1)
        {
            count++;
        }
        else
        {
            count--;
        }
        if ( count > max)
        {
            max = count;
        }
    }
    return max;
}

/* similar solution in java as scanline approach, reference
public class Solution {
    public int minMeetingRooms(Interval[] intervals) {
        if (intervals == null || intervals.length == 0) {
            return 0;
        }
         
        int len = intervals.length;
        int[] startTime = new int[len];
        int[] endTime = new int[len];
         
        for (int i = 0; i < len; i++) {
            Interval curr = intervals[i];
            startTime[i] = curr.start;
            endTime[i] = curr.end;
        }
         
        // Sort the start and end time
        Arrays.sort(startTime);
        Arrays.sort(endTime);
         
        int activeMeetings = 0;
        int numMeetingRooms = 0;
         
        int i = 0;
        int j = 0;
         
        while (i < len && j < len) {
            if (startTime[i] < endTime[j]) {
                activeMeetings++;
                numMeetingRooms = Math.max(numMeetingRooms, activeMeetings);
                i++;
            } else {
                activeMeetings--;
                j++;
            }
        }
         
        return numMeetingRooms;
    }
}
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        //return minMeetingRooms_pq( intervals);
        return minMeetingRooms_scan( intervals);
    }
};
