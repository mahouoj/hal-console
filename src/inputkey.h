#ifndef _INPUTKEY_H_
#define _INPUTKEY_H_

enum	KEYNAME	//�Q�[�����Ŏg���L�[�̎��
{
	KEY_UP,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_LEFT,
	KEY_JUMP,
	KEY_SHOT,

	KEY_NUM,	// �L�[�̎�ސ�
};

struct	KEYSTATE		//�L�[���(�e�L�[�ݒ�1�ɑ΂��č\���̂P��)
{
	int		nTrigger;		//�������u��
	int		nRelease;		//�������u��
	int		nPress;			//���݂̃L�[���
	int		nPressOld;	//�O���Press�̒l
};

struct	KEYCONFIG			//�Q�[�����̃L�[�ƃL�[�{�[�h�L�[�̊��蓖��
{
	KEYNAME		nName;		//�Q�[�����̃L�[���
	int				nCode;		//conioex.h�̃L�[�{�[�h�̃L�[�R�[�h
};

//�v���g�^�C�v�錾
void	InitKey();		//������
void	UninitKey();	//�I������
void	UpdateKey();	//�L�[���̍X�V
void	DrawKey();		//�`�揈���i�f�o�b�O���Ŏg���j

int		GetKeyTrigger(KEYNAME nKey);	//�L�[�̃g���K�[�����擾
int		GetKeyPress(KEYNAME nKey);		//�L�[�̃v���X�����擾
int		GetKeyRelease(KEYNAME nKey);	//�L�[�̃����[�X�����擾

void	PrintButton(KEYSTATE tKeyState);		//�{�^���`��i�f�o�b�O�p�j

#endif //_INPUTKEY_H_
