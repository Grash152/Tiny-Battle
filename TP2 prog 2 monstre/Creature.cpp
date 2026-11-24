#include "Creature.h" 
#include <iostream>
#include <cstdlib>
#include <list>
#include <Windows.h>
#include "Control.h"
#include <iomanip>
#include <chrono>
#include <thread>
#include <fstream>
using namespace std;
using namespace this_thread;
using namespace chrono;


list<Creature*> Creature::s_listeCreature;
int Creature::s_ID = 0;

void Creature::SetName(std::string name)
{
	m_name = name;
}

std::string Creature::GetName()
{
	return m_name;
}

int Creature::GetPV()
{	return m_pv;	}

int Creature::GetAtt()
{	return m_att;	}

int Creature::GetDef()
{	return m_def;	}

int Creature::GetInt()
{	return m_int;	}

int Creature::GetMP()
{	return m_mp;	}

int Creature::GetSID()
{
	return s_ID;
}

int Creature::GetListSize()
{
	return s_listeCreature.size();
}
int Creature::GetuID()
{
	return m_uID;
}

Creature::~Creature()
{
	cout << "dtor creature" << endl;
}

Creature::Creature(const string& nom, const int& pv, const int& att, const int& def,const int& spe, const int& mp):
	m_name(nom),m_pv(pv),m_att(att),m_def(def),m_int(spe),m_mp(mp), m_uID(s_ID++)
{
	s_listeCreature.push_back(this);

}
Creature::Creature():m_uID(s_ID++)
{
	cout << "Entrer le nom de la creature: " << endl;
	cin >> m_name;
	this->InputStats();
	s_listeCreature.push_back(this);

}

void Creature::InputStats()
{
	system("CLS");
	string cursorStats;
	int ptr = 0;
	cursorStats.push_back('[');
	cursorStats.push_back(']');
	for (int i = 0;i < 8;i++) 
	{
		cursorStats.push_back(' ');
	}
	int statTotal = 0;
	while (true)
	{
		sleep_for(milliseconds(50));
		cout << "\033[H";
		cout << "Les creatures peuvent avoir un maximum de 150 point distribuer avec minimum un point par stat" << endl;
		cout << cursorStats[0] << left << setw(12) << "PV" << cursorStats[1] << " : " << m_pv << endl;
		cout << cursorStats[2] << left << setw(12) << "Attaque" << cursorStats[3] << " : " << m_att << endl;
		cout << cursorStats[4] << left << setw(12) << "Defense" << cursorStats[5] << " : " << m_def << endl;
		cout << cursorStats[6] << left << setw(12) << "Intelligence" << cursorStats[7] << " : " << m_int << endl;
		cout << cursorStats[8] << left << setw(12) << "MP" << cursorStats[9] << " : " << m_mp << endl;

		if ((Control::KeyPressed('W') || Control::KeyPressed(VK_UP)) && ptr - 1 >= 0)
		{
			ptr -= 1;
			Control::Cursor(cursorStats, ptr, cursorStats.size());
		}
		if ((Control::KeyPressed('S') || Control::KeyPressed(VK_DOWN)) && ptr + 1 <= 4)
		{
			ptr += 1;
			Control::Cursor(cursorStats, ptr, cursorStats.size());
		}

		if ((GetAsyncKeyState('A') || GetAsyncKeyState(VK_LEFT)) && statTotal>5)
		{
			switch (ptr)
			{
			case 0:
				if(m_pv >=2)
					m_pv--;
				break;
			case 1:
				if (m_att >= 2)
					m_att--;
				break;
			case 2:
				if (m_def >= 2)
					m_def--;
				break;
			case 3:
				if (m_int >= 2)
					m_int--;
				break;
			case 4:
				if (m_mp >= 2)
					m_mp--;
				break;
			}
		}
		if ((GetAsyncKeyState('D') || GetAsyncKeyState(VK_RIGHT)) && statTotal < 150)
		{
			switch (ptr)
			{
			case 0:
				m_pv++;
				break;
			case 1:
				m_att++;
				break;
			case 2:
				m_def++;
				break;
			case 3:
				m_int++;
				break;
			case 4:
				m_mp++;
				break;
			}
		}

		statTotal = m_pv + m_att + m_def + m_int + m_mp;
		if (Control::KeyPressed(VK_RETURN))
		{
			if (statTotal == 150)
				return;
			else
			{
				system("CLS");
				cout << "Veuillez entrer 150 stats";
				sleep_for(seconds(2));
			}
		}

	}
}

Creature* Creature::GetCreature(int selection)
{
	auto current = s_listeCreature.begin();
	for (int i = 0; i < s_listeCreature.size(); i++)
	{
		if (selection == current._Ptr->_Myval->m_uID)
		{
			return current._Ptr->_Myval;
		}
		current++;
	}
	return nullptr;
}

Creature* Creature::GetCreature(string selection) //va chercher la valeur via un string donner 
{													
	auto current = s_listeCreature.begin();
	for (int i = 0; i < s_listeCreature.size(); i++)
	{
		if (selection == current._Ptr->_Myval->m_name)
		{
			return current._Ptr->_Myval;
		}
		current++;
	}
	return nullptr;
}



void Creature::ModifierCreature(Creature* modif)
{
	modif->PrintStats();
	int  ptr = 0;
	int  ptr2 = 0;
	string modifCursor;
	string confirmCursor;
	modifCursor.push_back('[');
	modifCursor.push_back(']');
	confirmCursor.push_back('[');
	confirmCursor.push_back(']');
	bool spacePressed = false;
	bool clearOnce = false;
	for (int i = 0; i < 4; i++) {
		modifCursor.push_back(' ');
	}
	for (int i = 0; i < 2; i++) {
		confirmCursor.push_back(' ');
	}
	string newName;
	system("CLS");
	while (true)
	{
		cout << "\033[H";
		cout << "What do you want to modify: \n\n" << modifCursor[0] <<"Name"<< modifCursor[1]<< " " << modifCursor[2] << "Stats" << modifCursor[3] << " " << modifCursor[4] << "Attaques" << modifCursor[5] << endl;
		if (!spacePressed)
		{

			if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr - 1 >= 0)
			{
				ptr -= 1;
				Control::Cursor(modifCursor, ptr, modifCursor.size());
			}
			if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr + 1 <= 3)
			{
				ptr += 1;
				Control::Cursor(modifCursor, ptr, modifCursor.size());
			}
		}
		if (Control::KeyPressed(VK_RETURN)||spacePressed)
		{
			spacePressed = true;
			switch (ptr)
			{
			case 0:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "What do you want it to be?" << endl;
				cin >> newName;
				while (true)
				{ 
					if (!clearOnce)
					{
						system("CLS");
						clearOnce = true;
					}
					cout << "\033[H";
					cout << "Current name : " << modif->GetName() << " to New name: " << newName << " . Confirm?" << endl << confirmCursor[0] << "Yes" << confirmCursor[1] << "" << confirmCursor[2] << "No" << confirmCursor[3] << endl;

					if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr2 - 1 >= 0)
					{
						ptr2 -= 1;
						Control::Cursor(confirmCursor, ptr2, confirmCursor.size());
					}
					if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr2 + 1 <= 1)
					{
						ptr2 += 1;
						Control::Cursor(confirmCursor, ptr2, confirmCursor.size());
					}
					if (Control::KeyPressed(VK_RETURN))
					{
						switch (ptr2)
						{
						case 0:
							modif->SetName(newName);
							return;
						case 1:
							break;
						}
						break;
					}
				}
				return;
			case 1:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				modif->InputStats();
				return;
			case 2:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				modif->SetAttaqueCreature();
				return;
			}
		}
	}
	system("CLS");

}

void Creature::SuprimeCreature(Creature* del)
{
	auto current = s_listeCreature.begin();
	for (int i = 0; i < s_listeCreature.size(); i++)
	{
		if (del->m_uID == current._Ptr->_Myval->m_uID)
		{
			s_listeCreature.erase(current);
			delete del;
			return;
		}
		current++;
	}
}


void Creature::PrintStats() const
{
	cout << endl <<"     Nom: " << "\033[0m" << m_name << "\033[0m" << endl;
	cout << "          Pv: " << "\033[32m" << m_pv << "\033[0m" << endl;
	cout << "     Attaque: " << "\033[31m" << m_att << "\033[0m" << endl;
	cout << "     Defense: " << "\033[34m" << m_def << "\033[0m" << endl;
	cout << "Intelligence: " << "\033[33m" << m_int << "\033[0m" << endl;
	cout << "       Magie: " << "\033[35m" << m_mp << "\033[0m" << endl;

}
void Creature::PrintListeCreature()
{

	auto current = s_listeCreature.begin();
	for (int i = 0; i < s_listeCreature.size(); i++)
	{
		current._Ptr->_Myval->PrintStats();
		current++;
	}
}

int Creature::CalculeDegat(Creature* ennemie, int attaque)
{
	int degat = GetAtt() * m_attaque[attaque]->m_multi * (100.f / (100.f + ennemie->GetDef()));
	m_attaque[attaque]->AttEffect(*this, *ennemie); //effet de l'attaque
	return degat;
}

void Creature::RecieveDamage(int Degat)
{
	m_currentHP -= Degat;
}


