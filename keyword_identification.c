//check if input is keyword or not
#include <stdio.h>
#include<string.h>

int SizeFinder(char inputChar[15]) {
    int i = 0;
    while (inputChar[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char a, b[12];
    int i, indent = 0, stringmatch = 0;
    FILE *fr;
    int stringMatch = 0;
    printf("Enter character which you want to check its a keyword or not:\n");
    scanf(" %s", &b);
    int inputSize = SizeFinder(b);
//    printf("Size of input is : %d\n", inputSize);
    fr = fopen("keywords.txt", "r");
    if (fr == NULL) {
        printf("Error opening file!");
        return 0;
    }
    while ((a = fgetc(fr)) != EOF) {

        if (a == ' ' || a == '\n' || a == '\t') {
//            i = 0;
            if (inputSize == stringmatch) {
                stringMatch = 1;
            }
            stringmatch = 0;
        } else if (a == b[stringmatch]) {
            stringmatch++;
//            i++;
        } else {
            stringmatch = 0;
//            indent++;
        }
    }


    if (stringMatch == 1) {
        printf("string match!!\n");
    } else {
        printf("no match!!\n");
    }
//    printf("The value of string match: %d\n", stringmatch);
//    printf("The value of indent: %d\n", indent);
//    if (stringmatch ==
//        strlen(b)
//            ) { //so that if length is same then valid
//        printf("Valid string");
//    } else {
//        printf("Not a valid keyword");
//    }
    fclose(fr);
    return 0;

}
