#include <iostream>
#include<stdlib.h>

using namespace std;

char matrix[3][3];

//function declarations
char check();
void createMatrix();
void userMove();
void computerMove();
void displayMatrix();
void showCoordinates();

int main()
{
    char done;
    cout<<"This is a tic tac toe game."<<endl;
    cout<<"You will be playing against the computer."<<endl;
    cout<<"Below is a coordinate matrix displayed for you."<<endl;
    showCoordinates();
    done=' ';
    createMatrix();
    cout<<"All the best!"<<endl;
    system("pause");
    
    //game execution 
    do{
        displayMatrix();
        userMove();
        done=check();
        if(done!=' ') { break; }
        computerMove();
        done=check();
    }while(done==' ');
    if(done=='X') { cout<<"You won!"<<endl; }
    else { cout<<"I won!"<<endl; }
    displayMatrix();
    return 0;
}

//function definitions

//matrix initialized
void createMatrix()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matrix[i][j]=' ';
        }
    }
}

//user's move to be recorded
void userMove()
{
    int x, y;
    cout<<"Enter x,y coordinates for your move."<<endl;
    cin>>x;
    cin>>y;
    cout<<endl;
    if(matrix[x][y]!=' ')
    {
        cout<<"Invalid move. Try again."<<endl;
        userMove();
    }
    else { matrix[x][y]='X'; }
}

//computer's move, which is pretty easy to beat
void computerMove()
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
            if(matrix[i][j]==' ') break;
        if(matrix[i][j]==' ') break;
    }

    if(i*j==9)
    {
        cout<<"Draw!"<<endl;
        exit(0);
    }
    else
    {
        matrix[i][j]='O';
    }
}

//a coordinate map to guide the user
void showCoordinates()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout<<i<<j<<" ";
        }
        cout<<endl;
        if(i!=2) { cout<<"--|--|--"<<endl; }
    }
}

//showing matrix at various stages
void displayMatrix()
{
    for(int t=0; t<3; t++)
    {
        cout<<" "<<matrix[t][0]<<"  "<<matrix[t][1]<<"  "<<matrix[t][2]<<endl;
        if(t!=2) { cout<<"--|---|--"<<endl; }
    }
}

//checking for win
char check()
{
    for(int i=0; i<3; i++)
    {
        if(matrix[i][0]==matrix[i][1] && matrix[i][0]==matrix[i][2])
        {
            return matrix[i][0];
        }
    }
    for(int i=0; i<3; i++)
    {
        if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
        {
            return matrix[0][i];
        }
    }
    if(matrix[0][0]==matrix[1][1] && matrix[0][0]==matrix[2][2])
    {
        return matrix[0][0];
    }
    if(matrix[1][1]==matrix[0][2] && matrix[1][1]==matrix[2][0])
    {
        return matrix[1][1];
    }
    return ' ';
}
