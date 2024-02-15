#include <stdio.h>
#include <string.h>
#define BUFFER 1000

size_t getLineFromFile(char fileName[], char strIn[])
{
    FILE* file = fopen(fileName , "r");
    fscanf(file, "%[^\n]", strIn);
    fclose(file);
    return strlen(strIn);
}

void writeLineToFile(char fileName[], char strOut[])
{
    FILE* file = fopen(fileName, "w");
    fprintf(file, "%s\n", strOut);
    fclose(file);
}

int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";

    char str[BUFFER];
    size_t strLength = getLineFromFile(name_in, str);

    for(int i = 0; i < strLength; i++)
    {
        switch (str[i])
        {
        case 'A':
            str[i] = 'B';
            break;
        case 'B':
            str[i] = 'A';
            break;
        case 'a':
            str[i] = 'b';
            break;
        case 'b':
            str[i] = 'a';
            break;
        }
    }
    
    writeLineToFile(name_out, str);

    return 0;
}