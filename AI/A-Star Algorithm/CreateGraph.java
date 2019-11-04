import java.util.ArrayList;
import java.util.Scanner;

public class CreateGraph
{
	ArrayList<GraphBean> graphQueue=new ArrayList<GraphBean>();
	GraphBean goalState = new GraphBean();
	Scanner sc = new Scanner(System.in);
	
	public int[][] acceptGraph()
	{
		int g[][]=new int[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				g[i][j]=sc.nextInt();
		}
		return g;
	}
	
	public void acceprData()
	{
		GraphBean graphBean = new GraphBean();
		System.out.println("Start State ->");
		graphBean.state=acceptGraph();
		System.out.println("Goal State ->");
		goalState.state=acceptGraph();
		graphQueue.add(graphBean);
		System.out.println("\nStart State : \n"+graphBean.toString());
		System.out.println("\nGoal State : \n"+goalState.toString());
	}
	
	public void algorithm()
	{
		AStarAlgorithm a = new AStarAlgorithm();
		a.algorithmInitiate(graphQueue,goalState);
	}
}
