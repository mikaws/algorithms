#include <iostream>
#include "arr.h"

int main() {
	auto arr = arr_util::random_array(5);
	for(int i=0;i<5;i++) {
		std::cout << arr[i];
	}
	std::cout << "\n";
}
