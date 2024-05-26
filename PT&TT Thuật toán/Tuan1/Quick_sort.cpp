//xs nhanh  
#include <stdio.h>
#define MAX_N 100

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
}Nhanh;


void swap(Nhanh *a, Nhanh *b){
	Nhanh tam;
	tam = *a;
	*a = *b;
	*b = tam;
}


int FindPivot(Nhanh a[], int i, int j){
	keytype firstkey;
	int k = i + 1;
	firstkey = a[i].key;
	while ((k <= j) && (a[k].key == firstkey))
		k++;
	if(k > j) 
		return -1;
	if(a[k].key > firstkey) 
		return k;
	return i;
}


int Partition(Nhanh a[], int i, int j, keytype pivot ){
	int L, R;
	L = i;
	R = j;
	while(L <= R){
		while (a[L].key < pivot)
			L++;
		while (a[R].key >= pivot)
			R--;
		if(L < R)
			swap(&a[L], &a[R]);
	}
	return L;
}



void QuickSort(Nhanh a[], int i, int j){
	keytype pivot;
	int pivotindex, k;
	pivotindex = FindPivot(a, i, j);
	
	if (pivotindex != -1){
		pivot = a[pivotindex].key;
		k = Partition(a, i, j, pivot);
		QuickSort(a, i, k-1);
		QuickSort(a, k, j);
	}
	
}



void nhap(Nhanh a[], int *n){
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

void in(Nhanh a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
	}
}

main(){
	Nhanh a[100];
	int i, j, n = 0;
	
	printf("Thuat toan Quick Sort\n\n");
	nhap(a, &n);
	printf("Du lieu truoc khi sap xep\n\n");
	in(a, n);
	
	QuickSort(a, 0, n-1);
	
	printf("Du lieu sau khi sap xep\n\n");
	in(a, n);
		
	return 0;
}
