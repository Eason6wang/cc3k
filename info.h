#ifndef __INFO_H__
#define __INFO_H__


struct Info {
    int hp, atk, def;
	public:
	Info& operator+ (const Info&other) {
		hp += other.hp;
		atk += other.atk;
		def += other.def;
		return *this;
	}
};

#endif
