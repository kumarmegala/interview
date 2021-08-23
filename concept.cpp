// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include "Header1.h"
#include <concepts>
#include <iterator>
#include <iostream>     // std::cout
#include <fstream>      // std::ifstream
#include <list>
#include <string>
#include <cstddef>
#include <concepts>
#include <vector>
#include <numeric>

using namespace std;
int gen_pdf(std::string url)
{
	cout << "gen pdf " << endl;
	return 0;
}
int main2()
{
	gen_pdf("test");
	cout << "Hello CMake." << endl;
	return 0;
}

int main3()
{
	std::ifstream datafile("my.data");
	istream_iterator<int>  start(datafile);
	istream_iterator<int> dataEnd;
	list<int> data(start, dataEnd);
	for (auto const& i : data) {
		cout << i << "\n";
	}
	return 0;
}

// Declaration of the concept "Hashable", which is satisfied by any type 'T'
// such that for values 'a' of type 'T', the expression std::hash<T>{}(a)
// compiles and its result is convertible to std::size_t
template<typename T>
concept Hashable = requires(T a) {
	{ std::hash<T>{}(a) } -> std::convertible_to<std::size_t>;
};

struct meow {};

// Constrained C++20 function template:
template<Hashable T>
void f(T) {}


int main5() {
	// using std::operator""s;
	f("abc"); // OK, std::string satisfies Hashable
   // f(meow{}); // Error: meow does not satisfy Hashable
	return 0;
}

//template <class T>
//concept integral = std::is_integral_v<T>;

//template <typename T>
//concept ILabel = requires(T v)
///{
//	{v.buildHtml()} -> std::convertible_to<std::string>;
//};


template <typename T>
requires std::integral<T> || std::floating_point<T>

constexpr double Average(std::vector<T> const& vec) {
	const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
	return sum / vec.size();
}

int main6() {
	std::vector ints{ 1, 2, 3, 4, 5 };
	std::cout << "average " <<  Average(ints) << '\n';
	return 0;

}
#include <numeric>
#include <iostream>
#include <vector>
#include <functional>
void  main_inner_product()
{
	//std::vector<int> a{ 0, 1, 2, 3, 4 };
	//std::vector<int> b{ 5, 4, 2, 3, 1 };

	std::vector<int> a{ 0, 1, 2, 3, 4 };
	std::vector<int> b{ 0,0,2,0,0,0};

	int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
	std::cout << "Inner product of a and b: " << r1 << '\n';

	int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0, std::plus<>(), std::equal_to<>());
	std::cout << "Number of pairwise matches between a and b: " << r2 << '\n';
}


#include <algorithm>
#include <iostream>
#include <vector>
void PrintFunc(int x) {
	std::cout << x << std::endl;
}
int main() {
	std::vector< int > v;
	v.push_back(1);
	v.push_back(2);
	std::for_each(v.begin(), v.end(), PrintFunc);
}

