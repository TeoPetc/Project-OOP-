#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


enum DISPONIBILITATE { VANDUT = 0, DISPONIBIL = 1 };

class IFileImobil {
	virtual void writetofile(fstream& f) = 0;
	virtual void readfromfile(fstream& f) = 0;
};

class Imobil : public IFileImobil {
private:
	const int Id_Imobil = 0;
	char* Adresa_Imobil = nullptr;
	float Pret_Imobil = 0;
	DISPONIBILITATE disponibilitate = DISPONIBILITATE::DISPONIBIL;
	int nr_camere = 0;
	float* suprafata_camere = nullptr;
	static int nr_imobile;

public:

	Imobil() {
		this->Adresa_Imobil = new char[strlen("Necunoscut") + 1];
		strcpy(this->Adresa_Imobil, "Necunscut");
	}

	// 2 CONSTRUCTORI CU PARAMETRII

	Imobil(const int _id_imobil, float _pret_imobil) : Id_Imobil(_id_imobil), Pret_Imobil(_pret_imobil) {
		Adresa_Imobil = new char[strlen("Necunoscut") + 1];
		strcpy(Adresa_Imobil, "Necunoscut");
		disponibilitate = DISPONIBILITATE::VANDUT;
		nr_camere = 0;
		suprafata_camere = nullptr;

		nr_imobile++;
	}

	Imobil(const int _Id_Imobil, const char* _Adresa_Imobil, float _Pret_Imobil, DISPONIBILITATE _disponibilitate, int _nr_camere, float* _suprafata_camere) :
		Id_Imobil(_Id_Imobil), Pret_Imobil(_Pret_Imobil), disponibilitate(_disponibilitate), nr_camere(_nr_camere)
	{
		Adresa_Imobil = new char[strlen(_Adresa_Imobil) + 1];
		strcpy(Adresa_Imobil, _Adresa_Imobil);
		if (nr_camere > 0)
		{
			suprafata_camere = new float[nr_camere];
			for (int i = 0; i < nr_camere; i++)
				suprafata_camere[i] = _suprafata_camere[i];
		}
		else
			suprafata_camere = nullptr;

		nr_imobile++;
	}

	//CONSTRUCTOR DE COPIERE
	Imobil(const Imobil& imb) : Id_Imobil(imb.Id_Imobil)
	{
		Adresa_Imobil = new char[strlen(imb.Adresa_Imobil) + 1];
		strcpy(Adresa_Imobil, imb.Adresa_Imobil);
		Pret_Imobil = imb.Pret_Imobil;
		disponibilitate = imb.disponibilitate;
		nr_camere = imb.nr_camere;
		if (imb.nr_camere > 0)
		{
			suprafata_camere = new float[nr_camere];
			for (int i = 0; i < nr_camere; i++)
				suprafata_camere[i] = imb.suprafata_camere[i];
		}
		else
			suprafata_camere = nullptr;
	}

	//SUPRAINCARCARE OPERATOR =
	Imobil& operator = (const Imobil& imb)
	{
		if (this != &imb)
		{
			*(int*)&Id_Imobil = imb.Id_Imobil;
			Adresa_Imobil = new char[strlen(imb.Adresa_Imobil) + 1];
			strcpy(Adresa_Imobil, imb.Adresa_Imobil);
			Pret_Imobil = imb.Pret_Imobil;
			disponibilitate = imb.disponibilitate;
			nr_camere = imb.nr_camere;
			if (imb.nr_camere > 0)
			{
				suprafata_camere = new float[nr_camere];
				for (int i = 0; i < nr_camere; i++)
					suprafata_camere[i] = imb.suprafata_camere[i];
			}
			else
				suprafata_camere = nullptr;
		}
		nr_imobile++;
		return *this;

	}

	//FUNCTII DE TIP ACCESOR SI SETTERI
	int getId_Imobil()
	{
		return Id_Imobil;
	}

	string getAdresa_Imobil()
	{
		return Adresa_Imobil;
	}

	float getPret_Imobil()
	{
		return Pret_Imobil;
	}

	DISPONIBILITATE getDisponibilitate()
	{
		if (disponibilitate == 1)
		{
			return disponibilitate;
		}
		else if (disponibilitate == 0)
		{
			return disponibilitate;
		}
	}

	int getNr_Camere()
	{
		return nr_camere;
	}

	float& getSuprafataCamere()
	{
		if (nr_camere > 0)
		{
			cout << "Suprafata camere: ";
			for (int i = 0; i < nr_camere - 1; i++)
				cout << this->suprafata_camere[i] << ' ';
			return suprafata_camere[nr_camere - 1];
		}
		else
		{
			cout << "Nu se cunoaste suprafata etajelor";
			return  *suprafata_camere;
		}
	}

	static int getNr_Imobile()
	{
		return Imobil::nr_imobile;
	}

	void setAdresa_Imobil(const char* adresa)
	{
		Adresa_Imobil = new char[strlen(adresa) + 1];
		strcpy(Adresa_Imobil, adresa);
	}

	void setPret_Imobil(float n)
	{
		if (n > 0)
		{
			Pret_Imobil = n;
		}
	}

	void setDisponibilitate(DISPONIBILITATE n)
	{
		disponibilitate = n;
	}

	void setSuprafata_Camere(int n, float* v)
	{
		if (n > 0)
		{
			nr_camere = n;
			suprafata_camere = new float[n];
			for (int i = 0; i < n; i++)
				suprafata_camere[i] = v[i];
		}
		else
			cout << "Date incorecte!";
	}

	//METODA PENTRU AFISARE
	void Afisare() {
		cout << "Id Imobil: " << Id_Imobil << endl;
		cout << "Adresa Imobil: " << Adresa_Imobil << endl;
		cout << "Pret Imobil: " << Pret_Imobil << " euro" << endl;
		cout << "Vandut/Disponibil: ";
		if (disponibilitate == 0)
			cout << "Vandut" << endl;
		else if (disponibilitate == 1)
			cout << "Disponibil" << endl;
		cout << "Nr Camere: " << nr_camere << endl;
		if (nr_camere > 0)
		{
			cout << "Suprafata Camere: ";
			for (int i = 0; i < nr_camere; i++)
			{
				cout << "Suprafata camera " << i + 1 << ": " << suprafata_camere[i] << ' ';
				cout << endl;
			}
		}
		else
			cout << "Nu se cunoate numarul/suprafata camerelor!\n" << endl;
	}

	//SUPRANINCARCARE OPERATOR << (OSTREAM)
	friend ostream& operator <<(ostream& out, const Imobil& imb)
	{
		out << "Id Imobil: " << imb.Id_Imobil << endl;
		out << "Adresa Imobil: " << imb.Adresa_Imobil << endl;
		out << "Pret Imobil: " << imb.Pret_Imobil << " euro" << endl;
		out << "Vandut/Disponibil: ";
		if (imb.disponibilitate == 0)
			out << "Vandut" << endl;
		else if (imb.disponibilitate == 1)
			out << "Disponibil" << endl;
		out << "Nr Camere: " << imb.nr_camere << endl;
		if (imb.nr_camere > 0)
		{
			for (int i = 0; i < imb.nr_camere; i++)
			{
				out << "Suprafata camera " << i + 1 << ": " << imb.suprafata_camere[i] << ' ';
				out << endl;
			}
		}
		else
			out << "Nu se cunoate numarul/suprafata camerelor!";
		out << endl;
		return out;
	}

	//SUPRAINCARCARE OPERATOR >> (ISTREAM)
	friend istream& operator >>(istream& in, Imobil& imb) {
		char buffer[200];
		in.clear();
		in.ignore();
		cout << "Adresa Imobil: (Strada_Nr._Oras_Judet): ";
		in.getline(buffer, 199);
		imb.Adresa_Imobil = new char[strlen(buffer) + 1];
		strcpy(imb.Adresa_Imobil, buffer);
		cout << "Id Imobil: ";
		in >> *(int*)&imb.Id_Imobil;
		cout << "Pret imobil: "; in >> imb.Pret_Imobil;
		cout << "Disponibil/Vandut: (1-Disponibil, 0-Vandut)  ";
		int val; in >> val;
		switch (val)
		{
		case 0:
			imb.disponibilitate = DISPONIBILITATE::VANDUT;
			break;
		case 1:
			imb.disponibilitate = DISPONIBILITATE::DISPONIBIL;
			break;
		}
		/*if (val != 0 && val != 1) {
			while (val != 0 && val != 1)
			{
				cout << "Valoare gresit introdusa, va rugam introduceti o valoare valida: ";
				in >> val;
			}
			if (val == 0)
				imb.disponibilitate = DISPONIBILITATE::VANDUT;
			else if (val == 1)
				imb.disponibilitate = DISPONIBILITATE::DISPONIBIL;
		}
		else if (val == 0)
			imb.disponibilitate = DISPONIBILITATE::VANDUT;
		else if (val == 1)
			imb.disponibilitate = DISPONIBILITATE::DISPONIBIL;*/
		cout << "Nr Camere: "; in >> imb.nr_camere;
		if (imb.nr_camere > 0)
		{
			imb.suprafata_camere = new float[imb.nr_camere];
			for (int i = 0; i < imb.nr_camere; i++) {
				cout << "Suprafata camera " << i + 1 << ": ";
				in >> imb.suprafata_camere[i];
			}
		}
		else
		{
			imb.suprafata_camere = nullptr;
			cout << endl;
		}
		return in;
	}

	//SUPRAINCARCARE OPERATOR ==
	friend bool operator==(Imobil const& l, Imobil const& r)
	{
		if (l.Pret_Imobil == r.Pret_Imobil && l.disponibilitate == r.disponibilitate && l.Id_Imobil == r.Id_Imobil && l.nr_camere == r.nr_camere)
		{
			if (strcmp(l.Adresa_Imobil, r.Adresa_Imobil) == 0)
			{
				for (int i = 0, j = 0; i < l.nr_camere && j < r.nr_camere; i++, j++)
				{
					if (l.suprafata_camere[i] == r.suprafata_camere[j])
						return true;
					else
						return false;
				}
			}
			else
				return false;
		}
		else
			return false;
	}

	//SUPRAINCARCARE OPERATOR DE INDEXARE []
	float operator[](int idx)
	{
		if (idx >= 0 && idx < nr_camere)
		{
			if (nr_camere > 0 && idx < nr_camere)
				return suprafata_camere[idx];
		}
		else {
			float s = 1;
			for (int i = 0; i < nr_camere; i++)
				s += i;
			cout << "Index gresit! Numarul de camere este: ";
			return s;
		}
	}

	//SUPRAINCARCARE OPERATOR +
	Imobil operator +(float p)
	{
		Imobil copie = *this;
		copie.setPret_Imobil(getPret_Imobil() + p);
		return copie;
	}

	//SUPRAINCARCARE OPERATOR -
	Imobil operator -(float p)
	{
		Imobil copie = *this;
		if (p < getPret_Imobil())
		{
			copie.setPret_Imobil(getPret_Imobil() - p);
			return copie;
		}
		else {
			cout << "Modificare imposibila!";
			return copie;
		}
	}

	void writetofile(fstream& f)
	{
		f.write((char*)&this->Id_Imobil, sizeof(int));
		char buffer[200];
		strcpy(buffer, this->Adresa_Imobil);
		f.write(buffer, sizeof(buffer));
		/*int NrCaractere = strlen(this->Adresa_Imobil) + 1;
		f.write((char*)&NrCaractere, sizeof(int));
		f.write(this->Adresa_Imobil, NrCaractere * sizeof(char));*/
		f.write((char*)&this->Pret_Imobil, sizeof(float));
		f.write((char*)&this->disponibilitate, sizeof(DISPONIBILITATE));
		f.write((char*)&this->nr_camere, sizeof(int));
		for (int i = 0; i < this->nr_camere; i++)
			f.write((char*)&this->suprafata_camere[i], sizeof(float));
	}

	void readfromfile(fstream& f)
	{
		f.read(((char*)&this->Id_Imobil), sizeof(int));
		char bufferAdresa[200];
		f.read(bufferAdresa, sizeof(bufferAdresa));
		if (this->Adresa_Imobil != nullptr)
			delete[] Adresa_Imobil;
		this->Adresa_Imobil = new char[strlen(bufferAdresa) + 1];
		strcpy(this->Adresa_Imobil, bufferAdresa);
		f.read((char*)&this->Pret_Imobil, sizeof(float));
		f.read((char*)&this->disponibilitate, sizeof(DISPONIBILITATE));
		f.read((char*)&this->nr_camere, sizeof(int));
		if (this->suprafata_camere != nullptr) {
			delete[] this->suprafata_camere;
			this->suprafata_camere = nullptr;
		}
		if (this->nr_camere > 0 && this->nr_camere < 100) {
			this->suprafata_camere = new float[this->nr_camere];
			for (int i = 0; i < this->nr_camere; i++)
				f.read((char*)&this->suprafata_camere[i], sizeof(float));
		}
		else
		{


			this->suprafata_camere = nullptr;
			this->nr_camere = 0;

		}
	}

	friend ofstream& operator<<(ofstream& out, const Imobil& imb);
	friend ifstream& operator>>(ifstream& in, Imobil& imb);
	friend void raportTEXT();
	friend void raportBINAR();

	virtual float CalculSuprafataTotala()
	{
		float s = 0;
		if (nr_camere > 0)
		{
			for (int i = 0; i < nr_camere; i++)
				s += suprafata_camere[i];
		}
		return s;
	}

	//DESTRUCTORUL CLASEI IMOBIL
	~Imobil()
	{
		nr_imobile--;
		if (Adresa_Imobil != nullptr) {
			delete[] Adresa_Imobil;
			Adresa_Imobil = nullptr;
		}
		if (suprafata_camere != nullptr) {
			delete[] suprafata_camere;
			suprafata_camere = nullptr;
		}
	}

};

int Imobil::nr_imobile = 0;

ofstream& operator<<(ofstream& out, const Imobil& imb) {
	out << imb.Id_Imobil;
	out << endl << imb.Adresa_Imobil << endl;
	out << imb.Pret_Imobil << endl;
	out << imb.nr_camere << endl;
	if (imb.nr_camere > 0)
		for (int i = 0; i < imb.nr_camere; i++)
			out << imb.suprafata_camere[i] << endl;
	return out;
}

ifstream& operator>>(ifstream& in, Imobil& imb) {
	in >> *(int*)&imb.Id_Imobil;

	in.clear();
	char buffer[200];
	in.clear();
	in.getline(buffer, 199);
	imb.Adresa_Imobil = new char[strlen(buffer) + 1];
	strcpy(imb.Adresa_Imobil, buffer);

	in >> imb.Pret_Imobil;
	in >> imb.nr_camere;
	if (imb.nr_camere > 0)
	{
		delete[] imb.suprafata_camere;
		imb.suprafata_camere = new float[imb.nr_camere];
		for (int i = 0; i < imb.nr_camere; i++)
			in >> imb.suprafata_camere[i];
	}
	else
	{
		imb.nr_camere = 0;
		imb.suprafata_camere = nullptr;
	}
	int val; in >> val;
	switch (val)
	{
	case 0:
		imb.disponibilitate = DISPONIBILITATE::VANDUT;
		break;
	case 1:
		imb.disponibilitate = DISPONIBILITATE::DISPONIBIL;
		break;
	}

	return in;

}

void raportTEXT()
{
	ifstream f("test.txt");
	Imobil i101, i102, i103, i104, i105, i106, i107, i108;
	f >> i102 >> i103 >> i106 >> i107 >> i108 >> i101;
	cout << i103 << i106 << i107 << i108 << i101;
	f.close();

}

void raportBINAR()
{

	fstream fIn("fisier.txt", ios::in | ios::binary);
	Imobil i111, i112, i113, i114, i115, i116, i117, i118;
	i111.readfromfile(fIn);
	i112.readfromfile(fIn);
	i113.readfromfile(fIn);
	i114.readfromfile(fIn);
	i115.readfromfile(fIn);
	fIn.close();
	cout << i111;
	cout << i112;
	cout << i113;
	cout << i114;
	cout << i115;

}

class IFileAgentie {
	virtual void writetofile(fstream& f) = 0;
	virtual void readfromfile(fstream& f) = 0;
};

class AgentieImobiliara : public IFileAgentie {
private:
	char* Denumire_Agentie = nullptr;
	Imobil* lista_imobile = nullptr;
	int nr_imobile;
	Imobil* lista_imobile_vandute = nullptr;
	int nr_imb_vandute = 0;
public:

	//2 CONSTRUCTORI CU PARAMETRI
	AgentieImobiliara(const char* _denumire_agentie = "Anonim")
	{
		if (Denumire_Agentie != nullptr)
		{
			delete[] Denumire_Agentie;
			Denumire_Agentie = nullptr;
		}
		Denumire_Agentie = new char[strlen(_denumire_agentie) + 1];
		strcpy(Denumire_Agentie, _denumire_agentie);
		nr_imobile = 0;
		lista_imobile = nullptr;
	}

	AgentieImobiliara(const char* _denumire_agentie, int _nr_imobile, Imobil* _lista_imobile) :nr_imobile(_nr_imobile)
	{
		if (Denumire_Agentie != nullptr)
		{
			delete[] Denumire_Agentie;
			Denumire_Agentie = nullptr;
		}
		Denumire_Agentie = new char[strlen(_denumire_agentie) + 1];
		strcpy(Denumire_Agentie, _denumire_agentie);
		if (nr_imobile > 0)
		{
			if (lista_imobile != nullptr)
			{
				delete[] lista_imobile;
				lista_imobile = nullptr;
			}
			lista_imobile = new Imobil[nr_imobile];
			for (int i = 0; i < nr_imobile; i++)
				lista_imobile[i] = _lista_imobile[i];
		}
		else
			lista_imobile = nullptr;
	}

	//CONSTRUCTOR DE COPIERE
	AgentieImobiliara(const AgentieImobiliara& ai)
	{
		nr_imobile = ai.nr_imobile;
		Denumire_Agentie = new char[strlen(ai.Denumire_Agentie) + 1];
		strcpy(Denumire_Agentie, ai.Denumire_Agentie);
		if (ai.nr_imobile > 0)
		{
			if (lista_imobile != nullptr)
			{
				delete[] lista_imobile;
				lista_imobile = nullptr;
			}
			lista_imobile = new Imobil[ai.nr_imobile];
			for (int i = 0; i < ai.nr_imobile; i++)
				lista_imobile[i] = ai.lista_imobile[i];
		}
		else
			lista_imobile = nullptr;
	}

	//SUPRAINCARCARE OPERATOR =
	AgentieImobiliara& operator = (const AgentieImobiliara& ai)
	{
		if (this != &ai)
		{
			nr_imobile = ai.nr_imobile;
			Denumire_Agentie = new char[strlen(ai.Denumire_Agentie) + 1];
			strcpy(Denumire_Agentie, ai.Denumire_Agentie);
			if (ai.nr_imobile > 0)
			{
				if (lista_imobile != nullptr)
				{
					delete[] lista_imobile;
					lista_imobile = nullptr;
				}
				lista_imobile = new Imobil[ai.nr_imobile];
				for (int i = 0; i < ai.nr_imobile; i++)
					lista_imobile[i] = ai.lista_imobile[i];
			}
			else
				lista_imobile = nullptr;
		}
		return *this;
	}

	//FUNCTII DE TIP ACCESOR SI SETTERI
	int getNr_Imobile()
	{
		return nr_imobile;
	}

	char* getDenumire_Agentie()
	{
		return Denumire_Agentie;
	}

	int getNr_Imb_Vandute()
	{
		return nr_imb_vandute;
	}


	Imobil& getImobile()
	{
		if (nr_imobile > 0)
		{
			for (int i = 0; i < nr_imobile - 1; i++)
				cout << this->lista_imobile[i] << '\n';
			return lista_imobile[nr_imobile - 1];
		}
		else
		{
			cout << "Nu se cunoaste suprafata camerelor";
			return  *lista_imobile;
		}
	}

	void setDenumire_Agentie(const char* denumire)
	{
		if (Denumire_Agentie != nullptr)
		{
			delete[] Denumire_Agentie;
			Denumire_Agentie = nullptr;
			Denumire_Agentie = new char[strlen(denumire) + 1];
			strcpy(Denumire_Agentie, denumire);
		}
		else
		{
			Denumire_Agentie = new char[strlen(denumire) + 1];
			strcpy(Denumire_Agentie, denumire);
		}
	}

	void setImobile(int n, Imobil* lista)
	{
		if (n > 0 && lista != nullptr)
		{
			nr_imobile = n;
			if (lista_imobile != nullptr)
			{
				delete[] lista_imobile;
				lista_imobile = nullptr;
			}
			lista_imobile = new Imobil[n];
			for (int i = 0; i < n; i++)
				lista_imobile[i] = lista[i];
		}
		else
			cout << "Date gresite";
	}

	//METODA PENTRU AFISARE
	void Afisare()
	{
		cout << "Denumire Agentie Imobiliara: " << Denumire_Agentie << endl;
		cout << "Numar imobile: " << nr_imobile << endl;
		if (nr_imobile > 0)
		{
			for (int i = 0; i < nr_imobile; i++)
				cout << "Imobil " << i + 1 << " :" << lista_imobile[i] << endl;
		}
		else
			cout << "Agentia nu are imobile in portofoliu!\n" << endl;
	}

	//SUPRAINCARCARE OPERATOR << (OSTREAM)
	friend ostream& operator <<(ostream& out, const AgentieImobiliara& ai)
	{
		out << "Denumire Agentie Imobiliara: " << ai.Denumire_Agentie << endl;
		out << "Numar imobile: " << ai.nr_imobile << endl;
		if (ai.nr_imobile > 0)
		{
			for (int i = 0; i < ai.nr_imobile; i++)
				out << "Imobil " << i + 1 << " :\n" << ai.lista_imobile[i] << endl;
		}
		else
			out << "Agentia nu are imobile in portofoliu!" << endl;
		return out;
	}

	//SUPRAINCARCARE OPERATOR >> (ISTREAM)
	friend istream& operator >>(istream& in, AgentieImobiliara& ai)
	{
		cout << "Denumire Agentie Imobiliara: ";
		char buffer[200];
		in.ignore();
		delete[] ai.Denumire_Agentie;
		in.getline(buffer, 199);
		ai.Denumire_Agentie = new char[strlen(buffer) + 1];
		strcpy(ai.Denumire_Agentie, buffer);
		cout << "Numar Imobile: "; in >> ai.nr_imobile;
		if (ai.nr_imobile > 0)
		{
			if (ai.lista_imobile != nullptr)
			{
				delete[] ai.lista_imobile;
				ai.lista_imobile = nullptr;
			}
			ai.lista_imobile = new Imobil[ai.nr_imobile];
			for (int i = 0; i < ai.nr_imobile; i++)
				in >> ai.lista_imobile[i];
		}
		else
			ai.lista_imobile = nullptr;
		return in;
	}

	//SUPRAINCARCARE OPERATOR [] DE INDEXARE
	Imobil& operator[](int idx)
	{
		if (idx >= 0 && idx < nr_imobile)
		{
			if (nr_imobile > 0 && idx < nr_imobile)
				return lista_imobile[idx];
		}
		else
			cout << "Index gresit!";
	}

	//METODA CALCUL VALOARE TOTALA IMOBILE
	float ValoareImobile()
	{
		float s = 0;
		if (nr_imobile > 0)
		{
			for (int i = 0; i < nr_imobile; i++)
				if (lista_imobile[i].getDisponibilitate() == 1)
					s += lista_imobile[i].getPret_Imobil();
				else
					;
			return s;
		}
		else
			return 0;
	}

	float ValoareImobileVandute()
	{
		float s = 0;
		if (nr_imb_vandute > 0)
		{
			for (int i = 0; i < nr_imb_vandute; i++)
				if (lista_imobile_vandute[i].getDisponibilitate() == 0)
					s += lista_imobile_vandute[i].getPret_Imobil();
				else
					;
			return s;
		}
		else
			return 0;
	}

	void writetofile(fstream& f)
	{
		int NrCaractere = strlen(this->Denumire_Agentie) + 1;
		f.write((char*)&NrCaractere, sizeof(int));
		f.write(this->Denumire_Agentie, NrCaractere * sizeof(char));
		f.write((char*)&this->nr_imobile, sizeof(int));
		if (this->lista_imobile != nullptr)
			delete[] this->lista_imobile;
		this->lista_imobile = new Imobil[this->nr_imobile];
		for (int i = 0; i < this->nr_imobile; i++)
			f.write((char*)&this->lista_imobile[i], sizeof(Imobil));

	}

	void readfromfile(fstream& f)
	{
		char bufferDenumire[200];
		f.read(bufferDenumire, sizeof(bufferDenumire));
		if (this->Denumire_Agentie != nullptr)
			delete[] Denumire_Agentie;
		this->Denumire_Agentie = new char[strlen(bufferDenumire) + 1];
		strcpy(this->Denumire_Agentie, bufferDenumire);
		f.read((char*)&this->nr_imobile, sizeof(int));
		if (this->lista_imobile != nullptr)
			delete[] this->lista_imobile;
		if (this->nr_imobile > 0) {
			this->lista_imobile = new Imobil[this->nr_imobile];
			for (int i = 0; i < this->nr_imobile; i++)
				f.read((char*)&this->lista_imobile[i], sizeof(double));
		}
		else
		{
			this->lista_imobile = nullptr;
			this->nr_imobile = 0;

		}
	}

	void addImobil(Imobil& i)
	{
		nr_imobile++;
		if (nr_imobile > 0)
		{
			Imobil* lista_veche = lista_imobile;
			lista_imobile = new Imobil[nr_imobile];
			for (int i = 0; i < nr_imobile - 1; i++)
			{
				lista_imobile[i] = lista_veche[i];
			}
			/*Imobil nou;
			cin >> nou;
			cout << nou;*/
			lista_imobile[nr_imobile - 1] = i;
			delete[] lista_veche;
		}
	}

	void deleteImobil(int index) {
		if (lista_imobile[index].getDisponibilitate() == 1)
		{
			if (nr_imobile >= 0 && index < nr_imobile && index >= 0) {
				nr_imobile--;
				Imobil* lista_veche = lista_imobile;

				nr_imb_vandute++;
				Imobil* lista_imobile_vandute_veche = lista_imobile_vandute;
				lista_imobile_vandute = new Imobil[nr_imb_vandute];
				for (int k = 0; k < nr_imb_vandute - 1; k++)
					lista_imobile_vandute[k] = lista_imobile_vandute_veche[k];
				lista_veche[index].setDisponibilitate(DISPONIBILITATE::VANDUT);
				lista_imobile_vandute[nr_imb_vandute - 1] = lista_veche[index];
				if (lista_imobile_vandute_veche != nullptr)
					delete[] lista_imobile_vandute_veche;

				if (nr_imobile > 0) {

					lista_imobile = new Imobil[nr_imobile];
					for (int i = 0, j = 0; (i < nr_imobile + 1) && (j < nr_imobile); i++, j++) {
						if (index != i && index <= nr_imobile) {
							lista_imobile[j] = lista_veche[i];
						}
						else
						{
							j--;
						}
					}
					if (lista_veche != nullptr)
						delete[] lista_veche;
				}
			}
			else {
				cout << "index gresit";
			}
		}
		else
		{
			cout << "\nImobil deja vandut!" << endl;
		}
	}


	friend ofstream& operator<<(ofstream& out, AgentieImobiliara& ai);
	friend ifstream& operator>>(ifstream& in, AgentieImobiliara& ai);

	//DESTRUCTOR
	~AgentieImobiliara()
	{
		if (lista_imobile != nullptr) {
			delete[] lista_imobile;
			lista_imobile = nullptr;
		}
		if (Denumire_Agentie != nullptr) {
			delete[] Denumire_Agentie;
			Denumire_Agentie = nullptr;
		}
	}

};

ofstream& operator <<(ofstream& out, AgentieImobiliara& ai)
{
	out << ai.Denumire_Agentie << endl;
	out << ai.nr_imobile << endl;
	if (ai.nr_imobile > 0)
	{
		for (int i = 0; i < ai.nr_imobile; i++)
		{
			out << ai.lista_imobile[i] << endl;
		}
	}
	return out;
}

ifstream& operator >>(ifstream& in, AgentieImobiliara& ai)
{
	in.clear();
	char buffer[200];
	in.clear();
	in.getline(buffer, 199);
	ai.Denumire_Agentie = new char[strlen(buffer) + 1];
	strcpy(ai.Denumire_Agentie, buffer);
	in >> ai.nr_imobile;
	if (ai.nr_imobile > 0)
	{
		delete[] ai.lista_imobile;
		ai.lista_imobile = new Imobil[ai.nr_imobile];
		for (int i = 0; i < ai.nr_imobile; i++)
			in >> ai.lista_imobile[i];
	}
	else
	{
		ai.nr_imobile = 0;
		ai.lista_imobile = nullptr;
	}
	return in;
}


class IFileClienti {
	virtual void writetofile(fstream& f) = 0;
	virtual void readfromfile(fstream& f) = 0;
};

class Clienti {
private:
	int id_client = 0;
	char* nume_client = nullptr;
	int varsta_client = 0;
	char* adresa_client = nullptr;
	int nr_rate = 0;
	float lista_rate[200] = {};
public:

	//2 CONSTRUCTORI CU PARAMETRI
	Clienti(int _id_client, int _varsta_client) : id_client(_id_client), varsta_client(_varsta_client)
	{
		nume_client = new char[strlen("Necunoscut") + 1];
		strcpy(nume_client, "Necunoscut");
		adresa_client = new char[strlen("Necunoscut") + 1];
		strcpy(adresa_client, "Necunoscut");
		nr_rate = 0;
	}

	Clienti(int _id_client = 0, const char* _nume_client = "Necunoscut", int _varsta_client = 0, const char* _adresa_client = "Ascuns", int _nr_rate = 0, float* _lista_rate = nullptr) :
		id_client(_id_client), varsta_client(_varsta_client), nr_rate(_nr_rate)
	{
		nume_client = new char[strlen(_nume_client) + 1];
		strcpy(nume_client, _nume_client);
		adresa_client = new char[strlen(_adresa_client) + 1];
		strcpy(adresa_client, _adresa_client);
		if (nr_rate > 0 && nr_rate < 199)
		{
			for (int i = 0; i < nr_rate; i++)
				lista_rate[i] = _lista_rate[i];
		}
	}

	//CONSTRUCTOR COPIERE
	Clienti(Clienti& c)
	{
		id_client = c.id_client;
		nume_client = new char[strlen(c.nume_client) + 1];
		strcpy(nume_client, c.nume_client);
		varsta_client = c.varsta_client;
		adresa_client = new char[strlen(c.adresa_client) + 1];
		strcpy(adresa_client, c.adresa_client);
		nr_rate = c.nr_rate;
		if (c.nr_rate > 0 && c.nr_rate < 199)
		{
			for (int i = 0; i < c.nr_rate; i++)
				lista_rate[i] = c.lista_rate[i];
		}
	}

	//SUPRAINCARCARE OPERATOR =
	Clienti& operator = (const Clienti& c)
	{
		if (this != &c)
		{
			id_client = c.id_client;
			nume_client = new char[strlen(c.nume_client) + 1];
			strcpy(nume_client, c.nume_client);
			varsta_client = c.varsta_client;
			adresa_client = new char[strlen(c.adresa_client) + 1];
			strcpy(adresa_client, c.adresa_client);
			nr_rate = c.nr_rate;
			if (c.nr_rate > 0 && c.nr_rate < 199)
			{
				for (int i = 0; i < c.nr_rate; i++)
					lista_rate[i] = c.lista_rate[i];
			}
		}
		return *this;
	}

	//FUNCTII DE ACCES SI SETTERI
	int getId_Client()
	{
		return id_client;
	}

	char* getNume_Client()
	{
		return nume_client;
	}

	int getVartsa_Client()
	{
		return varsta_client;
	}

	char* getAdresa_Client()
	{
		return adresa_client;
	}

	int getNr_Rate()
	{
		return nr_rate;
	}

	float getLista_Rate()
	{
		if (nr_rate > 0)
		{
			cout << "Lista rate: ";
			for (int i = 0; i < nr_rate - 1; i++)
				cout << lista_rate[i] << " ";
			return lista_rate[nr_rate - 1];
		}
		else
			return lista_rate[0] = 0;
	}

	void setLista_Rate(int n, float* v)
	{
		if (n > 0 && n < 199)
		{
			for (int i = 0; i < nr_rate; i++)
				lista_rate[i] = v[i];
		}
		else
			cout << "Numarul de rate este gresit! ( 1 <= rate <= 200)" << endl;
	}

	void setId_Client(int n)
	{
		id_client = n;
	}

	void setNume_Client(const char* nume)
	{
		if (nume_client != nullptr)
		{
			delete[] nume_client;
			nume_client = nullptr;
			nume_client = new char[strlen(nume) + 1];
			strcpy(nume_client, nume);
		}
		else
		{
			nume_client = new char[strlen(nume) + 1];
			strcpy(nume_client, nume);
		}
	}

	void setVarsta_Client(int n)
	{
		varsta_client = n;
	}

	void setAdresa_Client(const char* adresa)
	{
		if (adresa_client != nullptr)
		{
			delete[] adresa_client;
			adresa_client = nullptr;
			adresa_client = new char[strlen(adresa) + 1];
			strcpy(adresa_client, adresa);
		}
		else
		{
			adresa_client = new char[strlen(adresa) + 1];
			strcpy(adresa_client, adresa);
		}
	}

	//METODA AFISARE
	void Afisare()
	{
		cout << "\nId Client: " << id_client << endl;
		cout << "Nume Client: " << nume_client << endl;
		cout << "Varsta Client: " << varsta_client << endl;
		cout << "Adresa Client: " << adresa_client << endl;
		cout << "Nr rate: " << nr_rate << endl;
		if (nr_rate > 0 && nr_rate < 199)
		{
			cout << "Lista Rate: " << endl;
			for (int i = 0; i < nr_rate; i++)
				cout << "Rata " << i + 1 << ": " << lista_rate[i] << "euro" << endl;
		}
		else
			cout << "Nu se cunoaste numarul de rate!" << endl;

		cout << endl;
	}

	//SUPRAINCARCARE OPERATOR << (OSTREAM)
	friend ostream& operator <<(ostream& out, const Clienti& c)
	{
		out << "\nId Client: " << c.id_client << endl;
		out << "Nume Client: " << c.nume_client << endl;
		out << "Varsta Client: " << c.varsta_client << endl;
		out << "Adresa Client: " << c.adresa_client << endl;
		out << "Nr rate: " << c.nr_rate << endl;
		if (c.nr_rate > 0 && c.nr_rate < 199)
		{
			out << "Lista Rate: " << endl;
			for (int i = 0; i < c.nr_rate; i++)
				out << "Rata " << i + 1 << ": " << c.lista_rate[i] << " euro" << endl;
		}
		else
			out << "Nu se cunoaste numarul de rate!" << endl;
		return out;
	}

	//SUPRAINCARCARE OPERATOR >> (ISTREAM)
	friend istream& operator >>(istream& in, Clienti& c)
	{
		cout << "Nume client: ";
		char buffer[200];
		in.ignore();
		in.getline(buffer, 199);
		delete[] c.nume_client;
		c.nume_client = new char[strlen(buffer) + 1];
		strcpy(c.nume_client, buffer);
		cout << "Adresa client: ";
		in.getline(buffer, 199);
		delete[] c.adresa_client;
		c.adresa_client = new char[strlen(buffer) + 1];
		strcpy(c.adresa_client, buffer);
		cout << "Id client: "; in >> c.id_client;
		cout << "Varsta client: "; in >> c.varsta_client;
		cout << "Nr Rate: "; in >> c.nr_rate;
		if (c.nr_rate > 0 && c.nr_rate < 199)
		{
			cout << "Lista Rate: " << endl;
			for (int i = 0; i < c.nr_rate; i++)
			{
				cout << "Rata " << i + 1 << ": ";
				in >> c.lista_rate[i];
			}
		}
		return in;
	}

	//SUPRAINCARCARE OPERATOR [] DE INDEXARE
	float& operator[](int idx)
	{
		if (idx >= 0 && idx < nr_rate)
		{
			return lista_rate[idx];
		}
		else {
			cout << "Index gresit!";
			return lista_rate[0] = 0;
		}
	}

	//METODA CALCUL VALOARE TOTALA IMOBILE
	float ValoareRate()
	{
		float s = 0;
		if (nr_rate > 0)
		{
			for (int i = 0; i < nr_rate; i++)
				s += lista_rate[i];
			return s;
		}
		else
			return 0;
	}

	void writetofile(fstream& f)
	{
		f.write((char*)&this->id_client, sizeof(int));
		int NrCaractereNume = strlen(this->nume_client) + 1;
		f.write((char*)&NrCaractereNume, sizeof(int));
		f.write(this->nume_client, NrCaractereNume * sizeof(char));
		f.write((char*)&this->varsta_client, sizeof(int));
		int NrCaractereAdresa = strlen(this->adresa_client) + 1;
		f.write((char*)&NrCaractereAdresa, sizeof(int));
		f.write(this->adresa_client, NrCaractereAdresa * sizeof(char));
		f.write((char*)&this->nr_rate, sizeof(int));
		for (int i = 0; i < this->nr_rate; i++)
			f.write((char*)&this->lista_rate[i], sizeof(float));

	}

	void readfromfile(fstream& f)
	{
		f.read((char*)&this->id_client, sizeof(int));
		char bufferNume[200];
		f.read(bufferNume, sizeof(bufferNume));
		if (this->nume_client != nullptr)
			delete[] nume_client;
		this->nume_client = new char[strlen(bufferNume) + 1];
		strcpy(this->nume_client, bufferNume);
		f.read((char*)&this->varsta_client, sizeof(int));
		char bufferAdresa[200];
		f.read(bufferAdresa, sizeof(bufferAdresa));
		if (this->adresa_client != nullptr)
			delete[] adresa_client;
		this->adresa_client = new char[strlen(bufferAdresa) + 1];
		strcpy(this->adresa_client, bufferAdresa);
		f.read((char*)&this->nr_rate, sizeof(int));
		if (this->nr_rate > 0)
		{

			for (int i = 0; i < this->nr_rate; i++)
				f.read((char*)&this->lista_rate[i], sizeof(int));
		}
		else
		{
			nr_rate = 0;
		}
	}

	friend ofstream& operator<<(ofstream& out, Clienti& c);
	friend ifstream& operator>>(ifstream& in, Clienti& c);


	//DESTRUCTORUL CLASEI CLIENTI
	~Clienti()
	{
		delete[] nume_client;
	}
};

ofstream& operator<<(ofstream& out, Clienti& a)
{
	out << a.id_client << endl;
	out << a.nume_client << endl;
	out << a.varsta_client << endl;
	out << a.adresa_client << endl;

	if (a.nr_rate > 0) {
		out << a.nr_rate << endl;

		for (int i = 0; i < a.nr_rate; i++)
		{
			out << a.lista_rate[i] << endl;

		}
	}

	return out;
}

ifstream& operator>>(ifstream& in, Clienti& a)
{
	in >> a.id_client;
	char buffer[200];
	in.clear();
	in.getline(buffer, 199);
	a.nume_client = new char[strlen(buffer) + 1];
	strcpy(a.nume_client, buffer);
	in >> a.varsta_client;
	in >> a.nr_rate;
	if (a.nr_rate > 0)
	{
		for (int i = 0; i < a.nr_rate; i++)
			in >> a.lista_rate[i];
	}
	else
	{
		a.nr_rate = 0;
	}

	return in;
}

class IFileAngajati {
	virtual void writetofile(fstream& f) = 0;
	virtual void readfromfile(fstream& f) = 0;
};

class Angajati {
private:
	char* Nume_Prenume_Angajat = nullptr;
	int varsta = 0;
	float comision_imobile_vandute[100] = {};
	int nr_imb_vandute = 0;
	int id = 0;
public:
	//2 CONSTRUCTORI CU PARAMETRI
	Angajati(const char* nume_angajat = "Anonim")
	{
		if (Nume_Prenume_Angajat != nullptr)
		{
			delete[] Nume_Prenume_Angajat;
			Nume_Prenume_Angajat = nullptr;
		}
		Nume_Prenume_Angajat = new char[strlen(nume_angajat) + 1];
		strcpy(Nume_Prenume_Angajat, nume_angajat);
		varsta = 0;
		nr_imb_vandute = 0;
		id = 0;
	}

	Angajati(int _id, const char* nume_angajat, int _varsta, int _nr_imb_vandute, float* _imobile_vandute) :
		id(_id), varsta(_varsta), nr_imb_vandute(_nr_imb_vandute)
	{
		if (Nume_Prenume_Angajat != nullptr)
		{
			delete[] Nume_Prenume_Angajat;
			Nume_Prenume_Angajat = nullptr;
		}
		Nume_Prenume_Angajat = new char[strlen(nume_angajat) + 1];
		strcpy(Nume_Prenume_Angajat, nume_angajat);
		if (nr_imb_vandute > 0)
		{
			for (int i = 0; i < nr_imb_vandute; i++)
				comision_imobile_vandute[i] = _imobile_vandute[i];
		}
		else
			;
	}

	//CONSTRUCTOR DE COPIERE
	Angajati(const Angajati& a) : id(a.id), varsta(a.varsta), nr_imb_vandute(a.nr_imb_vandute)
	{
		Nume_Prenume_Angajat = new char[strlen(a.Nume_Prenume_Angajat) + 1];
		strcpy(Nume_Prenume_Angajat, a.Nume_Prenume_Angajat);
		if (nr_imb_vandute > 0)
		{
			for (int i = 0; i < nr_imb_vandute; i++)
				comision_imobile_vandute[i] = a.comision_imobile_vandute[i];
		}
		else
			;
	}

	//SUPRAINCARCARE OPERATOR =
	Angajati& operator =(const Angajati& a)
	{
		if (this != &a)
		{
			id = a.id;
			varsta = a.varsta;
			nr_imb_vandute = a.nr_imb_vandute;
			Nume_Prenume_Angajat = new char[strlen(a.Nume_Prenume_Angajat) + 1];
			strcpy(Nume_Prenume_Angajat, a.Nume_Prenume_Angajat);
			if (nr_imb_vandute > 0)
			{
				for (int i = 0; i < nr_imb_vandute; i++)
					comision_imobile_vandute[i] = a.comision_imobile_vandute[i];
			}
			else
				;
		}
		return *this;
	}

	//FUNCTII DE TIP ACCESOR SI SETTERI
	char* getNume_Prenume_A()
	{
		return Nume_Prenume_Angajat;
	}

	int getId_Angajat()
	{
		return id;
	}

	int getVarsta_Angajat()
	{
		return varsta;
	}

	int getNr_Imb_Vandute()
	{
		return nr_imb_vandute;
	}

	float getComisionImobileVandute()
	{
		if (nr_imb_vandute > 0)
		{
			cout << "Lista comisioane: (%)";
			for (int i = 0; i < nr_imb_vandute - 1; i++)
				cout << comision_imobile_vandute[i] << ' ';
			return comision_imobile_vandute[nr_imb_vandute - 1];
		}
		else
			return comision_imobile_vandute[0] = 0;
	}

	void setId(int n)
	{
		id = n;
	}

	void setNume_Prenume_A(const char* a)
	{
		if (Nume_Prenume_Angajat != nullptr)
		{
			delete[] Nume_Prenume_Angajat;
			Nume_Prenume_Angajat = nullptr;
			Nume_Prenume_Angajat = new char[strlen(a) + 1];
			strcpy(Nume_Prenume_Angajat, a);
		}
		else
		{
			Nume_Prenume_Angajat = new char[strlen(a) + 1];
			strcpy(Nume_Prenume_Angajat, a);
		}
	}

	void setVarsta(int n)
	{
		varsta = n;
	}

	void setComision(int n, float* v)
	{
		if (n > 0 && v != nullptr)
		{
			nr_imb_vandute = n;
			for (int i = 0; i < n; i++)
				comision_imobile_vandute[i] = v[i];
		}
		else
			nr_imb_vandute = 0;
	}

	float CalculComisioaneTotale()
	{
		float s = 0;
		if (nr_imb_vandute > 0)
		{
			for (int i = 0; i < nr_imb_vandute; i++)
				s += comision_imobile_vandute[i];
			return s;
		}
		else
			return 0;
	}

	//METODA PENTRU AFISARE
	void Afisare()
	{
		cout << "\nId Angajat: " << id << endl;
		cout << "Nume si prenume angajat: " << Nume_Prenume_Angajat << endl;
		cout << "Varsta: " << varsta << endl;
		cout << "Nr imobile vandute: " << nr_imb_vandute << endl;
		if (nr_imb_vandute > 0)
		{
			for (int i = 0; i < nr_imb_vandute; i++)
				cout << "Comision pentru imobilul " << i + 1 << ": " << comision_imobile_vandute[i] << "%" << endl;
		}
		else
			cout << "Angajatul nu are imobile vandute!" << endl;

	}

	//SUPRAINCARCARE OPERATOR << (OSTREAM)
	friend ostream& operator<<(ostream& out, const Angajati& a)
	{
		out << "\nId Angajat: " << a.id << endl;
		out << "Nume si prenume angajat: " << a.Nume_Prenume_Angajat << endl;
		out << "Varsta: " << a.varsta << endl;
		out << "Nr imobile vandute: " << a.nr_imb_vandute << endl;
		if (a.nr_imb_vandute > 0)
		{
			for (int i = 0; i < a.nr_imb_vandute; i++)
				out << "Comision aferent imobilului " << i + 1 << ": " << a.comision_imobile_vandute[i] << "%" << endl;
		}
		else
			out << "Angajatul nu are imobile vandute!" << endl;
		return out;
	}

	//SUPRAINCARCARE OPERATOR >> (ISTREAM)
	friend  istream& operator>>(istream& in, Angajati& a)
	{
		cout << "Nume si prenume angajat: ";
		char buffer[200];
		in.ignore();
		in.getline(buffer, 199);
		delete[] a.Nume_Prenume_Angajat;
		a.Nume_Prenume_Angajat = new char[strlen(buffer) + 1];
		strcpy(a.Nume_Prenume_Angajat, buffer);
		cout << "Id Angajat: "; in >> a.id;
		cout << "Varsta Angajat: "; in >> a.varsta;
		cout << "Nr Imobile vandute de angajat: "; in >> a.nr_imb_vandute;
		if (a.nr_imb_vandute > 0)
		{
			for (int i = 0; i < a.nr_imb_vandute; i++)
			{
				cout << "Comisionul aferent imobilului: " << i + 1 << ": ";
				in >> a.comision_imobile_vandute[i];
			}
		}
		else
			cout << "Angajatul nu are imobile vandute!" << endl;
		return in;
	}

	//SUPRAINCACARE OPERATOR ++ (PRE-INCREMENTARE)
	Angajati& operator++() {
		this->comision_imobile_vandute[nr_imb_vandute - 1] = this->comision_imobile_vandute[nr_imb_vandute - 1] + 0.05;
		return *this;
	}

	//SUPRAINCACARE OPERATOR ++ (POST-INCREMENTARE)
	Angajati operator++(int) {
		Angajati copie = *this;
		this->comision_imobile_vandute[nr_imb_vandute - 1] = this->comision_imobile_vandute[nr_imb_vandute - 1] + 0.05;
		return copie;
	}

	//SUPRAINCARCARE OPERATOR DE CAST
	operator int() {
		return nr_imb_vandute;
	}

	//SUPRAINCARCARE OPERATOR ! (daca nr imobile vandute este egal cu 0 returneaza true, adica angajatul nu a vandut imobile)
	bool operator! ()
	{
		return (nr_imb_vandute == 0);
	}

	//SUPRAINCARCARE OPERATOR < 
	friend bool operator <(Angajati const& l, Angajati const& r)
	{
		float sum1 = 0, sum2 = 0;
		for (int i = 0; i < l.nr_imb_vandute; i++)
			sum1 += l.comision_imobile_vandute[i];
		for (int i = 0; i < r.nr_imb_vandute; i++)
			sum2 += r.comision_imobile_vandute[i];
		if (sum1 < sum2)
			return true;
		else
			return false;

	}

	void writetofile(fstream& f)
	{
		f.write((char*)&this->id, sizeof(int));
		int NrCaractereNume = strlen(this->Nume_Prenume_Angajat) + 1;
		f.write((char*)&NrCaractereNume, sizeof(int));
		f.write(this->Nume_Prenume_Angajat, NrCaractereNume * sizeof(char));
		f.write((char*)&this->varsta, sizeof(int));
		f.write((char*)&this->nr_imb_vandute, sizeof(int));
		for (int i = 0; i < this->nr_imb_vandute; i++)
			f.write((char*)&this->comision_imobile_vandute[i], sizeof(float));
	}

	void readfromfile(fstream& f)
	{
		f.read((char*)&this->id, sizeof(int));
		char bufferNume[200];
		f.read(bufferNume, sizeof(bufferNume));
		if (this->Nume_Prenume_Angajat != nullptr)
			delete[] Nume_Prenume_Angajat;
		this->Nume_Prenume_Angajat = new char[strlen(bufferNume) + 1];
		strcpy(this->Nume_Prenume_Angajat, bufferNume);
		f.read((char*)&this->varsta, sizeof(int));
		f.read((char*)&this->nr_imb_vandute, sizeof(int));
		if (this->nr_imb_vandute > 0)
		{

			for (int i = 0; i < this->nr_imb_vandute; i++)
				f.read((char*)&this->comision_imobile_vandute[i], sizeof(int));
		}
		else
		{
			nr_imb_vandute = 0;
		}
	}

	friend ofstream& operator<<(ofstream& out, Angajati& imb);
	friend ifstream& operator>>(ifstream& in, Angajati& imb);

	//DESTRUCTOR
	~Angajati()
	{
		if (Nume_Prenume_Angajat != nullptr)
		{
			delete[] Nume_Prenume_Angajat;
			Nume_Prenume_Angajat = nullptr;
		}
	}
};

ofstream& operator<<(ofstream& out, Angajati& a)
{
	out << a.id << endl;
	out << a.Nume_Prenume_Angajat << endl;
	out << a.varsta << endl;

	if (a.nr_imb_vandute > 0) {
		out << a.nr_imb_vandute << endl;

		for (int i = 0; i < a.nr_imb_vandute; i++)
		{
			out << a.comision_imobile_vandute[i] << endl;

		}
	}

	return out;
}

ifstream& operator>>(ifstream& in, Angajati& a)
{
	in >> a.id;
	char buffer[200];
	in.clear();
	in.getline(buffer, 199);
	a.Nume_Prenume_Angajat = new char[strlen(buffer) + 1];
	strcpy(a.Nume_Prenume_Angajat, buffer);
	in >> a.varsta;
	in >> a.nr_imb_vandute;
	if (a.nr_imb_vandute > 0)
	{
		for (int i = 0; i < a.nr_imb_vandute; i++)
			in >> a.comision_imobile_vandute[i];
	}
	else
	{
		a.nr_imb_vandute = 0;
	}

	return in;
}

class IFileProprietari {
	virtual void writetofile(fstream& f) = 0;
	virtual void readfromfile(fstream& f) = 0;
};

class Proprietari {
private:
	char* nume = nullptr;
	double pret_imobil = 0;
	int nr_camere = 0;
	float suprafata_camere[100] = {};

public:

	//2 CONSTRUCTORI CU PARAMETRI
	Proprietari(const char* _nume = "Anonim")
	{
		if (nume != nullptr)
		{
			delete[] nume;
			nume = nullptr;
		}
		nume = new char[strlen(_nume) + 1];
		strcpy(nume, _nume);
		pret_imobil = 0;
		nr_camere = 0;
	}

	Proprietari(const char* _nume, double _pret, int _nr_camere, float* _suprafata_camere) :
		pret_imobil(_pret), nr_camere(_nr_camere)
	{
		if (nume != nullptr)
		{
			delete[] nume;
			nume = nullptr;
		}
		nume = new char[strlen(_nume) + 1];
		strcpy(nume, _nume);
		if (nr_camere > 0)
		{
			for (int i = 0; i < nr_camere; i++)
				suprafata_camere[i] = _suprafata_camere[i];
		}
		else
			;
	}

	//CONSTRUCTOR DE COPIERE
	Proprietari(const Proprietari& p) :pret_imobil(p.pret_imobil), nr_camere(p.nr_camere)
	{
		if (nume != nullptr)
		{
			delete[] nume;
			nume = nullptr;
		}
		nume = new char[strlen(p.nume) + 1];
		strcpy(nume, p.nume);
		if (nr_camere > 0)
		{
			for (int i = 0; i < nr_camere; i++)
				suprafata_camere[i] = p.suprafata_camere[i];
		}
		else
			;
	}

	//SUPRAINCARCARE OPERATOR =
	Proprietari& operator =(const Proprietari& p)
	{
		if (this != &p)
		{
			pret_imobil = p.pret_imobil;
			nr_camere = p.nr_camere;
			if (nume != nullptr)
			{
				delete[] nume;
				nume = nullptr;
			}
			nume = new char[strlen(p.nume) + 1];
			strcpy(nume, p.nume);
			if (nr_camere > 0)
			{
				for (int i = 0; i < nr_camere; i++)
					suprafata_camere[i] = p.suprafata_camere[i];
			}
			else
				;
		}
		return *this;
	}

	//FUNCTII DE TIP ACCESOR SI SETTERI
	char* getNume()
	{
		return nume;
	}

	int getNr_Camere()
	{
		return nr_camere;
	}

	double getPret()
	{
		return pret_imobil;
	}

	float getSuprafata_Camere()
	{
		if (nr_camere > 0)
		{
			cout << "Suprafata camere: ";
			for (int i = 0; i < nr_camere - 1; i++)
				cout << suprafata_camere[i] << ' ';
			return suprafata_camere[nr_camere - 1];
		}
	}

	void setNume(const char* n)
	{
		if (nume != nullptr)
		{
			delete[] nume;
			nume = nullptr;
			nume = new char[strlen(n) + 1];
			strcpy(nume, n);
		}
		else
		{
			nume = new char[strlen(n) + 1];
			strcpy(nume, n);
		}
	}

	void setPret(double n)
	{
		pret_imobil = n;
	}

	void setSuprafata_Camere(int n, float* v)
	{
		if (n > 0 && v != nullptr)
		{
			nr_camere = n;
			for (int i = 0; i < n; i++)
				suprafata_camere[i] = v[i];
		}
		else
			nr_camere = 0;
	}

	//METODA PENTRU AFISARE
	void Afisare()
	{
		cout << "\nNume Proprietar: " << nume << endl;
		cout << "Pret Imobil: " << pret_imobil << endl;
		cout << "Nr Camere: " << nr_camere << endl;
		if (nr_camere > 0)
		{
			for (int i = 0; i < nr_camere; i++)
				cout << "Camera " << i + 1 << ": " << suprafata_camere[i] << endl;
		}
		else
			cout << "Nu se cunoaste numarul/suprafata camerelor!" << endl;
	}

	//SUPRAINCARCARE OPERATOR << (OSTREAM)
	friend ostream& operator<<(ostream& out, const Proprietari& p)
	{
		out << "\nNume Proprietar: " << p.nume << endl;
		out << "Pret Imobil: " << p.pret_imobil << endl;
		out << "Nr Camere: " << p.nr_camere << endl;
		if (p.nr_camere > 0)
		{
			for (int i = 0; i < p.nr_camere; i++)
				out << "Camera " << i + 1 << ": " << p.suprafata_camere[i] << endl;
		}
		else
			out << "Nu se cunoaste numarul/suprafata camerelor!" << endl;
		return out;
	}

	//SUPRAINCARCARE OPERATOR >> (ISTREAM)
	friend istream& operator>>(istream& in, Proprietari& p)
	{
		in.ignore();
		cout << "Nume Proprietar: ";
		in.clear();
		char buffer[200];
		in.getline(buffer, 199);
		delete[] p.nume;
		p.nume = new char[strlen(buffer) + 1];
		strcpy(p.nume, buffer);
		cout << "Pret Imobil: "; in >> p.pret_imobil;
		cout << "Nr Camere: "; in >> p.nr_camere;
		if (p.nr_camere > 0)
		{
			cout << "Suprafata Camere: ";
			for (int i = 0; i < p.nr_camere; i++)
			{
				cout << "Suprafata camera " << i + 1 << ": ";
				in >> p.suprafata_camere[i];
			}
		}
		else
			cout << "Nu se cunoaste numarul/suprafata camerelor!" << endl;
		return in;
	}

	//SUPRAINCARCARE OPERATOR [] DE INDEXARE
	float& operator[](int idx)
	{
		if (idx >= 0 && idx < nr_camere)
		{
			return suprafata_camere[idx];
		}
		else {
			cout << "Index gresit!";
			return suprafata_camere[0] = 0;
		}
	}

	void writetofile(fstream& f)
	{
		int NrCaractereNume = strlen(this->nume) + 1;
		f.write((char*)&NrCaractereNume, sizeof(int));
		f.write(this->nume, NrCaractereNume * sizeof(char));
		f.write((char*)&this->pret_imobil, sizeof(double));
		f.write((char*)&this->nr_camere, sizeof(int));
		for (int i = 0; i < this->nr_camere; i++)
			f.write((char*)&this->suprafata_camere[i], sizeof(float));
	}

	void readfromfile(fstream& f)
	{
		char bufferNume[200];
		f.read(bufferNume, sizeof(bufferNume));
		if (this->nume != nullptr)
			delete[] nume;
		this->nume = new char[strlen(bufferNume) + 1];
		strcpy(this->nume, bufferNume);
		f.read((char*)&this->pret_imobil, sizeof(double));
		f.read((char*)&this->nr_camere, sizeof(int));
		if (this->nr_camere > 0)
		{

			for (int i = 0; i < this->nr_camere; i++)
				f.read((char*)&this->suprafata_camere[i], sizeof(int));
		}
		else
		{
			nr_camere = 0;
		}
	}

	//DESTRUCTOR
	~Proprietari()
	{
		if (nume != nullptr)
		{
			delete[] nume;
			nume = nullptr;
		}
	}

};

class FileManager {

public:
	FileManager() {

		//constructor default
	}

	void SalvareImobil(Imobil vector[], int n, const char* numeFisier)
	{
		ofstream fisier(numeFisier, ios::out | ios::trunc);
		if (fisier)
		{
			for (int i = 0; i < n; i++)
				fisier << vector[i] << " ";
		}
		else
		{
			cerr << "EROARE: Fisierul '" << numeFisier << "' nu a putut fi deschis pentru scriere." << endl;
		}

		cout << "Vector cu " << n << " elemente:" << endl;
		for (int i = 0; i < n; i++)
			cout << vector[i] << " ";
		cout << endl;
	}

	void IncarcareImobil(Imobil vector[], int& n, const char* numeFisier)
	{
		// deschidem fisierul pentru citire
		ifstream fisier(numeFisier);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// citim numarul de elemente din fisier
			fisier >> n;
			// citim elementele vectorului
			for (int i = 0; i < n; i++)
				fisier >> vector[i];
		}
		else
		{
			// afisam un mesaj de eroare
			cerr << "EROARE: Fisierul " << numeFisier << " nu a putut fi deschis pentru citire." << endl;
		}
		// fisierul este inchis automat de constructorul
		// clasei ifstream
	}

	void SalvareAgentie(AgentieImobiliara vector[], int n, const char* numeFisier)
	{
		// deschidem fisierul text pentru scriere
		// (si il suprascriem daca este cazul)
		ofstream fisier(numeFisier, ios::out | ios::trunc);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// scriem numarul de elemente pe prima linie
			//fisier << n << endl;
			// scriem elementele separate prin spatiu
			for (int i = 0; i < n; i++)
				fisier << vector[i] << " ";
		}
		else
		{
			// altfel efisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier
				<< "' nu a putut fi deschis pentru scriere." << endl;
		}
		for (int i = 0; i < n; i++)
			cout << vector[i] << " ";
	}

	void IncarcareAgentie(AgentieImobiliara vector[], int& n, const char* numeFisier)
	{
		// deschidem fisierul pentru citire
		ifstream fisier(numeFisier);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// citim numarul de elemente din fisier
			fisier >> n;
			// citim elementele vectorului
			for (int i = 0; i < n; i++)
				fisier >> vector[i];
		}
		else
		{
			// afisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier << "' nu a putut fi deschis pentru citire." << endl;
		}
	}

	void SalvareClienti(Clienti vector[], int n, const char* numeFisier)
	{
		// deschidem fisierul text pentru scriere
		// (si il suprascriem daca este cazul)
		ofstream fisier(numeFisier, ios::out | ios::trunc);
		// daca fisierul a fost deschis
		if (fisier)
		{
			//// scriem numarul de elemente pe prima linie
			//fisier << n << endl;
			// scriem elementele separate prin spatiu
			for (int i = 0; i < n; i++)
				fisier << vector[i] << " ";
		}
		else
		{
			// altfel efisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier << "' nu a putut fi deschis pentru scriere." << endl;
		}

		cout << "Vector cu " << n << " elemente:" << endl;
		for (int i = 0; i < n; i++)
			cout << vector[i] << " ";
		cout << endl;
	}

	void IncarcareClienti(Clienti vector[], int& n, const char* numeFisier)
	{
		// deschidem fisierul pentru citire
		ifstream fisier(numeFisier);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// citim numarul de elemente din fisier
			fisier >> n;
			// citim elementele vectorului
			for (int i = 0; i < n; i++)
				fisier >> vector[i];
		}
		else
		{
			// afisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier << " nu a putut fi deschis pentru citire." << endl;
		}
		// fisierul este inchis automat de constructorul
		// clasei ifstream
	}

	void SalvareAngajati(Angajati vector[], int n, const char* numeFisier)
	{
		// deschidem fisierul text pentru scriere
		// (si il suprascriem daca este cazul)
		ofstream fisier(numeFisier, ios::out | ios::trunc);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// scriem numarul de elemente pe prima linie
			fisier << n << endl;
			// scriem elementele separate prin spatiu
			for (int i = 0; i < n; i++)
				fisier << vector[i] << " ";
		}
		else
		{
			// altfel efisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier
				<< "' nu a putut fi deschis pentru scriere." << endl;
		}

		cout << "Vector cu " << n << " elemente:" << endl;
		for (int i = 0; i < n; i++)
			cout << vector[i] << " ";
		cout << endl;
	}
	void IncarcareAngajati(Angajati vector[], int& n, const char* numeFisier)
	{
		// deschidem fisierul pentru citire
		ifstream fisier(numeFisier);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// citim numarul de elemente din fisier
			fisier >> n;
			// citim elementele vectorului
			for (int i = 0; i < n; i++)
				fisier >> vector[i];
		}
		else
		{
			cerr << "EROARE: Fisierul '" << numeFisier << "' nu a putut fi deschis pentru citire." << endl;
		}

	}

	void SalvareProprietari(Proprietari vector[], int n, const char* numeFisier)
	{

		ofstream fisier(numeFisier, ios::out | ios::trunc);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// scriem numarul de elemente pe prima linie
			fisier << n << endl;
			// scriem elementele separate prin spatiu
			for (int i = 0; i < n; i++)
				fisier << vector[i] << " ";
		}
		else
		{
			// altfel efisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier << "' nu a putut fi deschis pentru scriere." << endl;
		}
		// fisierul este inchis automat de constructorul
		// clasei ofstream

		cout << "Vector cu " << n << " elemente:" << endl;
		for (int i = 0; i < n; i++)
			cout << vector[i] << " ";
		cout << endl;
	}

	void IncarcareProprietari(Proprietari vector[], int& n, const char* numeFisier)
	{
		// deschidem fisierul pentru citire
		ifstream fisier(numeFisier);
		// daca fisierul a fost deschis
		if (fisier)
		{
			// citim numarul de elemente din fisier
			fisier >> n;
			// citim elementele vectorului
			for (int i = 0; i < n; i++)
				fisier >> vector[i];
			// citim elementele vectorului

		}
		else
		{
			// afisam un mesaj de eroare
			cerr << "EROARE: Fisierul '" << numeFisier << "' nu a putut fi deschis pentru citire." << endl;
		}

		// fisierul este inchis automat de constructorul
		// clasei ifstream
	}

	~FileManager() {

		//destructor
	}
};

class Raport {


public:
	Raport() {

		//constructor
	}

	void raportNrCamereImobil(Imobil vector[5]) {
		ofstream file;
		file.open("raportNrCamereImobil.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 5; i++) {
				{

					file << "\nNr. camerelor imobilului " << i + 1 << " adica " << vector[i].getAdresa_Imobil() << " este de: " << vector[i].getNr_Camere() << " camere.";
				}
			}
		}
		file.close();
		cout << "\nS-a generat raportul pentru nr camere ce corespunde optiunii 3" << endl;
		cout << "Va rugam verificati in folder" << endl;
	}

	void raportSumaComisioane(Angajati vector[5]) {
		ofstream file;
		file.open("raportComisioaneTotale.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 5; i++) {
				{

					file << "\nSuma totala a comisioanelor angajatului " << i + 1 << " adica " << vector[i].getNume_Prenume_A() << " este: " << vector[i].CalculComisioaneTotale() << " lei.";
				}
			}
		}
		file.close();
		cout << "\nS-a generat raportul pentru valoarea comisioanelor ce corespunde optiunii 4" << endl;
		cout << "Va rugam verificati in folder" << endl;
	}

	void raportClienti(Clienti vector[5]) {
		ofstream file;
		file.open("raportClienti.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 5; i++) {
				{

					file << "Cientul " << i + 1 << " este: " << vector[i].getNume_Client() << " si are un numar de " << vector[i].getNr_Rate() << " rate." << endl;
				}
			}
		}
		file.close();
		cout << "\nS-a generat raportul cu date despre clienti ce corespunde optiunii 5" << endl;
		cout << "Va rugam verificati in folder" << endl;
	}

	void raportProprietari(Proprietari vector[5]) {
		ofstream file;
		file.open("raportProprietari.txt", ios::out);
		if (file.is_open()) {
			for (int i = 0; i < 5; i++) {
				{

					file << "Proprietarul " << i + 1 << " este: " << vector[i].getNume() << " si vinde imobilul cu: " << vector[i].getPret() << " lei" << endl;
				}
			}
		}
		file.close();
		cout << "\nS-a generat raportul despre proprietari ce corespunde optiunii 6" << endl;
		cout << "Va rugam verificati in folder" << endl;
	}

	~Raport()
	{
		//destructor
	}

};

void meniu() {


	fstream fOut("fisier.txt", ios::out | ios::binary);
	fstream raportTotal("raportTotal.txt", ios::out);
	FileManager m; Raport r;

	////cout << "\n\t\t\t\t--- CLASA IMOBIL ---" << endl;
	float suprafata_camere1[]{ 7,8.5,6,8 };
	float suprafata_camere2[]{ 9,10.3,7,8.5 };
	float suprafata_camere3[]{ 12, 13.5,10,11 };
	float suprafata_camere4[]{ 7,8.5,9 };

	//constructor toti parametrii
	Imobil i1(1, "Str. Mihai Bravu, nr. 13, bl. 213, Sector 2, Bucuresti", 60000, DISPONIBILITATE::VANDUT, 4, suprafata_camere1);
	Imobil i2(2, "Str. Tudor Arghezi, nr. 155, bl. 2, sc.3, Focsani, jud. Vrancea", 15000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere4);
	Imobil i3(3, "Str. Secuilor, nr. 13, bl.19, sc.7, Sector 4, Bucuresti", 50000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere2);
	Imobil i4(4, "Str. Novacesti, nr. 44, Com. Paunesti, jud. Vrancea", 40000, DISPONIBILITATE::VANDUT, 3, suprafata_camere1);
	Imobil i5(5, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3);

	ofstream g("test.txt");
	g << i1 << i2 << i3 << i4 << i5;
	g.close();
	i1.writetofile(fOut);
	i2.writetofile(fOut);
	i3.writetofile(fOut);
	i4.writetofile(fOut);
	i5.writetofile(fOut);
	fOut.close();

	//cout << "\n\t\t\t\t--- CLASA AgentieImobiliara ---" << endl;

	Imobil li1[] = {
		Imobil(2, "Str. Tudor Arghezi, nr. 155, bl. 2, sc.3, Focsani, jud. Vrancea", 15000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere4),
		Imobil(3, "Str. Novacesti, nr. 44, Com. Paunesti, jud. Vrancea", 40000, DISPONIBILITATE::VANDUT, 3, suprafata_camere1),
		Imobil(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3)
	};
	Imobil li2[] = {
		Imobil(1,"Str. Televiziunii, nr.100, Sectorul 5, Bucuresti",60000, DISPONIBILITATE::VANDUT, 3, suprafata_camere4)
	};
	Imobil li3[] = {
		Imobil(1, "Str. Mihai Bravu, nr. 13, bl. 213, Sector 2, Bucuresti", 60000, DISPONIBILITATE::VANDUT, 4, suprafata_camere1),
		Imobil(2, "Str. Secuilor, nr. 13, bl.19, sc.7, Sector 4, Bucuresti",50000, DISPONIBILITATE::DISPONIBIL,  4, suprafata_camere2),
		Imobil(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3),
		Imobil(5, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3)
	};

	//constructor cu toti parametri 
	AgentieImobiliara ai1("Casa de lux", 1, li2);
	AgentieImobiliara ai2("Casa la cheie", 3, li1);
	AgentieImobiliara ai3("Visuri la cheie", 4, li3);
	AgentieImobiliara ai4("Casa viselor", 3, li1);
	AgentieImobiliara ai5("CasExpert", 1, li2);

	////lucrul cu fisiere text
	//ofstream g("Agentie.txt");
	//g << ai4; //ofstream is a ostream (up cast)
	//g.close();
	AgentieImobiliara ai6;
	//ifstream f("Agentie.txt");

	//f >> ai6;
	//cout << ai6;

	//////scriere in fisier binar
	//fstream fOut("Agentii.txt", ios::out | ios::binary);
	//ai1.writetofile(fOut);
	//fOut.close();

	//////citire
	//fstream fIn("Agentii.txt", ios::in | ios::binary);
	//AgentieImobiliara ai6;
	//ai6.readfromfile(fIn);
	//fIn.close();
	//cout << ai6;


	//cout << "\n\t\t\t\t--- CLASA CLIENTI ---" << endl;

	float r1[]{ 250, 250,250,240 };
	float r2[]{ 300, 300,300 };
	float r3[]{ 350,350,350,300 };
	float r4[]{ 200,200 };

	//constructor cu toti parametri
	Clienti c1(0, "Pancescu Andrei", 25, "Str. Soarelui, nr.44, Adjud, Vrancea", 3, r2);
	Clienti c2(1, "Paizan Andreea", 20, "Str. Novacesti, nr 66, Paunesti, Vrancea", 4, r3);
	Clienti c3(2, "Tanasa Andre", 24, "Str. Principala, nr 88, Paunesti, Vrancea", 4, r1);
	Clienti c4(3, "Bogdan Valetin", 40, "Str. Revolutiei, nr.23, Sector 1, Bucuresti", 4, r3);
	Clienti c5(4, "Ionascu Dragos", 39, "Str. Credintei, nr. 888, Lespezi, Vrancea", 2, r4);

	//cout << "\n\t\t\t\t--- CLASA ANGAJATI ---" << endl;

	float iv1[]{ 0.1,0.15,0.12,0.08 };
	float iv2[]{ 0.15,0.10,0.08,0.09 };
	float iv3[]{ 0.20, 0.08, 0.09 };
	float ivnou[]{ 0.1,0.08,0.12,0.13 };
	Angajati a1(0, "Paraschiv Lenuta", 40, 4, iv1); //constructor default
	Angajati a2(1, "Giangu Darius", 30, 3, iv3); // constructor cu un parametru
	Angajati a3(2, "Maimascu Stefan", 30, 4, iv1); // constructor cu toti parametrii
	Angajati a4(3, "Badarau Ionut", 35, 4, iv2); // constructor cu toti parametrii
	Angajati a5(4, "Drilea Ovidiu", 22, 4, ivnou);

	////scriere in fisier binar
	//fstream fOut("fisier.txt", ios::out | ios::binary);
	//a5.writetofile(fOut);
	//fOut.close();

	//////citire
	//fstream fIn("fisier.txt", ios::in | ios::binary);
	//Angajati a;
	//a.readfromfile(fIn);
	//fIn.close();
	//cout << a;

	//cout << "\n\t\t\t\t--- CLASA PROPRIETARI ---" << endl;

	float sc1[]{ 12,13,10 };
	float sc2[]{ 12.5,14,13,8.5 };
	float sc3[]{ 13,15,10,12.3,14.5 };
	float scnou[]{ 13,13.5,14.5,12.2 };

	Proprietari p1("Ilie Flavian", 70000, 5, sc3); //cosntructor default
	Proprietari p2("Sava Andrei", 35000, 3, sc1); //constructor cu un parametru
	Proprietari p3("Rusu Stefan", 30000, 3, sc1); //constructor cu toti parametrii
	Proprietari p4("Radu Lucian", 40000, 4, sc2); //constructor cu toti parametrii
	Proprietari p5("Paizan Teodor", 50000, 4, scnou);

	int cod;

	do {
		cout << "\t\t\t\t\**********    MENIU!     ***********";//MENIU
		cout << "\n\nAlegeti o optiune: ";
		cout << "\n\t1.Afisare date spectatori/rapoarte(din fisiere text)";
		cout << "\n\t\t11.Afisare date spectatori/rapoarte(din fisiere binare)";
		cout << "\n\t2.Afisare date Clienti";
		cout << "\n\t3.Realizare raport nr. camere per imobil";
		cout << "\n\t4.Realizare raport suma comisoane(%)";
		cout << "\n\t5.Realizare raport nr. rate de client";
		cout << "\n\t6.Realizare raport pretul la care vinde proprietarul";
		cout << "\n\t7.Afisare date Agentii imobiliare/rapoarte(din fisiere text)";
		cout << "\n\t8.Afisare date Angajati";


		cout << "\n\t0.IESIRE\n";

		cin >> cod;
		cout << "\nAti ales optiunea: " << cod << endl;

		switch (cod)
		{
		case 1:
		{
			cout << "\nRaport din fisier text\n";

			{
				Imobil vector[] = { i1,i2,i3,i4,i5 };
				int n = 5;
				m.SalvareImobil(vector, n, "Imobile.txt");
				Imobil vector2[5]; int n2;
				m.IncarcareImobil(vector2, n2, "Imobile.txt");
				raportTEXT();

			}
			break;
		}
		case 11:
		{
			cout << "\nRaport din fisier binar\n";
			raportBINAR();
			break;
		}

		case 2:
		{
			Clienti c8, c9, c10, c11, c12;
			Clienti vector[] = { c1,c2,c3,c4,c5 };
			int n = 5;

			m.SalvareClienti(vector, n, "clienti.txt");
			g.close();

			ifstream f("clienti.txt");
			f >> c8 >> c9 >> c10 >> c11 >> c12;
			f.close();
			break;
		}

		case 3:
		{
			Imobil vectorI[] = { i1,i2,i3,i4,i5 };
			r.raportNrCamereImobil(vectorI);
			break;
		}
		case 4:
		{
			Angajati vectorA[] = { a1,a2,a3,a4,a5 };
			r.raportSumaComisioane(vectorA);
			break;
		}

		case 5:
		{
			Clienti vectorC[] = { c1,c2,c3,c4,c5 };
			r.raportClienti(vectorC);
			break;
		}

		case 6:
		{
			Proprietari vectorP[] = { p1,p2,p3,p4,p5 };
			r.raportProprietari(vectorP);
			break;
		}

		case 7:
		{
			cout << "\nRaport din fisier text\n";

			{
				AgentieImobiliara vector[] = { ai1,ai2,ai3,ai4,ai5 };
				int n = 5;
				m.SalvareAgentie(vector, n, "Agentii.txt");
				AgentieImobiliara vector2[5]; int n2;
				m.IncarcareAgentie(vector2, n2, "Agentii.txt");
				raportTEXT();
			}
			break;
		}
		case 8:
		{
			Angajati a8, a9, a10, a11, a12;
			Angajati vector[] = { a1,a2,a3,a4,a5 };
			int n = 5;

			m.SalvareAngajati(vector, n, "angajati.txt");
			g.close();

			ifstream f("angajati.txt");
			f >> a8 >> a9 >> a10 >> a11 >> a12;
			f.close();
			break;
		}
		}
	} while (cod != 0);
}

class Apartament : public Imobil {
private:
	int nr_etaj = 0;
public:
	Apartament(int id, const char* adresa, float pret, DISPONIBILITATE disponibilitate, int nr_camere, float* v, int _nr_etaj) : Imobil(id, adresa, pret, disponibilitate, nr_camere, v)
	{
		nr_etaj = _nr_etaj;
	}

	Apartament(const Apartament& a) : Imobil(a)
	{
		nr_etaj = a.nr_etaj;
	}

	Apartament operator =(const Apartament& a)
	{
		if (this != &a)
		{
			Imobil::operator=(a);
			nr_etaj = a.nr_etaj;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Apartament& a)
	{
		out << (const Imobil&)a;
		out << "Nr etaj: " << a.nr_etaj << endl;
		return out;
	}

	float CalculSuprafataTotala()
	{
		return Imobil::CalculSuprafataTotala();
	}

	~Apartament()
	{

	}


};

class Casa :public Imobil {
private:
	int nr_etaje;
	float suprafata_curte = 0;
public:
	Casa(int id, const char* adresa, float pret, DISPONIBILITATE disponibilitate, int nr_camere, float* v, int _nr_etaje, float s_c) : Imobil(id, adresa, pret, disponibilitate, nr_camere, v)
	{
		nr_etaje = _nr_etaje;
		suprafata_curte = s_c;
	}

	Casa(const Casa& c) : Imobil(c)
	{
		nr_etaje = c.nr_etaje;
		suprafata_curte = c.suprafata_curte;
	}

	Casa operator =(const Casa& c)
	{
		if (this != &c)
		{
			Imobil::operator=(c);
			nr_etaje = c.nr_etaje;
			suprafata_curte = c.suprafata_curte;
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Casa& c)
	{
		out << (const Imobil&)c << endl;
		out << "Nr etaje: " << c.nr_etaje << endl;
		out << "Suprafata curte" << c.suprafata_curte;
		return out;
	}

	float CalculSuprafataTotala()
	{
		return Imobil::CalculSuprafataTotala() + suprafata_curte;
	}

	~Casa()
	{

	}
};

// FAZA 1

void testareMain() {
	//Testare clase in functia main
	//CLASA IMOBIL
	cout << "\n\t\t\t\t--- CLASA IMOBIL ---" << endl;
	float suprafata_camere1[]{ 7,8.5,6,8 };
	float suprafata_camere2[]{ 9,10.3,7,8.5 };
	float suprafata_camere3[]{ 12, 13.5,10,11 };
	float suprafata_camere4[]{ 7,8.5,9 };

	Imobil i1; //default constructor
	Imobil i2(1, 15000); //constructor cu 2 parametri;
	Imobil i3(2, "Str. Secuilor, nr. 13, bl.19, sc.7, Sector 4, Bucuresti", 50000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere2); //constructor toti parametrii
	Imobil i4(3, "Str. Novacesti, nr. 44, Com. Paunesti, jud. Vrancea", 40000, DISPONIBILITATE::VANDUT, 3, suprafata_camere1);
	Imobil i5(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3);

	//Afisare prin metoda Afisare() si ostream(supraincarcare operator <<)
	i2.Afisare();
	cout << i3 << i4 << i5;

	cout << "In aplicatie sunt inregistrate " << Imobil::getNr_Imobile() << " imobile.\n";//contor nr_imobile(staticul ales)

	//setter si getteri

	i1.setSuprafata_Camere(3, suprafata_camere1);
	cout << endl << i1.getSuprafataCamere() << endl;

	cout << endl << i3.getDisponibilitate() << endl;
	i3.setDisponibilitate(DISPONIBILITATE::VANDUT);
	cout << endl << i3.getDisponibilitate() << endl;

	cout << "\nValori inainte de modificare date:\n";

	cout << endl << "Id imobil 4:" << i4.getId_Imobil();
	cout << endl << "Adresa imobil 3: " << i4.getAdresa_Imobil();
	cout << endl << "Pret imobil 4: " << i4.getPret_Imobil() << endl;
	cout << endl << "Disponibilitate imobil 4: ";
	if (i4.getDisponibilitate() == 1)
		cout << "Imobil DISPONIBIL!\n";
	else if (i4.getDisponibilitate() == 0)
		cout << "Imobil VANDUT\n";
	cout << endl << "Nr camere imobil 4: " << i4.getNr_Camere() << endl;
	cout << endl << i4.getSuprafataCamere() << endl;

	i4.setPret_Imobil(45000);
	i4.setAdresa_Imobil("Str.Novacesti, nr. 44, Com. Domnesti, jud.Vrancea");
	i4.setDisponibilitate(DISPONIBILITATE::DISPONIBIL);
	i4.setSuprafata_Camere(3, suprafata_camere4);

	cout << "\nValori dupa modificare date:\n";

	cout << endl << "Id imobil 4:" << i4.getId_Imobil();
	cout << endl << "Adresa imobil 3: " << i4.getAdresa_Imobil();
	cout << endl << "Pret imobil 4: " << i4.getPret_Imobil() << endl;
	cout << endl << "Disponibilitate imobil 4: ";
	if (i4.getDisponibilitate() == 1)
		cout << "Imobil DISPONIBIL!\n";
	else if (i4.getDisponibilitate() == 0)
		cout << "Imobil VANDUT\n";
	cout << endl << "Nr camere imobil 4: " << i4.getNr_Camere() << endl;
	cout << endl << i4.getSuprafataCamere() << endl;

	//citire si afisare folosind istream si ostream
	/*cin >> i1;
	cout << i1;*/

	//testare operator ==
	if (i4 == i3)
	{
		cout << "\nImobile identice!";
	}
	else
	{
		cout << "\nImobile diferite!";
	}

	Imobil i6, i7;
	if (i6 == i7)
	{
		cout << "\nImobile identice!";
	}
	else
	{
		cout << "\nImobile diferite!";
	}

	//testare operator indexare []
	cout << "\nSuprafata camerei 1 a imobilului 4 este: " << i4[0] << endl;
	//caz in care indexul e gresit -> mesaj informare
	cout << i4[-1] << endl; //index prea mic (negativ)
	cout << i4[5] << endl; //index prea mare

	//testare operator + (creste pretul imobilului si creeaza un obiect nou cu noul pret)

	cout << endl << "oerator +" << endl << "Pret Imobil 6: " << i6.getPret_Imobil() << endl;
	cout << endl << "Pret Imobil 7: " << i7.getPret_Imobil() << endl;
	cout << "\nAm crescut pretul cu 20000 euro" << endl;
	i7 = i6 + 20000;

	cout << endl << "Pret Imobil 6: " << i6.getPret_Imobil() << endl;
	cout << endl << "Pret Imobil 7: " << i7.getPret_Imobil() << endl;

	//testare operator - (scade pretul imobilului si creeaza un obiect nou cu noul pret)
	//daca pretul pe care utilizatorul vrea sa il scada este mai mare decat pretul actual se creeaza un mesaj de avertizare

	Imobil i8;

	cout << endl << "operator -" << endl << "Pret Imobil 7: " << i7.getPret_Imobil() << endl;
	cout << endl << "Pret Imobil 8: " << i8.getPret_Imobil() << endl;

	i8 = i7 - 5000;

	cout << endl << "Pret Imobil 7: " << i7.getPret_Imobil() << endl;
	cout << endl << "Pret Imobil 8: " << i8.getPret_Imobil() << endl;

	cout << "\nCaz eroare la scadere\n" << endl;

	i8 = i7 - 2500;

	//apel constructor de copiere
	Imobil i9(i5);
	cout << "Am copiat in imobilul 9 datele imobilului 5 prin constructorul de copiere\n" << i9;

	//supraincarcare operator =
	i8 = i9;
	cout << "Am copiat in imobilul 8 datele imobilului 9 prin operatorul =\n" << i9 << endl;

	cout << "In aplicatie sunt inregistrate " << Imobil::getNr_Imobile() << " imobile.\n";//contor nr_imobile(staticul ales)

	cout << "\n\t\t\t\t--- CLASA AgentieImobiliara ---" << endl;

	Imobil li1[] = {
		Imobil(),
		Imobil(3, "Str. Novacesti, nr. 44, Com. Paunesti, jud. Vrancea", 40000, DISPONIBILITATE::VANDUT, 3, suprafata_camere1),
		Imobil(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3)
	};
	Imobil li2[] = {
		Imobil(1,"Str. Televiziunii, nr.100, Sectorul 5, Bucuresti",60000, DISPONIBILITATE::VANDUT, 3, suprafata_camere4)
	};
	Imobil li3[] = {
		Imobil(),
		Imobil(1,15000),
		Imobil(2, "Str. Secuilor, nr. 13, bl.19, sc.7, Sector 4, Bucuresti",50000, DISPONIBILITATE::DISPONIBIL,  4, suprafata_camere2),
		Imobil(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3)
	};

	AgentieImobiliara ai1; //constructor default
	AgentieImobiliara ai2("Casa la cheie"); //constructor cu un singur parametru
	//constructor cu toti parametri 
	AgentieImobiliara ai3("Casa viselor", 3, li1);
	AgentieImobiliara ai4("CasExpert", 1, li2);

	//afisare folosind metoda Afisare() si ostream (supraincarcare operator <<)
	ai1.Afisare();
	ai2.Afisare();
	cout << ai3 << ai4;

	//setteri si getteri

	cout << "Datele agentiei " << ai3.getDenumire_Agentie() << " inainte de modificare : \n" << endl;
	cout << "Denumire agentie: " << ai3.getDenumire_Agentie() << endl;
	cout << "\nNumarul imobilelor: " << ai3.getNr_Imobile() << "\n" << endl;
	cout << ai3.getImobile() << endl;

	ai3.setDenumire_Agentie("Casa Viselor tale");
	ai3.setImobile(1, li2);

	cout << "Datele agentiei " << ai3.getDenumire_Agentie() << " dupa modificare : \n" << endl;
	cout << "Denumire agentie: " << ai3.getDenumire_Agentie() << endl;
	cout << "\nNumarul imobilelor: " << ai3.getNr_Imobile() << "\n" << endl;
	cout << ai3.getImobile() << endl;

	//citire si afisare folosind istream si ostream
	/*cin >> ai1;
	cout << ai1;*/

	//TESTARE OPERATORI
	//testare operator [] de indexare

	cout << "Imobilul 1 al agentiei " << ai3.getDenumire_Agentie() << ": \n" << ai3[0];

	//calcul valoare totala imobile disponibile
	AgentieImobiliara ai5("Casa Perfecta", 4, li3);
	cout << "Valoarea imobilelor agentiei " << ai5.getDenumire_Agentie() << " care sunt disponbile este de: " << ai5.ValoareImobile() << " euro" << endl;

	//apel constructor de copiere

	AgentieImobiliara ai6(ai5);
	cout << ai6;

	//copiere prin operatorul = (supraincarcat)
	AgentieImobiliara ai7;
	ai7 = ai4;
	cout << ai7;

	cout << "\n\t\t\t\t--- CLASA CLIENTI ---" << endl;

	float r1[]{ 250, 250,250,240 };
	float r2[]{ 300, 300,300 };
	float r3[]{ 350,350,350,300 };

	Clienti c1; //constructor default
	Clienti c2(1); //constructor 1 parametru
	Clienti c3(2, 36); //constructor 2 parametri
	Clienti c4(3, "Bogdan Valetin", 40, "Str. Revolutiei, nr.23, Sector 1, Bucuresti", 4, r3); //constructor cu toti parametri

	//afisare prin metoda Afisare() si folosind ostream-ul (operator <<)

	c1.Afisare();
	c2.Afisare();
	cout << c3 << c4;

	//setteri si getteri

	cout << "\nDatele clientului " << c4.getNume_Client() << " inainte de modificare.\n";
	cout << "\nId Client: " << c4.getId_Client() << endl;
	cout << "Nume Client: " << c4.getNume_Client() << endl;
	cout << "Varsta Client: " << c4.getVartsa_Client() << endl;
	cout << "Adresa Client: " << c4.getAdresa_Client() << endl;
	cout << "Nr Rate: " << c4.getNr_Rate() << endl;
	cout << c4.getLista_Rate() << endl;

	cout << "\nDatele clientului " << c4.getNume_Client() << " dupa modificare.\n";
	c4.setId_Client(5);
	c4.setNume_Client("Bogdan Andrei-Valentin");
	c4.setAdresa_Client("Str. Revolutiei, nr.23, Sector 2, Bucuresti");
	c4.setVarsta_Client(41);
	c4.setLista_Rate(4, r1);

	cout << "\nDatele clientului " << c4.getNume_Client() << " inainte de modificare.\n";
	cout << "\nId Client: " << c4.getId_Client() << endl;
	cout << "Nume Client: " << c4.getNume_Client() << endl;
	cout << "Varsta Client: " << c4.getVartsa_Client() << endl;
	cout << "Adresa Client: " << c4.getAdresa_Client() << endl;
	cout << "Nr Rate: " << c4.getNr_Rate() << endl;
	cout << c4.getLista_Rate() << endl;

	//citire si afisare folosind istream si ostream
	/*cout << endl;
	cin >> c1;
	cout << c1;*/

	//TESTARE OPERATORI
	//testare operator [] de indexare
	cout << "Valoare rata: " << c4[2] << endl;

	//metoda pentru calcularea valorii totale a ratelor
	cout << "Valoare totala rate: " << c4.ValoareRate() << endl;

	//testare operator =
	Clienti c5;
	c5 = c3;
	cout << c5;

	//apel constructor copiere
	Clienti c6(c4);
	cout << c6;

	cout << "\n\t\t\t\t--- CLASA ANGAJATI ---" << endl;

	float iv1[]{ 0.1,0.15,0.12,0.08 };
	float iv2[]{ 0.15,0.10,0.08,0.09 };
	float ivnou[]{ 0.1,0.08,0.12,0.13 };
	Angajati a1; //constructor default
	Angajati a2("Giangu Darius"); // constructor cu un parametru
	Angajati a3(1, "Maimascu Stefan", 30, 4, iv1); // constructor cu toti parametrii
	Angajati a4(2, "Badarau Ionut", 35, 4, iv2); // constructor cu toti parametrii

	//afisare prin metode Afisare() si prin ostream (operator <<)
	a1.Afisare();
	a2.Afisare();
	cout << a3 << a4;

	//setteri si getter
	cout << "\nDatele angajatului " << a3.getNume_Prenume_A() << " inainte de modificare.\n";
	cout << "\nId Angajat: " << a3.getId_Angajat() << endl;
	cout << "Nume Angajat: " << a3.getNume_Prenume_A() << endl;
	cout << "Varsta Angajat: " << a3.getVarsta_Angajat() << endl;
	cout << "Nr Imobile vandute: " << a3.getNr_Imb_Vandute() << endl;
	cout << a3.getComisionImobileVandute() << endl;

	cout << "\nDatele clientului " << a3.getNume_Prenume_A() << " dupa modificare.\n";
	a3.setId(3);
	a3.setNume_Prenume_A("Maimascu Stefan-Ionut");
	a3.setComision(4, ivnou);
	a3.setVarsta(31);

	cout << "\nDatele angajatului " << a3.getNume_Prenume_A() << " inainte de modificare.\n";
	cout << "\nId Angajat: " << a3.getId_Angajat() << endl;
	cout << "Nume Angajat: " << a3.getNume_Prenume_A() << endl;
	cout << "Varsta Angajat: " << a3.getVarsta_Angajat() << endl;
	cout << "Nr Imobile vandute: " << a3.getNr_Imb_Vandute() << endl;
	cout << a3.getComisionImobileVandute() << endl;

	//citire+afisare folosind istream si ostream
	/*cin >> a1;
	cout << a1;*/

	//TESTARE OPERATORI
	//SUPRAINCACARE OPERATOR ++ (PRE-INCREMENTARE) si (POST_INCREMENTARE)

	cout << endl << "Operator++(pre && post)" << endl;
	cout << a3;
	a1 = a3++;
	cout << "\nOPERATOR ++ POST, DUPA MODIFICARE:" << endl;
	cout << a1 << a3;
	a1 = ++a3;
	cout << "\nOPERATOR ++ PRE, DUPA MODIFICARE:" << endl;
	cout << a1 << a3;

	//SUPRAINCACARE OPERATOR DE CAST -conersie de la angajat la int
	int nr_imb_v = (int)a4;
	cout << "\nNr imobile vandute pentru angajatul " << a4.getNume_Prenume_A() << " este: " << nr_imb_v;

	//SUPRAINCARCARE OPERATOR ! (daca nr imobile vandute este egal cu 0 returneaza true, adica angajatul nu a vandut imobile)
	if (!a3)
		cout << "\nAngajatul " << a3.getNume_Prenume_A() << "nu are imobile vandute" << endl;
	else
		cout << "\nAngajatul " << a3.getNume_Prenume_A() << " are imobile vandute" << endl;


	//SUPRAINCARCARE OPERATOR <
	if (a3 < a4)
		cout << "\nAngajatul " << a4.getNume_Prenume_A() << " are valoare tuturor comisioanelor mai mare decat angajatul " << a3.getNume_Prenume_A() << endl;
	else
		cout << "\nAngajatul " << a3.getNume_Prenume_A() << " are valoare tuturor comisioanelor mai mare decat angajatul " << a4.getNume_Prenume_A() << endl;

	//supraincarcare operator =
	a1 = a3;
	cout << a1;

	//apel constructor de copiere
	Angajati a5(a1);
	cout << a5;

	cout << "\n\t\t\t\t--- CLASA PROPRIETARI ---" << endl;

	float sc1[]{ 12,13,10 };
	float sc2[]{ 12.5,14,13,8.5 };
	float scnou[]{ 13,13.5,14.5,12.2 };

	Proprietari p1; //cosntructor default
	Proprietari p2("Sava Andrei"); //constructor cu un parametru
	Proprietari p3("Rusu Stefan", 30000, 3, sc1); //constructor cu toti parametrii
	Proprietari p4("Radu Lucian", 40000, 4, sc2); //constructor cu toti parametrii

	//afisare prin metoda Afisare() si prin ostream (operator <<)
	p1.Afisare();
	p2.Afisare();
	cout << p3 << p4;

	//setteri si getteri

	cout << "\nDatele proprietarului " << p3.getNume() << " inainte de modificare.\n";
	cout << "Nume Proprietar: " << p3.getNume() << endl;
	cout << "Pret Imobil de vanzare: " << p3.getPret() << endl;
	cout << "Nr Camere: " << p3.getNr_Camere() << endl;
	cout << p3.getSuprafata_Camere() << endl;

	cout << "\nDatele proprietarului " << p3.getNume() << " dupa modificare.\n";

	p3.setPret(35000);
	p3.setNume("Rusu Andrei");
	p3.setSuprafata_Camere(4, scnou);

	cout << "Nume Proprietar: " << p3.getNume() << endl;
	cout << "Pret Imobil de vanzare: " << p3.getPret() << endl;
	cout << "Nr Camere: " << p3.getNr_Camere() << endl;
	cout << p3.getSuprafata_Camere() << endl;

	//citire si afisare folosind istream si ostream (operatorii >> si <<)
	/*cin >> p1;
	cout << p1;*/

	//supraincarcare operator =
	p1 = p3;
	cout << p1;

	//apel constructor de copiere
	Proprietari p5(p1);
	cout << p5;

	//supraincarcare operator [] de indexare
	cout << "Suprafata camerei 3 a proprietarului " << p5.getNume() << " este: " << p5[2] << endl;

	//STL VECTOR

	vector<Imobil> imobil;
	imobil.push_back(i1);
	imobil.push_back(i2);
	imobil.push_back(i3);
	imobil.push_back(i4);
	for (int i = 0; i < imobil.size(); i++)
		cout << imobil[i] << endl;

	//CLASE DERIVATE DIN CLASA IMOBIL + EXEMPLU DE VIRTUALIZARE

	cout << endl;

	float v[]{ 12,13 };
	Casa c(1, "Str. secuilor, nr. 23", 15000, DISPONIBILITATE::VANDUT, 2, v, 3, 500);
	Apartament a(1, "Str. Tudor Vladimirescu, nr. 30", 35000, DISPONIBILITATE::VANDUT, 2, v, 2);
	cout << "Apartamentul are suprafata de: " << a.CalculSuprafataTotala() << endl;
	cout << "Casa are suprafata de: " << c.CalculSuprafataTotala() << endl;

}

void main()
{
	// FAZA 2

	////cout << "\n\t\t\t\t--- CLASA IMOBIL ---" << endl;
	float suprafata_camere1[]{ 7,8.5,6,8 };
	float suprafata_camere2[]{ 9,10.3,7,8.5 };
	float suprafata_camere3[]{ 12, 13.5,10,11 };
	float suprafata_camere4[]{ 7,8.5,9 };

	//constructor toti parametrii
	Imobil i1(1, "Str. Mihai Bravu, nr. 13, bl. 213, Sector 2, Bucuresti", 60000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere1);
	Imobil i2(2, "Str. Tudor Arghezi, nr. 155, bl. 2, sc.3, Focsani, jud. Vrancea", 15000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere4);
	Imobil i3(3, "Str. Secuilor, nr. 13, bl.19, sc.7, Sector 4, Bucuresti", 50000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere2);
	Imobil i4(4, "Str. Novacesti, nr. 44, Com. Paunesti, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere1);
	Imobil i5(5, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3);


	//cout << "\n\t\t\t\t--- CLASA AgentieImobiliara ---" << endl;

	Imobil li1[] = {
		Imobil(2, "Str. Tudor Arghezi, nr. 155, bl. 2, sc.3, Focsani, jud. Vrancea", 15000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere4),
		Imobil(3, "Str. Novacesti, nr. 44, Com. Paunesti, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere1),
		Imobil(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3)
	};
	Imobil li2[] = {
		Imobil(1,"Str. Televiziunii, nr.100, Sectorul 5, Bucuresti",60000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere4)
	};
	Imobil li3[] = {
		Imobil(1, "Str. Mihai Bravu, nr. 13, bl. 213, Sector 2, Bucuresti", 60000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere1),
		Imobil(2, "Str. Secuilor, nr. 13, bl.19, sc.7, Sector 4, Bucuresti",50000, DISPONIBILITATE::DISPONIBIL,  4, suprafata_camere2),
		Imobil(4, "Str. Vasile Alecsandri, nr. 102, bl. 2, sc.4, Focsani, jud. Vrancea", 40000, DISPONIBILITATE::DISPONIBIL, 4, suprafata_camere3),
		Imobil(5,"Str. Televiziunii, nr.100, Sectorul 5, Bucuresti",60000, DISPONIBILITATE::DISPONIBIL, 3, suprafata_camere4)
	};

	//constructor cu toti parametri 
	AgentieImobiliara ai1("Casa de lux", 1, li2);
	AgentieImobiliara ai2("Casa la cheie", 3, li1);
	AgentieImobiliara ai3("Visuri la cheie", 4, li3);
	AgentieImobiliara ai4("Casa viselor", 3, li1);
	AgentieImobiliara ai5("CasExpert", 1, li2);


	//cout << "\n\t\t\t\t--- CLASA CLIENTI ---" << endl;

	float r1[]{ 250, 250,250,240 };
	float r2[]{ 300, 300,300 };
	float r3[]{ 350,350,350,300 };
	float r4[]{ 200,200 };

	//constructor cu toti parametri
	Clienti c1(0, "Pancescu Andrei", 25, "Str. Soarelui, nr.44, Adjud, Vrancea", 3, r2);
	Clienti c2(1, "Paizan Andreea", 20, "Str. Novacesti, nr 66, Paunesti, Vrancea", 4, r3);
	Clienti c3(2, "Tanasa Andre", 24, "Str. Principala, nr 88, Paunesti, Vrancea", 4, r1);
	Clienti c4(3, "Bogdan Valetin", 40, "Str. Revolutiei, nr.23, Sector 1, Bucuresti", 4, r3);
	Clienti c5(4, "Ionascu Dragos", 39, "Str. Credintei, nr. 888, Lespezi, Vrancea", 2, r4);

	//cout << "\n\t\t\t\t--- CLASA ANGAJATI ---" << endl;

	float iv1[]{ 0.1,0.15,0.12,0.08 };
	float iv2[]{ 0.15,0.10,0.08,0.09 };
	float iv3[]{ 0.20, 0.08, 0.09 };
	float ivnou[]{ 0.1,0.08,0.12,0.13 };

	//constructor cu toti parametrii
	Angajati a1(0, "Paraschiv Lenuta", 40, 4, iv1);
	Angajati a2(1, "Giangu Darius", 30, 3, iv3);
	Angajati a3(2, "Maimascu Stefan", 30, 4, iv1);
	Angajati a4(3, "Badarau Ionut", 35, 4, iv2);
	Angajati a5(4, "Drilea Ovidiu", 22, 4, ivnou);

	//cout << "\n\t\t\t\t--- CLASA PROPRIETARI ---" << endl;

	float sc1[]{ 12,13,10 };
	float sc2[]{ 12.5,14,13,8.5 };
	float sc3[]{ 13,15,10,12.3,14.5 };
	float scnou[]{ 13,13.5,14.5,12.2 };

	//constructor cu toti parametrii
	Proprietari p1("Ilie Flavian", 70000, 5, sc3);
	Proprietari p2("Sava Andrei", 35000, 3, sc1);
	Proprietari p3("Rusu Stefan", 30000, 3, sc1);
	Proprietari p4("Radu Lucian", 40000, 4, sc2);
	Proprietari p5("Paizan Teodor", 50000, 4, scnou);

	ofstream imobil;
	imobil.open("Imobile 2.0.txt", ios::out | ios::trunc);
	imobil << i1 << i2 << i3 << i4 << i5;
	ofstream agentie;
	agentie.open("Agentii 2.0.txt", ios::out | ios::trunc);
	agentie << ai1 << ai2 << ai3 << ai4 << ai5;

	int optiune;
	do
	{
		cout << "\t\t\t\t\**********    MENIU!     ***********";//MENIU
		cout << "\n\nAlegeti o optiune: ";
		cout << "\n\t1. Adaugare imobil la una dintre agentii";
		cout << "\n\t2. Vindeti si eliminati imobilul unei agentii";
		cout << "\n\t3. Afisare meniu pentru fisiere si rapoarte";
		cout << "\n\t4. Adaugare imobil in oferta";
		cout << "\n\t5. Determinare suma imobile vandute";
		cout << "\n\t6. Testare clase ( operatori, constructori, metode, getteri si setteri)";
		cout << "\n\t0.IESIRE\n";
		cout << "Optiune: ";
		cin >> optiune;
		cout << "Varianta aleasa: " << optiune << endl;

		switch (optiune)
		{
		case 1:
		{
			cout << "1. " << ai1.getDenumire_Agentie() << endl;
			cout << "2. " << ai2.getDenumire_Agentie() << endl;
			cout << "3. " << ai3.getDenumire_Agentie() << endl;
			cout << "4. " << ai4.getDenumire_Agentie() << endl;
			cout << "5. " << ai5.getDenumire_Agentie() << endl;
			cout << "Alegeti AGENTIA: " << endl;

			int optiune; cin >> optiune;
			cout << "Varianta aleasa: " << optiune << endl;

			switch (optiune)
			{
			case 1:
			{
				cout << "Adaugati imobil la agentia " << ai1.getDenumire_Agentie() << endl;
				Imobil nou;
				cin >> nou;
				ai1.addImobil(nou);
				cout << ai1;
				break;
			}
			case 2:
			{
				cout << "Adaugati imobil la agentia " << ai2.getDenumire_Agentie() << endl;
				Imobil nou;
				cin >> nou;
				ai2.addImobil(nou);
				cout << ai2;
				break;
			}
			case 3:
			{
				cout << "Adaugati imobil la agentia " << ai3.getDenumire_Agentie() << endl;
				Imobil nou;
				cin >> nou;
				ai3.addImobil(nou);
				cout << ai3;
				break;
			}
			case 4:
			{
				cout << "Adaugati imobil la agentia " << ai4.getDenumire_Agentie() << endl;
				Imobil nou;
				cin >> nou;
				ai4.addImobil(nou);
				cout << ai4;
				break;
			}
			case 5:
			{
				cout << "Adaugati imobil la agentia " << ai5.getDenumire_Agentie() << endl;
				Imobil nou;
				cin >> nou;
				ai5.addImobil(nou);
				cout << ai5;
				break;
			}
			}
			break;
		}
		case 2:
		{
			int optiune;
			cout << "1. " << ai1.getDenumire_Agentie() << endl;
			cout << "2. " << ai2.getDenumire_Agentie() << endl;
			cout << "3. " << ai3.getDenumire_Agentie() << endl;
			cout << "4. " << ai4.getDenumire_Agentie() << endl;
			cout << "5. " << ai5.getDenumire_Agentie() << endl;
			cout << "Alegeti AGENTIA: " << endl;
			cin >> optiune;
			cout << "Varianta aleasa: " << optiune << endl;

			switch (optiune)
			{
			case 1:
			{
				cout << ai1;
				cout << "\nAlegeti Index: ";
				int index; cin >> index;
				ai1.deleteImobil(index);
				cout << ai1;
				break;
			}
			case 2:
			{	cout << ai2;
			cout << "\nAlegeti Index: ";
			int index; cin >> index;
			ai2.deleteImobil(index);
			cout << ai2;
			break;
			}
			case 3:
			{	cout << ai3;
			cout << "\nAlegeti Index: ";
			int index; cin >> index;
			ai3.deleteImobil(index);
			cout << ai3;
			break;
			}
			case 4:
			{
				cout << ai4;
				cout << "\nAlegeti Index: ";
				int index; cin >> index;
				ai4.deleteImobil(index);
				cout << ai4;
				break;
			}
			case 5:
			{
				cout << ai5;
				cout << "\nAlegeti Index: ";
				int index; cin >> index;
				ai5.deleteImobil(index);
				cout << ai5;
				break;

			}
			}
			break;

		}
		case 3:
		{
			cout << "Varianta aleasa: " << optiune << endl;

			meniu();
			break;
		}
		case 4:
		{
			cout << "Varianta aleasa: " << optiune << endl;

			Imobil inou;
			cin >> inou;
			imobil << inou;
			imobil.close();
			break;
		}
		case 5:
		{
			cout << "1. " << ai1.getDenumire_Agentie() << endl;
			cout << "2. " << ai2.getDenumire_Agentie() << endl;
			cout << "3. " << ai3.getDenumire_Agentie() << endl;
			cout << "4. " << ai4.getDenumire_Agentie() << endl;
			cout << "5. " << ai5.getDenumire_Agentie() << endl;
			cout << "Alegeti AGENTIA pentru care doriti sa calculati: " << endl;

			int optiune; cin >> optiune;
			cout << "Varianta aleasa: " << optiune << endl;

			switch (optiune)
			{
			case 1:
			{
				cout << "Valoarea imobilelor vandute de agentia " << ai1.getDenumire_Agentie() << " este: " << ai1.ValoareImobileVandute() << endl;
				break;
			}
			case 2:
			{
				cout << "Valoarea imobilelor vandute de agentia " << ai2.getDenumire_Agentie() << " este: " << ai2.ValoareImobileVandute() << endl;
				break;
			}
			case 3:
			{
				cout << "Valoarea imobilelor vandute de agentia " << ai3.getDenumire_Agentie() << " este: " << ai3.ValoareImobileVandute() << endl;
				break;
			}
			case 4:
			{
				cout << "Valoarea imobilelor vandute de agentia " << ai4.getDenumire_Agentie() << " este: " << ai4.ValoareImobileVandute() << endl;
				break;
			}
			case 5:
			{
				cout << "Valoarea imobilelor vandute de agentia " << ai5.getDenumire_Agentie() << " este: " << ai5.ValoareImobileVandute() << endl;
				break;
			}
			}
			break;
		}
		case 6:
		{
			cout << "Varianta aleasa: " << optiune << endl;

			testareMain();
			cout << endl;
			break;
		}
		}
	} while (optiune != 0);

}