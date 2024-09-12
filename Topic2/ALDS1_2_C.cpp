//ALDS1_2_C
//Jimmy - s1312004

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

void printArray(string A[], int length)
{
    cout << A[0];
    for (int i = 1; i < length; i++)
    {
        cout << " " << A[i];
    }
    cout << endl;
}

void BubbleSort(string C[], int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = length - 1; j >= i + 1; j--)
        {
            if ((int)C[j][1] < (int)C[j - 1][1])
            {
                swap(C[j], C[j - 1]);
            }
        }
    }
}

void SelectionSort(string C[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int mini = i;
        for (int j = i + 1; j < length; j++)
        {
            if ((int)C[j][1] < (int)C[mini][1])
            {
                mini = j;
            }
        }
        swap(C[i], C[mini]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    int n, count[1000], index = 0;
    bool flag = false;
    set<int> container;
    vector<string> element[1000];

    cin >> n;
    string card[n], cardForBubbleSort[n], cardForSelectionSort[n];

    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
        cardForBubbleSort[i] = card[i];
        cardForSelectionSort[i] = card[i];
        count[(int)card[i][1]]++;
        if (count[(int)card[i][1]] > 1)
        {
            flag = true;
            container.insert((int)card[i][1]);
        }
    }

    BubbleSort(cardForBubbleSort, n);
    printArray(cardForBubbleSort, n);
    cout << "Stable" << endl;

    SelectionSort(cardForSelectionSort, n);
    printArray(cardForSelectionSort, n);
    set<int>::iterator x;
    for (x = container.begin(); x != container.end(); x++)
    {
        if (count[*x] > 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (*x == (int)card[i][1])
                {
                    element[index].push_back(card[i]);
                }
            }
            index++;
            for (int i = 0; i < n; i++)
            {
                if (*x == (int)cardForSelectionSort[i][1])
                {
                    element[index].push_back(cardForSelectionSort[i]);
                }
            }
            index++;
        }
    }
    for (int i = 0; i <= index; i += 2)
    {
        if (element[i] != element[i + 1])
        {
            cout << "Not stable" << endl;
            return 0;
        }
    }
    cout << "Stable" << endl;

    return 0;
}