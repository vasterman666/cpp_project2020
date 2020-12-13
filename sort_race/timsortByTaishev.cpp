#include <vector> 

template<typename T>
void timsort(std::vector<T>&);

template<typename T>
void merge(std::vector<T>&, int, int, int);

template<typename T>
void binaryInsertionSort(std::vector<T>&, int, int); 

template<typename T>
int binarySearch(std::vector<T>&, int, int, int);
int getminrun(int);

template<typename T>
std::vector<T> tim_sort(std::vector<T> v)
{
	timsort(v);
	return v;
}

template<typename T>
void timsort(std::vector<T>& v)
{
    int n = v.size();
    int minrun = getminrun(n);
    int left = 0;
    std::vector<std::pair<int, int>> p;
    while (n > 0)
    {
        if (n < 64)
        {
            binaryInsertionSort(v, left, v.size() - 1);
            p.push_back(std::make_pair(left, v.size() - 1));
            n = 0;
        }
        else
        {
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
                    T t = v.at(left + i);
                    v.at(left + i) = v.at(right - i - 1);
                    v.at(right - i - 1) = t;
                }
            }
            while (runsize <= minrun)
            {
                runsize++;
                right++;
            }
            //»нтервал - индекс на первый и последний элементы
            binaryInsertionSort(v, left, right - 1);
            p.push_back(std::make_pair(left, right - 1));
            
            left = right;
            n -= runsize;
        }
    }

    while (p.size() > 2)
    {
        for (int i = 0; i + 1 < p.size(); i++)
        {
            merge(v, p.at(i).first, p.at(i + 1).first, p.at(i + 1).second);
            p.at(i).second = p.at(i + 1).second;
            p.erase(p.begin() + i + 1);
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
            j++;
        }
        else
        {
            v.at(j) = v.at(second);
            second++;
            j++;
        }
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
void binaryInsertionSort(std::vector<T>& v, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        double t = v.at(i);
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
