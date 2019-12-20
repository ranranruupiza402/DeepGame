#include "Title.h"
#include <DxLib.h>

Title::Title(IOnChangedListener * impl, const Parameter & parameter)
	:AbstractScene(impl,parameter)
{
}

void Title::updeta()
{
}

void Title::draw()
{
	DrawString(100, 100, "ƒ^ƒCƒgƒ‹", GetColor(255, 255, 255));
}
