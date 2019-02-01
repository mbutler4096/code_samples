#ifndef LRU_CACHE_H
#define LRU_CACHE_H

#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>


class lru_cache
{
public:
	lru_cache() { usage.reserve(max_items); }
	~lru_cache() {}

	void insert(string url, int data);
	void clear();
	int get(string url);

	void display();

private:
	map<string, int> cache;
	vector<string> usage;

	const unsigned int max_items = 10;
};

void lru_cache::insert(string url, int data)
{
	//update the usage list
	auto it = find(usage.begin(), usage.end(), url);
	if (it == usage.end())
	{
		//not there so add it
		usage.insert(usage.begin(), url);
																		
		//remove the least used url if the cache is too large
		if (usage.size() > max_items)
		{
			cache.erase(usage.back());
			usage.pop_back();
		}
	}
	else
	{
		//already there, move to the front of the list
		rotate(usage.begin(), it, it + 1);
	}


	//update/add the url to the cache
	cache[url] = data;
}

	void lru_cache::clear()
	{
		cache.clear();
		usage.clear();
	}

	int lru_cache::get(string url)
	{
		//return the data or 0 if it's not there
		auto it = cache.find(url);
		if (it == cache.end()) return 0;

		//move the url to the front of the list
		auto vit = find(usage.begin(), usage.end(), url);
		rotate(usage.begin(), vit, vit+1);


		return it->second;
	}

	void lru_cache::display()
	{
		for (auto it = cache.begin(); it != cache.end(); ++it)
			cout << it->first << " " << it->second << "\n";
		cout << "-----------------------------" << "\n";
		for (auto lit = usage.begin(); lit != usage.end(); ++lit)
			cout << *lit << "\n";
	}

#endif //LRU_CACHE_H
