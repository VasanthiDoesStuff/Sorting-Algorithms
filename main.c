#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>


//Functions Used
void selection_sort(int *arr,int n);
void bubble_sort(int *arr,int n);
void merge_sort(int *arr,int n);
void merge(int *arr,int *leftArr,int l, int *rightArr,int r);
void compare_sort(int *arr,int n);
void display_arr(int *arr,int n);
void generateRandomArray(int *arr, int n);
void writeArrayToFile(int *arr, int n, char *filename);
void readArrayFromFile(int *arr, int n, char *filename);

int main()
{
     //Menu
    printf("Sorting Algorithms: Testing and Comparison Program\n");
    printf("1.Insertion Sort\n");
    printf("2.Bubble Sort\n");
    printf("3.Merge Sort\n");
    printf("4.Compare Sorting Algorithms\n");
    printf("5.Exit\n");

    int c;
    do
    {
        printf("Enter a choice:");
        scanf("%d",&c);
        //getchar();consume the newline character
    }
    while(c < 1 || c > 5);
    if(c==5)
    {
        return 0;
    }

    int size;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    //getchar consume the newline character
    int *arr = (int*)malloc(size * sizeof(int));
    generateRandomArray(arr, size); // Generate random array
    writeArrayToFile(arr, size, "input.txt"); // Write array to file
    readArrayFromFile(arr, size, "input.txt");// Read array from file

    // Function Calls
    switch(c)
    {
        case 1:
            selection_sort(arr,size);
            display_arr(arr,size);
            break;
        case 2:
            bubble_sort(arr,size);
            display_arr(arr,size);
            break;
        case 3:
            merge_sort(arr,size);
            display_arr(arr,size);
            break;
        case 4:
            compare_sort(arr,size);
            break;
        case 5:
            break;
        default :
            printf("Invalid Choice");
    }
    free(arr);
    return 0;
}
