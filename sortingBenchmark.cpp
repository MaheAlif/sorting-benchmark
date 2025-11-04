#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>
#include <string>
using namespace std;

// Sorting algorithms
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
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge
        int n1 = mid - left + 1;
        int n2 = right - mid;
        int *L = new int[n1];
        int *R = new int[n2];
        
        for (int i = 0; i < n1; i++)
            L[i] = arr[left + i];
        for (int j = 0; j < n2; j++)
            R[j] = arr[mid + 1 + j];
        
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }
        
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
        
        delete[] L;
        delete[] R;
    }
}

int main() {
    int numCount;
    
    cout << "=====================================" << endl;
    cout << "   SORTING ALGORITHM BENCHMARK" << endl;
    cout << "=====================================" << endl;
    cout << "\nEnter number of random numbers to generate" << endl;
    cout << "(Press Enter for default: 100000): ";
    
    string input;
    getline(cin, input);
    
    if (input.empty()) {
        numCount = 100000;
    } else {
        numCount = stoi(input);
    }
    
    cout << "\nGenerating " << numCount << " random numbers..." << endl;
    
    // Generate random numbers
    srand(static_cast<unsigned int>(time(nullptr)));
    int *originalArray = new int[numCount];
    
    for (int i = 0; i < numCount; i++) {
        originalArray[i] = rand();
    }
    
    cout << "Random numbers generated successfully!" << endl;
    
    // Choose sorting algorithm
    cout << "\n=====================================" << endl;
    cout << "Choose a sorting algorithm:" << endl;
    cout << "=====================================" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Selection Sort" << endl;
    cout << "4. Quick Sort" << endl;
    cout << "5. Merge Sort" << endl;
    cout << "\nEnter your choice (1-5): ";
    
    int choice;
    cin >> choice;
    
    // Create a copy of the array for sorting
    int *sortArray = new int[numCount];
    for (int i = 0; i < numCount; i++) {
        sortArray[i] = originalArray[i];
    }
    
    string algorithmName;
    auto start = chrono::high_resolution_clock::now();
    
    switch(choice) {
        case 1:
            algorithmName = "Bubble Sort";
            cout << "\nRunning Bubble Sort..." << endl;
            bubbleSort(sortArray, numCount);
            break;
        case 2:
            algorithmName = "Insertion Sort";
            cout << "\nRunning Insertion Sort..." << endl;
            insertionSort(sortArray, numCount);
            break;
        case 3:
            algorithmName = "Selection Sort";
            cout << "\nRunning Selection Sort..." << endl;
            selectionSort(sortArray, numCount);
            break;
        case 4:
            algorithmName = "Quick Sort";
            cout << "\nRunning Quick Sort..." << endl;
            quickSort(sortArray, 0, numCount - 1);
            break;
        case 5:
            algorithmName = "Merge Sort";
            cout << "\nRunning Merge Sort..." << endl;
            mergeSort(sortArray, 0, numCount - 1);
            break;
        default:
            cout << "Invalid choice!" << endl;
            delete[] originalArray;
            delete[] sortArray;
            return 1;
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    
    cout << "\n=====================================" << endl;
    cout << "BENCHMARK RESULTS" << endl;
    cout << "=====================================" << endl;
    cout << "Algorithm: " << algorithmName << endl;
    cout << "Numbers sorted: " << numCount << endl;
    cout << "Time taken: " << duration.count() << " ms" << endl;
    cout << "=====================================" << endl;
    
    // Save results to file
    ofstream resultFile;
    resultFile.open("benchmark_results.txt", ios::app);
    
    // Get current date/time
    time_t now = time(0);
    char* dt = ctime(&now);
    
    resultFile << "=====================================" << endl;
    resultFile << "Date/Time: " << dt;
    resultFile << "Algorithm: " << algorithmName << endl;
    resultFile << "Numbers sorted: " << numCount << endl;
    resultFile << "Time taken: " << duration.count() << " ms" << endl;
    resultFile << "=====================================" << endl << endl;
    resultFile.close();
    
    cout << "\nResults saved to benchmark_results.txt" << endl;
    
    // Optionally save sorted array to file
    char saveArray;
    cout << "\nDo you want to save the sorted array to a file? (y/n): ";
    cin >> saveArray;
    
    if (saveArray == 'y' || saveArray == 'Y') {
        string filename = "sorted_output_" + algorithmName + ".txt";
        // Remove spaces from filename
        filename.erase(remove(filename.begin(), filename.end(), ' '), filename.end());
        
        ofstream outputFile;
        outputFile.open(filename);
        
        for (int i = 0; i < numCount; i++) {
            outputFile << sortArray[i] << endl;
        }
        
        outputFile.close();
        cout << "Sorted array saved to " << filename << endl;
    }
    
    // Cleanup
    delete[] originalArray;
    delete[] sortArray;
    
    return 0;
}
