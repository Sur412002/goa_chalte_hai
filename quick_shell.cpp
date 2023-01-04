#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

void display(float* arr, int n)
{
	cout << "-----------TOP 5 SCORES :--------------\n";
    cout << "     ";
	for(int i = n-1; i > n-1-5; i--)
	{
		cout << fixed << setprecision(2) << arr[i] << " ";
	}
	cout << endl;
}

long long shellSort(float arr[], int n)
{
    long long cnt = 0;
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            float temp = arr[i];
            int j;           
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                cnt ++;
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    return cnt;
}

long long quickSort(float* arr, int first, int last) 
{
	if(first > last)
	{
		return 1;
	}
	int p = first;
	int i = first;
	int j = last;
	long long cnt = 0;
	while(i < j) 
	{

		while(arr[i] <= arr[p])
		{
			cnt ++;
			if(i == last)
			{
				break;
			}
			i ++;
		}
		while(arr[j] >= arr[p])
		{
			cnt++;
			if(j == first)
			{
				break;
			}
			j --;
		}
		if(i < j)
		{	
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[p],arr[j]);
	long long c1 = quickSort(arr, first , j - 1);
	long long c2 = quickSort(arr, j + 1, last);
	return cnt + c1 + c2;
}
		

int main()
{
	auto start = high_resolution_clock::now();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
        cout << "\n--------PROGRAM TO SORT FIRST YEAR PERCENTAGE OF STUDENTS-------\n";
        cout << "Menu: \n";
		cout << "1. Quick Sort & Display top five scores\n";
		cout << "2. Shell Sort & Display top five scores\n";
		cout << "3. Time taken for very large input size\n";
        cout << "4. Exit\n";
    do
	{
		cout << "\nENTER CHOICE - ";
		int ch;
		cin >> ch;
		switch(ch)
		{
            int n;
            float arr[100];
			case 1: 
                cout << "Enter no. of students: ";
                cin >> n;
                cout << "Enter the percentages of students: \n";
                for(int i = 0; i < n; i++)
                {
                    cin >> arr[i];
                }
                cout << "--------USING QUICK SORT----------: \n";
                quickSort(arr,0,n-1); 
                display(arr,n);
                break;
			case 2:
			//int arr[100];
                cout << "Enter no. of students: ";
                cin >> n;
                cout << "Enter the percentages of students: \n";
                for(int i = 0; i < n; i++)
                {
                    cin >> arr[i];
                }
                cout << "--------USING SHELL SORT----------: \n";
                shellSort(arr, n); 
                display(arr,n);
                break;
			case 3: {
                cout << "\n-------TIME TAKEN FOR LARGE INPUT SIZE---------\n";
                cout << "\n------------QUICK SORT------------------\n";
                int num = 10000;
                float *Arr = new float[num];
                long long a;
                for(int i = 0; i < num; i++)
                {
                    Arr[i] = rand();
                }
                start = high_resolution_clock::now();
                a = quickSort(Arr,0,num-1);
                stop = high_resolution_clock::now();
                cout << "------10,000 numbers------\n";
                duration = duration_cast<microseconds>(stop - start);
                cout << "No. of comparisons: " << a << endl;
                cout << fixed << "Time Taken: " << setprecision(4) << duration.count() / 1000000.00 << " seconds" << endl;
                cout << endl;
                num = 100000;
                Arr = new float[num];
                for(int i = 0; i < num; i++)
                {
                    Arr[i] = rand();
                }
                start = high_resolution_clock::now();
                a = quickSort(Arr,0,num-1);
                stop = high_resolution_clock::now();
                cout << "------1,00,000 numbers------\n";
                duration = duration_cast<microseconds>(stop - start);
                cout << "No. of comparisons: " << a << endl;
                cout << fixed << "Time Taken: " << setprecision(4) << duration.count() / 1000000.00 << " seconds" << endl;
                cout << endl;
                num = 1000000;
                Arr = new float[num];
                for(int i = 0; i < num; i++)
                {
                    Arr[i] = rand();
                }
                start = high_resolution_clock::now();
                a = quickSort(Arr,0,num-1);
                stop = high_resolution_clock::now();
                cout << "------10,00,000 numbers------\n";
                duration = duration_cast<microseconds>(stop - start);
                cout << "No. of comparisons: " << a << endl;
                cout << fixed << "Time Taken: " << setprecision(4) << duration.count() / 1000000.00 << " seconds" << endl;
                cout << endl;
                cout << "\n------------SHELL SORT------------------\n";	
                num = 10000;
                Arr = new float[num];
                for(int i = 0; i < num; i++)
                {
                    Arr[i] = rand();
                }
                start = high_resolution_clock::now();
                a = shellSort(Arr,num);
                stop = high_resolution_clock::now();
                cout << "------10,000 numbers------\n";
                duration = duration_cast<microseconds>(stop - start);
                cout << "No. of comparisons: " << a << endl;
                cout << fixed << "Time Taken: " << setprecision(4) << duration.count() / 1000000.00 << " seconds" << endl;
                cout << endl;
                num = 100000;
                Arr = new float[num];
                for(int i = 0; i < num; i++)
                {
                    Arr[i] = rand();
                }
                start = high_resolution_clock::now();
                a = shellSort(Arr,num);
                stop = high_resolution_clock::now();
                cout << "------1,00,000 numbers------\n";
                duration = duration_cast<microseconds>(stop - start);
                cout << "No. of comparisons: " << a << endl;
                cout << fixed << "Time Taken: " << setprecision(4) << duration.count() / 1000000.00 << " seconds" << endl;
                cout << endl;
                num = 1000000;
                Arr = new float[num];
                for(int i = 0; i < num; i++)
                {
                    Arr[i] = rand();
                }
                start = high_resolution_clock::now();
                a = shellSort(Arr,num);
                stop = high_resolution_clock::now();
                cout << "------10,00,000 numbers------\n";
                duration = duration_cast<microseconds>(stop - start);
                cout << "No. of comparisons: " << a << endl;
                cout << fixed << "Time Taken: " << setprecision(4) << duration.count() / 1000000.00 << " seconds" << endl;
                cout << endl;
                break;
            }
            case 4:
                cout << "\n------------EXITING-------------\n";
                exit(0);
		}
	}
    while(true);
}


