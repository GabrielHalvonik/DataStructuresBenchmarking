#pragma once

template <typename T>
class Comparator {
public:
	Comparator(bool);
	int operator()(const T&, const T&);

	bool getAsc() const;
	void setAsc(bool value);

protected:
	virtual int compare(const T&, const T&) = 0;

private:
	bool asc;
};

template<typename T>
Comparator<T>::Comparator(bool asc) : asc(asc) { }

template <typename T>
int Comparator<T>::operator()(const T& a, const T& b) {
	return asc ? this->compare(a, b) : this->compare(a, b) * -1;
}

template <typename T>
bool Comparator<T>::getAsc() const {
	return this->asc;
}

template <typename T>
void Comparator<T>::setAsc(bool value) {
	this->asc = value;
}


class IntComparator : public Comparator<int> {
protected:
	int compare(const int&, const int&) override;
};

int IntComparator::compare(const int& a, const int& b) {
	return a - b;
}
