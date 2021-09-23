#include <iostream>
#include "functions.cpp"
#include <vector>
#include <algorithm>
using namespace std;

const string POSIBLE_LETTERS = "abcdefghijklmnñopqrstuvwxyzáéíóú";
int live_count = 5;
int racha = 0;
bool rematch = true;
int main()
{
    string word_to_guess = get_a_word(POSIBLE_LETTERS);

    string letters_shown = first_and_last_letters(word_to_guess);

    string word_with_holes = format_word(letters_shown, word_to_guess);

    greet_player(word_with_holes);

    while(live_count>0 && word_with_holes.find("_")!=-1){
        string letra;
        cout << "\nElige una letra: " << endl;
        cin >> letra;

        if(letra=="hint")
        {
            cout << word_to_guess << endl;
        }

        if(letra.size()>1)
        {
            cout << "Elige una sola letra: " << endl;
            letra = tolower(letra[0]);
        } 
        else if(POSIBLE_LETTERS.find(letra) == -1)
        {
             cout << "Elige una letra válida: " << endl;
        }
        else if (letters_shown.find(letra) != -1){
            cout << "Esa letra ya esta descubierta!" << endl;
        }
        else if ( word_to_guess.find(letra) != -1 || word_to_guess.find(tilde(letra)) != -1 )
        {
           letters_shown += letra;
           string vowels = "áéíóúaeiou";
           if(vowels.find(letra) != -1)
           {
               letters_shown += tilde(letra);
           }
           word_with_holes = format_word(letters_shown, word_to_guess);
           cout << "CORRECTO!\n" << endl;
           if(word_with_holes.find("_") > 1)
           {
                cout << word_with_holes << endl; 
           }
        }
        else
        {
            live_count--;
            cout << "\nLetra incorrecta :(" << endl;
            if(live_count > 0)
            {
                string msg = "Te quedan ";
                msg+= live_count;
                msg+= " intentos";
                cout << msg << endl; 
            }
        }

    }
    if(live_count==0)
    {   
        string msg = "\nPerdiste, la palabra era: ";
        msg+= word_to_guess;
        msg+= "\nVer significado -> https://dle.rae.es/";
        msg+= word_to_guess;
        cout << msg << endl;
    }
    else
    {
        string msg = "##########\n Ganaste! \n##########\n\n La palabra era: ";
        msg+= word_to_guess;
        msg+= "\nVer significado -> https://dle.rae.es/";
        msg+= word_to_guess;
        cout << msg << endl;
        racha++;
        if(racha==1)
        {
        string msg = "GANASTE ";
        msg+= racha;
        msg+= " JUEGO!\n";
        cout << msg << endl;
        }
        else
        {
        string msg = "GANASTE ";
        msg+= racha;
        msg+= " JUEGOS CONSECUTIVOS!!\n";
        cout << msg << endl;
        }
       /*  rematch = play_again(); */
    }
    while(rematch == true)
    {
        main();
    }
}

