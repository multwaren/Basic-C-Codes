#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    char str[MAX_LENGTH], line[MAX_LENGTH];
    int counts[5] = {0};
    int i, len;

    printf("Enter first line of text: ");
    gets(line);
    strcpy(str, line);

    printf("Enter second line of text: ");
    gets(line);
    strcat(str, line);

    printf("Enter third line of text: ");
    gets(line);
    strcat(str, line);

    printf("Enter fourth line of text: ");
    gets(line);
    strcat(str, line);

    len = strlen(str);

    for (i = 0; i < len; i++) {
        switch (str[i]) {
            case 'a':
            case 'A':
                counts[0]++;
                break;
            case 'e':
            case 'E':
                counts[1]++;
                break;
            case 'i':
            case 'I':
                counts[2]++;
                break;
            case 'o':
            case 'O':
                counts[3]++;
                break;
            case 'u':
            case 'U':
                counts[4]++;
                break;
            default:
                break;
        }
    }

    printf("Vowel Occurrences\n");
    printf("A: %d\n", counts[0]);
    printf("E: %d\n", counts[1]);
    printf("I: %d\n", counts[2]);
    printf("O: %d\n", counts[3]);
    printf("U: %d\n", counts[4]);

    return 0;
}
