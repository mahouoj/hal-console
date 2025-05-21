//=============================================================================
//���g������
//		inputkey.cpp �� inputkey.h ���v���W�F�N�g���ɓ����
//		�L�[���͂���v���O�����Ɂu#include "inputkey.h"�v������
//
//		GetKeyPress(KEYNAME::�`�`�`�`) �� �`�`�`�`�̃L�[��������Ă����
//		GetKeyTrigger(KEYNAME::�`�`�`�`) �� �`�`�`�`�̃L�[�������ꂽ�u��
//		GetKeyRelease(KEYNAME::�`�`�`�`) �� �`�`�`�`�̃L�[��������ꂽ�u��
//		
//=============================================================================
#define CONIOEX
#include "conioex.h"
#include "inputkey.h"
#include <iostream>

// �L�[�R���t�B�O�ݒ�
#define KEY_CONFIG_MAX		(4)	//�L�[�R���t�B�O�̓o�^��

// �L�[�R���t�B�O�\���̔z��Ə�����
KEYCONFIG nKey[KEY_CONFIG_MAX] =
{
	//	�L�[�̎��				conioex�̃L�[
	{KEYNAME::KEY_RIGHT		,	PK_RIGHT	},
	{KEYNAME::KEY_LEFT		,	PK_LEFT		},
	{KEYNAME::KEY_JUMP		,	PK_UP		},
	{KEYNAME::KEY_SHOT		,	PK_SP		},

	// �K�v�Ȃ����ǉ�
};

// �L�[��񂪊i�[�����\���̔z��
KEYSTATE tKeyData[KEYNAME::KEY_NUM];//GAMEKEYNAME�̓o�^�������

//=============================================================================
// ����������
//=============================================================================
void InitKey()
{
	//�L�[�����O�N���A����
	memset(&tKeyData[0], 0, sizeof(tKeyData));

}

//=============================================================================
// �I������
//=============================================================================
void UninitKey()
{

}

//=============================================================================
// �X�V����
//=============================================================================
void UpdateKey()
{
	//KEYCONFIG�ɓo�^���ꂽ�L�[�̏����擾
	for (int nCnt = 0; nCnt < KEY_CONFIG_MAX; nCnt++)
	{
		// �O��̃L�[����ۑ�
		tKeyData[nKey[nCnt].nName].nPressOld = tKeyData[nKey[nCnt].nName].nPress;

		// ���݂̃L�[�����擾
		tKeyData[nKey[nCnt].nName].nPress = inport(nKey[nCnt].nCode);

		// �g���K�[���
		tKeyData[nKey[nCnt].nName].nTrigger =
			(tKeyData[nKey[nCnt].nName].nPressOld ^ tKeyData[nKey[nCnt].nName].nPress) & // ��ԕω�����
			tKeyData[nKey[nCnt].nName].nPress;                                           // �L�[����

		// �����[�X���
		tKeyData[nKey[nCnt].nName].nRelease =
			(tKeyData[nKey[nCnt].nName].nPressOld ^ tKeyData[nKey[nCnt].nName].nPress) & // ��ԕω�����
			(~tKeyData[nKey[nCnt].nName].nPress);                                        // �L�[���

	}

}

//=============================================================================
// �`�揈�� (�f�o�b�O�\���p)
//=============================================================================
void DrawKey()
{
#ifdef _DEBUG
	int nX = 1, nY = 2;			// ���W�ݒ�
	gotoxy(nX, nY);
	textcolor(LIGHTCYAN);
	std::cout << "KEY: ";
	PrintButton(tKeyData[KEYNAME::KEY_JUMP]);
	std::cout << "   ";
	PrintButton(tKeyData[KEYNAME::KEY_SHOT]);
	gotoxy(nX, nY + 1);
	std::cout << "    ";
	PrintButton(tKeyData[KEYNAME::KEY_LEFT]);
	std::cout << " ";
	PrintButton(tKeyData[KEYNAME::KEY_RIGHT]);
#endif
}

//=============================================================================
// �g���K�[�f�[�^�擾 (�������u��)
//=============================================================================
int GetKeyTrigger(KEYNAME nKey)
{
	return tKeyData[nKey].nTrigger;
}

//=============================================================================
// �����[�X�f�[�^�擾 (�������u��)
//=============================================================================
int GetKeyRelease(KEYNAME nKey)
{
	return tKeyData[nKey].nRelease;
}

//=============================================================================
// �v���X�f�[�^�擾 (���������Ă�����)
//=============================================================================
int GetKeyPress(KEYNAME nKey)
{
	return tKeyData[nKey].nPress;
}

//=============================================================================
// �{�^���`�� (�f�o�b�O�\���p)
//=============================================================================
void PrintButton(KEYSTATE tKeyState)
{
	// �F�ݒ�
	if (tKeyState.nTrigger)				// �L�[���������Ƃ�
	{
		textcolor(RED);
	}
	else if (tKeyState.nRelease)	// �L�[�𗣂����Ƃ�
	{
		textcolor(YELLOW);
	}
	else
	{
		textcolor(LIGHTCYAN);
	}

	// �\���ݒ�
	if (tKeyState.nPress)				// �L�[�������Ă����
	{
		std::cout << "@";
	}
	else
	{
		std::cout << "0";
	}
}