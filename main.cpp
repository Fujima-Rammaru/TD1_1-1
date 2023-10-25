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
	const int kBlockQuantify = 40;
	const int kBlockQuantify2 = 3;
	const int kBlockQuantify3 = 4;
	const int kBlockQuantify4 = 5;
	const int kBlockQuantify5 = 3;
	const int kBlockQuantify6 = 2;


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

	struct Block2
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block3
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block4
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block5
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};


	struct Block6
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block7
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block8
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block9
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block10
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block11
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block12
	{
		float halfsize;
		Vector2 pos;
		Vector2 leftT;
		Vector2 rightT;
		Vector2 leftB;
		Vector2 rightB;

	};

	struct Block13
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



		block[i].halfsize = 32;

		block[i].pos.x = float(32 * i) + 16;

		block[i].pos.y = 720;


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


	Block2 block2[kBlockQuantify2];
	for (int i = 0; i < kBlockQuantify2; i++) {



		block2[i].halfsize = 48;

		block2[i].pos.x = float(16 * i) + 0;

		block2[i].pos.y = 672;


		//左上
		block2[i].leftT.x = block2[i].pos.x - block2[i].halfsize;
		block2[i].leftT.y = block2[i].pos.y - block2[i].halfsize;
		//左下																 
		block2[i].leftB.x = block2[i].pos.x - block2[i].halfsize;
		block2[i].leftB.y = block2[i].pos.y + block2[i].halfsize;

		//右上																 
		block2[i].rightT.x = block2[i].pos.x + block2[i].halfsize;
		block2[i].rightT.y = block2[i].pos.y - block2[i].halfsize;

		//右下																 
		block2[i].rightB.x = block2[i].pos.x + block2[i].halfsize;
		block2[i].rightB.y = block2[i].pos.y + block2[i].halfsize;


	}


	Block3 block3[kBlockQuantify3];
	for (int i = 0; i < kBlockQuantify3; i++) {



		block3[i].halfsize = 32;

		block3[i].pos.x = float(16 * i) + 256;

		block3[i].pos.y = 672;


		//左上
		block3[i].leftT.x = block3[i].pos.x - block3[i].halfsize;
		block3[i].leftT.y = block3[i].pos.y - block3[i].halfsize;
		//左下																 
		block3[i].leftB.x = block3[i].pos.x - block3[i].halfsize;
		block3[i].leftB.y = block3[i].pos.y + block3[i].halfsize;

		//右上																 
		block3[i].rightT.x = block3[i].pos.x + block3[i].halfsize;
		block3[i].rightT.y = block3[i].pos.y - block3[i].halfsize;

		//右下																 
		block3[i].rightB.x = block3[i].pos.x + block3[i].halfsize;
		block3[i].rightB.y = block3[i].pos.y + block3[i].halfsize;


	}

	Block4 block4[kBlockQuantify3];
	for (int i = 0; i < kBlockQuantify3; i++) {



		block4[i].halfsize = 48;

		block4[i].pos.x = float(16 * i) + 512;

		block4[i].pos.y = 672;


		//左上
		block4[i].leftT.x = block4[i].pos.x - block4[i].halfsize;
		block4[i].leftT.y = block4[i].pos.y - block4[i].halfsize;
		//左下																 
		block4[i].leftB.x = block4[i].pos.x - block4[i].halfsize;
		block4[i].leftB.y = block4[i].pos.y + block4[i].halfsize;

		//右上																 
		block4[i].rightT.x = block4[i].pos.x + block4[i].halfsize;
		block4[i].rightT.y = block4[i].pos.y - block4[i].halfsize;

		//右下																 
		block4[i].rightB.x = block4[i].pos.x + block4[i].halfsize;
		block4[i].rightB.y = block4[i].pos.y + block4[i].halfsize;


	}

	Block5 block5[kBlockQuantify4];
	for (int i = 0; i < kBlockQuantify4; i++) {



		block5[i].halfsize = 32;

		block5[i].pos.x = float(32 * i) + 736;

		block5[i].pos.y = 576;


		//左上
		block5[i].leftT.x = block5[i].pos.x - block5[i].halfsize;
		block5[i].leftT.y = block5[i].pos.y - block5[i].halfsize;
		//左下																 
		block5[i].leftB.x = block5[i].pos.x - block5[i].halfsize;
		block5[i].leftB.y = block5[i].pos.y + block5[i].halfsize;

		//右上																 
		block5[i].rightT.x = block5[i].pos.x + block5[i].halfsize;
		block5[i].rightT.y = block5[i].pos.y - block5[i].halfsize;

		//右下																 
		block5[i].rightB.x = block5[i].pos.x + block5[i].halfsize;
		block5[i].rightB.y = block5[i].pos.y + block5[i].halfsize;


	}

	Block6 block6[kBlockQuantify2];
	for (int i = 0; i < kBlockQuantify2; i++) {



		block6[i].halfsize = 48;

		block6[i].pos.x = float(4 * i) + 1024;

		block6[i].pos.y = 672;


		//左上
		block6[i].leftT.x = block6[i].pos.x - block6[i].halfsize;
		block6[i].leftT.y = block6[i].pos.y - block6[i].halfsize;
		//左下																 
		block6[i].leftB.x = block6[i].pos.x - block6[i].halfsize;
		block6[i].leftB.y = block6[i].pos.y + block6[i].halfsize;

		//右上																 
		block6[i].rightT.x = block6[i].pos.x + block6[i].halfsize;
		block6[i].rightT.y = block6[i].pos.y - block6[i].halfsize;

		//右下																 
		block6[i].rightB.x = block6[i].pos.x + block6[i].halfsize;
		block6[i].rightB.y = block6[i].pos.y + block6[i].halfsize;


	}

	Block7 block7[kBlockQuantify5];
	for (int i = 0; i < kBlockQuantify5; i++) {



		block7[i].halfsize = 16;

		block7[i].pos.x = float(16 * i) + 128;

		block7[i].pos.y = 448;


		//左上
		block7[i].leftT.x = block7[i].pos.x - block7[i].halfsize;
		block7[i].leftT.y = block7[i].pos.y - block7[i].halfsize;
		//左下																 
		block7[i].leftB.x = block7[i].pos.x - block7[i].halfsize;
		block7[i].leftB.y = block7[i].pos.y + block7[i].halfsize;

		//右上																 
		block7[i].rightT.x = block7[i].pos.x + block7[i].halfsize;
		block7[i].rightT.y = block7[i].pos.y - block7[i].halfsize;

		//右下																 
		block7[i].rightB.x = block7[i].pos.x + block7[i].halfsize;
		block7[i].rightB.y = block7[i].pos.y + block7[i].halfsize;


	}

	Block8 block8[kBlockQuantify6];
	for (int i = 0; i < kBlockQuantify6; i++) {



		block8[i].halfsize = 32;

		block8[i].pos.x = float(16 * i) + 288;

		block8[i].pos.y = 320;


		//左上
		block8[i].leftT.x = block8[i].pos.x - block8[i].halfsize;
		block8[i].leftT.y = block8[i].pos.y - block8[i].halfsize;
		//左下																 
		block8[i].leftB.x = block8[i].pos.x - block8[i].halfsize;
		block8[i].leftB.y = block8[i].pos.y + block8[i].halfsize;

		//右上																 
		block8[i].rightT.x = block8[i].pos.x + block8[i].halfsize;
		block8[i].rightT.y = block8[i].pos.y - block8[i].halfsize;

		//右下																 
		block8[i].rightB.x = block8[i].pos.x + block8[i].halfsize;
		block8[i].rightB.y = block8[i].pos.y + block8[i].halfsize;


	}

	Block9 block9[kBlockQuantify5];
	for (int i = 0; i < kBlockQuantify5; i++) {



		block9[i].halfsize = 16;

		block9[i].pos.x = float(32 * i) + 448;

		block9[i].pos.y = 256;


		//左上
		block9[i].leftT.x = block9[i].pos.x - block9[i].halfsize;
		block9[i].leftT.y = block9[i].pos.y - block9[i].halfsize;
		//左下																 
		block9[i].leftB.x = block9[i].pos.x - block9[i].halfsize;
		block9[i].leftB.y = block9[i].pos.y + block9[i].halfsize;

		//右上																 
		block9[i].rightT.x = block9[i].pos.x + block9[i].halfsize;
		block9[i].rightT.y = block9[i].pos.y - block9[i].halfsize;

		//右下																 
		block9[i].rightB.x = block9[i].pos.x + block9[i].halfsize;
		block9[i].rightB.y = block9[i].pos.y + block9[i].halfsize;


	}

	Block10 block10[kBlockQuantify5];
	for (int i = 0; i < kBlockQuantify5; i++) {



		block10[i].halfsize = 32;

		block10[i].pos.x = float(32 * i) + 608;

		block10[i].pos.y = 224;


		//左上
		block10[i].leftT.x = block10[i].pos.x - block10[i].halfsize;
		block10[i].leftT.y = block10[i].pos.y - block10[i].halfsize;
		//左下																 
		block10[i].leftB.x = block10[i].pos.x - block10[i].halfsize;
		block10[i].leftB.y = block10[i].pos.y + block10[i].halfsize;

		//右上																 
		block10[i].rightT.x = block10[i].pos.x + block10[i].halfsize;
		block10[i].rightT.y = block10[i].pos.y - block10[i].halfsize;

		//右下																 
		block10[i].rightB.x = block10[i].pos.x + block10[i].halfsize;
		block10[i].rightB.y = block10[i].pos.y + block10[i].halfsize;


	}

	Block11 block11[kBlockQuantify6];
	for (int i = 0; i < kBlockQuantify6; i++) {



		block11[i].halfsize = 16;

		block11[i].pos.x = float(32 * i) + 768;

		block11[i].pos.y = 160;


		//左上
		block11[i].leftT.x = block11[i].pos.x - block11[i].halfsize;
		block11[i].leftT.y = block11[i].pos.y - block11[i].halfsize;
		//左下																 
		block11[i].leftB.x = block11[i].pos.x - block11[i].halfsize;
		block11[i].leftB.y = block11[i].pos.y + block11[i].halfsize;

		//右上																 
		block11[i].rightT.x = block11[i].pos.x + block11[i].halfsize;
		block11[i].rightT.y = block11[i].pos.y - block11[i].halfsize;

		//右下																 
		block11[i].rightB.x = block11[i].pos.x + block11[i].halfsize;
		block11[i].rightB.y = block11[i].pos.y + block11[i].halfsize;


	}

	Block12 block12[kBlockQuantify6];
	for (int i = 0; i < kBlockQuantify6; i++) {



		block12[i].halfsize = 16;

		block12[i].pos.x = float(32 * i) + 928;

		block12[i].pos.y = 160;


		//左上
		block12[i].leftT.x = block12[i].pos.x - block12[i].halfsize;
		block12[i].leftT.y = block12[i].pos.y - block12[i].halfsize;
		//左下																 
		block12[i].leftB.x = block12[i].pos.x - block12[i].halfsize;
		block12[i].leftB.y = block12[i].pos.y + block12[i].halfsize;

		//右上																 
		block12[i].rightT.x = block12[i].pos.x + block12[i].halfsize;
		block12[i].rightT.y = block12[i].pos.y - block12[i].halfsize;

		//右下																 
		block12[i].rightB.x = block12[i].pos.x + block12[i].halfsize;
		block12[i].rightB.y = block12[i].pos.y + block12[i].halfsize;


	}


	Block13 block13[kBlockQuantify4];
	for (int i = 0; i < kBlockQuantify4; i++) {



		block13[i].halfsize = 32;

		block13[i].pos.x = float(32 * i) + 1120;

		block13[i].pos.y = 112;


		//左上
		block13[i].leftT.x = block13[i].pos.x - block13[i].halfsize;
		block13[i].leftT.y = block13[i].pos.y - block13[i].halfsize;
		//左下																 
		block13[i].leftB.x = block13[i].pos.x - block13[i].halfsize;
		block13[i].leftB.y = block13[i].pos.y + block13[i].halfsize;

		//右上																 
		block13[i].rightT.x = block13[i].pos.x + block13[i].halfsize;
		block13[i].rightT.y = block13[i].pos.y - block13[i].halfsize;

		//右下																 
		block13[i].rightB.x = block13[i].pos.x + block13[i].halfsize;
		block13[i].rightB.y = block13[i].pos.y + block13[i].halfsize;


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


		/////////////////////////////////////////block/////////////////////////////////////////////

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

		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block2/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify2; i++) {
			if (block2[i].leftT.x < player.rightBottom.x && player.leftTop.x < block2[i].rightB.x) {
				if (player.centerPosition.y > block2[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block2[i].leftB.y) {
						player.centerPosition.y = block2[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		////床の当たり判定(下の辺)
		//for (int i = 0; i < kBlockQuantify2; i++) {

		//	//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
		//	if (block2[i].leftT.x < player.rightBottom.x && player.leftTop.x < block2[i].rightB.x) {

		//		//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
		//		if (player.leftTop.y < block2[i].leftB.y && block2[i].rightT.y < player.leftTop.y) {

		//			player.centerPosition.y = block2[i].leftB.y + player.halfHeight;

		//			player.velocity.y = 0;
		//		}
		//	}
		//}

		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block3/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify3; i++) {
			if (block3[i].leftT.x < player.rightBottom.x && player.leftTop.x < block3[i].rightB.x) {
				if (player.centerPosition.y > block3[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block3[i].leftB.y) {
						player.centerPosition.y = block3[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify3; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block3[i].leftT.x < player.rightBottom.x && player.leftTop.x < block3[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block3[i].leftB.y && block3[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block3[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block4/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify3; i++) {
			if (block4[i].leftT.x < player.rightBottom.x && player.leftTop.x < block4[i].rightB.x) {
				if (player.centerPosition.y > block4[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block4[i].leftB.y) {
						player.centerPosition.y = block4[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify3; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block4[i].leftT.x < player.rightBottom.x && player.leftTop.x < block4[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block4[i].leftB.y && block4[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block4[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block5/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify4; i++) {
			if (block5[i].leftT.x < player.rightBottom.x && player.leftTop.x < block5[i].rightB.x) {
				if (player.centerPosition.y > block5[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block5[i].leftB.y) {
						player.centerPosition.y = block5[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}

		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify4; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block5[i].leftT.x < player.rightBottom.x && player.leftTop.x < block5[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block5[i].leftB.y && block5[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block5[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////



		 /////////////////////////////////////////block6/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify2; i++) {
			if (block6[i].leftT.x < player.rightBottom.x && player.leftTop.x < block6[i].rightB.x) {
				if (player.centerPosition.y > block6[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block6[i].leftB.y) {
						player.centerPosition.y = block6[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify2; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block6[i].leftT.x < player.rightBottom.x && player.leftTop.x < block6[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block6[i].leftB.y && block6[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block6[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block7/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify5; i++) {
			if (block7[i].leftT.x < player.rightBottom.x && player.leftTop.x < block7[i].rightB.x) {
				if (player.centerPosition.y > block7[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block7[i].leftB.y) {
						player.centerPosition.y = block7[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}

		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify5; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block7[i].leftT.x < player.rightBottom.x && player.leftTop.x < block7[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block7[i].leftB.y && block7[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block7[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}


		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block8/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify6; i++) {
			if (block8[i].leftT.x < player.rightBottom.x && player.leftTop.x < block8[i].rightB.x) {
				if (player.centerPosition.y > block8[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block8[i].leftB.y) {
						player.centerPosition.y = block8[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify6; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block8[i].leftT.x < player.rightBottom.x && player.leftTop.x < block8[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block8[i].leftB.y && block8[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block8[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block9/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify5; i++) {
			if (block9[i].leftT.x < player.rightBottom.x && player.leftTop.x < block9[i].rightB.x) {
				if (player.centerPosition.y > block9[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block9[i].leftB.y) {
						player.centerPosition.y = block9[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify5; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block9[i].leftT.x < player.rightBottom.x && player.leftTop.x < block9[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block9[i].leftB.y && block9[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block9[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block10/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify5; i++) {
			if (block10[i].leftT.x < player.rightBottom.x && player.leftTop.x < block10[i].rightB.x) {
				if (player.centerPosition.y > block10[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block10[i].leftB.y) {
						player.centerPosition.y = block10[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify5; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block10[i].leftT.x < player.rightBottom.x && player.leftTop.x < block10[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block10[i].leftB.y && block10[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block10[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block11/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify6; i++) {
			if (block11[i].leftT.x < player.rightBottom.x && player.leftTop.x < block11[i].rightB.x) {
				if (player.centerPosition.y > block11[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block11[i].leftB.y) {
						player.centerPosition.y = block11[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify6; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block11[i].leftT.x < player.rightBottom.x && player.leftTop.x < block11[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block11[i].leftB.y && block11[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block11[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block12/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify6; i++) {
			if (block12[i].leftT.x < player.rightBottom.x && player.leftTop.x < block12[i].rightB.x) {
				if (player.centerPosition.y > block12[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block12[i].leftB.y) {
						player.centerPosition.y = block12[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify6; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block12[i].leftT.x < player.rightBottom.x && player.leftTop.x < block12[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block12[i].leftB.y && block12[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block12[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		/////////////////////////////////////////////////////////////////////////////////////////////



		/////////////////////////////////////////block13/////////////////////////////////////////////

		for (int i = 0; i < kBlockQuantify4; i++) {
			if (block13[i].leftT.x < player.rightBottom.x && player.leftTop.x < block13[i].rightB.x) {
				if (player.centerPosition.y > block13[i].leftT.y - player.halfHeight) {
					if (player.centerPosition.y + player.halfHeight < block13[i].leftB.y) {
						player.centerPosition.y = block13[i].leftT.y - player.halfHeight;
						player.velocity.x = 0;
						player.velocity.y = 0;
					}

				}
			}
		}


		//床の当たり判定(下の辺)
		for (int i = 0; i < kBlockQuantify4; i++) {

			//ブロックの左上Xがプレイヤの右下Xより小さい&&プレイヤの左下Xがブロックの右下Xより小さい
			if (block13[i].leftT.x < player.rightBottom.x && player.leftTop.x < block13[i].rightB.x) {

				//プレイヤの左上Yがブロックの左下Yより小さい&&ブロックの右上Yがプレイヤの左上Yより小さい
				if (player.leftTop.y < block13[i].leftB.y && block13[i].rightT.y < player.leftTop.y) {

					player.centerPosition.y = block13[i].leftB.y + player.halfHeight;

					player.velocity.y = 0;
				}
			}
		}

		////////////////////////////////////////////////////////////////////////////////////////////


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

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify2; i++) {
			Novice::DrawQuad
			(
				int(block2[i].leftT.x),
				int(block2[i].leftT.y),

				int(block2[i].rightT.x),
				int(block2[i].rightT.y),

				int(block2[i].leftB.x),
				int(block2[i].leftB.y),

				int(block2[i].rightB.x),
				int(block2[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify3; i++) {
			Novice::DrawQuad
			(
				int(block3[i].leftT.x),
				int(block3[i].leftT.y),

				int(block3[i].rightT.x),
				int(block3[i].rightT.y),

				int(block3[i].leftB.x),
				int(block3[i].leftB.y),

				int(block3[i].rightB.x),
				int(block3[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}


		for (int i = 0; i < kBlockQuantify3; i++) {
			Novice::DrawQuad
			(
				int(block4[i].leftT.x),
				int(block4[i].leftT.y),

				int(block4[i].rightT.x),
				int(block4[i].rightT.y),

				int(block4[i].leftB.x),
				int(block4[i].leftB.y),

				int(block4[i].rightB.x),
				int(block4[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify4; i++) {
			Novice::DrawQuad
			(
				int(block5[i].leftT.x),
				int(block5[i].leftT.y),

				int(block5[i].rightT.x),
				int(block5[i].rightT.y),

				int(block5[i].leftB.x),
				int(block5[i].leftB.y),

				int(block5[i].rightB.x),
				int(block5[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}


		for (int i = 0; i < kBlockQuantify2; i++) {
			Novice::DrawQuad
			(
				int(block6[i].leftT.x),
				int(block6[i].leftT.y),

				int(block6[i].rightT.x),
				int(block6[i].rightT.y),

				int(block6[i].leftB.x),
				int(block6[i].leftB.y),

				int(block6[i].rightB.x),
				int(block6[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}


		for (int i = 0; i < kBlockQuantify5; i++) {
			Novice::DrawQuad
			(
				int(block7[i].leftT.x),
				int(block7[i].leftT.y),

				int(block7[i].rightT.x),
				int(block7[i].rightT.y),

				int(block7[i].leftB.x),
				int(block7[i].leftB.y),

				int(block7[i].rightB.x),
				int(block7[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}


		for (int i = 0; i < kBlockQuantify6; i++) {
			Novice::DrawQuad
			(
				int(block8[i].leftT.x),
				int(block8[i].leftT.y),

				int(block8[i].rightT.x),
				int(block8[i].rightT.y),

				int(block8[i].leftB.x),
				int(block8[i].leftB.y),

				int(block8[i].rightB.x),
				int(block8[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify5; i++) {
			Novice::DrawQuad
			(
				int(block9[i].leftT.x),
				int(block9[i].leftT.y),

				int(block9[i].rightT.x),
				int(block9[i].rightT.y),

				int(block9[i].leftB.x),
				int(block9[i].leftB.y),

				int(block9[i].rightB.x),
				int(block9[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify5; i++) {
			Novice::DrawQuad
			(
				int(block10[i].leftT.x),
				int(block10[i].leftT.y),

				int(block10[i].rightT.x),
				int(block10[i].rightT.y),

				int(block10[i].leftB.x),
				int(block10[i].leftB.y),

				int(block10[i].rightB.x),
				int(block10[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify6; i++) {
			Novice::DrawQuad
			(
				int(block11[i].leftT.x),
				int(block11[i].leftT.y),

				int(block11[i].rightT.x),
				int(block11[i].rightT.y),

				int(block11[i].leftB.x),
				int(block11[i].leftB.y),

				int(block11[i].rightB.x),
				int(block11[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}

		for (int i = 0; i < kBlockQuantify6; i++) {
			Novice::DrawQuad
			(
				int(block12[i].leftT.x),
				int(block12[i].leftT.y),

				int(block12[i].rightT.x),
				int(block12[i].rightT.y),

				int(block12[i].leftB.x),
				int(block12[i].leftB.y),

				int(block12[i].rightB.x),
				int(block12[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


			);

		}


		for (int i = 0; i < kBlockQuantify4; i++) {
			Novice::DrawQuad
			(
				int(block13[i].leftT.x),
				int(block13[i].leftT.y),

				int(block13[i].rightT.x),
				int(block13[i].rightT.y),

				int(block13[i].leftB.x),
				int(block13[i].leftB.y),

				int(block13[i].rightB.x),
				int(block13[i].rightB.y),

				0, 0, 32, 32, playerTx, BLACK


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
