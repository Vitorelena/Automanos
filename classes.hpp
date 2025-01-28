#include <iostream>
#include <string>

using namespace std;

class Rassa{ //Cria classe de Raça
    public:
        int R_atk_f;
        int R_atk_m;
        int R_def_f;
        int R_def_m;
        int R_vida;
        float R_crtRate;
};

class Humano:public Rassa{
    public:
        Humano(){
            R_atk_f = 30;
            R_atk_m = 20;
            R_def_f = 10;
            R_def_m = 10;
            R_vida = 100;
            R_crtRate = 0.25;
        }
};

class Vampiro:public Rassa{
    public: 
        float vampirismo; //roubo de vida;
        Vampiro(){
            R_atk_f = 10;
            R_atk_m = 40;
            R_def_f = 5;
            R_def_m = 20;
            R_vida = 95;
            R_crtRate = 0.25;
            vampirismo = 0.2;   
        }

};

class Elfo:public Rassa{
    public:
        Elfo(){
            R_atk_f = 40;
            R_atk_m = 35;
            R_def_f = 5;
            R_def_m = 10;
            R_vida = 80;
            R_crtRate = 0.50;
        }
};


class Classe{ //Cria classe de Classe
    public:
        int C_atk_f;
        int C_atk_m;
        int C_def_f;
        int C_def_m;
        int C_vida;
        float C_crtRate;
};

class Arma{ //Cria classe de Arma
    public:
        int A_atk_f;
        int A_atk_m;
        int A_def_f;
        int A_def_m;
};

class Espada:public Arma{
    public:
        Espada(){
            A_atk_f = 25;
            A_atk_m = 25;
            A_def_f = 5;
            A_def_m = 5;
        }
};

class Arco:public Arma{
    public:
        Arco(){
            A_atk_f = 40;
            A_atk_m = 20;
            A_def_f = 0;
            A_def_m = 0;
        }
};

class Escudo:public Arma{
    public:
        Escudo(){
            A_atk_f = 5;
            A_atk_m = 0;
            A_def_f = 30;
            A_def_m = 25;
        }
};








