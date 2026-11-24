#include "Interface.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <Windows.h>
#include "CreatureDeFeu.h"
#include <chrono>
#include <thread>
#include <mmsystem.h>
#include "Control.h"
#include "CreatureSprites.h"

#pragma comment(lib, "winmm.lib")

using namespace std;
using namespace this_thread;
using namespace chrono;

Creature* Interface::m_player1 = nullptr;
Creature* Interface::m_player2 = nullptr;
int short Interface::s_inputPlayer[2] = { -1,-1 };
char Interface::g_currentRoom[ROOM_WIDTH][ROOM_HEIGHT] = { ' ' };
int Interface::m_player1PosX = 35;
int Interface::m_player1PosY = 20;
int Interface::m_player2PosX = 45;
int Interface::m_player2PosY = 19;





void Interface::MainMenu()
{

	std::string selectCursorMenu;
	for (int i = 0; i < 6; i++)
	{
		selectCursorMenu.push_back(' ');
	}
	int ptr = 0;
	Control::Cursor(selectCursorMenu, ptr, selectCursorMenu.size());

	bool menuIn = true;
	float percent = 100.0f;
	float maxVolume = 100.0f;
	string soundBar = Bar(percent,maxVolume);
	PlaySound(TEXT("Main Theme.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	for (int i = 0; i < 16; i++) {
		cout << "\033[H";
		if(i>=15)
			cout << "\033[31m" << R"(           ,----,                                                                                                  )" << "\033[0m" <<                        endl;
		if(i>=14)
			cout << "\033[31m" << R"(         ,/   .`|                                                                                           )" << "\033[32m" << R"()" << "\033[0m" <<        endl;
		if(i>=13)
			cout << "\033[31m" << R"(       ,`   .'  :                                          ,---,.                ___      ___     ,--)" << "\033[32m" << R"(,             )" << "\033[0m" << endl;
		if(i>=12)
			cout << "\033[31m" << R"(     ;    ;     / ,--,                                   ,'  .'  \             ,--.'|_  ,--.'|)" << "\033[32m" << R"(_ ,--.'|             )" << "\033[0m" << endl;
		if(i>=11)
			cout << "\033[31m" << R"(   .'___,/    ,',--.'|         ,---,                   ,---.' .' |             |  | :,')" << "\033[32m" << R"( |  | :,'|  | :             )" << "\033[0m" << endl;
		if(i>=19)
			cout << "\033[31m" << R"(   |    :     | |  |,      ,-+-. /  |                  |   |  |: |             :)" << "\033[32m" << R"(  : ' : :  : ' ::  : '             )" << "\033[0m" << endl;
		if(i>=9)
			cout << "\033[31m" << R"(   ;    |.';  ; `--'_     ,--.'|'   |     .--,         :   :  :  /  ,--.-)" << "\033[32m" << R"(-.  .;__,'  /.;__,'  / |  ' |      ,---.  )" << "\033[0m" << endl;
		if(i>=8)
			cout << "\033[31m" << R"(   `----'  |  | ,' ,'|   |   |  ,"' |   /_ ./|         :   |    ; )" << "\033[32m" << R"( /       \ |  |   | |  |   |  '  | |     /     \ )" << "\033[0m" << endl;
		if(i>=7)
			cout << "\033[31m" << R"(       '   :  ; '  | |   |   | /  | |, ' , ' :         |   )" << "\033[32m" << R"(:     \.--.  .-. |:__,'| : :__,'| :  |  | :    /    /  |)" << "\033[0m" << endl;
		if(i>=6)
			cout << "\033[31m" << R"(       |   |  ' |  | :   |   | |  | /___/ \: |      )" << "\033[32m" << R"(   |   |   . | \__\/: . .  '  : |__ '  : |__'  : |__ .    ' / |)" << "\033[0m" << endl;
		if(i>=5)
			cout << "\033[31m" << R"(       '   :  | '  : |__ |   | |  |/ .  \  ' )" << "\033[32m" << R"(|         '   :  '; | ," .--.; |  |  | '.'||  | '.'|  | '.'|'   ;   /|)" << "\033[0m" << endl;
		if(i>=4)
			cout << "\033[31m" << R"(       ;   |.'  |  | '.'||   | |--'   )" << "\033[32m" << R"(\  ;   :         |   |  | ; /  /  ,.  |  ;  :    ;;  :    ;  :    ;'   |  / |)" << "\033[0m" << endl;
		if(i>=3)
			cout << "\033[31m" << R"(       '---'    ;  :    ;|   |/)" << "\033[32m" << R"(        \  \  ;         |   :   / ;  :   .'   \ |  ,   / |  ,   /|  ,   / |   :    |)" << "\033[0m" << endl;
		if(i>=2)
			cout << "\033[31m" << R"(                |  ,   /)" << "\033[32m" << R"( '---'          :  \  \        |   | ,'  |  ,     .-./  ---`-'   ---`-'  ---`-'   \   \  / )" << "\033[0m" << endl;
		if(i>=1)
			cout << "\033[31m" << R"(                 )" << "\033[32m" << R"(---`-'                  \  ' ;        `----'     `--`---'                                 `----'  )" << "\033[0m" << endl;
		if(i>=0)
			cout << "\033[32m" << R"(                                          `--`                                                                     )" << "\033[0m" << endl;
		sleep_for(milliseconds(100));
	}

	while (menuIn) {
		cout << "\033[H";
		cout << "\033[31m" <<R"(           ,----,                                                                                                  )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(         ,/   .`|                                                                                           )"<< "\033[32m" << R"()" << "\033[0m" << endl;
		cout << "\033[31m" <<R"(       ,`   .'  :                                          ,---,.                ___      ___     ,--)"<< "\033[32m" <<R"(,             )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(     ;    ;     / ,--,                                   ,'  .'  \             ,--.'|_  ,--.'|)"<< "\033[32m" <<R"(_ ,--.'|             )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(   .'___,/    ,',--.'|         ,---,                   ,---.' .' |             |  | :,')" << "\033[32m" << R"( |  | :,'|  | :             )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(   |    :     | |  |,      ,-+-. /  |                  |   |  |: |             :)" << "\033[32m" << R"(  : ' : :  : ' ::  : '             )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(   ;    |.';  ; `--'_     ,--.'|'   |     .--,         :   :  :  /  ,--.-)" << "\033[32m" << R"(-.  .;__,'  /.;__,'  / |  ' |      ,---.  )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(   `----'  |  | ,' ,'|   |   |  ,"' |   /_ ./|         :   |    ; )" << "\033[32m" << R"( /       \ |  |   | |  |   |  '  | |     /     \ )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(       '   :  ; '  | |   |   | /  | |, ' , ' :         |   )" << "\033[32m" << R"(:     \.--.  .-. |:__,'| : :__,'| :  |  | :    /    /  |)"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(       |   |  ' |  | :   |   | |  | /___/ \: |      )" << "\033[32m" << R"(   |   |   . | \__\/: . .  '  : |__ '  : |__'  : |__ .    ' / |)"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(       '   :  | '  : |__ |   | |  |/ .  \  ' )" << "\033[32m" << R"(|         '   :  '; | ," .--.; |  |  | '.'||  | '.'|  | '.'|'   ;   /|)"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(       ;   |.'  |  | '.'||   | |--'   )" << "\033[32m" << R"(\  ;   :         |   |  | ; /  /  ,.  |  ;  :    ;;  :    ;  :    ;'   |  / |)"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(       '---'    ;  :    ;|   |/)" << "\033[32m" << R"(        \  \  ;         |   :   / ;  :   .'   \ |  ,   / |  ,   /|  ,   / |   :    |)"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(                |  ,   /)" << "\033[32m" << R"( '---'          :  \  \        |   | ,'  |  ,     .-./  ---`-'   ---`-'  ---`-'   \   \  / )"<< "\033[0m" << endl;
		cout << "\033[31m" <<R"(                 )" << "\033[32m" << R"(---`-'                  \  ' ;        `----'     `--`---'                                 `----'  )"<< "\033[0m" << endl;
		cout << "\033[32m" <<R"(                                          `--`                                                                     )"<< "\033[0m" << endl;
		cout << right << setw(60) << (selectCursorMenu[0] + string("Start") + selectCursorMenu[1]) << endl;
		cout << right << setw(60) << (selectCursorMenu[2] + string("Options") + selectCursorMenu[3]) << endl;
		cout << right << setw(60) << (selectCursorMenu[4] + string("Quit") + selectCursorMenu[5]) << endl;


		if ((Control::KeyPressed('W')|| Control::KeyPressed(VK_UP)) && ptr - 1 >=0)
		{
			ptr -= 1;
			Control::Cursor(selectCursorMenu, ptr, selectCursorMenu.size());
		}
		if ((Control::KeyPressed('S')|| Control::KeyPressed(VK_DOWN)) && ptr + 1 <=2)
		{
			ptr += 1;
			Control::Cursor(selectCursorMenu, ptr, selectCursorMenu.size());
		}

		if (Control::KeyPressed(VK_RETURN))
		{
			switch(ptr)
			{
			case 0:
				PlaySound(TEXT("Hub.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				HubWorld();
				break;
			case 1:
				cout << left << setw(42) << "\r" << "Volume Bar : Press enter to confirm" << endl;
				while (true)
				{
					sleep_for(milliseconds(100));
					if ((GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) && (percent - 5) >= 0)
					{
						percent -= 5;
						soundBar = Bar(percent, maxVolume);
					}
					else if ((GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) && (percent + 5) <= 100)
					{
						percent += 5;
						soundBar = Bar(percent, maxVolume);
					}
					cout << left << setw(54) << "\r" << left << setw(20) << soundBar;

					const DWORD dwVolume = (DWORD)(0xFFFF * (percent / 100));
					const MMRESULT result = waveOutSetVolume((HWAVEOUT)0, MAKELONG(dwVolume, dwVolume));
					if (Control::KeyPressed(VK_RETURN))
					{
						cout << "\033[2K" << "\033[F" << "\033[2K";
						break;
						
					}
				}
				break;
			case 2:
				menuIn = false;
				break;
			}
		}

		
	
	}
}

void Interface::CreateCreature()
{
	string confirmCursor;
	string confirmCursor2;
	string selectTypeCursor;
	int ptr = 0;
	int ptr2 = 0;
	int ptr3 = 0;
	confirmCursor.push_back('[');
	confirmCursor.push_back(']');
	confirmCursor2.push_back('[');
	confirmCursor2.push_back(']');
	selectTypeCursor.push_back('[');
	selectTypeCursor.push_back(']');
	int currentStep = 0;
	for (int i = 0; i < 2; i++) {
		confirmCursor.push_back(' ');
		confirmCursor2.push_back(' ');
	}
	for (int i = 0; i < 8; i++) {
		selectTypeCursor.push_back(' ');
	}
	while (true)
	{
		cout << "\033[H";
		cout << endl << "Voulez-vous creer une nouvelle creature?" << endl << confirmCursor[0] << "Yes" << confirmCursor[1] << " " << confirmCursor[2] << "No" << confirmCursor[3] << endl;
		if (currentStep == 0)
		{
			if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr - 1 >= 0)
			{
				ptr -= 1;
				Control::Cursor(confirmCursor, ptr, 4);
			}
			if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr + 1 <= 1)
			{
				ptr += 1;
				Control::Cursor(confirmCursor, ptr, 4);
			}

			if (Control::KeyPressed(VK_RETURN))
			{
				switch (ptr)
				{
				case 0:
					currentStep = 1;
					break;
				case 1:
					system("CLS");
					return;
				}
			}

		}
		if (currentStep == 2) 
		{
			cout << "Voulez-vous creer une creature aleatoire?" << endl << confirmCursor2[0] << "Yes" << confirmCursor2[1] << " " << confirmCursor2[2] << "No" << confirmCursor2[3] << endl;
		}
		if (currentStep == 1)
		{
			cout << "Voulez-vous creer une creature aleatoire?" << endl << confirmCursor2[0] << "Yes" << confirmCursor2[1] << " " << confirmCursor2[2] << "No" << confirmCursor2[3] << endl;
			if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr2 - 1 >= 0)
			{
				ptr2 -= 1;
				Control::Cursor(confirmCursor2, ptr2, 4);
			}
			if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr2 + 1 <= 1)
			{
				ptr2 += 1;
				Control::Cursor(confirmCursor2, ptr2, 4);
			}

			if (Control::KeyPressed(VK_RETURN))
			{

				switch (ptr2)
				{
				case 0:
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					CreateRandomCreature();
					system("CLS");
					SelectionCreature();
					break;
				case 1:
					currentStep = 2;
					break;
				}
			}
		}
		if (currentStep == 2) {
			cout << "Qu'elle type voulez-vous creer?" << endl << selectTypeCursor[0] << "Feu" << selectTypeCursor[1] << " " << selectTypeCursor[2] << "Eau" << selectTypeCursor[3] << " " << selectTypeCursor[4] << "Plante" << selectTypeCursor[5] << " " << selectTypeCursor[6] << "Electrique" << selectTypeCursor[7] << endl;

			if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr3 - 1 >= 0)
			{
				ptr3 -= 1;
				Control::Cursor(selectTypeCursor, ptr3, 8);
			}
			if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr3 + 1 <= 3)
			{
				ptr3 += 1;
				Control::Cursor(selectTypeCursor, ptr3, 8);
			}
			if (Control::KeyPressed(VK_RETURN))
			{
				switch (ptr3)
				{
				case 0:
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					new CreatureDeFeu();
					system("CLS");
					SelectionCreature();
					break;
				case 1:
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					system("CLS");
					SelectionCreature();
					break;
				case 2:
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					system("CLS");
					SelectionCreature();
					break;
				case 3:
					FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
					system("CLS");
					SelectionCreature();
					break;
				}

			}
		}
		sleep_for(milliseconds(20));
	}
			
}
void Interface::CreateRandomCreature()
{
	
	string nom;
	cout << "Entrer le nom de la creature: " << endl;
	cin >> nom;
	int rando;
	int pv = 1;
	int att = 1;
	int def = 1;
	int spe = 1;
	int mp = 1;
	for (int i = 0; i <= 144; i++) {
		rando = rand() % 5;
		switch (rando) {
		case 0:
			pv++;
			break;
		case 1:
			att++;
			break;
		case 2:
			def++;
			break;
		case 3:
			spe++;
			break;
		case 4:
			mp++;
			break;
		}
	}
	rando = rand() % 1;
	switch (rando)
	{
	case 0:
		new CreatureDeFeu(nom, pv, att, def, spe, mp);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}


void Interface::SelectionCreature()
{

	cout << " ";
	string choice;
	int ptr = 0;
	string out;
	int size;
	std::string selectMonsterCursor;
	std::string SelectActionCursor;
	SelectActionCursor.push_back('[');
	SelectActionCursor.push_back(']');
	for (int i = 0; i < 8; i++)
	{
		SelectActionCursor.push_back(' ');
	}
	system("CLS");
	while (true)
	{
		cout << "\033[H";
		cout << endl << SelectActionCursor[0] << "Ajouter une creature" << SelectActionCursor[1] << " " << SelectActionCursor[2] << "Modifier une creature" << SelectActionCursor[3] << " " << SelectActionCursor[4] << "Supprimer une creature" << SelectActionCursor[5] << " " << SelectActionCursor[6] << "Afficher les creatures" << SelectActionCursor[7] << " " << SelectActionCursor[8] << "Quitter" << SelectActionCursor[9] << endl;
		if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr - 1 >= 0)
		{
			ptr -= 1;
			Control::Cursor(SelectActionCursor, ptr, SelectActionCursor.size());
		}
		if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr + 1 <= 4)
		{
			ptr += 1;
			Control::Cursor(SelectActionCursor, ptr, SelectActionCursor.size());
		}
		if (Control::KeyPressed(VK_RETURN))
		{
			switch (ptr)
			{
			case 0:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				system("CLS");
				CreateCreature();
				break;
			case 1:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				system("CLS");
				size = Creature::GetListSize();
				if (size != 0)
				{
					cout << "Quelle creature voulez-vous modifier? \n";
					Creature::PrintListeCreature();
					cin >> choice;
					Creature::ModifierCreature(Creature::GetCreature(choice));
					system("CLS");
					break;
				}
				else
				{
					cout << "Aucune creature disponible a modifier";
					sleep_for(seconds(2));
					system("CLS");
					break;
				}
			case 2:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				system("CLS");
				size = Creature::GetListSize();
				if (size != 0)
				{
					cout << "Quelle creature voulez-vous supprimer? \n";
					Creature::PrintListeCreature();
					cin >> choice;
					Creature::SuprimeCreature(Creature::GetCreature(choice));
					system("CLS");
					break;
				}
				else
				{
					cout << "Aucune creature disponible a supprimer";
					sleep_for(seconds(2));
					system("CLS");
					break;
				}
			case 3:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				system("CLS");
				Creature::PrintListeCreature();
				cout << endl << "Press ENTER to quit";
				sleep_for(milliseconds(100));
				while (!Control::KeyPressed(VK_RETURN)) {

				}
				system("CLS");
				break;
			case 4:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				HubWorld();
				break;
			}
		}


	}
}

string Interface::Bar(float current, float maximum) {
	float blocks;
	string bar;
	blocks = maximum / 20;
	float inter = 0;

	bar.clear();
	for (int i = 0; i <= current; i++) {
		if (inter == (int)blocks * 2) {
			bar.push_back(m_FULL_BLOCK);
			inter = 0;
		}
		if (i >= current && inter != 0) {
			bar.push_back(m_HALF_BLOCK);
		}
		inter++;
	}
	return bar;
}


void Interface::SelectCreatureCombat()
{
	system("CLS");
	string input;
	string confirmCursor;
	int ptr = 0;
	int rando = 0;
	bool confirmed = false;
	bool once = false;
	confirmCursor.push_back('[');
	confirmCursor.push_back(']');
	for (int i = 0; i < 3; i++) {
		confirmCursor.push_back(' ');
	}
	while (true)
	{
		cout << "\033[H";
		if (!confirmed)
		{
			cout << "Player 1, choose your combatant: " << endl;
			Creature::PrintListeCreature();
			cout << "Enter creature name : ";
			cin >> input;
			m_player1 = Creature::GetCreature(input);
			cout << "Player 2: " << endl;
			cin >> input;
			m_player2 = Creature::GetCreature(input);
			if (m_player2 == m_player1 || m_player2 == nullptr || m_player1 == nullptr)
			{
				cout << "\nYou cannot choose same creature as player 1, please choose again" << endl << endl;
				system("CLS");
				continue;
			}
			else
			{

				confirmed = true;
			}
		}
		if (confirmed)
		{
			if (!once)
			{
				system("CLS");
				once = true;
			}
			cout << "Player 1: ";
			m_player1->PrintStats();
			cout << "Player 2: ";
			m_player2->PrintStats();
			cout << "Confirm?" << endl << confirmCursor[0] << "Yes" << confirmCursor[1] << " " << confirmCursor[2] << "No" << confirmCursor[3] << endl;
			if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr - 1 >= 0)
			{
				ptr -= 1;
				Control::Cursor(confirmCursor, ptr, 4);
			}
			if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr + 1 <= 2)
			{
				ptr += 1;
				Control::Cursor(confirmCursor, ptr, 4);
			}
			if (Control::KeyPressed(VK_RETURN))
			{
				switch (ptr)
				{
				case 0:
					PlaySound(TEXT("Go.wav"), NULL, SND_FILENAME | SND_SYNC);
					rando = rand() % 3;
					switch (rando)
					{
					case 0:
						PlaySound(TEXT("Combat 1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						break;
					case 1:
						PlaySound(TEXT("Combat 2.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						break;
					case 2:
						PlaySound(TEXT("Combat 3.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
						break;
					}
					return;
				case 1:
					confirmed = false;
					once = false;
					system("CLS");
					continue;
				}
			}
		}
	}
	system("CLS");

}

void Interface::PlayerInput()
{
	bool player1 = false;
	bool player2 = false;
	while (!player1 || !player2)
	{
		if (!player1)
		{

			if (Control::KeyPressed('A'))
			{
				s_inputPlayer[0] = 1;
				player1 = true;
			}
			if (Control::KeyPressed('W'))
			{
				s_inputPlayer[0] = 0;
				player1 = true;
			}
			if (Control::KeyPressed('D'))
			{
				s_inputPlayer[0] = 2;
				player1 = true;
			}
			if (Control::KeyPressed('S'))
			{
				s_inputPlayer[0] = 3;
				player1 = true;
			}

		}

		if (!player2)
		{

			if (Control::KeyPressed(VK_LEFT))
			{
				s_inputPlayer[1] = 1;
				player2 = true;
			}
			if (Control::KeyPressed(VK_UP))
			{
				s_inputPlayer[1] = 0;
				player2 = true;
			}
			if (Control::KeyPressed(VK_RIGHT))
			{
				s_inputPlayer[1] = 2;
				player2 = true;
			}
			if (Control::KeyPressed(VK_DOWN))
			{
				s_inputPlayer[1] = 3;
				player2 = true;
			}

		}
		
	}
}



void Interface::Combat()
{

	char y;
	int player1Sprite = 0;
	int player2Sprite = 0;
	int player1Shake1 = 2;
	int player1Shake2 = 2;
	int player2Shake1 = 2;
	int player2Shake2 = 2;
	int step = 0;
	bool shaking1 = false;
	bool shaking2 = false;
	string horizontalLine(114, HORIZONTAL_WALL);
	CreatureSprites::InitializeSprites();
	system("CLS");
	if (Creature::GetListSize() < 2 )
	{
		cout << "No creatures available for combat." << endl;
		sleep_for(seconds(3));
		return;
	}
	else {
		SelectCreatureCombat();
		if (CreatureDeFeu* feu = dynamic_cast<CreatureDeFeu*>(m_player1))
		{
			player1Sprite = 0;
		}
		//TO DO: Add other type in else if. Water is 1, plant is 2, electric is 3
		if (CreatureDeFeu* feu = dynamic_cast<CreatureDeFeu*>(m_player2))
		{
			player2Sprite = 0;
		}
		//TO DO: Add other type in else if. Water is 1, plant is 2, electric is 3
	}
	system("CLS");
	while (true)
	{
		FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
		if (m_player1->m_currentHP <= 0 || m_player2->m_currentHP <= 0) {
			system("CLS");
			PlayerWin(player1Sprite,player2Sprite);
			return;
		}
		cout << "\033[H";
		cout << CORNER_WALL_00 << horizontalLine << CORNER_WALL_X0 << endl;
		for (int i = 0; i < 31; i++)
		{
			cout << VERTICAL_WALL << left << setw(5) << " " << left << setw(player1Shake1) << " " << CreatureSprites::MonstreSprite[player1Sprite][i] << left << setw(player1Shake2) << " " << right << setw(5) <<  VERTICAL_WALL << left << setw(5) << " " << left << setw(player2Shake1) << " " << CreatureSprites::MonstreSprite[player2Sprite][i] << left << setw(player2Shake2) << " " << right << setw(4) << VERTICAL_WALL << endl;
		}

		cout << VERTICAL_WALL << "\033[32m" << right << setw(30) << Bar(m_player1->m_currentHP, m_player1->m_maxHP) << right << setw(4) << m_player1->m_currentHP << "/" << left << setw(4) << m_player1->m_maxHP << "\033[0m" << right << setw(19) << VERTICAL_WALL << "\033[32m" << right << setw(30) << Bar(m_player2->m_currentHP, m_player2->m_maxHP) << right << setw(4) << m_player2->m_currentHP << "/" << left << setw(4) << m_player2->m_maxHP << "\033[0m" << right << setw(18) << VERTICAL_WALL << endl;
		cout << VERTICAL_WALL << "\033[34m" << right << setw(30) << Bar(m_player1->m_currentMP, m_player1->m_maxMP) << right << setw(4) << m_player1->m_currentMP << "/" << left << setw(4) << m_player1->m_maxMP << "\033[0m" << right << setw(19) << VERTICAL_WALL << "\033[34m" << right << setw(30) << Bar(m_player2->m_currentMP, m_player2->m_maxMP) << right << setw(4) << m_player2->m_currentMP << "/" << left << setw(4) << m_player2->m_maxMP << "\033[0m" << right << setw(18) << VERTICAL_WALL << endl;
		cout << CORNER_WALL_0Y << horizontalLine << CORNER_WALL_XY << endl;
		cout << "Name: " << m_player1->GetName() << " VS  Name: " << m_player2->GetName() << endl;
		cout << right << setw(31) << m_player1->m_attaque[0]->GetNom() <<  setw(60) << "  " << m_player2->m_attaque[0]->GetNom() << endl;
		cout << right << setw(25) <<"W^" <<right << setw(70) << "^" << endl;
		cout << right << setw(15) << m_player1->m_attaque[1]->GetNom() << " A<--    |     -->D " << left << setw(15)<< m_player1->m_attaque[2]->GetNom() << setw(20) << "    " << right << setw(15) <<m_player2->m_attaque[1]->GetNom() << "  <--    |     -->  " << left << setw(15) << m_player2->m_attaque[2]->GetNom() << endl;
		cout << right << setw(25) << "Sv" <<right << setw(70) << "v" << endl;
		cout << right << setw(31) << m_player1->m_attaque[3]->GetNom() <<  setw(60) << "  " << m_player2->m_attaque[3]->GetNom() << endl;
		if (!shaking1 && !shaking2)
		{
			PlayerInput();
			m_player2->RecieveDamage(m_player1->CalculeDegat(m_player2, s_inputPlayer[0]));
			m_player1->RecieveDamage(m_player2->CalculeDegat(m_player1, s_inputPlayer[1]));
		}
		cout << m_player1->GetName() << " Attacks " << m_player2->GetName() << " with " << m_player1->m_attaque[s_inputPlayer[0]]->GetNom() << " for " << m_player1->CalculeDegat(m_player2, s_inputPlayer[0]) << " damage!" << endl;
		//Fix when theres a special effect(print or heal)
		if (!shaking2)
		{
			shaking1 = true;
			CombatShake(player2Shake1, player2Shake2, step);

			sleep_for(milliseconds(100));
			step++;
			if (step > 5)
			{
				step = 0;
				shaking1 = false;
			}
		}
		if (!shaking1)
		{
			shaking2 = true;
			cout << m_player2->GetName() << " Attacks " << m_player1->GetName() << " with " << m_player2->m_attaque[s_inputPlayer[1]]->GetNom() << " for " << m_player2->CalculeDegat(m_player1, s_inputPlayer[1]) << " damage!" << endl;
			CombatShake(player1Shake1, player1Shake2, step);
			sleep_for(milliseconds(100));
			step++;
			if (step > 5)
			{
				step = 0;
				shaking2 = false;
			}
		}
		if (!shaking1 && !shaking2)
		{
			cout << "Press SPACE to continue..." << endl;
			while (!Control::KeyPressed(VK_SPACE)) {

			}
			system("CLS");
		}
	}
}

void Interface::CombatShake(int& p1, int& p2, int step)
{
	switch (step) 
	{
	case 0:
		p1 = 0;
		p2 = 3;
		break;
	case 1:
		p1 = 3;
		p2 = 0;
		break;
	case 2:
		p1 = 1;
		p2 = 3;
		break;
	case 3:
		p1 = 3;
		p2 = 1;
		break;
	case 4:
		p1 = 2;
		p2 = 2;
		break;
	case 5:
		p1 = 2;
		p2 = 2;
		break;
	default:
		break;
	}

	
}

void Interface::PlayerWin(int player1, int player2)
{
	if (m_player2->m_currentHP <= 0)
	{	
		cout << R"(,-.----.                                                                                   )" << CreatureSprites::MonstreSprite[player2][0] << endl;
		cout << R"(\    /  \     ,--,                                                                ,---,    )" << CreatureSprites::MonstreSprite[player2][1] << endl;
		cout << R"(|   :    \  ,--.'|                                                             ,`--.' |    )" << CreatureSprites::MonstreSprite[player2][2] << endl;
		cout << R"(|   |  .\ : |  | :                                           __  ,-.          /    /  :    )" << CreatureSprites::MonstreSprite[player2][3] << endl;
		cout << R"(.   :  |: | :  : '                                         ,' ,'/ /|         :    |.' '    )" << CreatureSprites::MonstreSprite[player2][4] << endl;
		cout << R"(|   |   \ : |  ' |       ,--.--.          .--,     ,---.   '  | |' |         `----':  |    )" << CreatureSprites::MonstreSprite[player2][5] << endl;
		cout << R"(|   : .   / '  | |      /       \       /_ ./|    /     \  |  |   ,'            '   ' ;    )" << CreatureSprites::MonstreSprite[player2][6] << endl;
		cout << R"(;   | |`-'  |  | :     .--.  .-. |   , ' , ' :   /    /  | '  :  /              |   | |    )" << CreatureSprites::MonstreSprite[player2][7] << endl;
		cout << R"(|   | ;     '  : |__    \__\/: . .  /___/ \: |  .    ' / | |  | '               '   : ;    )" << CreatureSprites::MonstreSprite[player2][8] << endl;
		cout << R"(:   ' |     |  | '.'|   ," .--.; |   .  \  ' |  '   ;   /| ;  : |               |   | '    )" << CreatureSprites::MonstreSprite[player2][9] << endl;
		cout << R"(:   : :     ;  :    ;  /  /  ,.  |    \  ;   :  '   |  / | |  , ;               '   : |    )" << CreatureSprites::MonstreSprite[player2][10] << endl;
		cout << R"(|   | :     |  ,   /  ;  :   .'   \    \  \  ;  |   :    |  ---'                ;   |.'    )" << CreatureSprites::MonstreSprite[player2][11] << endl;
		cout << R"(`---'.|      ---`-'   |  ,     .-./     :  \  \  \   \  /                       '---'      )" << CreatureSprites::MonstreSprite[player2][12] << endl;
		cout << R"(  `---`                `--`---'          \  ' ;   `----'                                   )" << CreatureSprites::MonstreSprite[player2][13] << endl;
		cout << R"(                                          `--`                                             )" << CreatureSprites::MonstreSprite[player2][14] << endl;
		cout << R"(                                                                ,---,                      )" << CreatureSprites::MonstreSprite[player2][15] << endl;
		cout << R"(                                                             ,`--.' |                      )" << CreatureSprites::MonstreSprite[player2][16] << endl;
		cout << R"(                   .---.                                     |   :  :                      )" << CreatureSprites::MonstreSprite[player2][17] << endl;
		cout << R"(                  /. ./|   ,--,                              '   '  ;                      )" << CreatureSprites::MonstreSprite[player2][18] << endl;
		cout << R"(              .--'.  ' ; ,--.'|          ,---,               |   |  |                      )" << CreatureSprites::MonstreSprite[player2][19] << endl;
		cout << R"(             /__./ \ : | |  |,       ,-+-. /  |   .--.--.    '   :  ;                      )" << CreatureSprites::MonstreSprite[player2][20] << endl;
		cout << R"(         .--'.  '   \' . `--'_      ,--.'|'   |  /  /    '   |   |  '                      )" << CreatureSprites::MonstreSprite[player2][21] << endl;
		cout << R"(        /___/ \ |    ' ' ,' ,'|    |   |  ,"' | |  :  /`./   '   :  |                      )" << CreatureSprites::MonstreSprite[player2][22] << endl;
		cout << R"(        ;   \  \;      : '  | |    |   | /  | | |  :  ;_     ;   |  ;                      )" << CreatureSprites::MonstreSprite[player2][23] << endl;
		cout << R"(         \   ;  `      | |  | :    |   | |  | |  \  \    `.  `---'. |                      )" << CreatureSprites::MonstreSprite[player2][24] << endl;
		cout << R"(          .   \    .\  ; '  : |__  |   | |  |/    `----.   \  `--..`;                      )" << CreatureSprites::MonstreSprite[player2][25] << endl;
		cout << R"(           \   \   ' \ | |  | '.'| |   | |--'    /  /`--'  / .--,_                         )" << CreatureSprites::MonstreSprite[player2][26] << endl;
		cout << R"(            :   '  |--"  ;  :    ; |   |/       '--'.     /  |    |`.                      )" << CreatureSprites::MonstreSprite[player2][27] << endl;
		cout << R"(             \   \ ;     |  ,   /  '---'          `--'---'   `-- -`, ;                     )" << CreatureSprites::MonstreSprite[player2][28] << endl;
		cout << R"(              '---"       ---`-'                               '---`"                      )" << CreatureSprites::MonstreSprite[player2][29] << endl;
		cout << "                                                                                          " << CreatureSprites::MonstreSprite[player2][30] << endl << endl;
		cout << "Press SPACE to continue..." << endl;
		PlaySound(TEXT("Congrats.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(TEXT("Results.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		while (!Control::KeyPressed(VK_SPACE)) {

		}
		system("CLS");
		PlaySound(TEXT("Hub.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
	else if (m_player1->m_currentHP <= 0)
	{
	
		cout << R"(,-.----.                                                                                   )" << CreatureSprites::MonstreSprite[player2][0] << endl;
		cout << R"(\    /  \     ,--,                                                                 ,----,  )" << CreatureSprites::MonstreSprite[player2][1] << endl;
		cout << R"(|   :    \  ,--.'|                                                               .'   .' \ )" << CreatureSprites::MonstreSprite[player2][2] << endl;
		cout << R"(|   |  .\ : |  | :                                           __  ,-.           ,----,'    |)" << CreatureSprites::MonstreSprite[player2][3] << endl;
		cout << R"(.   :  |: | :  : '                                         ,' ,'/ /|           |    :  .  ;)" << CreatureSprites::MonstreSprite[player2][4] << endl;
		cout << R"(|   |   \ : |  ' |       ,--.--.          .--,     ,---.   '  | |' |           ;    |.'  / )" << CreatureSprites::MonstreSprite[player2][5] << endl;
		cout << R"(|   : .   / '  | |      /       \       /_ ./|    /     \  |  |   ,'           `----'/  ;  )" << CreatureSprites::MonstreSprite[player2][6] << endl;
		cout << R"(;   | |`-'  |  | :     .--.  .-. |   , ' , ' :   /    /  | '  :  /               /  ;  /   )" << CreatureSprites::MonstreSprite[player2][7] << endl;
		cout << R"(|   | ;     '  : |__    \__\/: . .  /___/ \: |  .    ' / | |  | '               ;  /  /-,  )" << CreatureSprites::MonstreSprite[player2][8] << endl;
		cout << R"(:   ' |     |  | '.'|   ," .--.; |   .  \  ' |  '   ;   /| ;  : |              /  /  /.`|  )" << CreatureSprites::MonstreSprite[player2][9] << endl;
		cout << R"(:   : :     ;  :    ;  /  /  ,.  |    \  ;   :  '   |  / | |  , ;            ./__;      :  )" << CreatureSprites::MonstreSprite[player2][10] << endl;
		cout << R"(|   | :     |  ,   /  ;  :   .'   \    \  \  ;  |   :    |  ---'             |   :    .'   )" << CreatureSprites::MonstreSprite[player2][11] << endl;
		cout << R"(`---'.|      ---`-'   |  ,     .-./     :  \  \  \   \  /                    ;   | .'      )" << CreatureSprites::MonstreSprite[player2][12] << endl;
		cout << R"(  `---`                `--`---'          \  ' ;   `----'                     `---'         )" << CreatureSprites::MonstreSprite[player2][13] << endl;
		cout << R"(                                          `--`                                             )" << CreatureSprites::MonstreSprite[player2][14] << endl;
		cout << R"(                                                                ,---,                      )" << CreatureSprites::MonstreSprite[player2][15] << endl;
		cout << R"(                                                             ,`--.' |                      )" << CreatureSprites::MonstreSprite[player2][16] << endl;
		cout << R"(                   .---.                                     |   :  :                      )" << CreatureSprites::MonstreSprite[player2][17] << endl;
		cout << R"(                  /. ./|   ,--,                              '   '  ;                      )" << CreatureSprites::MonstreSprite[player2][18] << endl;
		cout << R"(              .--'.  ' ; ,--.'|          ,---,               |   |  |                      )" << CreatureSprites::MonstreSprite[player2][19] << endl;
		cout << R"(             /__./ \ : | |  |,       ,-+-. /  |   .--.--.    '   :  ;                      )" << CreatureSprites::MonstreSprite[player2][20] << endl;
		cout << R"(         .--'.  '   \' . `--'_      ,--.'|'   |  /  /    '   |   |  '                      )" << CreatureSprites::MonstreSprite[player2][21] << endl;
		cout << R"(        /___/ \ |    ' ' ,' ,'|    |   |  ,"' | |  :  /`./   '   :  |                      )" << CreatureSprites::MonstreSprite[player2][22] << endl;
		cout << R"(        ;   \  \;      : '  | |    |   | /  | | |  :  ;_     ;   |  ;                      )" << CreatureSprites::MonstreSprite[player2][23] << endl;
		cout << R"(         \   ;  `      | |  | :    |   | |  | |  \  \    `.  `---'. |                      )" << CreatureSprites::MonstreSprite[player2][24] << endl;
		cout << R"(          .   \    .\  ; '  : |__  |   | |  |/    `----.   \  `--..`;                      )" << CreatureSprites::MonstreSprite[player2][25] << endl;
		cout << R"(           \   \   ' \ | |  | '.'| |   | |--'    /  /`--'  / .--,_                         )" << CreatureSprites::MonstreSprite[player2][26] << endl;
		cout << R"(            :   '  |--"  ;  :    ; |   |/       '--'.     /  |    |`.                      )" << CreatureSprites::MonstreSprite[player2][27] << endl;
		cout << R"(             \   \ ;     |  ,   /  '---'          `--'---'   `-- -`, ;                     )" << CreatureSprites::MonstreSprite[player2][28] << endl;
		cout << R"(              '---"       ---`-'                               '---`"                      )" << CreatureSprites::MonstreSprite[player2][29] << endl;
		cout << "                                                                                          " << CreatureSprites::MonstreSprite[player2][30] << endl << endl;
		cout << "Press SPACE to continue..." << endl;
		PlaySound(TEXT("Congrats.wav"), NULL, SND_FILENAME | SND_SYNC);
		PlaySound(TEXT("Results.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
		while (!Control::KeyPressed(VK_SPACE)) {

		}
		system("CLS");
		PlaySound(TEXT("Hub.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	}
}



void Interface::HubWorld()
{
	
	system("CLS");
	for (int y = 0; y < ROOM_HEIGHT; y++) {
		for (int x = 0; x < ROOM_WIDTH; x++) {
			if (y == 0 || y == ROOM_HEIGHT - 1) {
				g_currentRoom[x][y] = HORIZONTAL_WALL;
			}
			else if (x == 0 || x == ROOM_WIDTH - 1) {
				g_currentRoom[x][y] = VERTICAL_WALL;
			}
			else {
				g_currentRoom[x][y] = ' ';
			}
		}
	}
	g_currentRoom[0][0] = CORNER_WALL_00;
	g_currentRoom[0][ROOM_HEIGHT - 1] = CORNER_WALL_0Y;
	g_currentRoom[ROOM_WIDTH - 1][0] = CORNER_WALL_X0;
	g_currentRoom[ROOM_WIDTH - 1][ROOM_HEIGHT - 1] = CORNER_WALL_XY;
	for (int i = (ROOM_WIDTH / 2 - 4); i <= (ROOM_WIDTH / 2 + 4); i++) {
		g_currentRoom[i][0] = ' ';
	}
	g_currentRoom[50][1] = '^';
	g_currentRoom[50][2] = 192;
	g_currentRoom[51][2] = 'C';
	g_currentRoom[52][2] = 'O';
	g_currentRoom[53][2] = 'M';
	g_currentRoom[54][2] = 'B';
	g_currentRoom[55][2] = 'A';
	g_currentRoom[56][2] = 'T';


	for (int i = (ROOM_HEIGHT / 2 - 2); i <= (ROOM_HEIGHT / 2 + 2); i++) {
		g_currentRoom[0][i] = ' ';
	}
	g_currentRoom[1][10] = '<';
	g_currentRoom[2][10] = '-';
	g_currentRoom[3][10] = 'C';
	g_currentRoom[4][10] = 'R';
	g_currentRoom[5][10] = 'E';
	g_currentRoom[6][10] = 'A';
	g_currentRoom[7][10] = 'T';
	g_currentRoom[8][10] = 'U';
	g_currentRoom[9][10] = 'R';
	g_currentRoom[10][10] = 'E';
	g_currentRoom[11][10] = 'S';


	while (true) {
		sleep_for(milliseconds(0));
		cout << "\033[H";
		for (int y = 0; y < ROOM_HEIGHT; y++)
		{
			for (int x = 0; x < ROOM_WIDTH; x++)
			{
				if (x == m_player1PosX && y == m_player1PosY)
					cout << "\033[31m" << m_playerSprite << "\033[0m";
				else if (x == m_player2PosX && y == m_player2PosY)
					cout << "\033[34m" << m_playerSprite << "\033[0m";
				else
				{
					cout << g_currentRoom[x][y];
				}
			}
			cout << endl;
		}
		
		if(GetAsyncKeyState('W') && g_currentRoom[m_player1PosX][m_player1PosY - 1] == ' ')
		{
			m_player1PosY -= 1;
		}
		else if (GetAsyncKeyState('W') && m_player1PosY == 0)
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			Combat();
		}
		else if (GetAsyncKeyState('S') && g_currentRoom[m_player1PosX][m_player1PosY + 1] == ' ')
		{
			m_player1PosY += 1;
		}
		else if (GetAsyncKeyState('A') && g_currentRoom[m_player1PosX - 1][m_player1PosY] == ' ')
		{
			m_player1PosX -= 1;
		}
		else if(GetAsyncKeyState('A') &&m_player1PosX == 0)
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			if (Creature::GetListSize() == 0)
			{
				system("CLS");
				cout << "Aucune creature n'est presente, veuillez en creer une" << endl;
				CreateCreature();
			}
			else
				SelectionCreature();
		}
		else if (GetAsyncKeyState('D') && g_currentRoom[m_player1PosX + 1][m_player1PosY] == ' ')
		{
			m_player1PosX += 1;
		}
		if (GetAsyncKeyState(VK_UP) && g_currentRoom[m_player2PosX][m_player2PosY - 1] == ' ')
		{
			m_player2PosY -= 1;
		}
		else if (GetAsyncKeyState(VK_UP) && m_player2PosY == 0)
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			Combat();
		}
		else if (GetAsyncKeyState(VK_DOWN) && g_currentRoom[m_player2PosX][m_player2PosY + 1] == ' ')
		{
			m_player2PosY += 1;
		}
		else if (GetAsyncKeyState(VK_LEFT) && g_currentRoom[m_player2PosX - 1][m_player2PosY] == ' ')
		{
			m_player2PosX -= 1;
		}
		else if (GetAsyncKeyState(VK_LEFT) && m_player2PosX == 0)
		{
			FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
			if (Creature::GetListSize() == 0)
			{
				system("CLS");
				cout << "Aucune creature n'est presente, veuillez en creer une" << endl;
				CreateCreature();
			}
			else
				SelectionCreature();
		}
		else if (GetAsyncKeyState(VK_RIGHT) && g_currentRoom[m_player2PosX + 1 ][m_player2PosY] == ' ')
		{
			m_player2PosX += 1;
		}
	}
}


void Interface::LogoAndWarning()
{
	cout << "\n\n\n\n\n\033[31mWARNING: This game is best played in full screen mode, please press ALT + ENTER to switch to full screen mode. \nIt is recommanded to do it during this message and to restart the game if you miss the window it \033[0m" << endl; 
	sleep_for(seconds(6));
	system("CLS");
	PlaySound(TEXT("Small.wav"), NULL, SND_FILENAME | SND_ASYNC);
	sleep_for(milliseconds(100));
	cout << R"(         
                               -+#####+-                               
                              -#########-                              
                              +#-     -#+                              
                              ##.     -#+                              
                              ##.     +#-                              
                              +##-   -#+                               
                            -+#++-   -++#+-                            
                          -+####+-   -+####+-                          
                          +#+-           -+#+                          
                         -#+              .+#-                         
                         +#-               -#+                         
                        -#+ ---.        --- +#-                        
                       -##- ++#-       -#++ -##-                       
                       +#- -#-#-       -#-#- -#+                       
                      -#+ -##-#-       -#-##- +#-                      
                      +#--##-##         +#.##--#+                      
                     -#+ +#--#+         -#+-#+ +#-                     
                     +#- ## +#-         .## ##.-#+                     
                     +#--#+-#+    ---    +#-+#--#+                     
                     -####-+#-   -###-   -#+-####-                     
                      -++- ##    +#-#+   .## -++-                      
                           ##   -#+ +#-   ##                           
                          -#+  .+#- -#+   +#-                          
                          +#-  -#+   +#-  -#+                          
                          ##.  +#-   -#+   +#+                         
                         -#+   ##     ##.  .##                         
                         +#-  -#+     +#-  .##                         
                         ##  .+#-     -##- .##                         
                         ##  -#+       -#+  ##                         
                       -##+  +#-        ##  +##-                       
                      -##+- .##         ##. -+##                       
                      -++-.-+##         +#+..-#+                       
                      -+######-         -+#####-                       
                        -+#+-             +##+-                        )" << endl;
	sleep_for(milliseconds(333));
	system("CLS");
	cout << R"(                                                     
                    -+#+-                    
                   -#####-                   
                   +#-.-#+                   
                   ##. .##                   
                 -+#+. .+#+-                 
                -##+-. .-+##-                
               -##-       -##-               
               +#-         -#+               
              -#+---     ---+#-              
              +# +--     --+ ##-             
             -#++-+-     -+-+-#+             
             -#-#-#. --- .#-#-##             
             -###+# .+-+. #+###+             
              --.#+ .#-#- +#.++-             
                ##...###+ .##                
               -#+.-##++#-.+#-               
               +#- +#- -#+ -##               
               ##..##   ##..##               
              -#+ .##   ##..+#-              
              -++###+   +###++-              
              -+###+-   -+###+-              )" << endl;
	sleep_for(milliseconds(333));
	system("CLS");

	
	cout << R"(	      +##+               $$$$$$$$\$$\                           $$\      $$\                     )" << endl;
	cout << R"(             +####+              \__$$  __\__|                          $$$\    $$$ |                    )" << endl;
	cout << R"(             ##. ##                 $$ |  $$\ $$$$$$$\  $$\   $$\       $$$$\  $$$$ | $$$$$$\  $$$$$$$\  )" << endl;
	cout << R"(           -+#+ .+#+-               $$ |  $$ |$$  __$$\ $$ |  $$ |      $$\$$\$$ $$ | \____$$\ $$  __$$\ )" << endl;
	cout << R"(          -##+-. -+##-              $$ |  $$ |$$ |  $$ |$$ |  $$ |      $$ \$$$  $$ | $$$$$$$ |$$ |  $$ |)" << endl;
	cout << R"(         -##-      -##-             $$ |  $$ |$$ |  $$ |$$ |  $$ |      $$ |\$  /$$ |$$  __$$ |$$ |  $$ |)" << endl;
	cout << R"(         +#-..     .-#+             $$ |  $$ |$$ |  $$ |\$$$$$$$ |      $$ | \_/ $$ |\$$$$$$$ |$$ |  $$ |)" << endl;
	cout << R"(        -##...    ...+#-            \__|  \__|\__|  \__| \____$$ |      \__|     \__| \_______|\__|  \__|)" << endl;
	cout << R"(        -++-.. . ...-++-                                $$\   $$ |                                       )" << endl;
	cout << R"(        -+##-.. ...-##+-                    $$\         \$$$$$$  | $$\ $$\                               )" << endl;
	cout << R"(          +#- ..--.+#-                      $$ |         \______/  $$ |\__|                              )" << endl;
	cout << R"(          ##. .#++ -#+            $$$$$$$\$$$$$$\  $$\   $$\  $$$$$$$ |$$\  $$$$$$\                      )" << endl;
	cout << R"(         -#+..+#+#..+#-          $$  _____\_$$  _| $$ |  $$ |$$  __$$ |$$ |$$  __$$\                     )" << endl;
	cout << R"(         +#-.-##+#-.-##          \$$$$$$\   $$ |   $$ |  $$ |$$ /  $$ |$$ |$$ /  $$ |                    )" << endl;
	cout << R"(         ######--######           \____$$\  $$ |$$\$$ |  $$ |$$ |  $$ |$$ |$$ |  $$ |                    )" << endl;
	cout << R"(         -###+-  -+###-          $$$$$$$  | \$$$$  \$$$$$$  |\$$$$$$$ |$$ |\$$$$$$  |                    )" << endl;
	cout << R"(                                 \_______/   \____/ \______/  \_______|\__| \______/                     )" << endl;

	sleep_for(seconds(2));
	system("CLS");
	
}
