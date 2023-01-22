#include<iostream>
#include<conio.h>
using namespace std;

char square[10]={'o','1','2','3','4','5','6','7','8','9'};

int checkforWin(){
	if (square[1] == square[2] && square[2] == square[3])

        return 1;
    else if (square[4] == square[5] && square[5] == square[6])

        return 1;
    else if (square[7] == square[8] && square[8] == square[9])

        return 1;
    else if (square[1] == square[4] && square[4] == square[7])

        return 1;
    else if (square[2] == square[5] && square[5] == square[8])

        return 1;
    else if (square[3] == square[6] && square[6] == square[9])

        return 1;
    else if (square[1] == square[5] && square[5] == square[9])

        return 1;
    else if (square[3] == square[5] && square[5] == square[7])

        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' 
                    && square[4] != '4' && square[5] != '5' && square[6] != '6' 
                  && square[7] != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return -1;
}

void playArea();


tictactoe(){
	
	int player=1,stop=1,todo;
	char player1='X',player2='O',turn=player1;
	
	do{
		playArea();
		
		cout<<"Player of "<< turn << " Enter block no=";
		cin>>todo;
		if(square[todo]==player1 || square[todo]==player2 || todo>9 ||todo<1 ){
				cout<<"Invalid Input";
				getch();
				if(turn==player1){
				turn=player2;
				}
				else{
				turn=player1;
				}
			}
			else{
				for(int i=1;i<=9;i++){
			    if(todo==i){
				square[i]=turn;
			}
		}
			}
		
		
		
		//Change Turn
		if(turn==player1){
			turn=player2;
		}
		else{
			turn=player1;
		}
		
		stop=checkforWin();
		
	}while(stop==-1);
	playArea();
	if(turn==player1){
			turn=player2;
		}
		else{
			turn=player1;
		}
    if(stop==1)

        cout<<"-Player "<<turn<<" win ";
    else
        cout<<"-Game draw";
	
}


void playArea(){
	system("cls");
	cout<<"Tic Tac Toe\n\n";
	
	cout<<"Player 1 = X , Player 2 = O\n"<<endl;
	
	cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

    cout << "     |     |     " << endl << endl;
}

