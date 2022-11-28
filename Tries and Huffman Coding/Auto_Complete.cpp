#include <iostream>
#include <string>
#include <vector>
using namespace std;

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
    TrieNode *root;

public:
    int count;

    Trie()
    {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word)
    {
        // Base case
        if (word.size() == 0)
        {
            if (!root->isTerminal)
            {
                root->isTerminal = true;
                return true;
            }
            else
            {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word)
    {
        if (insertWord(root, word))
        {
            this->count++;
        }
    }

    void printWords(TrieNode *root, string words)
    {
        if (root->isTerminal == true)
        {
            cout << words << endl;
        }

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != NULL)
            {
                printWords(root->children[i], words + root->children[i]->data);
            }
        }
    }

    void findWord(TrieNode *root, string word, string words)
    {
        if (word.size() == 0)
        {

            // if (root->isTerminal == true) {
            //   cout << words << " ";
            // }
            printWords(root, words);

            return;
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL)
        {
            child = root->children[index];
            findWord(child, word.substr(1), words);
        }
        return;
    }

    void autoComplete(vector<string> input, string pattern)
    {
        // Write your code here
        for (int i = 0; i < input.size(); i++)
        {
            string word = input[i];
            //   while (word.size() > 0) {

            insertWord(word);
            // word = word.substr(1);
            //   }
        }
        findWord(root, pattern, pattern);
    }
};

int main()
{
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i)
    {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}