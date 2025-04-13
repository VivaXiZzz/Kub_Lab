#include <iostream>
#include <vector>
#include <functional>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

typedef vector<double> State;
typedef function<State(double, const State&)> DerivativeFunc;

State operator+(const State& a, const State& b) {
    State res(a.size());
    for (size_t i = 0; i < a.size(); ++i) res[i] = a[i] + b[i];
    return res;
}

State operator*(const State& a, double c) {
    State res(a.size());
    for (size_t i = 0; i < a.size(); ++i) res[i] = a[i] * c;
    return res;
}

// метод Рунге-Кутты 4-го порядка
State rungeKutta4(DerivativeFunc f, double t, const State& y, double h) {
    State k1 = f(t, y);
    State k2 = f(t + h/2, y + k1 * (h/2));
    State k3 = f(t + h/2, y + k2 * (h/2));
    State k4 = f(t + h, y + k3 * h);
    return y + (k1 + k2*2.0 + k3*2.0 + k4) * (h/6.0);
}

// сам метод Адамса-Мультона 5-го порядка
State adamsMoulton5Step(DerivativeFunc f, double t, const vector<State>& prev_states, 
                       double h, double eps = 1e-7, int max_iter = 50) {
    const State& yn   = prev_states[0];
    const State& yn1  = prev_states[1];
    const State& yn2  = prev_states[2];
    const State& yn3  = prev_states[3];
    
    State y_pred = yn3;
    for (int iter = 0; iter < max_iter; ++iter) {
        State term = 
            f(t + 4*h, y_pred) * (251.0/720.0) +
            f(t + 3*h, yn3)    * (646.0/720.0) +
            f(t + 2*h, yn2)    * (-264.0/720.0) +
            f(t + h, yn1)      * (106.0/720.0) +
            f(t, yn)           * (-19.0/720.0);
        
        State y_next = yn3 + term * h;
        
        double max_diff = 0.0;
        for (size_t i = 0; i < y_next.size(); ++i) {
            max_diff = max(max_diff, abs(y_next[i] - y_pred[i]));
        }
        if (max_diff < eps) break;
        y_pred = y_next;
    }
    return y_pred;
}

// система уравнений
DerivativeFunc testSystem() {
    return [](double t, const State& y) -> State {
        return { 
            y[1] - y[0],  // x' = y - x //1
            -y[0] - y[1] // y' = -x - y
            //y[1] + exp(-t), // 2
            //-y[0] + sin(t)
            }; 
    };
}

// точное решение
pair<double, double> exactSolution(double t) {
    double exp_t = exp(-t);
    return { exp_t*(cos(t) + sin(t)), exp_t*(cos(t) - sin(t)) };// 1
    //return { -exp_t*0.5 + sin(t) - 0.5*(t-3)*cos(t), 0.5*(-exp_t+(t-3)*sin(t)+cos(t))};// 2
}

void solve(DerivativeFunc f, const State& y0, double h, int steps, const string& filename) {
    vector<State> solution = {y0};
    
    for (int i = 0; i < 4; ++i) {
        solution.push_back(rungeKutta4(f, i*h, solution[i], h));
    }
    
    for (int step = 0; step < steps; ++step) {
        vector<State> prev = {
            solution[solution.size() - 4],
            solution[solution.size() - 3],
            solution[solution.size() - 2],
            solution.back()
        };
        State y_next = adamsMoulton5Step(f, (solution.size()-4)*h, prev, h);
        solution.push_back(y_next);
    }
    
    ofstream out(filename);
    out << fixed << setprecision(9);
    for (size_t i = 0; i < solution.size(); ++i) {
        auto exact = exactSolution(i*h);
        out << i*h << " " 
            << solution[i][0] << " " << exact.first << " "
            << solution[i][1] << " " << exact.second << "\n";
    }
}

int main() {
    State y0 = {1.0, 1.0}; // начальные условия для 1
    //State y1 = {1.0, 0.0}; // начальные условия для 2
    
    //h=0,5|1,0
    solve(testSystem(), y0, 1, 5, "h01.txt");
    solve(testSystem(), y0, 0.5, 10, "h005.txt");
    
    cout << "Результаты сохранены в h01.txt и h005.txt\n";
    return 0;
}