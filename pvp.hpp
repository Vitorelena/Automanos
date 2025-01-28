#include <iostream>
#include <cstdlib>
#include <ctime>

int randomizer(int limite){ // Serve para gera um numero aleatório
    std::srand(std::time(nullptr));
    return rand() % limite;
}

int dano(int atq, int res, float crit){ // Calcula o dano causado, com a diminuição dele a partir da resistencia do inimigo e o aumento conforme a chance de critico
    int dano = atq - (res/2);
    if(dano <= 0)
        dano = 1;
    float a = crit * 100;
    int b = randomizer(100);
    if(a >= b){
        if(dano % 2 == 1)
            dano = (dano + 1) *1.5;
        else if (dano % 2 == 0){
            dano = dano *1.5;
        }
        return dano;
    } else{
        return dano;
    }
    
    
}