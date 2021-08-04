#include <stdio.h>
#include <stdlib.h>
#define MAX 255

void input();
void output();
void linier();
void satu_utama();
void swap();

int n, m;
float a[MAX][MAX], b[MAX];

int main()
{
	int sama=0;

	do
	{
		printf("Input Variabel	= ");
		fflush(stdin);
		scanf("%i", &n);
		printf("Input Persamaan	= ");
		fflush(stdin);
		scanf("%i", &m);
		if(n==m)
			sama = 	1;
		else{
			printf("Tydak sama\n");
			sama = 0;
		}		
	}while(sama==0);
	
	input();
}

void input()
{
	int i, j;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("Nilai A[%i][%i] = ", i+1, j+1);
			fflush(stdin);
			scanf("%f", &a[i][j]);
		}
	}
	for(i=0;i<3;i++){
		printf("Vektor B[%i]	= ", i+1);
		fflush(stdin);
		scanf("%f", &b[i]);
	}
	output();
	linier();
}

void output()
{
	int i, j;
	
	for(i=0;i<n;i++){
		for(j=0;j<=m;j++){
			if(j == m)
				printf("%.2f	", b[i]);
			else
				printf("%.2f	", a[i][j]);
		}
		printf("\n");
	}
}

void linier()
{
	int i, j;
	
	puts("Persamaan Linier\n");
	for(i=0;i<n;i++){
		for(j=0;j<=m;j++){
			
			if(j == m)
				printf("= %.2f", b[i]);
			else{
				if(j == m-1)
					printf("%.2fX%i%i ", a[i][j], i+1, j+1);
				else
					printf("%.2fX%i%i + ", a[i][j], i+1, j+1);
			}
		}
		printf("\n");
	}
}

void swap()
{
	
}
