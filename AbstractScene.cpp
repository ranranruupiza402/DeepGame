#include "AbstractScene.h"
/*コンストラクタ
impl:シーン変更のリスナー
parameter:前のシーンから渡されたパラメーター*/
AbstractScene::AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	_implSceneChanged(impl)
{
}
