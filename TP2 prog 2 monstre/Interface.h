#pragma once
#include <string>
#include "Creature.h"
class Interface
{
private:
	static int short s_inputPlayer[2];
	static const char m_FULL_BLOCK = 219;
	static const char m_HALF_BLOCK = 221;
	static const char VERTICAL_WALL = 186;
	static const char HORIZONTAL_WALL = 205;
	static const char CORNER_WALL_00 = 201;
	static const char CORNER_WALL_0Y = 200;
	static const char CORNER_WALL_X0 = 187;
	static const char CORNER_WALL_XY = 188;
	static const unsigned int ROOM_WIDTH = 90;
	static const unsigned int ROOM_HEIGHT = 26;
	static int m_player1PosX;
	static int m_player1PosY;
	static int m_player2PosX;
	static int m_player2PosY;
	static const char m_playerSprite = 219;
	static char g_currentRoom[ROOM_WIDTH][ROOM_HEIGHT];
public:
	static void MainMenu();
	static void CreateCreature();
	static void CreateRandomCreature();//TODO mettre priver
	static void SelectionCreature(); 
	static std::string Bar(float current, float maximum);


	//-----------------------------------------------------( affichage en combat )-----|
	static Creature* m_player1;
	static Creature* m_player2;
	static void SelectCreatureCombat();
	
	//-----------------------------------------------------( logique Combat )----------|
	static void PlayerInput();
	static void LogoAndWarning();
	static void Combat();
	static void CombatShake(int& p1, int& p2, int step);
	static void PlayerWin(int player1, int player2);
	static void HubWorld();
	
};

