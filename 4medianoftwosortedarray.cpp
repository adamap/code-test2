//There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).



int findkthSortedArrays(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k)
{
    
    if ( start1 > end1)
    {
        return nums2[start2+k-1];
    }
    
    if ( start2 > end2)
    {
        return nums1[start1+k-1];
    }
    
    if ( 1 == k)
    {
        return (nums1[start1] > nums2[start2])?nums2[start2]:nums1[start1];
    }

    int len1 = end1-start1+1;
    int len2 = end2-start2+1;
    
    int mid1 = (len1>=k/2)?nums1[start1+k/2-1]:INT_MAX;
    int mid2 = (len2>=k/2)?nums2[start2+k/2-1]:INT_MAX;
    
    
    if ( mid1 > mid2)
    {
        return findkthSortedArrays(nums1, start1, end1, nums2, start2+k/2, end2, (k-k/2));
    }
    else
    {
        return findkthSortedArrays(nums1, start1+k/2, end1, nums2, start2, end2, (k-k/2));
    }
}


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        if ( (len1+len2)%2 == 0)
        {
            int total_len = len1+len2;
            int m1 = findkthSortedArrays(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, total_len/2);
            int m2 = findkthSortedArrays(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, total_len/2+1);
            
            return (double)(m1+m2)/2.0f;
        }
        else
        {
            int total_len = len1+len2;
            int m1 = findkthSortedArrays(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, total_len/2+1);
            
            return m1;
        }
    }
};
