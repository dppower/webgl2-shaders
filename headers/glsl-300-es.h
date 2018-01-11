// Emulation of GLSL ES 3.0
#define uniform
#define attribute
#define varying
#define precision
#define highp
#define mediump
#define lowp
#define in
#define centroid
#define smooth
#define flat
#define layout(x)
#define out
#define inout

//Generic vector templates
template<typename T> struct t_vec { };

template<> struct t_vec<double> { };
template<> struct t_vec<int> { };
template<> struct t_vec<bool> { };

template<int n> struct vec_n { };

template<> struct vec_n<2> { };
template<> struct vec_n<3> { };
template<> struct vec_n<4> { };

template<typename T, int n> struct t_vec_n : public t_vec<T>, public vec_n<n> { };

template<typename T> struct t_vec_n<T,2> : public t_vec<T>, public vec_n<2> {
	t_vec_n();
	t_vec_n(T x);
	t_vec_n(T x, T y);
	t_vec_n(const t_vec_n<T,2>& a);
	t_vec_n(const t_vec_n<T,3>& a);
	t_vec_n(const t_vec_n<T,4>& a);

	T x, y;
	t_vec_n<T,2>& xx; t_vec_n<T,2>& yy; t_vec_n<T,2>& xy; t_vec_n<T,2>& yx;

	t_vec_n<T,3>& xxx; t_vec_n<T,3>& xxy; t_vec_n<T,3>& xyy; t_vec_n<T,3>& xyx;
	t_vec_n<T,3>& yxx; t_vec_n<T,3>& yxy; t_vec_n<T,3>& yyx; t_vec_n<T,3>& yyy;
	
	t_vec_n<T,4>& xxxx; t_vec_n<T,4>& xxxy; t_vec_n<T,4>& xxyx; t_vec_n<T,4>& xxyy;
	t_vec_n<T,4>& yyxx; t_vec_n<T,4>& yyxy; t_vec_n<T,4>& yyyx; t_vec_n<T,4>& yyyy;

	t_vec_n<T,4>& yxxx; t_vec_n<T,4>& yxxy; t_vec_n<T,4>& yxyx; t_vec_n<T,4>& yxyy;
	t_vec_n<T,4>& xyxx; t_vec_n<T,4>& xyxy; t_vec_n<T,4>& xyyx; t_vec_n<T,4>& xyyy;

	T& operator [] (unsigned int index);
	t_vec_n<T,2>& operator = (const t_vec_n<T,2>& a);
};

template<typename T> struct t_vec_n<T,3> : public t_vec<T>, public vec_n<3> {
	t_vec_n();
	t_vec_n(T x);
	t_vec_n(T x, T y, T z);
	t_vec_n(t_vec_n<T,2> a, T b);
	t_vec_n(T a, t_vec_n<T,2> b);
	t_vec_n(const t_vec_n<T,3>& a);
	t_vec_n(const t_vec_n<T,4>& a);

	T x, y, z;

	t_vec_n<T,2>& xx; t_vec_n<T,2>& xy; t_vec_n<T,2>& xz; t_vec_n<T,2>& yx; t_vec_n<T,2>& yy; t_vec_n<T,2>& yz; t_vec_n<T,2>& zx; t_vec_n<T,2>& zy; t_vec_n<T,2>& zz;

	t_vec_n<T,3>& xxx; t_vec_n<T,3>& xxy; t_vec_n<T,3>& xxz; t_vec_n<T,3>& xyx; t_vec_n<T,3>& xyy; t_vec_n<T,3>& xyz; t_vec_n<T,3>& xzx; t_vec_n<T,3>& xzy; t_vec_n<T,3>& xzz;
	t_vec_n<T,3>& yxx; t_vec_n<T,3>& yxy; t_vec_n<T,3>& yxz; t_vec_n<T,3>& yyx; t_vec_n<T,3>& yyy; t_vec_n<T,3>& yyz; t_vec_n<T,3>& yzx; t_vec_n<T,3>& yzy; t_vec_n<T,3>& yzz;
	t_vec_n<T,3>& zxx; t_vec_n<T,3>& zxy; t_vec_n<T,3>& zxz; t_vec_n<T,3>& zyx; t_vec_n<T,3>& zyy; t_vec_n<T,3>& zyz; t_vec_n<T,3>& zzx; t_vec_n<T,3>& zzy; t_vec_n<T,3>& zzz;

	t_vec_n<T,4>& xxxx; t_vec_n<T,4>& xxxy; t_vec_n<T,4>& xxxz; t_vec_n<T,4>& xxyx; t_vec_n<T,4>& xxyy; t_vec_n<T,4>& xxyz; t_vec_n<T,4>& xxzx; t_vec_n<T,4>& xxzy; t_vec_n<T,4>& xxzz;
	t_vec_n<T,4>& xyxx; t_vec_n<T,4>& xyxy; t_vec_n<T,4>& xyxz; t_vec_n<T,4>& xyyx; t_vec_n<T,4>& xyyy; t_vec_n<T,4>& xyyz; t_vec_n<T,4>& xyzx; t_vec_n<T,4>& xyzy; t_vec_n<T,4>& xyzz;
	t_vec_n<T,4>& xzxx; t_vec_n<T,4>& xzxy; t_vec_n<T,4>& xzxz; t_vec_n<T,4>& xzyx; t_vec_n<T,4>& xzyy; t_vec_n<T,4>& xzyz; t_vec_n<T,4>& xzzx; t_vec_n<T,4>& xzzy; t_vec_n<T,4>& xzzz;

	t_vec_n<T,4>& yxxx; t_vec_n<T,4>& yxxy; t_vec_n<T,4>& yxxz; t_vec_n<T,4>& yxyx; t_vec_n<T,4>& yxyy; t_vec_n<T,4>& yxyz; t_vec_n<T,4>& yxzx; t_vec_n<T,4>& yxzy; t_vec_n<T,4>& yxzz;
	t_vec_n<T,4>& yyxx; t_vec_n<T,4>& yyxy; t_vec_n<T,4>& yyxz; t_vec_n<T,4>& yyyx; t_vec_n<T,4>& yyyy; t_vec_n<T,4>& yyyz; t_vec_n<T,4>& yyzx; t_vec_n<T,4>& yyzy; t_vec_n<T,4>& yyzz;
	t_vec_n<T,4>& yzxx; t_vec_n<T,4>& yzxy; t_vec_n<T,4>& yzxz; t_vec_n<T,4>& yzyx; t_vec_n<T,4>& yzyy; t_vec_n<T,4>& yzyz; t_vec_n<T,4>& yzzx; t_vec_n<T,4>& yzzy; t_vec_n<T,4>& yzzz;

	t_vec_n<T,4>& zxxx; t_vec_n<T,4>& zxxy; t_vec_n<T,4>& zxxz; t_vec_n<T,4>& zxyx; t_vec_n<T,4>& zxyy; t_vec_n<T,4>& zxyz; t_vec_n<T,4>& zxzx; t_vec_n<T,4>& zxzy; t_vec_n<T,4>& zxzz;
	t_vec_n<T,4>& zyxx; t_vec_n<T,4>& zyxy; t_vec_n<T,4>& zyxz; t_vec_n<T,4>& zyyx; t_vec_n<T,4>& zyyy; t_vec_n<T,4>& zyyz; t_vec_n<T,4>& zyzx; t_vec_n<T,4>& zyzy; t_vec_n<T,4>& zyzz;
	t_vec_n<T,4>& zzxx; t_vec_n<T,4>& zzxy; t_vec_n<T,4>& zzxz; t_vec_n<T,4>& zzyx; t_vec_n<T,4>& zzyy; t_vec_n<T,4>& zzyz; t_vec_n<T,4>& zzzx; t_vec_n<T,4>& zzzy; t_vec_n<T,4>& zzzz;

	T r, g, b;

	t_vec_n<T,2>& rr; t_vec_n<T,2>& rg; t_vec_n<T,2>& rb; t_vec_n<T,2>& gr; t_vec_n<T,2>& gg; t_vec_n<T,2>& gb; t_vec_n<T,2>& br; t_vec_n<T,2>& bg; t_vec_n<T,2>& bb;

	t_vec_n<T,3>& rrr; t_vec_n<T,3>& rrg; t_vec_n<T,3>& rrb; t_vec_n<T,3>& rgr; t_vec_n<T,3>& rgg; t_vec_n<T,3>& rgb; t_vec_n<T,3>& rbr; t_vec_n<T,3>& rbg; t_vec_n<T,3>& rbb;
	t_vec_n<T,3>& grr; t_vec_n<T,3>& grg; t_vec_n<T,3>& grb; t_vec_n<T,3>& ggr; t_vec_n<T,3>& ggg; t_vec_n<T,3>& ggb; t_vec_n<T,3>& gbr; t_vec_n<T,3>& gbg; t_vec_n<T,3>& gbb;
	t_vec_n<T,3>& brr; t_vec_n<T,3>& brg; t_vec_n<T,3>& brb; t_vec_n<T,3>& bgr; t_vec_n<T,3>& bgg; t_vec_n<T,3>& bgb; t_vec_n<T,3>& bbr; t_vec_n<T,3>& bbg; t_vec_n<T,3>& bbb;

	t_vec_n<T,4>& rrrr; t_vec_n<T,4>& rrrg; t_vec_n<T,4>& rrrb; t_vec_n<T,4>& rrgr; t_vec_n<T,4>& rrgg; t_vec_n<T,4>& rrgb; t_vec_n<T,4>& rrbr; t_vec_n<T,4>& rrbg; t_vec_n<T,4>& rrbb;
	t_vec_n<T,4>& rgrr; t_vec_n<T,4>& rgrg; t_vec_n<T,4>& rgrb; t_vec_n<T,4>& rggr; t_vec_n<T,4>& rggg; t_vec_n<T,4>& rggb; t_vec_n<T,4>& rgbr; t_vec_n<T,4>& rgbg; t_vec_n<T,4>& rgbb;
	t_vec_n<T,4>& rbrr; t_vec_n<T,4>& rbrg; t_vec_n<T,4>& rbrb; t_vec_n<T,4>& rbgr; t_vec_n<T,4>& rbgg; t_vec_n<T,4>& rbgb; t_vec_n<T,4>& rbbr; t_vec_n<T,4>& rbbg; t_vec_n<T,4>& rbbb;

	t_vec_n<T,4>& grrr; t_vec_n<T,4>& grrg; t_vec_n<T,4>& grrb; t_vec_n<T,4>& grgr; t_vec_n<T,4>& grgg; t_vec_n<T,4>& grgb; t_vec_n<T,4>& grbr; t_vec_n<T,4>& grbg; t_vec_n<T,4>& grbb;
	t_vec_n<T,4>& ggrr; t_vec_n<T,4>& ggrg; t_vec_n<T,4>& ggrb; t_vec_n<T,4>& gggr; t_vec_n<T,4>& gggg; t_vec_n<T,4>& gggb; t_vec_n<T,4>& ggbr; t_vec_n<T,4>& ggbg; t_vec_n<T,4>& ggbb;
	t_vec_n<T,4>& gbrr; t_vec_n<T,4>& gbrg; t_vec_n<T,4>& gbrb; t_vec_n<T,4>& gbgr; t_vec_n<T,4>& gbgg; t_vec_n<T,4>& gbgb; t_vec_n<T,4>& gbbr; t_vec_n<T,4>& gbbg; t_vec_n<T,4>& gbbb;

	t_vec_n<T,4>& brrr; t_vec_n<T,4>& brrg; t_vec_n<T,4>& brrb; t_vec_n<T,4>& brgr; t_vec_n<T,4>& brgg; t_vec_n<T,4>& brgb; t_vec_n<T,4>& brbr; t_vec_n<T,4>& brbg; t_vec_n<T,4>& brbb;
	t_vec_n<T,4>& bgrr; t_vec_n<T,4>& bgrg; t_vec_n<T,4>& bgrb; t_vec_n<T,4>& bggr; t_vec_n<T,4>& bggg; t_vec_n<T,4>& bggb; t_vec_n<T,4>& bgbr; t_vec_n<T,4>& bgbg; t_vec_n<T,4>& bgbb;
	t_vec_n<T,4>& bbrr; t_vec_n<T,4>& bbrg; t_vec_n<T,4>& bbrb; t_vec_n<T,4>& bbgr; t_vec_n<T,4>& bbgg; t_vec_n<T,4>& bbgb; t_vec_n<T,4>& bbbr; t_vec_n<T,4>& bbbg; t_vec_n<T,4>& bbbb;

	T& operator [] (unsigned int index);
	t_vec_n<T,3>& operator = (const t_vec_n<T,3>& a);
};

template<typename T> struct t_vec_n<T,4> : public t_vec<T>, public vec_n<4> {
	t_vec_n();
	t_vec_n(T x);
	t_vec_n(T x, T y, T z, T w);
	t_vec_n(const t_vec_n<T,2>& a, const t_vec_n<T,2>& b);
	t_vec_n(const t_vec_n<T,2>& a, T b, T c);
	t_vec_n(T a, T b, const t_vec_n<T,2>& c);
	t_vec_n(T a, const t_vec_n<T,2>& b, T c);
	t_vec_n(T a, const t_vec_n<T,3>& b);
	t_vec_n(const t_vec_n<T,3>& a, T b);
	t_vec_n(const t_vec_n<T,4>& a);

	T x, y, z, w;

	t_vec_n<T,2>& xx; t_vec_n<T,2>& xy; t_vec_n<T,2>& xz; t_vec_n<T,2>& xw; t_vec_n<T,2>& yx; t_vec_n<T,2>& yy; t_vec_n<T,2>& yz; t_vec_n<T,2>& yw; t_vec_n<T,2>& zx; t_vec_n<T,2>& zy; t_vec_n<T,2>& zz; t_vec_n<T,2>& zw; t_vec_n<T,2>& wx; t_vec_n<T,2>& wy; t_vec_n<T,2>& wz; t_vec_n<T,2>& ww;

	t_vec_n<T,3>& xxx; t_vec_n<T,3>& xxy; t_vec_n<T,3>& xxz; t_vec_n<T,3>& xxw; t_vec_n<T,3>& xyx; t_vec_n<T,3>& xyy; t_vec_n<T,3>& xyz; t_vec_n<T,3>& xyw; t_vec_n<T,3>& xzx; t_vec_n<T,3>& xzy; t_vec_n<T,3>& xzz; t_vec_n<T,3>& xzw; t_vec_n<T,3>& xwx; t_vec_n<T,3>& xwy; t_vec_n<T,3>& xwz; t_vec_n<T,3>& xww;
	t_vec_n<T,3>& yxx; t_vec_n<T,3>& yxy; t_vec_n<T,3>& yxz; t_vec_n<T,3>& yxw; t_vec_n<T,3>& yyx; t_vec_n<T,3>& yyy; t_vec_n<T,3>& yyz; t_vec_n<T,3>& yyw; t_vec_n<T,3>& yzx; t_vec_n<T,3>& yzy; t_vec_n<T,3>& yzz; t_vec_n<T,3>& yzw; t_vec_n<T,3>& ywx; t_vec_n<T,3>& ywy; t_vec_n<T,3>& ywz; t_vec_n<T,3>& yww;
	t_vec_n<T,3>& zxx; t_vec_n<T,3>& zxy; t_vec_n<T,3>& zxz; t_vec_n<T,3>& zxw; t_vec_n<T,3>& zyx; t_vec_n<T,3>& zyy; t_vec_n<T,3>& zyz; t_vec_n<T,3>& zyw; t_vec_n<T,3>& zzx; t_vec_n<T,3>& zzy; t_vec_n<T,3>& zzz; t_vec_n<T,3>& zzw; t_vec_n<T,3>& zwx; t_vec_n<T,3>& zwy; t_vec_n<T,3>& zwz; t_vec_n<T,3>& zww;
	t_vec_n<T,3>& wxx; t_vec_n<T,3>& wxy; t_vec_n<T,3>& wxz; t_vec_n<T,3>& wxw; t_vec_n<T,3>& wyx; t_vec_n<T,3>& wyy; t_vec_n<T,3>& wyz; t_vec_n<T,3>& wyw; t_vec_n<T,3>& wzx; t_vec_n<T,3>& wzy; t_vec_n<T,3>& wzz; t_vec_n<T,3>& wzw; t_vec_n<T,3>& wwx; t_vec_n<T,3>& wwy; t_vec_n<T,3>& wwz; t_vec_n<T,3>& www;

	t_vec_n<T,4>& xxxx; t_vec_n<T,4>& xxxy; t_vec_n<T,4>& xxxz; t_vec_n<T,4>& xxxw; t_vec_n<T,4>& xxyx; t_vec_n<T,4>& xxyy; t_vec_n<T,4>& xxyz; t_vec_n<T,4>& xxyw; t_vec_n<T,4>& xxzx; t_vec_n<T,4>& xxzy; t_vec_n<T,4>& xxzz; t_vec_n<T,4>& xxzw; t_vec_n<T,4>& xxwx; t_vec_n<T,4>& xxwy; t_vec_n<T,4>& xxwz; t_vec_n<T,4>& xxww;
	t_vec_n<T,4>& xyxx; t_vec_n<T,4>& xyxy; t_vec_n<T,4>& xyxz; t_vec_n<T,4>& xyxw; t_vec_n<T,4>& xyyx; t_vec_n<T,4>& xyyy; t_vec_n<T,4>& xyyz; t_vec_n<T,4>& xyyw; t_vec_n<T,4>& xyzx; t_vec_n<T,4>& xyzy; t_vec_n<T,4>& xyzz; t_vec_n<T,4>& xyzw; t_vec_n<T,4>& xywx; t_vec_n<T,4>& xywy; t_vec_n<T,4>& xywz; t_vec_n<T,4>& xyww;
	t_vec_n<T,4>& xzxx; t_vec_n<T,4>& xzxy; t_vec_n<T,4>& xzxz; t_vec_n<T,4>& xzxw; t_vec_n<T,4>& xzyx; t_vec_n<T,4>& xzyy; t_vec_n<T,4>& xzyz; t_vec_n<T,4>& xzyw; t_vec_n<T,4>& xzzx; t_vec_n<T,4>& xzzy; t_vec_n<T,4>& xzzz; t_vec_n<T,4>& xzzw; t_vec_n<T,4>& xzwx; t_vec_n<T,4>& xzwy; t_vec_n<T,4>& xzwz; t_vec_n<T,4>& xzww;
	t_vec_n<T,4>& xwxx; t_vec_n<T,4>& xwxy; t_vec_n<T,4>& xwxz; t_vec_n<T,4>& xwxw; t_vec_n<T,4>& xwyx; t_vec_n<T,4>& xwyy; t_vec_n<T,4>& xwyz; t_vec_n<T,4>& xwyw; t_vec_n<T,4>& xwzx; t_vec_n<T,4>& xwzy; t_vec_n<T,4>& xwzz; t_vec_n<T,4>& xwzw; t_vec_n<T,4>& xwwx; t_vec_n<T,4>& xwwy; t_vec_n<T,4>& xwwz; t_vec_n<T,4>& xwww;

	t_vec_n<T,4>& yxxx; t_vec_n<T,4>& yxxy; t_vec_n<T,4>& yxxz; t_vec_n<T,4>& yxxw; t_vec_n<T,4>& yxyx; t_vec_n<T,4>& yxyy; t_vec_n<T,4>& yxyz; t_vec_n<T,4>& yxyw; t_vec_n<T,4>& yxzx; t_vec_n<T,4>& yxzy; t_vec_n<T,4>& yxzz; t_vec_n<T,4>& yxzw; t_vec_n<T,4>& yxwx; t_vec_n<T,4>& yxwy; t_vec_n<T,4>& yxwz; t_vec_n<T,4>& yxww;
	t_vec_n<T,4>& yyxx; t_vec_n<T,4>& yyxy; t_vec_n<T,4>& yyxz; t_vec_n<T,4>& yyxw; t_vec_n<T,4>& yyyx; t_vec_n<T,4>& yyyy; t_vec_n<T,4>& yyyz; t_vec_n<T,4>& yyyw; t_vec_n<T,4>& yyzx; t_vec_n<T,4>& yyzy; t_vec_n<T,4>& yyzz; t_vec_n<T,4>& yyzw; t_vec_n<T,4>& yywx; t_vec_n<T,4>& yywy; t_vec_n<T,4>& yywz; t_vec_n<T,4>& yyww;
	t_vec_n<T,4>& yzxx; t_vec_n<T,4>& yzxy; t_vec_n<T,4>& yzxz; t_vec_n<T,4>& yzxw; t_vec_n<T,4>& yzyx; t_vec_n<T,4>& yzyy; t_vec_n<T,4>& yzyz; t_vec_n<T,4>& yzyw; t_vec_n<T,4>& yzzx; t_vec_n<T,4>& yzzy; t_vec_n<T,4>& yzzz; t_vec_n<T,4>& yzzw; t_vec_n<T,4>& yzwx; t_vec_n<T,4>& yzwy; t_vec_n<T,4>& yzwz; t_vec_n<T,4>& yzww;
	t_vec_n<T,4>& ywxx; t_vec_n<T,4>& ywxy; t_vec_n<T,4>& ywxz; t_vec_n<T,4>& ywxw; t_vec_n<T,4>& ywyx; t_vec_n<T,4>& ywyy; t_vec_n<T,4>& ywyz; t_vec_n<T,4>& ywyw; t_vec_n<T,4>& ywzx; t_vec_n<T,4>& ywzy; t_vec_n<T,4>& ywzz; t_vec_n<T,4>& ywzw; t_vec_n<T,4>& ywwx; t_vec_n<T,4>& ywwy; t_vec_n<T,4>& ywwz; t_vec_n<T,4>& ywww;

	t_vec_n<T,4>& zxxx; t_vec_n<T,4>& zxxy; t_vec_n<T,4>& zxxz; t_vec_n<T,4>& zxxw; t_vec_n<T,4>& zxyx; t_vec_n<T,4>& zxyy; t_vec_n<T,4>& zxyz; t_vec_n<T,4>& zxyw; t_vec_n<T,4>& zxzx; t_vec_n<T,4>& zxzy; t_vec_n<T,4>& zxzz; t_vec_n<T,4>& zxzw; t_vec_n<T,4>& zxwx; t_vec_n<T,4>& zxwy; t_vec_n<T,4>& zxwz; t_vec_n<T,4>& zxww;
	t_vec_n<T,4>& zyxx; t_vec_n<T,4>& zyxy; t_vec_n<T,4>& zyxz; t_vec_n<T,4>& zyxw; t_vec_n<T,4>& zyyx; t_vec_n<T,4>& zyyy; t_vec_n<T,4>& zyyz; t_vec_n<T,4>& zyyw; t_vec_n<T,4>& zyzx; t_vec_n<T,4>& zyzy; t_vec_n<T,4>& zyzz; t_vec_n<T,4>& zyzw; t_vec_n<T,4>& zywx; t_vec_n<T,4>& zywy; t_vec_n<T,4>& zywz; t_vec_n<T,4>& zyww;
	t_vec_n<T,4>& zzxx; t_vec_n<T,4>& zzxy; t_vec_n<T,4>& zzxz; t_vec_n<T,4>& zzxw; t_vec_n<T,4>& zzyx; t_vec_n<T,4>& zzyy; t_vec_n<T,4>& zzyz; t_vec_n<T,4>& zzyw; t_vec_n<T,4>& zzzx; t_vec_n<T,4>& zzzy; t_vec_n<T,4>& zzzz; t_vec_n<T,4>& zzzw; t_vec_n<T,4>& zzwx; t_vec_n<T,4>& zzwy; t_vec_n<T,4>& zzwz; t_vec_n<T,4>& zzww;
	t_vec_n<T,4>& zwxx; t_vec_n<T,4>& zwxy; t_vec_n<T,4>& zwxz; t_vec_n<T,4>& zwxw; t_vec_n<T,4>& zwyx; t_vec_n<T,4>& zwyy; t_vec_n<T,4>& zwyz; t_vec_n<T,4>& zwyw; t_vec_n<T,4>& zwzx; t_vec_n<T,4>& zwzy; t_vec_n<T,4>& zwzz; t_vec_n<T,4>& zwzw; t_vec_n<T,4>& zwwx; t_vec_n<T,4>& zwwy; t_vec_n<T,4>& zwwz; t_vec_n<T,4>& zwww;

	t_vec_n<T,4>& wxxx; t_vec_n<T,4>& wxxy; t_vec_n<T,4>& wxxz; t_vec_n<T,4>& wxxw; t_vec_n<T,4>& wxyx; t_vec_n<T,4>& wxyy; t_vec_n<T,4>& wxyz; t_vec_n<T,4>& wxyw; t_vec_n<T,4>& wxzx; t_vec_n<T,4>& wxzy; t_vec_n<T,4>& wxzz; t_vec_n<T,4>& wxzw; t_vec_n<T,4>& wxwx; t_vec_n<T,4>& wxwy; t_vec_n<T,4>& wxwz; t_vec_n<T,4>& wxww;
	t_vec_n<T,4>& wyxx; t_vec_n<T,4>& wyxy; t_vec_n<T,4>& wyxz; t_vec_n<T,4>& wyxw; t_vec_n<T,4>& wyyx; t_vec_n<T,4>& wyyy; t_vec_n<T,4>& wyyz; t_vec_n<T,4>& wyyw; t_vec_n<T,4>& wyzx; t_vec_n<T,4>& wyzy; t_vec_n<T,4>& wyzz; t_vec_n<T,4>& wyzw; t_vec_n<T,4>& wywx; t_vec_n<T,4>& wywy; t_vec_n<T,4>& wywz; t_vec_n<T,4>& wyww;
	t_vec_n<T,4>& wzxx; t_vec_n<T,4>& wzxy; t_vec_n<T,4>& wzxz; t_vec_n<T,4>& wzxw; t_vec_n<T,4>& wzyx; t_vec_n<T,4>& wzyy; t_vec_n<T,4>& wzyz; t_vec_n<T,4>& wzyw; t_vec_n<T,4>& wzzx; t_vec_n<T,4>& wzzy; t_vec_n<T,4>& wzzz; t_vec_n<T,4>& wzzw; t_vec_n<T,4>& wzwx; t_vec_n<T,4>& wzwy; t_vec_n<T,4>& wzwz; t_vec_n<T,4>& wzww;
	t_vec_n<T,4>& wwxx; t_vec_n<T,4>& wwxy; t_vec_n<T,4>& wwxz; t_vec_n<T,4>& wwxw; t_vec_n<T,4>& wwyx; t_vec_n<T,4>& wwyy; t_vec_n<T,4>& wwyz; t_vec_n<T,4>& wwyw; t_vec_n<T,4>& wwzx; t_vec_n<T,4>& wwzy; t_vec_n<T,4>& wwzz; t_vec_n<T,4>& wwzw; t_vec_n<T,4>& wwwx; t_vec_n<T,4>& wwwy; t_vec_n<T,4>& wwwz; t_vec_n<T,4>& wwww;
	
	T r, g, b, a;

	t_vec_n<T,2>& rr; t_vec_n<T,2>& rg; t_vec_n<T,2>& rb; t_vec_n<T,2>& ra; t_vec_n<T,2>& gr; t_vec_n<T,2>& gg; t_vec_n<T,2>& gb; t_vec_n<T,2>& ga; t_vec_n<T,2>& br; t_vec_n<T,2>& bg; t_vec_n<T,2>& bb; t_vec_n<T,2>& ba; t_vec_n<T,2>& ar; t_vec_n<T,2>& ag; t_vec_n<T,2>& ab; t_vec_n<T,2>& aa;

	t_vec_n<T,3>& rrr; t_vec_n<T,3>& rrg; t_vec_n<T,3>& rrb; t_vec_n<T,3>& rra; t_vec_n<T,3>& rgr; t_vec_n<T,3>& rgg; t_vec_n<T,3>& rgb; t_vec_n<T,3>& rga; t_vec_n<T,3>& rbr; t_vec_n<T,3>& rbg; t_vec_n<T,3>& rbb; t_vec_n<T,3>& rba; t_vec_n<T,3>& rar; t_vec_n<T,3>& rag; t_vec_n<T,3>& rab; t_vec_n<T,3>& raa;
	t_vec_n<T,3>& grr; t_vec_n<T,3>& grg; t_vec_n<T,3>& grb; t_vec_n<T,3>& gra; t_vec_n<T,3>& ggr; t_vec_n<T,3>& ggg; t_vec_n<T,3>& ggb; t_vec_n<T,3>& gga; t_vec_n<T,3>& gbr; t_vec_n<T,3>& gbg; t_vec_n<T,3>& gbb; t_vec_n<T,3>& gba; t_vec_n<T,3>& gar; t_vec_n<T,3>& gag; t_vec_n<T,3>& gab; t_vec_n<T,3>& gaa;
	t_vec_n<T,3>& brr; t_vec_n<T,3>& brg; t_vec_n<T,3>& brb; t_vec_n<T,3>& bra; t_vec_n<T,3>& bgr; t_vec_n<T,3>& bgg; t_vec_n<T,3>& bgb; t_vec_n<T,3>& bga; t_vec_n<T,3>& bbr; t_vec_n<T,3>& bbg; t_vec_n<T,3>& bbb; t_vec_n<T,3>& bba; t_vec_n<T,3>& bar; t_vec_n<T,3>& bag; t_vec_n<T,3>& bab; t_vec_n<T,3>& baa;
	t_vec_n<T,3>& arr; t_vec_n<T,3>& arg; t_vec_n<T,3>& arb; t_vec_n<T,3>& ara; t_vec_n<T,3>& agr; t_vec_n<T,3>& agg; t_vec_n<T,3>& agb; t_vec_n<T,3>& aga; t_vec_n<T,3>& abr; t_vec_n<T,3>& abg; t_vec_n<T,3>& abb; t_vec_n<T,3>& aba; t_vec_n<T,3>& aar; t_vec_n<T,3>& aag; t_vec_n<T,3>& aab; t_vec_n<T,3>& aaa;

	t_vec_n<T,4>& rrrr; t_vec_n<T,4>& rrrg; t_vec_n<T,4>& rrrb; t_vec_n<T,4>& rrra; t_vec_n<T,4>& rrgr; t_vec_n<T,4>& rrgg; t_vec_n<T,4>& rrgb; t_vec_n<T,4>& rrga; t_vec_n<T,4>& rrbr; t_vec_n<T,4>& rrbg; t_vec_n<T,4>& rrbb; t_vec_n<T,4>& rrba; t_vec_n<T,4>& rrar; t_vec_n<T,4>& rrag; t_vec_n<T,4>& rrab; t_vec_n<T,4>& rraa;
	t_vec_n<T,4>& rgrr; t_vec_n<T,4>& rgrg; t_vec_n<T,4>& rgrb; t_vec_n<T,4>& rgra; t_vec_n<T,4>& rggr; t_vec_n<T,4>& rggg; t_vec_n<T,4>& rggb; t_vec_n<T,4>& rgga; t_vec_n<T,4>& rgbr; t_vec_n<T,4>& rgbg; t_vec_n<T,4>& rgbb; t_vec_n<T,4>& rgba; t_vec_n<T,4>& rgar; t_vec_n<T,4>& rgag; t_vec_n<T,4>& rgab; t_vec_n<T,4>& rgaa;
	t_vec_n<T,4>& rbrr; t_vec_n<T,4>& rbrg; t_vec_n<T,4>& rbrb; t_vec_n<T,4>& rbra; t_vec_n<T,4>& rbgr; t_vec_n<T,4>& rbgg; t_vec_n<T,4>& rbgb; t_vec_n<T,4>& rbga; t_vec_n<T,4>& rbbr; t_vec_n<T,4>& rbbg; t_vec_n<T,4>& rbbb; t_vec_n<T,4>& rbba; t_vec_n<T,4>& rbar; t_vec_n<T,4>& rbag; t_vec_n<T,4>& rbab; t_vec_n<T,4>& rbaa;
	t_vec_n<T,4>& rarr; t_vec_n<T,4>& rarg; t_vec_n<T,4>& rarb; t_vec_n<T,4>& rara; t_vec_n<T,4>& ragr; t_vec_n<T,4>& ragg; t_vec_n<T,4>& ragb; t_vec_n<T,4>& raga; t_vec_n<T,4>& rabr; t_vec_n<T,4>& rabg; t_vec_n<T,4>& rabb; t_vec_n<T,4>& raba; t_vec_n<T,4>& raar; t_vec_n<T,4>& raag; t_vec_n<T,4>& raab; t_vec_n<T,4>& raaa;

	t_vec_n<T,4>& grrr; t_vec_n<T,4>& grrg; t_vec_n<T,4>& grrb; t_vec_n<T,4>& grra; t_vec_n<T,4>& grgr; t_vec_n<T,4>& grgg; t_vec_n<T,4>& grgb; t_vec_n<T,4>& grga; t_vec_n<T,4>& grbr; t_vec_n<T,4>& grbg; t_vec_n<T,4>& grbb; t_vec_n<T,4>& grba; t_vec_n<T,4>& grar; t_vec_n<T,4>& grag; t_vec_n<T,4>& grab; t_vec_n<T,4>& graa;
	t_vec_n<T,4>& ggrr; t_vec_n<T,4>& ggrg; t_vec_n<T,4>& ggrb; t_vec_n<T,4>& ggra; t_vec_n<T,4>& gggr; t_vec_n<T,4>& gggg; t_vec_n<T,4>& gggb; t_vec_n<T,4>& ggga; t_vec_n<T,4>& ggbr; t_vec_n<T,4>& ggbg; t_vec_n<T,4>& ggbb; t_vec_n<T,4>& ggba; t_vec_n<T,4>& ggar; t_vec_n<T,4>& ggag; t_vec_n<T,4>& ggab; t_vec_n<T,4>& ggaa;
	t_vec_n<T,4>& gbrr; t_vec_n<T,4>& gbrg; t_vec_n<T,4>& gbrb; t_vec_n<T,4>& gbra; t_vec_n<T,4>& gbgr; t_vec_n<T,4>& gbgg; t_vec_n<T,4>& gbgb; t_vec_n<T,4>& gbga; t_vec_n<T,4>& gbbr; t_vec_n<T,4>& gbbg; t_vec_n<T,4>& gbbb; t_vec_n<T,4>& gbba; t_vec_n<T,4>& gbar; t_vec_n<T,4>& gbag; t_vec_n<T,4>& gbab; t_vec_n<T,4>& gbaa;
	t_vec_n<T,4>& garr; t_vec_n<T,4>& garg; t_vec_n<T,4>& garb; t_vec_n<T,4>& gara; t_vec_n<T,4>& gagr; t_vec_n<T,4>& gagg; t_vec_n<T,4>& gagb; t_vec_n<T,4>& gaga; t_vec_n<T,4>& gabr; t_vec_n<T,4>& gabg; t_vec_n<T,4>& gabb; t_vec_n<T,4>& gaba; t_vec_n<T,4>& gaar; t_vec_n<T,4>& gaag; t_vec_n<T,4>& gaab; t_vec_n<T,4>& gaaa;

	t_vec_n<T,4>& brrr; t_vec_n<T,4>& brrg; t_vec_n<T,4>& brrb; t_vec_n<T,4>& brra; t_vec_n<T,4>& brgr; t_vec_n<T,4>& brgg; t_vec_n<T,4>& brgb; t_vec_n<T,4>& brga; t_vec_n<T,4>& brbr; t_vec_n<T,4>& brbg; t_vec_n<T,4>& brbb; t_vec_n<T,4>& brba; t_vec_n<T,4>& brar; t_vec_n<T,4>& brag; t_vec_n<T,4>& brab; t_vec_n<T,4>& braa;
	t_vec_n<T,4>& bgrr; t_vec_n<T,4>& bgrg; t_vec_n<T,4>& bgrb; t_vec_n<T,4>& bgra; t_vec_n<T,4>& bggr; t_vec_n<T,4>& bggg; t_vec_n<T,4>& bggb; t_vec_n<T,4>& bgga; t_vec_n<T,4>& bgbr; t_vec_n<T,4>& bgbg; t_vec_n<T,4>& bgbb; t_vec_n<T,4>& bgba; t_vec_n<T,4>& bgar; t_vec_n<T,4>& bgag; t_vec_n<T,4>& bgab; t_vec_n<T,4>& bgaa;
	t_vec_n<T,4>& bbrr; t_vec_n<T,4>& bbrg; t_vec_n<T,4>& bbrb; t_vec_n<T,4>& bbra; t_vec_n<T,4>& bbgr; t_vec_n<T,4>& bbgg; t_vec_n<T,4>& bbgb; t_vec_n<T,4>& bbga; t_vec_n<T,4>& bbbr; t_vec_n<T,4>& bbbg; t_vec_n<T,4>& bbbb; t_vec_n<T,4>& bbba; t_vec_n<T,4>& bbar; t_vec_n<T,4>& bbag; t_vec_n<T,4>& bbab; t_vec_n<T,4>& bbaa;
	t_vec_n<T,4>& barr; t_vec_n<T,4>& barg; t_vec_n<T,4>& barb; t_vec_n<T,4>& bara; t_vec_n<T,4>& bagr; t_vec_n<T,4>& bagg; t_vec_n<T,4>& bagb; t_vec_n<T,4>& baga; t_vec_n<T,4>& babr; t_vec_n<T,4>& babg; t_vec_n<T,4>& babb; t_vec_n<T,4>& baba; t_vec_n<T,4>& baar; t_vec_n<T,4>& baag; t_vec_n<T,4>& baab; t_vec_n<T,4>& baaa;

	t_vec_n<T,4>& arrr; t_vec_n<T,4>& arrg; t_vec_n<T,4>& arrb; t_vec_n<T,4>& arra; t_vec_n<T,4>& argr; t_vec_n<T,4>& argg; t_vec_n<T,4>& argb; t_vec_n<T,4>& arga; t_vec_n<T,4>& arbr; t_vec_n<T,4>& arbg; t_vec_n<T,4>& arbb; t_vec_n<T,4>& arba; t_vec_n<T,4>& arar; t_vec_n<T,4>& arag; t_vec_n<T,4>& arab; t_vec_n<T,4>& araa;
	t_vec_n<T,4>& agrr; t_vec_n<T,4>& agrg; t_vec_n<T,4>& agrb; t_vec_n<T,4>& agra; t_vec_n<T,4>& aggr; t_vec_n<T,4>& aggg; t_vec_n<T,4>& aggb; t_vec_n<T,4>& agga; t_vec_n<T,4>& agbr; t_vec_n<T,4>& agbg; t_vec_n<T,4>& agbb; t_vec_n<T,4>& agba; t_vec_n<T,4>& agar; t_vec_n<T,4>& agag; t_vec_n<T,4>& agab; t_vec_n<T,4>& agaa;
	t_vec_n<T,4>& abrr; t_vec_n<T,4>& abrg; t_vec_n<T,4>& abrb; t_vec_n<T,4>& abra; t_vec_n<T,4>& abgr; t_vec_n<T,4>& abgg; t_vec_n<T,4>& abgb; t_vec_n<T,4>& abga; t_vec_n<T,4>& abbr; t_vec_n<T,4>& abbg; t_vec_n<T,4>& abbb; t_vec_n<T,4>& abba; t_vec_n<T,4>& abar; t_vec_n<T,4>& abag; t_vec_n<T,4>& abab; t_vec_n<T,4>& abaa;
	t_vec_n<T,4>& aarr; t_vec_n<T,4>& aarg; t_vec_n<T,4>& aarb; t_vec_n<T,4>& aara; t_vec_n<T,4>& aagr; t_vec_n<T,4>& aagg; t_vec_n<T,4>& aagb; t_vec_n<T,4>& aaga; t_vec_n<T,4>& aabr; t_vec_n<T,4>& aabg; t_vec_n<T,4>& aabb; t_vec_n<T,4>& aaba; t_vec_n<T,4>& aaar; t_vec_n<T,4>& aaag; t_vec_n<T,4>& aaab; t_vec_n<T,4>& aaaa;
	
	T& operator [] (unsigned int index);
	t_vec_n<T,4>& operator = (const t_vec_n<T,4>& a);
};

// Double vectors
template <int n> using vecn = t_vec_n<double, n>;
typedef t_vec_n<double, 2> vec2;
typedef t_vec_n<double, 3> vec3;
typedef t_vec_n<double, 4> vec4;

// Boolean vectors
template <int n> using bvecn = t_vec_n<bool, n>;
typedef t_vec_n<bool, 2> bvec2;
typedef t_vec_n<bool, 3> bvec3;
typedef t_vec_n<bool, 4> bvec4;

// Integer vectors
template <int n> using ivecn = t_vec_n<int, n>;
typedef t_vec_n<int, 2> ivec2;
typedef t_vec_n<int, 3> ivec3;
typedef t_vec_n<int, 4> ivec4;

// Unsigned integer vectors
typedef unsigned int uint;
template <int n> using uvecn = t_vec_n<uint, n>;
typedef t_vec_n<uint, 2> uvec2;
typedef t_vec_n<uint, 3> uvec3;
typedef t_vec_n<uint, 4> uvec4;

// Vector operators - floats
template<int n> vecn<n> operator - (const vecn<n>& a);

template<int n> vecn<n> operator + (const vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n> operator - (const vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n> operator * (const vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n> operator / (const vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n>& operator += (vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n>& operator -= (vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n>& operator *= (vecn<n>& a, const vecn<n>& b);
template<int n> vecn<n>& operator /= (vecn<n>& a, const vecn<n>& b);

template<int n> vecn<n> operator + (double a, const vecn<n>& b) {};
template<int n> vecn<n> operator + (const vecn<n>& a, double b) {};
template<int n> vecn<n> operator - (double a, const vecn<n>& b) {};
template<int n> vecn<n> operator - (const vecn<n>& a, double b) {};
template<int n> vecn<n> operator * (double a, const vecn<n>& b) {};
template<int n> vecn<n> operator * (const vecn<n>& a, double b) {};
template<int n> vecn<n> operator / (double a, const vecn<n>& b) {};
template<int n> vecn<n> operator / (const vecn<n>& a, double b) {};

template<int n> vecn<n>& operator += (vecn<n>& a, double b) {};
template<int n> vecn<n>& operator -= (vecn<n>& a, double b) {};
template<int n> vecn<n>& operator *= (vecn<n>& a, double b) {};
template<int n> vecn<n>& operator /= (vecn<n>& a, double b) {};

// Vector operators - integers
template<int n> ivecn<n> operator - (const ivecn<n>& a);

template<int n> ivecn<n> operator + (const ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n> operator - (const ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n> operator * (const ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n> operator / (const ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n>& operator += (ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n>& operator -= (ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n>& operator *= (ivecn<n>& a, const ivecn<n>& b);
template<int n> ivecn<n>& operator /= (ivecn<n>& a, const ivecn<n>& b);

template<int n> ivecn<n> operator + (int a, const ivecn<n>& b) {};
template<int n> ivecn<n> operator + (const ivecn<n>& a, int b) {};
template<int n> ivecn<n> operator - (int a, const ivecn<n>& b) {};
template<int n> ivecn<n> operator - (const ivecn<n>& a, int b) {};
template<int n> ivecn<n> operator * (int a, const ivecn<n>& b) {};
template<int n> ivecn<n> operator * (const ivecn<n>& a, int b) {};
template<int n> ivecn<n> operator / (int a, const ivecn<n>& b) {};
template<int n> ivecn<n> operator / (const ivecn<n>& a, int b) {};

template<int n> ivecn<n>& operator += (ivecn<n>& a, int b) {};
template<int n> ivecn<n>& operator -= (ivecn<n>& a, int b) {};
template<int n> ivecn<n>& operator *= (ivecn<n>& a, int b) {};
template<int n> ivecn<n>& operator /= (ivecn<n>& a, int b) {};

// Vector operators - unsigned integers
template<int n> uvecn<n> operator - (const uvecn<n>& a);

template<int n> uvecn<n> operator + (const uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n> operator - (const uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n> operator * (const uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n> operator / (const uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n>& operator += (uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n>& operator -= (uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n>& operator *= (uvecn<n>& a, const uvecn<n>& b);
template<int n> uvecn<n>& operator /= (uvecn<n>& a, const uvecn<n>& b);

template<int n> uvecn<n> operator + (int a, const uvecn<n>& b) {};
template<int n> uvecn<n> operator + (const uvecn<n>& a, int b) {};
template<int n> uvecn<n> operator - (int a, const uvecn<n>& b) {};
template<int n> uvecn<n> operator - (const uvecn<n>& a, int b) {};
template<int n> uvecn<n> operator * (int a, const uvecn<n>& b) {};
template<int n> uvecn<n> operator * (const uvecn<n>& a, int b) {};
template<int n> uvecn<n> operator / (int a, const uvecn<n>& b) {};
template<int n> uvecn<n> operator / (const uvecn<n>& a, int b) {};

template<int n> uvecn<n>& operator += (uvecn<n>& a, int b) {};
template<int n> uvecn<n>& operator -= (uvecn<n>& a, int b) {};
template<int n> uvecn<n>& operator *= (uvecn<n>& a, int b) {};
template<int n> uvecn<n>& operator /= (uvecn<n>& a, int b) {};

// Matrices - webgl only supports single-precision, no dmat.
struct mat2 {
	mat2(double x);
	mat2(const mat3& m);
	mat2(const mat4& m);
	mat2(vec2 c1, vec2 c2);
	mat2(double m11, double m21, double m12, double m22);

	vec2& operator[] (unsigned int index);
};

mat2 operator * (double a, const mat2& b);
mat2 operator * (const mat2& a, double b);
vec2 operator * (const mat2& a, const vec2& b);
vec2 operator * (const vec2& a, const mat2& b);
mat2 operator * (const mat2& a, const mat2& b);

struct mat3 {
	mat3(double x);
	mat3(const mat4& m);
	mat3(vec3 c1, vec3 c2, vec3 c3);
	mat3(double m11, double m21, double m31, double m12, double m22, double m32, double m13, double m23, double m33);

	vec3& operator[] (unsigned int index);
};

mat3 operator * (double a, const mat3& b);
mat3 operator * (const mat3& a, double b);
vec3 operator * (const mat3& a, const vec3& b);
vec3 operator * (const vec3& a, const mat3& b);
mat3 operator * (const mat3& a, const mat3& b);

struct mat4 {
	mat4(double x);
	mat4(vec4 c1, vec4 c2, vec4 c3, vec4 c4);
	mat4(double m11, double m21, double m31, double m41, 
		 double m12, double m22, double m32, double m42, 
		 double m13, double m23, double m33, double m43, 
		 double m14, double m24, double m34, double m44);

	vec4& operator[] (unsigned int index);
};

mat4 operator * (double a, const mat4& b);
mat4 operator * (const mat4& a, double b);
vec4 operator * (const mat4& a, const vec4& b);
vec4 operator * (const vec4& a, const mat4& b);
mat4 operator * (const mat4& a, const mat4& b);

// Built-in input and outputs
// Vertex shader:
int gl_VertexID;
int gl_InstanceID;
vec4 gl_Position;
double gl_PointSize;

// Fragment Shader
vec4 gl_FragCoord;
bool gl_FrontFacing;
vec2 gl_PointCoord;
double gl_FragDepth;

// Built-in constants
const int gl_MaxVertexAttribs;
const int gl_MaxVertexUniformVectors;
const int gl_MaxVertexOutputVectors;
const int gl_MaxFragmentInputVectors;
const int gl_MaxVertexTextureImageUnits;
const int gl_MaxCombinedTextureImageUnits;
const int gl_MaxTextureImageUnits;
const int gl_MaxFragmentUniformVectors;
const int gl_MaxDrawBuffers;
const int gl_MinProgramTexelOffset;
const int gl_MaxProgramTexelOffset;

struct gl_DepthRangeParameters {
	double near;
	double far;
	double diff;
};

// Angle and Trigonmetry Functions
double radians(double degrees);
template<int n> vecn<n> radians(vecn<n> degrees);
double degrees(double radians);
template<int n> vecn<n> degrees(vecn<n> radians);
double sin(double radians);
template<int n> vecn<n> sin(vecn<n> radians);
double cos(double radians);
template<int n> vecn<n> cos(vecn<n> radians);
double tan(double radians);
template<int n> vecn<n> tan(vecn<n> radians);
double asin(double radians);
template<int n> vecn<n> asin(vecn<n> radians);
double acos(double radians);
template<int n> vecn<n> acos(vecn<n> radians);
double atan(double y, double x);
template<int n> vecn<n> atan(vecn<n> y, vecn<n> x);
double atan(double y_over_x);
template<int n> vecn<n> atan(vecn<n> y_over_x);

double sinh(double radians);
template<int n> vecn<n> sin(vecn<n> radians);
double cosh(double radians);
template<int n> vecn<n> cos(vecn<n> radians);
double tanh(double radians);
template<int n> vecn<n> tan(vecn<n> radians);
double asinh(double radians);
template<int n> vecn<n> asin(vecn<n> radians);
double acosh(double radians);
template<int n> vecn<n> acos(vecn<n> radians);
double atanh(double y, double x);
template<int n> vecn<n> atan(vecn<n> y, vecn<n> x);

// Exponential functions
double pow(double x, double y);
template<int n> vecn<n> pow(vecn<n> x, vecn<n> y);
double exp(double x);
template<int n> vecn<n> exp(vecn<n> x);
double log(double x);
template<int n> vecn<n> log(vecn<n> x);
double exp2(double x);
template<int n> vecn<n> exp2(vecn<n> x);
double log2(double x);
template<int n> vecn<n> log2(vecn<n> x);
double sqrt(double x);
template<int n> vecn<n> sqrt(vecn<n> x);
double inversesqrt(double x);
template<int n> vecn<n> inversesqrt(vecn<n> x);

// Common functions
double abs(double x);
template<int n> vecn<n> abs(vecn<n> x);
int abs(int x);
template<int n> ivecn<n> abs(ivecn<n> x);

double sign(double x);
template<int n> vecn<n> sign(vecn<n> x);
int sign(int x);
template<int n> ivecn<n> sign(ivecn<n> x);

double floor(double x);
template<int n> vecn<n> floor(vecn<n> x);

double trunc(double x);
template<int n> vecn<n> trunc(vecn<n> x);

double round(double x);
template<int n> vecn<n> round(vecn<n> x);

double roundEven(double x);
template<int n> vecn<n> roundEven(vecn<n> x);

double ceil(double x);
template<int n> vecn<n> ceil(vecn<n> x);

double fract(double x);
template<int n> vecn<n> fract(vecn<n> x);

double mod(double x, double y);
template<int n> vecn<n> mod(vecn<n> x, vecn<n> y);
template<int n> vecn<n> mod(vecn<n> x, double y);

double min(double x, double y);
template<int n> vecn<n> min(vecn<n> x, vecn<n> y);
template<int n> vecn<n> min(vecn<n> x, double y);
double min(int x, int y);
template<int n> ivecn<n> min(ivecn<n> x, ivecn<n> y);
template<int n> ivecn<n> min(ivecn<n> x, int y);
double min(uint x, uint y);
template<int n> uvecn<n> min(uvecn<n> x, uvecn<n> y);
template<int n> uvecn<n> min(uvecn<n> x, uint y);

double max(double x, double y);
template<int n> vecn<n> max(vecn<n> x, vecn<n> y);
template<int n> vecn<n> max(vecn<n> x, double y);
double max(int x, int y);
template<int n> ivecn<n> max(ivecn<n> x, ivecn<n> y);
template<int n> ivecn<n> max(ivecn<n> x, int y);
double max(uint x, uint y);
template<int n> uvecn<n> max(uvecn<n> x, uvecn<n> y);
template<int n> uvecn<n> max(uvecn<n> x, uint y);

double clamp(double x, double min, double max);
template<int n> vecn<n> clamp(vecn<n> x, vecn<n> min, vecn<n> max);
template<int n> vecn<n> clamp(vecn<n> x, double min, double max);

double mix(double x, double y, double alpha);
template<int n> vecn<n> mix(vecn<n> x, vecn<n> y, vecn<n> alpha);
template<int n> vecn<n> mix(vecn<n> x, vecn<n> y, double alpha);
template<int n> vecn<n> mix(vecn<n> x, vecn<n> y, bvecn<n> alpha);

double step(double edge, double x);
template<int n> vecn<n> step(vecn<n> edge, vecn<n> x);
template<int n> vecn<n> step(double edge, vecn<n> x);

double smoothstep(double edge0, double edge1, double x);
template<int n> vecn<n> smoothstep(vecn<n> edge0, vecn<n> edge1, vecn<n> x);
template<int n> vecn<n> smoothstep(double edge0, double edge1, vecn<n> x);

template<int n> bvecn<n> isnan(vecn<n> x);
template<int n> bvecn<n> isinf(vecn<n> x);

// Geometric functions
template<int n> double length(vecn<n> x);
double distance(double p0, double p1);
template<int n> double distance(vecn<n> p0, vecn<n> p1);
template<int n> double dot(vecn<n> x, vecn<n> y);
template<int n> vecn<n> cross(vecn<n> x, vecn<n> y);
template<int n> vecn<n> normalize(vecn<n> x);
template<int n> vecn<n> faceforward(vecn<n> incident, vecn<n> normal, vecn<n> reference);
template<int n> vecn<n> reflect(vecn<n> incident, vecn<n> normal);
template<int n> vecn<n> refract(vecn<n> incident, vecn<n> normal, double eta);

// Vector component comparisons functions
template<int n> bvecn<n> lessThan(vecn<n> x, vecn<n> y);
template<int n> bvecn<n> lessThan(ivecn<n> x, ivecn<n> y);
template<int n> bvecn<n> lessThan(uvecn<n> x, uvecn<n> y);
template<int n> bvecn<n> lessThanEqual(vecn<n> x, vecn<n> y);
template<int n> bvecn<n> lessThanEqual(ivecn<n> x, ivecn<n> y);
template<int n> bvecn<n> lessThanEqual(uvecn<n> x, uvecn<n> y);
template<int n> bvecn<n> greaterThan(vecn<n> x, vecn<n> y);
template<int n> bvecn<n> greaterThan(ivecn<n> x, ivecn<n> y);
template<int n> bvecn<n> greaterThan(uvecn<n> x, uvecn<n> y);
template<int n> bvecn<n> greaterThanEqual(vecn<n> x, vecn<n> y);
template<int n> bvecn<n> greaterThanEqual(ivecn<n> x, ivecn<n> y);
template<int n> bvecn<n> greaterThanEqual(uvecn<n> x, uvecn<n> y);
template<int n> bvecn<n> equal(vecn<n> x, vecn<n> y);
template<int n> bvecn<n> equal(ivecn<n> x, ivecn<n> y);
template<int n> bvecn<n> equal(bvecn<n> x, bvecn<n> y);
template<int n> bvecn<n> equal(uvecn<n> x, uvecn<n> y);
template<int n> bvecn<n> notEqual(vecn<n> x, vecn<n> y);
template<int n> bvecn<n> notEqual(ivecn<n> x, ivecn<n> y);
template<int n> bvecn<n> notEqual(bvecn<n> x, bvecn<n> y);
template<int n> bvecn<n> notEqual(uvecn<n> x, uvecn<n> y);
template<int n> bool any(bvecn<n> x);
template<int n> bool all(bvecn<n> x);
template<int n> bool not(bvecn<n> x);

// Texture Lookup
class sampler2D {};
class sampler2DShadow {};
class sampler3D {};
class samplerCube {};
class samplerCubeShadow {};
class sampler2DArray {};
class sampler2DArrayShadow {};

class isampler2D {};
class isampler3D {};
class isamplerCube {};
class isampler2DArray {};

class usampler2D {};
class usampler3D {};
class usamplerCube {};
class usampler2DArray {};

ivec2 textureSize(sampler2D sampler, int lod);
ivec3 textureSize(sampler3D sampler, int lod);
ivec2 textureSize(samplerCube sampler, int lod);
ivec3 textureSize(sampler2DArray sampler, int lod);

ivec2 textureSize(isampler2D sampler, int lod);
ivec3 textureSize(isampler3D sampler, int lod);
ivec2 textureSize(isamplerCube sampler, int lod);
ivec3 textureSize(isampler2DArray sampler, int lod);

ivec2 textureSize(usampler2D sampler, int lod);
ivec3 textureSize(usampler3D sampler, int lod);
ivec2 textureSize(usamplerCube sampler, int lod);
ivec3 textureSize(usampler2DArray sampler, int lod);

ivec2 textureSize(sampler2DShadow sampler, int lod);
ivec2 textureSize(samplerCubeShadow sampler, int lod);
ivec3 textureSize(sampler2DArrayShadow sampler, int lod);

vec4 texture(sampler2D sampler, vec2 p, double bias = 0);
vec4 texture(sampler3D sampler, vec3 p, double bias = 0);
vec4 texture(samplerCube sampler, vec3 p, double bias = 0);
vec4 texture(sampler2DArray sampler, vec3 p, double bias = 0);

double texture(sampler2DShadow sampler, vec3 p, double bias = 0);
double texture(samplerCubeShadow sampler, vec4 p, double bias = 0);
double texture(sampler2DArrayShadow sampler, vec4 p);


// Matrix muliplication by component
// TODO implement outerProduct and transpose definitions for non-square matrices
mat2 matrixCompMult(mat2 a, mat2 b);
mat3 matrixCompMult(mat3 a, mat3 b);
mat4 matrixCompMult(mat4 a, mat4 b);

mat2 outerProduct(vec2 a, vec2 b);
mat3 outerProduct(vec3 a, vec3 b);
mat4 outerProduct(vec4 a, vec4 b);

float determinant(mat2 m);
float determinant(mat3 m);
float determinant(mat4 m);

mat2 transpose(mat2 m);
mat3 transpose(mat3 m);
mat4 transpose(mat4 m);

mat2 inverse(mat2 m);
mat3 inverse(mat3 m);
mat4 inverse(mat4 m);