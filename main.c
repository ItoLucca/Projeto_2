#include <stdio.h>
#include "projeto.h"

int main(){
    funcao fs[] = {criar, deletar, listar, salvar, carregar};  // cria-se uma função de array chamda "fs[]" com 5 ponteiros dentro dela, sendo da ordem crescente, ou seja, a posição "fs[0]" será a função "criar", a posição "fs[1]" será a função "deletar" e assim por diante. 

    Tarefa tarefas[TOTAL];  // chama a struct "Tarefa", utilizando o array "tarefas" com um total de espaços dentro do array chamado "TOTAL".
    int pos;  // cria uma variavel de caracter interiro chamada "pos".
    ERROS erro = fs[4](tarefas, &pos);  // chama a estrutura typedef "ERROS"(criada em "tarefas.h"), onde diz que "erro" chama o ponteriro "fs[4]" o qual é a função "carregar".
    if(erro != OK)  // a função "if" diz que se a variavel "erro" for diferente do valor "OK", será feito a linha abaixo.
        printf("Erro ao carregar o arquivo.. ");
        return 1;

    int opcao;  // cria uma variavel de caracter interiro chamada "opcao".
    do{  // função "do" faz com que se inicie um looping, só finalizado quando se utilizado "while".
        printf("\nMenu principal\n");  //printa para o usuario a mensagem "Menu principal" pulando uma linha antes e depois da mensagem por conta do "\n".
        printf("1 - Criar tarefa\n");  //printa para o usuario a mensagem "1 - Criar tarefa" pulando uma linha depois da mensagem por conta do "\n".
        printf("2 - Deletar tarefa\n");  //printa para o usuario a mensagem "2 - Deletar tarefa" pulando uma linha depois da mensagem por conta do "\n".
        printf("3 - Listar tarefas\n");  //printa para o usuario a mensagem "3 - Listar tarefas" pulando uma linha depois da mensagem por conta do "\n".
        printf("4 - Exportar tarefa\n");
        printf("0 - Sair\n");  //printa para o usuario a mensagem "0 - Sair" pulando uma linha depois da mensagem por conta do "\n".
        printf("Escolha uma opcao: ");  // pede ao usuario que escolha uma das opcoes acima(entre 0 e 3).

        scanf("%d", &opcao);  // guarda a opcao escolhida pelo usuario no ultimo printf em "&opcao", só funcionando para caracteres numericos.
        opcao--;  // serve para garantir a posicao certa dentro do array.
        
        if(opcao == 0)  // função "if" diz que caso o usuario escolha uma "opcao" numerica acima de 3, vai ser enviado a mensagem abaixo.
            printf("Sair...\n");  // printa ao usario a mensagem "Opcao invalida", pulando uma linha apos esse print.
        else if(opcao >= 0 && opcao <= 3)  // função "if" diz que caso o usuario escolha uma "opcao" numerica maio ou igual a 0, vai ser enviado a mensagem abaixo.
            fs[opcao](tarefas, &pos);  // a função "fs" chama a função correspondente à opção desejada pelo usuaruio em "&opcao", salvando dentro do array "tarefas" na posição "&pos".
        else  // caso nenhuma condição acima seja feita, sera realizada a mensagem abaixo.
            erro = fs[opcao](tarefas, &pos);
            if(erro != OK){
                printf(" Erro \n");  // printa para o usuario a mensagem "Sair...\n", e apos a mensagem pula uma linha por conta da fncao "\n".
                return 1;
            }

    } while(opcao >= 0);  // fecha o looping quando a opcao escolhida pelo usuario for maior ou igual a 0.

    fs[3](tarefas, &pos);  // chama o ponteiro 3 do array "tarefas" o qual é a função "salvar", guardando em "&pos".

    return 0;
}
