#include "Skydome.h"

/// <summary>
/// ������
/// </summary>
void Skydome::Initialize(Model* model)
{
	//NULL�|�C���^�`�F�b�N
	assert(model);

	//�����Ƃ��Ď󂯎�����f�[�^�������o�ϐ��ɋL�^����
	model_ = model;

	//���[���h�ϊ��̏�����
	worldTransform_.Initialize();
	worldTransform_.scale_ = { 150.0f,150.0f,150.0f };

	//�s��̍X�V
	worldTransform_.matWorld_ = CreateScale(worldTransform_.scale_);

	worldTransform_.TransferMatrix();
}

/// <summary>
/// �X�V
/// </summary>
void Skydome::Update()
{}

/// <summary>
/// �`��
/// </summary>
void Skydome::Draw(ViewProjection& viewProjection)
{
	model_->Draw(worldTransform_, viewProjection);
}