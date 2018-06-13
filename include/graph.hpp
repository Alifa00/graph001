#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

class Graph
{
private:
    vector<vector<unsigned> > graph;
    vector<unsigned> result;
    unsigned N;

public:
    Graph()
    {
        N = 0;
    }

    ~Graph()
    {
        N = 0;
    }

    Graph(vector<vector<unsigned>>const & input)
    {
        for (unsigned int i = 0; i < input.size(); ++i)
        {
            for (const auto& j : input[i])
            {
                if ( j >= input.size())
                    throw length_error("fail");
            }
        }
        graph = input;
        N = graph.size();
    }

    void read(istringstream& stream)
    {
        graph.clear();
        string stroka;
        while (getline(stream, stroka))
        {
            istringstream stream(stroka);
            unsigned n;
            char op;
            if (stream >> n && stream >> op && op == ':')
            {
                N = n + 1;
                int value;
                vector<unsigned> time;
                while (stream >> value)
                {
                    time.push_back(value);
                }
                graph.push_back(time);
            }
        }
    }

    Graph(Graph const & other)
    {
        N = other.N;
        graph = other.graph;
        if (!(other.result.empty()))
            result = other.result;
    }

    Graph & operator=(Graph const & other)
    {
        if (this != &other)
        {
            N = other.N;
            graph = other.graph;
            if (!other.result.empty())
                result = other.result;
        }
        return (*this);
    }

    void bfs(unsigned index)
    {
        vector<bool> run_;
        result.clear();
        for (unsigned i = 0; i < N; ++i)
        {
            run_.push_back(false);
        }
        bfs_help(index, run_);
    }

    void bfs_help(unsigned index, vector<bool>& run_)
	{
		int n = 0;
	
		run_[index] = true;
		result.push_back(index);
		   while (n < N) {
			   n++;
			   for (const auto& i : graph[index])
			   {
				   if (!(run_[i]))
				   {
					   result.push_back(i);
					   run_[i] = true;
				   }
				   
			   }
			   index = result[n];
		   }
	}

    void print_result(ostream& stream) const
    {
        for (unsigned i : result)
            stream << "->" << i;
    }

    void print_graph(ostream& stream) const
    {
        for (unsigned i = 0; i < N; i++)
        {
            stream << i << ":";
            for (const auto j : graph[i])
            {
                stream << j << " ";
            }
            stream << endl;
        }
    }
};
