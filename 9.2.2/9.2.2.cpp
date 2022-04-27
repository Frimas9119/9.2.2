#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Spec { KOMPUTERNINAUKY, INFORMATIKA, MATEMATIKAIEKONOMIKA, FIZUKAIINFORMATIKA, TRUDOVENAVCHANNA };//оголошення переліків змінних

string spec_str[] = { "Com Science", "Informatics", "Math&Econom", "Physic&Info", "Handicrafts" };

struct Student
{
	string last_name;
	int cource;
	Spec speci;
	int fizuka;
	int matematika;
	union {
		int prog;
		int chuselni_metody;
		int peda;
	};
};

void Create(Student* s, const int N);
int* IndexArray(Student* s, const int N);
void PrintIndexArray(Student* s, int* I, const int N);

int main(){
	int N;
	cout << "Vvedit N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	IndexArray(s, N);
	PrintIndexArray(s, IndexArray(s, N), N);
}
int* IndexArray(Student* s, const int N) {
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;
	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1; j >= 0 && ((s[I[j]].cource > s[value].cource) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].prog > s[value].prog) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].prog > s[value].chuselni_metody) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].prog > s[value].peda) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].chuselni_metody > s[value].prog) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].chuselni_metody > s[value].chuselni_metody) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].chuselni_metody > s[value].peda) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].peda > s[value].prog) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].peda > s[value].chuselni_metody) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].peda > s[value].peda) ||

			(s[I[j]].cource == s[value].cource && s[I[j]].prog == s[value].prog && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].prog == s[value].chuselni_metody && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].prog == s[value].peda && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].chuselni_metody == s[value].prog && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].chuselni_metody == s[value].chuselni_metody && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].chuselni_metody == s[value].peda && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].peda == s[value].prog && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].peda == s[value].chuselni_metody && s[I[j]].last_name < s[value].last_name) ||
			(s[I[j]].cource == s[value].cource && s[I[j]].peda == s[value].peda && s[I[j]].last_name < s[value].last_name)); j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}
void Create(Student* s, const int N) {
	int speci;
	for (int i = 0; i < N; i++)
	{
		cout << "Student № " << i + 1 << ":" << endl;
		cin.get();
		cout << " Last Name: "; getline(cin, s[i].last_name);
		cout << " Cource : "; cin >> s[i].cource;
		cout << " Speciality (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, 3 - Physics and Informatics, 4 - Handicraft): ";
		cin >> speci;
		s[i].speci = Spec(speci);
		switch (s[i].speci) {
		case KOMPUTERNINAUKY:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Programming : "; cin >> s[i].prog;
			break;
		case INFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Numerical Methods : "; cin >> s[i].chuselni_metody;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		case FIZUKAIINFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		case TRUDOVENAVCHANNA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].peda;
			break;
		}
		cout << endl;
	}
}
void PrintIndexArray(Student* s, int* I, const int N) {
	cout << "============================================================================="
		<< endl;
	cout << "| № | Last Name | Course | Speciality | Phy | Math | Prog | Num Met | Ped |"
		<< endl;
	cout << "-----------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << s[I[i]].last_name
			<< "| " << setw(6) << right << s[I[i]].cource << " "
			<< "| " << setw(10) << left << spec_str[s[I[i]].speci];
		switch (s[i].speci) {
		case KOMPUTERNINAUKY:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << "|" << " " << setw(3) << right << s[I[i]].prog << " |"
				<< " " << setw(3) << right << " |" << " " << setw(3) << right << " |" << endl;
			break;
		case INFORMATIKA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< s[I[i]].chuselni_metody << " |" << setw(3) << right << "|" << endl;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[I[i]].peda<< " |" << endl;
			break;
		case FIZUKAIINFORMATIKA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[I[i]].peda << " |" << endl;
			break;
		case TRUDOVENAVCHANNA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[I[i]].peda << " |" << endl;
			break;
		}
	}
	cout << "============================================================================="
		<< endl;
	cout << endl;
}


