#include "Avion.h"
#include "VojniAvion.h"


#include<iostream>
#include<string>
#include<array>
#include<stack>
#include<queue>
#include<fstream>

//NAPOMENA: PROVERI DA LI CE RADITI KOD ZBOG ; ISPRED USING NAMESPASE STD
using namespace std;
static int brojac=0;

template <class T>

//racunanje ukupne tezine, razlika itd
class Tezina
{
private:
	T prva,druga;
public:
	Tezina(T b1, T b2){
		prva=b1;
		druga=b2;
	}
	void PrikaziRezultat(){
		cout << "Tezina : " << prva << " i " << druga << endl;
		cout << prva << " + " << druga << " = " << saberi() << endl;
		cout << prva << " - " << druga << " = " << oduzmi() << endl;
		cout << prva << " / " << druga << " = " << podeli() << endl;
		cout << prva << " * " << druga << " = " << pomnozi() << endl;
	}

	T saberi(){
		return prva+druga;
	}
	T oduzmi(){
		return prva-druga;
	}
	T podeli(){
		return prva/druga;
	}
	T pomnozi(){
		return prva*druga;
	}

};

/*int poredi(const void *a, const void *b){
	return static_cast<int>((*(Musterija*)a).GetBudzet()  - (*(Musterija*)b).GetBudzet() );  
};*/

int funkcijaUporediStepen(const void *a,const void *b)
{
	//bool myfunction (int i,int j) { return (i<j); }
	return static_cast<int>((*(VojniAvion*)a).getStepenNaoruzanja()  - (*(VojniAvion*)b).getStepenNaoruzanja());
};
  
int main()
{
	
	ofstream pokret;
	float prtljag;

	string klasa;
	string oznaka;

    //ako je prazan konstruktor u terminalu ce nam javiti da je avion u izgradi, takodje imam povezane funkcije avion i vojni avion
	Avion avioncic;
	VojniAvion avioncad;

	//ARRAY od nekoliko aviona

	array<Avion, 2> avioni={Avion(30,6,100,2500,"BOING-747","civilni teretni"),Avion(120,12,340,200,"SAB-340","putnicki")}; 
	VojniAvion vojniAvioni[3]={VojniAvion(0,10,100,1200,"An-26","vojni teretni",1),VojniAvion(0,2,20,0,"MIG-29","vojni lovacki",4),VojniAvion(0,2,20,0,"MIG-20","vojni lovacki",2)};

	///*/*Menjanje tezine prtljaga preko mutatora i const metode*/*/
	//void setPrtljaznik(float prtljag);

	cout<<".............PROMENA TEZINE PRTLJAGA............."<<endl;

	for(auto it = avioni.begin(); it!=avioni.end();it++){
		cout<<"Za avion-> ";(it)->ispisi();
		cout << "Unesite novu tezinu prtljaga" << endl;
		cin >> prtljag;
		(it)->setPrtljaznik(prtljag);

	}
	cout << "Nove tezine prtljaga po avionima su: ";
	for(auto it=avioni.begin();it!=avioni.end();it++){
		
		cout <<(it)->getPrtljaznik();
		cout<<", ";
		
	}
	cout << endl<<endl;

	//koriscenje pair da bi se napravila lista s vise razlicitih objekata

	cout<<".............PAIR VOJNI AVION I AVION............."<<endl;

	pair<VojniAvion, Avion>niz(VojniAvion(0,2,20,0,"MIG-29","vojni lovacki",4),Avion(120,12,340,200,"SAB-340","putnicki"));
	niz.first.ispisi();
	niz.second.ispisi();
	cout<<endl;

	///*/*Koriscenje stacka*/*/



	stack<Avion>Hangar;
	cout << ".............VOJNI HANGAR AEORODROMA............."<< endl;
	
	Hangar.push(niz.first);
	Hangar.push(vojniAvioni[0]);
	Hangar.push(vojniAvioni[1]);

	cout<<endl<<endl;

		cout << "U HANGARU su avioni: " << endl;
		Hangar.top().ispisi();
		cout<<".........................."<<endl;
		Hangar.pop();

		Hangar.top().ispisi();
		cout<<".........................."<<endl;
		Hangar.pop();

		Hangar.top().ispisi();
		cout<<".........................."<<endl;
		Hangar.pop();

	cout<<endl<<endl;

	//Queue biblioteka,redovi


	cout << ".............QUEUE BIBLIOTEKA............."<< endl;
		queue<Avion>noviAvioni;
		cout << "NAPRAVITE NOVI AVION: " << endl;
		for(int i=0;i<1/*3*/;i++){
			cout<<"NOVA OZNAKA: ";
			cin >> oznaka;

			cin.ignore();
			cout<<"\nA KLASA JE :";
			cin>>klasa;
			
			Avion novi(0,0,0,0,oznaka, klasa);
			noviAvioni.push(novi);	
		}
		cout<<"UNELI STE: "<<endl;
		int i=0;
		while(!noviAvioni.empty()){
			noviAvioni.front().ispisi();
			noviAvioni.pop();
			i++;
		}

	//qsort sortiranje vojnih aviona po stepenu naoruzanja, rastuci

		VojniAvion vojniNiz[3]={VojniAvion(0,2,20,0,"MIG-29","vojni lovacki",4),VojniAvion(0,2,20,0,"MIG-25","vojni lovacki",3),};
	
	cout<<".............VOJNI AVIONI PO STEPENU NAORUZANJA............."<<endl;
	qsort(vojniAvioni,sizeof(vojniAvioni)/sizeof(vojniAvioni),sizeof(vojniAvioni), funkcijaUporediStepen);
		
	for(int i=0;i<2;i++)
			vojniAvioni[i].ispisi();
		cout << endl;


		///*/*Ispis u datoteku*/*/
		pokret.open("Hangar.txt");
		if(pokret== NULL){
			cout << "ERROR: Otvaranje datoteke neuspesno." << endl;
			exit(1);
		}

		for(int i=0; i<avioni.size(); i++){
			pokret<<"Obicni avion: "<<endl;
			pokret << "Oznaka: " << avioni[i].getOznaka() << ", ";
			pokret << "Klase: " << avioni[i].getOznaka() << ", ";
			pokret<<"\n\n";
		}

		for(int i=0; i<2; i++){
			pokret<<"Vojni avion: "<<endl;
			pokret << "Oznaka: " << vojniAvioni[i].getOznaka() << ", ";
			pokret << "Klase: " << vojniAvioni[i].getOznaka() << ", ";
		}
		pokret.close();


	///*/*/*Koriscenje Templatea*/*/*/

		Tezina<int> tezine(280,300);
		Tezina<float>tezine2(235.48,78.99);

		tezine.PrikaziRezultat();
		tezine2.PrikaziRezultat();
		
	

	cout<<".............REGISTROVANI AVIONI............."<<endl<<endl;

	cout<<"Ukupan broj regisrovanih aviona je = "<<Avion::BrojAviona(); //stasticka funkcija


	cout<<endl<<endl;

	system("pause");
    return 0;
}