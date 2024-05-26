#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int TL, GT, PA;
    char Ten[25];    
} DoVat;

typedef int bang[50][100];

DoVat *Nhap_DL(int *W, int *n){
	FILE *f;
	f = fopen("QHD_CaiBalo.txt", "r");
	fscanf(f, "%d", W);
	DoVat *dsdv;
	dsdv= (DoVat*)malloc(sizeof(DoVat));
	int i = 0;
	while(!feof(f)){
		fscanf(f, "%d%d%[^\n\n]", &dsdv[i].TL, &dsdv[i].GT, &dsdv[i].Ten);
		dsdv[i].PA = 0;
		i++;
		dsdv = (DoVat*)realloc(dsdv, sizeof(DoVat)*(i + 1));
	}
	*n = i;
	fclose(f);
	return dsdv;
}


void In_PA(DoVat *dsdv, int n, int m){ //done
	int i, j, k;
    int tong_gt = 0, tong_tl = 0;
    printf("Phuong an Cai balo 1 su dung Quy hoach dong:\n");
    printf("Trong luong cua Ba lo: %-9d\n", m);
    printf("|---|---------------------|-----------|-------|---------|\n");
	printf("|%-3s|%-21s|%-11s|%-7s|%-9s|\n", "STT", "     Ten do vat", "Trong luong", "Gia tri", "Phuong an");
	printf("|---|---------------------|-----------|-------|---------|\n");
	for(i = 0, k = 1; i < n; i++){        
        printf("| %-2d| %-20s|%11d|%7d|%9d|\n", k++, dsdv[i].Ten, dsdv[i].TL, dsdv[i].GT, dsdv[i].PA);
        tong_gt += dsdv[i].GT*dsdv[i].PA;
        tong_tl += dsdv[i].TL*dsdv[i].PA;
	}	
	printf("|---|---------------------|-----------|-------|---------|\n");	
	printf("Phuong an X(");
	for(i = 0; i < n - 1; i++){
		printf("%d ", dsdv[i].PA);
		}
	printf("%d)\n", dsdv[n-1].PA);
    printf("Trong luong cua ba lo = %5d\n", m);
    printf("Tong trong luong      = %5d\n", tong_tl);
    printf("Tong gia tri          = %5d\n", tong_gt);
}

void Tao_Bang(DoVat *dsdv, int n, int m, bang F, bang X){ //done
	int xk, yk, k;
	int FMax, XMax, V;
	 
    for(V = 0; V <= m; V++){
        X[0][V] = V/dsdv[0].TL;
        F[0][V] = X[0][V] * dsdv[0].GT;
    }
    	
    for(k = 1; k < n; k++){
    	
        for(V = 0; V <= m; V++){
            FMax = F[k-1][V];
		
            XMax = 0;
		
            yk = V/dsdv[k].TL;
            for(xk = 1; xk <= yk; xk++){
                if(F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT > FMax){
                    FMax = F[k-1][V-xk*dsdv[k].TL] + xk*dsdv[k].GT;
                    XMax = xk;
                }
            }
            F[k][V] = FMax;
            X[k][V] = XMax;
        }
    }
}

void In_Bang(int n, int W, bang F, bang X){
	int V, k;
    printf("Bang quy hoach dong:\n");
	printf("============================================================================\n");  
	printf("|   ||  0      1      2      3      4      5      6      7      8     9    |\n");
	printf("----||---------------------------------------------------------------------|\n");
	for(k = 0; k < n; k++){
		printf("|%2d |", k+1);
		for(V = 0; V <= W; V++)
			printf("|%2d%2d |", F[k][V], X[k][V]);
			printf("|");
		printf("\n");
		
		}
			
	printf("============================================================================\n\n"); 
}

void Tra_Bang(DoVat *dsdv, int n, int m, bang X){
	int k , V;
	V = m;
    for(k = n-1; k >= 0; k--){
        dsdv[k].PA = X[k][V];
        V -= X[k][V]*dsdv[k].TL;
    }
}

int main (){
    int W, n;    
    DoVat *dsdv;
    bang F, X;
    dsdv = Nhap_DL(&W, &n);
    
    Tao_Bang(dsdv, n, W, F, X);
    
    In_Bang(n, W, F, X);
    
    Tra_Bang(dsdv, n, W, X);
    In_PA(dsdv, n, W);

    free(dsdv);
    return 0;
}
