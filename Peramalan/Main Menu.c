#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 255

//fungsi dari metode
void metode_linier_trend();

//definisi fungsi
void menu();

//variabel global
int i, choice, n, t[max], t2[max], tr;
float dt[max], t_dt[max], dtt[max];
float sum_dt, sum_t_dt, sum_t, sum_t2, sum_error, hasil_ramalan;
float a, b, selisih_error, hasil_selisih, rata_error;
char jawab;

int main()
{
	menu();
	return 0;
}

void menu()
{
	printf("<===============>MENU METODE PERAMALAN<===============>\n");	
	printf("1. Metode Linier Trend\n");
	printf("Pilih Metode	: ");
	scanf("%i", &choice);
	
	switch(choice)
	{
		case 1:
			metode_linier_trend();
			puts("");
			break;
		default:
			printf("Pilihan metode yang anda pilih, tidak ada dalam menu kami\n");
	}
}

void metode_linier_trend()
{
	sum_dt = 0;
	sum_t_dt = 0; 
	sum_t = 0; 
	sum_t2 = 0;
	sum_error = 0;
	
	printf("<===============>METODE LINIER TREND<===============>\n");
	printf("Input Jumlah Data (n)	: ");
	scanf("%i", &n);
	for(i=1;i<=n;i++)
	{
		printf("Titik ke-%i\n", i);
		printf("Data t ke-%i : ", i);
		fflush(stdin);
		scanf("%i", &t[i]);
		printf("Data dt ke-%i : ", i);
		fflush(stdin);
		scanf("%f", &dt[i]);
		puts("");
	}
	
	for(i=1;i<=n;i++)
	{
		t_dt[i] = t[i]*dt[i];
		t2[i] = pow(t[i], 2);
		sum_dt = sum_dt + dt[i];
		sum_t_dt = sum_t_dt + t_dt[i];
		sum_t = sum_t + t[i];
		sum_t2 = sum_t2 + t2[i];
	}
	
	b = ((n*sum_t_dt)-(sum_dt*sum_t))/(n*sum_t2-pow(sum_t,2));
	a = (sum_dt-(b*sum_t))/n;
	printf("--------------------------------------------------------------\n");
	printf("t\t dt\t t*dt\t t2\t dtt\t\t (dt-dtt)2\n");
	printf("--------------------------------------------------------------\n");
	for(i=1;i<=n;i++)
	{
		dtt[i] = a + b*t[i];
		selisih_error = dt[i] - dtt[i];
		hasil_selisih = pow(selisih_error,2);
		sum_error = sum_error + hasil_selisih;
		printf("%i\t %.0f\t %.0f\t %i\t %f\t %f\n", t[i], dt[i], t_dt[i], t2[i], dtt[i], hasil_selisih);	
	}
	printf("--------------------------------------------------------------\n");
	rata_error = sum_error/n;
	printf("%.0f\t %.0f\t %.0f\t %.0f\t -\t\t %f\n", sum_t, sum_dt, sum_t_dt, sum_t2, rata_error);
	printf("--------------------------------------------------------------\n");
	
	do
	{
		printf("\nIngin Meramal (y/n)? ");
		fflush(stdin);
		scanf("%c", &jawab);
		if(jawab == 'N' || jawab == 'n')
			exit(0);
		printf("Input Ramalan t : ");
		fflush(stdin);
		scanf("%i", &tr);
		hasil_ramalan = a + b*tr;
		printf("Hasil ramalan d't ke-%i adalah %.2f", tr, hasil_ramalan);
		puts("");
	}while(jawab=='Y' || jawab=='y');
}
