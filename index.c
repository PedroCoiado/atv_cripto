
/* Iniciando a atividade de Criptografia com Fibonacci */

#include <stdio.h>
#include <stdlib.h>

/* Definindo a constante para o tamanho máximo da palavra */
#define MAX 16

/*
O que é uma palavra cifrada? É uma palavra que foi transformada
de forma a não ser facilmente compreendida, geralmente para
proteger informações.

No contexto da criptografia, uma palavra cifrada é o resultado
de aplicar um algoritmo de criptografia a uma palavra original,
tornando-a ilegível sem a chave correta para decifrá-la.
*/

int main() {

    char palavra[MAX];
    char palavraCifrada[MAX];
    char alfabetoNormal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfabetoCifrado[27];

    int SHIFT = 3;
    int posicao;
    int i;

    /* Variáveis para calcular a sequência de Fibonacci */
    int fib = 1;
    int proximoFib = 1;
    int auxiliar;

    printf("Digite a palavra secreta (ate 15 letras, sem espacos): ");

    if (scanf("%15s", palavra) != 1) {
        printf("Erro ao ler entrada.\n");
        return 1;
    }

    printf("Digite o valor de SHIFT (ex: 3): ");

    if (scanf("%d", &SHIFT) != 1) {
        printf("Erro ao ler a entrada SHIFT.\n");
        return 1;
    }

    /* Transformando as letras minusculas em maiusculas */
    for (i = 0; palavra[i] != '\0'; i++) {
        if (palavra[i] >= 'a' && palavra[i] <= 'z') {
            palavra[i] = palavra[i] - 32;
        }
    }

    /* Ajustando o SHIFT para ficar entre 0 e 25 */
    SHIFT = SHIFT % 26;

    if (SHIFT < 0) {
        SHIFT = SHIFT + 26;
    }

    /*
    1 - Criando o alfabeto cifrado usando o FOR.
    O alfabeto normal sera deslocado de acordo com o SHIFT.
    */

    for (i = 0; i < 26; i++) {
        alfabetoCifrado[i] =
            alfabetoNormal[(i + SHIFT) % 26];
    }

    alfabetoCifrado[26] = '\0';

    printf("\nAlfabeto normal:  %s\n", alfabetoNormal);
    printf("Alfabeto cifrado: %s\n", alfabetoCifrado);

    /*
    2 - Pegando cada letra da palavra e procurando sua
    posicao no alfabeto cifrado.

    Depois, usamos essa posicao para encontrar a letra
    correspondente no alfabeto normal.
    */

    printf("\nPrimeira etapa da criptografia:\n");

    for (i = 0; palavra[i] != '\0'; i++) {

        for (posicao = 0; posicao < 26; posicao++) {
            if (palavra[i] == alfabetoCifrado[posicao]) {
                break;
            }
        }

        palavraCifrada[i] = alfabetoNormal[posicao];

        printf("%c -> %d -> %c\n",
               palavra[i], posicao, palavraCifrada[i]);
    }

    palavraCifrada[i] = '\0';

    /*
    3 - Aplicando a sequencia de Fibonacci na palavra
    que ja passou pela primeira etapa.

    Os valores utilizados serao 1, 1, 2, 3, 5...
    */

    printf("\nSegunda etapa: aplicando Fibonacci\n");

    for (i = 0; palavraCifrada[i] != '\0'; i++) {

        /* Encontrando a posicao da letra no alfabeto normal */
        for (posicao = 0; posicao < 26; posicao++) {
            if (palavraCifrada[i] == alfabetoNormal[posicao]) {
                break;
            }
        }

        /* Pegando o resto da divisao do Fibonacci por 26 */
        int deslocamentoFib = fib % 26;

        /* Aplicando o valor de Fibonacci na posicao */
        posicao = (posicao + deslocamentoFib) % 26;

        /* Substituindo pela nova letra do alfabeto normal */
        palavraCifrada[i] = alfabetoNormal[posicao];

        printf("Fibonacci (%d) -> %c\n",
               deslocamentoFib, palavraCifrada[i]);

        /* Calculando o proximo valor de Fibonacci */
        auxiliar = fib + proximoFib;
        fib = proximoFib;
        proximoFib = auxiliar;
    }

    printf("\nPalavra original: %s\n", palavra);
    printf("Palavra criptografada: %s\n", palavraCifrada);

    return 0;
}
