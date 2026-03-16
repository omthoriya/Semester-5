#include <stdio.h>

double fact(double n)
{
    if(n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    double n, ans;

    printf("Enter a number: ");
    scanf("%lf", &n);

    ans = fact(n);

    printf("\nFactorial = %lf\n", ans);

    return 0;
}