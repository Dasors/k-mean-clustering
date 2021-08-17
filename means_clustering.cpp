#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>

/*P is the standard deviation factor: 
   Use to adjust the algorithm*/
#define P 1

int sum(std::vector<int> vec)
{
    int E=0;
    for (int i = 0; i < vec.size() ; i++){
        E += vec[i];
    }
    return E;
}

float calculateSD(std::vector<int> vec)
{
    float mean, standardDeviation = 0.0;

    int i;

    float E = sum(vec);

    mean = E/vec.size();

    for(i = 0; i < vec.size(); ++i)
        standardDeviation += pow(vec[i] - mean, 2);

    return sqrt(standardDeviation / vec.size());
}

struct greater
{
    template<class T>
    bool operator()(T const &a, T const &b) const { return a > b; }
};

std::vector<std::vector<int>*> means_clustering( std::vector<int> in)
{
    std::vector<std::vector<int>*> vec; //result

    std::sort(in.begin(), in.end(), greater());

    int E = sum(in);//Sum of all values
    int N = (int)trunc(sum(in)/in[0]); // Number of groups
    int value = E / N ; // reference value
    float dp = calculateSD(in)/P;

    for(int i = 0; i < N; i++){
        std::vector<int>* v = new std::vector<int>;
        vec.push_back(v);
    }

    int pos_0 = 0;
    while(in.size() > 0){
        vec[pos_0]->push_back(in[0]);
        in.erase(in.begin());
        int pos_1 = 0;

        while((sum(*vec[pos_0]) <= value) && (pos_1 < in.size())){
            if( (sum(*vec[pos_0]) + in[pos_1]) <=  (value + dp)){
                vec[pos_0]->push_back(in[pos_1]);
                in.erase(in.begin() + pos_1);
            }
            else{
                pos_1++;
            }
        }
        
        if((pos_0+1) <  N){
            pos_0++;
        }
        else{
            std::vector<int>* v = new std::vector<int>;
            vec.push_back(v);
            N = N+1;
        }
    }
    return vec; 
}

int main(void)
{
    /*Input examples*/
    std::vector<int> in = {1,3,7,1,8};
    std::vector<int> in1 = {8,7,3,1,1,1};
    std::vector<int> in2 = {8,7,3,3,1,1,1};
    std::vector<int> in3 = {5,5,3,3,2,2,2,1,1};
    std::vector<int> in4 = {10,9,8,7,6,5,4,3,2,1};
    std::vector<int> in5 = {5,5,5,5,5,5,5,5};
    std::vector<int> in6 = {10,10,10,5,2};
    std::vector<int> in7 = {1300,1000,1000,500,200,11465,11541,6546,8797,5465,6544,8787,10,646,9797,7878,5454,554,5456,556,9777,9898,9989,454,454,6847,98};

    std::vector<std::vector<int>*> result_vecs = means_clustering(in7);

    /*printing result*/
    for(int j=0; j<result_vecs.size(); j++){
        for(int i = 0; i < (*result_vecs[j]).size(); i++){
            std::cout << "\n Vec" << j << " = " << (*result_vecs[j])[i];
        }
    }

    return 0; 
}