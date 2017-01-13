//
// Created by cat on 10/16/16.
//

#include "Geometric.h"
using namespace std;

default_random_engine generator;
uniform_real_distribution<double> distribution(0.0, 1.0);

Geometric::Geometric() {}

Geometric::~Geometric() {}

unsigned int Geometric::GetRandom(double p)
{
    double uniform_num = distribution(generator);
    unsigned int rand_num = (unsigned int)(log(uniform_num) / log(1 - p));
    return rand_num;
}

double Geometric::Gistogram(unsigned int number_experiments, std::string out_txt)
{
    int n_intervals = 10; // number of intervals
    int p[n_intervals];
    fill_n(p, n_intervals, 0);
    map<unsigned int, int> m;

    for (int i = 0; i < number_experiments; ++i)
    {
        unsigned int number = Geometric::GetRandom(0.3);
        if (m.find(number) == m.end())
        {
            m.insert(pair<unsigned int, int>(number, 1));
        }
        else
        {
            m[number]++;
        }
    }
    map<unsigned int, int>::iterator it_begin = m.begin();
    map<unsigned int, int>::iterator it_end = m.end();
    --it_end;
    double step = (it_end->first - it_begin->first) / n_intervals;

    double prob = 0;
    double entropy = 0;
    for (map<unsigned int, int>::iterator it = m.begin(); it != m.end(); ++it)
    {
        prob = it->second / static_cast<double>(number_experiments);
        entropy += (-1 * prob * log2(prob));
        double tmp = prob / step;
        AppendToFile(out_txt, it->first, prob);
    }
    entropy /= m.size();
    return entropy;
}

void Geometric::GetPlot(const string &config_path, const string &png_path, const string &source_path)
{
    AppendToFile(config_path, "set terminal  png size 512,512 font 'Verdana, 10'");
    AppendToFile(config_path, "set nokey");
    AppendToFile(config_path, "set title \"Geometric distribution\"");
    AppendToFile(config_path, "set output '" + png_path + "'");
    AppendToFile(config_path, "set ylabel \"PDF\"");
    AppendToFile(config_path, "set yrange [0:0.35]");
    AppendToFile(config_path, "set xlabel \"Random numbers\"");
    AppendToFile(config_path, "set xrange [0:40]");
    AppendToFile(config_path, "set xtics 1");
    AppendToFile(config_path, "set grid xtics ytics");
    string command = string("plot '") + source_path + "' using 1:2 lw 2 lt rgb 'blue'";
    AppendToFile(config_path, command);
    system(string("gnuplot \"" + config_path + "\"").c_str());
}