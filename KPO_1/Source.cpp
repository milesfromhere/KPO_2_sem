#include "stdafx.h"

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a = 1, menu1(), menu2();

	do {
		//ìåíþ
		menu1();
		char n;
		cin >> n;
		cout << "\n";
		//ïðîâåðêà
		while ('2' < n || n < '1') {
			cout << "Âû ââåëè íåêîððåêòíûé íîìåð.\n";
			cout << "Âûáåðèòå ñóùåñòâóþùèé âàðèàíò âûïîëíåíèÿ ïðîãðàììû\n";
			menu2();
			cin >> n;
			cout << "\n";
		}

		//âûïîëíåíèå ïðîãðàììû

		switch (n) {

		case '1': {
			cout << "Ââåäèòå äàòó(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
			static char data[chislo];
			cin >> data;
			//ïðîðåðêà 
			for (int i = 0; i < 8; i++) {

				if (data[i] > '9' || data[i] < '0') {

					cout << "Âû íåêîððåêòíî ââåëè äàòó!\n";
					cout << "Ââåäèòå äàòó(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
					cin >> data;
				}
			}
			int dol;
			//èçâëå÷åíèå ìåñÿöà 
			int mes = (data[2] - '0') * 10 + data[3] - '0';
			//èçâëå÷åíèå äíÿ 
			int den = (data[0] - '0') * 10 + data[1] - '0';
			//Äîï ïðîâåðêà êîððåêòíîñòè äàòû

			int god = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			bool cel = Checking(god);
			while (cel == 0 && mes == 2 && den > 28) {

				cout << "Âû íåêîððåêòíî ââåëè äàòó!\n";
				cout << "Ââåäèòå äàòó(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
				cin >> data;

				//èçâëå÷åíèå ìåñÿöà èç äàòû
				mes = (data[2] - '0') * 10 + data[3] - '0';
				//èçâëå÷åíèå äíÿ èç äàòû
				den = (data[0] - '0') * 10 + data[1] - '0';
				god = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';
			}
			while (data[0] > '3' || data[0] < '0' || mes > 12 || mes < 1 || den < 1 || den > 31) {


				cout << "Âû íåêîððåêòíî ââåëè äàòó!\n";
				cout << "Ââåäèòå äàòó(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
				cin >> data;
				//èçâëå÷åíèå ìåñÿöà èç äàòû
				mes = (data[2] - '0') * 10 + data[3] - '0';
				//èçâëå÷åíèå äíÿ èç äàòû
				den = (data[0] - '0') * 10 + data[1] - '0';
				god = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';

			}
			//èçâëå÷åíèå ãîäà èç äàòû
			god = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + data[7] - '0';

			//Ââîä äàòû ðîæäåíèÿ
			cout << "Ââåäèòå äàòó ðîæäåíèÿ(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
			static char birth[chislo];
			cin >> birth;
			//Ïðîâåðêà 
			for (int i = 0; i < 8; i++) {

				if (birth[i] > '9' || birth[i] < '0') {

					cout << "Âû íåêîððåêòíî ââåëè äàòó!!\n";
					cout << "Ââåäèòå äàòó ðîæäåíèÿ(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
					cin >> birth;
				}
			}
			//èçâëå÷åíèå ìåñÿöà
			int mesbirth = (birth[2] - '0') * 10 + birth[3] - '0';
			//èçâëå÷åíèå äíÿ
			int denbirth = (birth[0] - '0') * 10 + birth[1] - '0';
			//ïðîâåðêà

			int godbirth = (birth[4] - '0') * 1000 + (birth[5] - '0') * 100 + (birth[6] - '0') * 10 + birth[7] - '0';
			bool cell = Checking(godbirth);
			while (cel == 0 && mesbirth == 2 && denbirth > 28) {

				cout << "Âû íåêîððåêòíî ââåëè äàòó!!\n";
				cout << "Ââåäèòå äàòó(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
				cin >> data;
				//èçâëå÷åíèå ìåñÿöà
				mes = (data[2] - '0') * 10 + data[3] - '0';
				//èçâëå÷åíèå äíÿ
				den = (data[0] - '0') * 10 + data[1] - '0';
				godbirth = (birth[4] - '0') * 1000 + (birth[5] - '0') * 100 + (birth[6] - '0') * 10 + birth[7] - '0';
			}
			while (birth[0] > '3' || birth[1] < '0' || mesbirth > 12 || mesbirth < 1 || denbirth < 1 || denbirth > 31) {

				cout << "Âû íåêîððåêòíî ââåëè äàòó!!\n";
				cout << "Ââåäèòå äàòó ðîæäåíèÿ(â ôîðìàòå ÄÄÌÌÃÃÃÃ)\n";
				cin >> birth;
				//èçâëå÷åíèå ìåñÿöà
				mesbirth = (birth[2] - '0') * 10 + birth[3] - '0';
				//èçâëå÷åíèå äíÿ
				denbirth = (birth[0] - '0') * 10 + birth[1] - '0';
				godbirth = (birth[4] - '0') * 1000 + (birth[5] - '0') * 100 + (birth[6] - '0') * 10 + birth[7] - '0';
			}
			//èçâëå÷åíèå ãîäà 
			godbirth = (birth[4] - '0') * 1000 + (birth[5] - '0') * 100 + (birth[6] - '0') * 10 + birth[7] - '0';

			//Âûâîä èíôîðìàöèè î äàòå

			cout << "Âàøà ââåä¸ííàÿ äàòà: " << den << ":" << mes << ":" << god << "\n";
			cout << "Âàø äåíü ðîæäåíèÿ: " << denbirth << ":" << mesbirth << ":" << godbirth << "\n";
			cel = 0;
			//Ïðîâåðêà íà âèñîêîñíîñòü
			/*int Checking(int x, int y);*/
			if (Checking(god) == 1) {
				cout << "Äàííûé ãîä ÿâëÿåòñÿ âèñîêîñíûì \n";
			}
			else {
				cout << "Äàííûé ãîä íå ÿâëÿåòñÿ âèñîêîñíûì \n";
			}
			//Âû÷èñëåíèå ïîðÿäêîâîãî íîìåðà äíÿ â ãîäó
			int quantity(int x, int y, int z);
			cout << "Ââåä¸ííûé Âàìè äåíü ÿâëÿåòñÿ " << quantity(mes, den, Checking(god)) << " â ãîäó\n";

			//Âû÷èñëåíèå êîëè÷åñòâà äíåé äî Âàøåãî áëèæàéøåãî äíÿ ðîæäåíèÿ

			if (quantity(mes, den, Checking(god)) < quantity(mesbirth, denbirth, Checking(god))) {

				int daycout = quantity(mes, den, Checking(god));
				int daybirths = quantity(mesbirth, denbirth, Checking(god));
				int colvoday = daybirths - daycout;
				cout << "Äî áëèæàéøåãî Âàøåãî äíÿ ðîæäåíèÿ " << colvoday << " äíÿ(åé)\n";
			}
			else if (quantity(mes, den, Checking(god)) == quantity(mesbirth, denbirth, Checking(god))) {
				cout << " Ñ äí¸ì ðîæäåíèÿ!! \n";

			}

			else {

				int daycout = quantity(mes, den, Checking(god));
				int jatgod = god + 1;
				int daybirths = quantity(mesbirth, denbirth, Checking(jatgod));
				int daygod = 365 + Checking(god);
				int daydop = daygod - daycout;
				int colvoday = daybirths + daydop;
				cout << "Äî áëèæàéøåãî Âàøåãî äíÿ ðîæäåíèÿ " << colvoday << " äíÿ(åé)\n";
			}
		}

				//Âûõîä

		case '2': {

			cout << "Ïðîãðàììà çàâåðøåíà \n";

			return 0;
		}
		}
	} while (a != 0);
	return 0;
}

//Ôóíêöèè

//Ãëàâíîå ìåíþ
int menu1() {
	using namespace std;
	cout << "âûáåðèòå âàðèàíò âûïîëíåíèÿ ïðîãðàììû: \n";
	cout << "1 - Èíôîðìàöèÿ î ââåä¸ííîé Âàìè äàòå \n";
	cout << "2 - Âûõîä èç ïðîãðàììû \n";
	cout << "\n";
	cout << "Âàðèàíò âûïîëíåíèÿ ïðîãðàììû: ";
	return 0;
};

//Âîçâðàùåíèå â ìåíþ
int menu2() {
	int menu1();
	using namespace std;

	cout << "Âû ââåëè íåêîððåêòíûé âàðèàíò âûïîëíåíèÿ\n";
	menu1();
	return 0;
};