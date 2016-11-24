#include "Grafo.h"
#include "ReadData.h"
#include "Pajek.h"

int menu() {
	int op;
	system("cls");
	cout << "Escolha a opcao:" << endl;

	cout << "1-) Montar grafo a partir de csv;" << endl;
	cout << "2-) Gerar Pajek;" << endl;
	cout << "3-) Montar grafo a partir do Pajek;" << endl;
	cout << "4-) Verificar se grafo e Euliriano;" << endl;
	cin >> op;
	return op;
}

void main(void) {
	Grafo G;
	ReadData R;
	Pajek P;
	char op;

	inicio:
	switch (menu())
	{
	case 1:
		cout << "Loading..." << endl;
		R.readFile("mes072016.csv", &G);
		cout << "Grafo montado com sucesso. Deseja efetuar mais alguma operacao? (S/N)" << endl;
		cin >> op;
		if (op == 'S' || op == 's') {
			goto inicio;
		}
		else {
			goto fim;
		}
		break;
	case 2:
		cout << "Loading..." << endl;
		P.createPajek(&G);
		cout << "Pajek craido com sucesso. Deseja efetuar mais alguma operacao? (S/N)" << endl;
		cin >> op;
		if (op == 'S' || op == 's') {
			goto inicio;
		}
		else {
			goto fim;
		}
		break;
	case 3:
		cout << "Loading..." << endl;
		G = P.readPajek();
		cout << "Grafo montado a partir de um Pajek com sucesso. Deseja efetuar mais alguma operacao? (S/N)" << endl;
		cin >> op;
		if (op == 'S' || op == 's') {
			goto inicio;
		}
		else {
			goto fim;
		}
		break;
	case 4:
		cout << "Loading..." << endl;
		if (G.isEul()) {
			cout << "Grafo e Euleriano." << endl;
		}
		else {
			cout << "Grafo nao e Eureliano" << endl;
		}
		cout << "Deseja efetuar mais alguma operacao? (S/N)" << endl;
		cin >> op;
		if (op == 'S' || op == 's') {
			goto inicio;
		}
		else {
			goto fim;
		}
		break;
	default:
		break;
	}

	cout << endl;
	fim:
	system("pause");
}