#pragma once

#include "Sprite.h"
#include "MathUtility.h"

//�P�ʍs�񐶐��֐�
Matrix4 CreateIdentity();

//�X�P�[�����O�s��֐�
Matrix4 CreateScale(Vector3 scale);

//Z����]�s��֐�
Matrix4 CreateRotZ(Vector3 rotation);

//X����]�s��֐�
Matrix4 CreateRotX(Vector3 rotation);

//Y����]�s��֐�
Matrix4 CreateRotY(Vector3 rotation);

//���s�ړ��s��֐�
Matrix4 CreateTrans(Vector3 translation);

