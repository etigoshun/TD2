#include "Player.h"

/// <summary>
/// 初期化
/// </summary>
/// <param name="model">モデル</param>
/// <param name="texturehandle">テクスチャハンドル</param>
void Player::Initialize(Model* model, uint32_t textureHandle)
{
	//NULLポインタチェック
	assert(model);

	//引数として受け取ったデータをメンバ変数に記録する
	model_ = model;
	textureHandle_ = textureHandle;

	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ワールド変換の初期化
	//worldTransform_.translation_.z = 50;
	worldTransform_.Initialize();

	worldTransform_.scale_ = { 1.0f,1.0f,1.0f };
	worldTransform_.translation_ = { 0,-5,50 };
	
}


/// <summary>
/// 更新
/// </summary>
void Player::Update()
{

	//キャラクターの移動ベクトル
	Vector3 move = { 0,0,0 };

	//移動ベクトルを変更する処理
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

	//座標移動
	worldTransform_.translation_ += move;


	//移動限界処理
	const float kMoveLimitX = 33.0f;
	const float kMoveLimitY = 17.0f;

	//範囲を超えない処理
	worldTransform_.translation_.x = max(worldTransform_.translation_.x, -kMoveLimitX);
	worldTransform_.translation_.x = min(worldTransform_.translation_.x, +kMoveLimitX);
	worldTransform_.translation_.y = max(worldTransform_.translation_.y, -kMoveLimitY);
	//worldTransform_.translation_.y = min(worldTransform_.translation_.y, +kMoveLimitY);

	//行列の更新
	worldTransform_.matWorld_ = CreateIdentity();
	worldTransform_.matWorld_ *= CreateScale(worldTransform_.scale_);
	worldTransform_.matWorld_ *= CreateRotZ(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotX(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateRotY(worldTransform_.rotation_);
	worldTransform_.matWorld_ *= CreateTrans(worldTransform_.translation_);

	//親子関係
	//worldTransform_.matWorld_ *= worldTransform_.parent_->matWorld_;

	worldTransform_.TransferMatrix();

	//キャラクターの座標を画面に表示する
	debugText_->SetPos(50, 150);
	debugText_->Printf("translation:(%f,%f,%f)", worldTransform_.translation_.x, worldTransform_.translation_.y, worldTransform_.translation_.z);

	//自キャラの回転処理
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
/// 描画
/// </summary>
void Player::Draw(ViewProjection& viewProjection)
{
	//3Dモデルを描画
	model_->Draw(worldTransform_, viewProjection, textureHandle_);
}