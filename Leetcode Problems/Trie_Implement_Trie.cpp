class TrieNode
{
public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class Trie
{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode('\0');
    }

    // insert the word
    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int ind = word[0] - 'a';
        TrieNode *child;
        if (root->children[ind] != NULL)
        {
            child = root->children[ind];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[ind] = child;
        }
        insertWord(child, word.substr(1));
    }

    void insert(string word)
    {
        insertWord(root, word);
    }

    // find the word

    bool find(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            if (root->isTerminal)
                return true;
            return false;
        }
        int ind = word[0] - 'a';
        TrieNode *child;
        if (root->children[ind] != NULL)
        {
            child = root->children[ind];
            return find(child, word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool search(string word)
    {
        return find(root, word);
    }
    // find pattern

    bool findpat(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            // if(root->isTerminal)

            return true;
            // return false;
        }
        // cout<<word[0];
        int ind = word[0] - 'a';
        TrieNode *child;
        if (root->children[ind] != NULL)
        {
            child = root->children[ind];
            return findpat(child, word.substr(1));
        }
        else
        {
            return false;
        }
    }

    bool startsWith(string prefix)
    {
        return findpat(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */