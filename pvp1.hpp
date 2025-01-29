#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED
#include "classes.hpp"
#include "funcoes.hpp"
#include <thread> 
#include <chrono> 
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <csignal>


using namespace std;
int randomizer(int limite){ // Serve para gera um numero aleatório
    std::srand(std::time(nullptr));
    return rand() % limite;
}

int dano(int atq, int res, float crit){ // Calcula o dano causado, com a diminuição dele a partir da resistencia do inimigo e o aumento conforme a chance de critico
    float floatatq = (float)atq;
    float floatres = (float)res;
    int dano1;
    float floatdano = floatatq - (floatres/2);
    if(floatdano <= 0)
        floatdano = 1;
    float a = crit * 100;
    int b = randomizer(100);
    float floatb = (float)b;
    if(a >= floatb){
            floatdano = floatdano * 1.5;
            int dano = (int)floatdano;
            dano1 = dano;
            Escrever ("Ataque crítico.");
            std::this_thread::sleep_for(std::chrono::seconds(1));
            clearScreen();
        return dano1;
    } else{
        int dano = (int)floatdano;
        dano1 = dano;
        return dano1;
    }   
}

int batalha (int vida_m, int atf_m, int atm_m, int resf_m, int resm_m, float crit_m, float vamp_m, std::string nome, int vt){
//a variável "vida_max" tem que ser criada no arquivo pricipal logo quando o personagem é escolhido
//para registrar a vida máxima do personagem
int vida_max_m;
vida_max_m = vida_m;
int l;
int j;
int y;

Escrever ("Prepare-se para lutar contra o ", vt); Escrever (nome,vt); Escrever (".",vt);
while (j != 1){
Escrever(".\n O que você deseja fazer?",vt);
std::cout << endl << " 1-\33[1;34m" << "Usar o ataque mágico\n";
std::cout << "\33[0m 2-"<< "\33[1;31m" << "Usar o ataque físico\n";
std::cout << "\33[0m 3-"<< "\33[1;32m" << "Fugir como um covarde\n \33[0m";
std :: cin >> y;

if (y == 1){
    l = dano (p1.R_atk_m, resm_m, p1.R_crtRate); //ataque o personagem
    p1.R_vida += p1.R_vamp*l;
        if (R_vida > vida_max){
            R_vida = vida_max;
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
        Escrever ("O ",vt); Escrever (nome,vt); Escrever ("morreu.",vt);
        std::this_thread::sleep_for(std::chrono::seconds(2)); 
        clearScreen ();
        Escrever ("Você atacou e causou ",vt);
        std :: cout << l;
        Escrever (" de dano.\nAgora você tem ",vt);
        std :: cout << p1.R_vida;
        Escrever (" de vida e o ",vt); Escrever (nome,vt); Escrever(" tem ",vt);
        std :: cout << vida_m << ".\n";
        std::this_thread::sleep_for(std::chrono::seconds(3)); 
        clearScreen();
        j = 1;
        return j;
    }

    Escrever ("Você atacou e causou ",vt);
    std :: cout << l;
    Escrever (" de dano.\nAgora você tem ",vt);
    std :: cout << p1.R_vida;
    Escrever (" de vida e o "); Escrever (nome); Escrever(" tem ",vt);
    std :: cout << vida_m << ".\n";
    std::this_thread::sleep_for(std::chrono::seconds(3)); 
    clearScreen();

    
    int x;
    int v = randomizer(2); //ataque do monstro, essa linha calcula para o montro atacar com ataque físico ou mágico
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
    if (p1.R_vida <= 0){
    Escrever ("Você morreu.",vt);
    std::this_thread::sleep_for(std::chrono::seconds(2)); 
    exit (0);

    }

    Escrever ("O ",vt); Escrever (nome,vt); Escrever (" te atacou e causou ",vt);
    std :: cout << x; 
    Escrever (" de dano",vt);
    Escrever ("\nAgora você tem ",vt); 
    std :: cout << p1.R_vida;
     Escrever (" de vida e o ",vt); Escrever (nome,vt); Escrever (" tem ",vt);
     std :: cout << vida_m << ".\n";
      std::this_thread::sleep_for(std::chrono::seconds(3)); 
    clearScreen();
}
return j;
}
#endif
