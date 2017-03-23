#include <iostream>
#include <string>
using namespace std;

struct file {
	int angka;
	int pangkat;
	string x;

file *next;
};

struct linkedTunggal {
	file *first;
};
file *alokasi_memori(int angka, string x, int pangkat); //allocation list in memori
void createBox(linkedTunggal *link); //create list
void addValue(linkedTunggal *link, file *elm); //insert list in memori
void displayList(linkedTunggal link); //View list in memori
void delloc(file *daftar); //delete list in memori
void addBck(linkedTunggal *list, file *elm); //insert list in last (index last)
void dellBck(linkedTunggal *list); //delete last insert
void update(file *yang_akan_dirubah, int angka, string x, int pangkat);

//2 pembuatan gerbong dan pengisian nilai
void createBox(linkedTunggal *link) {
	link->first = NULL;
}

file *alokasi_memori(int angka, string x, int pangkat) {
	file *p = new file;

	p->angka = angka;
	p->pangkat = pangkat;
	p->x = x;

	p->next = NULL;

	return p;
}

void addValue(linkedTunggal *link, file *elm) {
	elm->next = link->first;
	link->first = elm;

	elm = NULL;
}

void displayList(linkedTunggal link) {
	if (link.first != 0) {
		file *p = link.first;
		while (p != 0) {
			cout << p->angka << p->x << p->pangkat << "  ~  ";
			p = p->next;
		}
	}
	else {
		cout << "Pengisian data" << endl;
	}
}

void delloc(file*daftar) {
	delete(daftar);
}

void addBck(linkedTunggal *list, file *elm) {
	if (list->first != 0) {
		file *p = list->first;
		while (p->next != 0) {
			p = p->next;
		}
		p->next = elm;
		elm = 0;
	}
	else {
		addValue(list, elm);
	}
}

void dellBck(linkedTunggal *list) {
	if (list->first != 0) {
	file *temp_1 = list->first;

		if (temp_1->next == 0) {
			delloc(temp_1);
		}
		else {
			file *temp_2 = temp_1;
			temp_1 = temp_2->next;
			while (temp_1->next != 0) {
				temp_2 = temp_1;
				temp_1 = temp_2->next;
			}
			temp_2->next = 0;
			delloc(temp_1);
		}
	}
	else {
		cout << "Kosong" << endl;
	}
}

void update(file *yang_akan_dirubah, int angka, string x, int pangkat) {
	yang_akan_dirubah->angka = angka;
	yang_akan_dirubah->x = x;
	yang_akan_dirubah->pangkat = pangkat;
}

int main()
{
	linkedTunggal link;
	createBox(&link);

	file *p1 = new file;

	p1 = alokasi_memori(12, "x^", 2);
	addValue(&link, p1);

	p1 = alokasi_memori(4, "x^", 3);
	addValue(&link, p1);

	p1 = alokasi_memori(2, "x^", 6);
	addValue(&link, p1);

	cout << "P1 = ";
	displayList(link);

	cout << "\n\nbelakang di hapus maka jadi :" << endl;

	//proses penghapusan gerbong list

	dellBck(&link);

	cout << "P1 = ";
	displayList(link);
	cout << "\n\n" << endl;
    return 0;
}

