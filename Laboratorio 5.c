#include"arbol_L5.h"
//-----------------------------------------------------------------
void main(){
	Arbol unArbol;
	char nombreArchivoArbol[]="arbol.txt";
	if(abrirArchivo(nombreArchivoArbol)==0){
		return;
	}
	unArbol = *creaArbol(nombreArchivoArbol);
	//muestraArbolEnTerminal(Arbol unArbol);
}
