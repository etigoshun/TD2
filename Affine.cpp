#include "Affine.h"

//�P�ʍs�񐶐��֐�
Matrix4 CreateIdentity()
{
	//�P�ʍs��
	Matrix4 matIdentity;

	matIdentity.m[0][0] = 1;
	matIdentity.m[1][1] = 1;
	matIdentity.m[2][2] = 1;
	matIdentity.m[3][3] = 1;

	return matIdentity;
}

//�X�P�[�����O�s��֐�
Matrix4 CreateScale(Vector3 scale)
{
	//�X�P�[�����O�s���錾
	Matrix4 matScale;

	matScale.m[0][0] = scale.x;
	matScale.m[1][1] = scale.y;
	matScale.m[2][2] = scale.z;
	matScale.m[3][3] = 1.0f;

	return matScale;
}

//Z����]�s��֐�
Matrix4 CreateRotZ(Vector3 rotation)
{
	//�e���p��]�s���錾
	Matrix4 matRotZ;

	//Z����]�s��
	matRotZ.m[0][0] = cos(rotation.z);
	matRotZ.m[0][1] = sin(rotation.z);
	matRotZ.m[1][0] = -sin(rotation.z);
	matRotZ.m[1][1] = cos(rotation.z);
	matRotZ.m[2][2] = 1;
	matRotZ.m[3][3] = 1;


	return matRotZ;
}

//X����]�s��֐�
Matrix4 CreateRotX(Vector3 rotation)
{
	//�e���p��]�s���錾
	Matrix4 matRotX;
	//X����]�s��
	matRotX.m[0][0] = 1;
	matRotX.m[1][1] = cos(rotation.x);
	matRotX.m[1][2] = sin(rotation.x);
	matRotX.m[2][1] = -sin(rotation.x);
	matRotX.m[2][2] = cos(rotation.x);
	matRotX.m[3][3] = 1;

	return matRotX;
}

//Y����]�s��֐�
Matrix4 CreateRotY(Vector3 rotation)
{
	//�e���p��]�s���錾
	Matrix4 matRotY;

	//Y����]�s��
	matRotY.m[0][0] = cos(rotation.y);
	matRotY.m[1][1] = 1;
	matRotY.m[0][2] = -sin(rotation.y);
	matRotY.m[2][0] = sin(rotation.y);
	matRotY.m[2][2] = cos(rotation.y);
	matRotY.m[3][3] = 1;

	return matRotY;
}

//���s�ړ��s��֐�
Matrix4 CreateTrans(Vector3 translation)
{
	//���s�ړ��s���錾
	Matrix4 matTrans = MathUtility::Matrix4Identity();

	//�ړ��ʂ��s��ɐݒ�
	matTrans.m[3][0] = translation.x;
	matTrans.m[3][1] = translation.y;
	matTrans.m[3][2] = translation.z;

	return matTrans;
}