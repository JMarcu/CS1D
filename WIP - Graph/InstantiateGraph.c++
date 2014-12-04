#include "header.h"

void InstantiateGraph(Graph<string>& graph)
{
	graph.AddVertex("SEA");      //0
	graph.AddVertex("SFO");      //1
	graph.AddVertex("SDO");       //2
	graph.AddVertex("ARZ");//3
	graph.AddVertex("OAK");  //4
	graph.AddVertex("DEN");       //5
	graph.AddVertex("DAL");  //6
	graph.AddVertex("STL");       //7
	graph.AddVertex("HOU");      //8
	graph.AddVertex("NOR");     //9
	graph.AddVertex("TEN");      //10
	graph.AddVertex("CAR");        //11

	graph.AddVertex("WAS");      //0
	graph.AddVertex("MIN");      //1
	graph.AddVertex("MIA");       //2
	graph.AddVertex("NWE");//3
	graph.AddVertex("CLE");  //4
	graph.AddVertex("BUF");       //5
	graph.AddVertex("ATL");  //6
	graph.AddVertex("CIN");       //7
	graph.AddVertex("GBY");      //8
	graph.AddVertex("CHI");     //9
	graph.AddVertex("IND");      //10
	graph.AddVertex("BAL");        //11

	graph.AddVertex("PIT");      //0
	graph.AddVertex("NYGJ");      //1
	graph.AddVertex("DET");       //2
	graph.AddVertex("KCY");//3
	graph.AddVertex("PHI");  //4
	graph.AddVertex("TBY");       //5
	graph.AddVertex("JAC");

	graph.AddEdge(graph.GetVertex("SEA"), graph.GetVertex("MIN"), 1395.62);
	graph.AddEdge(graph.GetVertex("SEA"), graph.GetVertex("SFO"), 682.098);
	graph.AddEdge(graph.GetVertex("SFO"), graph.GetVertex("SDO"), 451.762);
	graph.AddEdge(graph.GetVertex("SDO"), graph.GetVertex("ARZ"), 286.155);
	graph.AddEdge(graph.GetVertex("ARZ"), graph.GetVertex("HOU"), 1027);
	graph.AddEdge(graph.GetVertex("HOU"), graph.GetVertex("NOR"), 320.607);
	graph.AddEdge(graph.GetVertex("NOR"), graph.GetVertex("TEN"), 469.348);
	graph.AddEdge(graph.GetVertex("TEN"), graph.GetVertex("CAR"), 339.047);
	graph.AddEdge(graph.GetVertex("CAR"), graph.GetVertex("WAS"), 336.14);
	graph.AddEdge(graph.GetVertex("WAS"), graph.GetVertex("JAC"), 650.947);
	graph.AddEdge(graph.GetVertex("JAC"), graph.GetVertex("ATL"), 286.816);
	graph.AddEdge(graph.GetVertex("ATL"), graph.GetVertex("CIN"), 368.107);
	graph.AddEdge(graph.GetVertex("CIN"), graph.GetVertex("GBY"), 415.507);
	graph.AddEdge(graph.GetVertex("GBY"), graph.GetVertex("CHI"), 183.56);
	graph.AddEdge(graph.GetVertex("CHI"), graph.GetVertex("IND"), 163.836);
	graph.AddEdge(graph.GetVertex("IND"), graph.GetVertex("BAL"), 510.632);
	graph.AddEdge(graph.GetVertex("BAL"), graph.GetVertex("PIT"), 197.581);
	graph.AddEdge(graph.GetVertex("PIT"), graph.GetVertex("NYGJ"), 313.163);
	graph.AddEdge(graph.GetVertex("NYGJ"), graph.GetVertex("DET"), 476.338);
	graph.AddEdge(graph.GetVertex("DET"), graph.GetVertex("KCY"), 641.581);
	graph.AddEdge(graph.GetVertex("KCY"), graph.GetVertex("PHI"), 1032.42);
	graph.AddEdge(graph.GetVertex("PHI"), graph.GetVertex("TBY"), 922.785);
	graph.AddEdge(graph.GetVertex("TBY"), graph.GetVertex("STL"), 857.789);
	graph.AddEdge(graph.GetVertex("STL"), graph.GetVertex("DAL"), 561.268);
	graph.AddEdge(graph.GetVertex("DAL"), graph.GetVertex("DEN"), 654.188);
	graph.AddEdge(graph.GetVertex("DEN"), graph.GetVertex("OAK"), 936.712);
	graph.AddEdge(graph.GetVertex("OAK"), graph.GetVertex("ARZ"), 630.066);
	graph.AddEdge(graph.GetVertex("JAC"), graph.GetVertex("BUF"), 872.834);
	graph.AddEdge(graph.GetVertex("BUF"), graph.GetVertex("CLE"), 173.306);
	graph.AddEdge(graph.GetVertex("CLE"), graph.GetVertex("NWE"), 540.084);
	graph.AddEdge(graph.GetVertex("NWE"), graph.GetVertex("MIA"), 1223.69);
	graph.AddEdge(graph.GetVertex("MIA"), graph.GetVertex("MIN"), 1498.19);
}

