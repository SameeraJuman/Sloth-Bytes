/* exercise: Ctrl + C, Ctrl + V
Given a sentence containing few instances of "Ctrl + C" and "Ctrl + V", return the sentence after those keyboard shortcuts have been applied!

- "Ctrl + C" will copy all text behind it.

- "Ctrl + V" will do nothing if there is no "Ctrl + C" before it.

- A "Ctrl + C" which follows another "Ctrl + C" will overwrite what it copies.*/


#include <stdio.h>
#include <string.h>

void keyboardShortcut(char *sentence){
    char copied_text[1000] = "";
    char result[1000] = "";
    char sentence_copy[1000];
    char *token;
    int first = 1;
    int is_copied = 0;

    strcpy(sentence_copy, sentence);
    token = strtok(sentence_copy, " ");

    while(token != NULL){
        if (strcmp(token, "Ctrl") == 0){
            token = strtok(NULL, " ");

            if (token != NULL && strcmp(token, "+") == 0){
                token = strtok(NULL, " ");

                if (strcmp(token, "C") == 0){
                    strcpy(copied_text, result);
                    is_copied = 1;
                } else if (strcmp(token, "V") == 0){
                    if (is_copied){
                        if (!first){
                            strcat(result, " ");
                        }
                        strcat(result, copied_text);
                    }
                }
            }
        } else {
            if (!first){
                strcat(result, " ");
            }
            strcat(result, token);
            first = 0;
        }

        token = strtok(NULL, " ");
    }
    printf("Final sentence: %s\n\n", result);
}

int main(){

    keyboardShortcut("the egg and Ctrl + C Ctrl + V the spoon");

    keyboardShortcut("WARNING Ctrl + V Ctrl + C Ctrl + V");

    keyboardShortcut("The Ctrl + C Ctrl + V Town Ctrl + C Ctrl + V");

    return 0;
}

