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
#include <vector>
bool Control::m_lastKeyState[256] = { false };

bool Control::KeyPressed(int key)
{
	bool down = (GetAsyncKeyState(key) < 0) != 0;
	bool wasDown = m_lastKeyState[key];

	m_lastKeyState[key] = down;

	return (down && !wasDown);
}
void Control::Cursor(std::string& cursor, int ptr, const int taille)
{
	if (ptr < 0 || ptr >= taille)
	{
		return;
	}
	for (int i = 0; i < taille; i++)
	{
		cursor[i] = ' ';
	}
	cursor[ptr * 2] = '[';
	cursor[ptr * 2 + 1] = ']';
}