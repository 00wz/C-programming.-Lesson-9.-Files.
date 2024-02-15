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

void writeNumsArrayToFile(char fileName[], int strOut[], int length)
{
    FILE* file = fopen(fileName, "w");
    for(int i = 0; i < length; i++)
    {
        fprintf(file, "%d ", strOut[i]);
    }
    fclose(file);
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_array(int size, int a[])
{
    for(int i=size-1;i>0;i--)
    {
        for(int k=0;k<i;k++)
        {
            if(a[k]>a[k+1])
            {
                swap(&a[k],&a[k+1]);
            }
        }
    }
}

int main()
{
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";

    char str[BUFFER];
    size_t strLength = getLineFromFile(name_in, str);

    int nums[BUFFER];
    
    int numsCount = 0;
    int current = 0;
    int isNumberFlag = false;
    for(int i = 0; i < strLength; i++)
    {
        if(str[i]>='0' && str[i]<='9')
        {
            current *= 10;
            current += str[i] - '0';
            isNumberFlag = true;
        }
        else if(isNumberFlag)
        {
            nums[numsCount] = current;
            numsCount++;
            current = 0;
            isNumberFlag = false;
        }
    }

    sort_array(numsCount, nums);

    writeNumsArrayToFile(name_out, nums, numsCount);

    return 0;
}