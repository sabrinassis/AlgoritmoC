# 🛡️ Trabalho: Criptografia Dupla em Linguagem C

Repositório oficial da Atividade Avaliativa 02 da disciplina de **Algoritmo e Pensamento Computacional**, ministrada pelo professor Francisco de Assis Cavallaro.

---

## 👥 Integrantes

- **Sabrina Souza de Assis** - RGM: 49483731
- **Matheus Pugliese Rodrigues** - RGM: 48379298
- **Rodrigo Veniti dos Santos** - RGM: 49493973
- **Thiago dos Santos Estevam** - RGM: 48967670

---

## 🎯 Apresentação do Projeto

Este projeto tem como objetivo principal aplicar a lógica de programação em **Linguagem C** para resolver um problema de segurança da informação por meio de criptografia dupla.

Em resumo, a nossa solução funciona em etapas sequenciais:

1. **Escolha da Palavra:** Definimos o termo `algoritmo` (com 9 letras, sem acentos ou caracteres especiais) para ser processado.
2. **Escolha da Sequência:** Ao executar, o usuário escolhe qual sequência numérica será usada: PA, PG, Série de Fibonacci ou Números Primos.
3. **Criptografia Camada 1 (Cifra de César):** Aplicamos um deslocamento fixo (SHIFT) de 3 posições sobre o alfabeto.
4. **Criptografia Camada 2 (Matemática Aplicada):** Somamos a esse valor o deslocamento dinâmico gerado pelos termos da sequência escolhida, garantindo que cada letra da palavra sofra uma alteração única baseada em sua posição.
5. **Persistência de Dados (Log):** O sistema automatiza a criação do arquivo `resultado_criptografia.txt`, salvando o resultado codificado de forma permanente. A cada execução, uma nova linha é adicionada ao arquivo.

---

## 🧮 Como o cálculo funciona

Para cada letra da palavra, o deslocamento total é:

```
deslocamento = SHIFT + sequencia[i]
```

Como o alfabeto tem 26 letras, usamos o resto da divisão por 26 para que a letra volte ao início depois do `z`.

### Sequências utilizadas

| Sequência | Termos | Fórmula |
|---|---|---|
| Progressão Aritmética (PA) | 5, 8, 11, 14... | a₁ = 5 e r = 3 |
| Progressão Geométrica (PG) | 2, 4, 8, 16... | a₁ = 2 e q = 2 |
| Série de Fibonacci | 1, 1, 2, 3, 5, 8, 13... | Fₙ = Fₙ₋₁ + Fₙ₋₂ |
| Números Primos | 2, 3, 5, 7, 11... | não há fórmula geral |

### Exemplo com a Série de Fibonacci

| Letra | a | l | g | o | r | i | t | m | o |
|---|---|---|---|---|---|---|---|---|---|
| Fibonacci | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 |
| SHIFT + Fibonacci | 4 | 4 | 5 | 6 | 8 | 11 | 16 | 24 | 37 |
| Resultado | e | p | l | u | z | t | j | k | z |

**Palavra criptografada:** `epluztjkz`

**Arquivo gerado (`resultado_criptografia.txt`):**

```
Palavra codificada: epluztjkz | SHIFT: 3 | Tipo: 3 | Letras: 9
```

---

## 📊 Comparação das Sequências

Resultado da palavra `algoritmo` com SHIFT 3 em cada sequência:

| Sequência | Tipo | Palavra criptografada |
|---|---|---|
| PA | 1 | iwuflftpu |
| PG | 2 | fsrhaxulj |
| Fibonacci | 3 | epluztjkz |
| Primos | 4 | froyfynio |

---

## 📸 Demonstração da Execução

[![Resultado do Programa](AlgoritmoC.png)](AlgoritmoC.png)

---

## 🚀 Como Executar

1. Certifique-se de ter um compilador de C configurado (ou utilize o ambiente online *OnlineGDB*).
2. Baixe o código fonte contido no arquivo `main.c`.
3. Compile e execute o programa. No terminal:
   ```
   gcc main.c -o criptografia
   ./criptografia
   ```
4. Digite o número da sequência desejada (1 a 4) para visualizar a palavra criptografada e gerar o arquivo de log correspondente.
