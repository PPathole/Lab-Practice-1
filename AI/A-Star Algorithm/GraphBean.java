
public class GraphBean
{
	int state[][],hn,gn,fn,step=0;
	
	public GraphBean()
	{
		// TODO Auto-generated constructor stub
		this.hn=0;
		this.gn=0;
		this.fn=0;
	}
	
	@Override
	public String toString()
	{
		String str = new String();
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
				str+=("\t"+state[i][j]);
			str+="\n";
		}
		return str;
	}
}
