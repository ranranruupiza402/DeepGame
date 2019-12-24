#include "System.h"
#include <DxLib.h>
#include "Define.h"
#include "Looper.h"


bool System::initialize() const
{
	SetAlwaysRunFlag(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	SetWindowText("DeepGame");
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.0);
	const int COLOR_BIT = 32;
	SetGraphMode(Define::WIN_WIDTH, Define::WIN_HEGHT, COLOR_BIT);
	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;//エラーが起きたら終了
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void System::end() const
{
	DxLib_End();
}

void System::main() const
{
	Looper loop;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
	{
		if (!loop.loop()) {
			break;
		}
	}
}
