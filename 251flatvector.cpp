//
//
//Implement an iterator to flatten a 2d vector. 
//
//For example,
// Given 2d vector = 
// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
//
//
//
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6]. 
//

class Vector2D {
    unordered_map<int, vector<int> > hash_map;
    int init_index = 0;

    int set_index = 0;
    int length = 0;
    
public:
    Vector2D(vector<vector<int>>& vec2d) 
    {
       for (int i = 0; i < vec2d.size(); i++)
       {
          hash_map[init_index++] = vec2d[i];
          length += vec2d[i].size();
       }
    }

    int next() 
    {
        if ( length == 0)
        {
            return 0;
        }
        while(hash_map[set_index].size() == 0)
        {
            set_index++;
        }
        
        int ret = hash_map[set_index][0];
        hash_map[set_index].erase(hash_map[set_index].begin());
        length--;
        return ret;
    }

    bool hasNext() 
    {
        return (length > 0);
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
