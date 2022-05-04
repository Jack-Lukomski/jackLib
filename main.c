#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

int length(int *list);
void printList(int *list);
void bubbleSort(int *list);
int max(int *list);
int min(int *list);
float medium(int *list);
int binarySearch(int *list, int find);
int search(int *list, int find);

void main(void)
{
    int high = 100;
    int nums[SIZE];

    // Genorating random numbers
    for (int i = 0; i < SIZE - 1; i++)
        nums[i] = rand() % (high + 1);

    printf("\n");
    printf("Unsorted List: ");
    printList(nums);

    printf("Sorted List: ");
    bubbleSort(nums);
    printList(nums);

    printf("Max: %d\n", max(nums));
    printf("Min: %d\n", min(nums));
    printf("Medium: %f\n", medium(nums));

    printf("Index of random element (with binary search): %d\n", binarySearch(nums, nums[3]));
    printf("Index of ramdom element (with normal search): %d\n", search(nums, nums[3]));

}

int length(int *list)
{
    int i = 0;
    while (*(list + i) != 0)
        i++;
    return i;
}

void printList(int *list)
{
    printf("[");
    for (int i = 0; i < length(list); i++)
        if (i == length(list) - 1)
            printf("%d", *(list + i));
        else
            printf("%d, ", *(list + i));
    printf("]\n");
}

void bubbleSort(int *list)
{
    int temp;
    for (int i = 0; i < length(list); i++)
    {
        for (int j = 0; j < length(list); j++)
        {
            if (*(list + i) < *(list + j))
            {
                temp = *(list + i);
                *(list + i) = *(list + j);
                *(list + j) = temp;
            }
        }
    } 
}

int max(int *list)
{
    int max = 0;
    for (int i = 0; i < length(list); i++)
    {
        if (*(list +i) > max)
            max = *(list + i);
    }
    return max;
}

int min(int *list)
{
    int min = max(list);
    for (int i = 0; i < length(list); i++)
    {
        if (*(list +i) < min)
            min = *(list + i);
    }
    return min;
}

float medium(int *list)
{
    if (length(list) % 2 == 1)
        return *(list + length(list)/2 + 1);
    else 
        return *(list + length(list)/2 + 1) / *(list + length(list)/2 - 1);
}

int binarySearch(int *list, int find)
{
    int start = 0;
    int end = length(list) - 1;
    int half = 0;

    while (half != 1)
    {
        half = (start + end) / 2;
        if (*(list + half) < find)
            start = half;
        if (*(list + half) > find)
            end = half;
        if (*(list + half) == find)
            return half;
    }
    return 0;
}

int search(int *list, int find)
{
    for (int i = 0; i < length(list); i++)
    {
        if (*(list + i) == find)
            return i;
    }
    return 0;
}