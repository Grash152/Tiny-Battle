#include <iostream>
#include "Creature.h"
#include "CreatureDeFeu.h"
#include <cstdlib>
#include "main.h"
#include <iomanip>
#include <Windows.h>
#include "Interface.h"
#include "Control.h"
#include <fstream>

using namespace std;

Interface g_interface;


int main()
{
	Init();
	Interface::LogoAndWarning();
	Interface::MainMenu();
	return 0;
}

void Init() 
{
	HANDLE hStdOut = NULL;
	CONSOLE_CURSOR_INFO curInfo;

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	
	GetConsoleCursorInfo(hStdOut, &curInfo);
	curInfo.bVisible = FALSE;
	SetConsoleCursorInfo(hStdOut, &curInfo);
	const DWORD dwVolume = (DWORD)(0xFFFF * (20.0f));
	const MMRESULT result = waveOutSetVolume((HWAVEOUT)0, 
		MAKELONG(dwVolume, dwVolume));
	PlaySound(NULL, 0, 0);
	srand(time(NULL));
}


