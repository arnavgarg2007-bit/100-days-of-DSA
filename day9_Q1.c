#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    
    scanf("%s", s);          // read the string
    int len = strlen(s);

    for(int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);  // print in reverse
    }

    return 0;
}