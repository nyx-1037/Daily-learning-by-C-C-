//输入 I like beijing.
//输出 beijing. like I
//思路：1、逆序整个字符串
//      2、逆序每个单词
#include<stdio.h>
#include<string.h>
#include<assert.h>

void reverse(char* left, char* right)
{
    assert(left);
    assert(right);

    while (left < right)
    {
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right--;
    }
}

int main()
{
    char arr[100] = { 0 };
    gets_s(arr);
    int len = strlen(arr);
    reverse(arr, arr + len - 1);
    char* start = arr;

    while (*start)
    {
        char* end = start;
        while (*end != ' ' && *end != 0)
        {
            end++;
        }
        reverse(start, end - 1);
        if (*end != '\0')
            end++;
        start = end;
    }
    puts(arr);
    return 0;
}
