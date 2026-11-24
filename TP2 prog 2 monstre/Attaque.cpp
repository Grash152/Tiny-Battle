#include "Attaque.h"
#include "Creature.h"
#include <iostream>

using namespace std;

Attaque::Attaque(const std::string& nom, const float& multi, const SpecialEffect& specialBoy):
	m_nom(nom), m_multi(multi),m_specialEffect(specialBoy)
{
	//cout << "attaque ctor" << endl;
}

void Attaque::PrintAttaque() const
{
	cout << "Nom: " << m_nom << endl;
	cout << "Degat: " << m_multi << endl;
	cout << "Effet Speciale: " << PrintEffet() << endl;
}

string Attaque::PrintEffet() const 
{
	switch (m_specialEffect)
	{
	case SpecialEffect::loser:
		return "No Effect";
		break;
	case SpecialEffect::heal:
		return "Heal";
		break;
	case SpecialEffect::assassinate:
		return "Assassinate";
		break;
	case SpecialEffect::stun:
		return "Stun";
		break;
	case SpecialEffect::burn:
		return "Burn";
		break;
	default:
		break;
	}

}

void Attaque::AttEffect(Creature& perso, Creature& ennemie) //chaque effet est unique
{															//TODO enleve les chiffre magique 
	switch (m_specialEffect)
	{
	case SpecialEffect::heal:
		if (perso.m_currentMP >= 5)
		{
			perso.m_currentHP += perso.GetInt()*5;
			cout << perso.GetName() << "a ete soigner de " << perso.GetInt() * 5 << endl;
			perso.m_currentMP -= 5;
		}
		
		break;
	case SpecialEffect::assassinate:
		if (ennemie.m_currentHP < ennemie.m_maxHP / 3)
		{
			ennemie.m_currentHP = 0;
		}
		cout << ennemie.GetName() << " a ete assassiner " << endl;
		break;
	case SpecialEffect::stun:
		if(rand()%2)
		{
			//work in progress
		}
		break;
	case SpecialEffect::burn:
		//work in progress
		break;
	default:
		break;
	}
}
