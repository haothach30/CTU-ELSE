
#include <stdio.h>
#define MAX_N 100

typedef int keytype;
typedef float othertype;

typedef struct {
	keytype key;
	othertype otherfields;
}Heap;

void swap(Heap *a, Heap *b){
	Heap tam;
	tam = *a;
	*a = *b;
	*b = tam;
}



void PushDown(Heap a[], int first, int last){  
	int f = first;
	while (f <= (last-1) / 2){
		int L = 2*f+1, R = 2*f+2;
		if (last == L) { 
			if (a[f].key > a[L].key) 
				swap(&a[f], &a[L]);			
			return;
		}
        if ((a[f].key > a[L].key) && (a[L].key <= a[R].key)){
			swap(&a[f], &a[L]);
			f = L;
		}
        else if ((a[f].key > a[R].key) && (a[R].key < a[L].key)){
			swap(&a[f],&a[R]);
			f = R;
		}
        else return;
	}
}


void HeapSort(Heap a[], int n){
	int i;
	for(i = (n-2)/2; i >= 0; i--)
		PushDown(a, i, n-1);
	for(i = n-1; i >= 2; i--){
		swap(&a[0], &a[i]);
		PushDown(a, 0, i-1);
	}
	swap(&a[0], &a[1]);
}


void nhap(Heap a[], int *n){
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


void in(Heap a[], int n){
	int i;
	for(i = 0; i < n; i++)
		printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].otherfields);
}

main(){
	Heap a[100];
	int n = 0;
	
	printf("Thuat toan Heap Sort\n\n");
	nhap(a, &n);
	printf("Du lieu truoc khi sap xep\n\n");
	in(a, n);
	
	HeapSort(a, n);
	
	printf("Du lieu sau khi sap xep\n\n");
	in(a, n);
		
	return 0;
}
