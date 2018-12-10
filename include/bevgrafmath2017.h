#ifndef H___BEVGRAFMATH2017
#define H___BEVGRAFMATH2017

#include <stdint.h>
#include <math.h>
#include <assert.h>
#include <stdio.h>

///////////////////////////////////////////////////////////////////////////////
// Konstansok formazashoz
///////////////////////////////////////////////////////////////////////////////
#define __BGM_FORMAT_B "%5s"
#define __BGM_FORMAT_I "%9d"
#define __BGM_FORMAT_F "%9.14f"

///////////////////////////////////////////////////////////////////////////////
// 2D vektor
///////////////////////////////////////////////////////////////////////////////
struct vec2
{
	float x, y;

	vec2(float xy = 0.0f) :
		x(xy),
		y(xy)
	{}

	vec2(float xv, float yv) :
		x(xv),
		y(yv)
	{}

	const float& operator[](size_t ind) const
	{
		assert(ind >= 0 && ind <= 1);
		return (&x)[ind];
	}

	float& operator[](size_t ind)
	{
		assert(ind >= 0 && ind <= 1);
		return (&x)[ind];
	}
};

inline vec2 operator-(vec2 v)
{
	return vec2
	{
		-v[0],
		-v[1]
	};
}

inline bool operator==(vec2 v1, vec2 v2)
{
	return v1[0] == v2[0] && v1[1] == v2[1];
}

inline bool operator!=(vec2 v1, vec2 v2)
{
	return !(v1 == v2);
}

inline vec2 operator+(vec2 v1, vec2 v2)
{
	return vec2
	{
		v1[0] + v2[0],
		v1[1] + v2[1]
	};
}

inline vec2 operator-(vec2 v1, vec2 v2)
{
	return vec2
	{
		v1[0] - v2[0],
		v1[1] - v2[1]
	};
}

inline vec2& operator+=(vec2& v1, vec2 v2)
{
	v1 = v1 + v2;
	return v1;
}

inline vec2& operator-=(vec2& v1, vec2 v2)
{
	v1 = v1 - v2;
	return v1;
}

inline vec2 operator+(vec2 v, float f)
{
	return vec2
	{
		v[0] + f,
		v[1] + f
	};
}

inline vec2 operator-(vec2 v, float f)
{
	return vec2
	{
		v[0] - f,
		v[1] - f
	};
}

inline vec2 operator*(vec2 v, float f)
{
	return vec2
	{
		v[0] * f,
		v[1] * f
	};
}

inline vec2 operator/(vec2 v, float f)
{
	return vec2
	{
		v[0] / f,
		v[1] / f
	};
}

inline vec2 operator+(float f, vec2 v)
{
	return vec2
	{
		f + v[0],
		f + v[1]
	};
}

inline vec2 operator-(float f, vec2 v)
{
	return vec2
	{
		f - v[0],
		f - v[1]
	};
}

inline vec2 operator*(float f, vec2 v)
{
	return vec2
	{
		f * v[0],
		f * v[1]
	};
}

inline vec2 operator/(float f, vec2 v)
{
	return vec2
	{
		f / v[0],
		f / v[1]
	};
}

inline vec2& operator+=(vec2& v, float f)
{
	v = v + f;
	return v;
}

inline vec2& operator-=(vec2& v, float f)
{
	v = v - f;
	return v;
}

inline vec2& operator*=(vec2& v, float f)
{
	v = v * f;
	return v;
}

inline vec2& operator/=(vec2& v, float f)
{
	v = v / f;
	return v;
}


///////////////////////////////////////////////////////////////////////////////
// 3D vektor
///////////////////////////////////////////////////////////////////////////////
struct vec3
{
	float x, y, z;

	vec3(float xyz = 0.0f) :
		x(xyz),
		y(xyz),
		z(xyz)
	{}

	vec3(float xv, float yv, float zv = 0.0f) :
		x(xv),
		y(yv),
		z(zv)
	{}

	vec3(vec2 v, float zv = 0.0f) :
		x(v[0]),
		y(v[1]),
		z(zv)
	{}

	const float& operator[](size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return (&x)[ind];
	}

	float& operator[](size_t ind)
	{
		assert(ind >= 0 && ind <= 2);
		return (&x)[ind];
	}
};

inline vec3 operator-(vec3 v)
{
	return vec3
	{
		-v[0],
		-v[1],
		-v[2]
	};
}

inline bool operator==(vec3 v1, vec3 v2)
{
	return v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2];
}

inline bool operator!=(vec3 v1, vec3 v2)
{
	return !(v1 == v2);
}

inline vec3 operator+(vec3 v1, vec3 v2)
{
	return vec3
	{
		v1[0] + v2[0],
		v1[1] + v2[1],
		v1[2] + v2[2]
	};
}

inline vec3 operator-(vec3 v1, vec3 v2)
{
	return vec3
	{
		v1[0] - v2[0],
		v1[1] - v2[1],
		v1[2] - v2[2]
	};
}

inline vec3& operator+=(vec3& v1, vec3 v2)
{
	v1 = v1 + v2;
	return v1;
}

inline vec3& operator-=(vec3& v1, vec3 v2)
{
	v1 = v1 - v2;
	return v1;
}

inline vec3 operator+(vec3 v, float f)
{
	return vec3
	{
		v[0] + f,
		v[1] + f,
		v[2] + f
	};
}

inline vec3 operator-(vec3 v, float f)
{
	return vec3
	{
		v[0] - f,
		v[1] - f,
		v[2] - f
	};
}

inline vec3 operator*(vec3 v, float f)
{
	return vec3
	{
		v[0] * f,
		v[1] * f,
		v[2] * f
	};
}

inline vec3 operator/(vec3 v, float f)
{
	return vec3
	{
		v[0] / f,
		v[1] / f,
		v[2] / f
	};
}

inline vec3 operator+(float f, vec3 v)
{
	return vec3
	{
		f + v[0],
		f + v[1],
		f + v[2]
	};
}

inline vec3 operator-(float f, vec3 v)
{
	return vec3
	{
		f - v[0],
		f - v[1],
		f - v[2]
	};
}

inline vec3 operator*(float f, vec3 v)
{
	return vec3
	{
		f * v[0],
		f * v[1],
		f * v[2]
	};
}

inline vec3 operator/(float f, vec3 v)
{
	return vec3
	{
		f / v[0],
		f / v[1],
		f / v[2]
	};
}

inline vec3& operator+=(vec3& v, float f)
{
	v = v + f;
	return v;
}

inline vec3& operator-=(vec3& v, float f)
{
	v = v - f;
	return v;
}

inline vec3& operator*=(vec3& v, float f)
{
	v = v * f;
	return v;
}

inline vec3& operator/=(vec3& v, float f)
{
	v = v / f;
	return v;
}

///////////////////////////////////////////////////////////////////////////////
// 4D vektor
///////////////////////////////////////////////////////////////////////////////
struct vec4
{
	float x, y, z, w;

	vec4(float xyzw = 0.0f) :
		x(xyzw),
		y(xyzw),
		z(xyzw),
		w(xyzw)
	{}

	vec4(vec2 v, float zv = 0.0f, float wv = 0.0f) :
		x(v[0]),
		y(v[1]),
		z(zv),
		w(wv)
	{}

	vec4(vec3 v, float wv = 0.0f) :
		x(v[0]),
		y(v[1]),
		z(v[2]),
		w(wv)
	{}

	vec4(float xv, float yv, float zv = 0.0f, float wv = 0.0f) :
		x(xv),
		y(yv),
		z(zv),
		w(wv)
	{}

	const float& operator[](size_t ind) const
	{
		assert(ind >= 0 && ind <= 3);
		return (&x)[ind];
	}

	float& operator[](size_t ind)
	{
		assert(ind >= 0 && ind <= 3);
		return (&x)[ind];
	}
};

inline vec4 operator-(vec4 v)
{
	return vec4
	{
		-v[0],
		-v[1],
		-v[2],
		-v[3]
	};
}

inline bool operator==(vec4 v1, vec4 v2)
{
	return v1[0] == v2[0] && v1[1] == v2[1] && v1[2] == v2[2] && v1[3] == v2[3];
}

inline bool operator!=(vec4 v1, vec4 v2)
{
	return !(v1 == v2);
}

inline vec4 operator+(vec4 v1, vec4 v2)
{
	return vec4
	{
		v1[0] + v2[0],
		v1[1] + v2[1],
		v1[2] + v2[2],
		v1[3] + v2[3]
	};
}

inline vec4 operator-(vec4 v1, vec4 v2)
{
	return vec4
	{
		v1[0] - v2[0],
		v1[1] - v2[1],
		v1[2] - v2[2],
		v1[3] - v2[3]
	};
}

inline vec4& operator+=(vec4& v1, vec4 v2)
{
	v1 = v1 + v2;
	return v1;
}

inline vec4& operator-=(vec4& v1, vec4 v2)
{
	v1 = v1 - v2;
	return v1;
}

inline vec4 operator+(vec4 v, float f)
{
	return vec4
	{
		v[0] + f,
		v[1] + f,
		v[2] + f,
		v[3] + f
	};
}

inline vec4 operator-(vec4 v, float f)
{
	return vec4
	{
		v[0] - f,
		v[1] - f,
		v[2] - f,
		v[3] - f
	};
}

inline vec4 operator*(vec4 v, float f)
{
	return vec4
	{
		v[0] * f,
		v[1] * f,
		v[2] * f,
		v[3] * f
	};
}

inline vec4 operator/(vec4 v, float f)
{
	return vec4
	{
		v[0] / f,
		v[1] / f,
		v[2] / f,
		v[3] / f
	};
}

inline vec4 operator+(float f, vec4 v)
{
	return vec4
	{
		f + v[0],
		f + v[1],
		f + v[2],
		f + v[3]
	};
}

inline vec4 operator-(float f, vec4 v)
{
	return vec4
	{
		f - v[0],
		f - v[1],
		f - v[2],
		f - v[3]
	};
}

inline vec4 operator*(float f, vec4 v)
{
	return vec4
	{
		f * v[0],
		f * v[1],
		f * v[2],
		f * v[3]
	};
}

inline vec4 operator/(float f, vec4 v)
{
	return vec4
	{
		f / v[0],
		f / v[1],
		f / v[2],
		f / v[3]
	};
}

inline vec4& operator+=(vec4& v, float f)
{
	v = v + f;
	return v;
}

inline vec4& operator-=(vec4& v, float f)
{
	v = v - f;
	return v;
}

inline vec4& operator*=(vec4& v, float f)
{
	v = v * f;
	return v;
}

inline vec4& operator/=(vec4& v, float f)
{
	v = v / f;
	return v;
}

///////////////////////////////////////////////////////////////////////////////
// Homogen - inhomogen konverziok
///////////////////////////////////////////////////////////////////////////////

inline vec3 ihToH(vec2 v)
{
	return vec3(v.x, v.y, 1);
}

inline vec2 hToIh(vec3 v)
{
	return { v.x / v.z, v.y / v.z };
}

inline vec4 ihToH(vec3 v)
{
	return { v.x, v.y, v.z, 1 };
}


inline vec3 hToIh(vec4 v)
{
	return { v.x / v.w, v.y / v.w, v.z / v.w };
}

///////////////////////////////////////////////////////////////////////////////
// 3x3 matrix
///////////////////////////////////////////////////////////////////////////////
struct mat3
{
	vec3 v[3];

	mat3(float d = 1.0f) :
		v{
			{ d,    0.0f, 0.0f },
	{ 0.0f, d,    0.0f },
	{ 0.0f, 0.0f, d },
	}
	{}

	mat3(float v11, float v12, float v13,
		float v21, float v22, float v23,
		float v31, float v32, float v33) :
		v{
			{ v11, v12, v13 },
	{ v21, v22, v23 },
	{ v31, v32, v33 },
	}
	{}

	mat3(vec3 v1, vec3 v2, vec3 v3, bool columnMajor = false)
	{
		if (columnMajor)
		{
			v[0] = { v1[0], v2[0], v3[0] };
			v[1] = { v1[1], v2[1], v3[1] };
			v[2] = { v1[2], v2[2], v3[2] };
		}
		else
		{
			v[0] = { v1[0], v1[1], v1[2] };
			v[1] = { v2[0], v2[1], v2[2] };
			v[2] = { v3[0], v3[1], v3[2] };
		}
	}

	const vec3& operator[](size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return v[ind];
	}

	vec3& operator[](size_t ind)
	{
		assert(ind >= 0 && ind <= 2);
		return v[ind];
	}

	vec3 col(size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return{ v[0][ind], v[1][ind], v[2][ind] };
	}

	vec3 row(size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return v[ind];
	}
};

inline bool operator==(mat3 m1, mat3 m2)
{
	return m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2];
}

inline bool operator!=(mat3 m1, mat3 m2)
{
	return !(m1 == m2);
}

inline mat3 operator+(mat3 m1, mat3 m2)
{
	return mat3
	{
		m1[0] + m2[0],
		m1[1] + m2[1],
		m1[2] + m2[2]
	};
}

inline mat3 operator-(mat3 m1, mat3 m2)
{
	return mat3
	{
		m1[0] - m2[0],
		m1[1] - m2[1],
		m1[2] - m2[2]
	};
}

inline mat3 operator*(mat3 m1, mat3 m2)
{
	mat3 result;

	for (size_t i = 0; i < 3; ++i)
	{
		for (size_t j = 0; j < 3; ++j)
		{
			result[i][j] =
				m1[i][0] * m2[0][j] +
				m1[i][1] * m2[1][j] +
				m1[i][2] * m2[2][j];
		}
	}

	return result;
}

inline vec3 operator*(mat3 m, vec3 v)
{
	return vec3
	{
		m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2],
		m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2],
		m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2]
	};
}

inline mat3& operator+=(mat3& m1, mat3 m2)
{
	m1 = m1 + m2;
	return m1;
}

inline mat3& operator-=(mat3& m1, mat3 m2)
{
	m1 = m1 - m2;
	return m1;
}

inline mat3& operator*=(mat3& m1, mat3 m2)
{
	m1 = m1 * m2;
	return m1;
}

inline mat3 operator+(mat3 m, float f)
{
	return mat3
	{
		m[0] + f,
		m[1] + f,
		m[2] + f
	};
}

inline mat3 operator-(mat3 m, float f)
{
	return mat3
	{
		m[0] - f,
		m[1] - f,
		m[2] - f
	};
}

inline mat3 operator*(mat3 m, float f)
{
	return mat3
	{
		m[0] * f,
		m[1] * f,
		m[2] * f
	};
}

inline mat3 operator/(mat3 m, float f)
{
	return mat3
	{
		m[0] / f,
		m[1] / f,
		m[2] / f
	};
}

inline mat3 operator+(float f, mat3 m)
{
	return mat3
	{
		f + m[0],
		f + m[1],
		f + m[2]
	};
}

inline mat3 operator-(float f, mat3 m)
{
	return mat3
	{
		f - m[0],
		f - m[1],
		f - m[2]
	};
}

inline mat3 operator*(float f, mat3 m)
{
	return mat3
	{
		f * m[0],
		f * m[1],
		f * m[2]
	};
}

inline mat3 operator/(float f, mat3 m)
{
	return mat3
	{
		f / m[0],
		f / m[1],
		f / m[2]
	};
}

inline mat3& operator+=(mat3& m, float f)
{
	m = m + f;
	return m;
}

inline mat3& operator-=(mat3& m, float f)
{
	m = m - f;
	return m;
}

inline mat3& operator*=(mat3& m, float f)
{
	m = m * f;
	return m;
}

inline mat3& operator/=(mat3& m, float f)
{
	m = m / f;
	return m;
}

///////////////////////////////////////////////////////////////////////////////
// 4x4 matrix
///////////////////////////////////////////////////////////////////////////////
struct mat4
{
	vec4 v[4];

	mat4(float d = 1.0f) :
		v{
			{ d,    0.0f, 0.0f, 0.0f },
	{ 0.0f, d,    0.0f, 0.0f },
	{ 0.0f, 0.0f, d,    0.0f },
	{ 0.0f, 0.0f, 0.0f, d },
	}
	{}

	mat4(float v11, float v12, float v13, float v14,
		float v21, float v22, float v23, float v24,
		float v31, float v32, float v33, float v34,
		float v41, float v42, float v43, float v44) :
		v{
			{ v11, v12, v13, v14 },
	{ v21, v22, v23, v24 },
	{ v31, v32, v33, v34 },
	{ v41, v42, v43, v44 },
	}
	{}

	mat4(vec4 v1, vec4 v2, vec4 v3, vec4 v4, bool columnMajor = false)
	{
		if (columnMajor)
		{
			v[0] = { v1[0], v2[0], v3[0], v4[0] };
			v[1] = { v1[1], v2[1], v3[1], v4[1] };
			v[2] = { v1[2], v2[2], v3[2], v4[2] };
			v[3] = { v1[3], v2[3], v3[3], v4[3] };
		}
		else
		{
			v[0] = { v1[0], v1[1], v1[2], v1[3] };
			v[1] = { v2[0], v2[1], v2[2], v2[3] };
			v[2] = { v3[0], v3[1], v3[2], v3[3] };
			v[3] = { v4[0], v4[1], v4[2], v4[3] };
		}
	}

	mat4(mat3 m) :
		v{
			{ m[0][0], m[0][1], m[0][2], 0.0f },
	{ m[1][0], m[1][1], m[1][2], 0.0f },
	{ m[2][0], m[2][1], m[2][2], 0.0f },
	{ 0.0f,    0.0f,    0.0f,    1.0f },
	}
	{}

	const vec4& operator[](size_t ind) const
	{
		assert(ind >= 0 && ind <= 3);
		return v[ind];
	}

	vec4& operator[](size_t ind)
	{
		assert(ind >= 0 && ind <= 3);
		return v[ind];
	}

	vec4 col(size_t ind) const
	{
		assert(ind >= 0 && ind <= 3);
		return{ v[0][ind], v[1][ind], v[2][ind], v[3][ind] };
	}

	vec4 row(size_t ind) const
	{
		assert(ind >= 0 && ind <= 3);
		return v[ind];
	}
};

inline bool operator==(mat4 m1, mat4 m2)
{
	return m1[0] == m2[0] && m1[1] == m2[1] && m1[2] == m2[2] && m1[3] == m2[3];
}

inline bool operator!=(mat4 m1, mat4 m2)
{
	return !(m1 == m2);
}

inline mat4 operator+(mat4 m1, mat4 m2)
{
	return mat4
	{
		m1[0] + m2[0],
		m1[1] + m2[1],
		m1[2] + m2[2],
		m1[3] + m2[3]
	};
}

inline mat4 operator-(mat4 m1, mat4 m2)
{
	return mat4
	{
		m1[0] - m2[0],
		m1[1] - m2[1],
		m1[2] - m2[2],
		m1[3] - m2[3]
	};
}

inline mat4 operator*(mat4 m1, mat4 m2)
{
	mat4 result;

	for (size_t i = 0; i < 4; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			result[i][j] =
				m1[i][0] * m2[0][j] +
				m1[i][1] * m2[1][j] +
				m1[i][2] * m2[2][j] +
				m1[i][3] * m2[3][j];
		}
	}

	return result;
}

inline vec4 operator*(mat4 m, vec4 v)
{
	return vec4
	{
		m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
		m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3],
		m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] * v[3],
		m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] * v[3]
	};
}

inline mat4& operator+=(mat4& m1, mat4 m2)
{
	m1 = m1 + m2;
	return m1;
}

inline mat4& operator-=(mat4& m1, mat4 m2)
{
	m1 = m1 - m2;
	return m1;
}

inline mat4& operator*=(mat4& m1, mat4 m2)
{
	m1 = m1 * m2;
	return m1;
}

inline mat4 operator+(mat4 m, float f)
{
	return mat4
	{
		m[0] + f,
		m[1] + f,
		m[2] + f,
		m[3] + f
	};
}

inline mat4 operator-(mat4 m, float f)
{
	return mat4
	{
		m[0] - f,
		m[1] - f,
		m[2] - f,
		m[3] - f
	};
}

inline mat4 operator*(mat4 m, float f)
{
	return mat4
	{
		m[0] * f,
		m[1] * f,
		m[2] * f,
		m[3] * f
	};
}

inline mat4 operator/(mat4 m, float f)
{
	return mat4
	{
		m[0] / f,
		m[1] / f,
		m[2] / f,
		m[3] / f
	};
}

inline mat4 operator+(float f, mat4 m)
{
	return mat4
	{
		f + m[0],
		f + m[1],
		f + m[2],
		f + m[3]
	};
}

inline mat4 operator-(float f, mat4 m)
{
	return mat4
	{
		f - m[0],
		f - m[1],
		f - m[2],
		f - m[3]
	};
}

inline mat4 operator*(float f, mat4 m)
{
	return mat4
	{
		f * m[0],
		f * m[1],
		f * m[2],
		f * m[3]
	};
}

inline mat4 operator/(float f, mat4 m)
{
	return mat4
	{
		f / m[0],
		f / m[1],
		f / m[2],
		f / m[3]
	};
}

inline mat4& operator+=(mat4& m, float f)
{
	m = m + f;
	return m;
}

inline mat4& operator-=(mat4& m, float f)
{
	m = m - f;
	return m;
}

inline mat4& operator*=(mat4& m, float f)
{
	m = m * f;
	return m;
}

inline mat4& operator/=(mat4& m, float f)
{
	m = m / f;
	return m;
}

///////////////////////////////////////////////////////////////////////////////
// 2x4 matrix
///////////////////////////////////////////////////////////////////////////////

struct mat24
{
	vec4 v[2];

	mat24(float d = 1.0f) :
		v{
			{ d,    0.0f, 0.0f, 0.0f },
	{ 0.0f, d,    0.0f, 0.0f },
	}
	{}

	mat24(float v11, float v12, float v13, float v14,
		float v21, float v22, float v23, float v24) :
		v{
			{ v11, v12, v13, v14 },
	{ v21, v22, v23, v24 },
	}
	{}

	mat24(vec4 v1, vec4 v2) :
		v{
			{ v1[0], v1[1], v1[2], v1[3] },
	{ v2[0], v2[1], v2[2], v2[3] },
	}
	{}

	mat24(vec2 v1, vec2 v2, vec2 v3, vec2 v4) :
		v{
			{ v1[0], v2[0], v3[0], v4[0] },
	{ v1[1], v2[1], v3[1], v4[1] },
	}
	{}

	const vec4& operator[](size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return v[ind];
	}

	vec4& operator[](size_t ind)
	{
		assert(ind >= 0 && ind <= 2);
		return v[ind];
	}

	vec4 col(size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return{ v[0][ind], v[1][ind] };
	}

	vec4 row(size_t ind) const
	{
		assert(ind >= 0 && ind <= 2);
		return v[ind];
	}
};

inline bool operator==(mat24 m1, mat24 m2)
{
	return m1[0] == m2[0] && m1[1] == m2[1];
}

inline bool operator!=(mat24 m1, mat24 m2)
{
	return !(m1 == m2);
}

inline mat24 operator+(mat24 m1, mat24 m2)
{
	return mat24
	{
		m1[0] + m2[0],
		m1[1] + m2[1]
	};
}

inline mat24 operator-(mat24 m1, mat24 m2)
{
	return mat24
	{
		m1[0] - m2[0],
		m1[1] - m2[1]
	};
}


inline mat24 operator*(mat24 m1, mat4 m2)
{
	mat24 result;

	for (size_t i = 0; i < 2; ++i)
	{
		for (size_t j = 0; j < 4; ++j)
		{
			result[i][j] =
				m1[i][0] * m2[0][j] +
				m1[i][1] * m2[1][j] +
				m1[i][2] * m2[2][j] +
				m1[i][3] * m2[3][j];
		}
	}

	return result;
}

inline vec2 operator*(mat24 m, vec4 v)
{
	return vec2
	{
		m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] * v[3],
		m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] * v[3]
	};
}

inline mat24& operator+=(mat24& m1, mat24 m2)
{
	m1 = m1 + m2;
	return m1;
}

inline mat24& operator-=(mat24& m1, mat24 m2)
{
	m1 = m1 - m2;
	return m1;
}

inline mat24 operator+(mat24 m, float f)
{
	return mat24
	{
		m[0] + f,
		m[1] + f
	};
}

inline mat24 operator-(mat24 m, float f)
{
	return mat24
	{
		m[0] - f,
		m[1] - f
	};
}

inline mat24 operator*(mat24 m, float f)
{
	return mat24
	{
		m[0] * f,
		m[1] * f
	};
}

inline mat24 operator/(mat24 m, float f)
{
	return mat24
	{
		m[0] / f,
		m[1] / f
	};
}

inline mat24 operator+(float f, mat24 m)
{
	return mat24
	{
		f + m[0],
		f + m[1]
	};
}

inline mat24 operator-(float f, mat24 m)
{
	return mat24
	{
		f - m[0],
		f - m[1]
	};
}

inline mat24 operator*(float f, mat24 m)
{
	return mat24
	{
		f * m[0],
		f * m[1]
	};
}

inline mat24 operator/(float f, mat24 m)
{
	return mat24
	{
		f / m[0],
		f / m[1]
	};
}

inline mat24& operator+=(mat24& m, float f)
{
	m = m + f;
	return m;
}

inline mat24& operator-=(mat24& m, float f)
{
	m = m - f;
	return m;
}

inline mat24& operator*=(mat24& m, float f)
{
	m = m * f;
	return m;
}

inline mat24& operator/=(mat24& m, float f)
{
	m = m / f;
	return m;
}


///////////////////////////////////////////////////////////////////////////////
// PI
///////////////////////////////////////////////////////////////////////////////
inline float pi()
{
	return 3.14159265358979323846264338327950288419716939937510f;
}

inline float two_pi()
{
	static const float s_twoPi = pi() * 2.0f;

	return s_twoPi;
}

inline float half_pi()
{
	static const float s_halfPi = pi() / 2.0f;

	return s_halfPi;
}


///////////////////////////////////////////////////////////////////////////////
// Lebegopontos egyenloseg
///////////////////////////////////////////////////////////////////////////////
inline bool floatEqual(float a, float b, float sensitivity = 1.0e-8f)
{
	return fabs(a - b) < sensitivity;
}

///////////////////////////////////////////////////////////////////////////////
// Fok-radian konverziok
///////////////////////////////////////////////////////////////////////////////
inline float radToDeg(float val)
{
	static const float s_radToDeg = 180.0f / pi();

	return val * s_radToDeg;
}

inline float degToRad(float val)
{
	static const float s_degToRad = pi() / 180.0f;

	return val * s_degToRad;
}

///////////////////////////////////////////////////////////////////////////////
// Skalaris szorzat
///////////////////////////////////////////////////////////////////////////////
inline float dot(vec2 v1, vec2 v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1];
}

inline float dot(vec3 v1, vec3 v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline float dot(vec4 v1, vec4 v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2] + v1[3] * v2[3];
}

///////////////////////////////////////////////////////////////////////////////
// Hossz
///////////////////////////////////////////////////////////////////////////////
inline float length(vec2 v)
{
	return sqrtf(dot(v, v));
}

inline float length(vec3 v)
{
	return sqrtf(dot(v, v));
}

inline float length(vec4 v)
{
	return sqrtf(dot(v, v));
}

///////////////////////////////////////////////////////////////////////////////
// Negyzetes hossz
///////////////////////////////////////////////////////////////////////////////
inline float length2(vec2 v)
{
	return dot(v, v);
}

inline float length2(vec3 v)
{
	return dot(v, v);
}

inline float length2(vec4 v)
{
	return dot(v, v);
}

///////////////////////////////////////////////////////////////////////////////
// Tavolsag
///////////////////////////////////////////////////////////////////////////////
inline float dist(vec2 v1, vec2 v2)
{
	return length(v1 - v2);
}

inline float dist(vec3 v1, vec3 v2)
{
	return length(v1 - v2);
}

inline float dist(vec4 v1, vec4 v2)
{
	return length(v1 - v2);
}

///////////////////////////////////////////////////////////////////////////////
// Negyzetes tavolsag
///////////////////////////////////////////////////////////////////////////////
inline float dist2(vec2 v1, vec2 v2)
{
	return length2(v1 - v2);
}

inline float dist2(vec3 v1, vec3 v2)
{
	return length2(v1 - v2);
}

inline float dist2(vec4 v1, vec4 v2)
{
	return length2(v1 - v2);
}

///////////////////////////////////////////////////////////////////////////////
// Vektorialis szorzat
///////////////////////////////////////////////////////////////////////////////
inline vec3 cross(vec3 v1, vec3 v2)
{
	return
	{
		v1[1] * v2[2] - v1[2] * v2[1],
		v1[2] * v2[0] - v1[0] * v2[2],
		v1[0] * v2[1] - v1[1] * v2[0],
	};
}

///////////////////////////////////////////////////////////////////////////////
// Normalizalt
///////////////////////////////////////////////////////////////////////////////
inline vec2 normalize(vec2 v)
{
	return v / length(v);
}

inline vec3 normalize(vec3 v)
{
	return v / length(v);
}

inline vec4 normalize(vec4 v)
{
	return v / length(v);
}

///////////////////////////////////////////////////////////////////////////////
// Bezart szog (radianban, egysegvektorokkal)
///////////////////////////////////////////////////////////////////////////////
inline float angleBetweenFast(vec2 v1, vec2 v2)
{
	return acosf(dot(v1, v2));
}

inline float angleBetweenFast(vec3 v1, vec3 v2)
{
	return acosf(dot(v1, v2));
}

///////////////////////////////////////////////////////////////////////////////
// Bezart szog (radianban, tetszoleges vektorokkal)
///////////////////////////////////////////////////////////////////////////////
inline float angleBetween(vec2 v1, vec2 v2)
{
	return angleBetweenFast(normalize(v1), normalize(v2));
}

inline float angleBetween(vec3 v1, vec3 v2)
{
	return angleBetweenFast(normalize(v1), normalize(v2));
}

///////////////////////////////////////////////////////////////////////////////
// Matrix transzponalt
///////////////////////////////////////////////////////////////////////////////
inline mat3 transpose(mat3 m)
{
	return mat3
	{
		m.col(0),
		m.col(1),
		m.col(2)
	};
}

inline mat4 transpose(mat4 m)
{
	return mat4
	{
		m.col(0),
		m.col(1),
		m.col(2),
		m.col(3)
	};
}

///////////////////////////////////////////////////////////////////////////////
// Matrix determinans
///////////////////////////////////////////////////////////////////////////////
inline float determinant(mat3 m)
{
	return
		m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] +
		m[0][2] * m[1][0] * m[2][1] - m[0][0] * m[1][2] * m[2][1] -
		m[0][1] * m[1][0] * m[2][2] - m[0][2] * m[1][1] * m[2][0];
}

inline float determinant(mat4 m)
{
	return
		m[0][3] * m[1][2] * m[2][1] * m[3][0] - m[0][2] * m[1][3] * m[2][1] * m[3][0] -
		m[0][3] * m[1][1] * m[2][2] * m[3][0] + m[0][1] * m[1][3] * m[2][2] * m[3][0] +
		m[0][2] * m[1][1] * m[2][3] * m[3][0] - m[0][1] * m[1][2] * m[2][3] * m[3][0] -
		m[0][3] * m[1][2] * m[2][0] * m[3][1] + m[0][2] * m[1][3] * m[2][0] * m[3][1] +
		m[0][3] * m[1][0] * m[2][2] * m[3][1] - m[0][0] * m[1][3] * m[2][2] * m[3][1] -
		m[0][2] * m[1][0] * m[2][3] * m[3][1] + m[0][0] * m[1][2] * m[2][3] * m[3][1] +
		m[0][3] * m[1][1] * m[2][0] * m[3][2] - m[0][1] * m[1][3] * m[2][0] * m[3][2] -
		m[0][3] * m[1][0] * m[2][1] * m[3][2] + m[0][0] * m[1][3] * m[2][1] * m[3][2] +
		m[0][1] * m[1][0] * m[2][3] * m[3][2] - m[0][0] * m[1][1] * m[2][3] * m[3][2] -
		m[0][2] * m[1][1] * m[2][0] * m[3][3] + m[0][1] * m[1][2] * m[2][0] * m[3][3] +
		m[0][2] * m[1][0] * m[2][1] * m[3][3] - m[0][0] * m[1][2] * m[2][1] * m[3][3] -
		m[0][1] * m[1][0] * m[2][2] * m[3][3] + m[0][0] * m[1][1] * m[2][2] * m[3][3];
}

///////////////////////////////////////////////////////////////////////////////
// Matrix inverz
///////////////////////////////////////////////////////////////////////////////
inline mat3 inverse(mat3 m)
{
	float det = determinant(m);
	float invdet = 1.0f / det;

	mat3 result;

	result[0][0] = (m[1][1] * m[2][2] - m[2][1] * m[1][2]) * invdet;
	result[0][1] = (m[0][2] * m[2][1] - m[0][1] * m[2][2]) * invdet;
	result[0][2] = (m[0][1] * m[1][2] - m[0][2] * m[1][1]) * invdet;
	result[1][0] = (m[1][2] * m[2][0] - m[1][0] * m[2][2]) * invdet;
	result[1][1] = (m[0][0] * m[2][2] - m[0][2] * m[2][0]) * invdet;
	result[1][2] = (m[1][0] * m[0][2] - m[0][0] * m[1][2]) * invdet;
	result[2][0] = (m[1][0] * m[2][1] - m[2][0] * m[1][1]) * invdet;
	result[2][1] = (m[2][0] * m[0][1] - m[0][0] * m[2][1]) * invdet;
	result[2][2] = (m[0][0] * m[1][1] - m[1][0] * m[0][1]) * invdet;

	return result;
}

inline mat4 inverse(mat4 m)
{
	float A2323 = m[2][2] * m[3][3] - m[2][3] * m[3][2];
	float A1323 = m[2][1] * m[3][3] - m[2][3] * m[3][1];
	float A1223 = m[2][1] * m[3][2] - m[2][2] * m[3][1];
	float A0323 = m[2][0] * m[3][3] - m[2][3] * m[3][0];
	float A0223 = m[2][0] * m[3][2] - m[2][2] * m[3][0];
	float A0123 = m[2][0] * m[3][1] - m[2][1] * m[3][0];
	float A2313 = m[1][2] * m[3][3] - m[1][3] * m[3][2];
	float A1313 = m[1][1] * m[3][3] - m[1][3] * m[3][1];
	float A1213 = m[1][1] * m[3][2] - m[1][2] * m[3][1];
	float A2312 = m[1][2] * m[2][3] - m[1][3] * m[2][2];
	float A1312 = m[1][1] * m[2][3] - m[1][3] * m[2][1];
	float A1212 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
	float A0313 = m[1][0] * m[3][3] - m[1][3] * m[3][0];
	float A0213 = m[1][0] * m[3][2] - m[1][2] * m[3][0];
	float A0312 = m[1][0] * m[2][3] - m[1][3] * m[2][0];
	float A0212 = m[1][0] * m[2][2] - m[1][2] * m[2][0];
	float A0113 = m[1][0] * m[3][1] - m[1][1] * m[3][0];
	float A0112 = m[1][0] * m[2][1] - m[1][1] * m[2][0];

	float det = determinant(m);
	float invdet = 1.0f / det;

	mat4 result;

	result[0][0] = invdet * (m[1][1] * A2323 - m[1][2] * A1323 + m[1][3] * A1223);
	result[0][1] = invdet * -(m[0][1] * A2323 - m[0][2] * A1323 + m[0][3] * A1223);
	result[0][2] = invdet * (m[0][1] * A2313 - m[0][2] * A1313 + m[0][3] * A1213);
	result[0][3] = invdet * -(m[0][1] * A2312 - m[0][2] * A1312 + m[0][3] * A1212);
	result[1][0] = invdet * -(m[1][0] * A2323 - m[1][2] * A0323 + m[1][3] * A0223);
	result[1][1] = invdet * (m[0][0] * A2323 - m[0][2] * A0323 + m[0][3] * A0223);
	result[1][2] = invdet * -(m[0][0] * A2313 - m[0][2] * A0313 + m[0][3] * A0213);
	result[1][3] = invdet * (m[0][0] * A2312 - m[0][2] * A0312 + m[0][3] * A0212);
	result[2][0] = invdet * (m[1][0] * A1323 - m[1][1] * A0323 + m[1][3] * A0123);
	result[2][1] = invdet * -(m[0][0] * A1323 - m[0][1] * A0323 + m[0][3] * A0123);
	result[2][2] = invdet * (m[0][0] * A1313 - m[0][1] * A0313 + m[0][3] * A0113);
	result[2][3] = invdet * -(m[0][0] * A1312 - m[0][1] * A0312 + m[0][3] * A0112);
	result[3][0] = invdet * -(m[1][0] * A1223 - m[1][1] * A0223 + m[1][2] * A0123);
	result[3][1] = invdet * (m[0][0] * A1223 - m[0][1] * A0223 + m[0][2] * A0123);
	result[3][2] = invdet * -(m[0][0] * A1213 - m[0][1] * A0213 + m[0][2] * A0113);
	result[3][3] = invdet * (m[0][0] * A1212 - m[0][1] * A0212 + m[0][2] * A0112);

	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Transzformaciok - eltolas
///////////////////////////////////////////////////////////////////////////////
inline mat3 translate(vec2 v)
{
	mat3 result;

	result[0][2] = v[0];
	result[1][2] = v[1];

	return result;
}

inline mat4 translate(vec3 v)
{
	mat4 result;

	result[0][3] = v[0];
	result[1][3] = v[1];
	result[2][3] = v[2];

	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Transzformaciok - forgatas
///////////////////////////////////////////////////////////////////////////////
inline mat3 rotate(float angle)
{
	mat3 result;

	result[0][0] = cosf(angle);
	result[0][1] = -sinf(angle);
	result[1][0] = sinf(angle);
	result[1][1] = cosf(angle);

	return result;
}

inline mat4 rotateX(float angle)
{
	mat4 result;

	result[1][1] = cosf(angle);
	result[1][2] = -sinf(angle);
	result[2][1] = sinf(angle);
	result[2][2] = cosf(angle);

	return result;
}

inline mat4 rotateY(float angle)
{
	mat4 result;

	result[0][0] = cosf(angle);
	result[0][2] = sinf(angle);
	result[2][0] = -sinf(angle);
	result[2][2] = cosf(angle);

	return result;
}

inline mat4 rotateZ(float angle)
{
	mat4 result;

	result[0][0] = cosf(angle);
	result[0][1] = -sinf(angle);
	result[1][0] = sinf(angle);
	result[1][1] = cosf(angle);

	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Transzformaciok - skalazas
///////////////////////////////////////////////////////////////////////////////
inline mat3 scale(vec2 v)
{
	mat3 result;

	result[0][0] = v[0];
	result[1][1] = v[1];

	return result;
}

inline mat4 scale(vec3 v)
{
	mat4 result;

	result[0][0] = v[0];
	result[1][1] = v[1];
	result[2][2] = v[2];

	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Transzformaciok - WtV
///////////////////////////////////////////////////////////////////////////////
inline mat3 windowToViewport2(vec2 windowPos, vec2 windowSize, vec2 viewportPos, vec2 viewportSize)
{
	return
		translate(viewportPos) *
		scale(vec2(viewportSize.x / windowSize.x, viewportSize.y / windowSize.y)) *
		translate(-windowPos);
}

inline mat4 windowToViewport3(vec2 windowPos, vec2 windowSize, vec2 viewportPos, vec2 viewportSize)
{
	return
		translate(vec3(viewportPos.x, viewportPos.y, 0)) *
		scale(vec3(viewportSize.x / windowSize.x, viewportSize.y / windowSize.y, 1)) *
		translate(vec3(-windowPos.x, -windowPos.y, 0));
}

///////////////////////////////////////////////////////////////////////////////
// Transzformaciok - koordinata transzformacio
///////////////////////////////////////////////////////////////////////////////
inline mat3 coordinateTransform(vec2 d, vec2 i, vec2 j)
{
	mat3 result;

	result[0] = vec3(i, -dot(d, i));
	result[1] = vec3(j, -dot(d, j));

	return result;
}

inline mat4 coordinateTransform(vec3 d, vec3 i, vec3 j, vec3 k)
{
	mat4 result;

	result[0] = vec4(i, -dot(d, i));
	result[1] = vec4(j, -dot(d, j));
	result[2] = vec4(k, -dot(d, k));

	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Vetitesek
///////////////////////////////////////////////////////////////////////////////
inline mat4 ortho()
{
	mat4 result;

	result[2][2] = 0.0f;

	return result;
}

inline mat4 perspective(float center)
{
	mat4 result;

	result[2][2] = 0.0f;
	result[3][2] = -1.0f / center;

	return result;
}

inline mat4 parallel(vec3 dir)
{
	mat4 result;

	result[0][2] = -dir[0] / dir[2];
	result[1][2] = -dir[1] / dir[2];
	result[2][2] = 0.0f;

	return result;
}

inline mat4 axonometry(vec2 v1, vec2 v2, vec2 v3)
{
	mat4 result;

	result[0][0] = v1[0];
	result[0][1] = v2[0];
	result[0][2] = v3[0];
	result[1][0] = v1[1];
	result[1][1] = v2[1];
	result[1][2] = v3[1];
	result[2][2] = 0.0f;

	return result;
}

inline mat4 cavalier(float angle, float shortening)
{
	mat4 result;

	result[0][0] = -shortening * cosf(angle);
	result[0][1] = 1.0f;
	result[0][2] = 0.0f;
	result[1][0] = -shortening * sinf(angle);
	result[1][1] = 0.0f;
	result[1][2] = 1.0f;
	result[2][2] = 0.0f;

	return result;
}

///////////////////////////////////////////////////////////////////////////////
// Kiirato fuggvenyek
///////////////////////////////////////////////////////////////////////////////
inline void printMathObject(bool b, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%sbool(" __BGM_FORMAT_B ")\n",
		prefix,
		b ? "true" : "false");
}

inline void printMathObject(int i, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%sint(" __BGM_FORMAT_I ")\n",
		prefix,
		i);
}

inline void printMathObject(float f, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%sfloat(" __BGM_FORMAT_F ")\n",
		prefix,
		f);
}

inline void printMathObject(vec2 v, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%svec2("
		__BGM_FORMAT_F ", " __BGM_FORMAT_F ")\n",
		prefix,
		v[0], v[1]);
}

inline void printMathObject(vec3 v, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%svec3("
		__BGM_FORMAT_F ", " __BGM_FORMAT_F ", " __BGM_FORMAT_F ")\n",
		prefix,
		v[0], v[1], v[2]);
}

inline void printMathObject(vec4 v, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%svec4("
		__BGM_FORMAT_F ", " __BGM_FORMAT_F ", " __BGM_FORMAT_F ", " __BGM_FORMAT_F ")\n",
		prefix,
		v[0], v[1], v[2], v[3]);
}

inline void printMathObject(mat3 m, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%smat3\n(\n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", \n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", \n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F "\n)\n",
		prefix,
		m[0][0], m[0][1], m[0][2],
		m[1][0], m[1][1], m[1][2],
		m[2][0], m[2][1], m[2][2]);
}

inline void printMathObject(mat4 m, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%smat4\n(\n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", \n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", \n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", \n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F "\n)\n",
		prefix,
		m[0][0], m[0][1], m[0][2], m[0][3],
		m[1][0], m[1][1], m[1][2], m[1][3],
		m[2][0], m[2][1], m[2][2], m[2][3],
		m[3][0], m[3][1], m[3][2], m[3][3]);
}

inline void printMathObject(mat24 m, const char* prefix = "", FILE* fout = stdout)
{
	fprintf(fout, "%smat24\n(\n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", \n"
		__BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F ", "  __BGM_FORMAT_F "\n)\n",
		prefix,
		m[0][0], m[0][1], m[0][2], m[0][3],
		m[1][0], m[1][1], m[1][2], m[1][3]);
}

#endif // !H___BEVGRAFMATH2017
