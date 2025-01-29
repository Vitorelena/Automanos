#include <iostream>
#include <chrono>
#include <thread>
#include "classes.hpp"
#include "pvp1.hpp"
#include "funcoes.hpp"


int main(){
  std::string name;
  int seletor = 0;
  int dif = 1; // Dificuldade do jogo
  int config = 0, vt = 1; // Vt é a velocidade do texto
  float vamp = 0;
  int localizacao = 1;

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
      int raça, classe;
        std::cout << " 1-\033[1;34m" << "Humano\n";
        std::cout << "\033[0m 2-"<< "\033[1;31m" << "Vampiro\n";
        std::cout << "\033[0m 3-"<< "\033[1;32m" << "Elfo\n";
        std::cout << "\033[0m 4-"<< "\033[1;33m" << "Orc\n";
        std::cout << "\033[0m 5-"<< "\033[1;36m" << "Anão\n \033[0m";
          

      Humano H1; Vampiro V1; Elfo E1; Orc O1; Anao A1; //Instanciados objetos-base de raça  
      Cavaleiro Cv1; Arqueiro Ar1; Mago Mg1;           //Instanciados objetos-base de classe
      Espada Esp1; Arco arc1; Escudo esc1;             //Instanciados objetos-base de arma
      Player p1; //Instanciado objeto do jogador

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

      Escrever("Muito bem, ", vt); Escrever(name, vt); 
      Escrever(", a seguir, os seus atributos iniciais:\n", vt); 
      Escrever("(Lembre-se deles, pois serão muitos importantes durante a sua jornada!)\n\n", vt); 
           std::cout<<"Ataque Físico: "<<p1.R_atk_f<<std::endl
                   <<"Ataque Mágico: "<<p1.R_atk_m<<std::endl
                   <<"Defesa Física: "<<p1.R_def_f<<std::endl
                   <<"Defesa Mágica: "<<p1.R_def_m<<std::endl
                   <<"Pontos de Vida: "<<p1.R_vida<<std::endl
                   <<"Chance de Crítico: "<<p1.R_crtRate<<std::endl;

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
      mapa(localizacao);
      seletor = 0;
      std::cout<<"\nPressione qualquer tecla para voltar ao menu"<<std::endl;
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
    
  std::cout<<"FELIZ\n";


    return 0;
}
