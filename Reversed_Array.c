#include <stdio.h>
int main(){
   int num, i, j, array1[50], array2[50];
   printf("Enter no of elements in array");
   scanf("%d", &num);
   printf("Enter array elements");
   for (i = 0; i < num ; i++)
      scanf("%d", &array1[i]);
 
   for (i = num - 1, j = 0; i >= 0; i--,j++)
      array2[j] = array1[i];
   for (i = 0; i < num; i++)
      array1[i] = array2[i];
   printf("The reversed array:");
   for (i = 0; i< num; i++)
      printf("%d", array1[i]);
   return 0;
}

