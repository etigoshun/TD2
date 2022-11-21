#include "PlayerCommand.h"
#include <TextureManager.h>

PlayerCommand::PlayerCommand()
{
	attackTH_ = TextureManager::Load("command/attack.png");
	guardTH_ = TextureManager::Load("command/guard.png");
	healTH_ = TextureManager::Load("command/heal.png");
}

PlayerCommand::~PlayerCommand()
{
	delete attackSprite;
}

/// <summary>
/// ������
/// </summary>
void PlayerCommand::Initialize()
{
	//�V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//�A�^�b�N�R�}���h�̐���
	attackSprite = Sprite::Create(attackTH_, { 200,600 });

	guardSprite = Sprite::Create(guardTH_, { 510,600 });

	healSprite = Sprite::Create(healTH_, { 820, 600});

	//���[���h�ϊ��̏�����
	worldTransform_.Initialize();
}

/// <summary>
/// �X�V
/// </summary>
void PlayerCommand::Update()
{
	
}

/// <summary>
/// �`��
/// </summary>
void PlayerCommand::Draw()
{
	//�A�^�b�N�R�}���h�̕`��
	attackSprite->Draw();

	guardSprite->Draw();

	healSprite->Draw();
}

int PlayerCommand::Attack(int bossHp)
{
	bossHp -= 30;
	attackFlag = false;

	return bossHp;
}

int PlayerCommand::Guard(int bossAttack)
{
	bossAttack -= 20;
	guardFlag = false;

	return bossAttack;
}

int PlayerCommand::Heal(int playerHp)
{
	playerHp += 50;
	healFlag = false;

	return playerHp;
}
