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

class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int ind = word[0] - 'a';
        // if(word[0]=='.')
        //     ind=26;
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
    void addWord(string word)
    {
        insertWord(root, word);
    }

    bool findpat(TrieNode *root, string word)
    {
        if (!root)
        {
            return false;
        }
        if (word.size() == 0)
        {
            if (root->isTerminal == true)

                return true;
            return false;
        }
        // cout<<word[0];
        int ind = word[0] - 'a';
        // if(word[0]=='.')
        //     ind=26;

        if (word[0] == '.')
        {
            bool ans = false;
            for (int i = 0; i < 26; i++)
            {
                if (root->children[i] != NULL && findpat(root->children[i], word.substr(1)))
                {
                    return true;
                }
            }
            return false;
        }

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

    bool search(string word)
    {

        return findpat(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */