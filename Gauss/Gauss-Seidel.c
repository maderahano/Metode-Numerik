#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 20

//fungsi gauss
void gauss_seidel();

//fungsi biasa
void inisialisasi();
void menu();
void input();
void output_mat();

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
		printf("1. Gauss Seidel\n");
		printf("Pilihan Anda	: ");
		fflush(stdin);
		scanf("%i", &pilihan);
		if(pilihan < 1 || pilihan > 3)
			printf("Input pilihan anda, tidak ada dalam menu metode persamaan gauss kami\n Mohon diulang lagi\n");	
	}while(pilihan != 1 && pilihan != 2 && pilihan != 3);
	switch(pilihan)
	{
		case 1:
			gauss_seidel();
			break;
		default:
			printf("Pilihan anda tidak ada di dalam menu metode kami\nSilahkan dicoba lagi!\n");
	}
}

void gauss_seidel()
{
    int i, j, iter=0, iterasi, status=0;
    float sum;
    printf("Masukkan iterasi maksimum : ");
    scanf("%d", &iterasi);
    printf("Masukkan toleransi error : ");
    scanf("%g", &error);
    for(i=0; i<baris; i++)
    {
        printf("Masukkan nilai awal %d : ", i+1);
        scanf("%f", &X[i]);
    }
    do{
    	for(i=0; i<baris; i++){
    		sum=0;
    		for(j=0; j<kolom; j++){
    			if(j!=i)
                    sum = sum + A[i][j]*X[j];
		}
		S[i] = X[i];
		X[i] = (B[i] - sum)/A[i][i];
		er[i] = fabs(X[i] - S[i]);
	}
	printf("\nIterasi ke-%d\n", iter+1);
      for(i=0; i<baris; i++){
            printf("X%d = %f\t\tError-%d = %f\n", i+1,X[i],i+1,er[i]);
            if(er[i]<error){
                status=1;
                break;
            }
        }
        iter++;
	} while(iter<iterasi && status==0);
	printf("hasil:\n");
	for(i=0; i<baris; i++)
		printf("X[%d] = %f\n", i+1, X[i]);
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

