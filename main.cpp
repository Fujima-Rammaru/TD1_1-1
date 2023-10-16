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
		Vector2 vertexPosition[4];//矩形の4頂点の座標

		Vector2 velocity;//移動速度

		Vector2 acceleration;//加速度

		int texture;//画像読み込み用変数
	};

	int playerTx = Novice::LoadTexture("./resources/DRAGON2.png");

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

		playerTx,

	};


	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);



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

		player.vertexPosition[0].x = player.centerPosition.x - player.halfWidth;//左上X座標
		player.vertexPosition[0].y = player.centerPosition.y - player.halfHeight;//左上Y座標
		player.vertexPosition[1].x = player.centerPosition.x + player.halfWidth;//右上X座標
		player.vertexPosition[1].y = player.centerPosition.y - player.halfHeight;//右上Y座標
		player.vertexPosition[2].x = player.centerPosition.x - player.halfWidth;//左下X座標
		player.vertexPosition[2].y = player.centerPosition.y + player.halfHeight;//左下Y座標
		player.vertexPosition[3].x = player.centerPosition.x + player.halfWidth;//右下X座標
		player.vertexPosition[3].y = player.centerPosition.y + player.halfHeight;//右下Y座標

		player.velocity.y += player.acceleration.y;

		player.centerPosition.y -= player.velocity.y;

		if (keys[DIK_SPACE] != 0 && player.centerPosition.y == kWindowHeight - player.halfHeight) {
			player.acceleration.y = -0.8f;

			player.velocity.y = 17.0f;

		}

		if (player.centerPosition.y > kWindowHeight - player.halfHeight) {

			player.centerPosition.y = float(kWindowHeight - player.halfHeight);

			player.velocity.y = 0;

			player.acceleration.y = 0;


		}










		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Novice::DrawQuad(
			int(player.vertexPosition[0].x),
			int(player.vertexPosition[0].y),
			int(player.vertexPosition[1].x),
			int(player.vertexPosition[1].y),
			int(player.vertexPosition[2].x),
			int(player.vertexPosition[2].y),
			int(player.vertexPosition[3].x),
			int(player.vertexPosition[3].y),
			0, 0, 64, 64, playerTx, WHITE
		);
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
