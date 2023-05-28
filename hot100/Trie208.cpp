#include <set>
#include <string>
#include <vector>
using namespace std;

//为什么不用pass：因为没有前缀树的删除过程，所以如果nexts[i]位置上有 那么一定有
class TrieNode
{
public:
    TrieNode() : end(false) //,pass(0)
    {
        nexts = vector<TrieNode *>(26);
    };
    // int pass;    //如果有Node 则一定pass
    bool end;
    vector<TrieNode *> nexts;
};

//会否有些太简单了这也能过的 就纯一个set
class Trie
{
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *t = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if (t->nexts[ch] == nullptr)
            {
                t->nexts[ch] = new TrieNode();
            }
            // t->pass++;
            t = t->nexts[ch];
        }
        // t->pass++;
        t->end = true;
    }

    bool search(string word)
    {
        TrieNode *t = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ch = word[i] - 'a';
            if (t->nexts[ch] == nullptr)
                return false;
            t = t->nexts[ch];
        }
        // if (t->end)
        return t->end;
        // return false;
    }

    bool startsWith(string prefix)
    {
        TrieNode *t = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            int ch = prefix[i] - 'a';
            if (t->nexts[ch] == nullptr)
                return false;
            t = t->nexts[ch];
        }
        // if (t->pass)
        //     return true;
        return true;
    }

private:
    TrieNode *root;
};

int main()
{
    Trie *obj = new Trie();
    obj->insert("a");
    bool param_2 = obj->search("a");
    // bool param_4 = obj->search("app");
    bool param_3 = obj->startsWith("a");

    return 0;
}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */