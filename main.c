#include <stdio.h>
#include <stdlib.h>
#include "jackLib.h"
#define SIZE 20

void main(void)
{
    int high = 100;
    int nums[SIZE];

    // Genorating random numbers
    for (int i = 0; i < SIZE - 1; i++)
        nums[i] = rand() % (high + 1);

    printf("Unsorted List: ");
    printList(nums);
    printf("Sorted List: ");
    bubbleSort(nums);
    printList(nums);
    printf("Max: %d\n", max(nums));
    printf("Min: %d\n", min(nums));
    printf("Medium: %f\n", medium(nums));
    printf("Index of random element (using binary search): %d\n", binarySearch(nums, nums[4]));


    

    

    // printf("\n");
    // printf("Unsorted List: ");
    // printList(nums);

    // printf("Sorted List: ");
    // bubbleSort(nums);
    // printList(nums);

    // printf("Max: %d\n", max(nums));
    // printf("Min: %d\n", min(nums));
    // printf("Medium: %f\n", medium(nums));

    // printf("Index of random element (with binary search): %d\n", binarySearch(nums, nums[3]));
    // printf("Index of ramdom element (with normal search): %d\n", search(nums, nums[3]));

}