/*
 * lab2.cpp
 *
 *  Created on: Sep 14, 2019
 *      Author: user
 */

#include <iostream>
using namespace std;

int main(){
	//VARIABLES==============================================================================
	char wolf1 = 'w', sheep1 = 's', cabbage1 = 'c';
	char wolf2 = ' ', sheep2 = ' ', cabbage2 = ' ';
	char input;
	char turn = 'l';
	bool win = false, boatR = false, boatL = true;
	int loop = 0;

    //PRINT===================================================================================
	cout << "****************************" << endl;
	cout << "Wolf, Sheep and Cabbage Game\n";
	cout << "****************************\n" << endl;

	cout << "Left  --------------------  Right\n";
	cout << "w s c\n";
	cout << "boat\n\n";

	cout << "Game Start!\n";

	//LOOPING=================================================================================
	while(!win){
		cout << "Item to carry (w: wolf, s: sheep, c: cabbage, n: nothing):\n";
		if(turn == 'l'){
			cout << "(The boat goes to the right now.)\n";
			boatL = true;
			boatR = false;
		}
		else{
			cout << "(The boat goes to the left now.)\n";
			boatR = true;
			boatL = false;
		}

		cin >> input;
		cout << "Left  --------------------  Right\n";

		//moving things ******************************************************************************
		if(input == 'w' && turn == 'l'){
			wolf1 = ' ';
			wolf2 = 'w';
		}
		else if(input == 'w' && turn == 'r'){
			wolf2 = 'w';
			wolf1 = ' ';
		}
		else if(input == 's' && turn == 'l'){
			sheep2 = 's';
			sheep1 = ' ';
		}
		else if(input == 's' && turn == 'r'){
			sheep2 = ' ';
			sheep1 = 's';
		}
		else if(input == 'c' && turn == 'l'){
			cabbage2 = 'c';
			cabbage1 = ' ';
		}
		else if(input == 'c' && turn == 'r'){
			cabbage2 = ' ';
			cabbage1 = 'c';
		}


//		//WHEN THEY INPUT THE WRONG THINGS======================================================
//		if(turn == 'r'){
//			if((input == 'w' && wolf1 == ' ')||(input == 's' && sheep1 == ' ')||(input == 'c' && cabbage1 == ' ')){
//				cout << "There is no " << input << " in the right.\n\n=================================================\n";
//				loop = 0;
//				continue;
//			}
//		}
//		else if(turn == 'l'){
//			if((input == 'w' && wolf2 == ' ')||(input == 's' && sheep2 == ' ')||(input == 'c' && cabbage2 == ' ')){
//				cout << "There is no " << input << " in the left.\n\n=================================================\n";
//				loop = 0;
//				continue;
//			}
//		}



		//PRINT ---------------------------------------------------------------------------------
		cout << wolf1 << " " << sheep1 << " " << cabbage1
				<< "                         " << wolf2 << " "
				<< sheep2 << " " << cabbage2 << endl << "=============================================================\n";




		//WIN CONDITION --------------------------------------------------------------------------
		if(wolf2 == 'w' && sheep2 == 's' && cabbage2 == 'c'){
			win = true;
			cout << "YOU WIN!! CONGRATULATION!!\n";
		}


		//LOSING CONDIION(EATEN)--------------------------------------------------------------------
		else if(((wolf1 == 'w' && sheep1 == 's') ||
				(sheep1 == 's' && cabbage1 == 'c')) && loop != 0 && turn == 'l'){
			cout << "Boo! One of them is being eaten by the other. Try Again!!\n";
			loop = 0;
			turn = 'l';
			wolf1 = 'w', sheep1 = 's', cabbage1 = 'c';
			wolf2 = ' ', sheep2 = ' ', cabbage2 = ' ';
			continue;
		}
		else if(((wolf2 == 'w' && sheep2 == 's') ||
				(sheep2 == 's' && cabbage2 == 'c')) && loop != 0 && turn == 'r'){
			cout << "Boo! One of them is being eaten by the other. Try Again!!\n";
			loop = 0;
			turn = 'l';
			wolf1 = 'w', sheep1 = 's', cabbage1 = 'c';
			wolf2 = ' ', sheep2 = ' ', cabbage2 = ' ';
			continue;
		}

		//looping ------------------------------------------------------------------------------------
		++loop;
		if(turn == 'l')
			turn = 'r';
		else
			turn = 'l';
	}

	return 0;
}


