#include <Novice.h>

const char kWindowTitle[] = "GC1C_13_フジマ_ランマル_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	enum SCENE {
		GAME_TITLE,//0
		GAME_PLAY,//
		GAME_CLEAR,//2
		GAME_OVER,//3

	};

	int sceneNumber = 0;

	//スタート画面のエンターを押したときのSE読み込み
	int pressEnterAudio = Novice::LoadAudio("./Resources/Sound/Enter_sounds.wav");

	int pressEnterAudioHandle = -1;

	int pressEnterTimer = 0;

	//エンターが押されたかどうか
	bool isPressEnter = false;

	//スタート画面のBGM読み込み
	int gameStartAudio = Novice::LoadAudio("./Resources/Sound/Game_start_BGM.wav");

	int playHandle_gameStart = -1;

	int playHandle_gameOver = -1;

	int playHandle_gameResult = -1;

	//ゲームオーバー画面のBGM読み込み
	int gameOverAudio = Novice::LoadAudio("./Resources/Sound/gameover.wav");

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
			if (Novice::IsPlayingAudio(playHandle_gameStart) == 0 && pressEnterTimer == 0) {
				playHandle_gameStart = Novice::PlayAudio(gameStartAudio, true, 1.0f);
			}

			//エンターを押したとき効果音が流れる（BGMの再生を停止してから）、
			if (keys[DIK_RETURN] && !preKeys[DIK_RETURN]) {
				if (Novice::IsPlayingAudio(pressEnterAudioHandle) == 0) {

					Novice::StopAudio(playHandle_gameStart);



					pressEnterAudioHandle = Novice::PlayAudio(pressEnterAudio, false, 0.5f);
				}
				isPressEnter = true;

			}

			//エンターを押したとき秒数カウント用変数が始動する
			if (isPressEnter) {
				pressEnterTimer++;
			}

			//1秒後に次のシーンに切り替わる
			if (pressEnterTimer == 60) {
				sceneNumber = 1;
				pressEnterTimer = 0;
				isPressEnter = false;
			}
			break;

		case GAME_PLAY:




			break;

		case GAME_CLEAR:




			break;

		case GAME_OVER:




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

			break;

		case GAME_PLAY:

			break;

		case GAME_CLEAR:

			break;

		case GAME_OVER:

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
