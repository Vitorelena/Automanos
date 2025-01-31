#include <iostream>
#include <chrono>
#include <thread>
#include "classes.hpp"
#include "funcoes1.hpp"

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
    }else{
      seletor = 0;
    }
  }while(seletor == 0);
    
    //batalha(vidaMax, 100, 50, 50, 10, 10, 0.25, 0.3,vamp,"Vampiro", vt);
 //_______________________________________________________________//
 //PRÓLOGO--------------------------------------------------------//
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

  //ENCONTRO COM OS TROLLS--------------------------------------------------------//
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

  //HOENN LAND E o VELHO MELCHIOR-----------------------------------------------------
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

//O ENIGMA DO ORÁCULO-------------------------------------------------------------

  

  





  return 0;
}
