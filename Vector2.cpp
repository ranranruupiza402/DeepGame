#include "Vector2.h"
#include <cmath>

//コンストラクタ
Vector2::Vector2()
	:x(0), y(0)
{
}

Vector2::Vector2(float X, float Y)
	: x(X), y(Y)
{
}

//長さ
float Vector2::length() const
{
	return std::sqrtf(x	* x + y * y);
}

//正規化
Vector2 & Vector2::normalize()
{
	float L = length();
	if (L == 0) {
		return *this;
	}
	return *this /= L;
}

//内積
float Vector2::dot(const Vector2 & v) const
{
	return x * v.x + y * v.y;
}

//単項演算子+
Vector2 Vector2::operator+() const
{
	return *this;
}

//単項演算子-
Vector2 Vector2::operator-() const
{
	return { -x,-y };
}

//代入演算子+
Vector2 & Vector2::operator+=(const Vector2 & v)
{
	// TODO: return ステートメントをここに挿入します
	x += v.x;
	y += v.y;
	return *this;
}

//代入演算子-
Vector2 & Vector2::operator-=(const Vector2 & v)
{
	// TODO: return ステートメントをここに挿入します
	x -= v.x;
	y -= v.y;
	return *this;
}

//スカラー倍
Vector2 & Vector2::operator*=(float s)
{
	// TODO: return ステートメントをここに挿入します
	x *= s;
	y *= s;
	return *this;
}

//スカラー除算
Vector2 & Vector2::operator/=(float s)
{
	if (s == 0) {
		return *this;
	}
	// TODO: return ステートメントをここに挿入します
	x /= s;
	y /= s;
	return *this;
}

const Vector2 operator+(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x + v2.x, v1.y + v2.y);
}

const Vector2 operator-(const Vector2 & v1, const Vector2 & v2)
{
	return Vector2(v1.x - v2.x, v1.y - v2.y);
}

const Vector2 operator*(const Vector2 & v, float s)
{
	return Vector2(v.x*s, v.y*s);
}

const Vector2 operator*(float s, const Vector2 & v)
{
	return Vector2(v.x*s, v.y*s);
}

const Vector2 operator/(const Vector2 & v, float s)
{
	//sが0だと割ったとき永遠の0になるので条件追加
	if (s == 0) {
		return v;
	}
	return Vector2(v.x / s, v.y / s);
}
