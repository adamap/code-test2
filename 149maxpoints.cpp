//Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) 
    {
        if ( 0 == points.size())
        {
            return 0;
        }
        int max_ret = 0;
        for ( int i = 0; i < points.size(); i++)
        {
            int veritcal = 0;
            int samepoint = 0;
            unordered_map<double, int>hash_map;
            int max_p = 0;
            for ( int j = 0; j < points.size(); j++)
            {
                if ( i == j)
                {
                    continue;
                }
                if ((points[i].y == points[j].y) && ( points[i].x == points[j].x))
                {
                    samepoint++;
                }
                else if (points[i].y == points[j].y)
                {
                    veritcal++;
                }
                else
                {
                    double p = (double)(points[i].x - points[j].x)/(points[i].y - points[j].y);
                    hash_map[p]++;
                    max_p = max(max_p, hash_map[p]);
                }
            }
            
            int maxpoints = max(samepoint+veritcal, samepoint+max_p)+1;
            max_ret = max(max_ret, maxpoints);
        }
        
        return max_ret;
        
    }
};
