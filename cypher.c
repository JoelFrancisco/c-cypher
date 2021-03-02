#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) 
{
    char alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char capital_alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char *arg_word = argv[1];
    int length = strlen(arg_word);

    int key;
    key = atoi(argv[2]);

    char *numbers;
    numbers = (char*)malloc(sizeof(char) * (length + 1));

    char *word;
    word = (char*)malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < strlen(arg_word); i++)
    {
        if(isdigit(arg_word[i]) != 0)
            strncat(numbers, &arg_word[i], 1);
        else
            strncat(word, &arg_word[i], 1);
    }

    char *answer;
    answer = (char*)malloc(sizeof(char) * (length + 1));
    
    int index;

    for (int letter = 0; letter < strlen(word); letter++)
    {
        for (int i = 0; i < 26; i++)
        {
            if (word[letter] == alphabet[i])
            {
                index = i;

                if (key > 0)
                {
                    for (int j = 0; j < key; j++)
                    {
                        if (index+1 == 26)
                            index = 0;
                        else
                            index++;
                    }
                }
                else 
                {
                    for (int j = 0; j > key; j--)
                    {
                        if (index-1 == -1)
                            index = 26;
                        index --;
                    }
                }
                
                strncat(answer, &alphabet[index], 1);
            }
            else if (word[letter] == capital_alphabet[i])
            {
                index = i;

                if (key > 0)
                {
                    for (int j = 0; j < key; j++)
                    {
                        if (index+1 == 26)
                            index = 0;
                        else 
                            index++;
                    }
                }
                else
                {
                    for (int j = 0; j > key; j--)
                    {
                        if (index-1 == -1)
                            index = 26;
                        index--;
                    }
                }

                strncat(answer, &capital_alphabet[index], 1);
            }
        }
    }
    
    free(word);

    answer = strcat(answer, numbers);

    printf("%s\n", answer);

    free(numbers);
    free(answer);

    return 0;
}
