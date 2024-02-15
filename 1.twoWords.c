#include <stdio.h>
#include <string.h>
#define BUFFER 1000

size_t getLineFromFile(char fileName[], char strIn[])
{
    FILE *file = fopen(fileName , "r");
    fscanf(file, "%[^\n]", strIn);
    fclose(file);
    return strlen(strIn);
}

int main()
{
    FILE *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_out = fopen(name_out, "w");

    char str[BUFFER];
    size_t strLength = getLineFromFile(name_in, str);

    int spaceIndex = 0;
    while(str[spaceIndex]!=' ')
    {
        spaceIndex++;
    }
    
    for(int i = 0; i < spaceIndex; i++)
    {
        int count = 0;
        for (int j = 0; j < spaceIndex; j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }
        }
        if(count != 1)
        {
            continue;
        }

        count = 0;
        for (int j = spaceIndex + 1; j < strLength; j++)
        {
            if(str[i]==str[j])
            {
                count++;
            }
        }
        if(count != 1)
        {
            continue;
        }
        fprintf(f_out, "%c ", str[i]);
    }

    fclose(f_out);

    return 0;
}