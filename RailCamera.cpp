#include "RailCamera.h"
#include "MyMath.h"
#include "Affine.h"

void RailCamera::Initialize(Vector3& position, Vector3& rotation)
{
	//�V���O���g���C���X�^���X���擾����
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//���[���h�g�����X�t�H�[���̏����ݒ�
	worldTransform_.translation_ = position;
	worldTransform_.rotation_ = rotation;

	//�r���[�v���W�F�N�V�����̏�����
	viewProjection_.farZ = 2000.0f;
	viewProjection_.Initialize();

	cameraMove = { 0, 50, 100 };
}

void RailCamera::Update()
{
	if (input_->PushKey(DIK_SPACE))
	{
		ZoomOut(cameraMove);
	}

	

	//�f�o�b�O�p�\��
	debugText_->SetPos(50, 50);
	debugText_->Printf("RailCamera pos:(%f, %f, %f)", viewProjection_.eye.x, viewProjection_.eye.y, viewProjection_.eye.z);
	
}

void RailCamera::ZoomOut(Vector3 cameraMove)
{

	cameraMove.y -= 0.01;

	cameraMove.z -= 0.05;

	worldTransform_.translation_ += cameraMove;

	//�s��̍X�V
	worldTransform_.matWorld_ = CreateIdentity();
	worldTransform_.matWorld_ *= CreateScale(worldTransform_.scale_);
	worldTransform_.matWorld_ *= CreateRotZ(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotX(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotY(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateTrans(worldTransform_.translation_);

	//�J�������_���W��ݒ�
	viewProjection_.eye = worldTransform_.translation_;

	//���[���h�O���x�N�g��
	Vector3 forward(0, 0, 1);
	//���[���J�����̉�]�𔻒�
	forward = Transform(forward, worldTransform_);
	//���_����O���ɓK���ȋ����i�񂾈ʒu�������_
	forward += viewProjection_.eye;
	viewProjection_.target = forward;

	//���[���h����x�N�g��
	Vector3 up(0, 1, 0);
	//���[���J�����̉�]�𔽉f(���[���J�����̏���x�N�g��)
	viewProjection_.up = Transform(up, worldTransform_);

	//�r���[�v���W�F�N�V�������X�V
	viewProjection_.UpdateMatrix();
}