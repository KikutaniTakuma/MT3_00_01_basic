#include <Novice.h>
#include "Vector3D/Vector3D.h"

const char kWindowTitle[] = "LE2A_04_キクタニ_タクマ_MT3_00_01";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	const int kRowHeight = 20;

	Vector3D v1(1.0f, 3.0f, -5.0f);
	Vector3D v2(4.0f, -1.0f, 2.0f);
	float k = 4.0f;

	Vector3D resultAdd = v1 + v2;
	Vector3D resultSubtract = v1 - v2;
	Vector3D resultMultiply = v1 * k;
	float resultDot = v1.Dot(v2);
	float resultLength = v1.Length();
	Vector3D resultNormalize = v2.Normalize();

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		Vec3ScreenPrintf(0, 0, resultAdd, " : Add");
		Vec3ScreenPrintf(0, kRowHeight, resultSubtract, " : Subtract");
		Vec3ScreenPrintf(0, kRowHeight * 2, resultMultiply, " : Multiply");
		Novice::ScreenPrintf(0, kRowHeight * 3, "%0.02f : Dot", resultDot);
		Novice::ScreenPrintf(0, kRowHeight * 4, "%0.02f : Length", resultLength);
		Vec3ScreenPrintf(0, kRowHeight * 5, resultNormalize, " : Normalize");


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
