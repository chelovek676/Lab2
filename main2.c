#include <stdio.h>
#include <stdlib.h>
#include "magazin.h"

int main(){
struct stroika * arr = NULL;
int n = 0;
int stop = 0;
while (stop!=1){
int key;
printf("1-create 2-read 3-write 4-find\n");
scanf("%d", &key);
switch(key){
case 1:
create(&arr, &n);
if(arr)
write(arr, n);
break;
case 2:
read(&arr, &n);
if(!arr)
printf("read error\n");
else
printf("loaded %d\n", n);
break;
case 3:
for(int i = 0; i < n; i++)
printf("%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
break;
case 4:
find(arr, n);
break;
default:
stop = 1;
break;
}
}
if(arr)
free(arr);
return 0;
}
