#pragma once

#include "Avion.h"

#include <iostream>
#include <string>

using namespace std;

class VojniAvion: public Avion
{
private:
	int stepenNaoruzanja;
public:
	VojniAvion();
	VojniAvion(int brPutnikaa,int osobljee,float prtljaznikk,float terett,string oznakaa,const char* klasaa,int stepenNaoruzanja);

	void ispisi();

	void deklarisiStepen(int stepen);

	int getStepenNaoruzanja();
};