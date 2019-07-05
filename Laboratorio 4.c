#include "arbol_L4.h"
//----------------------------------------------------------------------
void main(){
	Arbol unArbol;
	char nombreArchivoArbol[]="arbol.txt";
	if(abrirArchivo(nombreArchivoArbol)==0){
		return;
	}
	unArbol=*creaArbol(nombreArchivoArbol);
	//imprimirArchivo(nombreArchivoArbol);
}
