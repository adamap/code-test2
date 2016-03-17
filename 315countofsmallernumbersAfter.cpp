//
//
//
//You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i]. 
//
//Example:
//Given nums = [5, 2, 6, 1]
//
//To the right of 5 there are 2 smaller elements (2 and 1).
//To the right of 2 there is only 1 smaller element (1).
//To the right of 6 there is 1 smaller element (1).
//To the right of 1 there is 0 smaller element.
//
//
//Return the array [2, 1, 1, 0]. 
//

// binary index tree implementation

class Solution_bit {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
        vector<int>clone(nums);
        int n = nums.size();
        bitree.resize(n + 1, 0);
        sort(clone.begin(), clone.end());
  
        unordered_map<int, int>hash_map;
        for (int i = 0; i < n; i++)
        {
            //i+1 so bitreeSum(hash_map[nums[i]]-1)dont need to check condition
            hash_map[clone[i]] = i+1;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            clone[i] = bitreeSum(hash_map[nums[i]]-1);
            bitreeUpdate(hash_map[nums[i]], 1);
        }
        return clone;   
    }
private:
    vector<int>bitree;
    void bitreeUpdate(int index, int val)
    {
        int n = bitree.size();
        
        while (index < n)
        {
            bitree[index] += val;
            index += index&(-index);
        }
    }
 
    int bitreeSum(int index)
    {
        int sum = 0;
        
        while (index > 0)
        {
            sum += bitree[index];
            index -= index&(-index);
        }
        return sum;
    }    
    
};

// merge sort implementation, use node to encapsulate data as we need to track in place
struct node {
  int val;
  int index;
  int count;
  
  node(int val, int index) : val(val), index(index), count(0) {}
  
  bool operator <= (const node &node2)const 
  {
    return val <= node2.val;
  }
};


void merge(vector<node>&clone, int l, int mid, int r, vector<node>&sort_nums)
{
    int left_start_pos = l;
    int right_start_pos = mid+1;
    int len = r-l+1;
    int sort_index = l;
    
    while(left_start_pos <= mid && right_start_pos <= r )
    {
        if ( clone[left_start_pos] <= clone[right_start_pos])
        {
            sort_nums[sort_index] = clone[left_start_pos];
            sort_nums[sort_index].count += right_start_pos - (mid+1);
            sort_index++;
            left_start_pos++;
        }
        else
        {
            sort_nums[sort_index++] = clone[right_start_pos++];
        }
    }
    
    while(left_start_pos <= mid)
    {
        sort_nums[sort_index] = clone[left_start_pos];
        sort_nums[sort_index].count += right_start_pos - (mid+1);
        sort_index++;
        left_start_pos++;
    }
    
    while(right_start_pos <= r)
    {
         sort_nums[sort_index++] = clone[right_start_pos++];
    }
    
    
    for (int i = l; i <= r; i++)
    {
         clone[i] = sort_nums[i];
    }
    
}


void merge_sort(vector<node>&clone, int l, int r, vector<node>&sort_nums)
{
    if ( l < r)
    {
        int mid = l+(r-l)/2;
        
        merge_sort(clone, l,     mid, sort_nums);
        merge_sort(clone, mid+1, r,   sort_nums);
        
        merge(clone, l, mid, r, sort_nums);
    }
    
}

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) 
    {
         vector<node>clone;
     
         for ( int i = 0 ; i < nums.size(); i++)
         {
             clone.push_back(node(nums[i], i));
         }
         
         vector<node>sort_nums(nums.size(), node(0,0));

         merge_sort(clone, 0, clone.size() - 1, sort_nums);
         
         vector<int>result(nums.size(), 0);
         
         for ( int i = 0; i < nums.size(); i++)
         {
             result[clone[i].index] = clone[i].count; 
         }
         
         return result;
    }
};

// bst insert implementation


/* java code, to do translate into c++
public class Solution {
    public List<Integer> countSmaller(int[] nums) {
        Integer[] result = new Integer[nums.length];
         
        BSTNode root = null;
        for (int i = nums.length - 1; i >= 0; i--) {
            root = insert(root, nums[i], i, result, 0);
        }
         
        return Arrays.asList(result);
    }
     
    private BSTNode insert(BSTNode root, int num, int i, Integer[] result, 
                           int preSum) {
        if (root == null) {
            root = new BSTNode(num, 0);
            result[i] = preSum;
            return root;
        } else if (root.val == num) {
            root.dup++;
            result[i] = preSum + root.numOfLeftNodes;
            return root;
        } else if (root.val > num) {
            root.numOfLeftNodes++;
            root.left = insert(root.left, num, i, result, preSum);
        } else {
            root.right = insert(root.right, num, i, result, 
                preSum + root.numOfLeftNodes + root.dup);
        }
         
        return root;
    }
     
    class BSTNode {
        int val;
        int dup = 1;
        int numOfLeftNodes;
        BSTNode left, right;
         
        BSTNode(int val, int numOfLeftNodes) {
            this.val = val;
            this.numOfLeftNodes = numOfLeftNodes;
        }
    }
}
*/




