/*
 * @lc app=leetcode id=509 lang=cpp
 * @lcpr version=30304
 *
 * [509] Fibonacci Number
 */
#include <vector>
// @lc code=start
class Solution {
public:
    int fib(int n) {
        enum class Mode { tr, tr_memo ,it,it_optspace  };
        Mode mode = Mode::it_optspace; 
        switch (mode) {
        case Mode::tr:
            return traverse(n);
        case Mode::tr_memo: {
            std::vector<int> memo(n + 1, -1);
            return traverse_with_memo(n, memo);
        
        }
        case Mode::it:
            return iterate(n);
        case Mode::it_optspace:
            return iterate_opt(n);
        }
        return 0; // 不会走到这里，消除编译器警告
    }

    int traverse(int x) {
        if (x == 0) return 0;
        if (x == 1) return 1;
        return traverse(x - 1) + traverse(x - 2);
    }

    int traverse_with_memo(int x, std::vector<int>& memo) {
        if (x <= 1) return x;
        if (memo[x] != -1) return memo[x];
        memo[x] = traverse_with_memo(x - 1, memo) + traverse_with_memo(x - 2, memo);
        return memo[x];
    }
    int iterate(int x){
        std::vector <int> dp(x+1,-1);        
        for (int i = 0;i<=x;i++){
            if(i <=1) dp[i] = i;
            else
            dp[i] = dp[i-1]+dp[i-2];
        }           
        return dp[x];  
    }
    
    int iterate_opt(int x){
        int dp0 = 0; 
        int dp1 =1 ;
        int dp =0;
        if (x<=1)
            return x;
        for (int i = 2;i<=x;i++){
            dp = dp0+dp1;
            dp0 = dp1;
            dp1 = dp;
        }           
        return dp;  
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 4\n
// @lcpr case=end

 */
