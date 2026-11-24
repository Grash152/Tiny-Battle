#pragma once
#include <string>
#include <vector>
#include "SpecialEffect.h"
class Creature;
class CreatureDeFeu;
class Attaque
{
	friend Creature;
	friend CreatureDeFeu;
private:
	std::string m_nom;
	float m_multi;

	//-----------------------------------( special effect )-------------------------------|
	SpecialEffect m_specialEffect;
	std::string PrintEffet() const;
	void AttEffect(Creature& perso,Creature& ennemie);

	Attaque(const std::string& nom, const float& multi, const SpecialEffect& specialBoy);
	void PrintAttaque() const;
public:
	std::string GetNom() const { return m_nom; }
};

