#pragma once
#include <WorldTransform.h>
#include <Input.h>
#include <DebugText.h>
#include <Sprite.h>
#include <cassert>
#include "Affine.h"

class PlayerCommand
{
public:		//メンバ関数

	PlayerCommand();
	~PlayerCommand();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	int Attack(int bossHp);

	int Guard(int bossAtaack);

	int Heal(int playerHp);

private:	//メンバ変数

	//ワールド変換データ
	WorldTransform worldTransform_;

	//攻撃テクスチャハンドル
	uint32_t attackTH_ = 0u;

	uint32_t guardTH_ = 0u;

	uint32_t healTH_ = 0u;

	//入力処理するため
	Input* input_ = nullptr;

	//デバッグテキスト
	DebugText* debugText_ = nullptr;

	//攻撃コマンド
	Sprite* attackSprite = nullptr;
	//防御コマンド
	Sprite* guardSprite = nullptr;
	//回復コマンド
	Sprite* healSprite = nullptr;

	bool attackFlag = false;
	bool guardFlag = false;
	bool healFlag = false;
};

