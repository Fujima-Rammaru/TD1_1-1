#include <Novice.h>


const char kWindowTitle[] = "GC1C_13_フジマ_ランマル_タイトル";


// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化

	const int kBlockSize = 32;

	const int kStageWidth = 40;
	const int kStageHeight = 23;

	const int kWindowWidth = kStageWidth * kBlockSize;
	const int kWindowHeight = kStageHeight * kBlockSize;

	//ブロックの個数
	const int kBlockQuantify = 10;

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

	int playerTx = Novice::LoadTexture("white1x1.png");

	int jumpChargeCount = 0;

	int jumpAudio = Novice::LoadAudio("./Resources/Sound/jump.wav");

	int jumpAudioHandle = -1;


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


		for (int i = 0; i < kBlockQuantify; i++) {
			if (block[i].leftT.x < player.rightBottom.x && player.leftTop.x < block[i].rightB.x) {
				if (player.centerPosition.y > block[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block[i].leftB.y) {
						player.centerPosition.y = block[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}





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

			if (Novice::IsPlayingAudio(jumpAudioHandle) == 0) {
				jumpAudioHandle = Novice::PlayAudio(jumpAudio, false, 1.0f);

			}


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

				0, 0, 32, 32, playerTx, RED


			);

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
