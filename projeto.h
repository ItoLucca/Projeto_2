#define TOTAL 100  // define que será armazenado até um total de 100 posições.
#define TAMANHO_CATEGORIA 100
#define TAMANHO_DESCRICAO 300
#define TAMANHO_ARQUIVO 300

typedef struct {  // estrutura chamada "Tarefa" criada para ser levada como base quando puxada por uma função.
    int prioridade;  // diz que a "prioridade" so poderá ser salvada caracteristicas númericas.
    char descricao[TAMANHO_DESCRICAO];  // diz que a função "decrição" so poderá ter letras inseridas dentro dela, contendo um total de até 300 "espaços" dentro dela, ou seja, podendo embutir até 300 características ou menos.
    char categoria[TAMANHO_CATEGORIA];  // diz que a "categoria" so poderá ter letras inseridas dentro dela, contendo um total de até 100 "espaços" dentro dela, ou seja, podendo embutir até 300 características ou menos.
    char arquivo[TAMANHO_ARQUIVO];
} Tarefa;

typedef enum {OK, MAX_TAREFA, SEM_TAREFAS, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;  // Este tipo "enum" denominada "ERROS" é usado para definir um conjunto de constantes inteiras nomeadas. 

typedef ERROS (*funcao)(Tarefa[], int*);  // define a 'funcao' para um ponteiro de função que retorna "ERROS", apresentadno um paramertro array de Tarefa e um outro parametro de ponteiro para int(inteiro).

ERROS criar(Tarefa tarefas[], int *pos);  // diz que a função 'carregar', que retorna ERROS, aceita um array de Tarefa e um ponteiro para int, ou seja, números inteiros como parâmetros. E que quando aplicado, a característica é colocado na ultima posição do array por conta da função int *pos.
ERROS deletar(Tarefa tarefas[], int *pos);  // diz que a função 'deletar', que retorna ERROS, aceita um array de Tarefa e um ponteiro para int, ou seja, números inteiros como parâmetros. E que quando aplicado, a característica é colocado na ultima posição do array por conta da função int *pos.
ERROS listar(Tarefa tarefas[], int *pos);  // diz que a função 'listar', que retorna ERROS, aceita um array de Tarefa e um ponteiro para int, ou seja, números inteiros como parâmetros. E que quando aplicado, a característica é colocado na ultima posição do array por conta da função int *pos.
ERROS salvar(Tarefa tarefas[], int *pos);  // diz que a função 'salvar', que retorna ERROS, aceita um array de Tarefa e um ponteiro para int, ou seja, números inteiros como parâmetros. E que quando aplicado, a característica é colocado na ultima posição do array por conta da função int *pos.
ERROS carregar(Tarefa tarefas[], int *pos);  // diz que a função 'carregar', que retorna ERROS, aceita um array de Tarefa e um ponteiro para int, ou seja, números inteiros como parâmetros. E que quando aplicado, a característica é colocado na ultima posição do array por conta da função int *pos.
ERROS exportar(Tarefa tarefas[], int *pos);

void clearBuffer();  // a função "void clearBuffer()" tem o intuito de "limpar" o buffer após o código ser efeuado.
