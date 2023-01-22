#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

char randop(){
	srand(time(0));
    int num = rand() % 3 + 1;
 
    if(num==1) return 'r';
    if(num==2) return 'p';
    if(num==3) return 's';
}

void Showop(char opt){
	if(opt=='r') cout << "Rock";
	if(opt=='p') cout <<"Paper";
	if(opt=='s') cout <<"Scissors";
}

main(){
	const char rock='r';
	const char paper='p';
	const char sci='s';
	system("cls");
	char user;
	cout<<"Enter character= (r) for rock " << endl << "(p) for paper" << endl << "(s) for scissors -> " << endl;
	cin>>user;
	
	while(user!='r' && user!='p' && user!='s'){
		cout<<"Invalid Input,Try again\n";
		cin>>user;
	}
	
   cout<<"You selected ";
	Showop(user);
	
	cout<<"\nComputer selected ";
	Showop(randop());
	
}
