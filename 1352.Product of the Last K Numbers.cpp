/*
 * @lc app=leetcode id=1352 lang=cpp
 * @lcpr version=30400
 *
 * [1352] Product of the Last K Numbers
 */

// @lc code=start
#include <vector>
class ProductOfNumbers
{
  public:
    std::vector<int> vec;
    std::vector<int> product{1};
    ProductOfNumbers()
    {
    }

    void add(int num)
    {
        vec.emplace_back(num);
        if (num != 0)
            product.emplace_back(num * product.back());
        else
            product.resize(1, 1);
    }

    int getProduct(int k)
    {
        if (k > product.size() - 1)
        {
            return 0;
        }
        else{
            return product.back()/ *(product.end()-1-k);
        }
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

/*
// @lcpr case=start
//
["ProductOfNumbers","add","add","add","add","add","getProduct","getProduct","getProduct","add","getProduct"]\n[[],[3],[0],[2],[5],[4],[2],[3],[4],[8],[2]]\n
// @lcpr case=end

 */
