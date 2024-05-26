#include<stdio.h>

#define MAX_N 100

//typedef int keytype; //key  chinh, dl can sap xep
//typedef float othertype; //gia tri phu di theo

typedef struct {
	int  key;
	float other;
}Noi_Bot;

void swap(Noi_Bot *a, Noi_Bot *b){
	Noi_Bot tam;
	tam = *a;
	*a = *b;
	*b = tam;
}

//Cach 1
//void bubbleSort(Noi_Bot a[], int n){
//	int i, j;
//	for( i = 0; i < n-1; i++)		
//		for(j = n-1; j > i; j--)	//sap xep tang dan/khong giam
//			if(a[j].key < a[i].key)
//				swap(&a[i], &a[j]);
//}


//Cách 2
void bubbleSort(Noi_Bot a[], int n){
	int i, j;
	for( i = 0; i < n-1; i++)		
		for(j = i + 1; j < n; j++)	
			if(a[j].key < a[i].key)
				swap(&a[j], &a[i]);		//sap xep tang dan/khong giam, khác cách 1
}


void nhap(Noi_Bot a[], int *n){    
	FILE *f = fopen("data.txt","r");
	if(f != NULL)
        while (!feof(f)){
            fscanf(f,"%d%f",&a[*n].key , &a[*n].other);
            (*n)++;
        }
    else printf("Loi moi file\n ");

	fclose(f);
}

void in(Noi_Bot a[], int n){
	int i, dem = 0;
    for(i = 0; i < n; i++){
        printf("%3d %5d %8.2f\n", i+1, a[i].key, a[i].other); //stt, khoa, number other
        dem ++;
    }
    printf("\nCo %d gia tri!", dem);
        
}


int main (){
	Noi_Bot a[MAX_N];
	int n = 0;
	printf("Thuat toan Bubble Sort\n");
	nhap(a, &n);
	printf("Du lieu truoc khi sap xep:\n");
	in(a, n);
	bubbleSort(a, n);
	printf("\n");
	printf("Du lieu sau khi sap xep:\n");
	in(a, n);
	return 0;
}
