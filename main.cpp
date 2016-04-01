#include <iostream.h>
#include <conio.h>
#include <locale.h>
#include <iomanip.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#define MAX 100

struct biblioteca{
    int codigo, ano_lan;
    char nome[40], autor[40], genero[40];
    float preco_custo;
};

void tela(){
cout<<"================================================================================";
cout<<"#  ______  _____ ______         _____  _____  _______ _______ _______ _______  #";
cout<<"#  |_____]   |   |_____] |        |   |     |    |    |______ |       |_____|  #";
cout<<"#  |_____] __|__ |_____] |_____ __|__ |_____|    |    |______ |_____  |     |  #";
cout<<"================================================================================";
}

void frase(){
int x;
srand( (unsigned)time(NULL) );
x = rand() % 10;
cout<<"\n================================================================================";
if(x==0)
    cout<<" \"As melhores e as mais lindas coisas do mundo n�o se pode ver nem tocar.\n     Elas devem ser sentidas com o cora��o\" - Charles Chaplin.";
if(x==1)
    cout<<" \"N�s poder�amos ser muito melhores se n�o quis�ssemos ser t�o bons.\"\n      - Sigmund Freud.";
if(x==2)
    cout<<" \"Nossos melhores sucessos v�m depois de nossas maiores decep��es.\"\n      - Henry Ward Beecher.";
if(x==3)
    cout<<" \"O lucro do nosso estudo � tornarmo-nos melhores e mais s�bios.\"\n      - Michel de Montaigne.";
if(x==4)
    cout<<" \"Trate sempre os seus funcion�rios exatamente como quer que eles tratem os seus  melhores clientes.\" - Stephen Covey.";
if(x==5)
    cout<<" \"O mundo n�o est� amea�ado pelas pessoas m�s, e sim por aquelas que permitem a  maldade.\" - Albert Einstein.";
if(x==6)
    cout<<" \"Tente mover o mundo - o primeiro passo ser� mover a si mesmo.\"\n      - Plat�o.";
if(x==7)
    cout<<" \"A palavra � meu dom�nio sobre o mundo.\"\n      - Clarice Lispector.";
if(x==8)
    cout<<" \"Quando todo mundo quer saber � porque ningu�m tem nada com isso.\"\n      - Mill�r Fernandes.";
if(x==9)
    cout<<" \"Seja a mudan�a que voc� quer ver no mundo.\"\n      - Dalai Lama.";
}

void inicio(){
tela();
cout<<"\n\n\n\n Bem vindo ao sistema de controle bibliotec�rio!";
cout<<"\n    Voc� poder�:";
cout<<"\n     *  Cadastrar e controlar todos os seus livros.";
cout<<"\n     *  Pesquisar seus livros usando um c�digo, nome ou g�nero.";
cout<<"\n     *  Exibir relat�rios detalhados sobre seu estoque.\n";
cout<<"\n\n        *Vamos come�ar cadastrando os livros.";
cout<<"\n                                                PRESSIONE ENTER PARA COME�AR\n\n\n\n";
frase();
getch();
}

void novo_livro(int *qtd_livros, biblioteca livro[]){
system("cls");
tela();

int i, x, j, aux, escolha, verif;

cout<<"\n Informe quantos livros ir� inserir no momento: ";
cin>>x;
aux=(*qtd_livros);


        for(i=0;i<x;i++){
            do{
                system("cls");
                tela();
                cout<<"\n                                 Inserir o "<<i+1<<"� Livro\n";
                do{
                    cout<<"\n  Insira o c�digo de identifica��o do livro(Utilize apenas n�meros): ";
                    cin>>livro[aux].codigo;
                    verif=0;
                      for(j=0;j<(*qtd_livros);j++){
                        if(livro[j].codigo==livro[aux].codigo && j!=aux){
                            verif=1;
                            cout<<"\n C�digo j� existente. Tente novamente. Pressione ENTER.\n";
                            getch();
                        }
                      }

                } while(verif==1);
                cout<<"\n  Insira o nome do livro: ";
                fflush(stdin);
                gets(livro[aux].nome);
                cout<<"\n  Insira o nome do autor de \""<<livro[aux].nome<<"\": ";
                fflush(stdin);
                gets(livro[aux].autor);
                cout<<"\n  Insira o g�nero de \""<<livro[aux].nome<<"\": ";
                fflush(stdin);
                gets(livro[aux].genero);
                cout<<"\n  Insira o ano de lan�amento de \""<<livro[aux].nome<<"\": ";
                cin>>livro[aux].ano_lan;
                cout<<"\n  Insira o pre�o de custo de \""<<livro[aux].nome<<"\": R$";
                cin>>livro[aux].preco_custo;
                    do{
                        system("cls");
                        tela();
                        cout<<"\n\n  Confira os dados do livro inserido: ";
                        cout<<"\n   Nome: "<<livro[aux].nome;
                        cout<<"\n  Autor: "<<livro [aux].autor;
                        cout<<"\n Genero: "<<livro[aux].genero;
                        cout<<"\n    Ano: "<<livro[aux].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[aux].preco_custo;
                        cout<<"\n\n Digite 1 para confirmar ou 2 para refazer este livro: \n\n\n\n\n\n\n";
                        frase();
                        cin>>escolha;
                    } while(escolha!=1 && escolha !=2);

        } while(escolha==2);

        escolha=0;
        aux++;
        (*qtd_livros)++;

        }

}

void excluir_livro(int *qtd_livros, biblioteca livro[]){
system("cls");
tela();

int i, j, escolha, valid=0;

cout<<"\n\n    Informe o c�digo do livro a ser deletado: ";
cin>>escolha;

    for(i=0;i<(*qtd_livros);i++){
        if(escolha==livro[i].codigo){
            valid=1;
            j=i;
        }
    }

    if(valid==0){
        cout<<"\n\n C�digo n�o encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
        frase();
        getch();
    }
        else{
            do{
                        system("cls");
                        tela();
                        cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[j].nome;
                        cout<<"\n  Autor: "<<livro [j].autor;
                        cout<<"\n Genero: "<<livro[j].genero;
                        cout<<"\n    Ano: "<<livro[j].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[j].preco_custo;
                        cout<<"\n\n Digite 1 para excluir ou 2 para cancelar: \n\n\n\n\n\n\n";
                        frase();
                        cin>>escolha;
                    } while(escolha!=1 && escolha !=2);
                            if(escolha==1){
                                for(i=j;i<(*qtd_livros);i++){
                                    livro[i].codigo = livro[i+1].codigo;
                                    strcpy(livro[i].nome,livro[i+1].nome);
                                    livro[i].ano_lan = livro[i+1].ano_lan;
                                    strcpy(livro[i].autor,livro[i+1].autor);
                                    livro[i].preco_custo = livro[i+1].preco_custo;
                                    strcpy(livro[i].genero,livro[i+1].genero);
                                }
                                *qtd_livros=(*qtd_livros)-1;
                                system("cls");
                                tela();
                                cout<<"\n\n\n\n\n     Livro exclu�do com Sucesso! Pressione ENTER para voltar ao Menu\n\n\n\n\n\n\n\n\n\n\n";
                                frase();
                                getch();
                            }
                                if(escolha==2){
                                    system("cls");
                                    tela();
                                    cout<<"\n\n\n\n\n     Nenhum livro foi exclu�do. Pressione ENTER para voltar ao Menu\n\n\n\n\n\n\n\n\n\n\n";
                                    frase();
                                    getch();
                                }
        }
}

int busca_codigo(int qtd, biblioteca livro[]){
    int i, j, escolha, valid=0;

    system("cls");
    tela();
    cout<<"\n\n    Informe o c�digo do livro: ";
    cin>>escolha;

        for(i=0;i<(qtd);i++){
            if(escolha==livro[i].codigo){
                valid=1;
                j=i;
            }
        }
        if(valid==0){
            cout<<"\n\n C�digo n�o encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
            return -1;
        }
            else{
                return j;
            }
}

int busca_nome(int qtd, biblioteca livro[]){
    int i, j, valid=0;
    char nome[40];

    system("cls");
    tela();

    cout<<"\n\n    Informe o nome do livro: ";

    fflush(stdin);
    gets(nome);

        for(i=0;i<(qtd);i++){
            if(strcmp(nome,livro[i].nome) == 0){
                valid=1;
                j=i;
            }
        }
        if(valid==0){
            cout<<"\n\n Livro n�o encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
            return -1;
        }
            else{
                return j;
            }
}

void busca_autor(int qtd, biblioteca livro[]){
int i, valid=0;
    char autor[40];

    system("cls");
    tela();

    cout<<"\n\n    Informe o nome do autor: ";

    fflush(stdin);
    gets(autor);

        for(i=0;i<(qtd);i++){
            if(strcmp(autor,livro[i].autor) == 0){
                valid=1;
                system("cls");
                tela();
                cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[i].nome;
                        cout<<"\n  Autor: "<<livro [i].autor;
                        cout<<"\n Genero: "<<livro[i].genero;
                        cout<<"\n    Ano: "<<livro[i].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[i].preco_custo;
                            if(valid==1){
                                cout<<"\n\n Pressione ENTER para procurar outro livro do mesmo autor. \n\n\n\n\n\n\n";
                                frase();
                                getch();
                            }
                valid=2;

            }
        }
        if(valid==0){
            cout<<"\n\n Livro n�o encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
        if(valid==2){
            system("cls");
            tela();
            cout<<"\n\n\n\n\n N�o foram encontrados mais livros do mesmo autor!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
}

int busca_genero(int qtd, biblioteca livro[]){
    int i, valid=0;
    char genero[40];

    system("cls");
    tela();

    cout<<"\n\n    Informe o g�nero do livro: ";

    fflush(stdin);
    gets(genero);

        for(i=0;i<(qtd);i++){
            if(strcmp(genero,livro[i].genero) == 0){
                valid=1;
                system("cls");
                tela();
                cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[i].nome;
                        cout<<"\n  Autor: "<<livro [i].autor;
                        cout<<"\n Genero: "<<livro[i].genero;
                        cout<<"\n    Ano: "<<livro[i].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[i].preco_custo;
                            if(valid==1){
                                cout<<"\n\n Pressione ENTER para procurar outro livro do mesmo g�nero. \n\n\n\n\n\n\n\n";
                                frase();
                                getch();
                            }
                valid=2;

            }
        }
        if(valid==0){
            cout<<"\n\n Livro n�o encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
        if(valid==2){
            system("cls");
            tela();
            cout<<"\n\n\n\n\n N�o foram encontrados mais livros do mesmo g�nero!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
}

void pesquisar_livro(int *qtd_livros, biblioteca livro[]){
    int i, escolha, indice, qtd;
    qtd=(*qtd_livros);

        do{
            system("cls");
            tela();
            cout<<"\n\n  Escolha o filtro de busca: ";
            cout<<"\n\n   1 - Buscar por c�digo.\n\n   2 - Buscar por nome do livro. \n\n   3 - Buscar por nome do autor \n\n   4 - Buscar por g�nero\n\n\n\n\n\n";
            frase();
            cin>>escolha;
        }while(escolha!=1 && escolha !=2 && escolha !=3 && escolha !=4);

    if(escolha==1){
        indice = busca_codigo(qtd, livro);
            if(indice == -1){}
                else{
                    system("cls");
                    tela();
                        cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[indice].nome;
                        cout<<"\n  Autor: "<<livro [indice].autor;
                        cout<<"\n Genero: "<<livro[indice].genero;
                        cout<<"\n    Ano: "<<livro[indice].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[indice].preco_custo;
                        cout<<"\n\n Pressione ENTER para voltar ao menu. \n\n\n\n\n\n";
                        frase();
                        getch();
                }
    }

    if(escolha==2){
    indice = busca_nome(qtd, livro);
        if(indice == -1){}
                else{
                    system("cls");
                    tela();
                        cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[indice].nome;
                        cout<<"\n  Autor: "<<livro [indice].autor;
                        cout<<"\n Genero: "<<livro[indice].genero;
                        cout<<"\n    Ano: "<<livro[indice].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[indice].preco_custo;
                        cout<<"\n\n Pressione ENTER para voltar ao menu. \n\n\n\n\n\n\n";
                        frase();
                        getch();
                }
    }

    if(escolha==3)
        busca_autor(qtd, livro);

    if(escolha==4)
        busca_genero(qtd, livro);
}

void relatorios(int *qtd_livros, biblioteca livro[]){
int i, j, escolha, valid=0, cont=0, auxint;
char vetor[40], auxvet[40];
float valor1, valor2, auxfloat;
biblioteca aux[MAX];

        do{
            system("cls");
            tela();
            cout<<"\n\n  Escolha o tipo de relat�rio: ";
            cout<<"\n\n   1 - Livros de um g�nero antes de uma determinada data.\n\n   2 - Livros em um intervalo de pre�o. \n\n   3 - Quantidade de livros por g�nero \n\n   4 - Todos os livros em ordem alfab�tica.  \n\n   5 - Todos os livros em ordem alfab�tica do autor.\n\n\n\n";
            frase();
            cin>>escolha;
        }while(escolha!=1 && escolha !=2 && escolha !=3 && escolha !=4 && escolha !=5);

        if(escolha==1){
            system("cls");
            tela();

            cout<<"\n\n Insira o g�nero � ser buscado: ";
            fflush(stdin);
            gets(vetor);

            cout<<"\n\n Insira o ano de lan�amento: ";
            cin>> escolha;

            cout<<"\n\n  * O sistema ir� gerar um relat�rio com todos os livros do g�nero escolhido e com ano de lan�amento inferior ao escolhido.\n\n        Pressione ENTER para continuar";
            cout<<"\n\n\n\n\n";
            frase();
            getch();

                for(i=0;i<(*qtd_livros);i++){
                    if(strcmp(vetor, livro[i].genero)==0 && livro[i].ano_lan<=escolha){
                        system("cls");
                        tela();
                        cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[i].nome;
                        cout<<"\n  Autor: "<<livro [i].autor;
                        cout<<"\n Genero: "<<livro[i].genero;
                        cout<<"\n    Ano: "<<livro[i].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[i].preco_custo;
                        cout<<"\n\n Pressione ENTER para procurar o pr�ximo. \n\n\n\n\n\n";
                        valid=2;
                        frase();
                        getch();
                    }
                }
            if(valid==0){
                system("cls");
                tela();
                cout<<"\n\n Nenhum livro encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
                frase();
                getch();
            }
            if(valid==2){
                system("cls");
                tela();
                cout<<"\n\n\n\n\n N�o foram encontrados mais livros do mesmo g�nero e ano inferior ao escolhido!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
                frase();
                getch();
            }
        }

        if(escolha==2){
            system("cls");
            tela();

            cout<<"\n\n      Escolha um intervalo de pre�os ";
            cout<<"\n\n  Valor m�nimo: R$";
            cin>>valor1;
            cout<<"\n  Valor m�ximo: R$";
            cin>>valor2;
                while(valor2<=valor1){
                    cout<<"\n  Valor m�ximo deve ser maior que o m�nimo. Tente novamente: ";
                    cin>>valor2;
                }

            cout<<"\n\n  * O sistema ir� gerar um relat�rio com todos os livros que custaram entre R$"<<valor1<<" e R$"<<valor2<<"\n\n     Pressione ENTER para continuar";
            cout<<"\n\n\n\n";
            frase();
            getch();

            for(i=0;i<(*qtd_livros);i++){
                    if(livro[i].preco_custo>=valor1 && livro[i].preco_custo<=valor2){
                        system("cls");
                        tela();
                        cout<<"\n\n  Confira os dados do livro escolhido: ";
                        cout<<"\n   Nome: "<<livro[i].nome;
                        cout<<"\n  Autor: "<<livro [i].autor;
                        cout<<"\n Genero: "<<livro[i].genero;
                        cout<<"\n    Ano: "<<livro[i].ano_lan;
                        cout<<"\n  Pre�o: "<<livro[i].preco_custo;
                        cout<<"\n\n Pressione ENTER para procurar o pr�ximo. \n\n\n\n\n\n";
                        valid=2;
                        frase();
                        getch();
                    }
                }
            if(valid==0){
                system("cls");
                tela();
                cout<<"\n\n Nenhum livro encontrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
                frase();
                getch();
            }
            if(valid==2){
                system("cls");
                tela();
                cout<<"\n\n\n\n\n N�o foram encontrados mais livros na faixa de pre�o escolhida!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
                frase();
                getch();
            }
        }

        if(escolha==3){
            system("cls");
            tela();

            cout<<"\n\n      Escolha o g�nero: ";
            fflush(stdin);
            gets(vetor);

            for(i=0;i<(*qtd_livros);i++){
                    if(strcmp(vetor, livro[i].genero)==0){
                       cont++;
                    }
            }
            cout<<"\n\n\n Quantidade de livros encontrado do g�nero \""<<vetor<<"\": "<<cont;
            cout<<"\n\n                           Pressione ENTER para voltar ao menu.\n\n\n\n\n\n\n\n";
            frase();
            getch();
    }

        if(escolha==4){
                for(i=0;i<(*qtd_livros);i++){
                    aux[i].ano_lan = livro[i].ano_lan;
                    aux[i].codigo = livro[i].codigo;
                    strcpy(aux[i].autor,livro[i].autor);
                    strcpy(aux[i].genero,livro[i].genero);
                    strcpy(aux[i].nome,livro[i].nome);
                    aux[i].preco_custo = livro[i].preco_custo;
                }

            for (i=0; i<(*qtd_livros)-1; i++){

                for (j=i+1; j<(*qtd_livros); j++){

                    if ((strcmp(aux[j].nome, aux[i].nome)) < 0){
                        auxint=aux[j].codigo;
                        aux[j].codigo=aux[i].codigo;
                        aux[i].codigo=auxint;

                        auxint=aux[j].ano_lan;
                        aux[j].ano_lan=aux[i].ano_lan;
                        aux[i].ano_lan=auxint;

                        auxfloat=aux[j].preco_custo;
                        aux[j].preco_custo=aux[i].preco_custo;
                        aux[i].preco_custo=auxint;

                        strcpy(auxvet, aux[j].nome);
                        strcpy(aux[j].nome, aux[i].nome);
                        strcpy(aux[i].nome, auxvet);

                        strcpy(auxvet, aux[j].autor);
                        strcpy(aux[j].autor, aux[i].autor);
                        strcpy(aux[i].autor, auxvet);

                        strcpy(auxvet, aux[j].genero);
                        strcpy(aux[j].genero, aux[i].genero);
                        strcpy(aux[i].genero, auxvet);
                    }
                }
            }
        valid=0;
        for(i=0;i<(*qtd_livros);i++){
                valid=1;
                system("cls");
                tela();
                cout<<"\n\n  Confira os dados de todos os livros em ordem alfab�tica: ";
                        cout<<"\n C�digo: "<<aux[i].codigo;
                        cout<<"\n   Nome: "<<aux[i].nome;
                        cout<<"\n  Autor: "<<aux[i].autor;
                        cout<<"\n Genero: "<<aux[i].genero;
                        cout<<"\n    Ano: "<<aux[i].ano_lan;
                        cout<<"\n  Pre�o: "<<aux[i].preco_custo;
                            if(valid==1){
                                cout<<"\n\n Pressione ENTER para ir ao pr�ximo livro. \n\n\n\n\n\n";
                                frase();
                                getch();
                            }
                valid=2;


        }
        if(valid==0){
           system("cls");
            tela();
            cout<<"\n\n\n\n\n N�o existe nenhum livro cadastrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
        if(valid==2){
            system("cls");
            tela();
            cout<<"\n\n\n\n\n Todos os livros foram listados em ordem alfab�tica!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
    }

        if(escolha==5){
                for(i=0;i<(*qtd_livros);i++){
                    aux[i].ano_lan = livro[i].ano_lan;
                    aux[i].codigo = livro[i].codigo;
                    strcpy(aux[i].autor,livro[i].autor);
                    strcpy(aux[i].genero,livro[i].genero);
                    strcpy(aux[i].nome,livro[i].nome);
                    aux[i].preco_custo = livro[i].preco_custo;
                }

            for (i=0; i<(*qtd_livros)-1; i++){

                for (j=i+1; j<(*qtd_livros); j++){

                    if ((strcmp(aux[j].autor, aux[i].autor)) < 0){
                        auxint=aux[j].codigo;
                        aux[j].codigo=aux[i].codigo;
                        aux[i].codigo=auxint;

                        auxint=aux[j].ano_lan;
                        aux[j].ano_lan=aux[i].ano_lan;
                        aux[i].ano_lan=auxint;

                        auxfloat=aux[j].preco_custo;
                        aux[j].preco_custo=aux[i].preco_custo;
                        aux[i].preco_custo=auxint;

                        strcpy(auxvet, aux[j].nome);
                        strcpy(aux[j].nome, aux[i].nome);
                        strcpy(aux[i].nome, auxvet);

                        strcpy(auxvet, aux[j].autor);
                        strcpy(aux[j].autor, aux[i].autor);
                        strcpy(aux[i].autor, auxvet);

                        strcpy(auxvet, aux[j].genero);
                        strcpy(aux[j].genero, aux[i].genero);
                        strcpy(aux[i].genero, auxvet);
                    }
                }
            }
        valid=0;
        for(i=0;i<(*qtd_livros);i++){
                valid=1;
                system("cls");
                tela();
                cout<<"\n\n  Confira os dados de todos os livros em ordem alfab�tica dos autores: ";
                        cout<<"\n C�digo: "<<aux[i].codigo;
                        cout<<"\n   Nome: "<<aux[i].nome;
                        cout<<"\n  Autor: "<<aux[i].autor;
                        cout<<"\n Genero: "<<aux[i].genero;
                        cout<<"\n    Ano: "<<aux[i].ano_lan;
                        cout<<"\n  Pre�o: "<<aux[i].preco_custo;
                            if(valid==1){
                                cout<<"\n\n Pressione ENTER para ir ao pr�ximo livro. \n\n\n\n\n\n";
                                frase();
                                getch();
                            }
                valid=2;


        }
        if(valid==0){
           system("cls");
            tela();
            cout<<"\n\n\n\n\n N�o existe nenhum livro cadastrado!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
        if(valid==2){
            system("cls");
            tela();
            cout<<"\n\n\n\n\n Todos os livros foram listados em ordem alfab�tica!\n         Pressione Enter para continuar\n\n\n\n\n\n\n\n\n\n";
            frase();
            getch();
        }
    }

}

int main(){
    //Personaliza��o de Cor
    system("color F0");

    //Configurando Idioma
    setlocale(LC_ALL, "Portuguese");

    //Vari�veis
    biblioteca livro[MAX];
    int qtd_livros=0, escolha;

    //Inicio
    inicio();
    novo_livro(&qtd_livros, livro);

    //Menu Principal
        do{
            system("cls");
            tela();
            cout<<"\n\n\n\n\n    1 - Inserir novo livro                              2 - Excluir um livro\n";
            cout<<"\n\n\n    3 - Pesquisar livros                                4 - Exibir relat�rios\n";
            cout<<"\n\n\n\n\n                                                                        5 - SAIR";
            frase();
            cin>>escolha;
            if(escolha==1){
            novo_livro(&qtd_livros, livro);
            escolha=0;
            }
            if(escolha==2){
            excluir_livro(&qtd_livros, livro);
            escolha=0;
            }
            if(escolha==3){;
            pesquisar_livro(&qtd_livros, livro);
            escolha=0;
            }
            if(escolha==4){;
            relatorios(&qtd_livros, livro);
            escolha=0;
            }
        } while(escolha!=5);
}
