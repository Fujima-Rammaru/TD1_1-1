#include <Novice.h>


const char kWindowTitle[] = "GC1C_13_フジマ_ランマル_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	//==================================================================
	//キャラクターの動き用変数用意
	// =================================================================
	// ライブラリの初期化
	const int kBlockSize = 32;

	const int kStageWidth = 40;
	const int kStageHeight = 23;

	const int kWindowWidth = kStageWidth * kBlockSize;
	const int kWindowHeight = kStageHeight * kBlockSize;

	//ブロックの個数
	const int kBlockQuantify = 15;

	struct Vector2
	{
		float x;
		float y;
	};

	struct Block
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Player
	{
		float halfWidth;//プレイヤーの横幅
		float halfHeight;//プレイヤーの縦幅

		Vector2 centerPosition;//中心座標
		Vector2 leftTop;
		Vector2 rightTop;
		Vector2 leftBottom;
		Vector2 rightBottom;

		Vector2 velocity;//移動速度

		Vector2 acceleration;//加速度

	};

	//プレイヤーの表示(矩形版)
	Player player =
	{
		16,32,
		{32,
		kWindowHeight - player.halfHeight},

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


	Block block[kBlockQuantify];
	for (int i = 0; i < kBlockQuantify; i++) {



		block[i].halfsize = 16;

		block[i].pos.x = float(32 * i) + 200;

		block[i].pos.y = 500;


		//左上
		block[i].leftT.x = block[i].pos.x - block[i].halfsize;
		block[i].leftT.y = block[i].pos.y - block[i].halfsize;
		//左下																 
		block[i].leftB.x = block[i].pos.x - block[i].halfsize;
		block[i].leftB.y = block[i].pos.y + block[i].halfsize;

		//右上																 
		block[i].rightT.x = block[i].pos.x + block[i].halfsize;
		block[i].rightT.y = block[i].pos.y - block[i].halfsize;

		//右下																 
		block[i].rightB.x = block[i].pos.x + block[i].halfsize;
		block[i].rightB.y = block[i].pos.y + block[i].halfsize;


	}



	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	int playerHandle[3] =
	{

		Novice::LoadTexture("./Resources/HOPPER player1.png"),
		Novice::LoadTexture("./Resources/HOPPER player2.png"),
		Novice::LoadTexture("./Resources/HOPPER player3.png"),
	};

	int currentPlayerTx = playerHandle[0];//プレイヤー画像

	int jumpChargeCount = 0;

	int jumpAudio = Novice::LoadAudio("./Resources/Sound/jump.wav");

	int jumpAudioHandle = -1;

	int jumpCount = 0;

	//==================================================================
	//シーン遷移用変数用意
	// =================================================================

	int blockTx = Novice::LoadTexture("./Resources/white1x1.png");


	enum SCENE {
		GAME_TITLE,//0
		GAME_PLAY,//
		GAME_RESULT,//2
		GAME_OVER,//3

	};

	//シーン遷移の値格納用変数
	int sceneNumber = 0;

	//スタート画面のエンターを押したときのSE読み込み
	int pressEnterAudio = Novice::LoadAudio("./Resources/Sound/Enter_sounds.wav");

	int pressEnterAudioHandle = -1;

	int pressEnterTimer = 0;

	//エンターが押されたかどうか
	bool isPressEnter = false;


	//BGM読み込み用の変数
	int gameTitleAudio = Novice::LoadAudio("./Resources/Sound/Game_Title_BGM.wav");

	int gamePlayAudio = Novice::LoadAudio("./Resources/Sound/Game_Play_BGM.wav");

	int playHandle_gameTitle = -1;

	int playHandle_gamePlay = -1;

	//int playHandle_gameOver = -1;

	//int playHandle_gameResult = -1;

	// //ゲームオーバー画面のBGM読み込み
	// int gameOverAudio = Novice::LoadAudio("./Resources/Sound/gameover.wav");


	//アニメーションの移動速度
	int animationspeed = 2;

	//壁の初期座標
	int wallPosX = 0;

	int TITLETexture = Novice::LoadTexture("./Resources/HOPPER Title.png");

	int PLAYTexture = Novice::LoadTexture("./Resources/background.png");

	int RESULTTexture = Novice::LoadTexture("./Resources/HOPPER CLEAR.png");

	int GAME_OVERTexture = Novice::LoadTexture("./Resources/HOPPER OVER.png");

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

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




		switch (sceneNumber) {

		case GAME_TITLE:

			//BGMを再生するための処理
			if (Novice::IsPlayingAudio(playHandle_gameTitle) == 0 && pressEnterTimer == 0) {
				playHandle_gameTitle = Novice::PlayAudio(gameTitleAudio, true, 1.0f);
			}

			//エンターを押したとき効果音が流れる（BGMの再生を停止してから）、
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				if (Novice::IsPlayingAudio(pressEnterAudioHandle) == 0) {

					Novice::StopAudio(playHandle_gameTitle);

					wallPosX = -kWindowWidth - 560;

					pressEnterAudioHandle = Novice::PlayAudio(pressEnterAudio, false, 0.5f);
				}
				isPressEnter = true;

			}

			//エンターを押したとき秒数カウント用変数が始動する
			if (isPressEnter) {
				pressEnterTimer++;
			}

			//2秒後に次のシーンに切り替わる
			if (pressEnterTimer == 120) {

				//プレイヤの座標をリセット
				player.centerPosition.x = 32;
				player.centerPosition.y = kWindowHeight - player.halfHeight;

				sceneNumber = 1;
				pressEnterTimer = 0;
				isPressEnter = false;
			}
			break;

		case GAME_PLAY:

			//BGMを再生するための処理
			if (Novice::IsPlayingAudio(playHandle_gamePlay) == 0 && pressEnterTimer == 0) {
				playHandle_gamePlay = Novice::PlayAudio(gamePlayAudio, true, 1.0f);
			}

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				if (Novice::IsPlayingAudio(pressEnterAudioHandle) == 0) {

					Novice::StopAudio(playHandle_gamePlay);

					pressEnterAudioHandle = Novice::PlayAudio(pressEnterAudio, false, 0.5f);
				}

				isPressEnter = true;

			}

			//エンターを押したとき秒数カウント用変数に1フレにつき+1する
			if (isPressEnter) {
				pressEnterTimer++;
			}

			//1秒後に次のシーンに切り替わる
			if (pressEnterTimer == 60) {
				sceneNumber = 2;
				pressEnterTimer = 0;
				isPressEnter = false;
			}

			//壁の移動処理
			wallPosX += animationspeed;

			if (wallPosX > 0) {
				wallPosX = 0;

			}

			//壁の当たり判定
			if (wallPosX + 1280 > player.centerPosition.x - player.halfWidth) {
				sceneNumber = GAME_OVER;

			}


			//プレイヤーの更新処理ここから↓
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


			//床の当たり判定(上の辺)
			for (int i = 0; i < kBlockQuantify; i++) {

				if (block[i].leftT.x < player.rightBottom.x && player.leftTop.x < block[i].rightB.x) {

					if (player.centerPosition.y > block[i].leftT.y - player.halfHeight) {

						if (player.centerPosition.y + player.halfHeight < block[i].leftB.y) {

							currentPlayerTx = playerHandle[0];

							player.centerPosition.y = block[i].leftT.y - player.halfHeight;
							player.velocity.x = 0;
							player.velocity.y = 0;

							jumpCount = 0;
						}

					}
				}
			}

			//床の当たり判定(下の辺)
			for (int i = 0; i < kBlockQuantify; i++) {

				//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
				if (block[i].leftT.x < player.rightBottom.x && player.leftTop.x < block[i].rightB.x) {

					//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
					if (player.leftTop.y < block[i].leftB.y && block[i].rightT.y < player.leftTop.y) {

						player.centerPosition.y = block[i].leftB.y + player.halfHeight;

						player.velocity.y = 0;


					}
				}
			}

			if (jumpCount < 2) {
				if (keys[DIK_SPACE]) {
					currentPlayerTx = playerHandle[1];
					jumpChargeCount++;

				}


				//キーが離れた瞬間に速度と加速度が付与される
				if (keys[DIK_SPACE] == 0 && preKeys[DIK_SPACE]) {

					currentPlayerTx = playerHandle[2];

					jumpCount++;

					if (jumpChargeCount < 30) {//長押しするほどジャンプ力が上がる
						player.velocity.y = 15.0f;

						player.velocity.x = 2.0f;

					}
					else if (jumpChargeCount > 31) {
						player.velocity.y = 20;

						player.velocity.x = 3;
					}
					player.acceleration.y = -0.8f;

					if (Novice::IsPlayingAudio(jumpAudioHandle) == 0) {
						jumpAudioHandle = Novice::PlayAudio(jumpAudio, false, 1.0f);

					}


					jumpChargeCount = 0;

				}
			}


			if (player.centerPosition.y > kWindowHeight - player.halfHeight) {

				currentPlayerTx = playerHandle[0];

				player.centerPosition.y = float(kWindowHeight - player.halfHeight);

				player.velocity.y = 0;

				player.acceleration.y = 0;

				player.velocity.x = 0;

				player.acceleration.x = 0;

				jumpCount = 0;

			}

			if (player.centerPosition.x > kWindowWidth - player.halfWidth) {
				player.centerPosition.x = kWindowWidth - player.halfWidth;
			}
			//プレイヤーの更新処理ここまで↑

			break;

		case GAME_RESULT:
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {

				isPressEnter = true;

			}

			//エンターを押したとき秒数カウント用変数が始動する
			if (isPressEnter) {
				pressEnterTimer++;
			}

			//1秒後に次のシーンに切り替わる
			if (pressEnterTimer == 60) {
				sceneNumber = 3;
				pressEnterTimer = 0;
				isPressEnter = false;
			}



			break;

		case GAME_OVER:

			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {

				isPressEnter = true;

			}

			//エンターを押したとき秒数カウント用変数が始動する
			if (isPressEnter) {
				pressEnterTimer++;
			}

			//1秒後に次のシーンに切り替わる
			if (pressEnterTimer == 60) {
				sceneNumber = 0;
				pressEnterTimer = 0;
				isPressEnter = false;
			}

			break;

		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (sceneNumber) {

		case GAME_TITLE:
			Novice::DrawSprite(0, 0, TITLETexture, 1, 1, 0.0f, WHITE);
			break;

		case GAME_PLAY:

			Novice::DrawSprite(0, 0, PLAYTexture, 1, 1, 0.0f, WHITE);

			Novice::DrawBox(wallPosX, 0, kWindowWidth, kWindowHeight, 0.0f, GREEN, kFillModeSolid);

			//自機の描画
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
				0, 0, 32, 64, currentPlayerTx, WHITE
			);

			//ブロックの描画
			for (int i = 0; i < kBlockQuantify; i++) {
				Novice::DrawQuad
				(
					int(block[i].leftT.x),
					int(block[i].leftT.y),

					int(block[i].rightT.x),
					int(block[i].rightT.y),

					int(block[i].leftB.x),
					int(block[i].leftB.y),

					int(block[i].rightB.x),
					int(block[i].rightB.y),

					0, 0, 32, 32, blockTx, BLACK


				);

			}

			Novice::ScreenPrintf(0, 0, "counter=%d", jumpChargeCount);

			break;

		case GAME_RESULT:
			Novice::DrawSprite(0, 0, RESULTTexture, 1, 1, 0.0f, WHITE);
			break;

		case GAME_OVER:
			Novice::DrawSprite(0, 0, GAME_OVERTexture, 1, 1, 0.0f, WHITE);
			break;

		}






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
