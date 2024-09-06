#include <stdio.h>

int n;
int seq[20];
int val[20];

char a[8][4]={{'A','B','C','1'},
{'O','N','M','1'},
{'I','H','G','1'},
{'J','L','K','Z'},
{'D','F','E','1'},
{'W','Y','X','1'},
{'T','U','V','S'},
{'R','Q','P','1'}};

void rec(int level) {
   //base case
   if(level==n) {
      //print
      for(int j=0;j<n;j++) {
         printf("%c",val[j]);
      }
      printf("\n");
      return;
   }

   //compute
   for(int i=0;i<4;i++){
      if(a[seq[level]-1][i]!='1') {
         val[level]=a[seq[level]-1][i];
         rec(level+1);
      }
   }

   //return
   return;
}

int main() {
   scanf("%d",&n);
   for(int i=0;i<n;i++) {
      scanf("%d",&seq[i]);
   }
   rec(0);
   return 0;
}