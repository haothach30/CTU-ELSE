//tham an
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int w, v, qty; //trong luong, gia
    float gmh; //gia mat hang
    char name[25]; //ten mat hang   
} item;

void swap (item *a, item* b){
    item tam = *a;
    *a = *b;
    *b = tam;
}

void sort (item *a, int n){
	int i, j;
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(a[i].gmh < a[j].gmh)
                swap(&a[i], &a[j]);
}

void readFile (item **a, int *n, int *m){    
    FILE *f = fopen("CaiBalo1.txt", "r");
    *a = (item*)malloc(sizeof(item));
    fscanf(f, "%d", m);
    int i = 0;    
    while (!feof(f)){
        (*a) = realloc(*a, sizeof(item)*(i+1));
        fscanf(f, "\n%d %d %[^\n]s", &(*a)[i].w, &(*a)[i].v, (*a)[i].name);
        
        (*a)[i].gmh = (float)(*a)[i].v / (*a)[i].w;
        (*a)[i].qty = 0;
        
        i++;
    }
    *n = i;
    fclose(f);
}

void printChart (item *a, int n){
    int i, k, w, total_val = 0, total_weight = 0;
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
	printf("|---|---------------------|-----------|-------|-------|---------|\n");
	for(i = 0, k = 1; i < n; i++){        //bien k de diem stt
        printf("| %-2d| %-20s|%11d|%7d|%7.1f|%9d|\n", k++, a[i].name, a[i].w, a[i].v, a[i].gmh, a[i].qty);
        total_val += a[i].v*a[i].qty;
        total_weight += a[i].w*a[i].qty;
	}	
	printf("|---|---------------------|-----------|-------|-------|---------|\n");	
	printf("Phuong an (theo thu tu DG giam dan): X(");
	
	for(i=0; i<n-1; i++){
		printf("%d,", a[i].qty);
	}	
	printf("%d)\n", a[n-1].qty);
	
    printf("Tong trong luong = %5d\n", total_weight);
    printf("Tong gia tri     = %5d\n", total_val);
}

void greedy(item *a, int n, int m){
	int i;
    for(i = 0; i < n; i++){
        a[i].qty = m / a[i].w;
        m -= a[i].w * a[i].qty;
    }
}

int main (){
    int n = 0, m = 0;
    item *a;
    readFile(&a, &n, &m);
    sort(a, n);
    greedy(a, n, m);
    printChart(a, n);
    free(a);
}
