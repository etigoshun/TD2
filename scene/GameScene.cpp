#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>

GameScene::GameScene() {}

GameScene::~GameScene() {
	//プレイヤーモデルの削除
	delete playerModel_;
}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	debugText_ = DebugText::GetInstance();

	//ファイル名を指定してテクスチャを読み込む
	playerTH_ = TextureManager::Load("cube/cube.jpg");

	//model_ = Model::Create();
	//3Dモデルの生成
	playerModel_ = Model::CreateFromOBJ("cube", true);

	//3Dモデルの生成
	modelSkydome_ = Model::CreateFromOBJ("skydome", true);

	//ビュープロジェクションの初期化
	viewProjection_.Initialize();

	//プレイヤーの初期化
	newPlayer->Initialize(playerModel_, playerTH_);

	//天球の初期化
	newSkydome->Initialize(modelSkydome_);

	Vector3 cameraPos(0, 0, 5);
	Vector3 cameraRot(0, 0, 0);
	//レールカメラの初期化
	newRailCamera->Initialize(cameraPos, cameraRot);

	//自キャラとレールカメラの親子関係を結ぶ
	//newRailCamera->SetParent(newPlayer->GetWorldMatrix());

	newCommand->Initialize();
}

void GameScene::Update() {

	//プレイヤーの更新
	newPlayer->Update();

	//天球の更新
	newSkydome->Update();

	//レールカメラの更新
	newRailCamera->Update();

	//レールカメラをゲームシーンのカメラに適応する
	viewProjection_.matView = newRailCamera->GetViewProjection().matView;
	viewProjection_.matProjection = newRailCamera->GetViewProjection().matProjection;

	//ビュープロジェクションの転送
	viewProjection_.TransferMatrix();

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	newPlayer->Draw(viewProjection_);

	//天球の描画
	newSkydome->Draw(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	newCommand->Draw();

	// デバッグテキストの描画
	debugText_->DrawAll(commandList);
	//
	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
