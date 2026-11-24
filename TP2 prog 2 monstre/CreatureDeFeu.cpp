#include "CreatureDeFeu.h"
#include <iostream>
#include "Interface.h"
#include "Control.h"
#include <Windows.h>

using namespace std;


vector<Attaque*> CreatureDeFeu::s_listAttaque = 
{ 
	{new Attaque("Fire Slash", 1.1, SpecialEffect::loser) },
	{new Attaque("Beam Attack",0.1,SpecialEffect::assassinate)},
	{new Attaque("Phoenix Ashes",0.0f,SpecialEffect::heal)},
	{new Attaque("Flamethrower", 0.8f,SpecialEffect::burn)}
};

CreatureDeFeu::CreatureDeFeu(const std::string& nom, const int& pv, const int& att, const int& def, const int& spe, const int& mp):
	Creature(nom, pv, att, def,spe,mp)
{
	this->SetAttaqueCreature();
	
}

CreatureDeFeu::CreatureDeFeu() :Creature()
{
	this->SetAttaqueCreature();
	
}

CreatureDeFeu::~CreatureDeFeu()
{
	cout << "Type: Feu dtor" << endl;
}

void CreatureDeFeu::PrintStats() const
{
	Creature::PrintStats();
	cout << "        Type: " << type << endl << endl;
	PrintCreatureAttaque();
}

void CreatureDeFeu::PrintAttaqueChoice() const
{
	for (int i = 0; i < s_listAttaque.size();i++)
	{
		cout << "Chois " << i + 1 << " :\n";
		s_listAttaque.at(i)->PrintAttaque();
		cout << endl;
	}
}

void CreatureDeFeu::SetAttaqueCreature()
{
	
	system("CLS");
	string cursor;
	cursor.push_back('[');
	cursor.push_back(']');
	for (int i = 0; i < 2; i++)
	{
		cursor.push_back(' ');
	}
	int ptr = 0;
	while (true)
	{
		cout << "\033[H";
		cout << "Do you want to randomize attacks?" << endl << cursor[0] << "Yes" << cursor[1] << " " << cursor[2] << "No" << cursor[3] << endl;
		if ((Control::KeyPressed('A') || Control::KeyPressed(VK_LEFT)) && ptr - 1 >= 0)
		{
			ptr -= 1;
			Control::Cursor(cursor, ptr, 4);
		}
		if ((Control::KeyPressed('D') || Control::KeyPressed(VK_RIGHT)) && ptr + 1 <= 1)
		{
			ptr += 1;
			Control::Cursor(cursor, ptr, 4);
		}
		if (Control::KeyPressed(VK_RETURN))
		{
			switch (ptr)
			{
			case 0:
				for (int i = 0; i < size(m_attaque); i++)
				{
					m_attaque[i] = GetAttaque(rand() % s_listAttaque.size());
					for (int j = 0; j < i; j++)
					{
						if (m_attaque[i] == m_attaque[j] && i != j)
						{
							m_attaque[i] = GetAttaque(rand() % s_listAttaque.size());
							j = -1;
							continue;
						}
					}
				}
				return;
			case 1:
				FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
				cout << "Choose 4 attacks for the creature: " << endl << endl;
				PrintAttaqueChoice();
				for (int i = 0; i < size(m_attaque); i++)
				{
					cout << "\n\nEnter attack " << i + 1 << " : ";
					cin >> ptr;
					m_attaque[i] = GetAttaque(ptr - 1);
					for (int j = 0; j < i; j++)
					{
						if (m_attaque[i] == m_attaque[j] && i != j)
						{
							cout << "cette attaque est deja choisi prendre une autre" << endl;
							cin >> ptr;
							m_attaque[i] = GetAttaque(ptr - 1);
							j--;
							continue;
						}
					}

				}
			}
			return;
		}
	}
}

Attaque* CreatureDeFeu::GetAttaque(string selected)
{
	for (int i = 0; i < s_listAttaque.size(); i++)
	{
		if (s_listAttaque.at(i)->m_nom == selected)
		{
			return s_listAttaque.at(i);
		}
	}
	return nullptr;
}

Attaque* CreatureDeFeu::GetAttaque(int selected)
{
	for (int i = 0; i < s_listAttaque.size(); i++)
	{
		if (i == selected)
		{
			return s_listAttaque.at(i);
		}
	}
	return nullptr;
}

int CreatureDeFeu::CalculeDegat(Creature* ennemie,int attaque)
{
	int degat = GetAtt() * m_attaque[attaque]->m_multi * (100.f / (100.f + ennemie->GetDef()));
	m_attaque[attaque]->AttEffect(*this, *ennemie); //effet de l'attaque
	degat *= 1.2; 
	return degat;
}

void CreatureDeFeu::PrintCreatureAttaque() const
{
	for (int i = 0; i < size(m_attaque); i++)
	{
		m_attaque[i]->PrintAttaque();
		cout << endl;
	}
}




