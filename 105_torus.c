#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int bisection_function(double tab[])
{
    int count = 0;
    double x = 0.5;
    double save_x = 0;
    int b = 1;
    int a = 0;
    int x_born = b;

    while ((save_x - x) != pow(10, -1 * tab[5])) {
        double result = tab[0] + tab[1] * x + tab[2] * (x * x) + tab[3] * (x * x * x)  + tab[4] * (x * x * x * x);
        double result2 = tab[0] + tab[1] * x_born + tab[2] * (x_born * x_born) + tab[3] * (x_born * x_born * x_born) + tab[4] * (x_born * x_born * x_born * x_born);

        if ((result * result2) <= 0) {
            printf("%f\n", x);
            save_x = x;
            x = (x_born + x) / 2;
            if (count != 0) {
                a = x_born;
            }
            x_born = save_x;
        }
        if ((result * result2) < 0) {
            count++;
            x_born = a;
        }
    }
}

/*char *printt(double x, int precision)
{
  char *leaf = malloc(sizeof(char) * (precision * 2));
  while (m * 10 < x)
  m / 10

  for (int i = 0; i != precision + 4; i++) {
    leaf[i] = x % (precision - ((precision - 1) - i));
  }
  for (int i = 0; i != 1; i++) {
    printf("%f\n", leaf[i]);
  }
}
*/
int secant_function(double tab[])
{
    double x = 0;
    double x1 = 1;
    double x2 = 0;
    double save = 0;
    int u = 0;
    while (u != 1) {
        x2 = x1 - (((x1 - x) / ((tab[0] + tab[1] * pow(x1, 1) + tab[2] * pow(x1, 2) + tab[3] * pow(x1, 3)  + tab[4] * pow(x1, 4)) - (tab[0] + tab[1] * pow(x, 1) + tab[2] * pow(x, 2) + tab[3] * pow(x, 3)  + tab[4] * pow(x, 4)))) * (tab[0] + tab[1] * pow(x1, 1) + tab[2] * pow(x1, 2) + tab[3] * pow(x1, 3)  + tab[4] * pow(x1, 4)));
        printf("%0.8f\n", x2);
        save = x1;
        x1 = x2;
        x = save;
        if ((x2 - save) >= pow(10, -100)) {
            printf("je suis la différence %f\n", x2 -save);
            printf("%0.15f",pow(10, -100));
            u++;
        }
    }
}

int main (int ac, char **av)
{
    if (ac < 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        printf("USAGE\n");
        printf("    ./105torus opt a0 a1 a2 a3 a4 n\n\n");
        printf("DESCRIPTION\n");
        printf("    opt      method option:\n");
        printf("                1 for the bisection method\n");
        printf("                2 dor Newton's method\n");
        printf("                3 for the secont method\n");
        printf("    a[0-4]    coefficients of the equation\n");
        printf("    n         precission (the application of the polynomial to the solution should\n");
        printf("              be smaller than 10^-n\n");
    } else if (ac != 8)
          return (84);
    if (av[1][0] != '1' && av[1][0] != '2' && av[1][0] != '3') {
        return (84);
    }
    double a0 = atof(av[2]);
    double a1 = atof(av[3]);
    double a2 = atof(av[4]);
    double a3 = atof(av[5]);
    double a4 = atof(av[6]);
    int n = atoi(av[7]);
    double tab[6] = {a0, a1, a2, a3, a4, n};
    if (av[1][0] == '1')
        bisection_function(tab);
    //if (av[1][0] == '2')
        //newton_function(tab);
    if (av[1][0] == '3')
        secant_function(tab);
}
