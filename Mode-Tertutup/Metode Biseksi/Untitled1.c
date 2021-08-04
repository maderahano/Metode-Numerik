#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fungsi (double);
double biseksi (double, double);

main()
{
    double x1, x2, fx1, fx2, indeks, a, temp;
    int n, i=1;

    puts("\t\t     >>>> METODE BISEKSI dan TABEL <<<<");
    puts("\t\t\t\tf(x)=e^x + x ");
    printf("  Masukan batas bawah : ");
    scanf("%lf", &x1);
    printf("  Masukan batas atas  : ");
    scanf("%lf", &x2);
    printf("  Masukan banyak iterasi : ");
    scanf("%d", &n);
    puts("  ==========================================================================");
    puts("\t\t\t\tMETODE TABEL");

    a = (x2 - x1) / n;
    fx1 = fungsi(x1);
    fx2 = fungsi(x2);
      
    temp = x1;
    puts("    no    x\t     fx");
    do
	{
        fx1 = fungsi(temp);
        fx2 = fungsi(temp+a);
        printf("  %3d  %.7lf  %.7lf\n",i,temp, fx1);
        
        if (fx1*fx2<=0)
            indeks = temp;

        fx1 = fx2;
        temp = temp + a;
        i++;
    }while(i<=n);

    printf("  Hasil berada diantara %.5lf dan %.5lf\n\n",indeks, indeks+a );
    biseksi(indeks,indeks+a);    
}
double fungsi (double a)
{
    double hasil;
    hasil =exp(a) + a;
    return hasil;
}

double biseksi (double a, double b)
{
    double c, fd,fb, fc, abs;
    int no=1;
    
    puts("\t\t\t\tMETODE BISEKSI");
    puts("  ==========================================================================");
    printf("\ta\t  b\t    c\t\tfa\t fb\t    fc\t      abs\n");
    puts("  ==========================================================================");
    for(;;no++)
	{
        c = (b +a)/2;
        fd = fungsi(a);
        fb = fungsi(b);
        fc = fungsi(c);
        abs= b-a;

        printf("%3.d %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf  %.7lf\n",no, a,b,c,fd,fb,fc, abs);
        
        if (fd*fc>=0)
            a = c;
        else
            b=c;
            
        if (abs<0 .0001="" o:p="">
        {
            printf("%3.d %.7lf %.7lf %.7lf %.7lf %.7lf %.7lf  %.7lf\n",no+1, a,b,c,fd,fb,fc, abs);
            puts("  ==========================================================================");
            break;
        }     
    }
    printf("\n Nilai x mendekati : %.9lf\n Nilai fungsi : %.9lf \nNilai absolut %.9lf",c,fc, abs);
    return(0);
}
