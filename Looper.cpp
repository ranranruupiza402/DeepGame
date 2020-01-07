#include "Looper.h"
#include "TitleScene.h"
#include "GamePlayScene.h"
#include "Keyboard.h"
#include "Image.h"

using namespace std;

/*���������Ă��Ď��ɉ������Ȃ��Ƃ����Ȃ��̂���
�킴�킴�m���Ă��������Ȃ��B
Looper�ł�邱�Ƃ͍X�V��`����w�����邾���ɂ�����
�V�[�����������Ƃ�Looper�̎d���������Ȃ��Ă��܂��̂�h������*/

Looper::Looper()
{
	Image::getIns()->load();
	Parameter parameter;
	_sceneStack.push(make_shared<TitleScene>(this, parameter)); //�^�C�g����ʃV�[���������push
}

/*�X�^�b�N����Ă���V�[���̃g�b�v�̃V�[���̏���������*/
bool Looper::loop() const
{
	Keyboard::getIns()->update();//�L�[�{�[�h�̍X�V
	_sceneStack.top()->update();//�X�^�b�N�̃g�b�v�̃V�[�����X�V
	_sceneStack.top()->draw();//�X�^�b�N�̃g�b�v�̃V�[����`��
	return true;
}

/*�V�[���ύX�i�e�V�[������R�[���o�b�N�����j
secen �ύX����V�[�������enum
parmeter �O�̃V�[������̈��p���p�����[�^�[
stackClear ���݂̃V�[���̃X�^�b�N���N���A����*/
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
