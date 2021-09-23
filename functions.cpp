#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> retrieve_dict_page(char start_letter)
{
    vector<string> page;
    string path = "diccionario/palabras_";
    path += start_letter;
    path += ".txt";
    ifstream file(path);
    string word;
    while (getline(file, word))
    {
        page.push_back(word);
    }
    return page;
}
string get_random_word_from(vector<string> page)
{
    const int MIN_LENGTH = 6;
    srand((unsigned)time(0));
    int random = rand() % page.size();
    string word = page[random];
    return word;
}
string get_a_word(string posible_letters)
{
    srand((unsigned)time(0));
    int random = rand() % 26;
    char start_letter = posible_letters[random];
    vector<string> dict_page = retrieve_dict_page(start_letter);
    string word = get_random_word_from(dict_page);
    return word;
}

string first_and_last_letters(string word)
{
    string letters;
    letters+=word[0];
    letters+=word[word.size() - 1];
    return letters;
}

string format_word(string letters, string word)
{
    string formatted_word;
    for (int w = 0; w < word.size(); w++)
    {
        bool found = false;
        for (int l = 0; l < letters.size(); l++)
        {
            if (word[w] == letters[l])
            {
                formatted_word += word[w];
            }
        }
        if (found == false && w + 1 < word.length())
        {
            formatted_word += "_";
        }
    }
    return formatted_word;
}

void greet_player(string word)
{
    cout << "\nJUEGO: EL AHORACADO" << endl;
    cout << "Adivina la sigueinte palabra, puedes equivocarte 5 veces." << endl;
    cout << "Presiona Ctrl+C para salir\n" << endl;
    cout << "La palabra a adivinar es: " << endl;
    cout << word << endl;
}

string tilde(string letra)
{   
    string vowels_no_tilde = "aeiou";
    string vowels_tilde = "áéíóú";
    if(vowels_no_tilde.find(letra) == -1 && vowels_tilde.find(letra) == -1)
    {
        return letra;
    }
    string inverse_vowel;
    int find_in_no_tilde = vowels_no_tilde.find(letra);
    int find_in_tilde = vowels_tilde.find(letra);
    if(find_in_no_tilde != -1)
    {
        inverse_vowel = vowels_tilde[find_in_no_tilde];
    }
    if(find_in_tilde != -1)
    {
        inverse_vowel = vowels_no_tilde[find_in_tilde];
    }
    return inverse_vowel;
}
string input(string msg)
{

}
bool yes_check(string input){
    int x;
}
bool play_again()
{
    int x;
/*     string replay = input("\nJugar de nuevo? (s/n)");
    replay = replay.strip();
    return yes_check(replay, &play_again); */
}