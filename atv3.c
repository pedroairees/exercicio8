#include <stdio.h>

int main() {
    int n;
    printf("Digite o valor de n (número inteiro maior ou igual a zero): ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Por favor, insira um número inteiro maior ou igual a zero.\n");
    } else {
        int termo_atual = 0;
        int proximo_termo = 1;

        if (n == 0) {
            printf("O termo de ordem 0 na sequência de Fibonacci é 0.\n");
        } else if (n == 1) {
            printf("O termo de ordem 1 na sequência de Fibonacci é 1.\n");
        } else {
            for (int i = 2; i <= n; i++) {
                int temp = termo_atual + proximo_termo;
                termo_atual = proximo_termo;
                proximo_termo = temp;
            }

            printf("O termo de ordem %d na sequência de Fibonacci é %d.\n", n, proximo_termo);
        }
    }

    return 0;
}
