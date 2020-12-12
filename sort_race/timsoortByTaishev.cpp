#include <vector>
#include <utility>

#define PAIR_SIZE(x) x.second - x.first

void timsort(std::vector<double>&);
void insertion_sort(std::vector<double>&, int, int);
void merge(std::vector<double>& v, std::pair<int, int>, std::pair<int, int>);
int getminrun(int);

std::vector<double> sort(std::vector<double> v)
 {
    timsort(v);
	return v;
}

void timsort(std::vector<double>& v)
{
    std::vector<std::pair<int, int>> p;
    int n = 0;
    while (n < v.size())
    {
        int minrun = getminrun(v.size() - n);
        insertion_sort(v, n, n + minrun - 1);
        p.push_back(std::make_pair(n, n + minrun - 1));
        n += minrun;
    }
    while (p.size() > 2)
    {
        auto z = p.back();
        p.pop_back();
        auto y = p.back();
        p.pop_back();
        auto x = p.back();
        p.pop_back();

        if (PAIR_SIZE(x) > PAIR_SIZE(y) + PAIR_SIZE(z) && PAIR_SIZE(y) > PAIR_SIZE(z))
        {
            merge(v, y, z);
            y.second = z.second;
            p.push_back(x);
            p.push_back(y);
        }
        else
        {
            if (PAIR_SIZE(z) > PAIR_SIZE(x))
            {
                merge(v, x, y);
                x.second = y.second;
                p.push_back(x);
                p.push_back(z);
            }
            else
            {
                merge(v, y, z);
                y.second = z.second;
                p.push_back(x);
                p.push_back(y);
            }
        }
    }
    if (p.size() == 2)
    {
        auto y = p.back();
        p.pop_back();
        auto x = p.back();
        merge(v, x, y);
    }
}

void insertion_sort(std::vector<double>& v, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        double t = v.at(i);
        int j = i - 1;
        while (j >= left && v.at(j) > t)
        {
            v.at(j + 1) = v.at(j);
            j--;
        }
        v.at(j + 1) = t;
    }
}

void merge(std::vector<double>& v, std::pair<int, int> x, std::pair<int, int> y)
{;
    std::vector<double> t(x.second - x.first + 1);
    for (int i = 0; i < t.size(); i++)
        t.at(i) = v.at(x.first + i);

    int i = x.first;
    int j = 0;
    while (j < t.size() && y.first <= y.second)
    {
        if (t.at(j) <= v.at(y.first))
        {
            v.at(i) = t.at(j);
            i++;
            j++;
        }
        else
        {
            v.at(i) = v.at(y.first);
            i++;
            y.first++;
        }
    }
    while (j < t.size())
    {
        v.at(i) = t.at(j);
        i++;
        j++;
    }
    while (y.first <= y.second)
    {
        v.at(i) = v.at(y.first);
        i++;
        y.first++;
    }
}

int getminrun(int n)
{
    int r = 0;
    while (n >= 64) 
    {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}