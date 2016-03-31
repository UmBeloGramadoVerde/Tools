/*   Error propagation calculator - Kayna Rodrigues Oliveira */
/*   Contacts - kaynarodrigues@live.com */
/*   https://github.com/UmBeloGramadoVerde */
/*   If you make some sort o modification in the software send it to me. I would like to see it */
/*   I assume that is of your interest to input correct information */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){

    char opcao;
    char opcao2;
    float x, y, dx, dy, c, dc;
    float constante;
    float expoente;
    int kill = 0;
    char terminador;

    while (kill == 0){

        x=0;
        y=0;
        dx=0;
        dy=0;
        c=0;
        dc=0;

        system("clear");

        printf("********************************\n");
        printf("* ERROR PROPAGATION CALCULATOR *\n");
        printf("********************************\n");

        while (getchar() != '\n');

        printf("Enter x\n>>");
        scanf("%f", &x);
        while (getchar() != '\n');
        printf("Enter dx\n>>");
        scanf("%f", &dx);
        while (getchar() != '\n');
        printf("Enter y\n>>");
        scanf("%f", &y);
        while (getchar() != '\n');
        printf("Enter dy\n>>");
        scanf("%f", &dy);
        while (getchar() != '\n');
        printf("\n");
        printf("Options: \n'm' -> Multiplication\n'd' -> Division\n'p' -> Potenciation\n'c' -> Multiplication by a constant\n");
        printf("\n");
        printf("Choose an option\n>>");
        scanf("%c", &opcao);
        while (getchar() != '\n');

        switch(opcao){
            case 'm' :
            c = x * y;
            dc = ((y * dx) + (x * dy));
            break;
            case 'd' :
            c = x / y;
            dc = ((dx / y) + ((x * dy) / pow(y, 2)));
            break;
            case 'p' :
            printf("\n");
            printf("Which number do you want to make the operation with?\n>>");
            scanf("%c", &opcao2);
            while (getchar() != '\n');
            printf("\n");
            printf("By which power will the potenciacion of %c happen ?\n>>", opcao2);
            scanf("%f", &expoente);
            while (getchar() != '\n');
            if (opcao2 == 'X' || opcao2 == 'x')
            {
                c = pow(x, expoente);
                dc = expoente * pow(x, (expoente -1)) * dx;
            }
            if (opcao2 == 'Y' || opcao2 == 'y')
            {
                c = pow(y, expoente);
                dc = 2 * y * dy;
            }
            break;
            case 'c' :
            printf("\n");
            printf("With which number do you want to make the operation ?\n>>");
            scanf("%c", &opcao2);
            while (getchar() != '\n');
            printf("\n");
            printf("Enter the constant\n>>");
            scanf("%f", &constante);
            while (getchar() != '\n');
            if (opcao2 == 'X' || opcao2 == 'x')
            {
                c = x * constante;
                dc = dx * constante;
            }
            if (opcao2 == 'Y' || opcao2 == 'y')
            {
                c = y * constante;
                dc = dy * constante;
            }
            break;
        }

        printf("\nC = %.10f\n", c);
        printf("dC = %.10f\n\n", dc);

        printf("Do you want to make another operation ? (Y/N)\n>>");

        scanf("%c", &terminador);
        printf("%c\n", terminador);
        while(getchar()!='\n');

        if (terminador == 'Y' || terminador == 'y')
        {
            kill = 0;
        }
        else if (terminador == 'N' || terminador == 'n')
        {
            kill = 1;
        }

    }

    return 0;
}