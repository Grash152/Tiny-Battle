#pragma once
#include <string>
#include "Creature.h"
#include <vector>
class CreatureDeFeu : public Creature
{
private:
	const std::string type = "\033[31mFeu\033[0m";
public:
	static std::vector<Attaque*> s_listAttaque;

	//----------------( ctor,dtor )------------------------------------------|
	CreatureDeFeu(const std::string& nom, const int& pv, const int& att, const int& def, const int& spe, const int& mp);
	CreatureDeFeu();
	~CreatureDeFeu() override;

	//----------------( override de Creature )-------------------------------|
	void PrintStats() const override;
	void PrintAttaqueChoice() const override;
	void SetAttaqueCreature() override;
	Attaque* GetAttaque(std::string byName) override;
	Attaque* GetAttaque(int byNumber) override;
	int CalculeDegat(Creature* ennemie,int attaque) override;
	void PrintCreatureAttaque() const;
};

