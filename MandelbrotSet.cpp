#include<cstdio>
#include<graphics.h>
#include<cmath>

class complex
{
public:
    float real,imag;
    complex(float a=0,float b=0)
    {
        real=a;
        imag=b;
    }
    complex operator+(complex const &x)
    {
        complex y;
        y.real=real+x.real;
        y.imag=imag+x.imag;
        return y;
    }
    complex operator-(complex const &x)
    {
        complex y;
        y.real=real-x.real;
        y.imag=imag-x.imag;
        return y;
    }
    complex operator*(complex const &x)
    {
        complex y;
        y.real=real*x.real-imag*x.imag;
        y.imag=imag*x.real+x.imag*real;
        return y;
    }
    complex operator/(complex const &x)
    {
        complex y;
        y.real=(real*x.real+imag*x.imag)/(x.real*x.real+x.imag*x.imag);
        y.imag=(+imag*x.real-x.imag*real)/(x.real*x.real+x.imag*x.imag);
        return y;
    }
};

complex mandelbrot(complex xnou,complex x)
{
    return xnou*xnou+x;
}

int main()
{
    int i,j,k,iter=100,xmax=800,ymax=800,escape;
    float tal=0.000001;
    complex z,znou;
    initwindow(xmax,ymax);
    setbkcolor(BLACK);
    cleardevice();
    for(i=0;i<800;i++)
    {
        for(j=0;j<800;j++)
        {
            z=complex((i-400.0)/250-1,(400.0-j)/250);
            znou=complex(0,0);
            escape=0;
            for(k=1;k<iter;k++)
            {
                znou=mandelbrot(znou,z);
                if(znou.real>2||znou.real<-2||znou.imag>2||znou.imag<-2)
                {
                    escape=k;
                    break;
                }
            }
            if(escape)
            {
                if(escape<15)
                {
                    putpixel(i,j,COLOR(0,0,0));
                }
                else if(escape<20)
                {
                    putpixel(i,j,COLOR(255,255,0));
                }
                else if(escape<25)
                {
                    putpixel(i,j,COLOR(100,255,0));
                }
                else if(escape<30)
                {
                    putpixel(i,j,COLOR(0,255,0));
                }
                else if(escape<40)
                {
                    putpixel(i,j,COLOR(0,255,100));
                }
                else if(escape<50)
                {
                    putpixel(i,j,COLOR(0,255,255));
                }
                else if(escape<60)
                {
                    putpixel(i,j,COLOR(0,100,255));
                }
                else if(escape<70)
                {
                    putpixel(i,j,COLOR(0,0,255));
                }
                else if(escape<80)
                {
                    putpixel(i,j,COLOR(100,0,255));
                }
                else if(escape<90)
                {
                    putpixel(i,j,COLOR(255,0,255));
                }
                else
                {
                    putpixel(i,j,COLOR(255,255,255));
                }
            }
        }
    }
    getch();
    closegraph();
    return 0;
}
