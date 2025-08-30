
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[100005];
    scanf("%s", s);
    int freq[26] = {0};
    for (int i = 0; s[i]; i++)
        freq[s[i] - 'a']++;
    
    // Gather all non-zero frequencies
    int values[26], cnt = 0;
    for (int i = 0; i < 26; i++)
        if (freq[i] > 0)
            values[cnt++] = freq[i];
    
    // Sort values for easier comparison
    for (int i = 0; i < cnt - 1; i++)
        for (int j = i + 1; j < cnt; j++)
            if (values[i] > values[j]) {
                int tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
            }
    
    int yes = 0;
    if (values[0] == values[cnt - 1])
        yes = 1;
    else if (values[0] == 1 && values[1] == values[cnt - 1])
        yes = 1;
    else if (values[0] == values[cnt - 2] && values[cnt - 1] == values[cnt - 2] + 1)
        yes = 1;
    
    printf("%s\n", (yes ? "YES" : "NO"));
    return 0;
}
