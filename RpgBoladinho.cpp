#include <iostream>
#include <chrono>
#include <thread>


void clearScreen() {
   #ifdef _WIN32
       system("cls"); // Para Windows
   #else
       std::cout << "\033[2J\033[H"; // Para Linux/MacOS
   #endif
   }

void Escrever(const std::string texto, int vt) {
    
    for (char c : texto) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100/vt));
    }

}

void Menu(int vt) {
    std::cout << "\033[1;34m" // Cor azul para título
              << "===============================================================\n"
              << "                      \033[1;32mRPG dos Automanos\033[1;34m\n"
              << "===============================================================\n"
              << "\033[0m"; // Reset de cores
    std::cout << "\n\033[1;33m" // Cor amarela para opções
              <<           "  [1] \033[0mJogar\n"
              << "  \033[1;33m[2] \033[0mConfigurações\n"
              << "  \033[1;33m[3] \033[0mSair\n\n";
    std::cout << "\033[1;34m" // Cor azul para rodapé
              << "===============================================================\n";
               Escrever("\033[0mEscolha uma opção: ", vt);
}

void personagem(int &vida, int &atf, int &atm, int &resf, int &resm, int a){

  switch(a){
    case 1: // Humano
    vida += 100;
    atf += 30;
    atm += 20;
    resf += 10;
    resm += 7;
    break;
    case 2: // Vampiro
    vida += 130;
    atf += 10;
    atm += 40;
    resf += 7;
    resm += 20;
    break;
    case 3: // Elfo
    vida += 90;
    atf += 30;
    atm += 30;
    resf += 7;
    resm += 9;
    break;
    case 4: // Orc
    vida += 200;
    atf += 25;
    atm += 8;
    resf += 15;
    resm += 15;
    break;
    case 5: // Anão
    vida += 180;
    atf += 20;
    atm += 10;
    resf += 25;
    resm += 25;
    break;
    
  }
  
 
  
}

int main(){
  std::string name;
  int seletor = 0;
  int dif = 1; // Dificuldade do jogo
  int config = 0, vt = 1; // Vt é a velocidade do texto
  int raça;
  int vida = 0, atf = 0, atm = 0, resf = 0 , resm =0;
  do{
    Menu(vt);
    std::cin >> seletor;
    
    if(seletor == 1){
      clearScreen();
      Escrever("\nBom, para começar...",vt);
      
      Escrever("\nDigite seu nome: ",vt);
      std::cin >> name;
      clearScreen();
      Escrever("\nSeja bem-vindo, ",vt); Escrever(name,vt); Escrever("!",vt);
      Escrever("\nO que você é?\n",vt);
        std::cout << " 1-\33[1;34m" << "Humano\n";
        std::cout << "\33[0m 2-"<< "\33[1;31m" << "Vampiro\n";
        std::cout << "\33[0m 3-"<< "\33[1;32m" << "Elfo\n";
        std::cout << "\33[0m 4-"<< "\33[1;33m" << "Orc\n";
        std::cout << "\33[0m 5-"<< "\33[1;36m" << "Anão\n \33[0m";
        std::cin >> raça;

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

    } else{
      seletor = 0;
    }
   } while(seletor == 0);
    



    return 0;
}
