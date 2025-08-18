#include <stdio.h>
#include <string.h>
#include <ctype.h>  // for tolower()

int main() {
    char str[1000];    // input string (enough size for sentence)
    
    // Read a full line of input
    fgets(str, sizeof(str), stdin);

    int letters[26] = {0};  // frequency array for a-z

    // Traverse the string
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);   // convert to lowercase

        // Check if it is a letter (a-z)
        if (ch >= 'a' && ch <= 'z') {
            letters[ch - 'a'] = 1;   // mark this letter as present
        }
    }

    // Check if all 26 letters are present
    int isPangram = 1;  // assume true
    for (int i = 0; i < 26; i++) {
        if (letters[i] == 0) {
            isPangram = 0;  // missing a letter
            break;
        }
    }

    // Print result
    if (isPangram) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }

    return 0;
}