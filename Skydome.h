#pragma once
#include "WorldTransform.h"
#include "Model.h"
#include "ViewProjection.h"
#include <cassert>
#include "Affine.h"

/// <summary>
/// �V��
/// </summary>
class Skydome
{
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize(Model* model);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(ViewProjection& viewProjection);

private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	//���f��
	Model* model_ = nullptr;

	//�r���[�v���W�F�N�V����
	ViewProjection viewProjection_;

};