#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//fungsi dari metode
void metode_reimann();
void metode_trapezoida();
void metode_simpson_1per3();
void metode_simpson_3per8();
void metode_kuadratur_2titik();
void metode_kuadratur_3titik();

//definisi fungsi
float fx1(float );
float gx1(float );
float fungsix(float );

//variabel global
int i;
float a, b, n, h, L=0, sum=0;
float x, fx, fx2, fx3, fx4;
float sigma_1=0, sigma_2=0;

int main()
{
	int pil;
	
	printf("<===============>MENU METODE INTEGRASI<===============>\n");	
	printf("1. Metode Integrasi Reimann\n");
	printf("2. Metode Integrasi Trapezoida\n");
	printf("3. Metode Integrasi Simpson 1/3\n");
	printf("4. Metode Integrasi Simpson 3/8\n");
	printf("5. Metode Integrasi Kuadratur 2 Titik\n");
	printf("6. Metode Integrasi Kuadratur 3 Titik\n");
	printf("Pilih Metode	: ");
	scanf("%i", &pil);
	
	switch(pil)
	{
		case 1:
			metode_reimann();
			puts("");
			break;
		case 2:
			metode_trapezoida();
			puts("");
			break;
		case 3:
			metode_simpson_1per3();
			puts("");
			break;
		case 4:
			metode_simpson_3per8();
			puts("");
			break;
		case 5:
			metode_kuadratur_2titik();
			puts("");
			break;
		case 6:
			metode_kuadratur_3titik();
			puts("");
			break;
		default:
			printf("Pilihan metode yang anda pilih, tidak ada dalam menu kami\n");
	}
}

void metode_reimann()
{
	printf("<===============>METODE REIMANN<===============>\n");
	printf("Input Batas Bawah (a)		: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)		: ");
	scanf("%f", &b);
	printf("Inpu Jumlah Pembagi Area (N)	: ");
	scanf("%f", &n);
	
	x = a;
	h = (b-a)/n;
	printf("-------------------------------------------------------------------------\n");
	printf("i\t\t x\t\t f(x)\t\t 2f(x)\t\t\n");
	printf("-------------------------------------------------------------------------\n");
	for(i=0;x<b;i++)
	{
		x = a+(i*h);
		fx = fx1(x);
		fx2 = 2*fx;
		sum += fx;
		if(i==0 || i==n)
			printf("%i\t\t %f\t %f\t -\t\n", i, x, fx);
		else
			printf("%i\t\t %f\t %f\t %f\t\n", i, x, fx, fx2);	
	}
	printf("-------------------------------------------------------------------------\n");
	L = h*sum;
	printf("Luas Total	: %f\n", L);
	printf("-------------------------------------------------------------------------\n");
}

void metode_trapezoida()
{
	printf("<===============>METODE TRAPEZOIDA<===============>\n");
	printf("Input Batas Bawah (a)		: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)		: ");
	scanf("%f", &b);
	printf("Inpu Jumlah Pembagi Area (N)	: ");
	scanf("%f", &n);
	
	x = a;
	h = (b-a)/n;
	printf("-------------------------------------------------------------------------\n");
	printf("i\t\t x\t\t f(x)\t\t 2f(x)\t\t\n");
	printf("-------------------------------------------------------------------------\n");
	for(i=0;x<b;i++)
	{
		x = a+(i*h);
		fx = fx1(x);
		fx2 = 2*fx;
		if(i==0 || i==n)
			sum += fx;
		else
			sum += 2*fx;
		if(i==0 || i==n)
			printf("%i\t\t %f\t %f\t -\t\n", i, x, fx);
		else
			printf("%i\t\t %f\t %f\t %f\t\n", i, x, fx, fx2);	
	}
	printf("-------------------------------------------------------------------------\n");
	L = h/2*sum;
	printf("Luas Total	: %f\n", L);
	printf("-------------------------------------------------------------------------\n");
}

void metode_simpson_1per3()
{
	printf("<===============>METODE SIMPSON 1/3<===============>\n");
	printf("Input Batas Bawah (a)		: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)		: ");
	scanf("%f", &b);
	printf("Inpu Jumlah Pembagi Area (N)	: ");
	scanf("%f", &n);
	
	x = a;
	h = (b-a)/n;
	printf("-------------------------------------------------------------------------\n");
	printf("i\t\t x\t\t f(x)\t\t 4f(x)\t\t 2f(x)\t\t\n");
	printf("-------------------------------------------------------------------------\n");
	for(i=0;x<b;i++)
	{
		x = a+(i*h);
		fx = fx1(x);
		fx2 = 2*fx;
		fx4 = 4*fx;
		
		if(i==0 || i==n)
			sum += fx;
		else if(i%2==0)
            sigma_2+=2*fx;
        else
        	sigma_1+=4*fx;
        
		if(i==0 || i==n)
			printf("%i\t\t %f\t %f\t -\t\t -\t\n", i, x, fx);
		else if(i%2==0)
			printf("%i\t\t %f\t %f\t -\t\t %f\t\n", i, x, fx, fx2);
		else
			printf("%i\t\t %f\t %f\t %f\t -\t\n", i, x, fx, fx4);
	}
	printf("-------------------------------------------------------------------------\n");
	L = (h/3)*(sum + sigma_1 + sigma_2);
	printf("Luas Total	: %f\n", L);
	printf("-------------------------------------------------------------------------\n");
}

void metode_simpson_3per8()
{
	printf("<===============>METODE SIMPSON 3/8<===============>\n");
	printf("Input Batas Bawah (a)		: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)		: ");
	scanf("%f", &b);
	printf("Inpu Jumlah Pembagi Area (N)	: ");
	scanf("%f", &n);
	
	x = a;
	h = (b-a)/n;
	printf("-------------------------------------------------------------------------\n");
	printf("i\t\t x\t\t f(x)\t\t 3f(x)\t\t 2f(x)\t\t\n");
	printf("-------------------------------------------------------------------------\n");
	for(i=0;x<b;i++)
	{
		x = a+(i*h);
		fx = fx1(x);
		fx2 = 2*fx;
		fx3 = 3*fx;
		
		if(i==0 || i==n)
			sum += fx;
        else if(i%3==0)
            sigma_2+=2*fx;
        else
            sigma_1+=3*fx;
        
		if(i==0 || i==n)
			printf("%i\t\t %f\t %f\t -\t\t -\t\n", i, x, fx);
		else if(i%3==0)
			printf("%i\t\t %f\t %f\t %f\t -\t\n", i, x, fx, fx3);
		else
			printf("%i\t\t %f\t %f\t -\t\t %f\t\n", i, x, fx, fx2);
	}
	printf("-------------------------------------------------------------------------\n");
	L = ((3*h)/8)*(sum + sigma_1 + sigma_2);
	printf("Luas Total	: %f\n", L);
	printf("-------------------------------------------------------------------------\n");
}

void metode_kuadratur_2titik()
{
	printf("<===============>METODE KUADRATUR 2 TITIK<===============>\n");
	printf("Input Batas Bawah (a)		: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)		: ");
	scanf("%f", &b);
	
	puts("");
	printf("-------------------------------------------------------------------------\n");
	L = gx1((-(1/sqrt(3)))) + gx1((1/sqrt(3)));
	printf("Luas Total	: %f\n", L);
	printf("-------------------------------------------------------------------------\n");
}

void metode_kuadratur_3titik()
{
	printf("<===============>METODE KUADRATUR 3 TITIK<===============>\n");
	printf("Input Batas Bawah (a)		: ");
	scanf("%f", &a);
	printf("Input Batas Atas (b)		: ");
	scanf("%f", &b);
	
	puts("");
	printf("-------------------------------------------------------------------------\n");
	L = ((8*gx1(0))/9) + ((5*gx1(-(3/sqrt(5))))/9) + ((5*gx1(3/sqrt(5)))/9);
	printf("Luas Total	: %f\n", L);
	printf("-------------------------------------------------------------------------\n");
}

float fx1(float x)
{
	return (exp(-pow(x,2)));
}

float gx1(float hu)
{
	return ((b-a)/2) * fx1(fungsix(hu));
}

float fungsix(float u)
{
	return (((b-a)/2)*u)+((b+a)/2);
}
