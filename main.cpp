#include <Novice.h>

const char kWindowTitle[] = "GC1C_13_フジマ_ランマル_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {


	const int kBlockSize = 32;

	const int kStageWidth = 40;
	const int kStageHeight = 23;

	const int kWindowWidth = kStageWidth * kBlockSize;
	const int kWindowHeight = kStageHeight * kBlockSize;



	struct Vector2
	{
		float x;
		float y;
	};

	struct Player
	{
		float halfWidth;//プレイヤーの横幅
		float halfHeight;//プレイヤーの縦幅

		Vector2 centerPosition;//中心座標
		Vector2 leftTop;//playerLeftX 
		Vector2 rightTop;//playerRightX 
		Vector2 leftBottom;//playerTopY 
		Vector2 rightBottom;//playerBottomY

		Vector2 velocity;//移動速度

		Vector2 acceleration;//加速度

		int texture;//画像読み込み用変数
	};

	//プレイヤーの表示(矩形版)
	Player player =
	{
		16,32,
		{player.halfWidth,kWindowHeight - player.halfHeight},

		player.centerPosition.x - player.halfWidth,//左上X座標
			player.centerPosition.y - player.halfHeight,//左上Y座標
			player.centerPosition.x + player.halfWidth,//右上X座標
			player.centerPosition.y - player.halfHeight,//右上Y座標
			player.centerPosition.x - player.halfWidth,//左下X座標
			player.centerPosition.y + player.halfHeight,//左下Y座標
			player.centerPosition.x + player.halfWidth,//右下X座標
			player.centerPosition.y + player.halfHeight,//右下Y座標

		{0,0},

		{0,-0.8f},

	};


	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);


	int playerTx = Novice::LoadTexture("white1x1.png");

	int jumpChargeCount = 0;



	int zimenGrahp;
	zimenGrahp = Novice::LoadTexture("./Resources/.zimen.png");

	int zimenGrahp1;
	zimenGrahp1 = Novice::LoadTexture("./Resources/.zimen1.png");

	int zimenGrahp2;
	zimenGrahp2 = Novice::LoadTexture("./zimen2.png");

	int zimenGrahp3;
	zimenGrahp3 = Novice::LoadTexture("./zimen3.png");

	int zimenGrahp4;
	zimenGrahp4 = Novice::LoadTexture("./zimen4.png");

	int zimenGrahp5;
	zimenGrahp5 = Novice::LoadTexture("./zimen5.png");

	int zimenGrahp6;
	zimenGrahp6 = Novice::LoadTexture("./zimen6.png");

	int zimenGrahp7;
	zimenGrahp7 = Novice::LoadTexture("./zimen7.png");

	int zimenGrahp8;
	zimenGrahp8 = Novice::LoadTexture("./zimen8.png");

	int zimenGrahp9;
	zimenGrahp9 = Novice::LoadTexture("./zimen9.png");

	int zimenGrahp13;
	zimenGrahp13 = Novice::LoadTexture("./zimen13.png");

	int zimenGrahp16;
	zimenGrahp16 = Novice::LoadTexture("./zimen16.png");



	// キを受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	int blockPosX = 640;
	int blockPosY = 704;
	int blockRX = 640;
	int blockRY = 32;

	int  leftBottomX = blockPosX - blockRX;
	int    rightTopX = blockPosX + blockRX;
	int     leftTopY = blockPosY - blockRY;
	int rightBottomY = blockPosY + blockRY;

	int blockPosX1 = 48;//0
	int blockPosY1 = 624;//576
	int blockRX1 = 48;
	int blockRY1 = 48;

	int leftBottom1 = blockPosX1 - blockRX1;
	int rightTop1 = blockPosX1 + blockRX1;
	int leftTop1 = blockPosY1 - blockRY1;
	int rightBottom1 = blockPosY1 + blockRY1;

	int blockPosX2 = 320;
	int blockPosY2 = 640;
	int blockRX2 = 64;
	int blockRY2 = 32;

	int leftBottom2 = blockPosX2 - blockRX2;
	int rightTop2 = blockPosX2 + blockRX2;
	int leftTop2 = blockPosY2 - blockRY2;
	int rightBottom2 = blockPosY2 + blockRY2;

	int blockPosX3 = 576;
	int blockPosY3 = 624;
	int blockRX3 = 64;
	int blockRY3 = 48;

	int leftBottom3 = blockPosX3 - blockRX3;
	int rightTop3 = blockPosX3 + blockRX3;
	int leftTop3 = blockPosY3 - blockRY3;
	int rightBottom3 = blockPosY3 + blockRY3;

	int blockPosX4 = 800;
	int blockPosY4 = 576;
	int blockRX4 = 80;
	int blockRY4 = 32;

	int  leftBottom4 = blockPosX4 - blockRX4;
	int    rightTop4 = blockPosX4 + blockRX4;
	int     leftTop4 = blockPosY4 - blockRY4;
	int rightBottom4 = blockPosY4 + blockRY4;

	int blockPosX5 = 1056;
	int blockPosY5 = 624;
	int blockRX5 = 32;
	int blockRY5 = 48;

	int  leftBottom5 = blockPosX5 - blockRX5;
	int    rightTop5 = blockPosX5 + blockRX5;
	int     leftTop5 = blockPosY5 - blockRY5;
	int rightBottom5 = blockPosY5 + blockRY5;

	int blockPosX6 = 1104;//1088
	int blockPosY6 = 640;//608
	int blockRX6 = 16;
	int blockRY6 = 32;

	int  leftBottom6 = blockPosX6 - blockRX6;
	int    rightTop6 = blockPosX6 + blockRX6;
	int     leftTop6 = blockPosY6 - blockRY6;
	int rightBottom6 = blockPosY6 + blockRY6;

	int blockPosX7 = 1136;
	int blockPosY7 = 656;
	int blockRX7 = 16;
	int blockRY7 = 16;

	int  leftBottom7 = blockPosX7 - blockRX7;
	int    rightTop7 = blockPosX7 + blockRX7;
	int     leftTop7 = blockPosY7 - blockRY7;
	int rightBottom7 = blockPosY7 + blockRY7;

	int blockPosX8 = 176;
	int blockPosY8 = 464;
	int blockRX8 = 48;
	int blockRY8 = 16;

	int  leftBottom8 = blockPosX8 - blockRX8;
	int    rightTop8 = blockPosX8 + blockRX8;
	int     leftTop8 = blockPosY8 - blockRY8;
	int rightBottom8 = blockPosY8 + blockRY8;

	int blockPosX9 = 320;
	int blockPosY9 = 352;
	int blockRX9 = 32;
	int blockRY9 = 32;

	int  leftBottom9 = blockPosX9 - blockRX9;
	int    rightTop9 = blockPosX9 + blockRX9;
	int     leftTop9 = blockPosY9 - blockRY9;
	int rightBottom9 = blockPosY9 + blockRY9;

	int blockPosX10 = 464;
	int blockPosY10 = 288;
	int blockRX10 = 16;
	int blockRY10 = 32;

	int  leftBottom10 = blockPosX10 - blockRX10;
	int    rightTop10 = blockPosX10 + blockRX10;
	int     leftTop10 = blockPosY10 - blockRY10;
	int rightBottom10 = blockPosY10 + blockRY10;

	int blockPosX11 = 496;
	int blockPosY11 = 272;
	int blockRX11 = 16;
	int blockRY11 = 16;

	int  leftBottom11 = blockPosX11 - blockRX11;
	int    rightTop11 = blockPosX11 + blockRX11;
	int     leftTop11 = blockPosY11 - blockRY11;
	int rightBottom11 = blockPosY11 + blockRY11;

	int blockPosX12 = 528;
	int blockPosY12 = 256;
	int blockRX12 = 16;
	int blockRY12 = 32;

	int  leftBottom12 = blockPosX12 - blockRX12;
	int    rightTop12 = blockPosX12 + blockRX12;
	int     leftTop12 = blockPosY12 - blockRY12;
	int rightBottom12 = blockPosY12 + blockRY12;

	int blockPosX13 = 656;
	int blockPosY13 = 256;
	int blockRX13 = 48;
	int blockRY13 = 32;

	int  leftBottom13 = blockPosX13 - blockRX13;
	int    rightTop13 = blockPosX13 + blockRX13;
	int     leftTop13 = blockPosY13 - blockRY13;
	int rightBottom13 = blockPosY13 + blockRY13;

	int blockPosX14 = 784;
	int blockPosY14 = 192;
	int blockRX14 = 16;
	int blockRY14 = 32;

	int  leftBottom14 = blockPosX14 - blockRX14;
	int    rightTop14 = blockPosX14 + blockRX14;
	int     leftTop14 = blockPosY14 - blockRY14;
	int rightBottom14 = blockPosY14 + blockRY14;

	int blockPosX15 = 816;
	int blockPosY15 = 208;
	int blockRX15 = 16;
	int blockRY15 = 16;

	int  leftBottom15 = blockPosX15 - blockRX15;
	int    rightTop15 = blockPosX15 + blockRX15;
	int     leftTop15 = blockPosY15 - blockRY15;
	int rightBottom15 = blockPosY15 + blockRY15;

	int blockPosX16 = 896;
	int blockPosY16 = 80;
	int blockRX16 = 32;
	int blockRY16 = 16;

	int  leftBottom16 = blockPosX16 - blockRX16;
	int    rightTop16 = blockPosX16 + blockRX16;
	int     leftTop16 = blockPosY16 - blockRY16;
	int rightBottom16 = blockPosY16 + blockRY16;

	int blockPosX17 = 896;
	int blockPosY17 = 176;
	int blockRX17 = 32;
	int blockRY17 = 16;

	int  leftBottom17 = blockPosX17 - blockRX17;
	int    rightTop17 = blockPosX17 + blockRX17;
	int     leftTop17 = blockPosY17 - blockRY17;
	int rightBottom17 = blockPosY17 + blockRY17;

	int blockPosX18 = 1008;
	int blockPosY18 = 128;
	int blockRX18 = 16;
	int blockRY18 = 32;

	int  leftBottom18 = blockPosX18 - blockRX18;
	int    rightTop18 = blockPosX18 + blockRX18;
	int     leftTop18 = blockPosY18 - blockRY18;
	int rightBottom18 = blockPosY18 + blockRY18;

	int blockPosX19 = 1168;
	int blockPosY19 = 128;
	int blockRX19 = 80;
	int blockRY19 = 32;

	int  leftBottom19 = blockPosX19 - blockRX19;
	int    rightTop19 = blockPosX19 + blockRX19;
	int     leftTop19 = blockPosY19 - blockRY19;
	int rightBottom19 = blockPosY19 + blockRY19;


	  // ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		player.leftTop.x = player.centerPosition.x - player.halfWidth;//左上X座標
		player.leftTop.y = player.centerPosition.y - player.halfHeight;//左上Y座標
		player.rightTop.x = player.centerPosition.x + player.halfWidth;//右上X座標
		player.rightTop.y = player.centerPosition.y - player.halfHeight;//右上Y座標
		player.leftBottom.x = player.centerPosition.x - player.halfWidth;//左下X座標
		player.leftBottom.y = player.centerPosition.y + player.halfHeight;//左下Y座標
		player.rightBottom.x = player.centerPosition.x + player.halfWidth;//右下X座標
		player.rightBottom.y = player.centerPosition.y + player.halfHeight;//右下Y座標

		player.velocity.y += player.acceleration.y;

		player.centerPosition.y -= player.velocity.y;

		player.centerPosition.x += player.velocity.x;

		if (keys[DIK_SPACE] && jumpChargeCount <= 60) {
			jumpChargeCount++;

		}


		//キーが離れた瞬間に速度と加速度が付与される
		if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE]) {
			if (jumpChargeCount < 30) {//長押しするほどジャンプ力が上がる
				player.velocity.y = 15.0f;

				player.velocity.x = 2.0f;

			}
			else if (jumpChargeCount > 31) {
				player.velocity.y = 20;

				player.velocity.x = 3;
			}
			player.acceleration.y = -0.8f;


			jumpChargeCount = 0;

		}

		if (player.centerPosition.y > kWindowHeight - player.halfHeight) {

			player.centerPosition.y = float(kWindowHeight - player.halfHeight);

			player.velocity.y = 0;

			player.acceleration.y = 0;

			player.velocity.x = 0;

			player.acceleration.x = 0;
		}

		if (player.centerPosition.x > kWindowWidth - player.halfWidth) {
			player.centerPosition.x = kWindowWidth - player.halfWidth;
		}

		if (player.leftTop.x < rightBottomY && leftTopY < player.rightBottom.x) {
			if (player.leftTop.y < rightBottomY && leftTopY < player.leftBottom.y) {

			}
		}








		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///


		Novice::ScreenPrintf(0, 0, "counter=%d", jumpChargeCount);


		Novice::DrawQuad
		(
			int(player.leftTop.x),
			int(player.leftTop.y),
			int(player.rightTop.x),
			int(player.rightTop.y),
			int(player.leftBottom.x),
			int(player.leftBottom.y),
			int(player.rightBottom.x),
			int(player.rightBottom.y),
			0, 0, 1, 1, playerTx, WHITE
		);


		//Novice::DrawBox(0, 672, 1280, 736, 0.0f, WHITE, kFillModeSolid);
		Novice::DrawSprite(blockPosX - blockRX, blockPosY - blockRY, zimenGrahp, 1, 1, 0.0f, WHITE);

		/*	Novice::DrawBox(0, 576, 96, 96, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX1 - blockRX1, blockPosY1 - blockRY1, zimenGrahp1, 1, 1, 0.0f, WHITE);

		/*	Novice::DrawBox(256, 608, 128, 64, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX2 - blockRX2, blockPosY2 - blockRY2, zimenGrahp2, 1, 1, 0.0f, WHITE);

		/*  Novice::DrawBox(512, 576, 128, 96, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX3 - blockRX3, blockPosY3 - blockRY3, zimenGrahp3, 1, 1, 0.0f, WHITE);

		/*	Novice::DrawBox(736, 544, 160, 64, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX4 - blockRX4, blockPosY4 - blockRY4, zimenGrahp4, 1, 1, 0.0f, WHITE);

		/*Novice::DrawBox(1024, 576, 64, 96, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX5 - blockRX5, blockPosY5 - blockRY5, zimenGrahp5, 1, 1, 0.0f, WHITE);

		/*Novice::DrawBox(1088, 608, 32, 64, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX6 - blockRX6, blockPosY6 - blockRY6, zimenGrahp6, 1, 1, 0.0f, WHITE);

		/*	Novice::DrawBox(1120, 640, 32, 32, 0.0f, WHITE, kFillModeSolid);*/
		Novice::DrawSprite(blockPosX7 - blockRX7, blockPosY7 - blockRY7, zimenGrahp7, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX8 - blockRX8, blockPosY8 - blockRY8, zimenGrahp8, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX9 - blockRX9, blockPosY9 - blockRY9, zimenGrahp9, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX10 - blockRX10, blockPosY10 - blockRY10, zimenGrahp6, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX11 - blockRX11, blockPosY11 - blockRY11, zimenGrahp7, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX12 - blockRX12, blockPosY12 - blockRY12, zimenGrahp6, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX13 - blockRX13, blockPosY13 - blockRY13, zimenGrahp13, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX14 - blockRX14, blockPosY14 - blockRY14, zimenGrahp6, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX15 - blockRX15, blockPosY15 - blockRY15, zimenGrahp7, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX16 - blockRX16, blockPosY16 - blockRY16, zimenGrahp16, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX17 - blockRX17, blockPosY17 - blockRY17, zimenGrahp16, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX18 - blockRX18, blockPosY18 - blockRY18, zimenGrahp6, 1, 1, 0.0f, WHITE);

		Novice::DrawSprite(blockPosX19 - blockRX19, blockPosY19 - blockRY19, zimenGrahp4, 1, 1, 0.0f, WHITE);





		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
