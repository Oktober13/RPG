// UnterFell.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Main.h"


int main(int argc, char *argv[])
{

	CMain* cmain = new CMain(1000, 800, 6135, 1300);
	cmain->GameLoop();
	delete cmain;

    return 0;
}