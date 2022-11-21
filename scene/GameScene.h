#pragma once

#include "Audio.h"
#include "DirectXCommon.h"
#include "DebugText.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Player.h"
#include "RailCamera.h"
#include "Skydome.h"
#include <memory>
#include "PlayerCommand.h"

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

  public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

  private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;
	DebugText* debugText_ = nullptr;
	//ビュープロジェクション
	ViewProjection viewProjection_;

	//プレイヤー
	std::unique_ptr<Player> newPlayer = std::make_unique<Player>();
	//プレイヤーモデル
	Model* playerModel_ = nullptr;
	//プレイヤーのテクスチャハンドル
	uint32_t playerTH_ = 0;

	//	天球を生成し、初期化
	std::unique_ptr<Skydome> newSkydome = std::make_unique<Skydome>();
	//スカイドームモデル
	Model* modelSkydome_ = nullptr;

	//レールカメラ
	std::unique_ptr<RailCamera> newRailCamera = std::make_unique<RailCamera>();

	//
	std::unique_ptr<PlayerCommand> newCommand = std::make_unique<PlayerCommand>();

	/// <summary>
	/// ゲームシーン用
	/// </summary>
};
