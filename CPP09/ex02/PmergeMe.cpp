#include "PmergeMe.hpp"

void printPair(std::pair<int, int> p)
{
    std::cout << p.first << " ";
}

template <typename T>
void merge(T& ct, size_t start, size_t middle, size_t end)
{
    (void)ct;
    (void)start;
    (void) middle;
    (void)end;
    return;
}

static void merge(std::vector<std::pair<int, int> >& v);

std::vector<std::pair<int, int> > vectorSort(std::string str)
{
    std::vector<std::pair<int, int> > v;

    int extra = initializeContainer<std::vector<std::pair<int, int> > > (v, str);
    std::sort(v.begin(), v.end());
    merge(v);
    if (extra != -1)
    {
        std::vector<std::pair<int, int> >::iterator i = v.begin();
        while (i != v.end() && (*i).first < extra)
            i++;
        v.insert(i, std::make_pair(extra, -1));
    }
    for(size_t i = 0; i < v.size(); i++)
    {
        printPair(v[i]);
    }
    std::cout << std::endl;
    return (v);
}

static void merge(std::vector<std::pair<int, int> >& v)
{
    int tmp;

    for (unsigned long int i = 0; i < v.size(); i++)
    {
        if (v[i].second != -1)
        {
            tmp = v[i].second;
            std::vector<std::pair<int, int> >::iterator aux = v.begin() + i;
            while (aux != v.end() && aux->first <= tmp)
                aux++;
            v.insert(aux, std::make_pair(tmp, -1));
        }
    }
}

static void merge (std::list<std::pair<int,int> >& lst);

std::list<std::pair<int, int> >	listSort(std::string str)
{
	std::list<std::pair<int,int> >	lst;

	int	extra = initializeContainer<std::list<std::pair<int,int> > >(lst, str);
	lst.sort();
	merge(lst);
	if (extra != -1)
	{
		std::list<std::pair<int, int> >::iterator i = lst.begin();
		while (i != lst.end()  && (*i).first < extra)
			++i;
		lst.insert(i, std::make_pair(extra, -1));
	}
	return (lst);
}

static void merge (std::list<std::pair<int,int> >& lst)
{
	int	tmp;
	for (std::list<std::pair<int,int> >::iterator it = lst.begin();
			it != lst.end(); ++it)
	{
		if ((*it).second != -1)
		{
			tmp = (*it).second;
			std::list<std::pair<int,int> >::iterator aux = it;
			while (aux != lst.end() && (*aux).first < tmp)
				++aux;
			lst.insert(aux, std::make_pair(tmp, -1));
		}
	}
}
