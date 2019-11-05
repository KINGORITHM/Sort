#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>

using namespace std;

bool cmp(int a, int b)
{
	if (a == b)
		return a > b;

	vector<int> a_v;
	vector<int> b_v;

	do
	{
		a_v.push_back(a%10);
		a /= 10;
	} while (a > 0);
	
	do 
	{
		b_v.push_back(b % 10);
		b /= 10;
	} while (b > 0);

	reverse(a_v.begin(), a_v.end());
	reverse(b_v.begin(), b_v.end());

	if (a_v[0] == b_v[0]) // 1. 맨앞의 숫자가 같은 경우
	{
		for (int i = 0; a_v.size() < 4; i++) //네자리로 만들어줌
			a_v.push_back(a_v[i]);

		for (int i = 0; b_v.size() < 4; i++) //네자리로 만들어줌
			b_v.push_back(b_v[i]);

		for (int i = 0; i < 4; i++)
		{
			if (a_v[i] > b_v[i])
				return true;
			else if (a_v[i] < b_v[i])
				return false;
		}
	}
	else if (a_v[0] > b_v[0]) // 2. a의 첫번째 숫자가 더 큰 경우
		return true;
	else if (a_v[0] < b_v[0]) // 3. b의 첫번째 숫자가 더 큰 경우
		return false;
}

string solution(vector<int> numbers) {
	string answer = "";

	sort(numbers.begin(), numbers.end(), cmp);

	for (int i = 0; i < numbers.size(); i++)
	{
		answer += to_string(numbers[i]);
	}

	if (numbers[0] == 0)
		return "0";

	return answer;
}

int main()
{
	//vector<int> numbers = { 3,30,34,5,9 };
	//vector<int> numbers = { 6,10,2 };
	vector<int> numbers = { 21, 212 };
	//vector<int> numbers = { 70,0,0 };
	string answer = solution(numbers);
	cout << answer;
	return 0;
}