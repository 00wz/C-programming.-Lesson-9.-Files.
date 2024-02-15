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

    int maxLength = 0;
    int maxWordIndex = 0;
    int currentLength = 0;
    int currentWordIndex = 0;
    for(int i = 0; i < strLength; i++)
    {
        if(str[i]==' ')
        {
            if(currentLength > maxLength)
            {
                maxWordIndex = currentWordIndex;
                maxLength = currentLength;
            }
            currentLength = 0;
            currentWordIndex = i + 1;
        }
        else
        {
            currentLength++;
        }
    }

    char result[BUFFER] = {'\0'};
    memcpy(result, &str[maxWordIndex], maxLength);
    
    writeLineToFile(name_out, result);

    return 0;
}