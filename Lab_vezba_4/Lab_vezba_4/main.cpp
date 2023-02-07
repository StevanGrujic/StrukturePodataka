#include"Graph.h"

int main()
{
	Graph g;
	g.addNode(6);
	g.addNode(5);
	g.addNode(4);
	g.addNode(3);
	g.addNode(2);
	g.addNode(1);
	g.addEdge(1, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 5);
	g.addEdge(2, 1);
	g.addEdge(3, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 1);
	g.addEdge(4, 6);
	cout << "-------PRINT METODA---------" << endl;
	g.print();
	cout << "-----------OBILAZAK GRAFA PO DUBINI---------------" << endl;
	g.dfs(1);
	cout << "-------BROJ NEORIJENTISANIH GRANA U GRAFU-----------" << endl;
	cout << g.bidirectedEdges() << endl;
	cout << endl;
	cout << "--------NAJKRACI PUT IZMEDJU CVOROVA 1 I 6-----------" << endl;
	g.shortestPath(1, 6);
	cout << endl;
	cout << endl;
	cout << "--------NAJKRACI PUT IZMEDJU CVOROVA 1 I 2-----------" << endl;
	g.shortestPath(1, 2);
	cout << endl;
	cout << "--------NAJKRACI PUT IZMEDJU CVOROVA 3 I 5-----------" << endl;
	g.shortestPath(3, 5);
	cout << endl;
	cout << endl;
	Graph g1;
	g1.addNode(6);
	g1.addNode(5);
	g1.addNode(4);
	g1.addNode(3);
	g1.addNode(2);
	g1.addNode(1);
	g1.addEdge(1,4);
	g1.addEdge(4,1);
	g1.addEdge(5,1);
	g1.addEdge(4,5);
	g1.addEdge(5,4);
	g1.addEdge(5,2);
	g1.addEdge(2,3);
	g1.addEdge(3,6);
	g1.addEdge(6,3);
	g1.addEdge(3,5);
	g1.addEdge(5,3);
	cout << "-----------------DRUGI GRAF-------------------" << endl;
	cout << endl;
	cout << "-------BROJ NEORIJENTISANIH GRANA U DRUGOM GRAFU-----------" << endl;
	cout<<g1.bidirectedEdges()<<endl;
	cout << "--------NAJKRACI PUT IZMEDJU CVOROVA 6 I 1-----------" << endl;
	g1.shortestPath(6, 1);
	cout << endl;
	cout << "--------NAJKRACI PUT IZMEDJU CVOROVA 6 I 2-----------" << endl;
	g1.shortestPath(6, 2);

	return 0;
}