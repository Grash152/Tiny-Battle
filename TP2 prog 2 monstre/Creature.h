#pragma once
#include <string>
#include <list>
#include "Attaque.h"
class Creature // Classe abstraite
{
private:
	static std::list<Creature*> s_listeCreature;
	static int s_ID;	
	int m_uID;
	
	//---------------( stats )------------------------------------------------|
private:
	std::string m_name;
	int m_pv = 1;
	int m_att = 1;
	int m_def = 1;
	int m_int = 1;
	int m_mp = 1;
public: 
	void SetName(std::string name);
	std::string GetName();
	int GetPV();
	int GetAtt();
	int GetDef();
	int GetInt();
	int GetMP();
	static int GetSID();
	static int GetListSize();

	int GetuID();
	
	//--------------( stats de combats )-------------------------------------|
	const int m_maxHP = m_pv * 5;
	int m_currentHP = m_maxHP;
	const int m_maxMP = m_mp * 2;
	int m_currentMP = m_maxMP;
	int m_currentBlock = 0; //voir si on implemente 
	Attaque* m_attaque[4];

public:
	//----------------( ctor,dtor )-----------------------------------------|
	virtual ~Creature();	
	Creature(const std::string& nom,const int& pv,const int& att,const int& def,const int& spe, const int& mp);
	Creature();

	//----------------( Manipulation des Creature )-------------------------|
private:	
	void InputStats();
	
public:
	
	static Creature* GetCreature(int byID);
	static Creature* GetCreature( std::string byName);
	static void ModifierCreature(Creature* modif); //TIPs Combo avec GetCreature
	static void SuprimeCreature(Creature* del);
	virtual void SetAttaqueCreature()=0;
	virtual Attaque* GetAttaque(std::string byName) = 0;
	virtual Attaque* GetAttaque(int byNumber) = 0;
	//---------------( print )----------------------------------------------|
	virtual void PrintStats() const;
	static void PrintListeCreature();

	virtual void PrintAttaqueChoice() const = 0;
	virtual int CalculeDegat(Creature* ennemie,int attaque);
	virtual void RecieveDamage(int Degat);
};


