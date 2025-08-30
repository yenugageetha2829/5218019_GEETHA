
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 10  // letters from 'a' to 'j'

// Trie Node structure
typedef struct TrieNode {
    struct TrieNode *children[ALPHABET_SIZE];
    int isEndOfWord;
} TrieNode;

// Create a new Trie node
TrieNode* createNode() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;
    return node;
}

// Insert a word into Trie and check for BAD SET condition
int insertWord(TrieNode *root, const char *word) {
    TrieNode *current = root;
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        
        if (current->children[index] == NULL) {
            current->children[index] = createNode();
        }
        
        current = current->children[index];

        // If we encounter a node which is already end of another word
        if (current->isEndOfWord && i != length - 1)
            return 0;  // BAD SET
    }

    // If this node already had children, then current word is prefix of another word
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (current->children[i] != NULL)
            return 0; // BAD SET
    }

    // If current word itself is duplicate
    if (current->isEndOfWord)
        return 0;

    current->isEndOfWord = 1;
    return 1; // GOOD so far
}

int main() {
    int n;
    scanf("%d", &n);
    
    TrieNode *root = createNode();
    char word[100000];

    for (int i = 0; i < n; i++) {
        scanf("%s", word);

        if (!insertWord(root, word)) {
            printf("BAD SET\n%s\n", word);
            return 0;
        }
    }

    printf("GOOD SET\n");
    return 0;
}
