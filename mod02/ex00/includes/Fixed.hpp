class Fixed
{
private:
	int value;
	static const int fractionalBitsNb = 8;

public:
	Fixed();
	Fixed(Fixed &other);
	~Fixed();
	Fixed &operator=(Fixed &other);
	int getRawBits() const;
	void setRawBits(int const raw);
};
