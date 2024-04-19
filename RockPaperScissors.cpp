#include <iostream>
#include <ctime>
#include <cstdlib>

char getUserChoice();
char getComputerChoice();
void showChoice(char choice);
void chooseWinner(char player, char computer, int& playerScore, int& computerScore);
void displayScore(int playerScore, int computerScore);
bool askReplay();

int main()
{
    int playerScore = 0;
    int computerScore = 0;

    do
    {
        while (playerScore < 3 && computerScore < 3)
        {
            char player = getUserChoice();
            std::cout << "Your choice: ";
            showChoice(player);

            char computer = getComputerChoice();
            std::cout << "Computer's choice: ";
            showChoice(computer);

            chooseWinner(player, computer, playerScore, computerScore);

            displayScore(playerScore, computerScore);
        }

        if (playerScore >= 3)
        {
            std::cout << "Congratulations! You win the game!\n";
        }
        else
        {
            std::cout << "Sorry, you lost the game.\n";
        }

        playerScore = 0;
        computerScore = 0;

    } while (askReplay());

    return 0;
}

char getUserChoice()
{
    char player;
    std::cout << "Rock-Paper-Scissors Game\n";
    do
    {
        std::cout << "*******************************\n";
        std::cout << "* Choose one of the following *\n";
        std::cout << "*******************************\n";
        std::cout << "'r' for rock\n";
        std::cout << "'p' for paper\n";
        std::cout << "'s' for scissors\n";
        std::cin >> player;
    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice()
{
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num)
    {
    case 1:
        return 'r';
    case 2:
        return 'p';
    case 3:
        return 's';
    }
}

void showChoice(char choice)
{
    switch (choice)
    {
    case 'r':
        std::cout << "Rock\n";
        break;
    case 'p':
        std::cout << "Paper\n";
        break;
    case 's':
        std::cout << "Scissors\n";
        break;
    }
}

void chooseWinner(char player, char computer, int& playerScore, int& computerScore)
{
    if ((player == 'r' && computer == 's') ||
        (player == 'p' && computer == 'r') ||
        (player == 's' && computer == 'p'))
    {
        std::cout << "You win\n";
        ++playerScore;
    }
    else if ((player == 'r' && computer == 'p') ||
             (player == 'p' && computer == 's') ||
             (player == 's' && computer == 'r'))
    {
        std::cout << "You lose\n";
        ++computerScore;
    }
    else
    {
        std::cout << "It's a tie\n";
    }
}

void displayScore(int playerScore, int computerScore)
{
    std::cout << "Player Score: " << playerScore << ", Computer Score: " << computerScore << "\n";
}



bool askReplay()
{
    char choice;
    while (true)
    {
        std::cout << "Do you want to play again? (Y/N): ";
        std::cin >> choice;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 'N' || choice == 'n')
        {
            system("clear"); // Clear terminal
            return false;
        }
        else if (choice == 'Y' || choice == 'y')
        {
            system("clear"); // Clear terminal
            return true;
        }
        else
        {
            std::cout << "Invalid input. Please enter 'Y' or 'N'.\n";
        }
    }
}
