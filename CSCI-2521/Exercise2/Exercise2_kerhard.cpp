/**
 * @file Exercise2_kerhard.cpp
 * @author Kate Erhard
 * @date 2026-04-20
 * @brief This program allows the user to enter a sentence and translates
 * each letter into Morse Code.
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/**
 * @class MorseTranslator
 * @brief Translates letters into Morse Code.
 */
class MorseTranslator
{
public:

    /**
     * @brief Returns the Morse Code translation of a letter.
     * @param letter - The letter to translate.
     * @return Representation of Morse Code as a string.
     */
    string getMorse(char letter)
    {
        switch (letter)
        {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        default: return "";
        }
    }
};

/**
 * @class TranslationApp
 * @brief Handles user input and displaying the translation.
 */
class TranslationApp
{
private:
    MorseTranslator translator;

public:

    /**
     * @brief Runs the translation program loop.
     */
    void run()
    {
        string sentence;

        while (true)
        {
            cout << "Enter a sentence (max 50 characters): ";
            getline(cin, sentence);

            if (sentence.length() > 50)
            {
                cout << "Sorry, sentence is too long.\n";
                continue;
            }

            translateSentence(sentence);

            char again;
            cout << "Translate another sentence? (y/n): ";
            cin >> again;
            cin.ignore();

            if (tolower(again) != 'y')
                break;
        }
    }

    /**
     * @brief Translates the entire sentence to Morse Code.
     * @param sentence - The sentence to translate.
     */
    void translateSentence(string sentence)
    {
        for (char c : sentence)
        {
            if (isalpha(c))
            {
                c = tolower(c);
                cout << translator.getMorse(c) << " ";
            }
        }

        cout << endl;
    }
};

/**
 * @brief Main function coordinating the program flow.
 * @return int
 */
int main()
{
    TranslationApp app;
    app.run();

    return 0;
}