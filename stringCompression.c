#include <stdio.h>

int string_length(char *string)
{
    int length = 0;
    while (string[++length] != '\0')
        ;
    return length;
}

int compress(char *chars, int charsSize)
{
    int compressed_index = 0, original_index = 0;
    while (original_index < charsSize)
    {
        char start_character = chars[original_index];
        int count = 0;
        while (original_index < charsSize && chars[original_index] == start_character)
        {
            original_index++;
            count++;
        }
        chars[compressed_index++] = start_character;
        if (count == 1)
        {
            continue;
        }
        int start_index = compressed_index;
        while (count != 0)
        {
            chars[compressed_index++] = count % 10 + '0';
            count /= 10;
        }
        int end_index = compressed_index - 1;
        while (start_index < end_index)
        {
            char temp = chars[start_index];
            chars[start_index] = chars[end_index];
            chars[end_index] = temp;
            start_index++;
            end_index--;
        }
    }
    return compressed_index;
}

void solution()
{
    char chars[100];
    printf("Enter string: ");
    scanf("%s", chars);
    int compressed_size = compress(chars, string_length(chars));
    chars[compressed_size] = '\0';
    printf("Compressed string: ");
    printf("%s", chars);
}

int main()
{
    solution();
    return 0;
}
