
#include "classes.h"



void Sistema::paginaInicial(){
    std::cout << "Bem-Vindo ao Sigaa 2.0: " << std::endl;
    std::cout << "Escolha o que deseja fazer: 1-Cadastrar  2-Login  3-Deletar Usuário  4-Atualizar" << std::endl;
    std::cin >> temp;
    
    while( temp != 1 && temp!=2 &&  temp!=3 && temp!=4 && temp!= 5){
        std::cout << "Opção inexistente. Por favor digite uma opção válida:  " << std::endl;
        std::cin >> temp;
    }

    if( temp == 1){
        estado =1;
    }
    if( temp == 2){
        estado =2;
    }
    if( temp == 3){
        estado =3;
    }
    if( temp == 4){
        estado =4;
    }

}



void Sistema::paginaCadastrarUsuario(){

    Usuario usuarioTemp;
    //Funções de cadastrar usuário
        std::string nomeTemp, emailTemp, senhaTemp[2];
        tm dataDeNasc;
        
        cadastrarUsuario();

            
}

void Sistema::paginaFazerLogin(){

    if(usuarios.size() == 0){
        std::cout << "Nenhum usuário cadastrado, por favor vá em cadastrar e insira seus dados: " << std:: endl;
        estado = 0;
    }
    std::cout << "Por favor digite suas informações: " << std:: endl;
        
    solicitarEmail(emailTemp);
    verificarEmail(emailTemp); 
    solicitarSenha(senhaTemp);
    verificarSenha(senhaTemp);

        
}

void Sistema::paginaDeletarUsuario(){} 


void Sistema::paginaAtualizarUsuario(){}





void Sistema::paginaPeriodos(){
    std:: cout << "Seja bem-vindo, <NOME>" << std:: endl << "Você tem <P> atividades pendentes e <V> atividades vencidas"<< std:: endl;
    std :: cout << "Deseja:" << std::endl << "1-Exibir período" << std::endl << "2-Cadastrar período" << std::endl << "3-Deletar período"  << std::endl << "4-Voltar" << std::endl;
}








void Sistema::paginaExibirPeriodos(){}
void Sistema::paginaCadastrarPeriodos(){}
void Sistema::paginaDeletarPeriodos(){}


void Sistema::paginaCadeiras(){
    std :: cout << "Deseja:" << std::endl << "1-Exibir Cadeira" << "2-Cadastrar Cadeira" << std::endl << "3-Deletar Cadeira"  << std::endl << "Voltar";

}

void Sistema::paginaExibirCadeira();
void Sistema::paginaDeletarCadeira();
void Sistema::paginaAtualizarCadeira();



void Sistema::paginaExibirCadeira(){} 




void paginaAtividades(){
    //1-Exibir Cadeira 
        //Nome da cadeira
        //Nome do professor
        //Faltas
        //Notas
        //Exibir lista de nomes atividades e ao lado <V> Atividades vencidas <P> atividades pendentes e <C> atividades concluídas
    }
void Sistema::paginaExibirAtividades(){
    //Selecionar atividade qualquer
        //"Atividade da/de cadeira <CADEIRA SELECIONADA>"
        //Estado da atividade
        //Nome da atividade
        //Descrição da atividade 
        //Data início da atividade
        //Data final da atividade

}
void Sistema::CadastrarAtividades(){}
void Sistema::paginaDeletarAtividades(){}
void Sistema::paginaAtualizarAtividades(){}


