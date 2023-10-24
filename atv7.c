#include <stdio.h>
#include <ctype.h>

int main() {
    char nome[10][50];
    char sexo;
    float altura, peso;
    int num_homens = 0, num_mulheres = 0;
    float soma_altura_homens = 0, soma_altura_mulheres = 0, soma_altura_grupo = 0;
    float soma_peso_homens = 0, soma_peso_mulheres = 0, soma_peso_grupo = 0;

    for (int i = 0; i < 10; i++) {
        printf("Pessoa %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", nome[i]);

        printf("Sexo (M/m para masculino, F/f para feminino): ");
        scanf(" %c", &sexo);
        sexo = tolower(sexo);

        if (sexo == 'm') {
            num_homens++;
        } else if (sexo == 'f') {
            num_mulheres++;
        } else {
            printf("Sexo inválido. Use M/m para masculino ou F/f para feminino.\n");
            i--;
            continue;
        }

        printf("Altura (em metros): ");
        scanf("%f", &altura);

        printf("Peso (em quilogramas): ");
        scanf("%f", &peso);

        if (sexo == 'm') {
            soma_altura_homens += altura;
            soma_peso_homens += peso;
        } else {
            soma_altura_mulheres += altura;
            soma_peso_mulheres += peso;
        }

        soma_altura_grupo += altura;
        soma_peso_grupo += peso;
    }

    float altura_media_homens = num_homens > 0 ? soma_altura_homens / num_homens : 0;
    float altura_media_mulheres = num_mulheres > 0 ? soma_altura_mulheres / num_mulheres : 0;
    float altura_media_grupo = soma_altura_grupo / 10;
    float peso_media_homens = num_homens > 0 ? soma_peso_homens / num_homens : 0;
    float peso_media_mulheres = num_mulheres > 0 ? soma_peso_mulheres / num_mulheres : 0;
    float peso_media_grupo = soma_peso_grupo / 10;

    printf("\nEstatísticas do grupo:\n");
    printf("Número de homens: %d\n", num_homens);
    printf("Número de mulheres: %d\n", num_mulheres);
    printf("Altura média dos homens: %.2f metros\n", altura_media_homens);
    printf("Altura média das mulheres: %.2f metros\n", altura_media_mulheres);
    printf("Altura média do grupo: %.2f metros\n", altura_media_grupo);
    printf("Peso médio dos homens: %.2f quilogramas\n", peso_media_homens);
    printf("Peso médio das mulheres: %.2f quilogramas\n", peso_media_mulheres);
    printf("Peso médio do grupo: %.2f quilogramas\n", peso_media_grupo);

    return 0;
}
