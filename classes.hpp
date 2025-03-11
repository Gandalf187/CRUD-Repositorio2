

#include <iostream>
#include <ctime>
#include <chrono>
#include <string>
#include <vector>
#include <windows.h>
#include "metodos_cadastrar.cpp"

typedef enum {
    PERIODO,
    ATIVIDADE
} tTipoCadastro;

//IntervaloTempo
class IntervaloTempo{
    protected:
        tTipoCadastro tipoCadastro;
        tm tempoInicio;
        tm tempoFinal;
    public:
    // Usado na função cadastrarTempo. Aqui, é definido qual o tipo de dado que te deseja cadastrar
    // Função para CADASTRAR a data de uma ATIVIDADE ou de um PERÍODO
        void cadastrarTempoFinal(){
            if(tipoCadastro == PERIODO){
                std::cout << "Cadastro de Período: (Formato: [Dia] [Mês] [Ano])\nSua data: ";
                std::cin >> tempoInicio.tm_mday >> tempoInicio.tm_mon >> tempoInicio.tm_year;
                tempoInicio.tm_hour = 0;
                tempoInicio.tm_min = 0;
                tempoInicio.tm_sec = 0;
            }
            else if (tipoCadastro == ATIVIDADE){
                std::cout << "Cadastro de Atividade: (Formato: [Dia] [Mês] [Ano] [Hora] [Min])\nSua data: ";
                std::cin >> tempoInicio.tm_mday >> tempoInicio.tm_mon >> tempoInicio.tm_year >> tempoInicio.tm_hour >> tempoInicio.tm_min;
                tempoInicio.tm_sec = 0;
            }
        }

        void cadastrarTempoInicio(){
            if(tipoCadastro == PERIODO){
                std::cout << "Cadastro de Período: (Formato: [Dia] [Mês] [Ano])\nSua data: ";
                std::cin >> tempoInicio.tm_mday >> tempoInicio.tm_mon >> tempoInicio.tm_year;
                tempoInicio.tm_hour = 0;
                tempoInicio.tm_min = 0;
                tempoInicio.tm_sec = 0;
            }
            else if (tipoCadastro == ATIVIDADE){
                std::cout << "Cadastro de Atividade: (Formato: [Dia] [Mês] [Ano] [Hora] [Min])\nSua data: ";
                std::cin >> tempoInicio.tm_mday >> tempoInicio.tm_mon >> tempoInicio.tm_year >> tempoInicio.tm_hour >> tempoInicio.tm_min;
                tempoInicio.tm_sec = 0;
            }
            std::cout << "Cadastro de data realizado com sucesso!" << std::endl;
        }

        bool compararTempos(tm dataFornecida, tm dataAlvo) {
            return mktime(&dataFornecida) >= mktime(&dataAlvo);
        }                                                                                                                    

        void exibirTempo(){
            std::cout << "Data de início: " << tempoInicio.tm_mday << "/" << tempoInicio.tm_mon << "/" << tempoInicio.tm_year << " " << tempoInicio.tm_hour << ":" << tempoInicio.tm_min << std::endl;
            std::cout << "Data de término: " << tempoFinal.tm_mday << "/" << tempoFinal.tm_mon << "/" << tempoFinal.tm_year << " " << tempoFinal.tm_hour << ":" << tempoFinal.tm_min << std::endl;
        }

        void exibirTempoParaArquivo(){
            if(tipoCadastro == PERIODO){
                std::cout << tempoInicio.tm_mday << "/" << tempoInicio.tm_mon << "/" << tempoInicio.tm_year << "|";
                std::cout << tempoFinal.tm_mday << "/" << tempoFinal.tm_mon << "/" << tempoFinal.tm_year;
            }
            else if(tipoCadastro == ATIVIDADE){
                std::cout << tempoInicio.tm_mday << "/" << tempoInicio.tm_mon << "/" << tempoInicio.tm_year << "," << tempoInicio.tm_hour << ":" << tempoInicio.tm_min << "|";
                std::cout << tempoFinal.tm_mday << "/" << tempoFinal.tm_mon << "/" << tempoFinal.tm_year << "," << tempoFinal.tm_hour << ":" << tempoFinal.tm_min;
            }
        }

        // Função para comparar o TEMPO ATUAL com outra data. Retorna true caso o tempo atual seja IGUAL OU MAIOR do que o fornecido.
        bool compararComTempoAtual(){

            std::chrono::system_clock::time_point agora = std::chrono::system_clock::now();
            time_t tempo = std::chrono::system_clock::to_time_t(agora); // Conversão para time_t
            tm* tempoAtual = localtime(&tempo); // Deixa o tempo usável, convertendo time_t para "tm"

            tempoAtual->tm_mon += 1;      // Os meses são contados de 0 a 11. Então para pegar o mês certo, é preciso somar 1
            tempoAtual->tm_year += 1900;  // Os anos são contados a partir de 1900. Então para pegar o ano certo, é preciso somar 1900

            return compararTempos(tempoAtual, tempoFinal);
        }
};
//Atributos

class Atividade: public IntervaloTempo{
    
    public:
        //atributos
        std::string nome;
        bool foiConcluida;

        //métodos
        Atividade(){
            tipoCadastro = ATIVIDADE;
        }
        Atividade(std::string n, tm dataInicio, tm dataFinal) : Atividade(){
            nome = n;
            tempoInicio = dataInicio;
            tempoFinal = dataFinal;
        }

        void cadastrarAtividade(){
            std:: cin >> nome;
        }
};

//Prova
class Prova: public Atividade{
    //Atributos
    float nota;
    //métodos
};



//Cadeira
class Cadeira{

    //Atributos
    public:
        std::string nome; 
        std::vector<std::string> ementa;
        std::vector<Atividade> atividadesTotais;
        std::vector<Prova> provasTotais;
        std::string professor;
        
    typedef enum{
        APROVADA,
        REPROVADA,
        TRANCADA,
        CANCELADA,
    }estadoCadeira;
    
    

    //métodos
     void exibir(){
        std::cout << nome << std::endl;
     }
};

//Período
class Periodo : public IntervaloTempo{
    
    //Atributos
    public:
    std::vector<Cadeira> cadeirasTotais;
    std::string nome; 

    //métodos
    Periodo(){
        tipoCadastro = PERIODO;
    }
    Periodo(std::string n, tm dataInicio, tm dataFinal) : Periodo(){
        nome = n;
        tempoInicio = dataInicio;
        tempoFinal = dataFinal;
    }

    
    void exibirCadeiras(){
        for(auto& cadeira : cadeirasTotais){
            cadeira.exibir();
        }
    }
};


//Usuário
class Usuario{
    private:
        std::string nome;
        tm dataNasc;
        std::string email;
        std::string nomeDeUsuario;
        std::string  senha;
        std::vector<Periodo> PeriodosTotais;
        
    public:
        Usuario(std::string n, tm dN, std::string e, std::string nDU, std::string  s): nome(n), dataNasc(dN), email(e), nomeDeUsuario(nDU), senha(s){}
        std::string getNome(){
            return nome;
        }
        tm getDataNasc(){
            return dataNasc;
        }
        std::string getNomeDeUsuario(){
            return nomeDeUsuario;
        }
        
        std::string getEmail(){
            return email;
        }
        std::string getSenha(){
            return senha;
        }

        void setNome(std::string n){
            nome = n;
        }
        void setDataNasc(tm dn){
            dataNasc = dn;
        }
        void setLogin(std::string nDU){
            nomeDeUsuario = nDU;
        }
        void setEmail(std::string e){
            email = e;
        }
        void setSenha(std::string s){
            senha = s;
        }
};

class Sistema{

    //Atributos
    private:
        std:: vector<Usuario> usuarios;

    public:
  
    //métodos
    bool login(std::string login, std::string senha);
    

    //páginas
    void paginaInicial();
    void paginaFazerLogin();
    void paginaCadastrarUsuario();
    void paginaDeletarUsuario();
    void paginaAtualizarUsuario();

    void paginaPeriodos();
    void paginaExibirPeriodos();
    void paginaCadastrarPeriodo();
    void paginaDeletarPeriodos();
    void paginaAtualizarPeriodos();

    void paginaCadeiras();
    void paginaExibirCadeira();
    void paginaCadastrarCadeira();
    void paginaDeletarCadeira();
    void paginaAtualizarCadeira();


    void paginaAtividades();
    void paginaExibirAtividades();
    void paginaCadastrarAtividades();
    void paginaDeletarAtividades();
    void paginaAtualizarAtividades();
        

     //métodos de cadastrar
    void cadastrarUsuario(std::string nome, time_t dataNasc, std::string login, std:: string senha); //pq não chamar o construtor

    void cadastrarPeriodo(Periodo& periodoTemporario);
    void cadastrarNomePeriodo(Periodo& periodoTemporario);
   
    void cadastrarCadeira(Periodo& periodoTemporario, Cadeira& cadeiraTemporario);
    void cadastrarNomeCadeira(Cadeira& cadeiraTemporario);
    void cadastrarNomeProfessor(Cadeira& cadeiraTemporario);
    void cadastrarEmentaCadeira(Cadeira& cadeiraTemporario);
    void cadastrarVectorAtividade(Cadeira& cadeiraTemporario);

    //métodos de exibir

    //métodos de atualizar

    //métodos de deletar


    // categoria a nomear
    bool verificaEmail(const std::string& emailTemp);
    void solicitarEmail(string emailTemp); 
    bool verificaSenha(const std::string& senhaTemp);
    void solicitarSenha(string senhaTemp); 
























        //métodos de arquivos
        std::string mostrarDataNascUsuario(Usuario u){
            return u.getDataNasc().tm_mday << "/" <<
                   u.getDataNasc().tm_mon  << "/" <<
                   u.getDataNasc().tm_year;
        }
    
        bool carregarDados(std::string nomeDoArquivo){
            std::fstream arq;
            arq.open(nomeDoArquivo, std::fstream::in);
            if(!arq.is_open()){
                std::cout << "Falha ao salvar seus dados, tente novamente\n";
                return false;
            }
    
            std::string linha;
    
            while(std::getline(arq, linha)){ // Ler o arquivo inteiro
                
                if(linha == "1- Usuarios"){
                    while(std::getline(arq, linha)){
                        if(linha  == "- FimUsuarios") break;
    
                        std::string nomeDeUsuario, senha, nome, email;
                        tm dataNasc;
                        std::stringstream ss(linha);
                        std::getline(ss, nomeDeUsuario, ",");
                        std::getline(ss, senha, ",");
                        std::getline(ss, nomeDeUsuario, ",");
                        std::getline(ss, dataNasc.tm_mday, "/");
                        std::getline(ss, dataNasc.tm_mon, "/");
                        std::getline(ss, dataNasc.tm_year, ",");
                        std::getline(ss, email);
                        usuarios.emplace_back(Usuario(nome, dataNasc, email, nomeDeUsuario, senha));
                    }
                }
                
                else if(linha == "2- Periodos"){
                    while(std::getline(arq, linha)){
                        if(linha == "- FimPeriodos") break;
    
                        std::string nome;
                        tm dataInicio, dataFim;
                        std::stringstream ss(linha);
                        std::getline(ss, nome, ",");
                        std::getline(ss, dataInicio.tm_mday, "/");
                        std::getline(ss, dataInicio.tm_mon, "/");
                        std::getline(ss, dataInicio.tm_year, "|");
                        std::getline(ss, dataFim.tm_mday, "/");
                        std::getline(ss, dataFim.tm_mon, "/");
                        std::getline(ss, dataFim.tm_year);
                        PeriodosTotais.emplace_back(Periodo(nome, dataInicio, dataFim));
                    }
                }
    
                else if(linha == "3- CadeirasGeral"){
                    while(std::getline(arq, linha)){
                        if(linha == "- FimCadeirasGeral") break;
    
                        
                    }
                }
                
                else if(linha == "4- CadeiraEmenta"){
                    while(std::getline(arq, linha)){
                        if(linha  == "- FimCadeiraEmenta") break;
    
    
                    }
                }
                
                else if(linha == "5- CadeiraAtividades"){
                    while (std::getline(arq, linha)){
                        if(linha == "- FimCadeiraAtividades") break;
    
    
                    }
                }
    
                else if(linha == "6- CadeiraProvas"){
                    while(std::getline(arq, linha)){
                        if(linha == "- FimCadeiraProvas") break;
    
    
                    }
                }
            }
        }
    
        bool salvarDados(std::string nomeDoArquivo){
            std::fstream arq;
            arq.open(nomeDoArquivo, std::fstream::out | std::fstream::trunc);
    
            if(!arq.is_open()){
                std::cout << "Falha ao salvar seus dados, tente novamente\n";
                return false;
            }
    
            int tamanhoUsuarios = usuarios.size();
            int tamanhoPeriodos = PeriodosTotais.size();
    
            // Salvar vector usuarios
            arq << "1- Usuarios" << std::endl;
            for(int i = 0; i < tamanhoUsuarios; i++){
    
                arq << usuarios[i].getNome() << "," << usuarios[i].getSenha() << "," << usuarios[i].getNomeDeUsuario() << "," << mostrarDataNascUsuario(usuarios[i]) << usuarios[i].getEmail() <<std::endl;
            
            }
            arq << "- FimUsuarios" << std::endl;
    
            // Salvar vector periodos
            arq << "2- Periodos" << std::endl;
            for(int i = 0; i < tamanhoPeriodos; i++){
                arq << PeriodosTotais[i].nome << PeriodosTotais[i].exibirTempoParaArquivo() <<std::endl;
            }
            arq << "- FimPeriodos" << std::endl;
    
            // Salvar vector cadeiras
            arq << "3- CadeirasGeral" << std::endl;
            for(Periodo p: PeriodosTotais)
                    {
                        int tamanhoCadeiras = p.cadeirasTotais.size();
                        for (int i = 0; i < tamanhoCadeiras; i++)
                        {
    
                            arq << p.cadeirasTotais[i].nome << "," << p.cadeirasTotais[i].professor << "," << p.cadeirasTotais[i].estado << std::endl;
                        
                        }
                    }
            arq << "- FimCadeirasGeral" << std::endl;
    
            // Salvar vector ementa
            arq << "4- CadeiraEmenta" << std::endl;
            for(Periodo p : PeriodosTotais){
                int tamanhoCadeiras = p.cadeirasTotais.size();
                for(int i = 0; i < tamanhoCadeiras; i++){
                    for(std::string ementa : p.cadeirasTotais[i].ementa){
                        if(i + 1 != tamanhoCadeiras){
    
                            arq << ementa << ",";
    
                        }
                        else{
    
                            arq << ementa << std::endl;
    
                        }
                    }
                }
            }
            arq << "- FimCadeiraEmenta" << std::endl;
    
            // Salvar vector atividades
            arq << "5- CadeiraAtividades" << std::endl;
            for(Periodo p : PeriodosTotais){
                int tamanhoCadeiras = p.cadeirasTotais.size();
                for(int i = 0; i < tamanhoCadeiras; i++){
                    for(Atividade at : p.cadeirasTotais[i].atividadesTotais){
    
                        arq << at.nome << "," << at.foiConcluida() << std::endl;
    
                    }
                }
            }
            arq << "- FimCadeiraAtividades" << std::endl;
    
            // Salvar vector provas
            arq << "6- CadeiraProvas" << std::endl;
            for(Periodo p : PeriodosTotais){
                int tamanhoCadeiras = p.cadeirasTotais.size();
                for(int i = 0; i < tamanhoCadeiras; i++){
                    for(Prova pr : p.cadeirasTotais[i].ProvasTotais){
    
                        arq << pr.nome << "," << pr.nota << "," << pr.foiConcluida() << std::endl;
    
                    }
                }
            }
            arq << "- FimCadeiraProvas" << std::endl;
    
            arq.close();
            return true;
        }
};

