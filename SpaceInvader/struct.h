#pragma once

struct Vec2
{
public:
	float x;
	float y;

public:
	Vec2()	:
		x(0.f),
		y(0.f)
	{
	}
	Vec2(float _x, float _y) :
		x(_x),
		y(_y)
	{
	}
	Vec2(long _x, long _y) :
		x((float)_x),
		y((float)_y)
	{
	}
	~Vec2()
	{
	}

public:
	Vec2 operator + (Vec2 _Other)
	{
		return Vec2(x + _Other.x, y + _Other.y);
	}

	void operator += (Vec2 _Other)
	{
		x += _Other.x;
		y += _Other.y;
	}

	Vec2 operator + (float _f)
	{
		return Vec2(x + _f, y + _f);
	}

	void operator += (float _f)
	{
		x += _f;
		y += _f;
	}

	Vec2 operator - (Vec2 _Other)
	{
		return Vec2(x - _Other.x, y - _Other.y);
	}

	void operator -= (Vec2 _Other)
	{
		x -= _Other.x;
		y -= _Other.y;
	}

	Vec2 operator - (float _f)
	{
		return Vec2((x - _f), (y - _f));
	}

	void operator -= (float _f)
	{
		x -= _f;
		y -= _f;
	}

	Vec2 operator / (Vec2 _Other)
	{
		return Vec2(x / _Other.x, y / _Other.y);
	}

	void operator /= (Vec2 _Other)
	{
		x /= _Other.x;
		y /= _Other.y;
	}

	Vec2 operator / (float _f)
	{
		return Vec2(x / _f, y / _f);
	}

	void operator /= (float _f)
	{
		x /= _f;
		y /= _f;
	}

	Vec2 operator * (Vec2 _Other)
	{
		return Vec2(x * _Other.x, y * _Other.y);
	}

	Vec2 operator * (float _f)
	{
		return Vec2(x * _f, y * _f);
	}

public:
	void Normalize()	// 벡터의 정규화
	{
		float fDist = sqrt(x * x + y * y);
		x /= fDist;
		y /= fDist;
	}
};

struct tEvent
{
	EEVENT_TYPE eType;
	DWORD_PTR wParam;
	DWORD_PTR lParam;
};