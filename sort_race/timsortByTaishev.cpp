#include <vector>

#define PAIR_SIZE(p) p.second - p.first

template<typename T>
void timsort(std::vector<T>&);

template<typename T>
void merge(std::vector<T>&, int, int, int);

template<typename T>
void insertionSort(std::vector<T>&, int, int); 

template<typename T>
void binaryInsertionSort(std::vector<T>&, int, int); 

template<typename T>
int binarySearch(std::vector<T>&, int, int, int); 
int getminrun1(int); 

template<typename T>
std::vector<T> timsortByTaishev(std::vector<T> v)
{
    timsort(v);
    return v;
}

template<typename T>
void timsort(std::vector<T>& v)
{
    int n = v.size();
    int left = 0;
    std::vector<std::pair<int, int>> p;
    while (n > 0)
    {
        if (n < 64)
        {
            if(v.size() > 50000)
                insertionSort(v, left, v.size() - 1);
            else
                binaryInsertionSort(v, left, v.size() - 1);
            p.push_back(std::make_pair(left, v.size() - 1));
            n = 0;
        }
        else
        {
            int minrun = getminrun1(n);
            bool increasing = (v.at(left) <= v.at(left + 1)) ? true : false;
            int runsize = 2;
            int right = left + 2;
            while ((increasing && v.at(right - 1) <= v.at(right)) || (!increasing && v.at(right - 1) >= v.at(right)))
            {
                right++;
                runsize++;
            }
            if (!increasing)
            {
                for (int i = 0; i < (right - left) / 2; i++)
                {
                    double t = v.at(left + i);
                    v.at(left + i) = v.at(right - i - 1);
                    v.at(right - i - 1) = t;
                }
            }
            while (runsize <= minrun)
            {
                runsize++;
                right++;
            }
            //Интервал - индекс на первый и последний элементы
            if (v.size() > 50000)
                insertionSort(v, left, right - 1);
            else
                binaryInsertionSort(v, left, right - 1);
            p.push_back(std::make_pair(left, right - 1));
            left = right;
            n -= runsize;
        }
    }
    while (p.size() >= 3)
    {
        auto z = p.back();
        p.pop_back();
        auto y = p.back();
        p.pop_back();
        auto x = p.back();
        p.pop_back();
        if (PAIR_SIZE(x) > PAIR_SIZE(y) + PAIR_SIZE(z) && PAIR_SIZE(y) > PAIR_SIZE(z))
        {
            merge(v, y.first, z.first, z.second);
            y.second = z.second;
            p.push_back(x);
            p.push_back(y);
        }
        else
        {
            if (PAIR_SIZE(x) > PAIR_SIZE(z))
            {
                merge(v, y.first, z.first, z.second);
                y.second = z.second;
                p.push_back(x);
                p.push_back(y);
            }
            else
            {
                merge(v, x.first, y.first, y.second);
                x.second = y.second;
                p.push_back(x);
                p.push_back(z);
            }
        }
    }
    if (p.size() == 2)
        merge(v, p.at(0).first, p.at(1).first, p.at(1).second);
}

template<typename T>
void merge(std::vector<T>&v, int left, int middle, int right)
{
    std::vector<T> t(middle - left);
    for (int i = 0; i < t.size(); i++)
        t.at(i) = v.at(left + i);
    int first = 0;
    int second = middle;
    int j = left;
    while (first < t.size() && second < right + 1)
    {
        if (t.at(first) <= v.at(second))
        {
            v.at(j) = t.at(first);
            first++;
        }
        else
        {
            v.at(j) = v.at(second);
            second++;
        }
        j++;
    }
    while (first < t.size())
    {
        v.at(j) = t.at(first);
        first++;
        j++;
    }
    while (second < right + 1)
    {
        v.at(j) = v.at(second);
        second++;
        j++;
    }
}

template<typename T>
void insertionSort(std::vector<T>& v, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        T t = v.at(i);
        int j = i - 1;
        while (j >= 0 && v.at(j) > t)
        {
            v.at(j + 1) = v.at(j);
            j--;
        }
        v.at(j + 1) = t;
    }
}

template<typename T>
void binaryInsertionSort(std::vector<T>& v, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        T t = v.at(i);
        int j = i - 1;
        int pos = binarySearch(v, t, left, i - 1);
        while (j >= pos)
        {
            v.at(j + 1) = v.at(j);
            j--;
        }
        v.at(j + 1) = t;
    }
}

template<typename T>
int binarySearch(std::vector<T>& v, int ziel, int left, int right)
{
    int middle = (left + right) / 2;

    if (left >= right)
        return (ziel >= v.at(left)) ? (left + 1) : left;
    if (ziel == v.at(middle))
        return middle + 1;
    else if (ziel < v.at(middle))
        return binarySearch(v, ziel, left, middle - 1);
    else
        return binarySearch(v, ziel, middle + 1, right);
}

int getminrun1(int n)
{
    int r = 0;
    while (n >= 64)
    {
        r |= n & 1;
        n >>= 1;
    }
    return n + r;
}
