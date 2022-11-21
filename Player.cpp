#include "Player.h"

/// <summary>
/// ������
/// </summary>
/// <param name="model">���f��</param>
/// <param name="texturehandle">�e�N�X�`���n���h��</param>
void Player::Initialize(Model* model, uint32_t textureHandle)
{
	//NULL�|�C���^�`�F�b�N
	assert(model);

	//�����Ƃ��Ď󂯎�����f�[�^�������o�ϐ��ɋL�^����
	model_ = model;
	textureHandle_ = textureHandle;

	//�V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//���[���h�ϊ��̏�����
	//worldTransform_.translation_.z = 50;
	worldTransform_.Initialize();

	worldTransform_.scale_ = { 1.0f,1.0f,1.0f };
	worldTransform_.translation_ = { 0,-5,50 };
	
}


/// <summary>
/// �X�V
/// </summary>
void Player::Update()
{

	//�L�����N�^�[�̈ړ��x�N�g��
	Vector3 move = { 0,0,0 };

	//�ړ��x�N�g����ύX���鏈��
	if (input_->PushKey(DIK_D))
	{
		move.x = 0.1f;
	}
	else if (input_->PushKey(DIK_A))
	{
		move.x = -0.1f;
	}

	/*if (input_->PushKey(DIK_S))
	{
		move.y = -0.1f;
	}*/

	if (input_->PushKey(DIK_W) && jumpFlag == false)
	{
		jumpPower = 100.0f;
		jumpFlag = true;
	}

	if (worldTransform_.translation_.y > 0)
	{
		jumpPower -= gravity;
	}

	//���W�ړ�
	worldTransform_.translation_ += move;


	//�ړ����E����
	const float kMoveLimitX = 33.0f;
	const float kMoveLimitY = 17.0f;

	//�͈͂𒴂��Ȃ�����
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	//worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	//�s��̍X�V
	worldTransform_.matWorld_ = CreateIdentity();
	worldTransform_.matWorld_ *= CreateScale(worldTransform_.scale_);
	worldTransform_.matWorld_ *= CreateRotZ(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotX(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotY(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateTrans(worldTransform_.translation_);

	//�e�q�֌W
	//worldTransform_.matWorld_ *= worldTransform_.parent_->matWorld_;

	worldTransform_.TransferMatrix();

	//�L�����N�^�[�̍��W����ʂɕ\������
	debugText_->SetPos(50, 150);
	debugText_->Printf("translation:(%f,%f,%f)", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);

	//���L�����̉�]����
	Vector3 turn = { 0,0.01f,0 };

	if (input_->PushKey(DIK_J))
	{
		worldTransform_.rotation_ -= turn;
	}
	else if (input_->PushKey(DIK_U))
	{
		worldTransform_.rotation_ += turn;
	}

	playerCmd->Heal(playerHp);
}

/// <summary>
/// �`��
/// </summary>
void Player::Draw(ViewProjection& viewProjection)
{
	//3D���f����`��
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}