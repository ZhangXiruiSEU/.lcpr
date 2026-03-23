/*
 * @lc app=leetcode id=146 lang=cpp
 * @lcpr version=30400
 *
 * [146] LRU Cache
 */

// @lc code=start

namespace diy
{
class DoublyListNode
{
  public:
    // friend class myDoublyList;
    int key, val;
    DoublyListNode *next;
    DoublyListNode *prev;

    DoublyListNode(int _key, int _val) : key(_key), val(_val) {};
};

class myDoublyList
{

    DoublyListNode *head;
    DoublyListNode *tail;
    int size;

  public:
    myDoublyList() : size(0)
    {
        // 初始化双向链表的数据
        head = new DoublyListNode(0, 0);
        tail = new DoublyListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    void addLast(DoublyListNode *x)
    {
        x->prev = tail->prev;
        x->next = tail;
        tail->prev->next = x;
        tail->prev = x;
        size++;
    }

    // 删除链表中的 x 节点（x 一定存在）
    // 由于是双链表且给的是目标 Node 节点，时间 O(1)
    void remove(DoublyListNode *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        size--;
    }

    // 删除链表中第一个节点，并返回该节点，时间 O(1)
    DoublyListNode *removeFirst()
    {
        if (head->next == tail)
            return nullptr;
        DoublyListNode *first = head->next;
        remove(first);
        return first;
    }
    // 返回链表长度，时间 O(1)
    int getSize()
    {
        return size;
    }
};
} // namespace diy

class LRUCache
{

    // key -> Node(key, val)
    unordered_map<int, diy::DoublyListNode *> map;
    // Node(k1, v1) <-> Node(k2, v2)...
    diy::myDoublyList cache;
    // 最大容量
    int cap;

  public:
    LRUCache(int capacity) : cap(capacity)
    {
    }
    // 将某个 key 提升为最近使用的
    void makeRecently(int key)
    {
        diy::DoublyListNode *x = map[key];
        // 先从链表中删除这个节点
        cache.remove(x);
        // 重新插到队尾
        cache.addLast(x);
    }

    // 添加最近使用的元素
    void addRecently(int key, int val)
    {
        diy::DoublyListNode *x = new diy::DoublyListNode(key, val);
        // 链表尾部就是最近使用的元素
        cache.addLast(x);
        // 别忘了在 map 中添加 key 的映射
        map[key] = x;
    }

    // 删除某一个 key
    void deleteKey(int key)
    {
        diy::DoublyListNode *x = map[key];
        // 从链表中删除
        cache.remove(x);
        // 从 map 中删除
        map.erase(key);
    }
    // 删除最久未使用的元素
    void removeLeastRecently()
    {
        // 链表头部的第一个元素就是最久未使用的
        diy::DoublyListNode *deletedNode = cache.removeFirst();
        // 同时别忘了从 map 中删除它的 key
        int deletedKey = deletedNode->key;
        map.erase(deletedKey);
    }

    int get(int key)
    {
        if (!map.count(key))
        {
            return -1;
        }
        // 将该数据提升为最近使用的
        makeRecently(key);
        return map[key]->val;
    }

    void put(int key, int val)
    {
        if (map.count(key))
        {
            // 删除旧的数据
            deleteKey(key);
            // 新插入的数据为最近使用的数据
            addRecently(key, val);
            return;
        }

        if (cap == cache.getSize())
        {
            // 删除最久未使用的元素
            removeLeastRecently();
        }
        // 添加为最近使用的元素
        addRecently(key, val);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
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
