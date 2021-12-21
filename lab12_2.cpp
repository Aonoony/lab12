#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int x;
	do{
	 x = rand()%14;
	}while(x == 0);
	return x;
}

int calScore(int x,int y,int z){
	if(x == 11 or x == 12 or x ==13){
		x =10;
	}if(y == 11 or y == 12 or y ==13){
		y =10;
	}if(z == 11 or z == 12 or z ==13){
		z =10;
	}
	int score = (x + y + z)%10;
	return score;
}

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1; 
	else{
		if((rand()%100+1) >= 70 and (rand()%100+1) <= 100) return 2;
		else return 1;
	}
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if(p == y){
		cout <<   "|             Draw!!!           |";
	}if(p > y){
		cout <<   "|         Player wins!!!        |";
	}if(p < y){
		cout <<   "|          Yugi wins!!!         |";
	}
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0}; 
	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction != 1 and playerAction != 2);
	if(playerAction == 1){
		cout << "Player draws the 3rd card!!!" << "\n";
		cout << "Your 3rd card: " <<cardNames[playerCards[3]]<< "\n";
		cout << "Your new score: " <<calScore(playerCards[0],playerCards[1],playerCards[2])<< "\n";
	}
	cout << "------------ Turn end -------------------\n\n";
	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " <<cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		cout << "Yugi draws the 3rd card!!!\n";
		cout << "Yugi's 3rd card: " <<cardNames[yugiCards[3]]<< "\n";
		cout << "Yugi's new score: " <<calScore(yugiCards[0],yugiCards[1],yugiCards[2])<< "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	checkWinner(playerScore,yugiScore);
}
