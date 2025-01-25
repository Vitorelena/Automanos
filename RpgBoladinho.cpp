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

void Escrever(const std::string texto) {
    
    for (char c : texto) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

}

void Menu() {
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
               Escrever("\033[0mEscolha uma opção: ");
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
  int raça;
  int vida = 0, atf = 0, atm = 0, resf = 0 , resm =0;
  do{
    Menu();
    std::cin >> seletor;
    
    if(seletor == 1){
      clearScreen();
      Escrever("\nBom, para começar...");
      
      Escrever("\nDigite seu nome: ");
      std::cin >> name;
      clearScreen();
      Escrever("\nSeja bem-vindo, "); Escrever(name); Escrever("!");
      Escrever("\nO que você é?\n");
        std::cout << " 1-\33[1;34m" << "Humano\n";
        std::cout << "\33[0m 2-"<< "\33[1;31m" << "Vampiro\n";
        std::cout << "\33[0m 3-"<< "\33[1;32m" << "Elfo\n";
        std::cout << "\33[0m 4-"<< "\33[1;33m" << "Orc\n";
        std::cout << "\33[0m 5-"<< "\33[1;36m" << "Anão\n \33[0m";
        std::cin >> raça;

    } else if(seletor == 2){
        seletor = 0;
    } else if(seletor == 3){

    } else{
      seletor = 0;
    }
   } while(seletor == 0);
    



    return 0;
}