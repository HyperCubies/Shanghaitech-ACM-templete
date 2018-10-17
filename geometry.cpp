#include "macros.cpp"

struct point2 {
	db x, y;
	point2():x(0),y(0) {}
	point2(db a, db b):x(a),y(b) {}
	point2(const point2& p):x(p.x),y(p.y) {}
	friend point2 operator+(const point2 &a, const point2 &b) { return point2(a.x+b.x, a.y+b.y); }
	friend point2 operator-(const point2 &a, const point2 &b) { return point2(a.x-b.x, a.y-b.y); }
	friend point2 operator*(const point2 &p, const db &k) { return point2(k*p.x, k*p.y); }
	friend point2 operator*(const db &k, const point2 &p) { return point2(k*p.x, k*p.y); }
	friend istream& operator>>(istream& in, point2 &p) { in>>p.x>>p.y; return in; }
	friend ostream& operator<<(ostream& out, point2 &p) { out<<p.x<<','<<p.y; return out; }
	db dot(const point2 &p) { return this->x*p.x + this->y*p.y; }
	static dot(const point2 &a, const point2 &b) { return a.x*b.x+a.y*b.y; }
	db norm() { return sqrt(this->dot(*this)); }
	db cross(const point2 &p) { return this->x*p.y - this->y*p.x; }
	static cross(const point2 &a, const point2 &b) { return a.x*b.y-a.y*b.x; }
};

void test() {
	stringstream ss;
	ss << "1 2";
	int a, b;
	ss >> a >> b;
	print(a);
	print(b);
}

int main()
{
	test();
	// system("pause");
	return 0;
}