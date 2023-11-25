#include <stdio.h>
#include <stdlib.h>
#include "magazin.h"
#include <string.h>

void write(struct stroika *arr, int n){
if(n<=0)
return;
FILE * f = fopen("stroika.txt", "w");
if(!f)
return;
fprintf(f, "%d\n", n);
for(int i = 0; i<n; i++)
fprintf(f, "%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
fclose(f);
}

void read(struct stroika **arr, int *n){
FILE *f = fopen("stroika.txt", "r");
if(!f)
return;
if(fscanf(f, "%d", n) != 1)
return;
if(*n<=0)
return;
*arr = (struct stroika*)calloc(*n, sizeof(struct stroika));
for (int i = 0; i<*n; i++)
fscanf(f, "%s %s %s %d", (*arr)[i].name, (*arr)[i].color, (*arr)[i].whomade, &(*arr)[i].price);
fclose(f);
}

void create(struct stroika **arr, int *n){
printf("n=");
scanf("%d", n);
if(*n <= 0)
return;
*arr = (struct stroika*)calloc(*n, sizeof(struct stroika));
for(int i = 0; i < *n; i++){
printf("Название стройматериала: ");
scanf("%s", (*arr)[i].name);
printf("Цвет: ");
scanf("%s", (*arr)[i].color);
printf("Производитель: ");
scanf("%s", (*arr)[i].whomade);
while(1){
printf("Цена за 1 кг в рублях: ");
if(scanf("%d", &(*arr)[i].price) == 1) {
break;
}
else{
printf("Некорректный ввод цены. Введите число.\n");
while(getchar() != '\n');
}
}
}
}

void find(struct stroika *arr, int n){
FILE *f = fopen("j.txt", "r");
if(!f)
return;
char search[40];
printf("Введите название стройматериала: ");
scanf("%s", search);
int found = 0;
int key;
int count = 0;
for(int i = 0; i < n; i++){
if(strcmp(arr[i].name, search) == 0){
found = 1;
count++;
}
}
if(!found){
printf("Стройматериал не найден\n");
fclose(f);
return;
}
printf("Выберите критерий, по которому вы хотите найти товар:\n");
printf("1 - Цвет\n");
printf("2 - Производитель\n");
printf("3 - Цена\n");
scanf("%d", &key);
switch(key){
case 1:
char color[40];
printf("Введите цвет: ");
scanf("%s", color);
for(int i = 0; i < n; i++){
if(strcmp(arr[i].name, search) == 0 && strcmp(arr[i].color, color) == 0){
printf("%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
found = 1;
count++;
}
}
break;
case 2:
char whomade[40];
printf("Введите производителя: ");
scanf("%s", whomade);
for(int i = 0; i < n; i++){
if(strcmp(arr[i].name, search) == 0 && strcmp(arr[i].whomade, whomade) == 0){
printf("%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
found = 1;
count++;
}
}
break;
case 3:
int price;
printf("Введите цену: ");
scanf("%d", &price);
for(int i = 0; i < n; i++){
if(strcmp(arr[i].name, search) == 0 && arr[i].price == price){
printf("%s %s %s %d\n", arr[i].name, arr[i].color, arr[i].whomade, arr[i].price);
found = 1;
count++;
}
}
break;
default:
printf("Некорректный ввод критерия.\n");
break;
}
if(count == 0)
printf("Стройматериал не найден\n");
fclose(f);
}

