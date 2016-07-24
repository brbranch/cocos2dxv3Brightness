# cocos2dxv3Brightness
cocos2d-xのv3でスプライトの輝度を変えるサンプル

shader/shaderactions内に以下のクラスがあります。

ChangeColorBy.hpp
ChangeColorBy.cpp

これらを使うことでスプライトの輝度と明度を変更できます。

## 説明
ChangeColorBy::create(【色タイプ】, 【色指定】, 【元に戻すかどうか】, 【アニメーション時間】);
* 色タイプ：ChangeColorType::RGBまたはChangeColorType::HSVを選択
* 色指定：Vec3(R,G,B) or Vec3(H,S,V) ※いずれも-1.0〜1.0の範囲で指定
* 元に戻すかどうか：trueの場合、アニメーション終了時に元の色に戻っていきます
* アニメーション時間：秒指定

## 使い方
以下のように使います。

```
auto sprite = Sprite::create("...");
sprite->runAction(ChangeColorBy::create(ChangeColorType::HSV , Vec3(0.0, -1.0 , 1.0), true , 1.0 ));
```
