#include <iostream>
#include <cstdlib>

void display(char box[3][3]);
bool filled(char cell);
bool check(char box[3][3], char player);
void play(char box[3][3], char player);

bool filled(char cell)
{
    return cell == 'X' || cell == 'O';
}

void display(char box[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            std::cout << box[i][j];
            if(j != 2) std::cout << " | ";
        }

        std::cout << std::endl;

        if(i != 2)
            std::cout << "---------\n";
    }
}

void play(char box[3][3], char player)
{
    char move;

    while(true)
    {
        std::cout << "Player " << player
                  << ", enter box number (1-9): ";

        std::cin >> move;

        if(move == 'q' || move == 'Q')
        {
            std::cout << "Thanks for playing!\n";
            exit(0);
        }

        switch(move)
        {
            case '1':
                if(!filled(box[0][0])) { box[0][0] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '2':
                if(!filled(box[0][1])) { box[0][1] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '3':
                if(!filled(box[0][2])) { box[0][2] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '4':
                if(!filled(box[1][0])) { box[1][0] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '5':
                if(!filled(box[1][1])) { box[1][1] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '6':
                if(!filled(box[1][2])) { box[1][2] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '7':
                if(!filled(box[2][0])) { box[2][0] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '8':
                if(!filled(box[2][1])) { box[2][1] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            case '9':
                if(!filled(box[2][2])) { box[2][2] = player; break; }
                else { std::cout << "Cell already filled!\n"; continue; }

            default:
                std::cout << "Invalid move!\n";
                continue;
        }

        break;
    }

    display(box);
}

bool check(char box[3][3], char player)
{
    if(box[0][0] == player && box[0][1] == player && box[0][2] == player) return true;
    if(box[1][0] == player && box[1][1] == player && box[1][2] == player) return true;
    if(box[2][0] == player && box[2][1] == player && box[2][2] == player) return true;

    if(box[0][0] == player && box[1][0] == player && box[2][0] == player) return true;
    if(box[0][1] == player && box[1][1] == player && box[2][1] == player) return true;
    if(box[0][2] == player && box[1][2] == player && box[2][2] == player) return true;

    if(box[0][0] == player && box[1][1] == player && box[2][2] == player) return true;
    if(box[0][2] == player && box[1][1] == player && box[2][0] == player) return true;

    return false;
}

int main()
{
    while(true)
    {
        char box[3][3] =
        {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
        };

        bool won = false;

        std::cout << "\nWelcome to Tic Tac Toe Game!\nPress 'Q' to quit at any time.\n";
        display(box);

        for(int i = 0; i < 4; i++)
        {
            play(box, 'X');

            if(check(box, 'X'))
            {
                std::cout << "Player X Wins!\n";
                won = true;
                break;
            }

            play(box, 'O');

            if(check(box, 'O'))
            {
                std::cout << "Player O Wins!\n";
                won = true;
                break;
            }
        }

        if(!won)
        {
            play(box, 'X');

            if(check(box, 'X'))
            {
                std::cout << "Player X Wins!\n";
                won = true;
            }
        }

        if(!won)
            std::cout << "It's a Draw!\n";

        char choice;

        std::cout << "Play again? (Y/N): ";
        std::cin >> choice;

        if(choice == 'n' || choice == 'N')
        {
            std::cout << "Thanks for playing!\n";
            break;
        }
    }

    return 0;
}