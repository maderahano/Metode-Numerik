#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float hasilfx(float);
float ffx(float);
float hasilgx(float);
float fffx(float);
void seder(void);
void newton (void);

int main()
{
    int pil;
    printf("1. iterasi sederhana\n");
    printf("2. newton Raphson\n=");
    scanf("%d", &pil);
    if (pil==1)
        seder();
    if (pil==2)
        newton();
    if (pil<1||pil>2)
        printf("tidak ada pada pilihan\n");

    return 0;
}
void seder(void)
{
    float x,e;
    int n,i=0;
    printf("f(x)= exp(x)+x\n");
    printf("g(x)= -exp(x)\n");
    printf("masukkan titik awal=");
    scanf("%f", &x);
    printf("masukkan jumlah pengulangan=");
    scanf("%d", &n);
    printf("masukkan toleransi error=");
    scanf("%f", &e);
    if (hasilgx(x)>1||hasilgx(x)<-1)
        printf("bilangan divergen");
    else{
        printf("i\t x\t\t f(x)\t\t g(x)\n");
        for (;i<n;i++){
            printf("%d\t %f\t %f\t %f\t\n", i, x, hasilfx(x), hasilgx(x));
            if (fabs(hasilfx(x))<e){
                printf("f(x) kurang dari error\n");
                break;
            }
            else
                x=hasilgx(x);
        }
        printf("\nx=%lf\n", x);
    }
}
void newton(void)
{
    float x,e;
    int n,i=0;
    printf("f(x)= exp(x)+x\n");
    printf("f'(x)= exp(x)+1\n");
    printf("masukkan titik awal=");
    scanf("%f", &x);
    printf("masukkan jumlah pengulangan=");
    scanf("%d", &n);
    printf("masukkan toleransi error=");
    scanf("%f", &e);
    if (fabs((hasilfx(x)*fffx(x))/(ffx(x)*ffx(x)))>=1)
        printf("bilangan divergen");
    else{
        printf("i\t x\t\t f(x)\t\t f'(x)\n");
        for (;i<n;i++){
            printf("%d\t %f\t %f\t %f\t\n", i, x, hasilfx(x), ffx(x));
            if (fabs(hasilfx(x))<e){
                printf("f(x) kurang dari error\n");
                break;
            }
            else
                x=(x-(hasilfx(x)/ffx(x)));
        }
        printf("\nx=%f\n", x);
    }
}
float hasilfx(float x)
{
    float fx;
    fx = x*(exp(-x))-(x*x);
    return fx;
}
float hasilgx(float x)
{
    float gx;
    gx = (x*x)/(exp(-x));
    return gx;
}
float ffx(float x)
{
    float fx;
    fx = exp(x)+1;
    return fx;
}
float fffx(float x)
{
    float fx;
    fx = exp(x);
    return fx;
}
