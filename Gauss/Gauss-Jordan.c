#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 20

//fungsi gauss
void gauss();
void gauss_jordan();

//fungsi operasi
void satu_utama(int);
void nol_bawah(int);
void tukar(int, int);

//fungsi biasa
void inisialisasi();
void menu();
void input();
void output_mat();
void find_x();

//variabel global
int baris, kolom;
float awalA[max][max], awalB[max], A[max][max], B[max], x[max], X[max], error, S[max], er[max];

int main()
{
	int sama=0;
	
	do
	{
		printf("Input Variabel	: ");
		fflush(stdin);
		scanf("%i", &kolom);
		printf("Input Persamaan	: ");
		fflush(stdin);
		scanf("%i", &baris);
		if(kolom==baris)
		{
			sama = 1;	
		}else
		{
			printf("Input Variabel dengan Persamaan tidak sama\nMohon diulang kembali\n");
			sama = 0;
		}
	}while(sama==0);
	menu();
}

void menu()
{
	int pilihan = 0;
	
	input();
	do
	{
		inisialisasi();
		printf("===============MENU METODE-METODE PERSAMAAN GAUSS===============\n");
		printf("1. Gauss Jordan\n");
		printf("Pilihan Anda	: ");
		fflush(stdin);
		scanf("%i", &pilihan);
		if(pilihan < 1 || pilihan > 3)
			printf("Input pilihan anda, tidak ada dalam menu metode persamaan gauss kami\n Mohon diulang lagi\n");	
	}while(pilihan != 1 && pilihan != 2 && pilihan != 3);
	switch(pilihan)
	{
		case 1:
			gauss();
            gauss_jordan();
			break;
		default:
			printf("Pilihan anda tidak ada di dalam menu metode kami\nSilahkan dicoba lagi!\n");
	}
}

void gauss()
{
	int i;
	for(i=0;i<baris;i++)
	{
		satu_utama(i);
		nol_bawah(i);
	}
}

void gauss_jordan(){
	int a, i, n, z;
	float k;
	for(n=kolom-1; n>=1; n--)
	{
		for(a=n-1; a>=0; a--){
			k = A[a][n];
			for(i=0; i<kolom; i++)
				A[a][i]=A[a][i] - k*A[n][i];
			B[a]=B[a] - k*B[n];
		}
		printf("\n0 kan diatas A[%d][%d]\n", n+1, n+1);
		output_mat();
	}
	printf("\nMatriks Gauss Jordan\n");
	output_mat();
	printf("\nHasil X:\n");
    for(z=0; z<baris; z++)
        printf("x%d = %g\n", z+1, B[z]);
}

void inisialisasi()
{
    int i,j;
    for(i=0; i<baris; i++)
    {
        B[i] = awalB[i];
        for(j=0; j<kolom; j++)
            A[i][j] = awalA[i][j];
    }
}

void input()
{
	int j, k;
	printf("==========INPUT DATA NILAI==========\n");
	if(baris==kolom){
		for (j = 0; j < baris; j++)
		{
			for (k = 0; k < kolom; k++)
			{
				fflush(stdin);
				printf("Nilai A[%i][%i] = ", j+1, k+1);
				scanf("%f", &A[j][k]);
			}
			printf("Vektor B[%i] = ", j+1);
			fflush(stdin);
			scanf("%f", &B[j]);
		}
		for(j=0; j<baris ; j++)
	      {
	        for(k=0; k<kolom ; k++)
	            awalA[j][k] = A[j][k];
	        awalB[j] = B[j];
	      }
	}else{
		printf("\njumlah baris dan kolom harus sama agar jadi matrix persegi\n");
	}
}

void output_mat()
{
	int k, l, flag=1;
	puts("");
	printf("==========MATRIKS AUGMENTED==========\n");
	for (k = 0; k < baris; k++)
	{
		for (l= 0; l < kolom; l++)
		{
			printf("%g\t", A[k][l]);
		}
		printf("|\t%g\n", B[k]);
	}
}

void satu_utama(int b)
{
	int i, k;
	if(A[b][b]!=1){
		if(A[b][b]==0){
			k = b+1;
			while(A[k][b]==0){
				k++;
				if(k==baris){
					printf("\nPerhitungan dihentikan karena kolom di bawah satu utama terdiri atas angka 0");
					exit(0);
				}
			}
			tukar(b, k);
			printf("\nHasil penukaran baris ke-%d", b+1);
			output_mat();
		}
		B[b]=B[b]/A[b][b];
		for(i=kolom-1;i>=0; i--)
			A[b][i]=(A[b][i])/A[b][b];
	}
	printf("\nHasil satu utama baris ke-%d", b+1);
	output_mat();

}

void tukar(int b, int l)
{
	float tempA, tempB;
	int i;
	for(i=kolom-1; i>=0; i--){
		tempA=A[b][i];
		A[b][i]=A[l][i];
		A[l][i]=tempA;
	}
	tempB=B[b];
	B[b]=B[l];
	B[l]=tempB;
}

void find_x()
{
    int m,n, j;
    float sum;
    x[baris-1] = B[baris-1];
    for(m=baris-2 ; m>=0; m--)
    {
        sum=0;
        for(n=m+1 ; n<kolom; n++)
            sum += A[m][n] * x[n];
        x[m] = B[m] - sum;
    }
    printf("\nHasil X:\n");
    for(j=0; j<kolom; j++)
        printf("X%d = %g\n", j+1, x[j]);
}

void nol_bawah(int b)
{
	int j, i;
	float bantu;
	for(j=b+1; j<baris ; j++){
		bantu=A[j][b];
		for(i=0; i<kolom; i++)
			A[j][i]=A[j][i] - bantu*(A[b][i]);
		B[j] = B[j] - bantu*(B[b]);
	}
	if(b!=baris-1)
        printf("\n0 kan dibawah a[%d][%d]", b+1, b+1);
    else
        printf("\nMatriks Gauss\n");
    output_mat();
}
