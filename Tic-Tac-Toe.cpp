#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
char grid[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
vector <int> moves = {1,2,3,4,5,6,7,8,9};
vector <int> ::iterator it1,it2;
char turn = 'X';
bool run =1;
int row=9, col=9, draw = 0,type;

int getIndex(vector<int> v, int K)
{
    auto it = find(v.begin(), v.end(), K);
 
    // If element was found
    if (it != v.end()) 
    {
     
        // calculating the index
        // of K
        int index = it - v.begin();
        return index;
    }
    return 0;
}

int pregame(int a)
{
    int choice;
    
    system("cls");
    
    cout << "*******************************************************************************\n";
    cout << "\t\t Tic Tac Toe by Sidharth Sethi\n";
    cout << "*******************************************************************************\n";
    if (a==0)
    cout<<endl<<endl<<"1)  Play 2 player Game "<<endl<<"2)  Play vs Computer"<<endl<<endl<<"Enter Your Choice : ";
    else
    cout<<endl<<endl<<"1)  Play 2 player Game "<<endl<<"2)  Play vs Computer"<<endl<<endl<<"Enter a Valid Choice : ";
    cin>>choice;
    if(choice == 1 || choice == 2)
    {
        return choice;
    }
    else
    {
        a=1;
        pregame(a);
    }
    return 0;

}

void board(int choice) //Display basic board
{
    system("cls"); //to clear previous screen
    cout << "*******************************************************************************\n";
    cout << "\t\t Tic Tac Toe by Sidharth Sethi\n";
    cout << "*******************************************************************************\n";
    if (type==1)
    cout << endl << "\t\t Player 1 is X" << endl << "\t\t Player 2 is O" << endl;
    else
    cout << endl << "You are Playing as X"<<endl;
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<grid[0][0]<<"  |  "<<grid[0][1]<<"  |  "<<grid[0][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<grid[1][0]<<"  |  "<<grid[1][1]<<"  |  "<<grid[1][2]<<"  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  "<<grid[2][0]<<"  |  "<<grid[2][1]<<"  |  "<<grid[2][2]<<"  \n";
    cout << "\t\t     |     |     \n";

    if(type==2)
    cout<<"\t\n Your Turn\n";
}

void pturn(int type)
{
    if (type==1)
    {
    if(turn == 'X')
        cout << "\t\n Player 1 X turn \n";
    else if(turn == 'O')
        cout << "\t\n Player 2 O turn \n";
    }
    int choice,choiceIndex;
    cin >> choice;
    if(type==2)
    {
    choiceIndex=getIndex(moves,choice);
    it1=moves.begin()+(choiceIndex);
    it2=moves.begin()+(choiceIndex+1);
    moves.erase(it1,it2);
    }
    switch(choice) //Taking Input
    {
        case 1:
            row=0; col=0;
            break;
        case 2:
            row=0; col=1;
            break;
        case 3:
            row=0; col=2;
            break;
        case 4:
            row=1; col=0;
            break;
        case 5:
            row=1; col=1;
            break;
        case 6:
            row=1; col=2;
            break;
        case 7:
            row=2; col=0;
            break;
        case 8:
            row=2; col=1;
            break;
        case 9:
            row=2; col=2;
            break;
        default : cout << "Invalid Choice \n"; 
    }
    /*
        Turn Switch and Prevention of changing other's marking
    */
   if (type==1)
   {
    if(turn == 'X' && grid[row][col] != 'X' && grid[row][col] != 'O')
    {
        grid[row][col] = 'X';
        turn = 'O';
    }
    else if(turn == 'O' && grid[row][col] != 'X' && grid[row][col] != 'O')
    {
        grid[row][col] = 'O';
        turn = 'X';
    }    
    else
    {
        cout << "Wrong Input";
        pturn(type); //Asking for input again here
    }
   }
   else
   {
       if(grid[row][col] != 'X' && grid[row][col] != 'O')
        {
            grid[row][col] = 'X';
            turn = 'O';
        }
        else
        {
            cout << "Wrong Input";
            pturn(type); //Asking for input again here
        }

   }
    board(type);
}

void cturn()
{
    int choice,choiceIndex;
    choiceIndex=rand() % moves.size();
    choice=moves[choiceIndex];
    
    it1=moves.begin()+(choiceIndex);
    it2=moves.begin()+(choiceIndex+1);
    moves.erase(it1,it2);
    
    switch(choice) //Taking Input
    {
        case 1:
            row=0; col=0;
            break;
        case 2:
            row=0; col=1;
            break;
        case 3:
            row=0; col=2;
            break;
        case 4:
            row=1; col=0;
            break;
        case 5:
            row=1; col=1;
            break;
        case 6:
            row=1; col=2;
            break;
        case 7:
            row=2; col=0;
            break;
        case 8:
            row=2; col=1;
            break;
        case 9:
            row=2; col=2;
            break;
        default : cout << "Invalid Choice \n"; 
    }
    /*
        Turn Switch and Prevention of changing other's marking
    */
    
        grid[row][col] = 'O';
        turn = 'X';
    
    //board(type);

}


int game()
{
    //win
    //horizontal
    for(int i=0; i<=2; i++)
        if(grid[i][0]==grid[i][1] && grid[i][0]== grid[i][2])
            return 0;
    //vertical
    for(int i=0; i<=2; i++)
        if(grid[0][i]==grid[1][i] && grid[0][i]== grid[2][i])
            return 0;
    //diagonals
    if(grid[0][0]==grid[1][1] && grid[1][1]== grid[2][2])
            return 0;
    if(grid[0][2]==grid[1][1] && grid[1][1]== grid[2][0])
            return 0;    
    //game running
    for(int i=0; i<=2; i++)
        for(int j=0; j<=2; j++)
            if(grid[i][j] != 'X' && grid[i][j] != 'O')
                return 1;
    draw=1;
    return 0;
}

void ending()
{
    if(type==1)
    {
    if(draw == 1)
        cout << "\t\tGame Draw";
    else if(turn == 'X')
        cout << "\t\tPlayer 2 WINS!!!";
    else if(turn == 'O')
        cout << "\t\tPlayer 1 WINS!!!";
    cout << "\n\t\tGAME OVER TATA";
    }
    else
    {
        if(draw==1)
        cout<<"\t\tGame Draw";
        else if(turn=='X')
            cout<<"\t\tYou Won !!";
        else if(turn =='O')
            cout<<"\t\tYou Lost :(";
        cout << "\n\t\tGAME OVER TATA";
    }
}

int main()
{
    int choice;
    int a=0;
    choice=pregame(a);
    if(choice==1){
        type=1;
    while(run)
    {
        board(type);
        pturn(type);
        run = game();
    }
    ending();
    }
    else
    {
    type=2;
    //cout<<"Coming Soon";
    while(run)
    {
    board(type);
    pturn(type);
    cturn();
    run=game();
    }
    ending();
    }
    return 0;
}
