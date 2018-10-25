#import <stdio.h>
#import <stdlib.h>

int menu();
int configurarAssentos();
int registrarReserva();
int liberarReserva();

void sair()
{
    printf("bye byeee\n\n");
    exit(0);
}

int main()
{
    printf("\n\nBem vindo ao sistema de reservas:");

    int opcao;
    int sala = 0;
    int assentos = 0;

    while (1)
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            sala = configurarAssentos(sala);
            break;
        case 2:
            assentos = registrarReserva(assentos, sala);
            break;
        case 3:
            assentos = liberarReserva(assentos, sala);
            break;
        case 4:
            sair();
            break;
        default:
            printf("\nOpcao invalida, tente novamente\n\n");
        }
    }
}

int menu()
{
    int ret;
    printf("\nEscolha uma opcao:\n1 - configurar sala \n2 - confirmar reserva \n3 - liberar reserva \n4 - sair\n\n");
    scanf("%i", &ret);
    return (ret);
}

int registrarReserva(assentos, sala)
{
    if (assentos < sala)
    {
        assentos++;
        int vagos = sala - assentos;
        printf("\nAssento reservado com sucesso, restam %i lugares vagos\n\n", vagos);
    }
    else
    {
        printf("\nSALA CHEIA! Nao foi possivel registrar reserva\n\n");
    }

    return assentos;
}

int liberarReserva(assentos, sala)
{
    if (assentos > 0)
    {
        assentos--;
        int vagos = sala - assentos;
        printf("\nAssento liberado com sucesso, restam %i lugares vagos\n\n", vagos);
    }
    else
    {
        printf("\nSALA VAZIA! Nao existem reservas para remover\n\n");
    }
    return assentos;
}

int configurarAssentos(sala)
{
    if (sala != 0)
    {
        int continuar = -1;
        printf("Sala ja configurada, deseja reconfigurar?\n1 - sim\n2 - nao\n");
        scanf("%d", &continuar);

        if (continuar == 2)
        {
            return sala;
        }
    }

    int totalAssentos = 0;
    printf("\nInforme o total de assentos para a sala:\n");
    scanf("%i", &totalAssentos);

    printf("\nsala configurada para %i assentos\n", totalAssentos);
    return totalAssentos;
}