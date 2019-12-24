#include "Looper.h"
#include"TitleScene.h"
#include "GamePlayScene.h"

using namespace std;

/*今何をしていて次に何をいないといけないのかを
わざわざ知っておきたくない。
Looperでやることは更新や描画を指示するだけにしたい
シーンが増えたときLooperの仕事が多くなってしまうのを防ぐため*/

Looper::Looper()
{
	Parameter parameter;
	_sceneStack.push(make_shared<TitleScene>(this, parameter)); //タイトル画面シーンを作ってpush
}

/*スタックされているシーンのトップのシーンの処理をする*/
bool Looper::loop() const
{
	_sceneStack.top()->update();
	_sceneStack.top()->draw();
	return true;
}

/*シーン変更（各シーンからコールバックされる）
secen 変更するシーンからのenum
parmeter 前のシーンからの引継ぐパラメーター
stackClear 現在のシーンのスタックをクリアする*/
void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, const bool stackClear)
{
	if (stackClear) {
		while (!_sceneStack.empty())
		{
			_sceneStack.pop();
		}
	}

	switch (scene)
	{
	case Title:
		_sceneStack.push(make_shared<TitleScene>(this, parameter));
		break;
	case GamePlay:
		_sceneStack.push(make_shared<GamePlayScene>(this, parameter));
		break;
	}
}
