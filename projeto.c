#include <stdio.h>  
#include <string.h>
#include "projeto.h"  // puxa as características dentro de tarefas.h.

ERROS criar(Tarefa tarefas[], int *pos){  // puxa as características inseridas dentro da função "criar" dentro do typedef ERROS.

    int prioridade;

    if(*pos <= TOTAL)  // a função "if" diz que se a *pos(ultima posição) for menor ou igual ao "TOTAL" o qual equivale a 100 ela realizara a função a seguir.
        return MAX_TAREFA;  // caso a função "if" seja correta, será retornado o valor MAX_TAREFA.

    printf("Entre com uma prioridade entre 1 a 10: \n");  // pede ao usuário que insira uma prioridade para a tarefa.
    scanf("%d", &prioridade);
    if(prioridade > 0 && prioridade <= 10){
        tarefas[*pos].prioridade = prioridade;
        printf("prioridade salva com sucesso. \n");
    }

    else{
        printf("A prioridade escolhida não é valida.. \n");
    }
    clearBuffer();  // limpa o buffer após ser inserido os dados.
    
    printf("Entre com a categoria: \n");  // pede ao usuário que insira uma categoria para a tarefa.
    fgets(tarefas[*pos].categoria, TAMANHO_CATEGORIA, stdin);  // salva o que foi escrito pelo usuario em "&tarefas[*pos].categoria" devido a função "stdin", tendo como um máximo de caracteres 100 "espaços".

    size_t len_categoria = strlen(tarefas[*pos].categoria);
    if (len_categoria > 0 && tarefas[*pos].categoria[len_categoria - 1] == '\n')
        tarefas[*pos].categoria[len_categoria - 1] = '\0';

    printf("Entre com a descricao: \n");  // pede ao usuário que insira uma desrição para a tarefa.
    fgets(tarefas[*pos].descricao, TAMANHO_DESCRICAO, stdin);  // salva o que foi escrito pelo usuario em "&tarefas[*pos].descricao" devido a função "stdin", tendo como um máximo de caracteres 300 "espaços".

    size_t len_descricao = strlen(tarefas[*pos].categoria);
    if (len_descricao > 0 && tarefas[*pos].categoria[len_descricao - 1] == '\n')
        tarefas[*pos].categoria[len_descricao - 1] = '\0';

    *pos = *pos + 1;  // cria uma posição após a "*pos"(antiga ultima posição).

    return OK;  //retorna o valor "OK" apó ser efetuada toda a função.
}

ERROS deletar(Tarefa tarefas[], int *pos){  // puxa as características inseridas dentro da função "deletar" dentro do typedef ERROS.
    // teste se existem tarefas
    if(*pos == 0)  // a função "if" diz que se a *pos(ultima posição) for equivalente a 0, ou seja, 0 tarefas, ele irá realizar a função seguinte.
        return SEM_TAREFAS;  // caso a função "if" seja correta, será retornado o valor MAX_TAREFA.

    // verifica se a tarefa escolhida existe
    int pos_deletar;  // cria uma nova variavel chamada "pos_deletar".
    printf("Entre com a posicao da tarefa a ser deletada: \n");  // pede ao usuário para que insira a posição da tarefa a ser deletada.
    scanf("%d", &pos_deletar);  // estrutura "scanf" guarda o que foi escrito pelo usuario em "&pos_deletar", porem guarda apenas algorismos numericos por conta de "%d".
    
    pos_deletar--; // garantir posicao certa no array
    if(pos_deletar >= *pos || pos_deletar < 0)  // a função "if" diz que só irá funcionar quando ambas as condições forem realizada corretamente, sendo as condições a posição "pos_deletar" ser menor ou igual a ultima posição(*pos) e a posição "pos_deletar" for menos que 0.
        return NAO_ENCONTRADO;  // retorna a mensagem quando a função acima é corretamente realizada.

    for(int i = pos_deletar; i < *pos; i++){  // a estrutura "for" faz com que ela rode todas as posições dentro do array desde a posição da terefa a ser deletada(pos_deletar) até a ultima posição feita pelo usuario na array(*pos), procurando em ordem crescente, ou seja, da tarefa procurada ate a ultima inserida pelo usuario, isso por conta da estrutura "i++".
        tarefas[i].prioridade = tarefas[i+1].prioridade;  // insere a tarefa "tarefas[i+1].prioridade" na posição da tarefa "tarefas[i].prioridade".
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);  // copia a string armazenada em "tarefas[i+1].categoria" da tarefa para o espaço "tarefas[i].categoria", ou seja, faz com que a categoria da tarefa na posição i seja igual a categoria da próxima tarefa na lista de tarefas.
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);  // copia a string armazenada em "tarefas[i+1].descricao" da tarefa para o espaço "tarefas[i].descricao", ou seja, faz com que a descricao da tarefa na posição i seja igual a descricao da próxima tarefa na lista de tarefas.
    }

    *pos = *pos - 1;  // subtrai uma posição do array.

    return OK;  // retorna o valor "OK" após rodar o codigo. 
}

ERROS listar(Tarefa tarefas[], int *pos){  // puxa as características inseridas dentro da função "listar" dentro do typedef ERROS.
    int categoria_escolhida;

    printf("Digite a categoria em questao para que seja listada a mesma: \n");
    scanf("%s", categoria_escolhida);

    for(int i = 0; i < *pos; i++ ){
        if(strcmp(categoria_escolhida, tarefas[i].categoria) == 0){
            printf("Pos: %d\t", i+1); 
            printf("Prioridade: %d\t", tarefas[i].prioridade);
            printf("Categoria: %s\t", tarefas[i].categoria);  
            printf("Descricao: %s\n", tarefas[i].descricao); 
        }
        else if(categoria_escolhida == "\0"){
            printf("Pos: %d\t", i+1); 
            printf("Prioridade: %d\t", tarefas[i].prioridade);
            printf("Categoria: %s\t", tarefas[i].categoria);  
            printf("Descricao: %s\n", tarefas[i].descricao); 
        }
        else{
            printf("Erro ao encontar a lista da categoria em questao.. \n");
        }
    }
//    if(*pos == 0)  // a função "if" diz que se a *pos(ultima posição) for equivalente a 0, ou seja, 0 tarefas, ele irá realizar a função seguinte.
//        return SEM_TAREFAS;  // caso a função "if" seja correta, será retornado o valor SEM_TAREFA.
//
//    for(int i=0; i<*pos; i++){  // a estrutura "for" faz com que ela rode todas as posições dentro do array desde a primeira tarefa/posição(i=0) até a ultima tarefa/posição(*pos) incluida pelo usuario, procurando em ordem crescente, ou seja, da tarefa procurada ate a ultima inserida pelo usuario, isso por conta da estrutura "i++" 
//        printf("Pos: %d\t", i+1);  // printa para o usuario "pos: " e após isso pula uma linha por conta de "i+1". Só aceitando caracteres numéricos.
//        printf("Prioridade: %d\t", tarefas[i].prioridade);  // printa para o usuario "Prioridade: " e printando logo em seguida a prioridade inserida no espaço "i" em "tarefas[i].prioridade". Só aceitando caracteres numéricos.
//        printf("Categoria: %s\t", tarefas[i].categoria);  // printa para o usuario "Categoria: " e printando logo em seguida a categoria inserida no espaço "i" em "tarefas[i].categoria". Só aceitando caracteres numéricos.
//        printf("Descricao: %s\n", tarefas[i].descricao);  // printa para o usuario "Descricao: " e printando logo em seguida a descricao inserida no espaço "i" em "tarefas[i].descricao". Só aceitando caracteres numéricos.
//    }
//
//    return OK;  // retorna o valor "OK" após rodar o codigo.
}

ERROS salvar(Tarefa tarefas[], int *pos){  // puxa as características inseridas dentro da função "salvar" dentro do typedef ERROS.
    FILE *f = fopen("tarefas.bin", "wb");  // a função abre o arquivo chamada "tarefas.bin" em codigo binario, onde o arquivo será aberto para escrita.
    if(f == NULL)  // acontece so quando o ponteiro f equivale a "NULL".
        return ABRIR;  // retorna o valor "ABRIR" após rodar o codigo.

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);  // cria um inteiro chamado "qtd", onde a função "fwrite" é usada para escrever dados em um arquivo, puxando as caracteristicas do array "tarefas", usando um total maximo de tarefas chamado "TOTAL", com os espaçamentos totais da struct "sizeof(Tarefa)" apontado pelo ponteiro "f".
    if(qtd == 0)  // acontece quando o inteiro  "qtd" equivale a 0.
        return ESCREVER;  // retorna o valor "ESCREVER" após rodar o codigo.

    qtd = fwrite(pos, 1, sizeof(int), f);  // usa o inteiro chamado "qtd", onde a função "fwrite" é usada para escrever dados em um arquivo, puxando as caracteristicas do array "pos", usando um espaço a ser escrito, com os espaçamentos totais da struct "sizeof(int)" apontado pelo ponteiro "f".
    if(qtd == 0)  // acontece quando o inteiro  "qtd" equivale a 0.
        return ESCREVER;  // retorna o valor "ESCREVER" após rodar o codigo.

    if(fclose(f))  // se a função "fclose" retornar um valor diferente de zero, indica que houve um erro ao fechar o arquivo. Caso retornar 0, a função irá retornar a mensagem da linha abaixo.
        return FECHAR;  // retorna o valor "FECHAR" após rodar o codigo.

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){  // puxa as características inseridas dentro da função "listar" dentro do typedef ERROS.
    FILE *f = fopen("tarefas.bin", "rb");  // a função abre o arquivo chamada "tarefas.bin" em codigo binario, onde o arquivo será aberto para visualização.
    if(f == NULL)  // acontece so quando o ponteiro f equivale a "NULL".
        return ABRIR;  // retorna o valor "ABRIR" após rodar o codigo.

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);  // cria um inteiro chamado "qtd", onde a função "fread" é usada para ler dados em um arquivo, puxando as caracteristicas do array "tarefas", usando um total maximo de tarefas chamado "TOTAL", com os espaçamentos totais da struct "sizeof(Tarefa)" apontado pelo ponteiro "f".
    if(qtd == 0)  // acontece quando o inteiro  "qtd" equivale a 0.
        return LER;  // retorna o valor "LER" após rodar o codigo.

    qtd = fread(pos, 1, sizeof(int), f);  // usa o inteiro chamado "qtd", onde a função "fread" é usada para ler dados em um arquivo, puxando as caracteristicas do array "pos", usando um espaço a ser escrito, com os espaçamentos totais da struct "sizeof(int)" apontado pelo ponteiro "f".
    if(qtd == 0)  // acontece quando o inteiro  "qtd" equivale a 0.
        return LER;  // retorna o valor "LER" após rodar o codigo.

    if(fclose(f))  // se a função "fclose" retornar um valor diferente de zero, indica que houve um erro ao fechar o arquivo. Caso retornar 0, a função irá retornar a mensagem da linha abaixo.
        return FECHAR;  // retorna o valor "FECHAR" após rodar o codigo.


    return OK;  // retorna o valor "OK" após rodar o codigo.

}

ERROS exportar(Tarefa tarefas[], int *pos){
    char nome_arquivo[200];
    FILE *arquivo_exportacao;

    printf("Digite o nome do arquivo a ser exportado: \n");
    fgets(nome_arquivo, TAMANHO_ARQUIVO, stdin);

    size_t len_nome = strlen(nome_arquivo);

    if(len_nome > 0 && nome_arquivo[len_nome - 1] == "\n"){
        nome_arquivo[len_nome - 1] = "\0";
    }

    else if(arquivo_exportacao == NULL){
        printf("Erro ao exportar o arquivo.. \n");
    }
}

void clearBuffer(){  // função "void" que tem o intuito de limpar os buffers.
    int c;  // cria uma variavel inteira chamada "c".
    while ((c = getchar()) != '\n' && c != EOF);  // função diz que lê caracteres do buffer de entrada até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF).
}
