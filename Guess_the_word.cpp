#include <iostream>
#include <string>
#include <conio.h>  

int main() {
    std::string Answers[11] = {"car","apple","mango","grape","chair","sharp",
                               "radio","stain","force","cargo","table"};

    std::string word, check;
    int points = 0;

    std::cout << "Welcome to Guess the Words!\n";
    std::cout << "Press ESC anytime to quit.\n";

    for (int j = 1; j <= 11; j++) {
        int life = 3;
        std::string ans = Answers[j - 1];

        std::cout << "\n----- Level " << j << " -----\n";
        std::cout << "Guess the word:";

        for (int i = 0; i < ans.length(); i++)
            std::cout << " _";

        std::cout << "\n";

        while (life > 0) {
            word = "";
            char ch,hc;

            std::cout << "Enter your guess: ";

            while (true) {
                ch = getch();  

                if (ch == 27) {  
                    std::cout << "\nGame Exited.\n";
                    std::cout << "Your Score: " << points << "\n";
                    return 0;
                }

                if (ch == 13)  
                    break;

                if (ch == 8) {   // Backspace
                     if (!word.empty()) {
                             word.pop_back();
                             std::cout << "\b \b";
                                        }
                            }
                else {
                    word += ch;
                    std::cout << ch;
                }
            }

            std::cout << "\n";

            if (word.length() != ans.length()) {
                std::cout << "Sorry, that's not a " << ans.length()
                          << "-letter word.\n";
                life--;
                std::cout << "Lives left: " << life << "\n";
                if (life == 0) {
                std::cout << "\n----- YOU'RE OUT -----\n";
                std::cout << "~~~~~Correct word was: " << ans << "~~~~~\n";
                std::cout << "Your Score: " << points << "\n";
                return 0;
            }
                continue;
            }

            if (word == ans) {
                std::cout << "-----Congratulations! You guessed the word!-----\n";
                if(life == 3)
                    points += 3;
                else if(life == 2)
                    points += 2;
                else
                points += 1;
                hc=getch();
                if(hc==27){
                    std::cout << "\n-----Game Exited-----\n";
                    std::cout << "Your Score: " << points << "\n";
                    return 0;
                }
                else
                break;
            }

            life--;
            std::cout << "Lives left: " << life << "\n";

            if (life == 0) {
                std::cout << "\n----- YOU'RE OUT -----\n";
                std::cout << "~~~~~Correct word was: " << ans << "~~~~~\n";
                std::cout << "Your Score: " << points << "\n";
                return 0;
            }

            check = "";
            for (int i = 0; i < ans.length(); i++) {
                if (word[i] == ans[i])
                    check += word[i];
                else
                    check += "_";
            }

            for (char x : check)
                std::cout << x << " ";

            std::cout << "\n";
        }
    }

    std::cout << "\n-----You completed all levels!-----\n:::::We Bow Before Your Vocabulary!:::::\n";
    std::cout << "Final Score: " << points << "\n";

    return 0;
}