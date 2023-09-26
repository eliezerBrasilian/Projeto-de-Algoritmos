#include <iostream>
#include <chrono>
using namespace std::chrono;
using namespace std;
class Tempo
{
public:
    time_point<high_resolution_clock> iniciaContagem();
    milliseconds interrompeContagem(time_point<high_resolution_clock>);
};

time_point<high_resolution_clock> Tempo::iniciaContagem()
{
    auto start_time = high_resolution_clock::now();  // Início da contagem de tempo
    return start_time;
}

milliseconds Tempo::interrompeContagem(time_point<high_resolution_clock> start_time)
{
    auto end_time = high_resolution_clock::now();  // Fim da contagem de tempo
    auto duration = duration_cast<milliseconds>(end_time - start_time);  // Calcula a diferença

    //cout << "Tempo gasto: " << duration.count() << " milissegundos" << endl;

    return duration;
}
