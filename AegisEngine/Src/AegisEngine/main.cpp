#include "AegisMain.h"
#include "checkML.h" //BASURA

int main() {
	// Agrega checkML.h al proyecto e incl�yelo en todos los m�dulos del proyecto 
	// Escribe el siguiente comando al inicio de la funci�n main
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // DEBUG	 

	AegisMain a;
	a.Init();

	return 0;
}