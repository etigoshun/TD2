#pragma once
#include "WorldTransform.h"
#include "ViewProjection.h"
#include "DebugText.h"
#include "Input.h"

class RailCamera
{
public:
	/// <summary>
	/// ������
	/// </summary>
	/// <param name="position">�������W</param>
	/// <param name="rotation">�����p�x</param>
	void Initialize(Vector3& position, Vector3& rotation);

	/// <summary>
	/// �X�V
	/// </summary>
	void Update();

	void ZoomOut(Vector3 CameraMove);

	/// <summary>
	/// �r���[�v���W�F�N�V�������擾
	/// </summary>
	/// <returns></returns>
	const ViewProjection& GetViewProjection() { return viewProjection_; }

	//���[���h�s����擾
	WorldTransform* GetWorldMatrix() { return &worldTransform_; }

private:
	//���[���h�ϊ��f�[�^
	WorldTransform worldTransform_;

	//�r���[�v���W�F�N�V����
	ViewProjection viewProjection_;

	//�f�o�b�O�e�L�X�g
	DebugText* debugText_ = nullptr;

	//���͏������邽��
	Input* input_ = nullptr;

	//���[���h�g�����X�t�H�[���̍��W�̐��l�������Z����(�ړ�)
	Vector3 cameraMove = { 0, 0, 0 };
};