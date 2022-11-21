#pragma once
#include <WorldTransform.h>
#include <Input.h>
#include <DebugText.h>
#include <Sprite.h>
#include <cassert>
#include "Affine.h"

class PlayerCommand
{
public:		//�����o�֐�

	PlayerCommand();
	~PlayerCommand();

	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	int Attack(int bossHp);

	int Guard(int bossAtaack);

	int Heal(int playerHp);

private:	//�����o�ϐ�

	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	//�U���e�N�X�`���n���h��
	uint32_t attackTH_ = 0u;

	uint32_t guardTH_ = 0u;

	uint32_t healTH_ = 0u;

	//���͏������邽��
	Input* input_ = nullptr;

	//�f�o�b�O�e�L�X�g
	DebugText* debugText_ = nullptr;

	//�U���R�}���h
	Sprite* attackSprite = nullptr;
	//�h��R�}���h
	Sprite* guardSprite = nullptr;
	//�񕜃R�}���h
	Sprite* healSprite = nullptr;

	bool attackFlag = false;
	bool guardFlag = false;
	bool healFlag = false;
};

