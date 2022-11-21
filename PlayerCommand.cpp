#include "PlayerCommand.h"
#include <TextureManager.h>

PlayerCommand::PlayerCommand()
{
	attackTH_ = TextureManager::Load("command/attack.png");
	guardTH_ = TextureManager::Load("command/guard.png");
	healTH_ = TextureManager::Load("command/heal.png");
}

PlayerCommand::~PlayerCommand()
{
	delete attackSprite;
}

/// <summary>
/// 初期化
/// </summary>
void PlayerCommand::Initialize()
{
	//シングルトンインスタンスを取得する
	input_ = Input::GetInstance();
	debugText_ = DebugText::GetInstance();

	//アタックコマンドの生成
	attackSprite = Sprite::Create(attackTH_, { 200,600 });

	guardSprite = Sprite::Create(guardTH_, { 510,600 });

	healSprite = Sprite::Create(healTH_, { 820, 600});

	//ワールド変換の初期化
	worldTransform_.Initialize();
}

/// <summary>
/// 更新
/// </summary>
void PlayerCommand::Update()
{
	
}

/// <summary>
/// 描画
/// </summary>
void PlayerCommand::Draw()
{
	//アタックコマンドの描画
	attackSprite->Draw();

	guardSprite->Draw();

	healSprite->Draw();
}

int PlayerCommand::Attack(int bossHp)
{
	bossHp -= 30;
	attackFlag = false;

	return bossHp;
}

int PlayerCommand::Guard(int bossAttack)
{
	bossAttack -= 20;
	guardFlag = false;

	return bossAttack;
}

int PlayerCommand::Heal(int playerHp)
{
	playerHp += 50;
	healFlag = false;

	return playerHp;
}
