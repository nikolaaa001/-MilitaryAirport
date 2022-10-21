#include "VojniAvion.h"

#include <iostream>
#include <string>

using namespace std;

VojniAvion::VojniAvion():Avion()
{
	stepenNaoruzanja=0;
}

//konstruktor za avion
VojniAvion::VojniAvion(int brPutnikaa,int osobljee,float prtljaznikk,float terett,string oznakaa,const char* klasaa,int stepenNaoruzanjaa):Avion(brPutnikaa,osobljee,prtljaznikk,terett,oznakaa,klasaa),stepenNaoruzanja(stepenNaoruzanjaa){ Avion::setKlasa("MIG29-vojni");} //probati da li ce prihvatiti klasu zbog naseg uslova


void VojniAvion::ispisi()
{
	Avion::ispisi();
	cout<<"Stepen naoruzanja je: "<<stepenNaoruzanja<<endl<<endl;
}

void VojniAvion::deklarisiStepen(int stepen)
{
	stepenNaoruzanja=stepen;
}

int VojniAvion::getStepenNaoruzanja()
{
	return stepenNaoruzanja;
}