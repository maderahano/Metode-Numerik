//program metode numerik integrasi numerik DENGAN MENU//
#include"stdio.h"
#include<math.h>
#include<stdlib.h>

double n,a,b,h,x;

double f(double x){
    //return(-cos(x)+1);
    return(x*x);
}

double feksak(double x){
    return pow(x,3)/3;
}

double gu(double u){
    return ( ((b-a)/2) * f( ( ( (b-a)/2)*u) + ( (b+a)/2) ) );
}
void reiman(){
    double luas=0;
    int i=0;
    printf("masukan batas atas(b): ");
    scanf("%lf",&b);
    printf("masukan batas bawah(a): ");
    scanf("%lf",&a);
    printf("masukan jumlah pembagi : ");
    scanf("%lf",&n);
    h=(b-a)/n;
    x=a;
    puts("\n");
    printf(" %4s  |%7s   |%7s   |%7s  \n", "i", "x", "f(x)","feksak(x)");
    while(x<=b){
        printf(" %4d  |%7lf  |%7lf  |%7lf \n", i, x, f(x),feksak(x));
        luas=luas+(h*f(x));
        x=x+h;
        i++;
    }
    printf("\nLUAS TOTAL =%lf\n",luas);
    printf("f eksak = %g\n",feksak(b)-feksak(a));
    printf("error = %g\n",fabs(luas-feksak(b)-feksak(a)));
}

void trapezoid(){
    int i=0;
    double luas=0, eror, sigma=0, total=0.0,f_eksak;

    printf("masukan batas atas(b): ");
    scanf("%lf",&b);
    printf("masukan batas bawah(a): ");
    scanf("%lf",&a);
    printf("masukan jumlah pembagi : ");
    scanf("%lf",&n);

    h = (b-a) / n;
       printf(" %4s  |%8s   |%8s   |%8s  \n\n", "i", "x", "f(x)","feksak(x)");
    x=a;
    for(x=a;x<b;x+=h)
    {
        luas=h/2*(f(x)+f(x+h));
        printf(" %4d  |%8lf  |%8lf  |%8lf \n", i, x, f(x),feksak(x));
        total=total+luas;
        i++;
    }
    puts("\n");
    f_eksak = feksak(b) - feksak(a);
    //luas = ( (h/2) * ( f(a) + (2*sigma) + f(b) ) );
    eror = fabs( fabs(luas) - fabs(f_eksak) );
   
    printf("Luas total = %7.5lf\n", total);
    printf("f_eksak = %7.5lf\n", f_eksak);
    printf("Error = %g\n", eror);
}

void simpson(){
    int i=0;
    double luas=0, eror, sigma1=0,sigma2=0, total=0.0,f_eksak;
    printf("masukan batas atas(b): ");
    scanf("%lf",&b);
    printf("masukan batas bawah(a): ");
    scanf("%lf",&a);
    printf("masukan jumlah pembagi : ");
    scanf("%lf",&n);

    h = (b-a) / n;
       printf(" %4s  |%8s   |%8s   |%8s  \n\n", "i", "x", "f(x)","feksak(x)");
    x=a;//batas bawah
   
    while(x<=b){
        printf(" %4d  |%8lf  |%8lf  |%8lf \n", i, x, f(x),feksak(x));
       
        if(i%2==0){
            sigma2+=2*f(x);//untuk fungsi genap
        }
        else{
            sigma1+=4*f(x);//untuk fungsi ganjil
        }
        x=x+h;
        i++;
    }
    f_eksak=feksak(b)-feksak(a);
    luas=((h/3)*(f(a)+sigma2+sigma1+f(b)));//simpson per dua
    eror = fabs( fabs(luas) - fabs(f_eksak) );//untuk mencari nilai error
   
    printf("Luas total = %7.5lf\n", luas);
    printf("f eksak = %7.5lf\n", f_eksak);
    printf("Error = %g\n", eror);
}

void simpson3per8(){
    int i=0;
    double luas=0, eror, sigma1=0,sigma2=0, total=0.0,f_eksak;
    printf("masukan batas atas(b): ");
    scanf("%lf",&b);
    printf("masukan batas bawah(a): ");
    scanf("%lf",&a);
    printf("masukan jumlah pembagi : ");
    scanf("%lf",&n);

    h = (b-a) / n;
       printf(" %4s  |%8.4s   |%8.4s   |%8s  \n\n", "i", "x", "f(x)","feksak(x)");
    x=a;//batas bawah
   
    while(x<b){
        printf(" %4d  |%8.4lf  |%8.4lf  |%8lf \n", i, x, f(x),feksak(x));
       
        if(i%3==0){
            sigma2+=2*f(x);//untuk fungsi genap
        }
        else{
            sigma1+=3*f(x);//untuk fungsi ganjil
        }
        x=x+h;
        i++;
    }
    f_eksak=feksak(b)-feksak(a);
    luas=((3*h/8)*(f(a)+sigma2+sigma1+f(b)));//simpson per 3/8
    eror = fabs( fabs(luas) - fabs(f_eksak) );//untuk mencari nilai error
   
    printf("Luas total = %7.5lf\n", luas);
    printf("f eksak = %7.5lf\n", f_eksak);
    printf("Error = %g\n", eror);
}

void kuadratur2titik(){
    int i=0;
    double luas=0, eror, sigma1=0,sigma2=0, total=0.0,f_eksak;
    printf("masukan batas atas(b): ");
    scanf("%lf",&b);
    printf("masukan batas bawah(a): ");
    scanf("%lf",&a);
   
    puts("");
    f_eksak = feksak(b) - feksak(a);
    luas = gu((-(1/sqrt(3)))) + gu((1/sqrt(3))) ;//rumus luas kuadratur gauss 2 titik
    eror = fabs( fabs(luas) - fabs(f_eksak) );   
    printf("Luas total = %7.5lf\n", luas);
    printf("f eksak = %7.5lf\n", f_eksak);
    printf("Error = %lg\n", eror);
}

void kuadratur3(){
    int i=0;
    double luas=0, eror, sigma1=0,sigma2=0, total=0.0,f_eksak;
    printf("masukan batas atas(b): ");
    scanf("%lf",&b);
    printf("masukan batas bawah(a): ");
    scanf("%lf",&a);
    puts("");
    f_eksak = feksak(b) - feksak(a);
    luas = (0.8888*gu(0))+(0.5555*gu(-(sqrt(0.6))))+(0.5555*gu(sqrt(0.6)));//rumus luas kuadratur gauss 2 titik
    luas = ( (8 * gu(0)) / 9 ) + ( (5 * gu( ( -(sqrt(3/5)) ) ) ) / 9 ) + ( (5 * gu(( (sqrt(3/5)) ))) / 9 ) ;
    eror = fabs( fabs(luas) - fabs(f_eksak) );
    printf("Luas total = %7.5lf\n", luas);
    printf("f eksak = %7.5lf\n", f_eksak);
    printf("Error = %lg\n", eror);
}

main(){
    char pil,jawab;
    puts("\t PRGRAM INTEGRASI NUMERIK");
    puts("\t   by achmad sayfudin\n");

    puts("->>MENU<<-\n");
    do{
    printf("1. metode reiman\n2. trapezoid\n3. simpson(1/3)\n4. simpson(3/8)\n5. kuadratur 2 titik\n6. kuadratur 3 titik\n7. keluar");
    printf("\n\nmasukan pilihan anda: ");
    fflush(stdin);
    pil=getchar();

        if(pil=='1'){
            reiman();
        }
        else if(pil=='2'){
            trapezoid();
        }
        else if(pil=='3'){
            simpson();
        }
        else if(pil=='4'){
            simpson3per8();
        }
        else if(pil=='5'){
            kuadratur2titik();
        }
        else if(pil=='6'){
            kuadratur3();
        }
        else if(pil=='7'){
            exit(0);
        }
        fflush(stdin);
        printf("\nkembali ke menu (y/t) : ");
        jawab=getchar();

    }while(jawab=='y'||jawab=='Y');
}
