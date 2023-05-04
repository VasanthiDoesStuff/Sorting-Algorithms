#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
void display_arr(int *arr, int n)
{
    printf("Sorted array\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

void generateRandomArray(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generate random number between 0-99
    }
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    fflush(stdout);

}

void writeArrayToFile(int *arr, int n, char *filename) {
    FILE *fptr;
    fptr = fopen(filename, "w");
    if (fptr == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%d\n", arr[i]);
    }
    fclose(fptr);
}

void readArrayFromFile(int *arr, int n, char *filename) {
    FILE *fptr;
    fptr = fopen(filename, "r");
    if (fptr == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }
    // consume any extra characters, such as newline characters
    int i = 0;
    while (fscanf(fptr, "%d", &arr[i]) == 1) {
        i++;
    }
    printf("Read %d elements from file.\n", i);
    fclose(fptr);
}
