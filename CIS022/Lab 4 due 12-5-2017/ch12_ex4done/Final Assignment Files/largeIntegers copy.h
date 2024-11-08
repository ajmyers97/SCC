class largeIntegers{
	public:
		void setNum(int list[], int length);     
		void printNum(ostream&);    
		void getNum(istream&);   
		void copyNum(const largeIntegers& right);    
		bool equal(const largeIntegers& right) const;    
		bool notEqual(const largeIntegers& right) const;    
		bool greaterThan(const largeIntegers& right) const;    
		bool lessThan(const largeIntegers& right) const;    
		bool lessOrEqualTo(const largeIntegers& right) const;    
		bool greaterOrEqualTo(const largeIntegers& right) const;    
		largeIntegers add(const largeIntegers& num);    
		largeIntegers subtract(const largeIntegers& num);    
		largeIntegers multiply(const largeIntegers& num);    
		largeIntegers();     
		largeIntegers(int list[], int length = 0, char numSign = '+');
	private:


};