// Name: Andrew Le

#include <iostream>
using namespace std;

int main() {
    int values[] = {5, 4, 6, 3, 7, 2, 8, 1, 9, 0};
    int len = sizeof(values) / sizeof(int);

    int sum = 0;
    int minVal = values[0];
    int maxVal = values[0];

    for (int i = 0; i < len; i++) {
        sum += values[i];
        if (values[i] < minVal)
            minVal = values[i];
        if (values[i] > maxVal)
            maxVal = values[i];
    }

    float average = static_cast<float>(sum) / len;

    cout << "Sum: " << sum << endl;
    cout << "minVal value: " << minVal << endl;
    cout << "maxVal value: " << maxVal << endl;
    cout << "Average: " << average << endl;

    int index;
    cout << "Enter index (0-" << (len - 1) << "): ";
    cin >> index;

    if (index < 0) {
        cout << "Buffer underrun" << endl;
    } else if (index >= len) {
        cout << "Buffer overrun" << endl;
    } else {
        cout << "Element value: " << values[index] << endl;
    }

    return 0;
}
