#include <stdio.h>
int main() {
   int a, b, i, hcf;

   scanf("%d%d", &a, &b);

   for(i = 1; i <= a || i <= b; i++) 
   {
   if( a%i == 0 && b%i == 0 )
      hcf = i;
   }

   printf("%0.1d", hcf);

   return 0;
}
