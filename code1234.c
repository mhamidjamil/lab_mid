#include <stdio.h>
#include <string.h>

int main() {
    char c[50];
    printf("Enter a string: ");
    gets(c);
    int validString = 0;
    int i, j,k;
    for (i = 0, j = (strlen(c) - 1); i < (strlen(c) / 2); i++, j--) {
        if(c[(strlen(c)/2)]!='c'){
            printf("Not valid!");
            return 0;
        }
        if (c[i] == c[j]) {
            validString = 1;
        } else {
            validString = 0;
            printf("The string is not invalid!\n");
            return 0;
        }
    }
    if (validString == 1) {
        printf("The string is valid\n");
    }
    return 0;
}


