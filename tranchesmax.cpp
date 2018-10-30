#include <iostream>
#include <vector>

using namespace std;
typedef vector<int> Vec;
typedef vector<vector<int>> Vec2D;
typedef vector<size_t> SVec;

int somme_consecutifs_max(Vec vec) {
	int sum = 0;
	int max_sum = 0;

	for (auto i : vec) {
		if (i != 0) {
			sum += i;
		}
		else {
			if (sum > max_sum) {
				max_sum = sum;
				sum = 0;
			}
		}
		//cout << "i: " << i << " sum: " << sum << " max_sum: " << max_sum << endl;
	}

	if (sum > max_sum) {
		max_sum = sum;
	}

	return max_sum;
}

SVec lignes_max(Vec2D vec) {
	vector<size_t> result;
	int max_sum = 0;

	for (int i = 0; i < vec.size(); i++) {
		int sum = somme_consecutifs_max(vec[i]);
		if (sum == max_sum) {
			result.push_back(i);
		}
		else if (sum > max_sum) {
			result.clear();
			result.push_back(i);
			max_sum = sum;
		}
	}

	return result;
}

Vec2D tranches_max(Vec2D v) {
	SVec idx = lignes_max(v);
	Vec2D result;

	for (auto i : idx) {
		result.push_back(v[i]);
	}

	return result;
}

int main()
{
	Vec2D v = { { 2,1,0,2 },{0,1,0,3 }, {1,3,0,0}, {0,2,2,0} };
	Vec2D foo = tranches_max(v);
	for (auto bar : foo) {
		for (auto i : bar) {
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}