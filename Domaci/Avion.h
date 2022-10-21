//klasa za avione
#pragma once
#include<iostream>
#include<string>


using namespace std; //zbog stringa



class Avion{
private:
	int brPutnika,osoblje;
	mutable float prtljaznik;
	float teret; //prtljaznik je za tezinu kofera i svega sto su putnici poneli
	//teret je za pakete i ostale stvari sto se transportuju
	string oznaka;
	string klasa;
	static int brojac;
public:
	Avion(); //ukoliko je prazan konstruktor avion se pravi

	Avion(int brPutnika,int osoblje,float prtljaznik,float teret,string oznaka,string klasa); //u zavisnosti od klase ce se stavljati broj putnika na nulu ili na neki drugi broj
	//klasa moze biti putnicki, teretni, privatni, takodje ce i varirati broj osoblja na avionu

	void poleti()const; //javlja da je avion poleteo
	void sleti()const; //javlja da je avion sleteo

	void virtual ispisi();

	int UkupanBrojLjudi() const volatile;

	float UkupnaTezinaTereta() const volatile;

	void setKlasa(string klasica);

	static int BrojAviona();

	void setBrojPutnika(int broj);

	void setPrtljaznik(float prtljag)const;

	float getPrtljaznik();

	string getOznaka();
	string getKlasa();
};