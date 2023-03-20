#include <iostream>
using namespace std;

class Neuron
{
public:
    Neuron()
    {
        weight = 1;
        last_error = 1.1;
        smoothing = 0.001;
    }

    float get_last_error()
    {
        return last_error;
    }

    void set_smoothing(float new_smoothing)
    {
        smoothing = new_smoothing;
    }
    float get_smoothing()
    {
        return smoothing;
    }

    float get_weight()
    {
        return weight;
    }

    float proccess_data(float input_data)
    {
        return input_data * weight;
    }

    void train(float input_data, float ExpectedResult)
    {
        float result_now = input_data * weight;

        last_error = float(ExpectedResult) - float(result_now);
        float correction = (last_error / result_now) * smoothing;

        weight += correction;
    }

    void training(float task, float ans)
    {
        int iteractions = 0;
        while (check_training())
        {   
            iteractions++;
            train(task, ans);
            cout << "Epoh: " << iteractions << " | Weight: " << get_weight() << endl;
        }
    }

    bool check_training()
    {
        if (last_error > smoothing || last_error < -smoothing)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

private:
    float weight;
    float last_error;
    float smoothing;
};

int main()
{
    Neuron neuron;
    float task = 1;
    float ans = 1;

    int iteraction = 0;

    cout << "Traning task >>";
    cin >> task;
    cout << "Traning ans >>";
    cin >> ans;

    cout << "Start traning." << endl;

    neuron.training(task, ans);
    neuron.set_smoothing(0.001);
    
    int right_ans = 00;
    
    while (true)
    {
        cout << "task> ";
        cin >> task;
        ans = neuron.proccess_data(task);
        cout << "------------" << endl;
        cout << ans << " | " << round(ans) << endl;
        cout << "------------" << endl;
        cout << "Right ans ( 0 for skip ): ";
        cin >> right_ans;
        if (right_ans != 0)
        {
            neuron.training(task, right_ans);
        }
        cout << "Weight: " << neuron.get_weight() << endl;
    }
}
