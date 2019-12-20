#include "Looper.h"

/*今何をしていて次に何をいないといけないのかを
わざわざ知っておきたくない。
Looperでやることは更新や描画を指示するだけにしたい
シーンが増えたときLooperの仕事が多くなってしまうのを防ぐため*/

Looper::Looper()
{
}


Looper::~Looper()
{
}

bool Looper::loop() const
{
	return true;
}