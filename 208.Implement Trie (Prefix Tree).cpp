/*
 * @lc app=leetcode id=208 lang=cpp
 * @lcpr version=30400
 *
 * [208] Implement Trie (Prefix Tree)
 */
#include "lc.h"
#include <string>
using namespace std;

// @lc code=start

class Trie
{
    struct TrieNode
    {
        std::vector<std::unique_ptr<TrieNode>> children;
        bool isEnd;
        TrieNode() : children(26), isEnd(false)
        {
        }
    };
    std::unique_ptr<TrieNode> root;

    TrieNode *searchPrefix(const std::string &prefix)
    {
        TrieNode *node = root.get();
        for (char ch : prefix)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                return nullptr;
            }
            node = node->children[index].get();
        }
        return node;
    }

  public:
    Trie() : root(std::make_unique<TrieNode>())
    {
    }

    void insert(std::string word)
    {
        TrieNode *node = root.get();
        for (char ch : word)
        {
            int index = ch - 'a';
            if (node->children[index] == nullptr)
            {
                // 使用 std::make_unique 创建新节点
                node->children[index] = std::make_unique<TrieNode>();
            }
            node = node->children[index].get();
        }
        node->isEnd = true;
    }

    bool search(std::string word)
    {
        TrieNode *node = searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(std::string prefix)
    {
        return searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end

/*
// @lcpr case=start
//
["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]\n
// @lcpr case=end

 */
