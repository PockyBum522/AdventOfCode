#include <iostream>
#include <sstream>
#include <list>
#include "RawData/RawData.h"

int scoreForYourMove(char move);

int scoreIfOpponentUsesRock(char opponentMove, char yourMove);

int scoreIfOpponentUsesPaper(char opponentMove, char yourMove);

int scoreIfOpponentUsesScissors(char opponentMove, char yourMove);

using namespace std;

// A for Rock, B for Paper, and C for Scissors
//
// Second column is what you should play in response:
// X for Rock, Y for Paper, and Z for Scissors.

// The score for a single round is the score for the shape you selected
// (1 for Rock, 2 for Paper, and 3 for Scissors)
//
// plus the score for the outcome of the round
// (0 if you lost, 3 if the round was a draw, and 6 if you won).

// First Column:
//     A - Rock
//     B - Paper
//     C - Scissors

// Second Column:
//     X - Rock - 1
//     Y - Paper - 2
//     Z - Scissors - 3

// Scoring:
//    0 - If you lose
//    3 - If a draw
//    6 - If you win

int main()
{
    string line;
    istringstream f(RawData::INPUT_DATA_RAW);

    int scoreTotal = 0;

    while (getline(f, line))
    {
        char opponentMove = line[0];
        char yourMove = line[2];

        scoreTotal += scoreIfOpponentUsesRock(opponentMove, yourMove);
        scoreTotal += scoreIfOpponentUsesPaper(opponentMove, yourMove);
        scoreTotal += scoreIfOpponentUsesScissors(opponentMove, yourMove);

        scoreTotal += scoreForYourMove(yourMove);
    }

    cout << "Total score: " << scoreTotal << endl;

    return 0;
}

int scoreIfOpponentUsesRock(char opponentMove, char yourMove)
{
    if (opponentMove == 'A')
    {
        cout << "Opponent played rock vs. ";

        if (yourMove == 'X') {
            cout << "your rock. ";
            cout << "It's a draw!" << endl;

            return 3;
        }

        if (yourMove == 'Y')
        {
            cout << "your paper. ";
            cout << "You win!" << endl;

            return 6;
        }

        if (yourMove == 'Z')
        {
            cout << "your scissors. ";
            cout << "You lose!" << endl;

            return 0;
        }
    }

    return 0;
}

int scoreIfOpponentUsesPaper(char opponentMove, char yourMove)
{
    if (opponentMove == 'B')
    {
        cout << "Opponent played paper vs. ";

        if (yourMove == 'X') {
            cout << "your rock. ";
            cout << "You lose!" << endl;

            return 0;
        }

        if (yourMove == 'Y')
        {
            cout << "your paper. ";
            cout << "It's a draw!" << endl;

            return 3;
        }

        if (yourMove == 'Z')
        {
            cout << "your scissors. ";
            cout << "You win!" << endl;

            return 6;
        }
    }

    return 0;
}

int scoreIfOpponentUsesScissors(char opponentMove, char yourMove)
{
    if (opponentMove == 'C')
    {
        cout << "Opponent played scissors vs. ";

        if (yourMove == 'X') {
            cout << "your rock. ";
            cout << "You win!" << endl;

            return 6;
        }

        if (yourMove == 'Y')
        {
            cout << "your paper. ";
            cout << "You lose!" << endl;

            return 0;
        }

        if (yourMove == 'Z')
        {
            cout << "your scissors. ";
            cout << "It's a draw!" << endl;

            return 3;
        }
    }

    return 0;
}

int scoreForYourMove(char yourMove)
{
    // Now add score for what move you used:
    if (yourMove == 'X') {
        // Rock
        return 1;
    }

    if (yourMove == 'Y')
    {
        // Paper
        return 2;
    }

    if (yourMove == 'Z')
    {
        // Scissors
        return 3;
    }
}



//if (line != "")
//{
//cumulation+=stoi(line);
//}
//else
//{
//cout << "Total for elf #" << ++counter << ": " << cumulation << endl;
//
//if (cumulation > highestAmount)
//{
//highestAmount = cumulation;
//
//totals.push_back(highestAmount);
//}
//
//cumulation = 0;
//}
//
//for (int x : totals) {
//cout << x << '\n';
//}
