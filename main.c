#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ========================================================
   TRABALHO: Atividade Avaliativa 02 - Algoritmo e Pensamento Computacional
   Professor: Francisco de Assis Cavallaro
   
   Integrantes
   - Sabrina Souza de Assis (RGM: 49483731)
   - Matheus Pugliese Rodrigues (RGM: 48379298)
   - Rodrigo Veniti dos Santos (RGM: 49493973)
   - Thiago dos Santos Estevam (RGM: 48967670)
   ======================================================== */

int calcula_sequencia(int tipo, int i) {
    if (tipo == 1) { // PA
        return 1 + (i * 3);
    } 
    else if (tipo == 2) { // PG
        int termo = 1;
        for (int j = 0; j < i; j++) termo *= 2;
        return termo;
    } 
    else if (tipo == 3) { // Fibonacci
        if (i == 0 || i == 1) return 1;
        int a = 1, b = 1, fib = 1;
        for (int j = 2; j <= i; j++) {
            fib = a + b;
            a = b;
            b = fib;
        }
        return fib;
    }
    else if (tipo == 4) { // Primos
        int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
        if (i < 15) return primos[i];
        return i; 
    }
    return 1;
}

int main() {
    char palavra[20] = "algoritmo"; 
    int shift_fixo = 3;             
    int tipo_seq = 3;               
    
    int tamanho = strlen(palavra);
    char palavra_cripto[20];
    
    for (int i = 0; i < tamanho; i++) {
        char c = palavra[i];
        
        if (c >= 'a' && c <= 'z') {
            int valor_sequencia = calcula_sequencia(tipo_seq, i);
            int deslocamento_total = shift_fixo + valor_sequencia;
            
            char nova_letra = 'a' + (c - 'a' + deslocamento_total) % 26;
            palavra_cripto[i] = nova_letra;
        } else {
            palavra_cripto[i] = c;
        }
    }
    palavra_cripto[tamanho] = '\0';
    
    printf("=== RESULTADO DA CRIPTOGRAFIA DUPLA ===\n");
    printf("Palavra original: %s\n", palavra);
    printf("Palavra criptografada: %s\n", palavra_cripto);
    
    FILE *arquivo = fopen("resultado_criptografia.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de log!\n");
        return 1;
    }
    
    fprintf(arquivo, "Palavra codificada: %s | SHIFT: %d | Tipo: %d | Letras: %d\n", 
            palavra_cripto, shift_fixo, tipo_seq, tamanho);
    fclose(arquivo);
    
    printf("Arquivo 'resultado_criptografia.txt' gerado com sucesso!\n");
    
    return 0;
}
