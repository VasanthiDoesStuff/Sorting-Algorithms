#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
// Function Definitions
void selection_sort(int *arr,int n);
void bubble_sort(int *arr,int n);
void merge_sort(int *arr,int n);
void merge(int *arr,int *leftArr,int l, int *rightArr,int r);
void compare_sort(int *arr,int n);

//The selection sort function
void selection_sort(int *arr,int n)
{
    //TODO: Implement selection sort
    //For i from 0 to n–1
        //Find smallest number between numbers[i] and numbers[n-1]
        //Swap smallest number with numbers[i]

    for(int position = 0; position < n; position++)
    {
        int min = arr[position];
        int min_index = position;
        for(int i = position; i< n; i++)
        {
            if(arr[i] < min){
                min = arr[i];
                min_index = i;
            }
        }
        int temp = arr[position];   //swap values
        arr[position] = arr[min_index];
        arr[min_index] = temp;
    }
}

//The bubble sort function
void bubble_sort(int *arr,int n)
{
    //TODO: Implement Bubble sort
    //Repeat n-1 times
    // For i from 0 to n–2
        //  If numbers[i] and numbers[i+1] out of order
            //Swap them
    if(n < 2)
    {
        return ;
    }
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n-k-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                int temp = arr[i];
                arr [i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

//The merge sort function
void merge_sort(int *arr, int n)
{
    //TODO: Implement Merge sort
    //If only one number
        //Quit
    //Else
        //Sort left half of number
        //Sort right half of number
        //Merge sorted halves
    if(n < 2){
        return;
    }

    int middle = n / 2;
    int *leftArr = (int*) malloc(middle * sizeof(int));
    int r = n - middle;
    int *rightArr = (int*) malloc(r * sizeof(int));

    for(int i = 0; i < middle; i++)
    {
        leftArr[i] = arr[i];
    }

    for(int i = 0; i < r; i++)
    {
        rightArr[i] = arr[i + middle];
    }

    merge_sort(leftArr, middle);
    merge_sort(rightArr, r);
    merge(arr, leftArr, middle, rightArr, r);

    free(leftArr);
    free(rightArr);
}

void merge(int *arr, int *leftArr, int l, int *rightArr, int r)
{
    int i = 0, j = 0, k = 0; // i for leftArr, j for rightArr, k for arr

    while(i < l && j < r)
    {
        if(leftArr[i] > rightArr[j]) // adding the least one to array
        {
            arr[k] = rightArr[j];
            j++;
        }
        else if(leftArr[i] < rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        k++;
    }

    while(i < l) // checking if any element is left in leftArr
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < r) // checking if any element is left in rightArr
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

//The compare function
void compare_sort(int* arr, int n) {
    int* arr_copy = (int*)malloc(n * sizeof(int));
    memcpy(arr_copy, arr, n * sizeof(int));

    clock_t start, end;
    double bubble_time, selection_time, merge_time;

    // Bubble sort
    start = clock();
    bubble_sort(arr_copy, n);
    end = clock();
    bubble_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    memcpy(arr_copy, arr, n * sizeof(int));

    // Selection sort
    start = clock();
    selection_sort(arr_copy, n);
    end = clock();
    selection_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    memcpy(arr_copy, arr, n * sizeof(int));

    // merge sort
    start = clock();
    merge_sort(arr_copy, n);
    end = clock();
    merge_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Output results
    printf("\nResults:\n");
    display_arr(arr_copy,n);
    printf("Bubble sort: %lf seconds\n", bubble_time);
    printf("Selection sort: %lf seconds\n", selection_time);
    printf("Merge sort: %lf seconds\n", merge_time);

    free(arr_copy);
}



