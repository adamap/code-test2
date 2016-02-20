//
//
//Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
//Examples: 
//
//[2,3,4] , the median is 3
//
//[2,3], the median is (2 + 3) / 2 = 2.5 
//
//Design a data structure that supports the following two operations: 
//void addNum(int num) - Add a integer number from the data stream to the data structure.
//double findMedian() - Return the median of all elements so far.
//
//For example:
//add(1)
//add(2)
//findMedian() -> 1.5
//add(3) 
//findMedian() -> 2
//
//

class MedianFinder {
    priority_queue<int, vector<int>>max_heap;
    priority_queue<int, vector<int>, greater<int>>min_heap;
    int median;
    int median_inited = 0;
    
public:

    // Adds a number into the data structure.
    void addNum(int num) 
    {
        if (max_heap.size() == 0 || min_heap.size() == 0 )
        {
            if (median_inited == 0)
            {
                median = num;
                median_inited = 1;
            }
            else
            {
                if ( num > median)
                {
                    if (max_heap.size() == 0)
                    {
                        max_heap.push(median);
                        min_heap.push(num);
                        median = min_heap.top();
                        min_heap.pop(); 
                    }
                    else
                    {
                        min_heap.push(num);
                    }
                }
                else
                {                    
                    if (max_heap.size() == 0)
                    {
                        max_heap.push(num);
                    }
                    else
                    {
                        min_heap.push(median);
                        max_heap.push(num);
                        median = max_heap.top();
                        max_heap.pop(); 
                    }
                }
            }
        }
        else
        {
            if ( num > median)
            {
                if ( max_heap.size() == min_heap.size())
                {
                    max_heap.push(median);
                    min_heap.push(num);
                    median = min_heap.top();
                    min_heap.pop();
                }
                else
                {
                    min_heap.push(num);
                }
            }
            else
            {
                if ( max_heap.size() == min_heap.size())
                {
                    max_heap.push(num);
                }
                else
                {
                    min_heap.push(median);
                    max_heap.push(num);
                    median = max_heap.top();
                    max_heap.pop();
                }
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() 
    {
        if (max_heap.size() == min_heap.size() || max_heap.size() == 0)
        {
            return median;
        }
        else
        {
            return ((double)(max_heap.top()+median)/2.0f);
        }
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
