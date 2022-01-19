#include <iostream>
#include "allocator.h"
#include <map>
#include <utility>

int main() {
	std::map<int, int, std::less<int>, allocator<std::pair<int, int>, 120>> m;
	for (int i = 0; i < 3; i++) {
		m[i] = i;
	}
	for (auto it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << std::endl;
	m.erase(m.begin());
	for (auto it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << std::endl;
	m.insert(m.end(), std::pair<int, int>{10, 10});
	for (auto it = m.begin(); it != m.end(); it++) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << std::endl;
	return 0;
}
