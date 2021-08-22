int main()
{
	std::ifstream datafile("my.data");
	istream_iterator<int>  start(datafile);
	istream_iterator<int> dataEnd;
	list<int> data(start, dataEnd);
	for (auto const& i : data) {
		cout << i << "\n";
	}


}
