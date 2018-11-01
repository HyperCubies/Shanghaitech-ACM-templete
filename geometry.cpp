#include "macros.cpp"

struct point2 {
	db x, y;
	point2(db a = 0, db b = 0):x(a),y(b) {}
	point2(const point2& p):x(p.x),y(p.y) {}
	point2(const pii& p):x(p.fi),y(p.se) {}
	friend point2 operator+(const point2 &a, const point2 &b) { return point2(a.x+b.x, a.y+b.y); }
	friend point2 operator-(const point2 &a, const point2 &b) { return point2(a.x-b.x, a.y-b.y); }
	friend point2 operator*(const point2 &p, const db &k) { return point2(k*p.x, k*p.y); }
	friend point2 operator*(const db &k, const point2 &p) { return point2(k*p.x, k*p.y); }
	friend istream& operator>>(istream& in, point2 &p) { in>>p.x>>p.y; return in; }
	friend ostream& operator<<(ostream& out, point2 &p) { out<<p.x<<','<<p.y; return out; }
	friend bool operator<(const point2 &a, const point2 &b);
	db dot(const point2 &p) { return this->x*p.x + this->y*p.y; }
	static db dot(const point2 &a, const point2 &b) { return a.x*b.x+a.y*b.y; }
	db norm() { return sqrt(this->dot(*this)); }
	db cross(const point2 &p) { return this->x*p.y - this->y*p.x; }
	static db cross(const point2 &a, const point2 &b) { return a.x*b.y-a.y*b.x; }
};


struct point3 {
	db x, y, z;
	point3():x(0),y(0),z(0) {};
	point3(db a, db b, db c):x(a),y(b),z(c) {};
	point3(const point3& p):x(p.x),y(p.y),z(p.z) {};
	friend point3 operator+(const point3 &a, const point3 &b) { return point3(a.x+b.x, a.y+b.y, a.z+b.z); }
	friend point3 operator-(const point3 &a, const point3 &b) { return point3(a.x-b.x, a.y-b.y, a.z+b.z); }
	friend point3 operator*(const point3 &p, const db &k) { return point3(k*p.x, k*p.y, k*p.z); }
	friend point3 operator*(const db &k, const point3 &p) { return p*k; }
	friend istream& operator>>(istream& in, point3 &p) { in>>p.x>>p.y>>p.z; return in; }
	db dot(const point3 &p) { return this->x*p.x + this->y*p.y; }
	static db dot(const point3 &a, const point3 &b) { return a.x*b.x+a.y*b.y; }
	db norm() { return sqrt(this->dot(*this)); }
	point3 cross(const point3 &p) {
		db a, b, c;
		a = this->y*p.z - this->z*p.y;
		b = this->z*p.x - this->x*p.z;
		c = this->x*p.y - this->y*p.x;
		return point3(a, b, c);
	}
	static point3 cross(point3 &a, point3 &b) { return a.cross(b); }
};



int main() {
	return 0;
}