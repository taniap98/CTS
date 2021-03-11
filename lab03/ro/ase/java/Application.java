package lab03.ro.ase.java;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;


import ro.ase.java.models.Coffee;
import ro.ase.java.utils.FileUtils;

public class Application {
	public static void main(String[] args) {
		Coffee c1 = new Coffee("Flat White", "Columbia", 12);
		Coffee c2 = new Coffee("Flat White", "Columbia", 12);
		Coffee c3 = new Coffee("Flat White", "Columbia", 12);
		Coffee c4 = new Coffee("Cappuchino", "Etiopia", 15);
		Coffee c5 = new Coffee("Cappuchino", "Etiopia", 15);
		Coffee c6 = new Coffee("Cappuchino", "Etiopia", 15);
		Coffee c7 = new Coffee("Cappuchino", "Etiopia", 15);
		Coffee c8 = new Coffee("Expresso", "Costa Rica", 10);
		
		List<Coffee> order = new ArrayList<Coffee>();
		order.add(c1);
		order.add(c2);
		order.add(c3);
		order.add(c4);
		order.add(c5);
		order.add(c6);
		order.add(c7);
		order.add(c8);
		FileUtils utils = new FileUtils();
	try {
		utils.saveOrderToTextFile(order, "details.txt");
		Map<String, Integer> details = utils.getOrderFromTextFile("details.txt")
;
		for(Entry<String, Integer> entry : details.entrySet()) {
			System.out.println(entry.getKey() + ": " +entry.getValue());
		}
		utils.writeOrderDetailsToBinaryFile(order, "details.dat");
		utils.readerOrderDetailsFromBinaryFile("details.dat");
		utils.serializeOrderDetails(order, "serialze.dat");
		utils.deserializeOrderDetails("serialze.dat");
	} catch (IOException e) {
		e.printStackTrace();
	}
	}
}
