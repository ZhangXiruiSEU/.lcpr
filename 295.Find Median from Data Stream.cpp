/*
 * @lc app=leetcode id=295 lang=cpp
 * @lcpr version=30400
 *
 * [295] Find Median from Data Stream
 */

// @lc code=start
class MedianFinder
{
    // 这个直接抄答案 要注意复习
    priority_queue<int> small;
    priority_queue<int, vector<int>, greater<>> large;

  public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (small.size() >= large.size())
        {
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        else
        {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }


    double findMedian() {
        // 如果元素不一样多，多的那个堆的堆顶元素就是中位数
        if (large.size() < small.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        }
        // 如果元素一样多，两个堆堆顶元素的平均数是中位数
        return (double)(large.top() + small.top())/ 2.0; 
    }
};

    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */
    // @lc code=end

    /*
    // @lcpr case=start
    // ["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]\n
    // @lcpr case=end

     */
