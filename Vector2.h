#pragma once
struct Vector2
{
	float x;
	float y;
	//コンストラクタ
	Vector2();
	Vector2(float X, float Y);

	//メンバ関数
	float length() const;//ノルム
	Vector2& normalize();//正規化
	float dot(const Vector2& v)const;//内積

	//単項演算子オーバーロード
	Vector2 operator + ()const;
	Vector2 operator - ()const;

	//代入演算子オーバーロード
	Vector2& operator +=(const Vector2&v);
	Vector2& operator -=(const Vector2&v);
	Vector2& operator *=(float s);
	Vector2& operator /=(float s);
};
//2項演算子オーバーロード
const Vector2 operator +(const Vector2& v1, const Vector2& v2);
const Vector2 operator -(const Vector2& v1, const Vector2& v2);
const Vector2 operator *(const Vector2& v, float s);
const Vector2 operator *(float s, const Vector2& v);
const Vector2 operator /(const Vector2& v, float s);

