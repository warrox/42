#include "../includes/span.hpp"


Span::Span():_n(0){}

Span::Span(unsigned int N):_n(N){}

Span::Span(const Span& other):_n(other.getN()){	
	_numbers = other._numbers;
}

Span& Span::operator=(const Span& other){
	if (this != &other){
		this->_n = other.getN();
		this->_numbers = other._numbers;
	}
	return *this;
}

Span::~Span(){}

unsigned int Span::getN () const{return this->_n;}

void Span::addNumber( int nbr ){
	if (this->getN() == _numbers.size()){
		throw std::exception();
	}
	else{
		_numbers.push_back(nbr);
	}
}

void Span::addNumber(size_t n, time_t seed){
    std::srand(static_cast<unsigned int>(seed));

    for (size_t i = 0; i < n; ++i) {
        int random_number = std::rand() % 100000 + 1;
		if (this->getN() == _numbers.size()){
			throw std::exception();
		}
        _numbers.push_back(random_number);
    }
}

int Span::longestSpan(){
	if (_numbers.size() == 0){
		throw std::exception();
	} else if (_numbers.size() == 1){
		return 0;
	}
		
	std::sort(_numbers.begin(), _numbers.end());
	return (_numbers[_numbers.size() - 1] - _numbers[0]);
}

int Span::shortestSpan(){
	if (_numbers.size() == 0){
		throw std::exception();
	} else if (_numbers.size() == 1){
		return 0;
	}
	
	std::sort(_numbers.begin(), _numbers.end());
	int min = _numbers[_numbers.size() - 1] - _numbers[0];
	
	for (std::size_t i = 1; i < _numbers.size(); i++){
		if (_numbers[i] - _numbers[i - 1] < min){
			min = _numbers[i] - _numbers[i - 1];
		}
	}
	return min;
}
