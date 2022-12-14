#include "RailCamera.h"
#include "MyMath.h"
#include "Affine.h"

void RailCamera::Initialize(Vector3& position, Vector3& rotation)
{
	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ワールドトランスフォームの初期設定
	worldTransform_.translation_ = position;
	worldTransform_.rotation_ = rotation;

	//ビュープロジェクションの初期化
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

	

	//デバッグ用表示
	debugText_->SetPos(50, 50);
	debugText_->Printf("RailCamera pos:(%f, %f, %f)", viewProjection_.eye.x, viewProjection_.eye.y, viewProjection_.eye.z);
	
}

void RailCamera::ZoomOut(Vector3 cameraMove)
{

	cameraMove.y -= 0.01;

	cameraMove.z -= 0.05;

	worldTransform_.translation_ += cameraMove;

	//行列の更新
	worldTransform_.matWorld_ = CreateIdentity();
	worldTransform_.matWorld_ *= CreateScale(worldTransform_.scale_);
	worldTransform_.matWorld_ *= CreateRotZ(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotX(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotY(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateTrans(worldTransform_.translation_);

	//カメラ視点座標を設定
	viewProjection_.eye = worldTransform_.translation_;

	//ワールド前方ベクトル
	Vector3 forward(0, 0, 1);
	//レールカメラの回転を判定
	forward = Transform(forward, worldTransform_);
	//視点から前方に適当な距離進んだ位置が注視点
	forward += viewProjection_.eye;
	viewProjection_.target = forward;

	//ワールド上方ベクトル
	Vector3 up(0, 1, 0);
	//レールカメラの回転を反映(レールカメラの上方ベクトル)
	viewProjection_.up = Transform(up, worldTransform_);

	//ビュープロジェクションを更新
	viewProjection_.UpdateMatrix();
}
