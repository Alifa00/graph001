#include <catch.hpp>
#include <sstream>

#include "graph.hpp"

TEST_CASE("num0")
{
    Graph graph({ { 1, 2, 6 }, { 0, 2, 3 }, { 0, 1 }, { 1, 4 }, { 3, 5 }, { 4, 6 }, { 0, 5 } });
    graph.bfs(0);
    ostringstream stream;
    graph.print_result(stream);
    string out = "->0->1->2->6->3->5->4";
    REQUIRE(out == stream.str());
}

TEST_CASE("num2")
{
    Graph graph({ { 1, 2, 6 }, { 0, 2, 3 }, { 0, 1 }, { 1, 4 }, { 3, 5 }, { 4, 6 }, { 0, 5 } });
    graph.bfs(2);
    ostringstream stream;
    graph.print_result(stream);
    string out = "->2->0->1->6->3->5->4";
    REQUIRE(out == stream.str());
}

TEST_CASE("num4")
{
    Graph graph({ { 1, 2, 6 }, { 0, 2, 3 }, { 0, 1 }, { 1, 4 }, { 3, 5 }, { 4, 6 }, { 0, 5 } });
    graph.bfs(4);
    ostringstream stream;
    graph.print_result(stream);
    string out = "->4->3->5->1->6->0->2";
    REQUIRE(out == stream.str());
}

TEST_CASE("constructor_1")
{
    Graph graph_1({ { 1, 2, 6 }, { 0, 2, 3 }, { 0, 1 }, { 1, 4 }, { 3, 5 }, { 4, 6 }, { 0, 5 } });
    graph_1.bfs(0);
    Graph graph(graph_1);
    ostringstream stream;
    graph.print_result(stream);
    string out = "->0->1->2->6->3->5->4";
    REQUIRE(out == stream.str());
}

TEST_CASE("construktor_2")
{
    Graph graph_1({ { 1, 2, 6 }, { 0, 2, 3 }, { 0, 1 }, { 1, 4 }, { 3, 5 }, { 4, 6 }, { 0, 5 } });
    graph_1.bfs(0);
    Graph graph;
    graph = graph_1;
    ostringstream stream;
    graph.print_result(stream);
    string out = "->0->1->2->6->3->5->4";
    REQUIRE(out == stream.str());
}

TEST_CASE("input_and_output")
{
    Graph graph;
    string input{ "0:1 2 6 \n"
                  "1:0 2 3 \n"
                  "2:0 1 \n"
                  "3:1 4 \n"
                  "4:3 5 \n"
                  "5:4 6 \n"
                  "6:0 5 \n" };
    istringstream in(input);
    graph.read(in);
    ostringstream stream;
    graph.print_graph(stream);
    REQUIRE(input == stream.str());
}

TEST_CASE("exception")
{
    bool success = false;
	try{
		Graph graph({ { 1, 2, 10 }, { 0, 2, 3 }, { 0, 1 }, { 1, 4 }, { 3, 5 }, { 4, 6 }, { 0, 5 } });
	}
	catch(std::length_error)
	{
		success=true;
	}
	REQUIRE(success);
}
