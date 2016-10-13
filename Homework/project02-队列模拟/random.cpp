#ifndef RANDOM_H
#define RANDOM_H
using namespace std;

class Random {
 public:
        Random(bool pseudo = true);
        double random_real();
        int random_integer(int low, int high);
        int poisson(double mean);
 private:
        int reseed();
        int source;
        int multiply_to, add_on;
};

int Random::reseed() {
        source = (source + add_on) * multiply_to;
        return source;
}

Random::Random(bool pseudo) {
        if (pseudo) source = 1;
        else source = time(NULL) % INT_MAX;
        add_on = 1201;
        multiply_to = 3351;
}

double Random::random_real() {
        double max = INT_MAX + 1.0;
        double temp = reseed();
        while (temp < 0) 
                temp += INT_MAX;
        return temp / max;
}

int Random::random_integer(int low, int high) {
        if (low > high) {
                int temp = high;
                high = low;
                low = temp;
        }
        int result =  ((int)((high - low + 1) * random_real())) + low;
        return result;
}

int Random::poisson(double mean) {
        double limit = exp(-mean);
        double product = random_real();
        int count = 0;
        while (product > limit) {
                ++count;
                product *= random_real();
        }
        return count;
}

#endif
