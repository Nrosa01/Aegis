#include "AegisMain.h"
#include <iostream>
#include "checkML.h" //BASURA
#include <Windows.h>

int main() {
	// Agrega checkML.h al proyecto e incl�yelo en todos los m�dulos del proyecto 
	// Escribe el siguiente comando al inicio de la funci�n main
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	::ShowWindow(::GetConsoleWindow(), SW_SHOW);
#else
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
#endif // DEBUG	 

	AegisMain a;
	if (a.init())
		a.startGame();
	else
		a.free();

	return 0;
}