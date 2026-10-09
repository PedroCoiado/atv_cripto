# Cifra Híbrida: César + Fibonacci em Linguagem C

> Implementação acadêmica desenvolvida para a disciplina **Algoritmo e Pensamento Computacional**, integrando conceitos de criptografia clássica, matemática aplicada e manipulação de cadeias de caracteres em C.

---

##  Contexto e Objetivos

O projeto aplica duas camadas sequenciais de cifra de substituição monoalfabética sobre uma mensagem de entrada:
1. **Camada Estática:** Deslocamento fixo (*Cifra de César*).
2. **Camada Dinâmica:** Deslocamento progressivo calculado a partir da **Série de Fibonacci**.

O foco pedagógico é demonstrar na prática o uso de vetores (`arrays`), strings em C, aritmética de ponteiros/ASCII e segurança básica na leitura de fluxos de entrada (`stdin`).

---

##  Arquitetura Inicial do Código

### 1. Definição de Constantes e Limites de Buffer

```c
#define MAX_LETRAS 16