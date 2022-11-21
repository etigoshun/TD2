#pragma once

#include <Model.h>
#include <WorldTransform.h>
#include <Input.h>
#include <DebugText.h>
#include <cassert>
#include "Affine.h"
#include "PlayerCommand.h"

class Player
{
public:		//メンバ関数

	/// <summary>
	/// 初期化
	/// </summary>
	/// <param name="model">モデル</param>
	/// <param name="texturehandle">テクスチャハンドル</param>
	void Initialize(Model* model, uint32_t textureHandle);

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(ViewProjection& viewProjection);

	//親子関係を結ぶセッター
	void SetParent(WorldTransform* worldTransform)
	{
		worldTransform_.parent_ = worldTransform;
	}

	//ワールド行列を取得
	WorldTransform* GetWorldMatrix() { return &worldTransform_; }
	
private:	//メンバ変数
	//ワールド変換データ
	WorldTransform worldTransform_;

	//モデル
	Model* model_ = nullptr;

	//テクスチャハンドル
	uint32_t textureHandle_ = 0u;

	//入力処理するため
	Input* input_ = nullptr;

	//デバッグテキスト
	DebugText* debugText_ = nullptr;

	//プレイヤーコマンドの生成
	std::unique_ptr<PlayerCommand> playerCmd = std::make_unique<PlayerCommand>();

	//ジャンプ力
	float jumpPower = 0;
	//ジャンプフラグ
	bool jumpFlag = false;

	//重力
	float gravity = 0;

	//HP
	int playerHp = 0;
};

