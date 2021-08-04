#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 255

float fx(float );
float ffx(float );
float gx(float );
void iterasi_sederhana();
void newton_raphson();

int main()
{
	int pilihan=0;
	
	puts("==========Persamaan Non-Linier Mode Terbuka==========");
	puts("1. Metode Iterasi Sederhana");
	puts("2. Metode Newton-Raphson");
	printf("Pilihan	: ");
	scanf("%i", &pilihan);
	
	switch(pilihan)
	{
		case 1 :
			iterasi_sederhana();
			break;
		case 2 :
			newton_raphson();
			break;
		default :
			printf("Input Tidak Valid");
	}
	
}

void iterasi_sederhana()
{
	float e, hasil_akar;
	int n, i;
	float x[MAX], f_x[MAX], g_x[MAX];
	
	printf("Input Titik Awal	: ");
	scanf("%f", &x[0]);
	printf("Input Jumlah Pengulangan	: ");
	scanf("%i", &n);
	printf("Input Toleransi Error	: ");
	scanf("%f", &e);
	
	g_x[0] = gx(x[0]);
	if(g_x[0]>1 || g_x[0]<-1)
		printf("Bilangan Divergen");
	else
	{
		printf("i\t x\t\t fx\t\t gx\t\n");
		for(i=0;i<n;i++)
		{
			x[i] = gx(x[i-1]);
			f_x[i] = fx(x[i]);
			g_x[i] = gx(x[i]);
			hasil_akar = x[i];
			printf("%i\t %f\t %f\t %f\t\n", i, x[i], f_x[i], g_x[i]);
		}
		printf("\nx = %f\n", hasil_akar);
	}
}

void newton_raphson()
{
	float e, hasil_akar;
	int n, i;
	float x[MAX], f_x[MAX], g_x[MAX], ff_x[MAX];
	
	printf("Input Titik Awal	: ");
	scanf("%f", &x[0]);
	printf("Input Jumlah Pengulangan	: ");
	scanf("%i", &n);
	printf("Input Toleransi Error	: ");
	scanf("%f", &e);
	
	g_x[0] = gx(x[0]);
	if(g_x[0]>1 || g_x[0]<-1)
		printf("Bilangan Divergen");
	else
	{
		printf("i\t x\t\t fx\t\t gx\t\n");
		for(i=0;i<n;i++)
		{
			f_x[i] = fx(x[i]);
			ff_x[i] = ffx(x[i]);
            x[i+1]=(x[i]-(f_x[i]/ff_x[i]));
            hasil_akar = x[i];
            printf("%i\t %f\t %f\t %f\t\n", i, x[i], f_x[i], ff_x[i]);
		}
		printf("\nx = %f\n", hasil_akar);
	}
}

float fx(float x)
{
	return (exp(-x)*x);
}

float ffx(float x)
{
	return (exp(x) + 1);
}

float gx(float x)
{
	return (x*x);
}
