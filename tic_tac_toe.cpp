#include <iostream>
#include <ctime>
#define endl '\n'

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void player2Move(char *spaces, char player2);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main() 
{
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ',  ' ', ' ', ' '};
    char player = 'X', computer = 'O', player2 = 'O';
    int giocatori;
    std::cout << "How many players are playing (1-2)? ";
    std::cin >> giocatori; 
    bool running = true;

    drawBoard(spaces);
    while(running)
    {
        if(giocatori == 1)
        {
            playerMove(spaces, player);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer))
            {
                running = false;
                break;
            }
            else if(checkTie(spaces))
            {
                running = false;
                break;
            }

            computerMove(spaces, computer);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer))
            {
                running = false;
                break;
            }
            else if(checkTie(spaces))
            {
                running = false;
                break;
            }
        }

        else if(giocatori == 2)
        {
            playerMove(spaces, player);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer))
            {
                running = false;
                break;
            }
            else if(checkTie(spaces))
            {
                running = false;
                break;
            }

            player2Move(spaces, player2);
            drawBoard(spaces);
            if(checkWinner(spaces, player, computer))
            {
                running = false;
                break;
            }
            else if(checkTie(spaces))
            {
                running = false;
                break;
            }
        }
    }
}

void drawBoard(char *spaces)
{
    std::cout << endl;
    std::cout << "     |     |     " << endl;
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << endl;
    std::cout << "_____|_____|_____" << endl;
    std::cout << "     |     |     " << endl;
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << endl;
    std::cout << "_____|_____|_____" << endl;
    std::cout << "     |     |     " << endl;
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << endl;
    std::cout << "     |     |     " << endl;
    std::cout << endl;
}
void playerMove(char *spaces, char player)
{
    int number;
    do
    {
        std::cout << "Inserisci la posizione (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ')
        {
            spaces[number] = player;
            break;
        }
            
    } while (!number > 0 || !number < 8);
    
}
void player2Move(char *spaces, char player2)
{
    int number;
    do
    {
        std::cout << "Inserisci la posizione (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' ')
        {
            spaces[number] = player2;
            break;
        }
            
    } while (!number > 0 || !number < 8);
    
}
void computerMove(char *spaces, char computer)
{
    int number;
    srand(time(0));

    while(true)
    {
        number = rand() % 9;
        if(spaces[number] == ' ')
        {
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer)
{
    //Controllo righe
    if((spaces[0] != ' ') && (spaces[0] == spaces[1]) && (spaces[1] == spaces[2]))
        spaces[0] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";
    else if((spaces[3] != ' ') && (spaces[3] == spaces[4]) && (spaces[4] == spaces[5]))
        spaces[3] == player ? std::cout << "Player Won!": std::cout << "Player Lose!"; 
    else if((spaces[6] != ' ') && (spaces[6] == spaces[7]) && (spaces[7] == spaces[8]))
        spaces[6] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";   

    //Controllo colonne
    else if((spaces[0] != ' ') && (spaces[0] == spaces[3]) && (spaces[3] == spaces[6]))
        spaces[0] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";  
    else if((spaces[1] != ' ') && (spaces[1] == spaces[4]) && (spaces[4] == spaces[7]))
        spaces[1] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";  
    else if((spaces[2] != ' ') && (spaces[2] == spaces[5]) && (spaces[5] == spaces[8]))
        spaces[2] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";

    //Prima diagonale
    else if((spaces[0] != ' ') && (spaces[0] == spaces[4]) && (spaces[4] == spaces[8]))
        spaces[0] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";

    //Seconda diagonale
    else if((spaces[2] != ' ') && (spaces[2] == spaces[4]) && (spaces[4] == spaces[6]))
        spaces[2] == player ? std::cout << "Player Won!": std::cout << "Player Lose!";
    
    else
        return false;
    return true;
}
bool checkTie(char *spaces)
{
    for (int i = 0; i < 9; i++)
        if(spaces[i] == ' ')
            return false;
    std::cout << "It's a tie!" << endl;
    return true;
}