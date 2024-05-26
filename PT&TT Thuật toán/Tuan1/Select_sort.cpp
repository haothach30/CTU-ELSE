//Select Sort   
#include <stdio.h>
#define MAX_N 100
typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
}recordtype;

void swap(recordtype *a, recordtype *b){
	recordtype tam;
	tam = *a;
	*a = *b;
	*b = tam;
}

void SelectionSort(recordtype a[], int n){
	int i, j, lowindex;
	keytype lowkey;
	for(i = 0; i <= n - 2; i++){
		lowkey = a[i].key;
		lowindex = i;
		for(j = i+1; j <= n-1; j++){
			if(a[j].key <lowkey){
				lowkey = a[j].key;
				lowindex = j;
			}
		}
		swap(&a[i], &a[lowindex]);
	}
	
}

void nhap(recordtype a[], int *n){
	int i;
	FILE *f = fopen("data.txt", "r");
	if(f != NULL)
		while(!feof(f)){
			fscanf(f, "%d%f", &a[*n].key, &a[*n].otherfields);
			(*n)++;
		}else printf("Loi moi file\n");
		fclose(f);
}

void in(recordtype a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
	}
}

main(){
	recordtype a[100];
	int n = 0;
	
	printf("Thuat toan Selection Sort\n\n");
	nhap(a, &n);
	printf("Du lieu truoc khi sap xep\n\n");
	in(a, n);
	
	SelectionSort(a, n);
	
	printf("Du lieu sau khi sap xep\n\n");
	in(a, n);
		
	return 0;
}
