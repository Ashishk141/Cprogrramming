/*
* C Program to Perform Quick Sort on a set of Entries from a File 
* using Recursion
*/
#include<stdio.h>
#include<time.h>
 
void quicksort (int [], int, int);
void open_numtxt();
void open_sortednumtxt();
int main()
{

    int list[1000];
    int size, i;
    printf("calling_open_numtxt()");
    open_numtxt();
    open_sortednumtxt();
 
    return 0;
}

//  quick sort program
void quicksort(int list[], int low, int high)
{
   

    int pivot, i, j, temp;

    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j) 
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quicksort(list, low, j - 1);
        quicksort(list, j + 1, high);
    }
   

}

// reading and writing operation on file
// sorting numtxt using any algorithm
void open_numtxt()
{
    //printf("\nIn open_numtxt()");
     clock_t start, end;

     /* mycode starts */
     int SIZE = 1000, no,i, j;
    int A[1000];

    FILE *f2 = fopen("num.txt", "r"); 
    if (f2 == NULL) 
    { 
       // printf("Cannot open file \n"); 
        //return 1; 
    } 
    
    int c;
    int myarray[1000];

    // Read contents from file 
    printf("reading data from file line\n");
    
    for(j=0; j < SIZE; j++)
    {
        fscanf(f2, "%d\n", &no);
        //printf("%d\n",no);
        myarray[j] = no;
    } 

    fclose(f2);

    // sending file data to function quicksort()
    
    //int i;
    start = clock();

    quicksort(myarray, 0, SIZE - 1);

    end=clock();
    double time_taken = ((double) (end-start)) / CLOCKS_PER_SEC;

    // printing sorted data to test the qucksort is working fine or not
    printf("\n -------------------------------------- \n");
    printf("After applying quick sort on (num.txt)\n");
    // for (i = 0; i < SIZE; i++)
    // {
    //     printf("%d ", myarray[i]);
    // }
    // printf("\n");
     printf("After applying quick sort on (num.txt)\n");
     printf("'You took %f seconds on (quick sort) to press a key!!!'' very slow\n",time_taken);

    fclose(f2);
    
}

void open_sortednumtxt()
{
      /* mycode starts */
     int SIZE = 1000, no,i, j;
    int A[1000];

    FILE *f2 = fopen("sortednum.txt", "r"); 
    if (f2 == NULL) 
    { 
        printf("Cannot open file \n"); 
        //return 1; 
    } 
    
    int c;
    int myarray[1000];
  
    // Read contents from file sortednum.txt
    printf("reading data from file(sortednum.txt)\n");
    
    for(j=0; j < SIZE; j++)
    {
        fscanf(f2, "%d\n", &no);
        //printf("%d\n",no);
        myarray[j] = no;
    } 

    fclose(f2);

    // sending file data to function quicksort()
    clock_t start, end;
    //int i;
    start = clock();
    quicksort(myarray, 0, SIZE - 1);
    end=clock();
    double time_taken = ((double) (end-start)) / CLOCKS_PER_SEC;
    
   

    // printing sorted data to test the qucksort is working fine or not
    printf("\n -------------------------------------- \n");
    printf("\nAfter applying quick sort on (sortednum.txt)\n");
     printf("'You took %f seconds to press a key!!!'' very slow\n",time_taken);
    // for (i = 0; i < SIZE; i++)
    // {
    //     printf("%d ", myarray[i]);
    // }
    printf("\n");

}