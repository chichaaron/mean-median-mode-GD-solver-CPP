#include <iostream>
using namespace std;

void for_mean(float frequency[], float fx[], int num_of_class){
    float sum_of_frequency = 0;
    float sum_of_fx = 0;
    for(int i = 0; i < num_of_class; i++){
        sum_of_frequency += frequency[i];
        sum_of_fx += fx[i];
    }
    cout << "\nn = " << sum_of_frequency << endl;
    cout << "summation of fx = " << sum_of_fx << endl;

    float mean = sum_of_fx / sum_of_frequency;
    cout << "\nMean = " << mean << endl;

}    

void for_median(float low_class[], float high_class[], float frequency[], int num_of_class, float cf[]){
    float sum_of_frequency = 0;
    float n_divide_2;
        for(int j = 0; j < num_of_class; j++){ //This will add all the frequency value
            sum_of_frequency += frequency[j];
        }

    //This formula will determine which class is the median if it is under the scope of a certain cf
    n_divide_2 = sum_of_frequency / 2; 
    
    float median = 0;
        //if n_divide_2 is less than the cf of the first class; then execute the body
        if(n_divide_2 <= cf[0]){ 
            float lmd = low_class[0] - 0.5;
            cf[0];
            float fmd = frequency[0];
            float interval = high_class[0] + 1 - low_class[0];

            median = (((n_divide_2 - cf[0]) / fmd) * interval);
        }

    cf[-1] = cf[0];
    for(int i = 0; i < num_of_class; i++){
        //this if statements will determine which set of class we should get every value we put in our formula
        if(n_divide_2 > cf[i] && n_divide_2 <= cf[i + 1]){ 
            float lmd = low_class[i + 1] - 0.5; // this is lmd
            cf[i - 1]; // this is <cf
            float fmd = frequency[i + 1]; //this is fmd
            float interval = high_class[i] + 1 - low_class[i]; // this is the interval

            median = lmd + (((n_divide_2 - cf[i]) / fmd) * interval);
        }
    }
        cout << "Median = " << median << endl;
}

int modal_class(float frequency[], int num_of_class){
    int max = 0;
    for(int i = 0; i < num_of_class; i++){
            if(max < frequency[i]){
                max = frequency[i];
            }
    }
    return max;
}

void for_mode(float frequency[], int num_of_class, float low_class[], float high_class[]){
    float lmo;
    float delta_one;
    float delta_two;
    float interval;
    float delta;
    float mode;
    frequency[-1] = 0;
    for(int i = 0; i < num_of_class; i++){
    lmo = low_class[i] - 0.5;
    delta_one = frequency[i] - frequency[i - 1];
    delta_two = frequency[i] - frequency[i + 1];
    interval = high_class[i] + 1 - low_class[i];
        if(modal_class(frequency, num_of_class) == frequency[i]){
            delta = delta_one + delta_two;
            mode = lmo + ((delta_one / delta) * interval);
        }
    }
    cout << "Mode = " << mode << endl;
}

int main(){
    cout << "\nThis is a solver for mean, median, and mode value.\n";
    cout << "Placing the set of classes should be from LOWEST to HIGHEST.\n\n";
    int num_of_class;
    cout << "How many classes? ";
    cin >> num_of_class;
    float arr_low[num_of_class];
    float arr_high[num_of_class];
    float arr_frequency[num_of_class];
    float arr_for_x[num_of_class];
    float arr_for_fx[num_of_class];
    float arr_for_cf_a[num_of_class];
    arr_for_cf_a[-1] = 0;
    for(int i = 0; i < num_of_class; i++){
        cout << "\nEnter low class value: ";
            cin >> arr_low[i];
        cout << "Enter high class value: ";
            cin >> arr_high[i];
        cout << arr_low[i] << " - " << arr_high[i] << endl;  
        cout << "frequency: ";
            cin >> arr_frequency[i];
        arr_for_x[i] = (arr_low[i] + arr_high[i])/2;
        cout << "x = " << arr_for_x[i] << endl;
        arr_for_fx[i] = arr_for_x[i] * arr_frequency[i];
        cout << "fx = " << arr_for_fx[i] << endl;

        arr_for_cf_a[i] = arr_for_cf_a[i-1] + arr_frequency[i];
        cout << "cf = " << arr_for_cf_a[i] << endl;
    }

    for_mean(arr_frequency, arr_for_fx, num_of_class);
    for_median(arr_low, arr_high, arr_frequency, num_of_class, arr_for_cf_a);
    for_mode(arr_frequency, num_of_class, arr_low, arr_high);


    return 0;
}