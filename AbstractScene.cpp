#include "AbstractScene.h"
/*�R���X�g���N�^
impl:�V�[���ύX�̃��X�i�[
parameter:�O�̃V�[������n���ꂽ�p�����[�^�[*/
AbstractScene::AbstractScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	_implSceneChanged(impl)
{
}
