#import <stdio.h>
#import <stdlib.h>
#include <ctype.h>

int menu();
void sair();
int configurarAssentos();

int main()
{
    printf("\n\nBem vindo ao sistema de reservas:");
    int opcao = 0;
    int assentos = 0;
    while (opcao != -1)
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            assentos = configurarAssentos();
            break;
        case 3:
            sair();
            break;
        }
    }
}

int menu()
{
    int ret;
    printf("\nEscolha uma opcao:\n1 - configurar assentos \n2 - confirmar reserva \n3 - sair\n\n");
    scanf("%i", &ret);
    return (ret);
}

int configurarAssentos()
{
    int totalAssentos = 0;
    printf("\nInforme o total de assentos para a sala:\n");
    scanf("%i", &totalAssentos);

    if (!isnumber(totalAssentos))
    {
        printf("\ndigite um numero valido!");
    }

    printf("\nsala configurada para %i assentos\n", totalAssentos);
    return (totalAssentos);
}

void sair()
{
    printf("bye byeee\n\n");
    exit(0);
}