#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_JOGADORAS 5
#define MAX_ENTREVISTADOS 300

typedef struct {
    char nome[50];
    int idade;
    char sexo;
    char voto;
} Entrevistado;

int main() {
    Entrevistado entrevistados[MAX_ENTREVISTADOS];
    int votos[MAX_JOGADORAS] = {0};
    int total_entrevistados = 0;
    int mulheres_entrevistadas = 0;

    printf("Bem-vindo à pesquisa sobre a melhor jogadora da Copa do Mundo de Futebol Feminino.\n");
    printf("A pesquisa pode ser encerrada a qualquer momento.\n");

    while (total_entrevistados < MAX_ENTREVISTADOS) {
        Entrevistado entrevistado;
        char voto;

        printf("\nEntrevistado %d:\n", total_entrevistados + 1);

        printf("Nome: ");
        scanf("%s", entrevistado.nome);

        printf("Idade (maior que 12 anos): ");
        scanf("%d", &entrevistado.idade);

        if (entrevistado.idade <= 12) {
            printf("A idade deve ser maior que 12 anos. Tente novamente.\n");
            continue;
        }

        printf("Sexo (M - masculino, F - feminino): ");
        scanf(" %c", &entrevistado.sexo);

        if (entrevistado.sexo != 'M' && entrevistado.sexo != 'F') {
            printf("O sexo deve ser M ou F. Tente novamente.\n");
            continue;
        }

        printf("Voto (A, B, C, D, E): ");
        scanf(" %c", &voto);

        if (voto != 'A' && voto != 'B' && voto != 'C' && voto != 'D' && voto != 'E') {
            printf("O voto deve ser A, B, C, D ou E. Tente novamente.\n");
            continue;
        }

        entrevistado.voto = voto;
        entrevistados[total_entrevistados] = entrevistado;
        votos[voto - 'A']++;

        if (entrevistado.sexo == 'F') {
            mulheres_entrevistadas++;
        }

        total_entrevistados++;

        printf("Deseja encerrar a pesquisa? (S para Sim, qualquer outra tecla para continuar): ");
        char encerrar;
        scanf(" %c", &encerrar);

        if (encerrar == 'S' || encerrar == 's') {
            break;
        }
    }

    // Exibir a quantidade de votos que cada jogadora recebeu
    printf("\nQuantidade de votos recebidos por cada jogadora:\n");
    for (int i = 0; i < MAX_JOGADORAS; i++) {
        printf("Jogadora %c: %d votos\n", 'A' + i, votos[i]);
    }

    // Encontrar a jogadora mais votada
    int max_votos = votos[0];
    for (int i = 1; i < MAX_JOGADORAS; i++) {
        if (votos[i] > max_votos) {
            max_votos = votos[i];
        }
    }

    // Exibir a jogadora(s) mais votada(s)
    printf("\nJogadora(s) mais votada(s):\n");
    for (int i = 0; i < MAX_JOGADORAS; i++) {
        if (votos[i] == max_votos) {
            printf("Jogadora %c\n", 'A' + i);
        }
    }

    // Exibir o nome, idade e sexo de todas as pessoas que participaram da pesquisa, separando por sexo, maior de idade e menor de idade
    printf("\nParticipantes da pesquisa:\n");
    printf("Maior de Idade:\n");
    for (int i = 0; i < total_entrevistados; i++) {
        if (entrevistados[i].idade >= 18) {
            printf("Nome: %s, Idade: %d, Sexo: %c\n", entrevistados[i].nome, entrevistados[i].idade, entrevistados[i].sexo);
        }
    }

    printf("\nMenor de Idade:\n");
    for (int i = 0; i < total_entrevistados; i++) {
        if (entrevistados[i].idade < 18) {
            printf("Nome: %s, Idade: %d, Sexo: %c\n", entrevistados[i].nome, entrevistados[i].idade, entrevistados[i].sexo);
        }
    }

    // Exibir o nome das pessoas maior de idade que votaram na Marta Vieira (Jogadora A)
    printf("\nPessoas maior de idade que votaram na Marta Vieira:\n");
    for (int i = 0; i < total_entrevistados; i++) {
        if (entrevistados[i].idade >= 18 && entrevistados[i].voto == 'A') {
            printf("Nome: %s\n", entrevistados[i].nome);
        }
    }

    // Exibir a quantidade de mulheres que participaram da pesquisa
    printf("\nQuantidade de mulheres que participaram da pesquisa: %d\n", mulheres_entrevistadas);

    return 0;
}
