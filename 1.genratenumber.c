#include<stdio.h>
#include<stdlib.h>
#include<string.h> // mycode
#include<time.h> // mycode

//void clock();
int SIZE=1000000; // intializing size to 10,00,000 (10 Lakh)

int main()
{ 
    

    // generate 10,00,000 (10 Lakh) random integer and store in num.txt
    int no, j, i;
    int buffer;
    FILE *f = fopen("num.txt","a");
    for(j=0; j < SIZE; j++) 
    {
        no = rand();
        fprintf(f,"%d\n",no); 
        //printf("%d\n",no);
    }
    printf("Stored successfully\n");
    fclose(f);
    
   
    return 0;
}
