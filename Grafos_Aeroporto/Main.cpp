#include "Grafo.h"
#include "ReadData.h"

void main(void) {
	Grafo *G= new Grafo();
	ReadData R;

	R.readFile("mes072016.csv", G);
	system("pause");
}