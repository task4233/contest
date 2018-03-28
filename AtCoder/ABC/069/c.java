import java.io.*;

public class c {
    public static void main(String[] args) {
	InputStreamReader isr = new InputStreamReader(System.in);
	BufferedReader br = new BufferedReader(isr);

	int f = 0;
	int t = 0;
	int other = 0;
	boolean ok = true;
	try {
	    String str = br.readLine();
	    int N = Integer.parseInt(str);
	    str = br.readLine();
	    String[] data = str.split(" ", 0);
	    for (int i = 0; i < N; ++i) {
		int tmp = Integer.parseInt(data[i]);
		if (tmp % 4 == 0)      f++;
		else if (tmp % 2 == 0) t++;
		else                   other++;
	    }

	    if (t > 0) {
		if (other > f) ok = false;
	    } else {
		if (other - 1 > f) ok = false;
	    }

	    System.out.println((ok ? "Yes" : "No"));
	} catch(IOException e) {
	} finally {
	    try {
		br.close();
	    } catch(IOException e) {
	    } finally {
	    }
	}
    }
}
