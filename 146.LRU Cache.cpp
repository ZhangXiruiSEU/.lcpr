/*
 * @lc app=leetcode id=146 lang=cpp
 * @lcpr version=30400
 *
 * [146] LRU Cache
 */

// @lc code=start

#include <list>
#include <unordered_map>
#include <utility>

class LRUCache
{
    list<pair<int, int>> data; // key, value
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;

  public:
    LRUCache(int n) : capacity(n)
    {
    }

    int get(int key)
    {
        // consider begin() is the recent one
        // because end() is the iterator after the last element
        // a little exhausting

        // try to find it in hash table
        auto mp_it = mp.find(key);
        // if found
        if (mp_it != mp.end())
        {
            data.splice(data.begin(), data, mp_it->second);
            return mp_it->second->second;
        }
        return -1;
    }
    void put(int key, int value)
    {
        auto mp_it = mp.find(key);
        // if found
        if (mp_it != mp.end())
        {
            mp_it->second->second = value;
            data.splice(data.begin(), data, mp_it->second);
        }
        else
        {
            if (data.size() == capacity)
            {
                mp.erase(data.back().first);
                data.pop_back();
            }
            data.push_front({key, value});
            mp[key] = data.begin();
        }
        
    }
};
/**
 * Your LRUCache ob ject will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

/*
// @lcpr case=start
//
["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]\n
// @lcpr case=end

 */
