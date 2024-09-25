//El pset de esta clase fue en hackerrank y nomas se hizo mergesort para el codigo de clase
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'miniMaxSum' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void miniMaxSum(vector<int> arr) {
    // Calculate the total sum of the array
    long long total_sum = 0;
    for (int num : arr) {
        total_sum += num;
    }

    // Find the minimum and maximum values in the array
    int min_value = *min_element(arr.begin(), arr.end());
    int max_value = *max_element(arr.begin(), arr.end());

    // Calculate the minimum sum (excluding the maximum value)
    long long min_sum = total_sum - max_value;

    // Calculate the maximum sum (excluding the minimum value)
    long long max_sum = total_sum - min_value;

    // Print the results
    cout << min_sum << " " << max_sum << endl;
}

int main()
{
    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(5);

    for (int i = 0; i < 5; i++) {
        int arr_item = stoi(arr_temp[i]);
        arr[i] = arr_item;
    }

    miniMaxSum(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );
    return s;
}

string rtrim(const string &str) {
    string s(str);
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );
    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;
    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));
        start = end + 1;
    }

    tokens.push_back(str.substr(start));
    return tokens;
}
