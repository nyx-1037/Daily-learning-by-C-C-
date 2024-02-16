#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

char word[20] = { 0 };

char* mergeAlternately(char* word1, char* word2)
{
    
    int i = 0;
    while (*word1 != 0 || *word2 != 0)
    {
        if (*word1 != 0) {
            word[i] = *word1;
            i++;
        }
       
        if (*word2 != 0) {
            word[i] =*word2;
            i++;
        }
           
        word1++;
        word2++;
    }
    return &word;
}

int main()
{
    char arr1[10] = { 0 };
    char arr2[10] = { 0 };
    scanf("%s", arr1);
    scanf("%s", arr2);
    char* rel[20] = mergeAlternately(arr1, arr2);
    printf("%s", *rel);
    return 0;
}
