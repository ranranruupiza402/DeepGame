#include "DxLib.h"
#include "System.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	System system;
	if (system.initialize()) {
		WaitKey();
	}
	system.end();

}