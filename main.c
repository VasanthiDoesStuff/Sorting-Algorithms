#include <stdio.h>
#define _POSIX_C_SOURCE 200809L
#include <stdlib.h>
#include <time.h>

void selection_sort(long int arr[],long int n);
void bubble_sort(long int arr[], long int n);
void insertion_Sort(long int arr[], long int n);
void merge(long int arr[], long int leftArr[] ,long int l,long int rightArr[], long int r);
void merge_sort(long int arr[], long int n);
int main()
{
    long int size = 10000;
    double time_b[10], time_s[10], time_i[10],time_m[10];

    FILE *fp = fopen("plot_data.txt", "w");
    fprintf(fp, "Size,Bubble Sort,Selection Sort, Insertion Sort, Merge Sort\n");
    printf("A_Size \t Bubble\t Selection Insertion Merge\n");
    for(int i = 0; i < 10; i++){
        long int a[size], b[size], c[size],d[size];
        for(int j = 0; j < size; j++){
            long int num = rand() % size;
            a[j] = num;
            b[j] = num;
            c[j] = num;
            d[j] = num;
        }
        clock_t start,end;

        //Bubble Sort
        start = clock();
        bubble_sort(a,size);
        end = clock();
        time_b[i] = ((double)(end - start));

        //Selection Sort
        start = clock();
        selection_sort(b,size);
        end = clock();
        time_s[i] = ((double)(end - start));

        //insertion Sort
        start = clock();
        insertion_Sort(c,size);
        end = clock();
        time_i[i] = ((double)(end - start));

        //merge Sort
        start = clock();
        merge_sort(d,size);
        end = clock();
        time_m[i] = ((double)(end - start));




        fprintf(fp," %li, %li, %li, %li, %li \n", size, (long int)time_b[i], (long int)time_s[i], (long int)time_i[i], (long int)time_m[i]);
        printf("%li     %li     %li      %li        %li\n", size, (long int)time_b[i], (long int)time_s[i], (long int)time_i[i], (long int)time_m[i]);
        size += 1000;
    }
    fclose(fp);
    system("gnuplot plot_script.txt");

    return 0;
}
//The selection sort function
void selection_sort(long int arr[], long int n)
{
    for(long int position = 0; position < n; position++)
    {
        long int min = arr[position];
        long int min_index = position;
        for(long int i = position; i< n; i++)
        {
            if(arr[i] < min){
                min = arr[i];
                min_index = i;
            }
        }
        long int temp = arr[position];   //swap values
        arr[position] = arr[min_index];
        arr[min_index] = temp;
    }
}

//The bubble sort function
void bubble_sort(long int arr[], long int n)
{
    if(n < 2)
    {
        return ;
    }
    for(long int k = 0; k < n; k++)
    {
        for(long int i = 0; i < n-k-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                long int temp = arr[i];
                arr [i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

// Insertion sort
void insertion_Sort(long int arr[], long int n)
{
	long int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		// Move elements of arr[0..i-1], that are
		// greater than key, to one position ahead
		// of their current position
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void merge(long int arr[], long int leftArr[] ,long int l,long int rightArr[], long int r)
{
    long int i = 0, j = 0, k = 0; // i for leftArr, j for rightArr, k for arr
    while(i < l && j < r)
    {
        if(leftArr[i] > rightArr[j]) // adding the least one to array
        {
            arr[k] = rightArr[j];
            j++;
        }
        else if(leftArr[i] <= rightArr[j])
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
void merge_sort(long int arr[], long int n)
{
    if(n <=1)
    {
        return;
    }

    long int mid = n / 2;
    long int left[mid];
    long int right[n-mid];
    for (long int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (long int i = mid; i < n; i++) {
        right[i - mid] = arr[i];
    }
    merge_sort(left, mid);
    merge_sort(right, n - mid);
    merge(arr, left, mid,right, n - mid);
}


