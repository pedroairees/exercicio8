#include <stdio.h>
#include <stdbool.h>

int main() {
    char resposta;
    
    do {
        int mes, ano;
        
        printf("Digite o mês (1-12): ");
        scanf("%d", &mes);
        
        if (mes < 1 || mes > 12) {
            printf("Mês inválido. Por favor, insira um valor de 1 a 12.\n");
            continue;
        }
        
        printf("Digite o ano: ");
        scanf("%d", &ano);
        
        bool bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        
        int diasNoMes;
        
        if (mes == 2) {
            diasNoMes = bissexto ? 29 : 28;
        } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
            diasNoMes = 30;
        } else {
            diasNoMes = 31;
        }
        
        printf("O mês %d/%d tem %d dias.\n", mes, ano, diasNoMes);
        
        printf("VOCÊ DESEJA OUTRAS ENTRADAS (S/?)? ");
        scanf(" %c", &resposta);
        
    } while (resposta == 'S' || resposta == 's');
    
    return 0;
}
