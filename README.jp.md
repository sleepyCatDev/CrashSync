# CrashSync
Another sound mangler

プラグインをテストしてくれてありがとうございますが　ほ　ん　と　に　気をつてください！このソフトは全然完了じゃないから耳（またはスピーカー）を守るためにマスター、プラグインのトラックとかにLimiterを追加して、オートミュートとか使ってください。

// ---------------------------
// 名前は?
// ---------------------------

しんごを歪回路でスマッシュしてオシレーターをシンクするから「クラッシュシンク」っていいけど実は回路を作った人から名前を盗んだ。いつかかえる

// ---------------------------
// 何をする?
// ---------------------------

John Hollisの回路 http://www.hollis.co.uk/john/circuits.html のベースでこのプラグインを作った。何を入力してもスクエアになるとオシレーターをその歪んだしんごでリセットする。単純にロボットの悲鳴みたいです。オシレーターの周波数はピークを作って、動いたらフランジャー的な音が出る。

// ---------------------------
// パラメーターは？
// ---------------------------

このパラメーターのすべては変わるけど 0.1として

Osc Freq: オシレーターの周波数を変える。最低、最高はたまに役に立たない。動いたらflanger/phaser的な音が出る

Threshold: このレベル以下に減ったらオシレーターはリセットする。入力は小さいか、なしか、音は出ない　

Gain: 音量を歪前に調整する。もし音はパッパッ出ているけどThresholdを下げたくないならこれをあげる　

Waveform: オシレーターの波形 (Triangle, Saw, Rounded Saw, Square, Wiggly Square, Sloped Square, Noise, Filtered Noise)

Input Mode: 歪あとのEnvelope followerをオン（１）オフ（０）になれる

Env Attack: Envelope followerのアタックタイム

Env Release: Envelope followerのリリースタイム

Output Lvl: ギターペダルのボリューム摘みみたいです

Tone: 高い倍音をさげる

Oversample: Aliasingを減らすために処理はsamplerate x 4で行動する。

Input Filter: 入力にあるResonant LPFのカットオフを変える。低いの方で音色はちょっとスムーズになる、高いの方はぎゃくです

Mix: 入力と処理した音をミクスする

