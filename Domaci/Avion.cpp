#include "Avion.h"
#include "VojniAvion.h"

#include<iostream>
#include<string>


using namespace std;

int Avion::brojac=0;


Avion::Avion()
{
	brojac++;
	cout<<"AVION JE U IZDRADI..."<<endl<<endl;
	brPutnika=0;
	osoblje=0;
	prtljaznik=0;
	teret=0;
	oznaka="";
	klasa="";

	
}

Avion::Avion(int brPutnika,int osoblje,float prtljaznik,float teret,string oznaka,string klasa)
{
	
	this->brPutnika=brPutnika;
	this->osoblje=osoblje;
	this->prtljaznik=prtljaznik;
	this->teret=teret;
	this->oznaka=oznaka;
	this->klasa=klasa;

	brojac++;

	//int izaberi=0,izaberi2=0;


	////ukoliko se unese pogresna klasa

	//if(strcmp(klasa,"putnicki")==0 || strcmp(klasa,"teretni")==0 || strcmp(klasa,"privatni")==0)
	//{
	//} //gledamo da li smo mozda definisali vojni avion kao obican avion
	//else if(strcmp(klasa,"MIG29-vojni")==0)
	//{}
	//else
	//	do
	//	{
	//		cout<<"Uneta klasa ne odgovara ni jednoj, molimo unesite ponovo kojoj klasi pripada avion: "<<endl;
	//		cout<<"(1) putnicki, (2) teretni, (3) privatni"<<endl;
	//		cout<<"BROJ: ";
	//		cin>>izaberi;
	//		switch (izaberi)
	//		{
	//		case 1:
	//			klasa="putnicki";
	//			break;
	//		case 2:
	//			klasa="teretni";
	//			break;
	//		case 3:
	//			klasa="privatni";
	//			break;
	//		default:
	//			break;
	//		}
	//	}while(izaberi<1 || izaberi>3);



	
}

void Avion::ispisi()
{
	cout<<"Avion:"<<endl;
	cout<<"Oznake: "<<oznaka;
	cout<<" ; Klase: "<<klasa;
	cout<<" ; Broj ljudi: "<<UkupanBrojLjudi();
	cout<<" ; Ukupna tezina tereta (kg): "<<UkupnaTezinaTereta();
	cout<<endl<<endl;
}

int Avion::UkupanBrojLjudi() const volatile
{
	return brPutnika+osoblje;
}

float Avion::UkupnaTezinaTereta() const volatile
{
	return prtljaznik+teret;
}

void Avion::poleti()const
{
	cout<<"Avion oznake: "<<oznaka<<" je uspesno poleteo"<<endl;
}

void Avion::sleti()const
{
	cout<<"Avion oznake: "<<oznaka<<" je uspresno sleteo"<<endl;
}

void Avion::setKlasa(string klasica)
{
	klasa=klasica;
}
int Avion::BrojAviona(){return brojac;}

void Avion::setBrojPutnika(int broj)
{
	brPutnika=broj;
}

void Avion::setPrtljaznik(float prtljag)const
{
	//boja=novaBoja;
	//return boja;
	prtljaznik=prtljag;
}

float Avion::getPrtljaznik(){return prtljaznik;}
/*
	void getOznaka();
	void getKlasa();*/

string Avion::getKlasa(){return klasa;}

string Avion::getOznaka(){return oznaka;}