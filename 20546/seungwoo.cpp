#include <iostream>

int price[14] = { 0, };

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(NULL);
	std::cin.tie(NULL);

	int cash; std::cin >> cash;
	int jCash = cash;
	int sCash = cash;

	for (int i = 0; i < 14; i++) {
		std::cin >> price[i];
	}

	int jStock[14] = { 0, };
	int sStock[14] = { 0, };

	bool flag = true;

	for (int i = 0; i < 14; i++) {
		jStock[i] = jCash / price[i];
		jCash %= price[i];

		if (i >= 3) {
			if (price[i - 2] > price[i - 3] && price[i - 1] > price[i - 2] && price[i] > price[i - 1]) {
				for (int j = 0; j <= i; j++) {
					sCash += price[i] * sStock[j];
					// std::cout << "Sell" << i << " " << sCash << std::endl;
				}
			}
			else if (price[i - 2] < price[i - 3] && price[i - 1] < price[i - 2] && price[i] < price[i - 1]) {
				sStock[i] = sCash / price[i];
				sCash %= price[i];
				// std::cout << "BUY" << i << " " << sCash << std::endl;
			}
		}
	}

	for (int i = 0; i < 14; i++) {
		jCash += price[13] * jStock[i];
		sCash += price[13] * sStock[i];
	}

	// std::cout << jCash << " " << sCash << std::endl;

	if (jCash == sCash)
		std::cout << "SAMESAME\n";
	else if (jCash > sCash)
		std::cout << "BNP\n";
	else
		std::cout << "TIMING\n";

	return 0;
}