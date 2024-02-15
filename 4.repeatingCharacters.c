#include <stdio.h>
#include <string.h>
#include <stdbool.h>
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

    char result[BUFFER];
    int resultIndex = 0;
    for(int i = 0; i < strLength; i++)
    {
        if(str[i]==' ')
        {
            continue;
        }
        bool repeat = false;
        for(int j = 0; j < resultIndex; j++)
        {
            if(str[i]==result[j])
            {
                repeat = true;
                break;
            }
        }
        if(!repeat)
        {
            result[resultIndex++] = str[i];
        }
    }
    
    writeLineToFile(name_out, result);

    return 0;
}