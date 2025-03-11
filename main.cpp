#include <iostream>
#include <fstream>
#include "classes.h"

int main(){
    
    SetConsoleOutputCP(65001); // Permitir que o VSCode leia caracteres especiais
    std::fstream arquivo;
    arquivo.open("login.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    Sistema sistema;
    // Objetos "entregadores"
    Periodo periodoTemporario;
    Cadeira cadeiraTemporaria;
    Atividade atividadeTemporaria;

    int estado = 0; // Controla o estado atual do programa
    std::string entrada;

    while (true) {
        switch (estado) {
            case 0:
                paginaInicial();
                break;
            case 1:
                void paginaCadastrarUsuario();
                break;
            case 2:
                void paginaFazerLogin();
                break;
            case 3:
                void paginaDeletarUsuario();
                break;
            case 4:
                void paginaAtualizarUsuario();
                break;
            case 5:
                void paginaPeriodos(vector<Usuario> usuarios){
                    std::cout << "Escolha um período: " << std::endl;
                    int j=0;
                
                    for(Periodo periodoIndex : usuarios[i].periodosTotais){
                        std::cout << j++ << "-" << periodoIndex.nome() << std::endl;
                    }
                    
                    std::cin >> j;

                    while( ( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5)){
                        std::cout << "Período inexistente. Por favor digite uma opção válida:  " << std::endl;
                        std::cin >> l;
                    }

                    std::cout << "Escolha o que deseja fazer: 1-Exibir  2-Cadastrar  3-Deletar  4-Atualizar  5-Voltar " << std::endl;
                    std::cin >> temp;

                    while( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5){
                        std::cout << "Opção inválida. Digite um valor inteiro entre 1 e 5:  " << std::endl;
                        std::cin >> temp;
                    }

                    if( temp == 1){
                        estado =6;
                    }
                    if( temp == 2){
                        estado =7;
                    }
                    if( temp == 3){
                        estado =8;
                    }
                    if( temp == 4){
                        estado =9;
                    }
                    if( temp == 5){
                        estado = 0;
                    }   
                    
                }
                break;
            case 6:
               
                    sistema.cadastrarPeriodo(periodoTemporario);
                    sistema.cadastrarCadeira(periodoTemporario,cadeiraTemporaria);
                
                break;
            case 7:
               void paginaDeletarPeriodo(usuarios[i].periodosTotais[j]);
                break;
            case 8:
               void paginaAtualizarPeriodo(usuarios[i].periodosTotais[j]);
                break;
            case 9:
               void paginaCadeiras(std::vector<Cadeira> cadeirasTotais){
                    std::cout << "Escolha um cadeira: " << std::endl;
                    int k=0;
                    for(Cadeira cadeiraIndex : cadeirasTotais){
                        std::cout << k++ << "-" << cadeirasTotais[k].nome << std::endl;
                    }
                    
                    std::cin >> k;

                    while( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5){
                        std::cout << "Cadeira inexistente. Por favor digite uma opção válida:  " << std::endl;
                        std::cin >> k;
                    }

                    std::cout << "Escolha o que deseja fazer: 1-Exibir 2-Cadastrar 3-Deletar 4-Atualizar 5-Voltar " << std::endl;
                    std::cin >> temp;

                    while( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5){
                        std::cout << "Opção inválida. Digite um valor inteiro entre 1 e 5:  " << std::endl;
                        std::cin >> temp;
                    }

                    if( temp == 1){
                        estado =10;
                    }
                    if( temp == 2){
                        estado =11;
                    } 
                    if( temp == 3){
                        estado =12;
                    }
                    if( temp == 4){
                        estado =13;
                    }
                    if( temp == 5){
                        estado =5;
                    }   
                
                }
                break;
            case 10:
              void  paginaExibirCadeira(Cadeira cadeiraSelecionada){}
                
                break;
            case 11:
              void   paginaCadastrarCadeira(Cadeira cadeiraSelecionada);
                break;
            case 12:
              void  paginaDeletarCadeira(Cadeira cadeiraSelecionada);
                break;
            case 13:
            void paginaAtualizarCadeira(usuarios[i].periodosTotais[j].cadeirasTotais[k]);
            break;
            case 14:
              void paginaAtividades(std::vector<Atividade> atividadesTotais){
                    std::cout << "Escolha um Atividade: " << std::endl;
                    int l=0;
                    for(Atividade atividadeIndex : atividadesTotais){
                        std::cout << l++ << "-" << atividadesTotais[l].nome << std::endl;
                    }
                    
                    std::cin >> l;

                    while( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5){
                        std::cout << "Atividade inexistente. Por favor digite uma opção válida:  " << std::endl;
                        std::cin >> l;
                    }

                    std::cout << "Escolha o que deseja fazer: 1-Exibir  2-Cadastrar  3-Deletar  4-Atualizar  5-Voltar " << std::endl;
                    std::cin >> temp;

                    while( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5){
                        std::cout << "Opção inválida. Digite um valor inteiro entre 1 e 5:  " << std::endl;
                        std::cin >> temp;
                    }

                    if( temp == 1){
                        estado =15;
                    }
                    if( temp == 2){
                        estado =16;
                    } 
                    if( temp == 3){
                        estado =17;
                    }
                    if( temp == 4){
                        estado =18;
                    }
                    if( temp == 5){
                        estado = 10;
                    }   
                }
                break;
            case 15:
              void  paginaExibirAtividades(Atividade atividadeSelecionada);
                break;
            case 16:
                void  paginaCadastrarAtividades(Atividade atividadeSelecionada){
                }
                break;
            case 17:
               void paginaDeletarAtividades(Atividade atividadeSelecionada){
                    std::cout << "Digite o nome da Atividade que deseja deletar" << std:: endl;
               }
                break;
            case 18:
               void paginaAtualizarAtividades(Atividade atividadeSelecionada){
                    s
               }
                break;
            default:
                std::cout << "Estado inválido! Encerrando o programa." << std::endl;
                return 0;
        }

    }
    arquivo.close()
}

    
