#pragma warning( disable : 4996 )

int main()
{
	printf("In main\n\n\n");

	cout << "Data Type Sizes:" << "\n";
	cout << "================" << "\n";
	cout << "bool........." << sizeof(bool) << " bytes" << "\n";
	cout << "char........." << sizeof(char) << " bytes" << "\n";
	cout << "int.........." << sizeof(int) << " bytes" << "\n";
	cout << "long........." << sizeof(long) << " bytes" << "\n";
	cout << "long long...." << sizeof(long long) << " bytes" << "\n";
	cout << "float........" << sizeof(float) << " bytes" << "\n";
	cout << "double......." << sizeof(double) << " bytes" << "\n";
	cout << "\n" << "\n";


	lru_cache web_cache;
	web_cache.insert("www.valrhona.com", 1);
	web_cache.insert("www.bloomberg.com", 2);
	web_cache.insert("www.amazon.com", 3);
	web_cache.insert("www.google.com", 4);
	web_cache.insert("www.watchguard.com", 5);
	web_cache.insert("www.laurellye.com", 6);
	web_cache.insert("www.campingworld.com", 7);
	web_cache.insert("www.microsoft.com", 8);
	web_cache.insert("www.gmail.com", 9);
	web_cache.insert("www.cppcon.com", 10);

	web_cache.display();
	cout << "\n";

	web_cache.insert("www.pendleton.com", 11);
	web_cache.insert("www.isocpp.org", 12);

	web_cache.display();
	cout << "\n";

	web_cache.get("www.gmail.com");
	web_cache.get("www.laurellye.com");
	web_cache.get("www.foobar.com");

	web_cache.display();
	cout << "\n";


	return 0;
}
