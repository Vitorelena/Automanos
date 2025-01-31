#include <iostream>
#include <chrono>
#include <thread>
#include "classes.hpp"
#include "funcoes.hpp"

      std::string enter;

      Humano H1; Vampiro V1; Elfo E1; Orc O1; Anao A1; //Instanciados objetos-base de raça  
      Cavaleiro Cv1; Arqueiro Ar1; Mago Mg1; //Instanciados objetos-base de classe
      Espada Esp1; Arco Arc1; Escudo Esc1; //Instanciados objetos-base de arma
      Player p1; //Instanciado objeto do jogador

int batalha (int vida_max, float vamp, int vida_m, int atf_m, int atm_m, int resf_m, int resm_m, float crit_m, float vamp_m, std::string nome, int vt){
    //a variável "vida_max" tem que ser criada no arquivo pricipal logo quando o personagem é escolhido
    //para registrar a vida máxima do personagem
    int vida_max_m;
    vida_max_m = vida_m;
    int l;
    int j;
    int y;

    Escrever ("Prepare-se para lutar contra o ", vt); Escrever (nome,vt); Escrever (".",vt);
    while (j != 1){
    std::cout<<"\nSua vida: "<<p1.R_vida<<"/"<<vida_max<<std::endl;
    std::cout<<"Vida do "<<nome<<": "<<vida_m<<"/"<<vida_max_m<<std::endl;
    Escrever("\n O que você deseja fazer?",vt);
    std::cout << endl << " 1-\33[1;34m" << "Usar o ataque mágico\n";
    std::cout << "\33[0m 2-"<< "\33[1;31m" << "Usar o ataque físico\n";
    std::cout << "\33[0m 3-"<< "\33[1;32m" << "Fugir como um covarde\n \33[0m";
    std :: cin >> y;

    if (y == 1){
         l = dano (p1.R_atk_m, resm_m, p1.R_crtRate); //ataque o personagem
        p1.R_vida += vamp*l;
        if (p1.R_vida > vida_max){
            p1.R_vida = vida_max;
        }

    } else if (y == 2){
        l = dano (p1.R_atk_f, resf_m, p1.R_crtRate); //ataque o personagem
            p1.R_vida += vamp*l;
            if (p1.R_vida > vida_max){
                p1.R_vida = vida_max;
         }

    } else if( y == 3){
    exit (0);
}
         vida_m = vida_m - l;

        if(vida_m <= 0){
            vida_m = 0;
            Escrever ("Você atacou e causou ",vt);
            std :: cout << l;
            Escrever (" de dano.\nAgora você tem ",vt);
            std :: cout << p1.R_vida;
            Escrever (" de vida e o ",vt); Escrever (nome,vt); Escrever (" morreu.",vt);

            std::cout<<"\nPressione ENTER para continuar."<<std::endl;
              std::cin.clear(); 
              std::cin.ignore(100, '\n'); 
              std::cin.get();
              clearScreen();
            j = 1;
            return j;
    }

        Escrever ("Você atacou e causou ",vt);
        std :: cout << l;
        Escrever (" de dano.\nAgora você tem ",vt);
        std :: cout << p1.R_vida;
        Escrever (" de vida e o ",vt); Escrever (nome,vt); Escrever(" tem ",vt);
        std :: cout << vida_m << ".\n";

        

    
        int x;
        int v = randomizer(2)+1; //ataque do monstro, essa linha calcula para o montro atacar com ataque físico ou mágico
        if (v == 1){
             x = dano (atf_m, p1.R_def_f, crit_m);
        } else if (v == 2){
            x = dano (atm_m, p1.R_def_m, crit_m);
        }
        vida_m = vida_m + x*vamp_m;
        if (vida_m > vida_max_m){
            vida_m = vida_max_m;
        }
        p1.R_vida -= x;
        

        Escrever ("\nO ",vt); Escrever (nome,vt); Escrever (" te atacou e causou ",vt);
        std :: cout << x; 
        Escrever (" de dano!!!!",vt);
        if (p1.R_vida <= 0){
        
        std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std::cin.ignore(); std::cin.get();
        clearScreen();
        Escrever ("\nVocê morreu.",vt);
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        exit (1);

        }
        Escrever ("\nAgora você tem ",vt); 
        std :: cout << p1.R_vida;
         Escrever (" de vida e o ",vt); Escrever (nome,vt); Escrever (" tem ",vt);
         std :: cout << vida_m << ".\n";

        std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std::cin.ignore(); std::cin.get();
        clearScreen();
    }
    return j;
}

int batalhadrag(bool amul, int vida_max, float vamp, int dif, int vt, std::string name, std::string ultimate){
    
    std::string drag = "\033[1;31mDragão\033[0m";
    int vida_max_d = 2000*dif;
    int vidad = vida_max_d;
    int resd = 50; //Resistência mágica e física do dragão
    int atqd = 50; // Ataque do dragão
    float critd = 0.5; //Chance de crítico do dragão
    int ultd = 0; // Rodadas para a ultimate do dragão
    int l;
    int j;
    int y;
    int esq = 3; //Esquiva
    int ult = 0; //Ultimate
    int cura = 4; // Cura
    int x;
    int v;
    int danomisto = 2*(p1.R_atk_f +p1.R_atk_m); // Dano misto entre fisico e mágico
    int resmista = p1.R_def_f + p1.R_def_m;
    dragao();
    Escrever("\033[1;35mPrincesa\033[0m: Saia da frente seu dragão imundo!!!\n",vt);
    Escrever(drag, vt);
    Escrever(": Meu nome é CORNELIUS, princesa e você será minha esposa!!!\n", vt);
    delay(1000);
    Escrever("E quem é esse que ousa fugir do meu castelo com minha princesa?\n\n", vt);
    Escrever(name, vt); Escrever(": Eu sou ", vt); Escrever(name, vt); Escrever(" e ela não vai casar com você!!!!!!\n ", vt);
    drag = "\033[1;31mDragão Cornelius\033[0m";
    Escrever ("Prepare-se para lutar contra o ", vt); Escrever (drag,vt); Escrever (".\n\n",vt);
    Escrever ("Aperte ENTER para começar a batalha final!!!\n",vt);
    std::cin.get();
    clearScreen();
    while (j != 1){
    if(esq > 3)
        esq = 3;
    if(ult > 5)
        ult = 5;
    if(cura > 4)
        cura = 4;
    clearScreen();
    dragao();
    std::cout<<"\nSua vida: "<<p1.R_vida<<"/"<<vida_max<<std::endl;
    std::cout<<"Vida do "<<drag<<": "<<vidad<<"/"<<vida_max_d<<std::endl;
    Escrever("\n O que você deseja fazer?",vt);
    std::cout << endl << " 1-\33[1;34m" << "Usar o ataque mágico\n\33[0m";
    std::cout << "\33[0m 2-"<< "\33[1;31m" << "Usar o ataque físico\n\33[0m";
    if(esq == 3)
        std::cout << "\33[0m 3-"<< "\33[1;32m" << "Esquivar!\n\33[0m";
    if(cura == 4 && amul == true)
        std::cout << "\33[0m 4-"<< "\33[1;35m" << "Curar!\n\33[0m";
    if(ult == 5 && amul == true)
        std::cout << "\33[0m 5-"<< ultimate <<"\n\33[0m";
    std :: cin >> y;

    if (y == 1){
         l = dano (p1.R_atk_m, resd, p1.R_crtRate); //ataque o personagem
        p1.R_vida += vamp*l;
        if (p1.R_vida > vida_max){
            p1.R_vida = vida_max;
        }
        Escrever ("Você atacou e causou ",vt);
        std :: cout << l;
        Escrever(" de Dano mágico!!\n",vt);
    } else if (y == 2){
        l = dano (p1.R_atk_f, resd, p1.R_crtRate); //ataque o personagem
            p1.R_vida += vamp*l;
            if (p1.R_vida > vida_max){
                p1.R_vida = vida_max;
         }
        Escrever ("Você atacou e causou ",vt);
        std :: cout << l;
        Escrever(" de Dano físico!!\n",vt);
    } else if( y == 3 && esq == 3){ //esquiva
        esq = 0;
        l =0;
        ult++;
        cura++;
        ultd++;
        Escrever(drag, vt); Escrever(": Você se esquivou do meu ataque!!! Da próxima vez isso não acontecerá!\n",vt);
        std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std :: cin.ignore(); std :: cin.get();
        
        continue;
    } else if(y == 4 && cura == 4){ //cura
        Escrever("Você se curou em 120 de vida!!\n", vt);
        p1.R_vida += 120;
            if (p1.R_vida > vida_max)
                p1.R_vida = vida_max;
        cura = 0;
        l = 0;
        
    } else if(y == 5 && ult == 5){//ultimate
        p1.R_vida -= vida_max/2;
        Escrever(name, vt); Escrever(": É agora...\n", vt);
        Escrever (".   ", 1);
        delay (1000);
        Escrever (".   ", 1);
        delay (1000);
        Escrever (".   ", 1);
        delay (1000);
        Escrever (".   \n", 1);
        Escrever (ultimate, 1);
        std::cout<<std::endl;
        l = dano (danomisto, resd, p1.R_crtRate);
        Escrever ("\nVocê atacou e causou ",vt);
        std :: cout << l;
        Escrever(" com a ultimate ",vt);
        Escrever (ultimate, vt); Escrever("!!!",vt);
        ult = 0;
        if (p1.R_vida <= 0){
        std::cout<<std::endl;
        Escrever(drag, vt); Escrever(": Acha que está no tutorial, guerreiro? Volta para o início e tente novamente!\nHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH\nTenta mudar a dificuldade mané\n\n",vt);
        std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std :: cin.ignore(); std :: cin.get();
        clearScreen();
        Escrever ("\nVocê morreu.",vt);
        delay(2000); 
        exit (1);

        }
        std :: cin.ignore(); std :: cin.get();
    }
         vidad = vidad - l;

        if(vidad <= 0){
            vidad = 0;
            Escrever ("Agora você tem ",vt);
            std :: cout << p1.R_vida;
            Escrever (" de vida e o ",vt); Escrever (drag,vt); Escrever (" morreu.",vt);

            std::cout<<"\nPressione ENTER para continuar."<<std::endl;
            std :: cin.ignore(); std :: cin.get();
            clearScreen ();
            j = 1;
            return j;
    }

        
        Escrever ("Agora você tem ",vt);
        std :: cout << p1.R_vida;
        Escrever (" de vida e o ",vt); Escrever (drag,vt); Escrever(" tem ",vt);
        std :: cout << vidad << ".\n";
        
            std::cin.clear();
            std::cin.ignore(100, '\n');
        
        if(ultd < 4){
             v = randomizer(2)+1; //ataque do monstro, essa linha calcula para o montro atacar com ataque físico ou mágico
            if (v == 1){
                x = dano (atqd, p1.R_def_f, critd);
            } else if (v == 2){
                x = dano (atqd, p1.R_def_m, critd);
            }
            
            Escrever ("\nO ",vt); Escrever (drag,vt); Escrever (" te atacou e causou ",vt);
            std :: cout << x; 
            Escrever (" de dano!!!!",vt);
            
        } else if(ultd == 4){
            Escrever(drag, vt); 
            Escrever(": Chegou a minha hora de brincar!!!\n",vt);
            Escrever (".   ", 1);
            delay (1000);
            Escrever (".   ", 1);
            delay (1000);
            Escrever (".   ", 1);
            delay (1000);
            Escrever (".   \n", 1);
            Escrever(drag, vt); Escrever ("\033[1;31m: CÉU ARDENTE EM CHAMAS!!!!!!\033[0m\n\n", 1);
            x = dano (3*atqd, resmista, critd);
            Escrever (drag,vt); Escrever (" usou \033[1;31m: CÉU ARDENTE EM CHAMAS!!!!!!\033[0m e causou ",vt);
            std :: cout << x; 
            Escrever (" de dano!!!!",vt);
            
        } else if(ultd == 5){//ultimate do dragão
            Escrever(drag, vt); Escrever (": Não acredito que deixarei de atacar porque utilizei minha maior arma\n\n", 1);
            ultd = 0;
            ult++;
            cura++;
            esq++;
            std::cout<<"\nPressione ENTER para continuar."<<std::endl;
            std :: cin.ignore(); std :: cin.get();
            continue;
        }
    
        p1.R_vida -= x;
        if (p1.R_vida <= 0){
        std::cout<<std::endl;
        Escrever(drag, vt); Escrever(": Acha que está no tutorial, guerreiro? Volta para o início e tente novamente!\nHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH\nTenta mudar a dificuldade mané\n\n",vt);
        std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std :: cin.ignore(); std :: cin.get();
        clearScreen();
        Escrever ("\nVocê morreu.",vt);
        delay(2000); 
        exit (1);

        }
        Escrever ("\nAgora você tem ",vt); 
        std :: cout << p1.R_vida;
         Escrever (" de vida e o ",vt); Escrever (drag,vt); Escrever (" tem ",vt);
         std :: cout << vidad << ".\n\n";
        if(ultd == 0){
            Escrever("\033[1;35mPrincesa\033[0m: Você consegue ",vt); Escrever (name,vt);Escrever("!!!!!\n",vt);
        }
        if(ultd == 1){
            Escrever(drag, vt); Escrever(": O último herói parece bastante com você... Tão inútil que foi derrotado antes do primeiro turno\n",vt);
        }
        if(ultd == 2){
            Escrever(drag, vt); Escrever(": Esse é o herói que enviaram? Parece que ninguém se importa com a princesa!\nHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH\n",vt);
        }
        if(ultd == 3){
            Escrever(drag, vt); Escrever(": HAHAHAHAHHAHAHAHAHAHAHAHAHAHAHHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAHAH\n",vt);
        }
        std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std :: cin.ignore(); std :: cin.get();
        clearScreen();
        ult++;
        cura++;
        esq++;
        ultd++;
    }
    return j;
}


int main(){
  std::string name;
  int seletor = 0;
  int dif = 1; // Dificuldade do jogo
  int config = 0, vt = 1; // Vt é a velocidade do texto
  float vamp = 0;
  int localizacao = 1;
  int vidaMax;
  int raça, classe;
  do{
    clearScreen();
    Menu(vt);
    std::cin >> seletor;

    if(seletor == 1){
      clearScreen();
      Escrever("\nBom, para começar...",vt);
      
      Escrever("\nComo é mesmo o seu nome? ",vt);
      std::cin >> name;
      
      clearScreen();
      Escrever("\nSeja bem-vindo, ", vt); Escrever(name, vt); Escrever("!", vt);
      Escrever("\nO que você é?\n", vt);

      //////// --- CRIAÇÃO DO PERSONAGEM --- ////////
      
        std::cout << " 1-\033[1;34m" << "Humano\n";
        std::cout << "\033[0m 2-"<< "\033[1;31m" << "Vampiro\n";
        std::cout << "\033[0m 3-"<< "\033[1;32m" << "Elfo\n";
        std::cout << "\033[0m 4-"<< "\033[1;33m" << "Orc\n";
        std::cout << "\033[0m 5-"<< "\033[1;36m" << "Anão\n \033[0m";
          

        while(1){
          std::cin >> raça;
          if(raça==1){// Humano
            p1.R_atk_f = p1.R_atk_f + H1.R_atk_f;
            p1.R_atk_m = p1.R_atk_m + H1.R_atk_m;
            p1.R_def_f = p1.R_def_f + H1.R_def_f;
            p1.R_def_m = p1.R_def_m + H1.R_def_m;
            p1.R_vida = p1.R_vida + H1.R_vida;
            p1.R_crtRate = p1.R_crtRate + H1.R_crtRate;
            name = "\033[1;34m" + name + "\033[0m";
            break;
          }else if(raça==2){// Vampiro
            p1.R_atk_f = p1.R_atk_f + V1.R_atk_f;
            p1.R_atk_m = p1.R_atk_m + V1.R_atk_m;
            p1.R_def_f = p1.R_def_f + V1.R_def_f;
            p1.R_def_m = p1.R_def_m + V1.R_def_m;
            p1.R_vida = p1.R_vida + V1.R_vida;
            p1.R_crtRate = p1.R_crtRate + V1.R_crtRate;
            name = "\033[1;31m" + name + "\033[0m";
            vamp = V1.vampirismo;
            break;
          }else if(raça==3){// Elfo
            p1.R_atk_f = p1.R_atk_f + E1.R_atk_f;
            p1.R_atk_m = p1.R_atk_m + E1.R_atk_m;
            p1.R_def_f = p1.R_def_f + E1.R_def_f;
            p1.R_def_m = p1.R_def_m + E1.R_def_m;
            p1.R_vida = p1.R_vida + E1.R_vida;
            p1.R_crtRate = p1.R_crtRate + E1.R_crtRate;
            name = "\033[1;32m" + name + "\033[0m";
            break;
          }else if(raça==4){// Orc
            p1.R_atk_f = p1.R_atk_f + O1.R_atk_f;
            p1.R_atk_m = p1.R_atk_m + O1.R_atk_m;
            p1.R_def_f = p1.R_def_f + O1.R_def_f;
            p1.R_def_m = p1.R_def_m + O1.R_def_m;
            p1.R_vida = p1.R_vida + O1.R_vida;
            p1.R_crtRate = p1.R_crtRate + O1.R_crtRate;
            name = "\033[1;33m" + name + "\033[0m";
            break;
          }else if(raça==5){// Anao
            p1.R_atk_f = p1.R_atk_f + A1.R_atk_f;
            p1.R_atk_m = p1.R_atk_m + A1.R_atk_m;
            p1.R_def_f = p1.R_def_f + A1.R_def_f;
            p1.R_def_m = p1.R_def_m + A1.R_def_m;
            p1.R_vida = p1.R_vida + A1.R_vida;
            p1.R_crtRate = p1.R_crtRate + A1.R_crtRate;
            name = "\033[1;36m" + name + "\033[0m";
            break;
          }else {
            Escrever("Insira uma opção válida!\n", vt);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
          }
        }
         
      Escrever("\nQual a sua Classe?\n", vt);
      std::cout<<"1-Cavaleiro."<<std::endl;
      std::cout<<"2-Arqueiro."<<std::endl;
      std::cout<<"3-Mago."<<std::endl;

        while(1){  
          std::cin>>classe;
          if(classe==1){//Cavaleiro Cv1
            p1.R_atk_f = p1.R_atk_f + Cv1.C_atk_f;
            p1.R_atk_m = p1.R_atk_m + Cv1.C_atk_m;
            p1.R_def_f = p1.R_def_f + Cv1.C_def_f;
            p1.R_def_m = p1.R_def_m + Cv1.C_def_m;
            p1.R_vida = p1.R_vida + Cv1.C_vida;
            p1.R_crtRate = p1.R_crtRate + Cv1.C_crtRate;
            break;
          }else if(classe==2){//Arqueiro Ar1
            p1.R_atk_f = p1.R_atk_f + Ar1.C_atk_f;
            p1.R_atk_m = p1.R_atk_m + Ar1.C_atk_m;
            p1.R_def_f = p1.R_def_f + Ar1.C_def_f;
            p1.R_def_m = p1.R_def_m + Ar1.C_def_m;
            p1.R_vida = p1.R_vida + Ar1.C_vida;
            p1.R_crtRate = p1.R_crtRate + Ar1.C_crtRate;
            break;
          }else if(classe==3){//Mago Mg1
            p1.R_atk_f = p1.R_atk_f + Mg1.C_atk_f;
            p1.R_atk_m = p1.R_atk_m + Mg1.C_atk_m;
            p1.R_def_f = p1.R_def_f + Mg1.C_def_f;
            p1.R_def_m = p1.R_def_m + Mg1.C_def_m;
            p1.R_vida = p1.R_vida + Mg1.C_vida;
            p1.R_crtRate = p1.R_crtRate + Mg1.C_crtRate;
            break;
          }else{
            Escrever("Insira uma opção válida!\n", vt);
            std::cin.clear();
            std::cin.ignore(100, '\n');
            continue;
          }
        }
      clearScreen();
      Escrever("Muito bem, ", vt); Escrever(name, vt); 
      Escrever(", a seguir, os seus atributos iniciais:\n", vt); 
      Escrever("(Lembre-se deles, pois serão muito importantes durante a sua jornada!)\n\n", vt); 
      if(raça == 1)
        homem(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 2) 
        vampiro(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 3)
        elfo(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 4)
        orc(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 5) 
         anao(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else 
        homem(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);

      vidaMax = p1.R_vida;

        std::cin.ignore();
        std::cout << "Pressione Enter para continuar..."<<std::endl;
        std::getline(std::cin, enter);
        clearScreen();

      ////////////////////////////////////////////////

    } else if(seletor == 2){
      do{
        clearScreen();
        std::cout << "\033[1;34m" << "===============================================================\n"
        << "\033[m1- Dificuldade\n2- Velocidade do texto\n3- Voltar ao menu\n"
        << "\033[1;34m" << "===============================================================\n" << "\033[0m";
        std::cin >> config;
        if(config == 1){
          clearScreen();
          std::cout << "\033[1;34m" << "===============================================================\n\033[0m";
          Escrever("Escolha a dificuldade do jogo:\n",vt);
          std::cout << "1- Fácil\n2- \033[1;33mMédio\n\033[0m3-\033[31m Difícil\n\033[0m4- \033[1;31mMUITO DIFICIL\033[0m\n";
          std::cout << "\033[1;34m" << "===============================================================\n\033[0m";
          std::cin >> dif;
          if(dif > 4)
          dif = 4;
          if(dif < 1)
          dif = 1;
          config = 0;
        } else if(config == 2){
              clearScreen();
              std::cout << "\033[1;34m" << "===============================================================\n\033[0m";
              Escrever("Escolha a velocidade do texto:\n1- Normal\n2- Rápido\n3- Muito Rápido\n", vt);
              std::cout << "\033[1;34m" << "===============================================================\n\033[0m";
              std::cin >> vt;
              if(vt >= 3)
                vt = 4;
              if(vt < 1)
                vt = 1;
              config = 0;
          } else
            config = 3;
            seletor = 0;
      } while (config == 0);
        
    } else if(seletor == 3){
      clearScreen();
      mapa(localizacao);
      std::cout<<"\n Você está na marca X vermelha!!"<< std::endl;
      seletor = 0;
      std::cout<<"\nPressione ENTER para voltar ao menu"<<std::endl;
      std::cin.ignore(); std::cin.get();
    } else if(seletor == 4){
      if(vt > 1 || dif > 1){
        Escrever("Uai, para que o 'caba' foi mexer nas configurações se ele não ia jogar?\n", vt);
      }
      exit(1);
    }else if(seletor == 5){
      creditos();
      seletor = 0;
      std::cout<<"\nPressione ENTER para voltar ao menu"<<std::endl;
      std::cin.ignore(); std::cin.get();
    }else{
      seletor = 0;
    }
  }while(seletor == 0);
    
    //batalha(vidaMax, 100, 50, 50, 10, 10, 0.25, 0.3,vamp,"Vampiro", vt);
 //_______________________________________________________________//
 //1ª Fase - PRÓLOGO--------------------------------------------------------//
  clearScreen();
  Escrever ("Você estava treinando nas florestas ao redor do Vilarejo, quando ouviu um grito feminino...", vt);
  Escrever ("\nParece ser da princesa, ela deve estar correndo perigo.", vt);
  Escrever ("\nVocê corre como uma flecha, mas já é tarde, os gritos da princesa foram emudecidos ", vt);
  Escrever ("pelo bater de asas de um grande monstro que a levara para longe.", vt);
  Escrever ("\n\nDesesperado, você corre para sua casa a fim de contar a sua mãe o que aconteceu. ", vt);
  Escrever ("Você chega em casa e está ofengante.", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  clearScreen();

  Escrever ("\033[35;1mMãe: \033[0mOi, filho, o que aconteceu?\n", vt);
  Escrever(name, vt);
  delay (1000);
  Escrever (":  .   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  Escrever ("\033[35;1m\nMãe: \033[0mMas você não viu o que a levou?\n", vt); Escrever (name, vt);
  Escrever (": Não.\n\033[35;1mMãe: \033[0mFoi você quem a viu ser capturada, é uma missão sua reencontrá-la...\n", vt);
  Escrever (name, vt);  Escrever (": MAS EU?!\n", vt); Escrever("\033[35;1mMãe: \033[0m Sim, você...\n", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
  Escrever ("\033[35;1mMãe: \033[0mVocê viu para onde ela foi levada?\n", vt);
  Escrever (name, vt); Escrever (": Não.\n", vt);
  Escrever ("\033[35;1mMãe: \033[0mSem problemas. Vá a Hoenn Land, lá você encontrará o sábio Melchior. Ele te ajudará em sua jornada.\n", vt);
  Escrever ("Mas antes de ir, tome isto. É um mapa do reino feito pelo seu tataravô.\n", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
  std::cout << "\033[31;1mVocê recebeu o mapa!\033[0m\n";
  delay(500);
  clearScreen();
  std :: cout << "\033[32;1mVocê recebeu o mapa!\033[0m\n";
  delay(500);
  clearScreen();
  std :: cout << "\033[33;1mVocê recebeu o mapa!\033[0m\n";
  delay (500);
  clearScreen();
  std :: cout << "\033[34;1mVocê recebeu o mapa!\033[0m\n";
  delay (500);

    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  mapa(localizacao);
  std::cout<<"\n Você está na marca \033[31;1mX\033[0m vermelha!!"<< std::endl;
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  //2ª Fase - ENCONTRO COM OS TROLLS--------------------------------------------------------//
  Escrever("Você parte em direção à Cidade de Hoenn Land", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);
  Escrever (".   ", 1);
  delay (1000);

  Escrever ("\nNo meio do caminho você encontra três trolls em volta de um fogueira assando um pequeno carneiro.\n", vt);
  Escrever ("\033[33;1mTrolls: \033[0m", vt); Escrever("Olha o que encontramos... Uma saborosa iguaria!", vt);
  Escrever (" Você servirá de petisco para nós.\n", vt);
  Escrever (name, vt); Escrever (": Não se eu matá-los antes.\n\n", vt);
  Escrever ("Prepare-se para batalhar contra o primeiro troll.", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
  
  Escrever ("\033[33;1mTom: \033[0m", vt); Escrever ("Eu vou cortar você em picadinhos e cozinhar sua carne.\n\n", vt);
  batalha(vidaMax, vamp, 120, 10, 10, 18, 1000, 0.25, 0.0, "\033[33;1mTom\033[0m", vt);

  Escrever ("\033[34;1mBert: \033[0m", vt); Escrever ("NÃO! Você matou o meu irmão!\n", vt);
  Escrever ("Prepare-se para batalhar contra o segundo troll.", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  Escrever ("\033[34;1mBert: \033[0m", vt); Escrever ("Eu vou sentar em cima de você e te amassar!\n\n", vt);
  batalha(vidaMax, vamp, 120, 10, 10, 1000, 18, 0.25, 0.0, "\033[33;1mBert\033[0m", vt);
 
  Escrever ("\033[34;1mWilliam: \033[0m", vt); Escrever ("Você vai pagar pelo que fez com meus irmãos!\n\n", vt);
  Escrever ("Prepare-se para batalhar contra o terceiro troll.", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  Escrever ("\033[34;1mWilliam: \033[0m", vt); Escrever("Eu vou fazer espetinho de você!!\n\n", vt);
  batalha(vidaMax, vamp, 240, 10, 10, 30, 30, 0.25, 0.0, "\033[33;1mWilliam\033[0m", vt);
    
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);

  clearScreen();
  std::cout << "\033[31;1mVocê derrotou os trolls!\033[0m\n";
  delay(500);
  clearScreen();
  std :: cout << "\033[32;1mVocê derrotou os trolls!\033[0m\n";
  delay(500);
  clearScreen();
  std :: cout << "\033[33;1mVocê derrotou os trolls!\033[0m\n";
  delay (500);
  clearScreen();
  std :: cout << "\033[34;1mVocê derrotou os trolls!\033[0m\n";
  delay (500);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  //3ª Fase - HOENN LAND E O VELHO MELCHIOR-----------------------------------------------------
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);

  Escrever("\nDepois de uma breve caminhada você finalmente chega à Hoenn Land, a cidade capital do país!", vt);
  Escrever("\nAo pedir informações aos habitantes, você descobre que Melchior está em sua escola de Filosofia", vt);
  Escrever("\nApós uma rápida procura pela cidade, você se depara com uma velha casa de madeira com uma placa escrito:", vt);
  Escrever("\n\033[33;1m'Academia de Filosofia para jovens superdotados'\033[0m\n", vt);
  Escrever("Ao passar pela porta, é surpreendido com um velho de dois metros de altura a sua frente!\n", vt);
  std::cout<<"\033[32;1mMelchior: \033[0m"; Escrever("Quem é você e o que fazes aqui, garoto?\n", vt);
  std::cout<<name<<": "; delay (500); Escrever ("  .   ", 1); delay (500); Escrever (".   ", 1); delay (500); Escrever (".   ", 1);
  std::cout<<"\033[32;1m\nMelchior: \033[0m"; Escrever("Entendi! Neste caso, um velho amigo meu pode te ajudar.\n", vt);
  Escrever("É um habilidoso oráculo que mora a sul daqui, ele com certeza vai saber te dizer a localização da princesa!\n", vt);
  Escrever("Vou marcar a localização dele no seu mapa, um momento.", vt);
    std::cout << "\nPressione Enter para abrir o mapa..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
    mapa(2);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
  std::cout<<"\033[32;1mMelchior: \033[0m"; Escrever("Ei jovem, espere! Não vá tão rápido!\n", vt);
  Escrever("Tenho o pressentimento de que sua jornada para resgatar a princesa será perigosa, não é seguro ir desarmado. ", vt);
  Escrever("Venha, me acompanhe, tenho uma coisa para te dar, vai ser muito útil em sua aventura\n\n.", vt);
  Escrever("*Você segue o sábio \033[32;1mMelchior\033[0m até uma sala nos fundos da escola*\n\n", vt);
  std::cout<<"\033[32;1mMelchior: \033[0m"; Escrever("Tome, essas armas foram forjadas a muito tempo num reino muito distante por uma antiga sociedade de anões místicos e empunhadas por grandes heróis do passado!", vt);
  Escrever("\nInfelizmente você só pode escolher uma das três, mas não se preocupe, ela não te decepcionará e será fiel a ti durante toda a sua jornada.\n\n", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
  int arma;
  Escrever("Escolha uma das armas:\n", vt);
  std::cout<<"\033[1;33m[1] \033[0mA Espada Mágica de Sir. Byron.\n"
           <<"\033[1;33m[2] \033[0mO Escudo Encantado de Lord Shelling.\n"
           <<"\033[1;33m[3] \033[0mO Arco Místico da Rainha Hildegarda.\n";
  while(1){
    std::cin>>arma;
    if(arma == 1){
      p1.R_atk_f = p1.R_atk_f + Esp1.A_atk_f;
      p1.R_atk_m = p1.R_atk_m + Esp1.A_atk_m;
      p1.R_def_f = p1.R_def_f + Esp1.A_def_f;
      p1.R_def_m = p1.R_def_m + Esp1.A_def_m;
      break;
    }else if(arma == 2){
      p1.R_atk_f = p1.R_atk_f + Esc1.A_atk_f;
      p1.R_atk_m = p1.R_atk_m + Esc1.A_atk_m;
      p1.R_def_f = p1.R_def_f + Esc1.A_def_f;
      p1.R_def_m = p1.R_def_m + Esc1.A_def_m;
      break;
    }else if(arma == 3){
      p1.R_atk_f = p1.R_atk_f + Arc1.A_atk_f;
      p1.R_atk_m = p1.R_atk_m + Arc1.A_atk_m;
      p1.R_def_f = p1.R_def_f + Arc1.A_def_f;
      p1.R_def_m = p1.R_def_m + Arc1.A_def_m;
      break;
    }else {
      Escrever("Insira uma opção válida!\n", vt);
      std::cin.clear();
      std::cin.ignore(100, '\n');
      continue;
    }
  }
  clearScreen();
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);

  if(arma == 1){
    clearScreen();
    std::cout << "\033[31;1mVocê recebeu A Espada Mágica de Sir. Byron!\033[0m\n";
    delay(500);
    clearScreen();
    std::cout << "\033[32;1mVocê recebeu A Espada Mágica de Sir. Byron!\033[0m\n";
    delay(500);
    clearScreen();
    std::cout << "\033[33;1mVocê recebeu A Espada Mágica de Sir. Byron!\033[0m\n";
    delay (500);
    clearScreen();
    std::cout << "\033[34;1mVocê recebeu A Espada Mágica de Sir. Byron!\033[0m\n";
    delay (500);
  }else if(arma == 2){
    clearScreen();
    std::cout << "\033[31;1mVocê recebeu O Escudo Encantado de Lord Shelling!\033[0m\n";
    delay(500);
    clearScreen();
    std::cout << "\033[32;1mVocê recebeu O Escudo Encantado de Lord Shelling!\033[0m\n";
    delay(500);
    clearScreen();
    std::cout << "\033[33;1mVocê recebeu O Escudo Encantado de Lord Shelling!\033[0m\n";
    delay (500);
    clearScreen();
    std::cout << "\033[34;1mVocê recebeu O Escudo Encantado de Lord Shelling!\033[0m\n";
    delay (500);
  }else if(arma == 3){
    clearScreen();
    std::cout << "\033[31;1mVocê recebeu O Arco Místico da Rainha Hildegarda!\033[0m\n";
    delay(500);
    clearScreen();
    std::cout << "\033[32;1mVocê recebeu O Arco Místico da Rainha Hildegarda!\033[0m\n";
    delay(500);
    clearScreen();
    std::cout << "\033[33;1mVocê recebeu O Arco Místico da Rainha Hildegarda!\033[0m\n";
    delay (500);
    clearScreen();
    std::cout << "\033[34;1mVocê recebeu O Arco Místico da Rainha Hildegarda!\033[0m\n";
    delay (500);
  }
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.ignore(100, '\n');
      std::getline(std::cin, enter);
      clearScreen();
  Escrever("Estes são os seus atributos atualizados:\n\n", vt);
      if(raça == 1)
        homem(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 2) 
        vampiro(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 3)
        elfo(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 4)
        orc(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 5) 
         anao(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else 
        homem(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      std::cout << "\n\nPressione Enter para continuar..."<<std::endl;
      std::getline(std::cin, enter);
      clearScreen();  
  std::cout<<"\033[32;1mMelchior: \033[0m"; Escrever("Só mais uma coisa antes de ir, meu jovem. Você parece estar cansado.\n", vt);
  Escrever("Se quiser, pode ficar e descansar um pouco para recuperar suas energias.\n", vt);
  int descanso;
  Escrever("\nO que deseja fazer?\n", vt);
  std::cout<<"\033[1;33m[1] \033[0mFicar e descansar um pouco.\n"
           <<"\033[1;33m[2] \033[0mIr em bora, pois estamos com pressa.\n";
  while(1){
    std::cin>>descanso;
    if(descanso == 1){
      Escrever("*Você descansou e suas energias foram recuperadas*\n\n", vt);
      p1.R_vida = vidaMax;
      std::cout<<"Vida atual: "<<p1.R_vida<<"/"<<vidaMax<<std::endl;
    break;
    }else if(descanso == 2){
      std::cout<<"\033[32;1mMelchior: \033[0m"; Escrever("Muito bem, boa sorte aventureiro!\n.", vt);
    break;
    }else{
      Escrever("Insira uma opção válida!\n", vt);
      std::cin.clear();
      std::cin.ignore(100, '\n');
      continue;
    }
  }
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.ignore(100, '\n');
      std::getline(std::cin, enter);
    clearScreen();
    Escrever (".   ", 1);
    delay (500);
    Escrever (".   ", 1);
    delay (500);
    Escrever (".   ", 1);
    delay (500);
    clearScreen();


//4ª Fase - O ENIGMA DO ORÁCULO-------------------------------------------------------------

    Escrever ("*Após uma tranquila caminhada enquanto se guiava per intermédio do mapa, você chega à entrada da caverna do oráculo.*", vt);
      std::cout << "\nPressione Enter para abrir o mapa..."<<std::endl;
      std::cin.get();
      mapa (3);
      std::cout << "\nPressione Enter para fechar o mapa..."<<std::endl;
      std::cin.get();
      clearScreen();
  Escrever ("Na entrada da caverna você encontra uma enorme porta com uma placa que diz: 'porta mágica que protege o oráculo daqueles que são intelectualmente incapazes de compreendê-lo. Acerte as resposta e poderá prosseguir.'\n", vt);
  Escrever ("\033[120;1mPorta mágica: \033[0m", vt); Escrever ("Decifra-me ou eu te devoro.\n", vt);
      std::cout << "\nPressione Enter para iniciar as perguntas..."<<std::endl;
      std::cin.get();
      clearScreen();
  Escrever ("\033[120;1mPorta mágica: \033[0mPosso ser contado, medido e calculado, mas jamais recuperado. Passado fui, futuro serei, mas de presente sua resposta esperarei. Responda agora, sem demora, não faça hora! O que eu sou?", vt);
  std :: cout << endl << "\033[34;1m1 - Areia\033[0m" << endl << "\033[31;1m2 - Formigas\033[0m" << endl; //primeiro
  std :: cout  << "\033[32;1m3 - Tempo\033[0m"  << endl << "\033[33;1m4 - Mar\033[0m" << endl;
  int resp_en;
  std :: cin >> resp_en;
  if (resp_en == 3){
  Escrever ("\033[120;1mPorta mágica: \033[0m", vt); Escrever("Parabéns, você acertou. Mas seu desafio ainda não acabou.\n", vt);
  }else{
      Escrever ("Você foi devorado, sua jornada acaba aqui.", vt);
      delay (1000);
      clearScreen();
      exit(1);
  }

  Escrever ("\033[120;1mPorta mágica: \033[0mDe picos e vales faço minha direção, de velocidade constante mesmo em oscilação. Visível, de aspecto natural, se invisível, por vezes mortal. Ilumine sua mente, deixe-a clarear, somente assim a resposta encontrará! O que eu sou?", vt);
  std :: cout << endl << "\033[34;1m1 - Luz\033[0m" << endl << "\033[31;1m2 - Montanhas\033[0m" << endl;
  std :: cout  << "\033[32;1m3 - Terra\033[0m"  << endl << "\033[33;1m4 - Sombra\033[0m" << endl;
  std :: cin >> resp_en;
  if (resp_en == 1){
  Escrever ("\033[120;1mPorta mágica: \033[0m", vt); Escrever("Parabéns, você acertou. Mas seu desafio ainda não acabou.\n", vt);
  }else{
      Escrever ("Você foi devorado, sua jornada acaba aqui.", vt);
      delay (1000);
      clearScreen();
      exit(1);
  }

  Escrever ("\033[120;1mPorta mágica: \033[0mPor cima, podes sobreviver, por baixo, certamente vais morrer. Se doce ou salgada, muito ou nada, sou essencial. Independente do estado, podes me encontrar, presente em mar, terra e ar. O que eu sou?", vt);
  std :: cout << endl << "\033[34;1m1 - Selva\033[0m" << endl << "\033[31;1m2 - Água\033[0m" << endl;
  std :: cout  << "\033[32;1m3 - Leão\033[0m"  << endl << "\033[33;1m4 - Bomba\033[0m" << endl;
  std :: cin >> resp_en;
  if (resp_en == 2){
  Escrever ("\033[120;1mPorta mágica: \033[0m", vt); Escrever("Parabéns, você acertou. Mas seu desafio ainda não acabou.\n", vt);
  }else{
      Escrever ("Você foi devorado, sua jornada acaba aqui.", vt);
      delay (1000);
      clearScreen();
      exit(1);
  }

  Escrever ("\033[120;1mPorta mágica: \033[0mPara voar e velejar, posso em muito ajudar. Se forte demais, sua casa vou levar. Meu tamanho pode variar, dependo da temperatura que enfrentar. A resposta não vou te falar,  o segredo não vou te soprar. O que eu sou?", vt);
  std :: cout << endl << "\033[34;1m1 - Motor\033[0m" << endl << "\033[31;1m2 - Borracha\033[0m" << endl;
  std :: cout  << "\033[32;1m3 - Metal\033[0m"  << endl << "\033[33;1m4 - Ar\033[0m" << endl;
  std :: cin >> resp_en;
  if (resp_en == 4){
  Escrever ("\033[120;1mPorta mágica: \033[0m", vt); Escrever("Parabéns, você acertou. Mas seu desafio ainda não acabou.\n", vt);
  }else{
      Escrever ("Você foi devorado, sua jornada acaba aqui.", vt);
      delay (1000);
      clearScreen();
      exit(1);
  }

  Escrever ("\033[120;1mPorta mágica: \033[0mComo bônus, vou te perguntar, será que é capaz de adivinhar. Entre todos os grupos terá que escolher, qual é o melhor, se não, vai perder. Qual é o grupo mais honrado?", vt);
  std :: cout << endl << "\033[34;1m1 - Passe o sal\033[0m" << endl << "\033[31;1m2 - Automanos\033[0m" << endl;
  std :: cout  << "\033[32;1m3 - Power Rangers\033[0m"  << endl << "\033[33;1m4 - C+ou-\033[0m" << endl;
  std :: cin >> resp_en;
  if (resp_en == 2){
  Escrever ("\033[120;1mPorta mágica: \033[0m", vt); Escrever("Parabéns, jovem, você provou ser digno e sábio, pode passar.\n", vt);
  }else{
      Escrever ("Você foi devorado, sua jornada acaba aqui.", vt);
      delay (1000);
      clearScreen();
      exit(1);
  }
      std::cout << "\nPressione Enter para continuar..."<<std::endl; //quinto
      std::cin.ignore(); 
      std::cin.get();
      clearScreen();
  Escrever ("Você entrou dentro da caverna, ela é baixa e estreita. Com muito cuidado, caminha a passos lentos.\nNada pode ser ouvido a não ser",vt);
  Escrever (" o ecoar dos seus passos.\n\n",vt);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      clearScreen();
  Escrever ("Você entrou na sala principal, onde há uma placa escrito: 'Eis aqui o receptáculo da gnose'.\n",vt);
  Escrever (" \033[35;1mMérida: \033[0mSaudações, viajente, eu me chamo Mérida e sou a Oráculo de Delfos. Vejo que foi o velho Melchior que te enviou, né?\n",vt);
  Escrever ("Ele era muito amigo de meu pai, dê notícias a ele quando retornar de que o velho Hagrid está morto e que agora eu recebo", vt);
  Escrever (" os suspiros divinos.\n",vt);
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.get();
      clearScreen();
  Escrever (" \033[35;1mMérida: \033[0mAgora, conte-me, para que precisa de minhas inspirações?\n",vt);
  std::cout<<name<<": "; delay (500); Escrever ("  .   ", 1); delay (500); Escrever (".   ", 1); delay (500); Escrever (".   ", 1);
  Escrever ("\n\nMérida, então, em uma espécie de transe começa a flutuar e a girar, de sua garganta sai uma voz esganiçada que diz:\n", vt);
  Escrever (" \033[35;1mMérida: \033[0mA princesa foi levada para o Castelo do Dragão, depois das Montanhas Denadoro.\n",vt);
  Escrever ("Mas tenha cuidado, antes ir para lá certifique-se de passar no Templo de Ratanabá para pegar a máscara Oogway com o Sábio Gaspar,", vt);
  Escrever (" ela permitirá que você respire o ar rarefeito das montanhas. Caso contrário, sua travessia será fatal.", vt);
 
      std::cout << "\n\nPressione Enter para continuar..."<<std::endl;
      std::getline(std::cin, enter);
      clearScreen();

  Escrever ("Depois que Mérida volta a si, você se despede dela e volta a passos curtos para a entrada da caverna.\n", vt);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  Escrever (".   ", 1);
  delay (500);
  clearScreen();
  Escrever ("A luz do sol brilha novamente. Agora você pode enfim abrir o mapa para se localizar.", vt);
      std::cout << "\nPressione Enter para abrir o mapa..."<<std::endl;
      std::cin.get();
      clearScreen();
  mapa (3);
      std::cout << "\nPressione Enter para fechar o mapa..."<<std::endl;
      std::cin.get();
      clearScreen();
  Escrever ("Para onde você deseja ir?", vt);
  std :: cout << endl << "\033[34;1m1 - Templo de Ratanabá\033[0m" << endl << "\033[31;1m2 - Monte Denadoro\033[0m" << endl;
  std :: cout  << "\033[32;1m3 - Castelo do dragão\033[0m\n";
  std :: cin >> resp_en;
  if (resp_en != 1){
      Escrever ("Você tentou seguir a jornada sozinho como um orgulhoso e morreu sem ar no Monte Denadoro. Sua jornada acaba aqui.", vt);
      delay (1000);
      exit (1);
  }
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      Escrever (".   ", 1);
      delay (1000);
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.ignore();
      std::cin.get();
      clearScreen();

  //5ª Fase - O LOBISOMEN PIDÃO E O TEMPLO DE RATANABÁ------------------------------------------------------------------------

  Escrever ("\nVocê segue em direção ao Templo de Ratanabá para encontrar o velho Gaspar. Mas, no meio do caminho você tem que atravessar uma densa",vt);
  Escrever (" floresta de árvores de quinze metros de altura.\nJá é tarde da noite. Nada se ouve, a não ser o piar das corujas e", vt);
  Escrever (" um grande uivo ao longe.",vt);
  Escrever ("\nO medo se apossa de você, mas não há nada a ser feito, recuar agora não é uma opção, você deve seguir em frente...", vt);
  Escrever ("\nCaminhando para dentro da floresta você encontra o responsável por aqueles uivos tenebrosos...",vt);
  Escrever ("\nUma grande criatura de pelos negros, garras sujas de sangue e olhos azuis... Você encontrou o Grande Lobo Mau Pidão.", vt);
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.get();
      clearScreen();
  Escrever ("\033[30;1mGrande Lobo Mau Pidão: \033[0mA coruja pia, o cachorro late, e o lobo... o lobo pede. Mim dê, papaaaai. Auuuuuuu.\n",vt);
  Escrever (name, vt); Escrever (": Grande Lobo Mau Pidão? Aparentemente as lendas sobre você não eram apenas lendas...", vt);
  Escrever ("\033[30;1mGrande Lobo Mau Pidão: \033[0mMim dê, papaaaai. Auuuuuuu.\n",vt);
      std::cout << "\nPressione Enter para iniciar a batalha contra o Lobo..."<<std::endl;
      std::cin.get();
      clearScreen();

  batalha(vidaMax, vamp, 350, 30, 30, 40, 40, 0.2, 0.0, "\033[30;1mGrande Lobo Mau Pidão\033[0m", vt);

  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);

  clearScreen();
  std :: cout << "\033[31;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay(500); clearScreen();
  std :: cout << "\033[32;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay(500); clearScreen();
  std :: cout << "\033[33;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay (500); clearScreen();
  std :: cout << "\033[34;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay (500); clearScreen();
  std :: cout << "\033[31;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay(500); clearScreen();
  std :: cout << "\033[32;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay(500); clearScreen();
  std :: cout << "\033[33;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay (500); clearScreen();
  std :: cout << "\033[34;1mVocê derrotou o Grande Lobo Mau Pidão!\033[0m\n";
  delay (500);
  Escrever("\nInfelizmente, seus pedidos ainda ecoam pela memória daqueles que outra vez o encontraram.", vt);
    std::cout << "\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);

  Escrever ("Ainda caminha por algumas horas, mas após um dia tão cheio, você decide descansar. Depois de acender uma fogueira você repousa sobre a grama verde da grande floresta.",vt);
    std::cout << "\nPressione Enter para dormir..."<<std::endl;
    std::cin.get();
    clearScreen();
  Escrever ("Dormindo a noite toda.\n", vt);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever (".   ", 1); delay (500);
  Escrever ("!", 1);    delay (500);
      clearScreen();

  Escrever ("Acordando cedo com os primeiros raios de luz do Sol, você parte para completar sua jornada.\n",vt);
  Escrever ("O Templo de Ratanabá não estava muito longe.\nEm poucos minutos você se depara com suas torres de pedra envoltas por musgos",vt);
  Escrever (" e escondidas atrás de grandes árvores.\nEntrando no templo, dá de cara com um senhor de barba branca e meio metro de altura. Parece ser o velho Gaspar.",vt);
  Escrever ("\nApesar da velhice, Gaspar é intimidador. O ar de superioridade que emana dele te faz sentir medo.",vt);
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.get();
      clearScreen();
  Escrever ("\033[34;1mVelho Gaspar: \033[0mOra, ora, você chegou... Eu estava mesmo esperando por você.\n",vt);

  Escrever("\033[1;34mVelho Gaspar\033[0m: Aceite esse chá feito de Açaí para se recuperar de sua longa jornada!\n\n",vt);
    p1.R_vida = vidaMax;
  Escrever("Você recuperou 100% da sua vida com esse chá suspeito de Açaí!!\n",vt);
  std::cout<<"Vida atual: "<<p1.R_vida<<"/"<<vidaMax<<"\n"<<std::endl;
  Escrever("\033[1;34mVelho Gaspar\033[0m: Oque te levou a vir a este templo e enfrentar o Lobisomem, jovem rapaz?\n",vt);
  std::cout<<name<<": "; delay (500); Escrever ("  .   ", 1); delay (500); Escrever (".   ", 1); delay (500); Escrever (".   ", 1);
  Escrever("\033[1;34mVelho Gaspar\033[0m: Entendi! E para qual motivo você faria essaa travessia tão perigosa, onde muitos entes queridos se vão? \n",vt);
  Escrever(name,vt); Escrever(": Eu irei para salvar a princesa das garras daquele monstro!!!!\n",vt);
  Escrever("\033[1;34mGaspar\033[0m: Nobre motivo, meu jovem, te darei esse antigo e poderoso artefato que encontrado por Balthazar, meu irmão, há 400 anos atrás, enquanto ele era um jovem peregrino nos países do oriente\n",vt);
  Escrever("Como tenho saudade dele. . . .\n",1);
      std::cout << "\nPressione Enter para continuar..."<<std::endl;
      std::cin.get();
      clearScreen();
  std :: cout << "\033[31;1mVocê recebeu a máscara de Oogway!\033[0m\n";
  delay(500);
  clearScreen();
  std :: cout << "\033[32;1mVocê recebeu a máscara de Oogway!\033[0m\n";
  delay(500);
  clearScreen();
  std :: cout << "\033[33;1mVocê recebeu a máscara de Oogway!\033[0m\n";
  delay (500);
  clearScreen();
  std :: cout << "\033[34;1mVocê recebeu a máscara de Oogway!\033[0m\n";
  delay (500);
    std::cout << "\n\nPressione Enter para continuar..."<<std::endl;
    std::getline(std::cin, enter);
     clearScreen();
  Escrever("\033[1;34mVelho Gaspar\033[0m: Agora, pequeno ",vt); Escrever(name,vt); Escrever(", voce deve ir em direção ao Monte Denadoro fazer a travessia!\n",vt);
  Escrever("Tome bastante cuidado e siga o mapa certinho para não se perder no imenso verde da floresta!\n\n",vt);
    std::cout<<"\nPressione ENTER para abrir o mapa."<<std::endl;
    std::cin.get();
    clearScreen ();
  mapa (4);
    std::cout << "\nPressione Enter para fechar o mapa..."<<std::endl;
    std::cin.get();
    clearScreen();

//6ª Fase - o monte Denadoro e o Dragão Branco de Olhos azuis----------------------------------------------
   
    Escrever("Você partiu em uma longa caminhada para o Monte Denadoro\n",vt);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   \n", 1);
    Escrever("Você chegou em algumas montanhas, quer conferir se é realmente onde você deveria estar?\n1-Sim\n2-Não\n",vt);
    int g;
    std::cin>>g;
    if(g == 1){
      
      clearScreen();
      mapa (5);
      std::cout << "\nPressione Enter para fechar o mapa..."<<std::endl;
      std::cin.ignore();
      std::cin.get();
      clearScreen();
      Escrever("Você realmente está no Monte Denadoro!!!\n\n",vt);
    }else {
        Escrever("Tudo bem, mas está correndo o risco de estar no lugar errado!\n\n",vt);
    }
    Escrever("Durante a travessia, você começa a sentir tontura\n",vt);
    Escrever("Mas você se lembra que a Máscara de Balthazar, e utilizando ela a tontura passou!\n\n",vt);

    Escrever("No pico da montanha você avista o castelo, respira fundo e se sente um pouco aliviado de ter chegado até aqui\n",vt);
    Escrever("Você aproveita para relaxar e contemplar a vista\n",vt);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   \n", 1);
    std::cout<<"\nPressione ENTER para continuar."<<std::endl;
        std::cin.get();
        clearScreen ();
    Escrever("Após contemplar a vista, você volta a caminhada rumo ao castelo, e encontra um corpo de dois metros e meio intacto na neve congelante\n",vt);
    Escrever("Ao cutucar o cadaver, você percebe que, no bolso de jaqueta há uma carta. Após lê-la, não restam dúvidas, este homem não era nada menos que o grande \033[1;34mSábio Balthazar\033[0m que acabou morrendo enquanto fazia a travessia!\n\nPress [F] to pay respect\n",vt);
    int amul;
    char F;
    std::string ultimate = "Nada"; //caso o player não preste respeito ao grande sabio ele só nn ganha ultimate hehehehe
    std::cin>>F;
    if(F == 'F'||F == 'f'){
        amul= true;
        Escrever("Ao prestar respeito ao grande \033[1;34mSábio Balthazar\033[0m, o seu fantasma apareceu em sua frente e te deu o seu amuleto!\nO poder dele corre em suas veias\nÉ tanto poder que não tem como explicar!!!\n",1);
        p1.R_vida += 100;
        p1.R_def_f += 10;
        p1.R_def_m += 10;
        vidaMax = p1.R_vida;
        if(raça == 1) //Humano
            ultimate = "\033[1;34mFURIA DO CAOS\033[0m";
        else if(raça == 2) //Vampiro
            ultimate = "\033[1;31mCONVERGÊNCIA DE SANGUE!!!\033[0m";
        else if(raça == 3) //Elfo
            ultimate = "\033[1;32mPRECISÃO CELESTIAL!!!\033[0m";
        else if(raça == 4) //Orc
            ultimate = "\033[1;33mORCQUESRTA DA DOR!!!\033[0m";
        else if(raça == 5) //Anão
            ultimate = "\033[1;36mFORJA VULCANICA\033[0m";
        else 
            ultimate = "\033[1;34mFURIA DO CAOS\033[0m";


        Escrever("Você aprendeu: ",1); Escrever(ultimate,1);
        Escrever("\nEstes são os seus atributos atualizados:\n\n", vt);
      if(raça == 1)
        homem(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 2) 
        vampiro(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 3)
        elfo(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 4)
        orc(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else if(raça == 5) 
         anao(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);
      else 
        homem(name, p1.R_vida, p1.R_atk_f, p1.R_atk_m, p1.R_def_f, p1.R_def_m, p1.R_crtRate);

        std::cout << "\n\nPressione Enter para continuar..."<<std::endl;
        std::cin.ignore();
        std::getline(std::cin, enter);
        clearScreen();  
        Escrever("\033[1;34mSábio Balthazar\033[0m: Tome cuidado com os guardas mágicos do castelo, eles são imunes a magia!!!\n",vt);
    } else{
        amul = false;
        Escrever("O espírito de Balthazar se enfureceu com seu comportamento desrespeitoso!!!\n\n", vt);
        batalha(vidaMax, vamp, 300, 50, 50, 40, 40, 0.25, 0.0, "\033[1;34mSábio Balthazar\033[0m", vt);
    }
    localizacao = 6;
     std::cout<<"\nPressione ENTER para continuar."<<std::endl;
     clearScreen ();
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   \n", 1);
    delay (1000);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   ", 1);
    delay (1000);
    Escrever (".   \n", 1);
    delay (1000);
      std::cout<<"\nPressione ENTER para abrir o mapa."<<std::endl;
        mapa(6);
      std::cout<<"\nPressione ENTER para fechar o mapa"<<std::endl;
      std::cin.get();
      clearScreen();
    Escrever("Finalmente você chegou no castelo!\nVocê entra pelo calabouço e tenta achar onde a princesa está presa!\n",vt);
    g=0;
    while(g!=3){
        clearScreen();
        Escrever("Para que lado você acha que está a princesa?\n1-Salão à esquerda\n2-cela à direita\n3-Corredor adainte\n",vt);
        std::cin>>g;
        if(g==1){
            Escrever("O salão à esquerda é apenas um refeirório e você encontra um guarda do castelo!!!",vt);
            batalha(vidaMax, vamp, 10, 50, 50, 5, 1000, 0.25, 0.0, "Guarda Esqueleto", vt);
        }
        if(g==2){
            Escrever("A cela à direita está vazia e você foi avistado pelo guarda!!",vt);
            batalha(vidaMax, vamp, 10, 50, 50, 5, 1000, 0.25, 0.0, "Guarda Esqueleto", vt);
        }
    }
    Escrever("\nVocê segue o corredor até chegar na torre noroeste do castelo. . .\nVocê começa a subir até o quarto mais alto da torre mais alta, da região mais alta da mais alta terra. . .\n",vt);
    Escrever (".   \n", 1);
    delay (800);
    Escrever (".   ", 1);
    delay (800);
    Escrever (".   ", 1);
    delay (800);
    Escrever (".   \n", 1);
    delay (800);
    Escrever (".   ", 1);
    delay (800);
    Escrever (".   ", 1);
    delay (800);
    Escrever (".   ", 1);
    delay (800);
    Escrever (".   \n", 1);
    delay (800);
    Escrever("Após um longo tempo subindo e quase vomitando no 53º andar, você chega no 77º andar, onde se encontra a princesa\n",vt);
    std::cout<<"\nPressione ENTER para continuar."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();
    Escrever("\033[1;35mPrincesa\033[0m: Q-Quem está ai?? Se forem vocês guardas, eu já disse que não vou me casar com esse lagarto albino imundo!!!\n",vt);
    Escrever(name, vt); Escrever(": Erghh. . . Calma princesa, eu.. e-u.... vim pra te salvar!!(Ela é bem mais bonita do que você imaginara)\n", vt);
    Escrever("\033[1;35mPrincesa\033[0m: Você veio para me salvar?? Que romântico você!! Quando que vamos nos casar?\n",vt);
    Escrever(name, vt); Escrever(": Erghh. . . CASAR? Eu acabei de te conhecer senhorita!!\n", vt);
    Escrever("\033[1;35mPrincesa\033[0m: Eu sei, mas é que você subiu nessa torre de 77 andares, matou o dragão e deve ter tido outros desafios para salvar alguém que não conhece!\n",vt);
    Escrever("\033[1;35mPrincesa\033[0m: Se isso não é uma imensa prova de amor, não sei oque é! Eu imagino o que você faria se me conhecesse <3 <3\n",vt);
    Escrever(name, vt); Escrever(": Dragão? Que Dragão? Eu não matei dragão nenhum!!!!!\n", vt);
    Escrever("\033[1;35mPrincesa\033[0m: É O QUÊ? NÃO MATOU O DRAGÃO !  !!! ! ! !  !!! ! ! ! ! !\n",vt);
    Escrever ("!   ", 1);
    delay (1000);
    Escrever ("!   ", 1);
    delay (1000);
    Escrever ("!   \n", 1);
    delay (1000);
    Escrever("Vocês escutam um barulho ensurdeçedor e a torre começa a desabar!!\nVocê pega a princesa no colo e corre com ela em seus braços até a saida do castelo\n",vt);
    Escrever("Chegando na saída, você é cercado de guardas e o Dragão barra a saída!!\n",vt);
    std::cout<<"\nPressione ENTER para continuar."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

    batalhadrag(amul, vidaMax, vamp, dif, vt, name, ultimate);

    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);

    clearScreen();
    std :: cout << "\033[31;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay(500); clearScreen();
    std :: cout << "\033[32;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay(500); clearScreen();
    std :: cout << "\033[33;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay (500); clearScreen();
    std :: cout << "\033[34;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay (500); clearScreen();
    std :: cout << "\033[31;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay(500); clearScreen();
    std :: cout << "\033[32;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay(500); clearScreen();
    std :: cout << "\033[33;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay (500); clearScreen();
    std :: cout << "\033[34;1mVocê derrotou o DRAGÃO CORNELIUS!\033[0m\n";
    delay (500);

    std::cout<<"\nPressione ENTER para continuar."<<std::endl;
    std::getline(std::cin, enter);
    clearScreen();

    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);

    Escrever("\033[1;35mPrincesa\033[0m: Vo-Você derrotou o Dragão! Meu herói!!! Mal posso esperar para me casar com você!\n",vt);
    std::cout<<name<<": "; delay (500); Escrever ("  .   ", 1); delay (500); Escrever (".   ", 1); delay (500); Escrever (".   ", 1);
    Escrever("\033[1;35mPrincesa\033[0m: Agora vamos! Me leve de volta para casa, meu herói!\n",vt);
    Escrever("\nQuando vocês saem juntos do castelo escutam um barulho atras de vocês", vt);
    Escrever("\nSão as torres que agora estão lentamente desmoronando.", vt);
    Escrever("\nParece que a energia vital do dragão sustentava esse antigo csatelo de pé, sem ela, a construção perecerá.", vt);
    Escrever("\n\nEntão vocês entraram novamente na jornada de volta para casa.", vt);
      std::cout<<"\nPressione ENTER para continuar."<<std::endl;
      std::getline(std::cin, enter);
      clearScreen();
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);
    Escrever (".   ", 1); delay (500);


//7ª Fase - EPÍLOGO---------------------------------------------------------------------

Escrever ("Chegando a Hoenn Land, você e a princesa se encontram com o rei.\nEste, muito grato por você ter salvado sua filha amada",vt);
Escrever (" oferece a mão da filha em casamento a você, que, perdido de amores por ela, aceita de prontidão.",vt);
Escrever ("\nA princesa, que se encantou por tamanha bravura, alegra-se em saber que há de se casar com alguém tão incrível.", vt);
Escrever ("\nTodos do reino também ficam felizes em saber que o futuro rei deles havia enfretado uma criatura tão terrível para salvar sua amada.",vt);
    Escrever ("\nPressione ENTER para continuar", vt);
    std::cin.get();
    clearScreen();
Escrever ("Passado alguns dias, uma mesa farta esperava por todos os convidados no palácio real para o grande dia do casamento.", vt);
Escrever ("\nPadre Fábio de Melo, grande sacerdote da região foi chamado para presidir a celebração na Catedral local.\n",vt);

Escrever ("\33[1;34mPadre Fábio de Melo: \33[0mQueridos irmãos e irmãs do Reino, estamos aqui hoje reunidos para celebrar a união deste casal, a princesa e ", vt);
Escrever (name, vt); Escrever (".\nPrincesa, você aceita receber ", vt); Escrever (name, vt);
Escrever (" como seu legítimo esposo, na saúde ou na doença, na riqueza ou na pobreza até que a morte os separe?\n", vt); Escrever ("\33[1;31mPrincesa: \33[0mAceito.\n", vt);
Escrever ("\33[1;34mPadre Fábio de Melo: \33[0m", vt); Escrever (name, vt); Escrever (", você aceita recebar a princesa como sua legítima esposa na saúde ou na doença, na riqueza ou na pobreza até que a morte os separe?\n", vt);
Escrever (name, vt); Escrever (": Aceito.\n", vt);
Escrever ("\33[1;34mPadre Fábio de Melo: \33[0mO que Deus uniu, que o homem não separe.\nPode beijar a noiva.", vt);
    Escrever ("\nPressione ENTER para continuar", vt);
    std::cin.get();
    clearScreen();

Escrever ("Depois do casamento você e a princesa viveram felizes para sempre.", vt);
    Escrever ("\nPressione ENTER para continuar", vt);
    std::cin.get();
    clearScreen();
    creditos();
  Escrever ("\nPressione ENTER para continuar", vt);
    std::cin.get();
    clearScreen();
  Escrever ("\t\t\tO FIM!\n",vt);
    delay (3000);
  return 0;
}
