#include <iostream>

struct AdsInfo {
	int viewed_ads;
	float pclicked_ads;
	float earnings;
};

void showInfo(AdsInfo info) {
	std::cout << "Viewed Ads: " << info.viewed_ads << '\n';
	std::cout << "% of Clicked Ads: " << info.pclicked_ads << '\n';
	std::cout << "Average Earnings from each ad: $" << info.earnings << '\n';
	std::cout << "You've made: $" << info.earnings * info.viewed_ads * info.pclicked_ads * 0.01f << " this day.\n";
}

int main() {
	AdsInfo ads;

	std::cout << "Enter number of viewed ads: ";
	std::cin >> ads.viewed_ads;
	std::cout << "Enter porcentage of ads clicked: ";
	std::cin >> ads.pclicked_ads;
	std::cout << "Enter average earnings from each ad: $";
	std::cin >> ads.earnings;

	showInfo(ads);

	return 0;
}
