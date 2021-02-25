//comentariile sunt pe liniile 48, 378, 568, 1718, 1988

#include<iostream>
#include<string>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>
#include <set>
#include <map>

using namespace std; 

class Produs {
private:
	char* categorie;
	string denumire;
	float cantitate;
	float pret;
	int nrRating;
	int* rating;
	int cumparariLunare[12];
	const float TVA;
	static int id;

public:

	//constructori
	Produs() : TVA(0.19) {
		cout << "Apel constructor fara parametri" << endl;
		this->categorie = new char[strlen("Par") + 1];
		strcpy(this->categorie, "Par");
		this->denumire = "Ulei";
		this->cantitate = 20;
		this->pret = 60;
		this->nrRating = 3;
		this->rating = new int[this->nrRating];
		for (int i = 0; i < this->nrRating; i++) {
			this->rating[i] = i + 2;
		}
		for (int i = 0; i < 12; i++) {
			this->cumparariLunare[i] = i + 120;
		}
		this->id++;
	}
//1. Linia 47 e prea lunga
	Produs(const char* categorieP, string denumireP, float cantitateP, float pretP, int nrRatingP, int* ratingP, int cumparariLunareP[12]) : TVA(0.19) {
		cout << "Apel constructor cu parametri" << endl;
		this->categorie = new char[strlen(categorieP) + 1];
		strcpy(this->categorie, categorieP);
		this->denumire = denumireP;
		this->cantitate = cantitateP;
		this->pret = pretP;
		this->nrRating = nrRatingP;
		this->rating = new int[this->nrRating];
		for (int i = 0; i < this->nrRating; i++) {
			this->rating[i] = ratingP[i];
		}
		for (int i = 0; i < 12; i++) {
			this->cumparariLunare[i] = cumparariLunareP[i];
		}
		this->id++;
	}

	Produs(int nrRatingP, int* ratingP) : TVA(0.19){
		this->categorie = new char[1];
		strcpy(this->categorie, "");
		this->cantitate = NULL;
		this->pret = NULL;
		this->nrRating = nrRatingP;
		this->rating = new int[this->nrRating];
		for (int i = 0; i < this->nrRating; i++) {
			this->rating[i] = ratingP[i];
		}
		for (int i = 0; i < 12; i++) {
			this->cumparariLunare[i] = 0;
		}
		this->id++;
	}

	//constructor de copiere
	Produs(const Produs& produs) : TVA(0.19) {
		this->categorie = new char[strlen(produs.categorie) + 1];
		strcpy(this->categorie, produs.categorie);
		this->denumire = produs.denumire;
		this->cantitate = produs.cantitate;
		this->pret = produs.pret;
		this->nrRating = produs.nrRating;
		this->rating = new int[this->nrRating];
		for (int i = 0; i < this->nrRating; i++) {
			this->rating[i] = produs.rating[i];
		}
		for (int i = 0; i < 12; i++) {
			this->cumparariLunare[i] = produs.cumparariLunare[i];
		}
		this->id++;
	}

	//supraincarcare operator = 
	Produs& operator=(const Produs& produs){
		this->categorie = new char[strlen(produs.categorie) + 1];
		strcpy(this->categorie, produs.categorie);
		this->denumire = produs.denumire;
		this->cantitate = produs.cantitate;
		this->pret = produs.pret;
		this->nrRating = produs.nrRating;
		this->rating = new int[this->nrRating];
		for (int i = 0; i < this->nrRating; i++) {
			this->rating[i] = produs.rating[i];
		}
		for (int i = 0; i < 12; i++) {
			this->cumparariLunare[i] = produs.cumparariLunare[i];
		}
		this->id++;
		return *this;
	}

	//getteri
	int getId() {
		return this->id;
	}

	char* getCategorie() {
		return this->categorie;
	}

	string getDenumire() {
		return this->denumire;
	}

	float getCantitate() {
		return this->cantitate;
	}

	float getPret() {
		return this->pret;
	}

	int getNrRating() {
		return this->nrRating;
	}

	int* getRating() {
		return this->rating;
	}

	int* getCumparariLunare() {
		return this->cumparariLunare;
	}

	float getTVA() {
		return this->TVA;
	}

	//setteri
	static void setId(int idNou) {
		if (idNou > 0)
			Produs::id = idNou;
	}

	void setCategorie(char* categorieNou) {
		if ((strlen(categorieNou) > 2) && (strlen(categorieNou) < 25))
		{
			if (this->categorie != NULL)
				delete[] this->categorie;
			this->categorie = new char[strlen(categorieNou) + 1];

			this->categorie = categorieNou;
		}
	}

	void setDenumire(string denumireNou) {
		if ((denumireNou.length() > 2) && (denumireNou.length() < 25))
			this->denumire = denumireNou;
	}

	void setCantitate(float cantitateNou) {
		if (cantitateNou > 0)
			this->cantitate = cantitateNou;
	}

	void setPret(float pretNou) {
		if (pretNou > 0)
			this->pret = pretNou;
	}

	void setNrRating(int nrRatingNou) {
		this->nrRating = nrRatingNou;
	}

	void setRating(int nrRatingNou, int* ratingNou) {
		if (this->rating != NULL) {
			delete[] this->rating;
		}
		this->nrRating = nrRatingNou;
		this->rating = new int[this->nrRating];
		for (int i = 0; i < this->nrRating; i++) {
			if ((ratingNou[i] >= 0) && (ratingNou[i] <= 5))
				this->rating[i] = ratingNou[i];
		}
	}

	void setCuparariLunare(int cumparariLunareN[12]) {
		for (int i = 0; i < 12; i++) {
			if (cumparariLunareN >= 0)
				this->cumparariLunare[i] = cumparariLunareN[i];
		}
	}

	//metode de prelucrare si afisare
	void prelucrarePret() {
		cout << "Pretul cu TVA este ";
		float pretTVA = (this->pret*TVA) + this->pret;
		cout << pretTVA << endl;
	}

	void ratingMediu() {
		int s = 0;
		for (int i = 0; i < this->nrRating; i++)
			s = s + this->rating[i];
		float ratingMediu;
		ratingMediu = (float)s / this->nrRating;
		cout << "Ratingul mediu al produsului este " << ratingMediu << endl;
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Produs produs) {
		out << "Categorie: " << produs.categorie << endl;
		out << "Denumire: " << produs.denumire << endl;
		out << "Cantitate: " << produs.cantitate << endl;
		out << "Pret: " << produs.pret << endl;
		out << "Nr rating: " << produs.nrRating << endl;
		for (int i = 0; i < produs.nrRating; i++) {
			out << "Ratingul produsului " << i + 1 << " este " << produs.rating[i] << endl;
		}
		out << endl;
		for (int i = 0; i < 12; i++) {
			out << "Achizitiile produsului in luna " << i + 1 << " este " << produs.cumparariLunare[i]<<endl;
		}
		out << endl;
		return out;
	}

	//supraincarcare operator >>
	friend istream& operator>>(istream& in, Produs& produs) {
		cout << "Categorie: ";
		if (produs.categorie != NULL)
			delete[] produs.categorie;
		string aux;
		in >> aux;
		produs.categorie = new char[aux.length() + 1];
		strcpy(produs.categorie, aux.c_str());
	
		cout << "Denumire: ";
		in >> produs.denumire;
		cout << "Cantitate: ";
		in >> produs.cantitate;
		cout << "Pret: ";
		in >> produs.pret;
		cout << "Nr rating: ";
		in >> produs.nrRating;

		if (produs.rating != NULL)
			delete[] produs.rating;
		produs.rating = new int[produs.nrRating];
		for (int i = 0; i < produs.nrRating; i++) {
			cout << "Ratingul produsului " << i + 1 << " este ";
			in >> produs.rating[i];
		}
	
		for (int i = 0; i < 12; i++) {
			cout << "Achizitiile produsului in luna " << i + 1 << " este ";
			in >> produs.cumparariLunare[i];
		}
		cout << endl;
		return in;
	}

	//supraincarcare operator !
	bool operator!() {
		if (this->rating != NULL)
			return false;
		else
			return true;
	}

	//supraincarcare operator ==
	bool operator==(Produs p) {
		if (strcmp(this->categorie, p.categorie) == 1 && this->denumire == p.denumire && this->cantitate == p.cantitate && this->pret == p.pret && this->nrRating == p.nrRating)
			return true;
		else
			return false;
	}

	//supraincarcare operator >
	bool operator>(Produs p) {
		if (this->pret > p.pret)
			return true;
		else
			return false;
	}
	
	//supraincarcare operator index[]
	int& operator[](int index) {
		if (index < 0 || index > this->nrRating) {
			cout << "Index in afara limitelor" << endl;
			throw new exception("Exceptie");
		}
		else {
			return this->rating[index];
		}
	}

	//supraincarcare operator cast
	explicit operator float() {
		return this->pret;
	}

	//supraincarcare operator ++ prefixat
	Produs& operator++(){
		int* ratingNou = new int[this->nrRating + 1];
		for (int i = 0; i < this->nrRating; i++) {
			ratingNou[i] = this->rating[i];
		}
		ratingNou[this->nrRating] = 5;
		this->nrRating++;
		if (this->rating != NULL) {
			delete[] this->rating;
		}
		this->rating = ratingNou;
		return *this;
	}

	//supraincarcare operator ++ sufixat
	Produs operator++(int) {
		Produs copie = *this;
		int* ratingNou = new int[this->nrRating + 1];
		for (int i = 0; i < this->nrRating; i++) {
			ratingNou[i] = this->rating[i];
		}
		ratingNou[this->nrRating] = 5;
		this->nrRating++;
		if (this->rating != NULL) {
			delete[] this->rating;
		}
		this->rating = ratingNou;
		return copie;
	}

	//supraincarcare operator + pentru apel p1+3;
	Produs operator+(float valoare) {
		Produs copie = *this;
		copie.pret += valoare;
		return copie;
	}

	//supraincarcare operator + pentru apel 3+p1;
	friend Produs operator+(int valoare, Produs p) {
		Produs copie = p;
		copie.pret += valoare;
		return copie;
	}
	//supraincarcare operator - pentru apel p1-3;
	Produs operator-(float valoare) {
		Produs copie = *this;
		copie.pret -= valoare;
		return copie;
	}

	//supraincarcare operator - pentru apel 3-p1;
	friend Produs operator-(int valoare, Produs p) {
		Produs copie = p;
		copie.pret -= valoare;
		return copie;
	}
//2. Am cout in Destructor si la rulare as avea un output redundant (pentru un vector e 1000 de obiecte, 1000 de afisari)
	//Destructor
	~Produs() {
		cout << "Apel destructor" << endl;
		if (this->categorie != NULL)
			delete[] this->categorie;
		if (this->rating != NULL)
			delete[] this->rating;
		this->id--;
	}

	//Metoda de afisare
	void afisare() {
		cout << "------------------------------" << endl;
		cout << "Id: " << this->id << endl;
		cout << "Categorie: " << this->categorie << endl;
		cout << "Denumire: " << this->denumire<< endl;
		cout << "Cantitate: " << this->cantitate << endl;
		cout << "Pret: " << this->pret << endl;
		for (int i = 0; i < this->nrRating; i++)
			cout << "Ratingul numarul " << i + 1 << ": " << this->rating[i] << endl;
		for (int i = 0; i < 12; i++)
			cout << "Achizitii in luna " << i + 1 << ": " << cumparariLunare[i] << endl;
		cout << "--------------------------" << endl;
	}
};
int Produs::id = 0;

// Clasa mostenitoare 

class Ruj : public Produs {
protected:
	int nrCulori;
	string culoare[20];

public:

	//apel constructor fara parametri

	Ruj() : Produs() {
		this->nrCulori = 10;
		for (int i = 0; i < this->nrCulori; i++) {
			this->culoare[i] = "Culoarea " + to_string(i+1);
		}
	}

	//apel constructor cu parametri
	//aici imi da eroare si nu stiu ce sa fac cu const TVA

	Ruj(const char* categorieP, string denumireP, float cantitateP, float pretP, int nrRatingP, int* ratingP, int cumparariLunareP[12], int nrCuloriP, string culoareP[20]) : Produs(categorieP, denumireP, cantitateP, pretP, nrRatingP, ratingP, cumparariLunareP){
		cout << "Apel constructor clasa Ruj" << endl;
		this->nrCulori = nrCuloriP;
		for (int i = 0; i < this->nrCulori; i++) {
			this->culoare[i] = culoareP[i];
		}
	}

	//apel constructor de copiere

	Ruj(const Ruj &r) :Produs(r) {
		this->nrCulori = r.nrCulori;
		for (int i = 0; i < this->nrCulori; i++) {
			this->culoare[i] = r.culoare[i];
		}
	}

	//apel getteri

	int getNrCulori() {
		return this->nrCulori;
	}

	string* getCuloare() {
		return this->culoare;
	}

	//apel setteri

	void setNrCulori(int nrCuloriP) {
		this->nrCulori = nrCuloriP;
	}

	void setCuloare(string culoareP[20]) {
		for (int i = 0; i < this->nrCulori; i++) {
			if (culoareP[i].length() > 2)
				this->culoare[i] = culoareP[i];
		}
	}

	//apel destructor

	~Ruj() {
		cout << "Apel destructor clasa Ruj" << endl;
	}

	void afisareRuj() {
		cout << "--------------------" << endl;
		cout << "Id: " << this->getId() << endl;
		cout << "Categorie: " << this->getCategorie() << endl;
		cout << "Denumire: " << this->getDenumire() << endl;
		cout << "Cantitate: " << this->getCantitate() << endl;
		cout << "Pret: " << this->getPret() << endl;
		int nr = this->getNrRating();
		int* r = new int[nr];
		r = this->getRating();
		for (int i = 0; i < nr; i++)
			cout << r[i] << endl;

		int* cl = this->getCumparariLunare();
		for (int i = 0; i < 12; i++)
			cout << cl[i] << endl;

		cout << "Numar culori: " << this->nrCulori << endl;
		for (int i = 0; i < this->nrCulori; i++) {
			cout << "Culoare: " << this->culoare[i] << endl;
		}
	}
};

// Clasa mostenitoare

class RujMat : public Ruj {
private: 
	int oreRezistenta;
	bool formulaUscata;
public:

	RujMat() :Ruj() {
		this->oreRezistenta = 12;
		this->formulaUscata = 0;
	}

	RujMat(const char* categorieP, string denumireP, float cantitateP, float pretP, int nrRatingP, int* ratingP, int cumparariLunareP[12], int nrCuloriP, string culoareP[20], int oreRezistentaN, bool formulaUscataN) : Ruj(categorieP, denumireP, cantitateP, pretP, nrRatingP, ratingP, cumparariLunareP, nrCuloriP, culoareP) {
		this->oreRezistenta = oreRezistentaN;
		this->formulaUscata = formulaUscataN;
	}

	int getOreRezistenta() {
		return this->oreRezistenta;
	}

	bool getFormulaUscata() {
		return this->formulaUscata;
	}

	void setOreRezistenta(int oreRezistentaP) {
		this->oreRezistenta = oreRezistentaP;
	}

	void setFormulaUscata(bool formulaUscataN) {
		this->formulaUscata = formulaUscataN;
	}

	~RujMat() {
		cout << "Apel destructor clasa RujMat" << endl;
	}

	void afisareRujMat() {
		cout << "--------------------" << endl;
		cout << "Id: " << this->getId() << endl;
		cout << "Categorie: " << this->getCategorie() << endl;
		cout << "Denumire: " << this->getDenumire() << endl;
		cout << "Cantitate: " << this->getCantitate() << endl;
		cout << "Pret: " << this->getPret() << endl;
		int nr = this->getNrRating();
		int* r = new int[nr];
		r = this->getRating();
		for (int i = 0; i < nr; i++)
			cout << r[i] << endl;

		int* cl = this->getCumparariLunare();
		for (int i = 0; i < 12; i++)
			cout << cl[i] << endl;

		cout << "Numar culori: " << this->nrCulori << endl;
		for (int i = 0; i < this->nrCulori; i++) {
			cout << "Culoare: " << this->culoare[i] << endl;
		}
		cout << "Numarul de ore rezistente: " << this->oreRezistenta << endl;
		cout << "Forumula uscata?: " << this->formulaUscata << endl;
	}
};

class Categorii {
private:
	char* denumire;
	int nrProduse;
	int* idProduse;
	float pretProduse[200];
	static int codCategorie;
//3. numele de variabila constanta trebuia sa fie cu litere mari
	const string PRESCURTARE;

public:

	//constructori
	Categorii() : PRESCURTARE("P001") {
		cout << "Apel constructor fara parametri" << endl;
		this->denumire = new char[strlen("par") + 1];
		strcpy(this->denumire, "par");
		this->nrProduse = 4;
		this->idProduse = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->idProduse[i] = i + 1;
		}
		for (int i = 0; i < this->nrProduse; i++) {
			this->pretProduse[i] = i + 100;
		}
		this->codCategorie++;
	}

	Categorii(char* denumireP, int nrProduseP, int* idProduseP, float pretProduseP[]) : PRESCURTARE("Z00X") {
		cout << "Apel constructor cu parametri" << endl;
		this->denumire = new char[strlen(denumireP) + 1];
		strcpy(this->denumire, denumireP);
		this->nrProduse = nrProduseP;
		this->idProduse = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->idProduse[i] = idProduseP[i];
		}
		for (int i = 0; i < this->nrProduse; i++) {
			this->pretProduse[i] = pretProduseP[i];
		}
		this->codCategorie++;
	}

	Categorii(int nrProduseP, int* idProduseP) : PRESCURTARE("Z00W") {
		this->denumire = new char[1];
		strcpy(this->denumire, "");
		this->nrProduse = nrProduseP;
		this->idProduse = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->idProduse[i] = idProduseP[i];
		}
		for (int i = 0; i < this->nrProduse; i++) {
			this->pretProduse[i] = NULL;
		}
		this->codCategorie++;
	}

	//constructor de copiere
	Categorii(const Categorii& categorie) : PRESCURTARE("X00Z") {
		this->denumire = new char[strlen(categorie.denumire) + 1];
		strcpy(this->denumire, categorie.denumire);
		this->nrProduse = categorie.nrProduse;
		this->idProduse = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->idProduse[i] = categorie.idProduse[i];
			this->pretProduse[i] = categorie.pretProduse[i];
		}
		this->codCategorie++;
	}

	//supraincarcare operator = 
	Categorii& operator= (const Categorii& categorie) {
		this->denumire = new char[strlen(categorie.denumire) + 1];
		strcpy(this->denumire, categorie.denumire);
		this->nrProduse = categorie.nrProduse;
		this->idProduse = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->idProduse[i] = categorie.idProduse[i];
			this->pretProduse[i] = categorie.pretProduse[i];
		}
		return *this;
	}

	//getteri

	int getCodCategorie() {
		return this->codCategorie;
	}

	char* getDenumire() {
		return this->denumire;
	}

	int getNrProduse() {
		return this->nrProduse;
	}

	int* getIdProduse() {
		return this->idProduse;
	}	

	float* getPretProduse() {
		return this->pretProduse;
	}

	string getPrescurtare() {
		return this->PRESCURTARE;
	}

	//setteri

	void setDenumire(char* denumire) {
		if ((strlen(denumire) >= 3) && (strlen(denumire) <= 25))
		{
			if (this->denumire != NULL)
				delete[] this->denumire;
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
	}

	void setNrProduse(int nrProduse) {
		if (nrProduse > 0) {
			this->nrProduse = nrProduse;
		}
	}

	void setIdProduse(int nrProduse, int* idProduse) {
		if (idProduse != NULL)
			delete[] this->idProduse;
		this->nrProduse = nrProduse;
		this->idProduse = new int[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			if (idProduse[i] > 0)
				this->idProduse[i] = idProduse[i];
		}
	}

	void setPretProduse(int nrProduse, float pretProduse[]) {
		for (int i = 0; i < nrProduse; i++) {
			if (pretProduse >= 0)
				this->pretProduse[i] = pretProduse[i];
		}
	}

	void setCodCategorie(int codCategorie) {
		if (codCategorie >= 0)
			this->codCategorie = codCategorie;

	}

	//metode de prelucrare si afisare
	void reducerePret() {
		for (int i = 0; i < this->nrProduse; i++) {
			this->pretProduse[i] = 0.8*this->pretProduse[i];
			cout << this->pretProduse[i] << " ";
		}
		cout << endl;
	}

	void prelucrareDenumire() {
		this->denumire[0] = toupper(this->denumire[0]);
		cout << this->denumire << endl;
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Categorii& categorie) {
		out << "Codul categoriei este " << categorie.codCategorie << endl;
		out << "Denumirea categoriei este " << categorie.denumire << endl;
		out << "Numarul de produse din actegorie este " << categorie.nrProduse << endl;
		out << "Id-urile produselor din aceasta categorie sunt: ";
		for (int i = 0; i < categorie.nrProduse; i++) {
			out << categorie.idProduse[i] << " ";
		}
		out << endl;
		out << "Preturile produselor sunt: " << endl;
		for (int i = 0; i < categorie.nrProduse; i++) {
			out << categorie.pretProduse[i] << " ";
		}
		out << endl;
		return out;
	}

	//supraincarcare operator >>
	friend istream& operator>>(istream& in, Categorii& categorie) {
		cout << "Denumire categorie: ";
		if (categorie.denumire != NULL)
			delete[] categorie.denumire;
		string aux;
		in >> aux;
		categorie.denumire = new char[aux.length() + 1];
		strcpy(categorie.denumire, aux.c_str());

		cout << "Numarul de produse din categorie este: ";
		in >> categorie.nrProduse;

		if (categorie.idProduse != NULL)
			delete[] categorie.idProduse;
		categorie.idProduse = new int[categorie.nrProduse];
		for (int i = 0; i < categorie.nrProduse; i++) {
			cout << "Id-ul produsului " << i << " este: ";
			in >> categorie.idProduse[i];
		}

		for (int i = 0; i < categorie.nrProduse; i++) {
			cout << "Pretul produsului " << i << " este: ";
			in >> categorie.pretProduse[i];
		}
		return in;
	}

	//supraincarcare operator !
	bool operator!() {
		if (this->idProduse != NULL)
			return false;
		else 
			return true;
	}

	//supraincarcare operator >
	bool operator>(Categorii c) {
		if (this->nrProduse > c.nrProduse)
			return true;
		else
			return false;
	}

	//supraincarcare operator ==
	bool operator==(Categorii c) {
		if (strcmp(this->denumire, c.denumire) == 1 && this->nrProduse == c.nrProduse)
			return true;
		else
			return false;
	}

	//supraincarcare operator index[]
	int& operator[](int index) {
		if (index<0 || index > this->nrProduse) {
			cout << "Index in afara limitelor" << endl;
			throw new exception("Exceptie");
		}
		else
			return this->idProduse[index];
	}

	//supraincarcare operator cast
	explicit operator int() {
		return this->nrProduse;
	}

	//supraincarcare operator ++ prefixat
	Categorii& operator++() {
		int* idNou = new int[this->nrProduse + 1];
		for (int i = 0; i < this->nrProduse; i++) {
			idNou[i] = this->idProduse[i];
		}
		idNou[this->nrProduse] = 100;
		this->pretProduse[this->nrProduse] = 100;
		this->nrProduse++;
		if (this->idProduse != NULL)
			delete[] this->idProduse;
		this->idProduse = idNou;
		return *this;
	}
	//Supraincarcare operator ++ sufixat
	Categorii operator++(int) {
		Categorii copie = *this;
		int* idNou = new int[this->nrProduse + 1];
		for (int i = 0; i < this->nrProduse; i++) {
			idNou[i] = this->idProduse[i];
		}
		idNou[this->nrProduse] = 100;
		this->pretProduse[this->nrProduse] = 100;
		this->nrProduse++;
		if (this->idProduse != NULL)
			delete[] this->idProduse;
		this->idProduse = idNou;
		return copie;
	}

	//supraincarcare operator + pentru apel c1+3;
	Categorii operator+(float valoare) {
		Categorii copie = *this;
		for (int i = 0; i < this->nrProduse; i++)
			copie.pretProduse[i] += valoare;
		return copie;
	}

	//supraincarcare operator + pentru apel 3+c1;
	friend Categorii operator+(float valoare, Categorii c) {
		Categorii copie = c;
		for (int i = 0; i < c.nrProduse; i++)
			copie.pretProduse[i] += valoare;
		return copie;
	}

	//supraincarcare operator - pentru apel c1-3;
	Categorii operator-(float valoare) {
		Categorii copie = *this;
		for (int i = 0; i < this->nrProduse; i++)
			copie.pretProduse[i] -= valoare;
		return copie;
	}

	//supraincarcare operator - pentru apel 3-c1;
	friend Categorii operator-(float valoare, Categorii c) {
		Categorii copie = c;
		for (int i = 0; i < c.nrProduse; i++)
			copie.pretProduse[i] += valoare;
		return copie;
	}


	//destructor 
	~Categorii() {
		cout << "Apel destructor" << endl;
		if (this->denumire != NULL)
			delete[] this->denumire;
		if (this->idProduse != NULL)
			delete[] this->idProduse;
		this->codCategorie--;
	}

	void afisare() {
		cout << "----------------------" << endl;
		cout << "Codul categoriei este " << this->codCategorie << endl;
		cout << "Denumirea categoriei este: " << this->denumire << endl;
		cout << "Numarul de produse este: " << this->nrProduse << endl;
		for (int i = 0; i < this->nrProduse; i++) {
			cout << "Id-ul produsului " << i << " este:" << this->idProduse[i] << endl;
		}
		for (int i = 0; i < this->nrProduse; i++) {
			cout << "Pretul produsului " << i << " este:" << this->pretProduse[i] << endl;
		}
		cout << "-------------------------" << endl;
	}
};
int Categorii::codCategorie = 0;

class Producatori {
private:
	bool crueltyFree;
	char* denumire;
	int nrIngrediente;
	int ingrediente[200];
	const int serie;
	static int idProducator;

public:

	//constructori
	Producatori() : serie(1) {
		cout << "Apel constructor fara parametri" << endl;
		this->crueltyFree = 1;
		this->denumire = new char[strlen("Colourpop") + 1];
		strcpy(this->denumire, "Colourpop");
		this->nrIngrediente = 6;
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = i + 1;
		}
		this->idProducator++;
	}

	Producatori(bool crueltyFreeP, char* denumireP, int nrIngredienteP, int ingredienteP[200]): serie(2) {
		cout << "Apel constructor cu parametri" << endl;
		this->crueltyFree = crueltyFreeP;
		this->denumire = new char[strlen(denumireP) + 1];
		strcpy(this->denumire, denumireP);
		this->nrIngrediente = nrIngredienteP;
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = ingredienteP[i];
		}
		this->idProducator++;
	}

	Producatori(int nrIngredienteP, int ingredienteP[]) : serie(3) {
		cout << "Apel constructor cu parametri" << endl;
		this->crueltyFree = 0;
		this->denumire = new char[1];
		strcpy(this->denumire, "");
		this->nrIngrediente = nrIngredienteP;
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = ingredienteP[i];
		}
		idProducator++;
	}

	//constructor de copiere
	Producatori(const Producatori& producator):serie(4) {
		cout << "Apel constructor de copiere" << endl;
		this->crueltyFree = producator.crueltyFree;
		this->denumire = new char[strlen(producator.denumire) + 1];
		strcpy(this->denumire, producator.denumire);
		this->nrIngrediente = producator.nrIngrediente;
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = producator.ingrediente[i];
		}
		this->idProducator++;
	}

	//supraincarcare operator = 
	Producatori& operator=(const Producatori& producator) {
		this->crueltyFree = producator.crueltyFree;
		this->denumire = new char[strlen(producator.denumire) + 1];
		strcpy(this->denumire, producator.denumire);
		this->nrIngrediente = producator.nrIngrediente;
		for (int i = 0; i < this->nrIngrediente; i++) {
			this->ingrediente[i] = producator.ingrediente[i];
		}
		this->idProducator++;
		return *this;
	}

	//getteri
	bool getCrueltyFree() {
		return this->crueltyFree;
	}

	char* getDenumire() {
		return this->denumire;
	}

	int getNrIngrediente() {
		return this->nrIngrediente;
	}

	int* getIngrediente() {
		return this->ingrediente;
	}

	int getIdProducator() {
		return this->idProducator;
	}
	
	int getSerie() {
		return this->serie;
	}

	//setteri
	void setCrueltyFree(bool crueltyFree) {
		if(crueltyFree == 0 || crueltyFree == 1)
			this->crueltyFree = crueltyFree;
	}

	void setDenumire(char* denumire) {
		if (strlen(denumire) >= 3 && strlen(denumire) <= 25)
		{
			if (this->denumire != NULL)
				delete[] this->denumire;
			this->denumire = new char[strlen(denumire) + 1];
			strcpy(this->denumire, denumire);
		}
	}

	void setNrIngrediente(int nrIngrediente) {
		if(nrIngrediente >= 0)
			this->nrIngrediente = nrIngrediente;
	}

	void setIngrediente(int nrIngrediente, int ingrediente[]) {
		if (nrIngrediente > 0) {
			this->nrIngrediente = nrIngrediente;
			for (int i = 0; i < this->nrIngrediente; i++) {
				if(ingrediente[i]>0)
					this->ingrediente[i] = ingrediente[i];
			}
		}
	}

	void setIdProducator(int idProducator) {
		if(idProducator >= 0)
			this->idProducator = idProducator;
	}

	//metode de prelucrare
	void schimbareCrueltyFree() {
		if (this->crueltyFree == 0) 
			this->crueltyFree = 1;
		else 
			this->crueltyFree = 0;
		cout << this->crueltyFree << endl;
	}

	void prelucrareDenumireProduc() {
		strupr(this->denumire);
		cout << this->denumire << endl;
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& out, Producatori& p) {
		out << "Id producator: " << p.idProducator << endl;
		out << "Cruelty Free: " << p.crueltyFree << endl;
		out << "Denumire: " << p.denumire << endl;
		out << "Numar ingrediente: " << p.nrIngrediente << endl;
		for (int i = 0; i < p.nrIngrediente; i++) {
			out << "Ingredientul " << p.ingrediente[i] << endl;
		}
		out << "Serie: " << p.serie << endl;
		return out;
	}

	//supraincarcare operator >>
	friend istream& operator>>(istream& in, Producatori& p) {
		cout << "Cruelty free (0/1): ";
		in >> p.crueltyFree;

		cout << "Denumire: ";
		if (p.denumire != NULL)
			delete[] p.denumire;
		string aux;
		in >> aux;
		p.denumire = new char[aux.length() + 1];
		strcpy(p.denumire, aux.c_str());

		cout << "Numar ingrediente: ";
		in >> p.nrIngrediente;
		for (int i = 0; i < p.nrIngrediente; i++) {
			cout << "Ingredientul numarul: ";
			in >> p.ingrediente[i];
		}
		cout << "Id producator: ";
		in >> p.idProducator;
		return in;
	}

	//supraincarcare operator !
	bool operator!() {
		if (this->denumire != NULL)
			return false;
		else
			return true;
	}

	//supraincarcare operator ==
	bool operator==(Producatori p) {
		if (this->crueltyFree == p.crueltyFree && strcmp(this->denumire, p.denumire) == 0 && this->nrIngrediente == p.nrIngrediente)
			return true;
		else
			return false;
	 }

	//supraincarcare operator >
	bool operator>(Producatori p) {
		if (this->nrIngrediente > p.nrIngrediente)
			return true;
		else
			return false;
	}

	//supraincarcare operator index[]
	int& operator[](int index) {
		if (index < 0 || index > this->nrIngrediente) {
			cout << "Index in afara limitelor." << endl;
			throw new exception("Exceptie");
		}
		else
			return this->ingrediente[index];
	}

	//supraincarcare operator cast
	explicit operator bool() {
		return this->crueltyFree;
	}

	//supraincarcare operator -- prefixat
	Producatori& operator--() {
		if (this->nrIngrediente > 0)
		{
			this->nrIngrediente--;
			return *this;
		}
	}

	//supraincarcare operator -- sufixat
	Producatori operator--(int) {
		if (this->nrIngrediente > 0)
		{
			Producatori copie = *this;
			this->nrIngrediente--;
			return copie;
		}
	}

	//supraincarcare operator + pentru apel p1+3;
	Producatori operator+(float valoare) {
		Producatori copie = *this;
		for (int i = 0; i < this->nrIngrediente; i++)
			copie.ingrediente[i] += valoare;
		return copie;
	}

	//supraincarcare operator + pentru apel 3+p1;
	friend Producatori operator+(float valoare, Producatori p) {
		Producatori copie = p;
		for (int i = 0; i < p.nrIngrediente; i++)
			copie.ingrediente[i] += valoare;
		return copie;
	}

	//supraincarcare operator - pentru apel p1-3;
	Producatori operator-(float valoare) {
		Producatori copie = *this;
		for (int i = 0; i < this->nrIngrediente; i++)
			copie.ingrediente[i] -= valoare;
		return copie;
	}

	//supraincarcare operator - pentru apel 3-p1;
	friend Producatori operator-(float valoare, Producatori p) {
		Producatori copie = p;
		for (int i = 0; i < p.nrIngrediente; i++)
			copie.ingrediente[i] += valoare;
		return copie;
	}

	//destructor
	~Producatori() {
		cout << "Apel destructor" << endl;
		if (this->denumire != NULL)
			delete[] this->denumire;
		this->idProducator--;
	}


	//metoda afisare
	void afisare() {
		cout << "--------------------" << endl;
		cout << "Id-ul producatorului: " << this->idProducator << endl;
		cout << "Cruelty free: " << this->crueltyFree << endl;
		cout << "Denumire: " << this->denumire << endl;
		cout << "Numar ingrediente: " << this->nrIngrediente << endl;
		for (int i = 0; i < this->nrIngrediente; i++) {
			cout << "Ingredientul " << this->ingrediente[i] << endl;
		}
		cout << "Serie: " << this->serie << endl;
		cout << "------------------------" << endl;
	}
};
int Producatori:: idProducator = 0;

// Clasa abstracta

class Ingredient {
protected:
	string denumire;
	float pret;

public:
	Ingredient() {
		this->denumire = "ulei de cocos";
		this->pret = 35;
	}

	Ingredient(string ingredientP, float pretP) {
		this->denumire = ingredientP;
		this->pret = pretP;
	}

	void setDenumire(string denumire) {
		this->denumire = denumire;
	}

	void setPret(float pret) {
		this->pret = pret;
	}

	string getDenumire() {
		return this->denumire;
	}

	float getPret() {
		return this->pret;
	}

	virtual void folosinta() = 0;

	virtual ~Ingredient() {
		cout << "Apel destructor clasa ingredient." << endl;
	}
};

// interfata cu metoda virtuala

class IMarirePret {
	virtual float getPret() = 0;
	virtual void marirePret(float valAdaugata) = 0;
};

// clasa care mosteneste clasa abstracta si implementeaza interfata pentru apel

class Industrie : public Ingredient, public IMarirePret {
private:
	string nume;
public:

	Industrie(): Ingredient() {
		this->nume = "farmaceutica";
	}

	Industrie(string denumireP, float pretP, string numeP) :Ingredient(denumireP, pretP) {
		this->nume = numeP;
	}

	string getNume() {
		return this->nume;
	}

	void setNume(string numeP) {
		this->nume = numeP;
	}

	virtual void folosinta() {
		cout << "Ingredientul " << this->denumire << " se va folosi!" << endl;
	}

	virtual float getPret() {
		return this->pret;
	}

	virtual void marirePret(float valAdaugata) {
		this->pret += valAdaugata;
	}

	~Industrie() {
		cout << "Apel destructor clasa Industrie" << endl;
	}
};

//Clasa relatia HAS A

class Gama {
private:
	int nrProduse;
	Produs** produse;
public:
	Gama() {
		this->nrProduse = 0;
		this->produse = NULL;
	}

	Gama(int nrProduseP, Produs** produseP) {
		this->nrProduse = nrProduseP;
		this->produse = new Produs*[this->nrProduse];
		for (int i = 0; i < this->nrProduse; i++) {
			this->produse[i] = produseP[i];
		}
	}

	~Gama() {
		cout << "Apel destructor clasa Gama" << endl;
		if (this->produse != NULL) {
			delete[] this->produse;
		}
	}

	void afisare() {
		cout << "Afisare gama" << endl;
		cout << "Numarul de produse este: " << this->nrProduse << endl;
		for (int i = 0; i < this->nrProduse; i++) {
			this->produse[i]->afisare();
		}
	}

};

void vectorRandom(int nrRating, int* rating) {
	for (int i = 0; i < nrRating; i++) {
		rating[i] = rand() % 5 + 1;
	}
}

int main()
{
	///CLASA PRODUS

	char* categorie = new char[strlen("ten") + 1];
	strcpy(categorie, "ten");
	std::string denumire = "panda";
	float cantitate = 1.2;
	float pret = 100;
	int nrRating = 5;
	int* rating = new int[nrRating];
	srand(time(NULL));
	vectorRandom(nrRating, rating);
	int cumparariLunare[12];
	for (int i = 0; i < 12; i++) {
		cumparariLunare[i] = i + 100;
	}

	//apelare constructori
	Produs p1;
	p1.afisare();

	Produs p2(categorie, denumire, cantitate, pret, nrRating, rating, cumparariLunare);
	p2.afisare();
	vectorRandom(nrRating, rating);

	Produs p3(nrRating, rating);
	p3.afisare();

	//apelare constructor de copiere
	Produs p4 = p2;
	p4.afisare();

	//apelare supraincarcare =
	p4 = p3;
	p4.afisare();

	//apelare getteri si setteri
	char* categNou = new char[strlen("Make-up") + 1];
	strcpy(categNou, "Make-up");
	p1.setCategorie(categNou);
	cout << p1.getCategorie() << endl;

	p1.setDenumire("Fond de ten");
	cout << p1.getDenumire() << endl;

	p1.setCantitate(1.9);
	cout << p1.getCantitate() << endl;

	p1.setPret(193);
	cout << p1.getPret() << endl;

	p1.setNrRating(7);
	cout << p1.getNrRating() << endl;

	int nr = p1.getNrRating();
	int* r = new int[nr];
	rating = new int[nr];
	srand(time(NULL));
	vectorRandom(nr, rating); // apelam functia pentru a face un nou vector random
	p1.setRating(nr, rating);
	r = p1.getRating();
	for (int i = 0; i < nr; i++)
		cout << r[i] << endl;

	int cNou[12];
	for (int i = 0; i < 12; i++)
		cNou[i] = 100 + i;
	p1.setCuparariLunare(cNou);
	int* cl = p1.getCumparariLunare();
	for (int i = 0; i < 12; i++)
		cout << cl[i] << endl;

	p1.setId(9);
	cout << p1.getId() << endl;

	cout << p1.getTVA() << endl;

	//apelare metode de prelucrare
	p1.prelucrarePret();
	p1.ratingMediu();

	//apelare supraincarcare operator << si >>
	cin >> p1;
	cout << p1;

	//apelare supraincarcare !
	if (!p1)
		cout << "Da" << endl;
	else
		cout << "Nu" << endl;

	//apelare supraincarcare ==
	if (p1 == p2)
		cout << "Atributele sunt la fel." << endl;
	else
		cout << "Atributele nu sunt la fel." << endl;

	//apelare supraincarcare operator >
	if (p1 > p2)
		cout << "Pretutul obiectului p1 este mai mare decat pretul obiectului p2." << endl;
	else
		cout << "Pretutul obiectului p1 nu este mai mare decat pretul obiectului p2." << endl;

	//apelare supraincarcare operator index[]
	try {
		cout << p1[20] << endl;
	}
	catch (exception * e){
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1" << endl;
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl;
	}

	//apel supraincarcare operator cast
	cout << "Pretul produsului este: " << (float)p1 << endl;

	//apel supraincarcare operator ++ prefixat si sufixat;
	p1++;
	p1.afisare();
	++p1;
	p1.afisare();

	//apel supraincarcare + si -
	p1 = p1 + 30;
	p1.afisare();
	p1 = 50 + p1;
	p1.afisare();
	p1 = p1 - 30;
	p1.afisare();
	p1 = 50 - p1;
	p1.afisare();

	///CLASA CATEGORII

	char* denumireC = new char[strlen("corp") + 1];
	strcpy(denumireC, "corp");
	int nrProduse = 4;
	int* idProduse = new int[nrProduse];
	for (int i = 0; i < nrProduse; i++) {
		idProduse[i] = i + 1;
	}
	float pretProduse[200];
	for (int i = 0; i < nrProduse; i++) {
		pretProduse[i] = 100 + i;
	}

	//apelare constructori

	Categorii c1;
	c1.afisare();
	Categorii c2(denumireC, nrProduse, idProduse, pretProduse);
	c2.afisare();
	Categorii c3(nrProduse, idProduse);
	c3.afisare();

	//apelare constructor de copiere
	Categorii c4 = c3;
	c4.afisare();

	//apelare supraincarcare =
	c4 = c1;
	c4.afisare();

	//apelare getteri setteri

	char* denumNou = new char[strlen("Huda") + 1];
	strcpy(denumNou, "Huda");
	c1.setDenumire(denumNou);
	cout << c1.getDenumire() << endl;

	c1.setNrProduse(2);
	cout << c1.getNrProduse() << endl;

	int nrPr = c1.getNrProduse();
	int *idNou = new int[nrPr];
	for (int i = 0; i < nrPr; i++) {
		idNou[i] = i + 3;
	}
	c1.setIdProduse(nrPr, idNou);
	int* id = new int[nrPr];
	id = c1.getIdProduse();
	for (int i = 0; i < nrPr; i++) {
		cout << id[i] << endl;
	}

	float prNoi[200];
	for (int i = 0; i < nrPr; i++) {
		prNoi[i] = 120.5 + i;
	}
	c1.setPretProduse(nrPr, prNoi);
	float* pr = new float[nrPr];
	pr = c1.getPretProduse();
	for (int i = 0; i < nrPr; i++) {
		cout << pr[i] << endl;
	}

	c1.setCodCategorie(200);
	cout << c1.getCodCategorie() << endl;

	cout << c1.getPrescurtare() << endl;

	//apelare metode de prelucrare
	c1.reducerePret();
	c1.prelucrareDenumire();

	//apelare supraincarcare << si >>
	cin >> c1;
	cout << c1;

	//apelare supraincarcare !
	if (!c1)
		cout << "Da" << endl;
	else
		cout << "Nu" << endl;

	//apelare supraincarcare ==
	if (c1 == c2)
		cout << "Atributele sunt la fel." << endl;
	else
		cout << "Atributele nu sunt la fel." << endl;

	//apelare supraincarcare operator >
	if (c1 > c2)
		cout << "Exista mai multe produse in prima categorie." << endl;
	else 
		cout << "Nu exista mai multe produse in prima categorie." << endl;

	//apel supraincarcare operator []
	try {
		cout << c1[2] << endl;
	}
	catch (exception* e) {
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1" << endl;
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl;
	}

	//apelare supraincarcare operator cast
	cout << "Numarul de produse este: " << (int)c1 << endl;

	//apelare supraincarcare ++ prefixat si sufixat
	c1++;
	c1.afisare();
	++c1;
	c1.afisare();

	//apel supraincarcare + si -
	c1 = c1 + 30;
	c1.afisare();
	c1 = 50 + c1;
	c1.afisare();
	c1 = c1 - 30;
	c1.afisare();
	c1 = 50 - c1;
	c1.afisare();

	///CLASA PRODUCATORI

	bool crueltyFree = 1;
	char* denumireP = new char[strlen("Morphe") + 1];
	strcpy(denumireP, "Morphe");
	int nrIngrediente = 3;
	int v[200];
	for (int i = 0; i < nrIngrediente; i++)
		v[i] = i + 1;

	//apelare constructori

	Producatori produc1;
	produc1.afisare();

	Producatori produc2(crueltyFree, denumireP, nrIngrediente, v);
	produc2.afisare();

	Producatori produc3(nrIngrediente, v);
	produc3.afisare();

	//apelare constructor de copiere
	Producatori produc4 = produc1;
	produc4.afisare();

	//apelar supraincarcare operator =
	produc4 = produc1;
	produc4.afisare();

	//apelare getteri si setteri
	produc4.setCrueltyFree(0);
	cout << produc4.getCrueltyFree() << endl;

	char* denNou = new char[strlen("Ana") + 1];
	strcpy(denNou, "Ana");
	produc4.setDenumire(denNou);
	cout << produc4.getDenumire() << endl;

	produc4.setNrIngrediente(2);
	cout << produc4.getNrIngrediente() << endl;

	int nrProduc = produc4.getNrIngrediente();
	int pNou[200];
	for (int i = 0; i < nrProduc; i++) {
		pNou[i] = i + 5;
	}
	produc4.setIngrediente(nrProduc, pNou);
	int lungime = produc4.getNrIngrediente();
	int* p = produc4.getIngrediente();
	for (int i = 0; i < lungime; i++) {
		cout << p[i] << endl;
	}

	produc4.setIdProducator(88);
	cout << produc4.getIdProducator() << endl;

	cout << produc4.getSerie() << endl;

	//apelare metode de prelucrare
	produc1.schimbareCrueltyFree();
	produc1.prelucrareDenumireProduc();

	//apelare supraincarcare << si >>
	
	Producatori produc5;
	cin >> produc5;
	cout << produc5;

	//apelare supraincarcare !
	if (!produc1)
		cout << "Da" << endl;
	else
		cout << "Nu" << endl;

	//apelare supraincarcare ==
	if (produc1 == produc2)
		cout << "Atributele sunt la fel." << endl;
	else
		cout << "Atributele nu sunt la fel." << endl;

	//apelare supraincarcare operator >
	if (produc1 > produc2)
		cout << "Produsul 1 contine mai multe ingrediente." << endl;
	else
		cout << "Produsul 1 nu contine mai multe ingrediente." << endl;

	try {
		cout << produc1[1] << endl;
	}
	catch (exception* e) {
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1." << endl;
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl;
	}

	//apelare supraincarcare operator cast
	cout << "Cruelty free este: " << (bool)produc1 << endl;

	//apel supraincarcare -- prefixat si sufixat;
	produc1--;
	produc1.afisare();
	--produc1;
	produc1.afisare();

	//apel supraincarcare + si -
	produc1 = produc1 + 2;
	produc1.afisare();
	produc1 = 2 + produc1;
	produc1.afisare();
	produc1 = produc1 - 2;
	produc1.afisare();
	produc1 = 2 - produc1;
	produc1.afisare();

	//DE AICI INCEPE FAZA 2

	///CLASA MOSTENITOARE RUJ
	

	//apel constructor fara parametri
	Ruj ruj;
	ruj.afisareRuj();

//4. Am folosit copy paste la bucati de cod, trebuia reutilizat codul adica crearea unor metode ce puteau fi apelate
	//apel constructori cu parametri
{
		// aici am folosit { } pentru a putea declara din nou parametrii pentru constructor, avand restul main-ului comentat
	char* categorie = new char[strlen("ten") + 1];
	strcpy(categorie, "ten");
	std::string denumire = "panda";
	float cantitate = 1.2;
	float pret = 100;
	int nrRating = 5;
	int* rating = new int[nrRating];
	srand(time(NULL));
	vectorRandom(nrRating, rating);
	int cumparariLunare[12];
	for (int i = 0; i < 12; i++) {
		cumparariLunare[i] = i + 100;
	}
	int nrCulori = 9;
	string culoare[20];
	for (int i = 0; i < nrCulori; i++) {
		culoare[i] = "Culoarea " + to_string(i + 10);
	}

	Ruj rP(categorie, denumire, cantitate, pret, nrRating, rating, cumparariLunare, nrCulori, culoare);
	rP.afisareRuj();
}

	//apel setteri getteri
	ruj.setNrCulori(3);
	cout << ruj.getNrCulori() << endl;

	string nou[20];
	for (int i = 0; i < ruj.getNrCulori(); i++) {
		nou[i] = "Culoarea " + to_string(i + 3);
	}

	ruj.setCuloare(nou);
	nr = ruj.getNrCulori();
	
	string* rNou = ruj.getCuloare();
	for (int i = 0; i < nr; i++) {
		cout << "Culoare: " << rNou[i] << endl;
	}

	///CLASA RUJMAT

	//apel constructor fara parametri

	RujMat rujM;
	rujM.afisareRujMat();

	//apel constructor cu parametri
{
		// aici am folosit { } pentru a putea declara din nou parametrii pentru constructor, avand restul main-ului comentat
	char* categorie = new char[strlen("ten") + 1];
	strcpy(categorie, "ten");
	std::string denumire = "panda";
	float cantitate = 1.2;
	float pret = 100;
	int nrRating = 5;
	int* rating = new int[nrRating];
	srand(time(NULL));
	vectorRandom(nrRating, rating);
	int cumparariLunare[12];
	for (int i = 0; i < 12; i++) {
		cumparariLunare[i] = i + 100;
	}
	int nrCulori = 9;
	string culoare[20];
	for (int i = 0; i < nrCulori; i++) {
		culoare[i] = "Culoarea " + to_string(i + 10);
	}
	bool formulaUscata = 0;
	int oreRezistenta = 10;

	RujMat rPM(categorie, denumire, cantitate, pret, nrRating, rating, cumparariLunare, nrCulori, culoare, oreRezistenta, formulaUscata);
	rPM.afisareRujMat();
}

	//apel setteri si getteri

	rujM.setOreRezistenta(18);
	cout << rujM.getOreRezistenta() << endl;
	
	rujM.setFormulaUscata(1);
	cout << rujM.getFormulaUscata() << endl;

	//CLASA ABSTRACTA IINGEDIENT SI INTERFATA 

	Industrie i1;
	i1.folosinta();
	cout << i1.getPret() << endl;
	i1.marirePret(200);
	cout << i1.getPret() << endl;


	///CLASA GAMA

	Produs* produse[3] = { &p1, &p2, &p3 };
	Gama g(3, produse);
	g.afisare();


	// DE AICI INCEPE FAZA 3

	///IMPLEMENTARE CITIRE/AFISARE DIN FISIER BINAR

	//scriere intr-un fisier normal

	Produs pFisier;
	ofstream fileWriteNormal;
	fileWriteNormal.open("fisier.txt", ios::out);
	fileWriteNormal << pFisier;
	fileWriteNormal.close();

	//citirea din fisier normal

	ifstream fileReadNormal;
	fileReadNormal.open("fisier1.txt", ios::in);
	Produs pCitire;
	fileReadNormal >> pCitire;
	cout << "obiectul citit din fisier normal este: " << endl << pCitire;
	fileReadNormal.close();

	//scrierea in fisier binar

	ofstream fileWriteBinar;
	fileWriteBinar.open("fisierBinar.dat", ios::binary | ios::out);
	fileWriteBinar << pFisier;
	fileWriteBinar.close();

	//citirea din fisier binar

	ifstream fileReadBinar;
	fileReadBinar.open("fisierBinar.dat", ios::binary | ios::in);
	Produs pCitire2;
	fileReadBinar >> pCitire2;
	cout << "Obiectul citit ddin fisierul binar este: " << endl << pCitire2;
	fileReadBinar.close();

	/// STL
	
	//vector

	cout << endl << "STL -> vector" << endl;
	vector<string> produseNoi;
	produseNoi.push_back("Fond de ten");
	produseNoi.push_back("Tus");
	produseNoi.push_back("Rimel");
	for (int i = 0; i < produseNoi.size(); i++) {
		cout << produseNoi[i] << " ";
	}
	cout << endl;

	sort(produseNoi.begin(), produseNoi.end());
	cout << "Iterator 1" << endl;
	vector<string>::iterator it;
	for (it = produseNoi.begin(); it != produseNoi.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	cout << "Iterator 2" << endl;
	produseNoi.pop_back();
	for (it = produseNoi.begin(); it != produseNoi.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//lista

	
	cout << endl << "STL -> lista" << endl;
	list<float> preturi;
	preturi.push_back(100.3f);
	preturi.push_front(124.55f);
	preturi.push_back(99);
	preturi.push_front(99.99f);

	list<float>::iterator it2;
	for (it2 = preturi.begin(); it2 != preturi.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	//stergere
	preturi.pop_front();
	for (it2 = preturi.begin(); it2 != preturi.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	//sortare
	preturi.sort();
	for (it2 = preturi.begin(); it2 != preturi.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	//lista reversed
	preturi.reverse();
	for (it2 = preturi.begin(); it2 != preturi.end(); it2++) {
		cout << *it2 << " ";
	}
	cout << endl;

	//set

	cout << endl << "STL -> set" << endl;
	set<string> numeBranduri;
	numeBranduri.insert("Huda Beauty");
	numeBranduri.insert("Fenty Beauty");
	numeBranduri.insert("Too Faced");
	numeBranduri.insert("Anastasia");
	numeBranduri.insert("Too Faced");
	numeBranduri.insert("Too Faced");
	numeBranduri.insert("Anastasia");
	
	set<string>::iterator it3;
	for (it3 = numeBranduri.begin(); it3 != numeBranduri.end(); it3++) {
		cout << *it3 << " ";
	}
	cout << endl;

	it3 = numeBranduri.find("Anastasia");
	if (it3 != numeBranduri.end()) {
		cout << "S-a gasit numele brandului" << endl;
	}
	else {
		cout << "Nu s-a gasit numele brandului" << endl;
	}


	//map

	cout << endl << "STL -> map" << endl;
	Produs pMap1;
{
		// aici am folosit { } pentru a putea declara din nou parametrii pentru constructor, avand restul main-ului comentat
		char* categorie = new char[strlen("ten") + 1];
		strcpy(categorie, "ten");
		std::string denumire = "panda";
		float cantitate = 1.2;
		float pret = 100;
		int nrRating = 5;
		int* rating = new int[nrRating];
		srand(time(NULL));
		vectorRandom(nrRating, rating);
		int cumparariLunare[12];
		for (int i = 0; i < 12; i++) {
			cumparariLunare[i] = i + 100;
		}
}
	Produs pMap2(categorie, denumire, cantitate, pret, nrRating, rating, cumparariLunare);

	Produs pMap3;

	
	map<int, Produs> prod;
	prod.insert(make_pair(1, pMap1));
	prod.insert(make_pair(2, pMap2));
	prod.insert(make_pair(3, pMap3));

	map<int, Produs>::iterator it4;
	for (it4 = prod.begin(); it4 != prod.end(); it4++) {
		cout << "Produsul numarul " << it4->first << " este produsul: " << endl << it4->second << endl;
	}

	cout << "Apel map dupa cheie prod[2] = " << endl << prod[3] << endl;

//5. Apelarea meniului e la final => nu se ajunge la el, nu e folosit
	///MENIU
	
	cout << "-------- Console Menu --------" << endl;
	cout << "Optiunea 1: scrierea unui obiectului default din clasa Produs in fisier text." << endl;
	cout << "Optiunea 2: afisarea in consola a obiectului default din clasa Producatori." << endl;
	cout << "Optiunea 3: citeste produsul din fisierul text fisier1." << endl;
	cout << "Optiunea 4: adaugarea in vectorul produseNoi un produs." << endl;
	cout << "Optiunea 5: iesire din meniu" << endl;
	cout << endl << "Alege o optiune (1/2/3/4/5)" << endl;

	int optiune;
	cin >> optiune;
	cout << endl;

	switch (optiune) {
	case 1: {
		Produs pFisierMeniu;
		ofstream fileWriteNormal;
		fileWriteNormal.open("fisier.txt", ios::out);
		fileWriteNormal << pFisierMeniu;
		fileWriteNormal.close();
		break;
	}
	case 2: {
		Producatori producMeniu;
		producMeniu.afisare();
		break;
	}
	case 3: {
		ifstream fileReadNormal;
		fileReadNormal.open("fisier1.txt", ios::in);
		Produs pCitire;
		fileReadNormal >> pCitire;
		cout << "obiectul citit din fisier normal este: " << endl << pCitire;
		fileReadNormal.close();
	}
	case 4: {
		 // aici am folosit { } pentru a putea testa meniul, avand restul main-ului comentat
			vector<string> produseNoi;
			produseNoi.push_back("Fond de ten");
			produseNoi.push_back("Tus");
			produseNoi.push_back("Rimel");
		
		produseNoi.push_back("Farduri");
		for (int i = 0; i < produseNoi.size(); i++) {
			cout << produseNoi[i] << " ";
		}
		break;
	}
	case 5: {
		cout << "Menu exit" << endl;
		break;
	}
	default:
		cout << "Optiune aleasa gresit";
	}

	return 0;
}