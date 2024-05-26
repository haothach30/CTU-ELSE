#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int val, qty; //qty la sl to tien
    char s[25];    
} atm;

void swap (atm *a, atm *b){
    atm tam = *a;
    *a = *b;
    *b = tam;
}

void sort (atm *m, int n){ //bubble sort
	int i, j;
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(&m[i].val < &m[j].val)
                swap(&m[i], &m[j]);    
}

void nhap (atm **m, int *n){
	FILE *f;
    f = fopen("ATM.txt", "r");
    (*m )= (atm*)malloc(sizeof(atm));
    int i = 0;
    while(!feof(f)){
        *m = (atm*)realloc(*m, sizeof(atm)*(i+1));
        fscanf(f, "%d %[^\n]s", &(*m)[i].val, 	&(*m)[i].s);
        
        (*m)[i].s[strlen((*m)[i].s) - 1] = '\0';
        (*m)[i].qty = 0;
        
        i++;
    }
    *n = i;
}

void printChart (atm *m, int n, int t){
    int i, k, total = 0;
	printf("\n|---|---------------------|----------|-------|----------|\n");
	printf("|%-3s|%-21s|%-10s|%-7s|%-10s|\n", 
			  "STT", "      Loai tien", " Menh Gia", " So to", "Thanh tien");
	printf("|---|---------------------|----------|-------|----------|\n");
	
	for(i = 0, k = 1; i < n; i++){
        if(m[i].qty){
            printf("| %-2d| %-20s| %9d|   %-4d| %9d|\n", k++, m[i].s, m[i].val, m[i].qty, m[i].val*m[i].qty);
            total += m[i].val*m[i].qty;
        }
	}	
	
	printf("|---|---------------------|----------|-------|----------|\n");
    printf("So tien can rut  = %9d\n", t);
    printf("So tien da tra   = %9d\n", total);
    printf("So tien chua tra = %9d", t - total); //so tien can rut tru cho tong cac menh gia
}

void greedy (atm *m, int n, int t){    
    int i = 0;
    while (i < n && t > 0) {
        m[i].qty = t / m[i].val;
        t -= m[i].qty*m[i].val;
        i++;
    }    
}

int main() {
    atm *m;
    int n = 0, t; // t la so tien can rut
    nhap(&m, &n);    
    printf("Nhap so tien can rut: ");
    scanf("%d", &t);
    sort(m, n); //sx to tien menh gia giam dan
    greedy(m, n, t);
    printChart(m, n, t);
    printf("\n");
    free(m);
}
