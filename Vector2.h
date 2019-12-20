#pragma once
struct Vector2
{
	float x;
	float y;
	//�R���X�g���N�^
	Vector2();
	Vector2(float X, float Y);

	//�����o�֐�
	float length() const;//�m����
	Vector2& normalize();//���K��
	float dot(const Vector2& v)const;//����

	//�P�����Z�q�I�[�o�[���[�h
	Vector2 operator + ()const;
	Vector2 operator - ()const;

	//������Z�q�I�[�o�[���[�h
	Vector2& operator +=(const Vector2&v);
	Vector2& operator -=(const Vector2&v);
	Vector2& operator *=(float s);
	Vector2& operator /=(float s);
};
//2�����Z�q�I�[�o�[���[�h
const Vector2 operator +(const Vector2& v1, const Vector2& v2);
const Vector2 operator -(const Vector2& v1, const Vector2& v2);
const Vector2 operator *(const Vector2& v, float s);
const Vector2 operator *(float s, const Vector2& v);
const Vector2 operator /(const Vector2& v, float s);

