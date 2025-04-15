import java.util.*;

public class adj_list_graph{

	private LinkedList<Integer>adj[];
	public adj_list_graph(int v) {
		adj = new LinkedList[v];
		for(int i=0;i<v;i++){
			adj[i] = new LinkedList<Integer>();
		}
	}
	
	public void addedge(int s,int d){
		adj[s].add(d);
		adj[d].add(s);
	} 
	    	
	public static void main(String[] args){
	     Scanner sc  = new Scanner(System.in);
	     System.out.println("Enter the number of vertices and edges: ");
	     int v = sc.nextInt();
	     int e = sc.nextInt();
	     adj_list_graph g = new adj_list_graph(v);
	     System.out.println("Enter the edges in (u v) format: ");
	     for(int i=0;i<e;i++){
	     	int s = sc.nextInt();
	     	int d = sc.nextInt();
	     	g.addedge(s,d);
	     }
	     g.printgraph();
  	}
  	
  	public void printgraph(){
  		for (int i = 0; i < adj.length; i++) {
			System.out.print("Vertex " + i + ":");
			for (Integer neighbor : adj[i]) {
		        	System.out.print(" " + neighbor);
		    	}
		    System.out.println();
        	}
  	}
  	
}

