# Season2020: Firmware

## 概要
Season2020 ロボットの制御プログラム。
開発には **PlatformIO mbed** および一部ツール作成に **Arduino IDE** を使用。

## プロジェクト一覧

### 1. Season2020 (Main Project)
**概要:** 大会本番で使用した統合プログラム
移動機構（足回り）とアーム機構の制御を統合した最終版。

**主要ファイル構成:**
* **`src/ArmUnit.cpp`, `include/ArmUnit.h`**
    * アーム機構のメイン制御プログラム。
    * ダイレクトティーチング機能の実装に加え、本番動作で使用する教示済みの位置データ（座標配列）が定義されている。
* **`src/ArmPitchUnit.cpp`, `include/ArmPitchUnit.h`**
    * 肩のピッチ軸回転機構を制御するプログラム。
    * アーム同様、本番用の動作データを含む。
* **`src/Dynamixel.cpp`, `include/Dynamixel.h`**
    * *下記 `Dynamixel_Trial` で開発したドライバを使用。*
* **`src/LineTrace.cpp`, `include/LineTrace.h`**
    * ライントレース制御プログラム（チームメンバー担当）。

---

### 2. Dynamixel_Trial
**概要:** 自作Dynamixelドライバ開発と検証用プロジェクト
**開発環境:** PlatformIO / mbed

**開発背景:**
開発当時、mbed用の既存Dynamixelライブラリが動作しなかったため、Arduino用のライブラリを参考にしつつ、**mbed環境向けにC++でドライバを自作（移植・再設計）** した。移動機構と統合する前の単体テストおよび、ダイレクトティーチング機能の初期実装はここで行った。

**主要ファイル構成:**
* **`src/Dynamixel.cpp`, `include/Dynamixel.h`**
    * **自作ドライバ:** Dynamixel AX-12Aの通信プロトコル（データの生成と受信）を実装。コマンド送信や位置データ等の取得を行う。
* **`src/ArmUnit.cpp`**
    * ダイレクトティーチングのロジック実装（初期バージョン）。
    * 現在のボリューム値を読み取り、配列に保存する処理などが含まれている。
* **`src/ArmPitchUnit.cpp`**
    * ダイレクトティーチング時の「アシスト機能」を実装。手で動かす際に補助を加えている。

---

### 3. Arduino IDEで開発したモノ
サーボモータの初期設定や簡易動作確認のために作成した単機能ツール。

* **Dynamixel_ChangeBaudrate**
    * Dynamixelのボーレートを変更・設定するためのツール。
* **Dynamixel_MoveTrial**
    * 新しいモータを接続した際に、正常に動くかを確認するための簡易テストプログラム。

---
[プロジェクトトップに戻る](../README.md)
