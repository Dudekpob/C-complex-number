#include <stdio.h>
#include <math.h>

struct {
    double Re;
    double Im;
    double mod;
    double arg; //w rad
}typedef Comp;

Comp alg2wyk(Comp z)
{
    Comp zA;
    zA.mod = sqrt(pow(z.Re,2)+pow(z.Im,2));
    if (z.Re >= 0 && z.Im >= 0)
    {
        zA.arg = acos(z.Im/zA.mod);
    }
    if (z.Re <= 0 && z.Im >= 0)
    {
        zA.arg = acos(z.Re/zA.mod);
    }
    if (z.Re <= 0 && z.Im <= 0)
    {
        zA.arg = atan(z.Im/z.Re)-M_PI;
    }
    if (z.Re >= 0 && z.Im <= 0)
    {
        zA.arg = asin(z.Im/zA.mod);
    }

    return zA;
}

Comp add(Comp a, Comp b)
{
    Comp c; 
    c.Re= a.Re+b.Re;
    c.Im= a.Im+b.Im;
    return c;
}

Comp substract(Comp a, Comp b)
{
     Comp c; 
    c.Re= a.Re-b.Re;
    c.Im= a.Im-b.Im;
    return c;
}

Comp multiply(Comp  a, Comp  b)
{
     Comp c; 
    c.Re= (a.Re*b.Re)-(a.Im*b.Im);
    c.Im= (a.Im*b.Re)+(a.Im*b.Im);
    return c;
}

Comp divide(Comp  a, Comp  b)
{
      Comp  c; 
    c.Re= ((a.Re*b.Re)-(a.Im*b.Im))/(pow(b.Re,2)+pow(b.Im,2));
    c.Im= ((a.Im*b.Re)+(a.Im*b.Im))/(pow(b.Re,2)+pow(b.Im,2));
    return c;
}

Comp arg(Comp  a)
{
    typZesp c;
    c.Re = a.Re;
    c.Im = -(a.Im);
    c.arg = a.arg;
    c.mod = a.mod;
    return c;
}
