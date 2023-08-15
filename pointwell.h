#pragma once
#include <cstdint>

typedef std::uint16_t welltype;

class PointWell {
public:
	PointWell() {
		Max = 1u;
		Current = 1u;
	}

	PointWell(welltype mHP, welltype cHP) {
		Max = mHP;
		Current = cHP;

		if (Current > Max)
			Current = Max;
	}

	bool setMax(welltype newMax) {
		if (newMax < 1) {
			return false;
		}

		Max = newMax;

		if (Current > Max){
			Current = Max;
		}

		return true;
	}

	welltype getMax() {
		return Max;
	}

	welltype getCurrent() {
		return Current;
	}

	void reduce(welltype amountReduced) {
		if (amountReduced > Current) {
			Current = 0;
			return;
		}

		Current -= amountReduced;
	}

	void increase(welltype amountIncreased) {
		if (amountIncreased + Current > Max) {
			Current = Max;
			return;
		}

		Current += amountIncreased;
	}

private:
	//hptype ShieldHP;
	welltype Current;
	welltype Max;

};
