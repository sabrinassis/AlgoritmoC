#include <stdio.h>
#include <string.h>

/*
TRABALHO: Atividade Avaliativa 02 - Algoritmo e Pensamento Computacional
Professor: Francisco de Assis Cavallaro

Integrantes
- Sabrina Souza de Assis     (RGM: 49483731)
- Matheus Pugliese Rodrigues (RGM: 48379298)
- Rodrigo Veniti dos Santos  (RGM: 49493973)
- Thiago dos Santos Estevam  (RGM: 48967670)
*/

int calcula_sequencia(int tipo, int i) {
    int j, termo = 1;
    int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    if (tipo == 1) {
        termo = 5 + i * 3;
    }
    else if (tipo == 2) {
        termo = 2;
        for (j = 0; j < i; j++) {
            termo = termo * 2 % 26;
        }
    }
    else if (tipo == 3) {
        int a = 1, b = 1, proximo;
        for (j = 2; j <= i; j++) {
            proximo = (a + b) % 26;
            a = b;
            b = proximo;
        }
        termo = b;
    }
    else if (tipo == 4) {
        termo = primos[i];
    }
    return termo;
}

int main() {
    char palavra[16] = "algoritmo";
    char cripto[16];
    int shift = 3;
    int tipo = 0;
    int tamanho = strlen(palavra);
    int i;

    do {
        printf("Sequencia (1-PA, 2-PG, 3-Fibonacci, 4-Primos): ");
        scanf("%d", &tipo);
        while (getchar() != '\n');
    } while (tipo < 1 || tipo > 4);

    for (i = 0; i < tamanho; i++) {
        int deslocamento = shift + calcula_sequencia(tipo, i);
        cripto[i] = 'a' + (palavra[i] - 'a' + deslocamento) % 26;
    }
    cripto[tamanho] = '\0';

    printf("Palavra original: %s\n", palavra);
    printf("Palavra criptografada: %s\n", cripto);

    FILE *arquivo = fopen("resultado_criptografia.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de log!\n");
        return 1;
    }
    fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n",
            cripto, shift, tipo, tamanho);
    fclose(arquivo);
    printf("Arquivo 'resultado_criptografia.txt' gerado com sucesso!\n");

    return 0;
}
