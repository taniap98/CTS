package lab03.ro.ase.java.utils;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.EOFException;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import ro.ase.java.models.Coffee;

public class FileUtils {
	
	public FileUtils() {}
	
	public void saveOrderToTextFile(List<Coffee> orderDetails, String fileName) throws IOException {
		File file = new File(fileName);
		FileWriter writer = new FileWriter(file);
		for(Coffee c : orderDetails) {
			writer.write(c.getBeverageName() + "," + c.getCoffeeType() + "," + c.getPrice() + "\n");
		}
		writer.close();
		//System.out.println("Order details were saved to: " + fileName);
		System.out.println("Order details were saved to: " + file.getAbsolutePath());
	}
	
	public Map<String, Integer> getOrderFromTextFile(String fileName) throws IOException {
		Map<String, Integer> orderDetails = new HashMap<String, Integer>();
		File file = new File(fileName);
		BufferedReader reader = new BufferedReader(new FileReader(file));
		String line = "";
		while((line = reader.readLine()) != null) {
			String[] values = line.split(",");
			String beverageName = values[0];
			if(orderDetails.containsKey(beverageName)) {
				orderDetails.put(beverageName, orderDetails.get(beverageName) + 1);
			} else {
				orderDetails.put(beverageName, 1);
			}
		}
		reader.close();
		return orderDetails;
	}
	
	public void writeOrderDetailsToBinaryFile(List<Coffee> orderDetails, String fileName) throws IOException {
		File file = new File(fileName);
		FileOutputStream fos = new FileOutputStream(fileName);
		DataOutputStream oos = new DataOutputStream(fos);
		oos.writeInt(orderDetails.size());
		for(Coffee c : orderDetails) {
			oos.writeUTF(c.getBeverageName());
			oos.writeUTF(c.getCoffeeType());
			oos.writeDouble(c.getPrice());
		}
		oos.close();
		fos.close();
		System.out.println("Order details were saved in binary format to: " + file.getAbsolutePath());
	}
	
	public void readerOrderDetailsFromBinaryFile(String fileName) throws IOException{
		File file = new File(fileName);
		FileInputStream fis = new FileInputStream(file);
		DataInputStream dis = new DataInputStream(fis);
		int noObjects = dis.readInt();
		for(int i = 0; i < noObjects; i++) {
			System.out.println(dis.readUTF());
			System.out.println(dis.readUTF());
			System.out.println(dis.readDouble());
		}
		dis.close();
		fis.close();
	}
	
	public void serializeOrderDetails(List<Coffee> orderDetails, String fileName) throws IOException {
		File file = new File(fileName);
		FileOutputStream fos = new FileOutputStream(file);
		ObjectOutputStream oos = new ObjectOutputStream(fos);
		for(Coffee c : orderDetails) {
			oos.writeObject(c);
		}
		oos.close();
		fos.close();
	}
	
	public void deserializeOrderDetails(String fileName) throws IOException {
		File file = new File(fileName);
		FileInputStream fis = new FileInputStream(file);
		ObjectInputStream ois = new ObjectInputStream(fis);
	
		while(true) {
			try {
				Coffee c = (Coffee) ois.readObject();
				System.out.println(c.getBeverageName() + " " + c.getCoffeeType()+ " " + c.getPrice());
			} catch(EOFException ex) {
				break;
			} catch (ClassNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		fis.close();
		ois.close();

	}
}
