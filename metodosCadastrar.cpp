#include "classes.hpp"

bool Sistema::login(std::string login, std::string senha){
    if (login == alunos.getLogin() && senha == alunos.getSenha()){
        return true;
    }
    else{
        return false;
    }
}




void cadastrarUsuario(const string& nome_arq) {
    
    fstream arq(nome_arq, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!arq.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return;
    }

    Usuario temp;

    string ntemp; // Ler o NOME do usuário
    cout << "Digite seu nome: ";
    getline(cin, ntemp);

    tm datatemp; // Ler a DATA DE NASCIMENTO do usuário
    cout << "Digite sua data de nascimento [DD] [MM] [AAAA]: ";
    cin >> datatemp.tm_mday >> datatemp.tm_mon >> datatemp.tm_year;
    datatemp.tm_mon -= 1; // Ajusta o mês (janeiro = 0)
    datatemp.tm_year -= 1900; // Ajusta o ano (anos desde 1900)
    cin.ignore(); // Limpa o buffer de entrada

    string confirmacaoSenha[2] = {"", ""};
    string ltemp;

    cout << "Digite seu login: ";
    cin >> ltemp;

    int tentativas = 3;
    do {
        cout << "Digite sua senha: ";
        cin >> confirmacaoSenha[0];
        
        cout << "Confirme sua senha: ";
        cin >> confirmacaoSenha[1];
        
        if (confirmacaoSenha[0] == confirmacaoSenha[1]) {
            break; // Sai do loop se as senhas coincidirem
        } else {
            tentativas--;
            cout << "As senhas não são compatíveis. Tentativas restantes: " << tentativas << endl;
        }
    } while (tentativas > 0);

    if (tentativas == 0) {
        cout << "Número máximo de tentativas atingido. Tente novamente mais tarde." << endl;
        return;
    }

    // Quando tudo estiver certo para cadastrar:
    temp.setNome(ntemp);
    temp.setDataNasc(datatemp);
    temp.setLogin(ltemp);
    temp.setSenha(confirmacaoSenha[0]);

    try {
        arq << temp.getLogin() << ", "  // Login
            << temp.getSenha() << " | " // Senha
            << temp.getNome() << " - "  // Nome
            << temp.getDataNasc().tm_mday << "/"
            << (temp.getDataNasc().tm_mon + 1) << "/" // Ajusta o mês
            << (temp.getDataNasc().tm_year + 1900) << endl; // Ajusta o ano
    } catch (...) {
        cout << "Erro ao escrever no arquivo!" << endl;
        arq.close();
        return;
    }

    usuarios.push_back(temp);
    cout << "Usuário cadastrado com sucesso!" << endl;
    arq.close();
}












void Sistema::cadastrarPeriodo(Periodo& periodoTemporario){
    cadastrarNomePeriodo(periodoTemporario);
    cadastrarCadeira    (periodoTemporario, cadeiraTemporario);
}            

void Sistema::cadastrarNomePeriodo(Periodo& periodoTemporario){
    std:: cout << "Digite o nome do período que deseja criar: ";
    std:: getline(std::cin,periodoTemporario.nome);
}

// método que engloba os métodos
void Sistema::cadastrarCadeira(Periodo& periodoTemporario, Cadeira& cadeiraTemporario){
    cadastrarNomeCadeira    (cadeiraTemporario);
    cadastrarNomeProfessor  (cadeiraTemporario);
    cadastrarEmentaCadeira  (cadeiraTemporario);
    cadastrarVectorAtividade(cadeiraTemporario);

    periodoTemporario.cadeirasTotais.push_back(cadeiraTemporario);
    
  } 

void Sistema::cadastrarNomeCadeira(Cadeira& cadeiraTemporario){
   std:: cout << "Digite o nome da cadeira: ";
   std::getline(std::cin, cadeiraTemporario.nome);
}

void Sistema::cadastrarNomeProfessor(Cadeira& cadeiraTemporario){
    std:: cout << "Digite o nome do professor responsável pela cadeira: ";
    std:: getline(std::cin,cadeiraTemporario.professor);
}

void cadastrarEmentaCadeira(Cadeira& cadeiraTemporario){
   std:: cout << "Digite a ementa da cadeira (uma por vez): ";

   do{
        std:: cout << "Digite \"s\" para sair: ";
        std:: getline(std::cin, cadeiraTemporario.nome);
        PeriodosTotais.back().CadeirasTotais.back().ementa.push_back(cadeiraTemporario.nome);
     }while(cadeiraTemporario.nome!="s");
}

// cadastra uma atividade no vector de atividades de cadeira usando as variáveis "temporárias" cadeiraTemporario e atividadeTemporario como "entregadores de informações" para o vector
    void Sistema::cadastrarVectorAtividade(Cadeira& cadeiraTemporario){

        Atividade atividadeTemporario; 
        std:: string escolha; // condição para sair do loop
        std:: cout << "Digite o nome da Atividade que deseja criar: ";
        
        do{
            atividadeTemporario.cadastrarAtividade();
            cadeiraTemporario.atividadesTotais.push_back(atividadeTemporario);
            std::getline(std::cin,escolha);
            std:: cout << "Digite \"new\" se deseja cadastrar outra atividade: ";
        }while(escolha =="new");
    }













    bool Sistema::verificarEmail(const std::string& emailTemp) {
        for (const Usuario& usuarioTemp : Sistema:: usuarios) {
            if (emailTemp == usuarioTemp.getEmail()) {
                return true; 
            }
        }
        return false; 
    }
    void Sistema::solicitarEmail(string emailTemp) {
        std::cout << "Insira seu E-mail: ";
            getline(std::cin, emailTemp);
    
        while (!verificaEmail(emailTemp)){
            std::cout << "Não existe conta com esse E-mail. Por favor, tente novamente." << std::endl;
            std::cout << "Insira seu E-mail: ";
            getline(std::cin, emailTemp);
        }    
    }
  

    
    bool Sistema::verificarSenha(const std::string& senhaTemp) {
        for (const Usuario& usuarioTemp : usuarios) {
            if (senhaTemp == usuarioTemp.getEmail()) {
                return true; 
            }
        }
        return false; 
    }
    void Sistema::solicitarSenha(string senhalTemp) {
        std::cout << "Insira sua Senha: ";
            getline(std::cin, senhaTemp);
    
        while (!verificaEmail(senhaTemp)){
            std::cout << "Não existe conta com essa Senha. Por favor, tente novamente." << std::endl;
            std::cout << "Insira seu Senha: ";
            getline(std::cin, senhaTemp);
        }    
    }



