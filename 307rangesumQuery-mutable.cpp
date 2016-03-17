//
//
//
//Given an integer array nums, find the sum of the elements between indices i and j (i<=j), inclusive.
//The update(i, val) function modifies nums by updating the element at index i to val. 
//Example:
//
//Given nums = [1, 3, 5]
//
//sumRange(0, 2) -> 9
//update(1, 2)
//sumRange(0, 2) -> 8
//
//
class NumArray_bit {

private:
    vector<int>&nums_;
    vector<int>bitree;
    
    int sumbitree(int index)
    {
        index++;
        int sum = 0;
        while (index > 0)
        {
            sum += bitree[index];
            index -= index&(-index);
        }
        return sum;
    }
 
    void updateBITree(int index, int val)
    {
        index++;
        while (index <= nums_.size())
        {
            bitree[index] += val;
            index += index&(-index);
        }
    }
    
public:
    NumArray_bit(vector<int> &nums):nums_(nums)
    {
        bitree.resize(nums_.size() + 1, 0);
        for (int i = 0; i < nums_.size(); i++)
        {
            updateBITree(i, nums_[i]);
        }
    }

    void update(int i, int val) 
    {
        if (val - nums_[i] != 0)
        {
            updateBITree(i, val - nums_[i]);
            nums_[i] = val;
        }
    }

    int sumRange(int i, int j) 
    {
        int sum = sumbitree(j);
        if (i > 0)
        {
            sum -= sumbitree(i - 1);
        }
        return sum;
    }
};

class segmentTree
{
public:
    int start, end;
    int sum;
    segmentTree *left, *right;
    segmentTree(int start, int end)
    {
         this->start = start;
        this->end = end;
        left = right = NULL;
    }
    segmentTree(int start, int end, int sum)
    {
        this->start = start;
        this->end = end;
        this->sum = sum;
        left = right = NULL;
    }
};

class NumArray
{
private:
    segmentTree *root;
    segmentTree *buildSegmentTree(vector<int> nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }
        if (start == end)
        {
            return new segmentTree(start, end, nums[start]);
        }
        segmentTree *root = new segmentTree(start, end);
        int mid = start + (end - start) / 2;
        root->left  = buildSegmentTree(nums, start, mid);
        root->right = buildSegmentTree(nums, mid+1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }
 
    int sumRange_helper(segmentTree *root, int start, int end)
    {
        if (root == NULL || end < root->start || start > root->end || start > end)
        {
            return 0;
        }
        if (start <= root->start && end >= root->end)
        {
            return root->sum;
        }
        int mid = root->start + (root->end - root->start) / 2;
        return sumRange_helper(root->left, start, min(end, mid)) + sumRange_helper(root->right, max(start, mid + 1), end);
    }
    
    void updateRange_helper(segmentTree *root, int index, int val)
    {
        if (root == NULL)
        {
            return;
        }
        int mid = root->start + (root->end - root->start) / 2;
        
        if (index <= mid)
        {
            updateRange_helper(root->left, index, val);
        }
        else
        {
            updateRange_helper(root->right, index, val);
        }
        
        if (root->start == root->end && root->end == index)
        {
            root->sum = val;
            return;
        }
        
        root->sum = root->left->sum + root->right->sum;
    }    

public:
    NumArray(vector<int> &nums)
    {
        if (0 == nums.size())
        {
            return;
        }
        root = buildSegmentTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) 
    {
        updateRange_helper(root, i, val);
    }

    int sumRange(int i, int j) 
    {
        return sumRange_helper(root, i, j);
    }
    
};

// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
