//Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set. 
//
//get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
//set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item. 

class LRUCache{
    list <pair<int, int>> cache;
    unordered_map<int, list <pair<int, int>>::iterator>lru_cache;
    int cache_size;
public:
    LRUCache(int capacity) 
    {
        cache_size = capacity;
    }
    
    int get(int key) 
    {
        if (lru_cache.find(key) == lru_cache.end())
        {
            return -1;
        }
        else
        {
            list <pair<int, int>>::iterator it = lru_cache[key];
            int val = it->first;
            cache.erase(it);
            lru_cache.erase(key);
            cache.push_front(make_pair(val, key));
            lru_cache[key] = cache.begin();
            return val;
        }
    }
    
    void set(int key, int value) 
    {
        if (lru_cache.find(key) == lru_cache.end())
        {
            if ( cache.size() == cache_size)
            {
                int todelete = cache.back().second;
                cache.pop_back();
                lru_cache.erase(todelete);
                cache.push_front(make_pair(value, key));
                lru_cache[key] = cache.begin();
            }
            else
            {
                cache.push_front(make_pair(value, key));
                lru_cache[key] = cache.begin();
            }
        }
        else
        {
            list <pair<int, int>>::iterator it = lru_cache[key];
            cache.erase(it);
            lru_cache.erase(key);
            cache.push_front(make_pair(value, key));
            lru_cache[key] = cache.begin();
        }
    }
};

void test_lru1()
{
  LRUCache cache(1);

  cache.set(2, 1);
  cache.get(2);
  cache.set(3, 2);
  cache.get(2);
  cache.get(3);
}

