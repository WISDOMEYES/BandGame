#include "stdafx.h"

int main(int argc, char* argv[])
{
	CSystem* pSystem = new CSystem;

	pSystem->Initialize();

	pSystem->Run();

	pSystem->Terminate();

	delete pSystem;

	return 0;
}

