#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_N 100

typedef struct {
    int TL, GT, PA;
    float DG; //don gia GT/TL
    char Ten[25];    
} Do_Vat;

void swap (Do_Vat *a, Do_Vat* b){
    Do_Vat tam = *a;
    *a = *b;
    *b = tam;
}

void sort (Do_Vat *a, int n){
	int i, j;
    for(i = 0; i < n-1; i++)
        for(j = i+1; j < n; j++)
            if(a[i].DG < a[j].DG)
                swap(&a[i], &a[j]);
}

void Nhap_DL (Do_Vat **a, int *n, int *m){
    FILE *f = fopen("CaiBalo1.txt", "r");
    *a = (Do_Vat*)malloc(sizeof(Do_Vat));
    fscanf(f, "%d", m); // m la trong luong toi da cua ba lo
    int i = 0;    
    while (!feof(f)){
        (*a) = realloc(*a, sizeof(Do_Vat)*(i+1));
        fscanf(f, "\n%d %d %[^\r\n]s", &(*a)[i].TL, &(*a)[i].GT, (*a)[i].Ten);
        (*a)[i].DG = (float)(*a)[i].GT / (*a)[i].TL;
        (*a)[i].PA = 0;
        i++;
    }
    *n = i;
    fclose(f);
}

void In_PA (Do_Vat *a, int n, int m){
    int i, k, tong_gt = 0, total_weight = 0;
    printf("|---|---------------------|-----------|-------|-------|---------|\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Don gia","Phuong an");
	printf("|---|---------------------|-----------|-------|-------|---------|\n");
	for(i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%7.2f|%9d|\n", k++, a[i].Ten, a[i].TL, a[i].GT, a[i].DG, a[i].PA);
        tong_gt += a[i].GT*a[i].PA;
        total_weight += a[i].TL*a[i].PA;
	}	
	printf("|---|---------------------|-----------|-------|-------|---------|\n");	
	printf("Phuong an (theo thu tu DG giam dan): X(");
	for(i = 0; i<n-1; i++){
		printf("%d,", a[i].PA);
	}	
	printf("%d)\n", a[n-1].PA);
	printf("Trong luong cua ba lo = %5d\n",m); //m la trong luong cua ba lo
    printf("Tong trong luong      = %5d\n", total_weight);
    printf("Tong gia tri          = %5d\n", tong_gt);
}

void solve(Do_Vat *a, int n, int p_val, int m, int x[], int i, float *final_res){
	int j, k;
	for(j = m/a[i].TL; j >= 0; j--){
		float cur_val, remain, ubound;
		cur_val= p_val + j*a[i].GT;
		remain = m - j*a[i].TL;
		ubound = cur_val + remain*a[i+1].DG;
		if(ubound > *final_res){
			x[i] = j;			
			if((i == n-1 || remain == 0) && cur_val > *final_res){
				*final_res = cur_val;
				for(k = 0; k < n; k++){
					a[k].PA = x[k];
				}		
			}
			else
				solve(a, n, cur_val, remain, x, i+1, final_res);
		}		
		x[i] = 0;	
	}
}

int main (){
	
	Do_Vat *a;
	int n, m, x[MAX_N];
	float final_res = 0;
	Nhap_DL(&a, &n, &m);
	sort(a, n);	
	solve(a, n, 0, m, x, 0, &final_res);
	In_PA(a, n, m);
	
	
}
