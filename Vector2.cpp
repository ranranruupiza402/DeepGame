#include "Vector2.h"
#include <cmath>

//�R���X�g���N�^
Vector2::Vector2()
	:x(0), y(0)
{
}

Vector2::Vector2(float X, float Y)
	: x(X), y(Y)
{
}

//����
float Vector2::length() const
{
	return std::sqrtf(x	* x + y * y);
}

//���K��
Vector2 & Vector2::normalize()
{
	float L = length();
	if (L == 0) {
		return *this;
	}
	return *this /= L;
}

//����
float Vector2::dot(const Vector2 & v) const
{
	return x * v.x + y * v.y;
}

//�P�����Z�q+
Vector2 Vector2::operator+() const
{
	return *this;
}

//�P�����Z�q-
Vector2 Vector2::operator-() const
{
	return { -x,-y };
}

//������Z�q+
Vector2 & Vector2::operator+=(const Vector2 & v)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	x += v.x;
	y += v.y;
	return *this;
}

//������Z�q-
Vector2 & Vector2::operator-=(const Vector2 & v)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	x -= v.x;
	y -= v.y;
	return *this;
}

//�X�J���[�{
Vector2 & Vector2::operator*=(float s)
{
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
	x *= s;
	y *= s;
	return *this;
}

//�X�J���[���Z
Vector2 & Vector2::operator/=(float s)
{
	if (s == 0) {
		return *this;
	}
	// TODO: return �X�e�[�g�����g�������ɑ}�����܂�
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
	//s��0���Ɗ������Ƃ��i����0�ɂȂ�̂ŏ����ǉ�
	if (s == 0) {
		return v;
	}
	return Vector2(v.x / s, v.y / s);
}
