#include <stdio.h>

int main() {
    int elevadorA_M = 0, elevadorA_V = 0, elevadorA_N = 0;
    int elevadorB_M = 0, elevadorB_V = 0, elevadorB_N = 0;
    int elevadorC_M = 0, elevadorC_V = 0, elevadorC_N = 0;

    int moradores = 50;
    int total_servicos = 0;

    for (int i = 1; i <= moradores; i++) {
        int elevadorUsado;
        char periodo;

        printf("Morador %d:\n", i);

        // Leitura do elevador usado
        printf("Elevador utilizado (1 - A, 2 - B, 3 - C): ");
        scanf("%d", &elevadorUsado);

        if (elevadorUsado < 1 || elevadorUsado > 3) {
            printf("Opção de elevador inválida. Tente novamente.\n");
            i--; // Decrementa i para que a entrada seja repetida.
            continue;
        }

        // Consumir o caractere de nova linha da entrada anterior
        while (getchar() != '\n');

        // Leitura do período
        printf("Período (M - Matutino, V - Vespertino, N - Noturno): ");
        scanf(" %c", &periodo);

        switch (elevadorUsado) {
            case 1: // Elevador A
                if (periodo == 'M') elevadorA_M++;
                else if (periodo == 'V') elevadorA_V++;
                else if (periodo == 'N') elevadorA_N++;
                break;
            case 2: // Elevador B
                if (periodo == 'M') elevadorB_M++;
                else if (periodo == 'V') elevadorB_V++;
                else if (periodo == 'N') elevadorB_N++;
                break;
            case 3: // Elevador C
                if (periodo == 'M') elevadorC_M++;
                else if (periodo == 'V') elevadorC_V++;
                else if (periodo == 'N') elevadorC_N++;
                break;
        }

        total_servicos++;
    }

    // Cálculos e impressões dos resultados
    // 1. Qual o período mais usado e a que elevador pertence
    char periodo_mais_usado;
    int periodo_mais_usado_elevador;
    int max_periodo = 0;

    if (elevadorA_M > max_periodo) {
        max_periodo = elevadorA_M;
        periodo_mais_usado = 'M';
        periodo_mais_usado_elevador = 1;
    }

    if (elevadorB_M > max_periodo) {
        max_periodo = elevadorB_M;
        periodo_mais_usado = 'M';
        periodo_mais_usado_elevador = 2;
    }

    if (elevadorC_M > max_periodo) {
        max_periodo = elevadorC_M;
        periodo_mais_usado = 'M';
        periodo_mais_usado_elevador = 3;
    }

    // Repita os mesmos cálculos para os períodos V e N

    // 2. Qual é o elevador mais frequentado e em que período se concentra o maior fluxo
    char elevador_mais_frequentado;
    char periodo_maior_fluxo;
    int max_elevador = elevadorA_M + elevadorA_V + elevadorA_N;

    if ((elevadorB_M + elevadorB_V + elevadorB_N) > max_elevador) {
        max_elevador = elevadorB_M + elevadorB_V + elevadorB_N;
        elevador_mais_frequentado = 'B';
    }

    if ((elevadorC_M + elevadorC_V + elevadorC_N) > max_elevador) {
        max_elevador = elevadorC_M + elevadorC_V + elevadorC_N;
        elevador_mais_frequentado = 'C';
    }

    if (elevador_mais_frequentado == 'A') {
        if (elevadorA_M > elevadorA_V && elevadorA_M > elevadorA_N) {
            periodo_maior_fluxo = 'M';
        } else if (elevadorA_V > elevadorA_M && elevadorA_V > elevadorA_N) {
            periodo_maior_fluxo = 'V';
        } else {
            periodo_maior_fluxo = 'N';
        }
    }

    // Repita os mesmos cálculos para B e C

    // 3. Diferença percentual entre o mais usado dos horários e o menos usado
    int min_periodo = elevadorA_M, max_periodo = elevadorA_M;

    if (elevadorB_M < min_periodo) min_periodo = elevadorB_M;
    if (elevadorB_M > max_periodo) max_periodo = elevadorB_M;
    // Repita para B e C e para os períodos V e N

    float diferenca_percentual = (float)(max_periodo - min_periodo) / min_periodo * 100;

    // 4. Percentagem sobre o total de serviços prestados do elevador de média utilização
    int elevador_media_utilizacao = 0;

    if ((elevadorA_M + elevadorA_V + elevadorA_N) >= total_servicos) {
        elevador_media_utilizacao = 1;
    }
    // Repita para B e C

    // Impressão dos resultados
    printf("1. Qual o período mais usado e a que elevador pertence: Período %c (Elevador %c)\n", periodo_mais_usado, periodo_mais_usado_elevador + 64);
    printf("2. Qual é o elevador mais frequentado e em que período se concentra o maior fluxo: Elevador %c (Período %c)\n", elevador_mais_frequentado, periodo_maior_fluxo);
    printf("3. Diferença percentual entre o mais usado dos horários e o menos usado: %.2f%%\n", diferenca_percentual);
    printf("4. Percentagem sobre o total de serviços prestados do elevador de média utilização: Elevador %c\n", elevador_media_utilizacao + 64);

    return 0;
}
