#include <stdio.h>
#include <string.h>
 
/*
    Nhap xuat danh s�ch n sinh vi�n
*/
 
int main(){
    char list[1000][50]; // mang chua toi da da 1000 sinh vi�n, moi t�n sinh vi�n d�i toi da 50 k� tu
    int n;
    do{
        scanf("%d", &n);
    }while(n < 1);
 
    for(int i = 0; i < n; i++)
        fgets(list, 1000, stdin);
        if(list[strlen(list)-1]=='\n')
	    	list[strlen(list)-1]='\0';
 
 
    // Xuat danh s�ch
    for(int i = 0; i < n; i++){
        printf("%d: %s\n", i+1, list[i]);
    }
}
