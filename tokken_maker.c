#include <stdio.h>
# include <string.h>
//Muhammad Hamid Jamil
//SP19-BCS-098

int SizeFinder(char inputChar[15]) {
    int i = 0;
    while (inputChar[i] != '\0') {
        i++;
    }
    return i;
}

void manageToken(char h[55], FILE *f) {
    int i = 0;
    while (h[i] != '\0' && h[i] != '\n' && h[i] != ' ') {
        fputc(h[i], f);
        i++;
    }
}

int numaricdata(char userInput[55]) {
    int numericFound = 0;
    int EFound = 0;
    int dotFound = 0;
    int symbolFound = 0;
    int inputCharSize;
    int i;
    inputCharSize = SizeFinder(userInput);
//    printf("%d", inputCharSize);
    for (i = 0; i < inputCharSize; i++) {
        if (userInput[i] == '.') {
            dotFound = 1;
            if (i == 0) {
                printf("%s is not a valid number", userInput);
                return 0;
            } else if (EFound == 1 || EFound == 2) {
                printf("%s is not a valid number", userInput);
                return 0;
            }

        } else if (userInput[i] == 'E' || userInput[i] == 'e') {
            if (i != 0) {
                EFound = 1;
                numericFound = 0;
            }
        } else if (userInput[i] >= '0' && userInput[i] <= '9') {
            if (EFound == 2) {
                numericFound = 1;
            } else if (EFound == 1) {
//                numericFound = 0;
                printf("%s is not a valid number", userInput);
                return 0;
            } else if (dotFound == 1) {
                numericFound = 1;
            } else if (symbolFound == 1) {
                numericFound = 1;
            } else {
                numericFound = 1;
            }
        } else if (userInput[i] == '+' || userInput[i] == '-') {
            if (EFound == 1) {
                EFound = 2;
            } else if (i == 0) {
                symbolFound = 1;
                numericFound = 0;
            } else if (EFound == 2) {
//                numericFound = 0;
                printf("%s is not a valid number", userInput);
                return 0;
            } else {
//                printf("%s is not a valid number", userInput);
                return 0;
            }
        } else if (((userInput[i] >= 'a' && userInput[i] < 'e') || (userInput[i] >= 'A' && userInput[i] < 'E')) ||
                   ((userInput[i] >= 'f' && userInput[i] <= 'z') || (userInput[i] >= 'F' && userInput[i] <= 'Z'))) {
//            numericFound = 0;
//            printf("%s is not a valid number", userInput);
        }
    }

    if (numericFound == 1 && EFound != 1) {
        printf("%s is a valid number", userInput);
        return 1;
    } else {
        printf("%s is not a valid number", userInput);
        return 0;
    }
}

int buildInFuntion(char userInput[55]) {
    if (strlen(userInput) <= 2) {
        return 0;
    }
    FILE *fp;
//    char userInput[15];
    int indexFinded = 0;
    int inputCharSize = 0;
    int stringFinded = 0;
//    printf("Enter String : ");
//    scanf("%s", userInput);
    inputCharSize = SizeFinder(userInput);
//    printf("%d", inputCharSize);
    fp = fopen("buildinfunctions.txt", "r");
    if (fp == NULL) {
        printf("!----Error opening file----!");
//        exit(1);
    } else if (fp != NULL) {
        char c;
        while ((c = fgetc(fp)) != EOF) {
//            printf("%c",c);
            if (c == ' ') {
                if (indexFinded == inputCharSize) {
                    stringFinded = 1;

                }
                indexFinded = 0;
            } else if (c == userInput[indexFinded]) {
                indexFinded++;
            } else {
                indexFinded = 0;
            }
        }

        fclose(fp);
    }
    if (stringFinded == 1) {
        printf("\nString is a keyword");
        return 1;
    } else {
        printf("\nString is not a keyword");
        return 0;
    }
}

int specialCharacter(char h[55]);

int identifier(char h[55]);

int bracket(char h[55]);

int keyword(char h[55]);

int digit(char h[55]);

int lexicalaAnalyzer(char h[55]);

int keyword(char userInput[55]) {
    if (strlen(userInput) <= 2) {
        return 0;
    }

    FILE *fp;
//    char userInput[15];
    int indexFinded = 0;
    int inputCharSize = 0;
    int stringFinded = 0;
//    printf("Enter String : ");
//    scanf("%s", userInput);
    inputCharSize = SizeFinder(userInput);
//    printf("%d", inputCharSize);
    fp = fopen("keywords.txt", "r");
    if (fp == NULL) {
        printf("Error opening file");
//        exit(1);
    } else if (fp != NULL) {
        char c;
        while ((c = fgetc(fp)) != EOF) {
//            printf("%c",c);
            if (c == ' ') {
                if (indexFinded == inputCharSize) {
                    stringFinded = 1;

                }
                indexFinded = 0;
            } else if (c == userInput[indexFinded]) {
                indexFinded++;
            } else {
                indexFinded = 0;
            }
        }

        fclose(fp);
    }
    if (stringFinded == 1) {
        printf("\nString is a keyword");
        return 1;
    } else {
        printf("\nString is not a keyword");
        return 0;
    }
}

int specialCharacter(char h[55]) {
    FILE *fw;
    fw = fopen("tokens.txt", "a");
    if (strlen(h) == 1) {
        printf("specialCharacter\n");
        if (h[0] == '!' || h[0] == '#' || h[0] == '%' || h[0] == '&' || h[0] == '*' || h[0] == '+' ||
            h[0] == '-' || h[0] == '/' || h[0] == '<' || h[0] == '>' || h[0] == '=' || h[0] == '?' || h[0] == '@' ||
            h[0] == '^' || h[0] == '~' || h[0] == '"' || h[0] == ';') {
            fputs("<Special character,", fw);
            manageToken(h, fw);
            fputc('>', fw);
            fputc('\n', fw);
            fclose(fw);
            return 1;
        } else {
            printf("not a specialCharacter!!\n");
            fclose(fw);
            return 0;
        }
    }
}

int bracket(char h[55]) {
    if (strlen(h) == 1) {
        printf("Bracket\n");
    } else {
        printf("Not a bracket\n");
        return 0;
    }
    FILE *fw;
    fw = fopen("tokens.txt", "a");
    if (h[0] == '(' || h[0] == '{') {
        printf("Opening bracket Bracket\n");
        fputs("<specialCharacter,", fw);
        putc(h[0], fw);
        fputc('>', fw);
        fputc('\n', fw);
        fclose(fw);
        return 1;
    } else if (h[0] == ')' || h[0] == '}') {
        printf("Closing Bracket\n");
        fputs("<specialCharacter,", fw);
        putc(h[0], fw);
        fputc('>', fw);
        fputc('\n', fw);
        fclose(fw);
        return 1;
    } else {
        fclose(fw);
        return 0;
    }
}

int character(char h[55]) {
    FILE *fw;
    fw = fopen("tokens.txt", "a");
    if (strlen(h) == 1) {
        printf("Character\n");
        if (h[0] >= 'a' && h[0] <= 'z' || h[0] >= 'A' && h[0] <= 'Z') {
            printf("Character\n");
            fputs("<Character,", fw);
            manageToken(h, fw);
            fputc('>', fw);
            fputc('\n', fw);
            fclose(fw);
            return 1;
        }
        return 1;
    } else {
        printf("Not a character\n");
        return 0;
    }
}

int digit(char h[55]) {
    FILE *fw;
    fw = fopen("tokens.txt", "a");
    if (strlen(h) == 1) {
        if (h[0] >= '0' && h[0] <= '9') {
            printf("Digit\n");
            fputs("<Digit,", fw);
            manageToken(h, fw);
            fputc('>', fw);
            fputc('\n', fw);
            fclose(fw);
            return 1;
        } else {
            printf("Not a digit\n");
            fclose(fw);
            return 0;
        }
    } else {
        printf("Not a digit\n");
        return 0;
    }
}

int identifier(char userInput[55]) {
//    char userInput[20];
    int validIdentifier = 0;
    int inputCharSize;
    int i;
//    int alier = 0;
//    printf("Enter numeric data : ");
//    scanf("%s", userInput);
    inputCharSize = SizeFinder(userInput);
//    printf("%d", inputCharSize);



    for (i = 0; i < inputCharSize; i++) {
        if (i == 0 && (userInput[i] >= '0' && userInput[i] <= '9') || userInput[i] == '-') {

            printf("Invalid Identifier");
            return 0;
        } else if ((userInput[i] >= 'a' && userInput[i] <= 'z') || (userInput[i] >= 'A' && userInput[i] <= 'Z') ||
                   userInput[i] == '_' || (userInput[i] >= '0' && userInput[i] <= '9')) {
            validIdentifier = 1;
        } else {
//            validIdentifier = 0;
            printf("Invalid Identifier");
            return 0;
        }
    }
    if (validIdentifier == 1) {
        printf("%s is a valid identifier", userInput);
        return 1;
    } else {
        printf("%s is not a valid identifier", userInput);
        return 0;
    }
}

void charClear(char str[55]) {
    int i;
    for (i = 0; i < 55; i++) {
        str[i] = '\0';
    }
}

int lexicalaAnalyzer(char h[55]) {
    FILE *fw;
    fw = fopen("tokens.txt", "a");
    if (keyword(h) != 0) {
        fputs("<Keyword,", fw);
        manageToken(h, fw);
        fputc('>', fw);
        fputc('\n', fw);
        fclose(fw);
    } else if (buildInFuntion(h) != 0) {
        fputs("<BuildInFunction,", fw);
        manageToken(h, fw);
        fputc('>', fw);
        fputc('\n', fw);
        fclose(fw);
    } else if (specialCharacter(h) != 0) {}
    else if (identifier(h) != 0) {
        fputs("<Identifier,", fw);
        manageToken(h, fw);
        fputc('>', fw);
        fputc('\n', fw);
        fclose(fw);
    } else if (digit(h) != 0) {}
    else if (bracket(h) != 0) {}
    else if (character(h) != 0) {}
    else if (numaricdata(h) != 0) {
        fputs("<NumaricData,", fw);
        manageToken(h, fw);
        fputc('>', fw);
        fputc('\n', fw);
        fclose(fw);
    } else {
        printf("Not a valid token!!!\n");
        fclose(fw);
        return 0;
    }
//    printf("token created \n");
    fclose(fw);
    return 0;
}

int main() {
    char a;
    int i = 0;
    FILE *f;
    remove("tokens.txt");
    char toBeSend[55];
    charClear(toBeSend);
    f = fopen("input.txt", "r");
    while ((a = getc(f)) != EOF) {
        if (a == '#') {
            toBeSend[i] = a;
            i++;
            while (a != '\n') {
                a = getc(f);
                toBeSend[i] = a;
                i++;
            }

            FILE *fw;
            fw = fopen("tokens.txt", "a");
            fputs("<Header,", fw);
            manageToken(toBeSend, fw);
            fputc('>', fw);
            fputc('\n', fw);
            fclose(fw);
            charClear(toBeSend);
            i = 0;

        }
        if (a == ' ' || a == '\n' || a == '\t') {
            lexicalaAnalyzer(toBeSend);
            charClear(toBeSend);
            i = 0;
        } else {
            toBeSend[i] = a;
            i++;
        }
    }
    return 0;
}