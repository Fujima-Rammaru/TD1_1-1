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

	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

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

	int animationspeed = 3;

	//壁の初期座標
	int wallPosX = -kWindowWidth;

	int TITLETexture = Novice::LoadTexture("./Resources/HOPPER Title.png");

	int PLAYTexture = Novice::LoadTexture("./Resources/haikei.png");

	int RESULTTexture = Novice::LoadTexture("./Resources/HOPPER CREAR.png");

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

					wallPosX = -kWindowWidth;

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

		Novice::ScreenPrintf(0, 0, "SCENE_NUMBER=%d", sceneNumber);


		switch (sceneNumber) {

		case GAME_TITLE:
			Novice::DrawSprite(0, 0, TITLETexture, 1, 1, 0.0f, WHITE);
			break;

		case GAME_PLAY:

			Novice::DrawSprite(0, 0, PLAYTexture, 1, 1, 0.0f, WHITE);

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
