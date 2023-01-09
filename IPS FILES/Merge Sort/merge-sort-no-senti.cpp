#include <iostream>
#include <stdlib.h>
#include <limits.h>

#define NUM_ELE(a) sizeof(a)/sizeof(a[0])

int divide(int *, int, int);
int combine(int *, int, int, int);
void print_array(int *, int);


int main()
{
   int i;
   int a[] = {4, 5, 1, 2, 5, 10, 1};
   printf("Unsorted Array is - ");
   print_array(a, NUM_ELE(a));
   printf("\n");

   divide(a, 0, NUM_ELE(a) - 1);

   printf("Sorted Array is - ");
   print_array(a, NUM_ELE(a));
   printf("\n");
}
int divide(int *a, int start, int end)
{
   int middle;

   if(start < end) {
      middle = (start + end) / 2;
      divide(a, start, middle);
      divide(a, middle + 1, end);
      combine(a, start, middle, end);
   }
   return 0;
}

int combine(int *a, int start, int middle, int end)
{
   int *L = malloc(sizeof(int) *  (middle - start +1));
   int *R = malloc(sizeof(int) * (end - middle));
   int i;
   int i_r, i_l;

   if( L == NULL || R == NULL) {
      printf("ERROR: malloc failed, may day !!!\n");
      exit(0);
   }

   /* Fill in l array */
   for(i = 0; i < middle - start + 1; i++) {
      L[i] = a[start + i];
   }

   /* Fill in r array */
   for(i = 0; i < end - middle ; i++) {
      R[i] = a[middle + i + 1];
   }

   i_l = i_r = 0;
   for(i = start; i <= end; i++) {
      if(L[i_l] <= R[i_r]) {
         /* See if L array is full,
            if Yes the copy from R array */
         if(i_l > middle - start) {
            a[i] = R[i_r++];
         } else {
            a[i] = L[i_l++];
         }
      }else {
         /* See if R array is full,
            if Yes the copy from R array */
         if(i_r >= end - middle) {
            a[i] = L[i_l++];
         }else {
            a[i] = R[i_r++];
         }
      }
   }
   free(L);
   free(R);
}