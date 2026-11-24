#pragma once

class Control
{

	
public:
	static bool m_lastKeyState[256];
	static bool KeyPressed(int key);
	static void Cursor(std::string& cursor, int ptr, const int taille);
	
};

