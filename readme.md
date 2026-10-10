# Entrega 1 - Atividade de Criptografia 

## Metadados

* **Nome do Aluno 1/Curso:** Guilherme Hiroshi dos Santos Okamoto - **RGM:** 47554703 (Engenharia de Software)
* **Nome do Aluno 2/Curso:** Gustavo Gomes Silva - **RGM:** 47436808 (Engenharia de Software)
* **Nome do Aluno 3/Curso:** Pedro Henrique Ruola Coiado - **RGM:** 47589124 (Ciência da Computação)

  ```c
  Professor/Disciplina: Francisco De Assis Cavallaro - Algoritmos e Pensamento Computacional


# Cifra Híbrida: César + Fibonacci em Linguagem C

Implementação acadêmica desenvolvida para a disciplina de **Algoritmo e Pensamento Computacional**, com o objetivo de praticar conceitos de programação em C por meio de uma atividade de criptografia.

---

## Contexto e Objetivos

O programa utiliza duas etapas para transformar uma palavra em uma mensagem criptografada:

1. **Cifra de César:** utiliza um valor de SHIFT para montar um alfabeto cifrado e substituir as letras da palavra original.
2. **Cifra com Fibonacci:** utiliza os valores da sequência de Fibonacci para realizar um novo deslocamento nas letras, tornando a criptografia um pouco mais elaborada.

O objetivo da atividade é colocar em prática os conceitos aprendidos em aula, utilizando vetores, strings, estruturas de repetição e operações matemáticas.

---

## 1. Definição de Constantes e Variáveis

Para começar, definimos o tamanho máximo da palavra e criamos os vetores que serão utilizados durante a criptografia.

```c
#define MAX 16

char palavra[MAX];
char palavraCifrada[MAX];
char alfabetoNormal[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char alfabetoCifrado[27];
```

A constante `MAX` permite armazenar até 15 caracteres na palavra, deixando uma posição extra para o caractere `\0`, que indica o final de uma string em C.

O vetor `palavra` armazena a palavra digitada pelo usuário, enquanto `palavraCifrada` guarda o resultado das etapas de criptografia. Já os vetores `alfabetoNormal` e `alfabetoCifrado` são utilizados para realizar as substituições das letras.

---

## 2. Entrada dos Dados

O programa solicita ao usuário uma palavra e o valor de SHIFT que será utilizado na primeira etapa.

```c
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
```

O valor de SHIFT determina quantas posições serão utilizadas para deslocar o alfabeto. Por exemplo, com SHIFT igual a 3, o alfabeto cifrado começa pela letra D.

---

## 3. Criação do Alfabeto Cifrado

Utilizamos um laço de repetição `for` para percorrer as 26 letras do alfabeto e montar o alfabeto cifrado de acordo com o valor de SHIFT.

```c
for (i = 0; i < 26; i++) {
    alfabetoCifrado[i] =
        alfabetoNormal[(i + SHIFT) % 26];
}

alfabetoCifrado[26] = '\0';
```

A operação `% 26` permite que o alfabeto continue do início quando o deslocamento ultrapassa a letra Z.

Por exemplo, com SHIFT igual a 3:

- Alfabeto normal: `ABCDEFGHIJKLMNOPQRSTUVWXYZ`
- Alfabeto cifrado: `DEFGHIJKLMNOPQRSTUVWXYZABC`

---

## 4. Substituição das Letras

Depois de montar o alfabeto cifrado, o programa procura a posição de cada letra da palavra digitada.

```c
for (i = 0; palavra[i] != '\0'; i++) {

    for (posicao = 0; posicao < 26; posicao++) {
        if (palavra[i] == alfabetoCifrado[posicao]) {
            break;
        }
    }

    palavraCifrada[i] = alfabetoNormal[posicao];
}

palavraCifrada[i] = '\0';
```

Quando encontra a letra no alfabeto cifrado, o programa utiliza a posição encontrada para buscar a letra correspondente no alfabeto normal.

Dessa forma, a palavra passa pela primeira etapa de criptografia.

---

## 5. Aplicação da Sequência de Fibonacci

Na segunda etapa, utilizamos a sequência de Fibonacci para determinar o deslocamento de cada letra.

A sequência começa com os valores `1, 1, 2, 3, 5, 8...`. A cada repetição do laço, um novo valor é calculado e utilizado na próxima letra.

```c
int fib = 1;
int proximoFib = 1;
int auxiliar;

for (i = 0; palavraCifrada[i] != '\0'; i++) {

    for (posicao = 0; posicao < 26; posicao++) {
        if (palavraCifrada[i] == alfabetoNormal[posicao]) {
            break;
        }
    }

    int deslocamentoFib = fib % 26;

    posicao = (posicao + deslocamentoFib) % 26;

    palavraCifrada[i] = alfabetoNormal[posicao];

    auxiliar = fib + proximoFib;
    fib = proximoFib;
    proximoFib = auxiliar;
}
```

Primeiro, o programa encontra a posição da letra no alfabeto normal. Depois, soma o valor de Fibonacci à posição e utiliza o resto da divisão por 26 para manter o resultado dentro do alfabeto.

O laço também calcula os próximos valores de Fibonacci para que cada letra possa receber um deslocamento diferente.

---

## 6. Exemplo de Execução:


Considerando a palavra `GUI` e o valor de SHIFT igual a 3, temos:

| Etapa | Resultado |
|---|---|
| Palavra original | GUI |
| Primeira etapa | DRF |
| Fibonacci aplicado | ESH |

Na primeira etapa, as letras são substituídas utilizando o alfabeto cifrado. Na segunda, os valores de Fibonacci modificam novamente as posições das letras.

#Segundo Exemplo de Execução:

<img width="675" height="718" alt="{8FF52226-E5D0-46C3-A746-52F489931ED2}" src="https://github.com/user-attachments/assets/99a55a4a-e7fa-447d-adc4-23526fa8fb24" />

Demonstração do código em prática, passo a passo, seguindo a mesma regra do primeiro exemplo. 

---

## 7. Considerações Finais

A atividade permitiu praticar estruturas de repetição, vetores, manipulação de strings e operações matemáticas na linguagem C.

A combinação da Cifra de César com a sequência de Fibonacci demonstra como diferentes regras podem ser utilizadas em conjunto para transformar uma mensagem.

O programa tem finalidade acadêmica e didática, servindo como exercício para compreender a lógica por trás de algoritmos de substituição. Ele não deve ser utilizado para proteger informações sensíveis, pois esse tipo de cifra não oferece segurança adequada para uso real.
