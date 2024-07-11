#include <bits/stdc++.h>
using namespace std;

void drawBox(char *box){
    cout << "\n       |       |       ";
    cout << "\n   " << box[0] << "   |" << "   " << box[1] << "   |" << "  " << box[2] << "   ";
    cout << "\n_______|_______|_______";
    cout << "\n       |       |       ";
    cout << "\n   " << box[3] << "   |" << "   " << box[4] << "   |" << "  " << box[5] << "   ";
    cout << "\n_______|_______|_______";
    cout << "\n       |       |       ";
    cout << "\n   " << box[6] << "   |" << "   " << box[7] << "   |" << "  " << box[8] << "   ";
    cout << "\n       |       |       ";
    cout << "\n";
    cout << "\n";
}

void player1Move(char *box, char player1){
    int flag = 1;
    while (flag == 1)
    {
        cout << "Player-1 enter a number between (1-9) to mark your spot: ";
        int pos;
        cin >> pos;
        pos--;
        if (box[pos] == ' ')
        {
            box[pos] = player1;
            flag = 0;
        }
    }
}

void player2Move(char *box, char player2){
    int flag = 1;
    while (flag == 1)
    {
        cout << "Player-2 enter a number between (1-9) to mark your spot: ";
        int pos;
        cin >> pos;
        pos--;
        if (box[pos] == ' ')
        {
            box[pos] = player2;
            flag = 0;
        }
    }
}

bool checkWinner(char *box, char player1, char player2){
    string winner;
    if (box[0]!=' ' && box[0]==box[1] && box[1]==box[2])
    {
        winner = box[0]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[3]!=' ' && box[3]==box[4] && box[4]==box[5])
    {
        winner = box[3]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[6]!=' ' && box[6]==box[7] && box[7]==box[8])
    {
        winner = box[6]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[0]!=' ' && box[0]==box[3] && box[3]==box[6])
    {
        winner = box[0]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[1]!=' ' && box[1]==box[4] && box[4]==box[7])
    {
        winner = box[1]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[2]!=' ' && box[2]==box[5] && box[5]==box[8])
    {
        winner = box[2]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[0]!=' ' && box[0]==box[4] && box[4]==box[8])
    {
        winner = box[0]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    else if (box[2]!=' ' && box[2]==box[4] && box[4]==box[6])
    {
        winner = box[2]==player1 ? "Player1" : "Player2";
        cout<<"The winner is "<<winner<<endl;
        return true;
    }
    return false;
}

bool checkTie(char *box){
    for (int i = 0; i < 9; i++)
    {
        if (box[i] == ' ')
        {
            return false;
        }
    }
    cout<<"Match Draw!"<<endl;
    return true;
}

int main(){
    char box[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player1 = 'X';
    char player2 = 'O';
    bool running = true;
    drawBox(box);

    while (running){
        player1Move(box, player1);
        drawBox(box);
        if (checkWinner(box,player1,player2))
        {
            running = false;
            break;
        }
        if (checkTie(box))
        {
            running = false;
            break;
        }

        player2Move(box, player2);
        drawBox(box);
        if (checkWinner(box,player1,player2))
        {
            running = false;
            break;
        }
        if (checkTie(box))
        {
            running = false;
            break;
        }
    }
    cout<<"Thanks for playing!"<<endl;

    return 0;
}