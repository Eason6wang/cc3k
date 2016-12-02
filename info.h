#ifndef __INFO_H__
#define __INFO_H__


struct Info {
    int hp, atk, def;
	public:
	/*Info& operator+ (const Info&other) {
		hp += other.hp;
		atk += other.atk;
		def += other.def;
		return *this;
	}*/
	Info &operator*(const int num){
	    hp *= num;
	    atk *= num;
	    def *= num;
	    return *this;
	}
};

#endif
