#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    printf("** Bem-vindo ao feedback de clientes!\n");

    int otimo = 0;
    int bom = 0;
    int regular = 0;
    int ruim = 0;
    int pessimo = 0;
    int somaIdadeRuim = 0;
    int maiorIdadeRuim = 0, maiorIdadeOtimo = 0;

    int opcao = -1;  // Inicialize opcao com um valor que n�o seja 0

    while (opcao != 0) {
        int idade;
        int opiniao;

        printf("\n1 - �timo         2 - Bom");
        printf("\n3 - Regular         4 - Ruim");
        printf("\n5 - P�ssimo\n");
        printf("\nMe informe sua idade: ");
        scanf("%d", &idade);
        
        printf("\nPressione 0 caso queira encerrar a vota��o!");
        printf("\nInforme sua nota de satisfa��o em rela��o ao filme: ");
        scanf("%d", &opiniao);

        if (opiniao == 0) {
            break;  // Sai do loop quando o usu�rio digitar "0"
        }

        switch (opiniao) {
            case 1:
                otimo++;
                if (idade > maiorIdadeOtimo) {
                    maiorIdadeOtimo = idade;
                }
                break;
            case 2:
                bom++;
                break;
            case 3:
                regular++;
                break;
            case 4:
                ruim++;
                somaIdadeRuim += idade;
                if (idade > maiorIdadeRuim) {
                    maiorIdadeRuim = idade;
                }
                break;
            case 5:
                pessimo++;
                if (idade > maiorIdadeRuim) {
                    maiorIdadeRuim = idade;
                }
                break;
            default:
                printf("Opini�o inv�lida. Tente novamente.\n");
        }
    }

    int diferencaPercent = abs((bom - regular) * 100) / regular;
    float percentPessimo = ((float)pessimo / 10) * 100;
    int diferencaDeIdade = maiorIdadeOtimo - maiorIdadeRuim;

    printf("\n\nEstatisticas:");
    printf("\nValor de votos otimo: %d", otimo);
    printf("\nA diferen�a em percentual entre bons e regular e de: %d%%", diferencaPercent);
    if(ruim > 0) {
        float mediaIdadeRuim = somaIdadeRuim/(float)ruim;
        printf("\nA m�dia de idade de pessoas que votaram em Ruim � de: %.1f", mediaIdadeRuim);
    } else {
        printf("\nNinguem voltou em Ruim!");
    }
    printf("\nA percentagem de resposta pessima �: %.1f%%", percentPessimo);
    printf("\nA diferen�a de idade entre a maior idade que respondeu otimo e a maior idade que respondeu ruim: %d", diferencaDeIdade);
    
    
}