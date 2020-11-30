/*
* C Program to Perform Quick Sort on a set of Entries from a File 
* using Recursion
*/
#include <stdio.h>
void quicksort (int [], int, int);
void open_numtxt();
void open_sortednumtxt(int [], int);
int main()
{
    int list[50];
    int size, i;
    
    printf("2.soritingnumber.c main()");
    open_numtxt();
 
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
void open_numtxt()
{
    printf("open_numtxt");
     /* mycode starts */
     int SIZE = 1000000, no,i, j;
    int A[1000000];

    FILE *f2 = fopen("num.txt", "r"); 
    if (f2 == NULL) 
    { 
        printf("Cannot open file \n"); 
        //return 1; 
    } 
    
    int c;
    int myarray[1000000];

    // Read contents from file 
    printf("reading data from file\n");
    
    for(j=0; j < SIZE; j++)
    {
        fscanf(f2, "%d\n", &no);
        printf("%d\n",no);
        myarray[j] = no;
    } 

    fclose(f2);

    // sending file data to function quicksort()
    quicksort(myarray, 0, SIZE - 1);

    // printing sorted data to test the qucksort is working fine or not
    printf("After applying quick sort on (num.txt)\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d ", myarray[i]);
    }
    printf("\n");


    // writing sorted data on file sortednum.txt
    printf("writing sorted data on the file : sortednum.txt\n");

    FILE *f3 = fopen("sortednum.txt", "w");
    for(j=0; j < SIZE; j++)
    {
        fprintf(f3, "%d\n", myarray[j]);
        printf("%d\n",myarray[j]);
        
    } 

    fclose(f3);
    
}