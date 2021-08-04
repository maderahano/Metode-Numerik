#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//fungsi dari metode
void metode_maju();
void metode_tengahan();
void metode_mundur();

//definisi fungsi
float fx_maju(float );
float fx_tengahan(float );
float fx_mundur(float );
float fx1(float );
float fx2(float );
float fx3(float );

//variabel global
float a, b, h;
float xo, x, fx, fxt, eksak, error;

int main()
{
	int pil;
	
	printf("<===============>MENU METODE DIFERENSIASI<===============>\n");	
	printf("1. Selisih Maju\n");
	printf("2. Selisih Tengahan\n");
	printf("3. Selisih Mundur\n");
	printf("Pilih Metode	: ");
	scanf("%i", &pil);
	
	switch(pil)
	{
		case 1:
			metode_maju();
			puts("");
			break;
		case 2:
			metode_tengahan();
			puts("");
			break;
		case 3:
			metode_mundur();
			puts("");
			break;
		default:
			printf("Pilihan metode yang anda pilih, tidak ada dalam menu kami\n");
	}
}

void metode_maju()
{
	int i;
	
	printf("<===============>METODE SELISIH MAJU<===============>\n");
	printf("Input h			: ");
	scanf("%f", &h);
	printf("Input Batas Bawah (a)	: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)	: ");
	scanf("%f", &b);
	
	xo = a;
	printf("i\t\t x\t\t f(x)\t\t f'(x)\t\t eksak\t\t error\n");
	for(i=0;x<b;i++)
	{
		x = xo + i*h;
		fx = fx1(x);
		fxt = fx_maju(x);
		eksak = fx2(x);
		error = (h*fx3(x))/2;
		printf("%i\t\t %f\t %f\t %f\t %f\t %f\t\n", i, x, fx, fxt, eksak, error);	
	}
}

void metode_tengahan()
{
	int i;
	
	printf("<===============>METODE SELISIH TENGAHAN<===============>\n");
	printf("Input h			: ");
	scanf("%f", &h);
	printf("Input Batas Bawah (a)	: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)	: ");
	scanf("%f", &b);
	
	xo = a;
	printf("i\t\t x\t\t f(x)\t\t f'(x)\t\t eksak\t\t error\n");
	for(i=0;x<b;i++)
	{
		x = xo + i*h;
		fx = fx1(x);
		fxt = fx_tengahan(x);
		eksak = fx2(x);
		error = (h*fx3(x))/2;
		printf("%i\t\t %f\t %f\t %f\t %f\t %f\t\n", i, x, fx, fxt, eksak, error);	
	}
}

void metode_mundur()
{
	int i;
	
	printf("<===============>METODE SELISIH MUNDUR<===============>\n");
	printf("Input h			: ");
	scanf("%f", &h);
	printf("Input Batas Bawah (a)	: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)	: ");
	scanf("%f", &b);
	
	xo = a;
	printf("i\t\t x\t\t f(x)\t\t f'(x)\t\t eksak\t\t error\n");
	for(i=0;x<b;i++)
	{
		x = xo + i*h;
		fx = fx1(x);
		fxt = fx_mundur(x);
		eksak = fx2(x);
		error = (h*fx3(x))/2;
		printf("%i\t\t %f\t %f\t %f\t %f\t %f\t\n", i, x, fx, fxt, eksak, error);	
	}
}

float fx_maju(float x)
{
	return (fx1(x+h)-fx1(x))/h;
}

float fx_tengahan(float x)
{
	return (fx1(x+h)-fx1(x-h))/2*h;
}

float fx_mundur(float x)
{
	return (fx1(x)-fx1(x-h))/h;
}

float fx1(float x)
{
	return cos(x);
}

float fx2(float x)
{
	return -exp(-x)*(sin(x)+cos(x));
}

float fx3(float x)
{
	return -2*exp(-x)*sin(x);
}
