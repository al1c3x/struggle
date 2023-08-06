#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

class characters {
public:
    string name;
    double hp = 0;
    double str = 0;
    double def = 0;
    double spatk = 0;
    double spdef = 0;
    double spd = 0 ;
    int cd = 0 ;
    int cd2 = 0 ;
    bool block = false;
    bool sblock = false;
    bool stun = false;
    int pdam = 0;
    string m1;
    string m2;
    string m3;
    string m4;

public:
    void set_value(string, double, double, double, double, double, double, string, string, string, string);
    void printstats();
    void printmoves();
   
       
    
};

void characters::set_value(string s1, double a, double b, double c, double d, double e, double f, string s2, string s3, string s4, string s5)
{
    name = s1;
    hp = a;
    str = b;
    def = c;
    spatk = d;
    spdef = e;
    spd = f;
    m1 = s2;
    m2 = s3;
    m3 = s4;
    m4 = s5;
}
void characters::printstats()
{
    cout << "Name : " << name << endl;
    cout << "HP : " << hp << endl;
    cout << "STR : " << str << endl;
    cout << "DEF : " << def << endl;
    cout << "SATK : " << spatk << endl;
    cout << "SDEF : " << spdef << endl;
    cout << "SPEED : " << spd << endl;
    cout << "S1 : " << m1 << endl;
    cout << "S2 : " << m2 << endl;
    cout << "S3 : " << m3 << endl;
    cout << "S4 : " << m4 << endl;

}
void characters::printmoves()
{
    cout << name << "'s Moves:" << endl;
    cout << "[1]" << m1 << endl;
    cout << "[2]" << m2 << endl;
    cout << "[3]" << m3 << endl;
    cout << "[4]" << m4 << endl;
    cout << "Input an action: ";

}

int pturn(double spd1, double spd2)
{
    if (spd1 > spd2)
    {
        return 1;
    }
        
    else if (spd1 == spd2) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
        
}

void damagecalc(int pmove, characters &n1, characters &n2, int popt)
{

    int proc;

    if (n1.stun == true)
    {
        n1.stun = false;
        popt = 0;
       
    }

    switch (popt)
    {
    case 1:
        n1.sblock = false;
        if (n1.cd == 1)
        {
            n1.def = n1.def - 20;
            n1.cd = 0;
        }

        switch (pmove)
        {
        case 1:
            n2.hp = n2.hp - (n1.str - n2.def);
            break;
        case 2:
            proc = rand() % 100 + 1;
            if (proc > 30)
            {
                n1.sblock = true;
            }
            break;
        case 3:
            n1.def = n1.def + 20;
            n1.cd = 1;
            break;
        case 4:
            n2.hp = n2.hp - (n1.spatk + n1.str - n2.spdef);
            break;
        }
        break;

    case 2:

        n1.block = false;
        n1.sblock = false;
        switch (pmove)
        {
        case 1:
            n2.hp = n2.hp - (n1.str - n2.def);;
            break;

        case 2:
            proc = rand() % 100 + 1;
            if (proc <= 80)
            {
                n1.block = true;
                n1.sblock = true;
            }
            break;

        case 3:
            n1.str = n1.str * 0.8;
            n2.hp = n2.hp - (n1.str - n2.def);
            n2.def = n2.def * 0.8;
            n2.spd = n2.spd * 0.8;
            n1.str = n1.str / 0.8;
            break;

        case 4:
            n1.hp = n1.hp * 0.7;
            n2.hp = n2.hp - ((n1.str*1.5) - n2.def);
        }
        break;

    case 3:
        n1.sblock = false;
        n1.block = false;
        if (n1.cd == 1)
        {
            pmove = 2;
        }
        switch (pmove)
        {

        case 1:
            n2.hp = n2.hp -(n1.str - n2.def);
            break;
        case 2:
            if (n1.cd == 0)
            {
                n1.cd = 1;
            }
            else
            {
                n2.hp = n2.hp - ((n1.str - n2.def)+ (n1.spatk - n2.spdef));
                n1.cd = 0;
            }
            break;
        case 3:
            proc = rand() % 100 + 1;
            if (proc <= 50)
            {
                n1.sblock = true;
                n1.block = true;
            }
            break;
        case 4:
            if (n1.cd2 == 0)
            {
                n1.sblock = true;
                n1.block = true;
            }

            n1.cd2 = 1;
            break;
        }
        break;
    case 4:
            switch (pmove)
            {
            case 1:
                n1.pdam = n1.pdam + 1;
                n2.hp = n2.hp - (20 *n1.pdam);
                break;
            case 2:
                n2.stun = true;
                break;
            case 3:
                n2.hp = n2.hp - (n1.spatk - n2.spdef);
                n1.hp = n1.hp + ((n1.spatk - n2.spdef) / 2);
                break;
            case 4:
                 n2.hp = n2.hp/ 2;
                 break;
            }

            break;
        }

    }






int main()
{
    characters player;
    characters npc;
    int pmove;
    int gameover = 0;
    int rounds = 1;
    int nmove;
    int i;
    int pick[3];
    int count = 1;
    int popt;
 

    cout << "[Struggle]" << endl;
    cout << "Character Selection Menu" << endl;
    cout << "[1] Hadiran" << endl;
    cout << "[2] Ulric" << endl;
    cout << "[3] Terrowin, The Wanderer" << endl;
    
    do 
    {
        cout << "Select Your Character: ";
        cin >> pmove;
        if (pmove > 3 || pmove <= 0)
        {
            cout << "Invalid Input!" << endl;
        }
    } while (pmove > 3 || pmove <= 0);
    pick[0] = pmove;
    pick[1] =  0;
    pick[2] =  0;
 
   
    while (gameover != 1)
    {
        if (pmove == 1)
        {
            player.set_value("Hadrian", 500, 80, 60, 100, 10, 80, "Slash", "Pendant of Gwendolyn", "Defend", "The Chosen One");

        }

        else if (pmove == 2)
        {
            player.set_value("Ulric", 400, 120, 10, 0, 10, 100, "Cross Slash", "Evade", "Cripple", "Envy");

        }

        else if (pmove == 3)
        {
            player.set_value("Terrowin, The Wanderer", 500, 80, 50, 80, 50, 50, "Spinning Strike", "Imbue", "Evade", "Will to Live");

        }



        if (rounds == 3)
        {
            npc.set_value("Tassilo, Sage of Dark Arts", 800, 10, 50, 100, 50, 50, "Black Plague", "Cursed Soil", "Parasite", "Judgement");
        }
        else
        {
            while (count == 1)
            {
                pick[rounds]= rand() % 3 + 1;
                for (i = 0; i < 2; i++)
                {
                    if (pick[rounds] != pick[i])
                    {
                        count = 0;
                        nmove = pick[rounds];
                    }
                }

            }
           

            if (nmove ==  1)
            {
                npc.set_value("Hadrian", 500, 80, 60, 100, 10, 80, "Slash", "Pendant of Gwendolyn", "Defend", "The Chosen One");
        
            }

            else if (nmove == 2)
            {
                npc.set_value("Ulric", 400, 120, 10, 0, 10, 100, "Cross Slash", "Evade", "Cripple", "Envy");
             
            }

            else if ( nmove == 3)
            {
                npc.set_value("Terrowin, The Wanderer", 500, 80, 50, 80, 50, 50, "Spinning Strike", "Imbue", "Evade", "Will to Live");
            }

        }


        while (player.hp > 0 && npc.hp > 0)
        {
            cout << player.name << endl;
            cout << " HP : " << player.hp << endl;
            cout << npc.name << endl;
            cout << " HP : " << npc.hp << endl << endl;

            if (pturn(player.spd, npc.spd) == 1)
            {
                player.printmoves();
                cin >> popt;
                damagecalc(popt, player, npc, pmove);

                srand(time(0));
                popt = rand() % 4 + 1;
                damagecalc(popt, npc, player, nmove);

            }

            else
            {
                srand(time(0));
                popt = rand() % 4 + 1;
                damagecalc(popt, npc, player, nmove);


                player.printmoves();
                cin >> popt;
                damagecalc(popt, player, npc, pmove);

            }

            system("CLS");

        }
    
        if (player.hp > 0) 
        {
            cout << "You have slain " << npc.name << "!" << endl;
            rounds = rounds + 1;;
        }
        else 
        { 
            gameover = 1;
        }

   
       
    }

    if (gameover == 1)
    {
        cout << "You have been defeated..... " << endl;
        cout << "Game Over" << endl;
    }
    else
    {
        cout << "Congratulation You Defeated All of The Enemy" << endl;
    }
   


}
