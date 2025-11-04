#include<bits/stdc++.h>
#include<fstream>
#include<string>
#include<chrono>
using namespace std;

void print(int *data, int a) {
	int i;
	for(i= 0; i<a; i++) {
		printf("%d ",data[i]);
	}
	printf("\n\n");
	return;
}

void bubbleSort(int *data, int n) {
	int i, j, temp;

	for(i = 0; i < n-1; i++) {
		for(j = 0; j < n-1-i; j++) {
			if(data[j] > data[j+1]) {
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
}


void insertionSort(int *data, int n) {
	int i, j, key;
	for(i = 1; i < n; i++) {
		key = data[i];
		for(j = i-1; j >= 0 && data[j] > key; j--) {
			data[j+1] = data[j];
		}
		data[j+1] = key;
	}
	return;

}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}


int partition(int *arr, int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



int main() {
    // ofstream myFile;
    // myFile.open("inputSomething.txt");
    // // if(myFile.is_open()) {
    // //     myFile << "It should've been created!\n";
    // //     myFile.close();
    // // }
    // myFile << "It should've created the file!" << endl;
    // myFile.close(); 


    ifstream myFile;
    myFile.open("inputSomething2.txt");
    int number, count = 0;
    //cout << "Numbers from file: ";
    while(myFile >> number) {
        //cout << number << " ";
        count++;
    }
    cout << "\nCount : " << count << endl;
    myFile.close();

    myFile.open("inputSomething2.txt");

    int *myArray = new int[count];
    int j=0,n;
    while(myFile >> n) {
        myArray[j] = n;
        //cout << n << " ";
        j++;
    }

    //for(int i=0; i<count; i++) {
        //cout << "myArray[" << i << "] -> " << myArray[i] << endl;
    //}
    myFile.close(); 
    
    cout << "\nChoose an option to sort : \n1. Bubble sort\n2. Insertion sort\n3. Selection sort\n4. Quick sort\n" << endl;
    int choice = 0;
    cin >> choice;
    if(choice == 1) {
        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(myArray,count);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        cout << "\nAfter bubble sort : " << endl;
        // print(myArray,count);
        cout << "\nRuntime : " << duration.count() << " ms" << endl;

        ofstream myFile;
        myFile.open("outputBubbleSort3.txt");

        myFile << "\nAfter bubble sort : " << endl;
        myFile << "\nRuntime : " << duration.count() << " ms" << endl;

        for(int i=0; i<count; i++) {
            myFile << myArray[i] << endl;
        }
        myFile.close();
        cout << "Output has been updated in the OutputSomething file!" << endl;

    } else if(choice == 2) {
        auto start = std::chrono::high_resolution_clock::now();
        insertionSort(myArray,count);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        cout << "\nAfter insertion sort : " << endl;
        // print(myArray,count);
        cout << "\nRuntime : " << duration.count() << " ms" << endl;

        ofstream myFile;
        myFile.open("outputInsertionSort.txt");

        myFile << "\nAfter insertion sort : " << endl;
        myFile << "\nRuntime : " << duration.count() << " ms" << endl;

        for(int i=0; i<count; i++) {
            myFile << myArray[i] << endl;
        }
        myFile.close();
        cout << "Output has been updated in the OutputSomething file!" << endl;

    } else if(choice == 3) {
        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(myArray,count);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        cout << "\nAfter selection sort : " << endl;
        // print(myArray,count);
        cout << "\nRuntime : " << duration.count() << " ms" << endl;

        ofstream myFile;
        myFile.open("outputSelectionSort.txt");

        myFile << "\nAfter selection sort : " << endl;
        myFile << "\nRuntime : " << duration.count() << " ms" << endl;

        for(int i=0; i<count; i++) {
            myFile << myArray[i] << endl;
        }
        myFile.close();
        cout << "Output has been updated in the OutputSomething file!" << endl;

    } else if(choice == 4) {
        auto start = std::chrono::high_resolution_clock::now();
        quickSort(myArray,0,count-1);
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

        cout << "\nAfter quick sort : " << endl;
        // print(myArray,count);
        cout << "\nRuntime : " << duration.count() << " ms" << endl;

        ofstream myFile;
        myFile.open("outputQuickSort7.txt");

        myFile << "\nAfter quick sort : " << endl;
        myFile << "\nRuntime : " << duration.count() << " ms" << endl;

        for(int i=0; i<count; i++) {
            myFile << myArray[i] << endl;
        }
        myFile.close();
        cout << "Output has been updated in the OutputSomething file!" << endl;
    }
}