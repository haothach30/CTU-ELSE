
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

void InsertionSort(recordtype a[], int n){
	int i, j;
	for(i=1; i<= n-1; i++){
		j = i;
		while (a[j].key < a[j-1].key){
			swap(&a[j], &a[j-1]);
			j--;
		}
	}
}

void nhap(recordtype a[], int *n){
	int i;
	FILE *f = fopen("data.txt", "r");
	if(f != NULL)
		while(!feof(f)){
			fscanf(f, "%d%f", &a[i].key, &a[i].otherfields);
			i++;
		}else printf("Loi moi file\n");
		fclose(f);
		*n = i;
}

void in(recordtype a[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
}

main(){
	recordtype a[100];
	int n = 0;
	
	printf("Thuat toan Insertion Sort\n\n");
	nhap(a, &n);
	printf("Du lieu truoc khi sap xep\n\n");
	in(a, n);
	
	InsertionSort(a, n);
	
	printf("Du lieu sau khi sap xep\n\n");
	in(a, n);
		
	return 0;
}
