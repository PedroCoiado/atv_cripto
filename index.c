//Iniciando a atividade de Criptografia com Fibonacci

#include <stdio.h>
#include <stdlib.h>

// Definindo a constante para o tamanho m�ximo da palavra
#define MAX 16

// O que � uma palavra cifrada? � uma palavra que foi transformada de forma a 
// n�o ser facilmente compreendida, geralmente para proteger informa��es. 
// No contexto da criptografia, uma palavra cifrada � o resultado de aplicar um algoritmo 
// de criptografia a uma palavra original, tornando-a ileg�vel sem a chave correta para decifr�-la.


int main() {
    char palavra[MAX];
    char palavraCifrada[MAX]; 
    int SHIFT = 3; // Definindo o valor do deslocamento para a cifra 
    int sequenciaFib = 3; // Definindo o valor inicial da sequ�ncia de Fibonacci, estabelecida pelo professor. 

    printf("Digite a palavra secreta (ate 15 letras, sem espacos): ");
    if (scanf("%15s", palavra) != 1) {
        printf("Erro ao ler entrada.\n");
        return 1;
    }

    printf(" Digite o valor de SHIFT (ex: 3):  ");
    if (scanf("%d", SHIFT)!= 1){
        printf("Error ao ler a entrada SHIFT. \n" );
        return 0;
    }
    return 0;
}
