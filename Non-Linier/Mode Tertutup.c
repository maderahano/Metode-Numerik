#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 255

void tabel();
void biseksi();
void regula_falsi();

int main()
{
	int pilihan=0;
	
	puts("Program Persamaan Non-Linier Mode Tertutup");
	puts("Pilihan Menu Metode Tertutup :");
	puts("1. Metode Tabel");
	puts("2. Metode Biseksi");
	puts("3. Metode Regula Falsi");
	printf("Pilihan = ");
	fflush(stdin);
	scanf("%i", &pilihan);
	
	switch(pilihan)
	{
        case 1 :
            tabel();
            break;
        case 2 :
            biseksi();
            break;
        case 3 :
        	regula_falsi();
        	break;
        default:
            printf("Input pilihan tidak valid.");
	}
}

void tabel()
{
	float x[MAX], fx[MAX], h=0, n, a, b;
	int  i=0;
	
	puts("===============METODE TABEL===============");
 	puts("f(x)=e^x + x ");
 	printf("Masukan batas bawah : ");
 	fflush(stdin);
 	scanf("%f", &a);
 	printf("Masukan batas atas  : ");
 	fflush(stdin);
 	scanf("%f", &b);
 	printf("Masukan banyak iterasi : ");
 	fflush(stdin);
 	scanf("%f", &n);
 	
 	puts("x\tf(x)");
	h = (b-a)/n;
	do
	{
		x[i] = a + (i*h);
		fx[i] = exp(x[i]) + x[i];
		printf("%.2f\t%.5f\n", x[i], fx[i]);
		i++;		
	}while(i<=n);
	
	for(i=0; i<n; i++)
	{
		if(fx[i]==0)
			printf("Penyelesaian dari persamaan diatas adalah %.2f", x[i]);
	}
	
	for(i=0; i<n; i++)
	{
		if(fx[i]*fx[i+1]<0)
		{
			if( fx[i] * fx[i] < fx[i+1] * fx[i+1] )
                printf("Penyelesaian dari persamaan diatas adalah %0.2f", x[i]);
            else
                printf("Penyelesaian dari persamaan diatas berada di antara %0.2f dan %0.2f", x[i], x[i+1]);
		}
	}
}

void biseksi()
{
	int i=0;
	float e, fa=0, fb=0, a, b, n;
	float x[MAX], fx[MAX], fal[MAX], fbl[MAX], fxi, isi[MAX];
	
	puts("===============METODE BISEKSI===============");
 	puts("f(x)=e^x + x ");
 	printf("Masukan batas bawah : ");
 	fflush(stdin);
 	scanf("%f", &a);
 	printf("Masukan batas atas  : ");
 	fflush(stdin);
 	scanf("%f", &b);
 	printf("Masukan banyak iterasi : ");
 	fflush(stdin);
 	scanf("%f", &n);
 	printf("Masukkan banyak toleransi error : ");
 	fflush(stdin);
 	scanf("%f", &e);
 	
 	fa = exp(a) + a;
 	fb = exp(b) + b;
 	if(fa*fb>0)
 		printf("Proses diberhentikan karena tidak ada akar dalam persamaan tersebut\n");
 	else
	{		
		puts("a\t\t b \t\t x \t\t f(x) \t\t f(a)");
 		for(i=0; i<=n; i++)
 		{
 			x[i] = (a+b)/2;
 			fx[i] = exp(x[i]) + x[i];
 			fxi = exp(x[i]) + x[i];
 			fal[i] = exp(a) + a;
 			if(fx[i]*fa<0)
 			{
 				b = x[i];
 				fb = fxi;
			}
			else
			{
				a = x[i];
				fa = fxi;
			}
			printf("%.4f\t\t %.4f \t %.4f \t %.4f \t %.4f\n", a, b, x[i], fal[i], fx[i]);
			if (((b-a)*(b-a)<e))
                isi[i]=x[i];
		}
		printf("\nAkar dari persamaan tersebut adalah %f", x[i]);
	}
}

void regula_falsi()
{
	int i=0;
	float e, fa=0, fb=0, a, b, n;
	float x[MAX], fx[MAX], fal[MAX], fbl[MAX], fxi, isi[MAX];
	
	puts("===============METODE REGULA FALSI===============");
 	puts("f(x)=e^x + x ");
 	printf("Masukan batas bawah : ");
 	fflush(stdin);
 	scanf("%f", &a);
 	printf("Masukan batas atas  : ");
 	fflush(stdin);
 	scanf("%f", &b);
 	printf("Masukan banyak iterasi : ");
 	fflush(stdin);
 	scanf("%f", &n);
 	printf("Masukkan banyak toleransi error : ");
 	fflush(stdin);
 	scanf("%f", &e);
 	
 	fa = exp(a) + a;
 	fb = exp(b) + b;
 	if(fa*fb>0)
 		printf("Proses diberhentikan karena tidak ada akar dalam persamaan tersebut\n");
 	else
	{		
		puts("a\t\t b \t\t x \t\t f(x) \t\t f(a)");
 		for(i=0; i<=n; i++)
 		{
 			x[i] = (fb*a-fa*b)/(fb-fa);
 			fx[i] = exp(x[i]) + x[i];
 			fxi = exp(x[i]) + x[i];
 			fal[i] = exp(a) + a;
 			if(fx[i]*fa<0)
 			{
 				b = x[i];
 				fb = fxi;
			}
			else
			{
				a = x[i];
				fa = fxi;
			}
			printf("%.4f\t\t %.4f \t %.4f \t %.4f \t %.4f\n", a, b, x[i], fal[i], fx[i]);
			if (((b-a)*(b-a)<e))
                isi[i]=x[i];
		}
		printf("\nAkar dari persamaan tersebut adalah %.4f", a);
	}
}
